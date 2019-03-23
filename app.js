var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
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

/*fs.readFile('./index.html', function (err, html) {
    if (err) {
        throw err;
    }
    http.createServer(function(request, response) {
        response.writeHeader(200, {"Content-Type": "text/html"});
        response.write(html);
        response.end();
    }).listen(8000);
});*/

http.createServer(function (req, res) {
  if (req.url == '/fileupload') {
    var form = new formidable.IncomingForm();
    form.parse(req, function (err, fields, files) {
      var oldpath = files.filetoupload.path;
      var newpath = 'C:/Users/Your Name/' + files.filetoupload.name;
      fs.rename(oldpath, newpath, function (err) {
        if (err) throw err;
        res.write('File uploaded and moved!');
        res.end();
      });
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

function uploadFileToS3(path){
  console.log(path);
}


// PROCESAR C++
var exec = require('child_process').exec;
exec('pwd', function callback(error, stdout, stderr){
    console.log(error, stdout, stderr);
});


// SUBIR ARCHIVO A S3c
const AWS = require('aws-sdk');
const s3 = new AWS.S3();


// ANALIZAR IMAGEN
var rekognition = new AWS.Rekognition();

var image = {
 Image: {
  S3Object: {
   Bucket: "ucode19",
   Name: "teams/group-20/celebrities.jpg"
  }
 },
 MaxLabels: 50,
 MinConfidence: 70
};

var image2  = {
 Image: {
  S3Object: {
   Bucket: "ucode19",
   Name: "teams/group-20/celebrities.jpg"
  }
 },
 MaxLabels: 50,
 MinConfidence: 70
};

var imageData = getLabels(image);

function getLabels(params) {
  rekognition.detectLabels(params, function(err, data) {
    if (err) {
      //console.log(err + err.stack);
      return err + err.stack;
    }
    else {
      //console.log(data);
      return data;
    };
  });
}


/*
var params = {
 Image: {
  S3Object: {
   Bucket: "ucode19",
   Name: "teams/group-20/celebrities.jpg"
  }
 }
};

rekognition.recognizeCelebrities(params, function(err, data) {
  if (err) console.log(err, err.stack);
  else     console.log(data);
});*/
