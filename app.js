// node
var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
// aws
const AWS = require('aws-sdk');
const s3 = new AWS.S3();
var rekognition = new AWS.Rekognition();

const image = {
 Image: {
  S3Object: {
   Bucket: "ucode19",
   Name: "teams/group-20/celebrities.jpg"
  }
 },
 MaxLabels: 20,
 MinConfidence: 70
};

http.createServer(function (req, res) {
  if (req.url == '/fileupload') {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
      loadFileToS3(files);
      res.write('File uploaded');
      res.end();
    });
  } else {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write('<form action="fileupload" method="post" enctype="multipart/form-data">');
    res.write('<input type="file" name="filetoupload"><br>');
    res.write('<input type="submit">');
    res.write('</form>');
    return res.end();
  }
}).listen(8080);


// objEtiquetas tiene el objeto con todas las eiquetas
var objEtiquetas;


function escribirArchivo() {
  console.log(objEtiquetas);

  let testStr = "";
  for (let i=0; i<objEtiquetas.Labels.length;  i++) {
    testStr += objEtiquetas.Labels[i].Name + "\n";
  }
  fs.writeFile('test.txt', testStr);
}


function loadFileToS3(files) {
  // Lee las etiquetas de la imagen
  rekognition.detectLabels(image, function(err, data) {
    if (err) {
      console.log(err + err.stack);
    }
    else {
      //console.log(data);
      objEtiquetas = data;
      escribirArchivo();
    };
  });

  //var imageData = labels(image);
  //console.log(imageData);

  // Escribe el archivo


  // Carga el archivo de c++
  //procesarLabels(imageData);
}

/*
http.createServer(function (req, res) {
  if (req.url == '/fileupload') {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
      console.log(err, fields, files);
      res.write('File uploaded');
      res.end();
    });
  } else {
    fs.readFile('index.html', function(err, data) {
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.write(data);
      return res.end();
    });
  }
}).listen(8080);
*/

/*
fs.readFile('./index.html', function (err, html) {
    if (err) {
        throw err;
    }
    http.createServer(function(request, response) {
        response.writeHeader(200, {"Content-Type": "text/html"});
        response.write(html);
        response.end();
    }).listen(8000);
});
*/

function labels(info) {

}

function procesarLabels(data) {
  // PROCESAR C++
  var exec = require('child_process').exec;
  exec('pwd', function callback(error, stdout, stderr){
      console.log(error, stdout, stderr);
  });
}
