var http = require('http');
var fs = require('fs');

http.createServer(function (req, res) {
  fs.readFile('index.html', function(err, data) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write(data);
    res.end();
  });
}).listen(8080);


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
      console.log(err + err.stack);
      return err + err.stack;
    }
    else {
      console.log(data);
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
