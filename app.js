// node
var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
// aws
const AWS = require('aws-sdk');
const s3 = new AWS.S3();
var rekognition = new AWS.Rekognition();
// ejecutar comandos
var exec = require('child_process').exec;

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

/* APP DE NODE
http.createServer(function (req, res) {
  if (req.url == '/fileupload') {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
      loadFileToS3(req, res);
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
}).listen(8080);*/

http.createServer(function(req, res) {
    fs.readFile('index.html', function(err, data) {
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.write(data);
      return res.end();
    });
}).listen(8080);


// PROCESO DE LOS DATOS
var objEtiquetas;

function procesarDatos(req, res) {
  // escribir el archivo
  let testStr = "";
  for (let i=0; i<objEtiquetas.Labels.length;  i++) {
    testStr += objEtiquetas.Labels[i].Name + "\n";
  }
  fs.writeFile('cpp/datos.txt', testStr);
  // ejecutar c++
  exec('./cpp/test', function callback(error, stdout, stderr){
      console.log(error, stdout, stderr);
  });

  fs.readFile('cpp/url.txt', function(err, data) {
    if (err) {
      console.log("Error al abrir el archivo con el enlace");
    } else {
      res.writeHead(301, { Location: data });
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
