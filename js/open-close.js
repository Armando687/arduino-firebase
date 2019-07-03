// Your web app's Firebase configuration
var firebaseConfig = {
    apiKey: "AIzaSyAtobkS6J9vl1kUKT5RHxUsQ0FFNCj_DHY",
    authDomain: "proyectoinicio-aa3c3.firebaseapp.com",
    databaseURL: "https://proyectoinicio-aa3c3.firebaseio.com",
    projectId: "proyectoinicio-aa3c3",
    storageBucket: "proyectoinicio-aa3c3.appspot.com",
    messagingSenderId: "745203185708",
    appId: "1:745203185708:web:5700a02273e3bdea"
  };
  firebase.initializeApp(firebaseConfig);

   // Get a reference to the database ser
   function writeDoor(data) {
       firebase.database().ref('home/' + "Door").set({
         estado: data
       });
    }
// Get a reference to the database ser
    function writeWindowOne(data) {
        firebase.database().ref('home/' + "WindowOne").set({
            estado: data
        });
    }

    function writeWindowTwo(data) {
        firebase.database().ref('home/' + "WindowTwo").set({
            estado: data
        });
    }

    function writeLightOne(data) {
        firebase.database().ref('home/' + "LightOne").set({
            estado: data
        });
    }

    function writeLightTwo(data) {
        firebase.database().ref('home/' + "LightTwo").set({
            estado: data
        });
    }

  function readDoor(){
    var result = null;
    var door = firebase.database().ref('home/Door');
    door.on('value',function(data){
      result = data.val();
      console.log(result.estado);
      if(result.estado == 1){
          $('#detailD').text("activo");
      }else{
        $('#detailD').text("desactivado");
      }
    });
  }
readDoor();
  function readWindowOne(){
    var result = null;
    var window = firebase.database().ref('home/WindowOne');
    window.on('value',function(data){
      result = data.val();
      console.log(result.estado);
      if(result.estado == 1){
          $('#detailW').text("activo");
      }else{
        $('#detailW').text("desactivado");
      }
    });
  }
readWindowOne();

function readWindowTwo(){
    var result = null;
    var window = firebase.database().ref('home/WindowTwo');
    window.on('value',function(data){
      result = data.val();
      console.log(result.estado);
      if(result.estado == 1){
          $('#detailW2').text("activo");
      }else{
        $('#detailW2').text("desactivado");
      }
    });
  }
readWindowTwo();

function readLightOne(){
    var result = null;
    var light = firebase.database().ref('home/LightOne');
    light.on('value',function(data){
      result = data.val();
      console.log(result.estado);
      if(result.estado == 1){
          $('#detailL').text("activo");
      }else{
        $('#detailL').text("desactivado");
      }
    });
  }
readLightOne();

function readLightTwo(){
    var result = null;
    var light = firebase.database().ref('home/LightTwo');
    light.on('value',function(data){
      result = data.val();
      console.log(result.estado);
      if(result.estado == 1){
          $('#detailL2').text("activo");
      }else{
        $('#detailL2').text("desactivado");
      }
    });
  }
readLightTwo();

$('#openD').click(function(){writeDoor(1)});
$('#closeD').click(function(){writeDoor(0)});

$('#openW').click(function(){writeWindowOne(1)});
$('#closeW').click(function(){writeWindowOne(0)});

$('#openW2').click(function(){writeWindowTwo(1)});
$('#closeW2').click(function(){writeWindowTwo(0)});

$('#onL').click(function(){writeLightOne(1)});
$('#offL').click(function(){writeLightOne(0)});

$('#onL2').click(function(){writeLightTwo(1)});
$('#offL2').click(function(){writeLightTwo(0)});

