// ELECTRON
// Módulos para controlar electron
const {app, BrowserWindow} = require('electron')

// Referencia global de la ventana electron
let mainWindow

// Crear la vantana de electron
function createWindow () {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })
  // Carga del HTML
  mainWindow.loadFile('index.html')
  // Cerrar la ventana
  mainWindow.on('closed', function () {
    mainWindow = null
  })
}

// Método llamado para cargar la app cuando se haya cargado electron
app.on('ready', createWindow)

// Cerrar todos los procesos cuando se cierra la ventana
app.on('window-all-closed', function () {
  // Excepto en mac
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', function () {
  if (mainWindow === null) {
    createWindow()
  }
})

// ANALIZAR IMAGEN
const AWS = require('aws-sdk');

var rekognition = new AWS.Rekognition();


var params = {
 Image: {
  S3Object: {
   Bucket: "ucode19",
   Name: "teams/group-20/celebrities.jpg"
  }
 },
 MaxLabels: 50,
 MinConfidence: 70
};


rekognition.detectLabels(params, function(err, data) {
  if (err) console.log(err, err.stack);
  else     console.log(data);
});

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
