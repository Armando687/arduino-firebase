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

//    // Get a reference to the database ser
//    function writeTemperatura() {
//        firebase.database().ref('home/' + "Temperatura").set({
//          temperatura: "14",
//          estado: "2",
//          ventilador: "1"
//        });
//      }
// writeTemperatura();
  function readTemperatura(){
    var result = null;
    var temperatura = firebase.database().ref('home/Temperatura');
    temperatura.on('value',function(data){
      result = data.val();
      console.log(result.temperatura);
      $("#temperatura").text(result.temperatura);
      if(result.estado == 1){
        $("#estado").text("Normal");
      }else{
        $("#estado").removeClass("badge badge-primary badge-pill");
        $("#estado").addClass("badge badge-danger badge-pill");
        $("#estado").text("Critico");
      }

      if(result.ventilador == 1){
        $("#ventilador").text("Apagado");
      }else{
        $("#ventilador").removeClass("badge badge-primary badge-pill");
        $("#ventilador").addClass("badge badge-danger badge-pill");
        $("#ventilador").text("Encendido");
      }
      if(result != null){
        $("#conexion").text("Activo");
      }else{
        $("#conexion").text("Inactivo");
      }
      
    });
    
  }
readTemperatura();
 