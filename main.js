const AWS = require('aws-sdk');
const rekog = require('rekognition');

var image = {
   "contentString":{
      "Attributes":[
         "ALL"
      ],
      "Image":{
         "S3Object":{
            "Bucket":"console-sample-images",
            "Name":"face.jpg"
         }
      },
      "MinConfidence":30,
      "MaxLabels":50
   }
}

var data = AWS.DetectLabels(image);

console.log(data);
