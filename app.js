// node
var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
// aws
const AWS = require('aws-sdk');
const s3 = new AWS.S3();
var rekognition = new AWS.Rekognition();
// ejecutar comandos y abrir enlace
var exec = require('child_process').exec;
const command = "./cpp/procesador";
var opn = require('opn');

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

// APP DE NODE BASICA
/*
http.createServer(function (req, res) {
  if (req.url == '/upload') {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
      loadFileToS3();
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
*/

// APP DE NODE CON CSS
http.createServer(function(req, res) {
  if (req.url != 'upload') {
    /*
    fs.readFile('index.html', function(err, data) {
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.write(data);
      return res.end();
    });
    */
    if (req.url == '/upload') {
      // HTML
      res.writeHead(200, {'Content-Type':'text/html'});
      var myReadStream = fs.createReadStream(__dirname + '/upload.html', 'utf8');
      myReadStream.pipe(res);
      // Formulario
      var form = new formidable.IncomingForm();
      form.parse(req, function (err, fields, files) {
        loadFileToS3();
        res.end();
      });
    }
    else {
      res.writeHead(200, {'Content-Type':'text/html'});
      var myReadStream = fs.createReadStream(__dirname + '/index.html', 'utf8');
      myReadStream.pipe(res);
    }
  }
}).listen(8080);


// PROCESO DE LOS DATOS
var objEtiquetas;

function procesarDatos() {
  // escribir el archivo
  let testStr = "";
  for (let i=0; i<objEtiquetas.Labels.length;  i++) {
    testStr += objEtiquetas.Labels[i].Name + "\n";
  }
  fs.writeFile('cpp/datos.txt', testStr);
  // ejecutar c++
  exec(command, function callback(error, stdout, stderr){
      console.log(error, stdout, stderr);
  });

  fs.readFile('cpp/url.txt', function(err, data) {
    if (err) {
      console.log("Error al abrir el archivo con el enlace");
    } else {
      console.log("Redireccionando a ", data);
      opn(data);
    }
  });
}

function loadFileToS3(files) {
  // Lee las etiquetas de la imagen
  rekognition.detectLabels(image, function(err, data) {
    if (err) {
      console.log(err + err.stack);
    }
    else {
      objEtiquetas = data;
      procesarDatos();
    };
  });
}
