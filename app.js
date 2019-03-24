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
const command = './procesador';
var opn = require('opn');


// APP DE NODE BASICA
http.createServer(function (req, res) {
  if (req.url == '/upload') {
      // Estilos
      res.writeHead(200, {'Content-Type': 'text/html'});
      var html = fs.readFileSync('./upload.html');
      res.write(html);
      // Formulario
      var form = new formidable.IncomingForm();
      form.parse(req, function (err, fields, files) {
        let fileSize = files.filetoupload.size;
        // Comprueba que el archivo sea valido
        if (fileSize == 0) {
          res.write('<p style="font-size:30px; color:#ce1818; font-weight:800; text-align:center;">Archivo no válido</p>');
        } else {
          uploadImage(files.filetoupload.path);
        }
        res.end();
      });
  }
  else {
    // Estilos
    res.writeHead(200, {'Content-Type': 'text/html'});
    var html = fs.readFileSync('./index.html');
    res.write(html);
    return res.end();
  }
}).listen(8080);


function uploadImage(filename) {
  // Imagen a cargar a S3
  let name = "teams/group-20" + filename;
  let fileData = fs.createReadStream(filename);
  let imageS3 = {
    Bucket: "ucode19",
    Body: fileData,
    Key: name
  };

  s3.putObject(imageS3, function(err, data) {
    if (err) {
      console.log(err, err.stack);
    }
    else {
      // Imagen a descargar de S3
      const imageName = "teams/group-20" + filename;
      var image = {
       Image: {
        S3Object: {
         Bucket: "ucode19",
         Name: imageName
        }
       },
       MaxLabels: 50,
       MinConfidence: 70
      };
      // Analizar etiquetas de la imagen
      rekognition.detectLabels(image, function(err, data) {
          if (err) {
            console.log(err + err.stack);
          }
          else {
            objEtiquetas = data;
            console.log(data);
            procesarDatos();
          };
      });
    }
  });
}


// PROCESADO DE LOS DATOS
var objEtiquetas;

function procesarDatos() {
  // escribir el archivo
  let testStr = "";
  for (let i=0; i<objEtiquetas.Labels.length;  i++) {
    testStr += objEtiquetas.Labels[i].Name.toLowerCase() + "\n";
  }
  fs.writeFile('datos.txt', testStr, function(err) {
    if (err) {
      console.log("Error al abrir datos.txt:", err);
    }
    else {
      // ejecutar c++
      exec(command, function callback(error, stdout, stderr) {
        if (error) {
          console.log("Error:", error, "| stdout: ", stdout, "| stderr: ", stderr);
        }
        else {
          // Abrir enlace
          fs.readFile('url.txt', 'utf8', function(err, data) {
            if (err) {
              console.log("Error al abrir el archivo con el enlace");
            }
            else if (data == null || data == "") {
              console.log("No se encontraron etiquetas");
            }
            else {
              console.log("Redireccionando a", data);
              opn(data.toString());
            }
          });
        }
      });
    }
  });
}
