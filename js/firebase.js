// Your web app's Firebase configuration
var firebaseConfig = {
    apiKey: "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    authDomain: "example-aa3c3.firebaseapp.com",
    databaseURL: "https://exaple-aa3c3.firebaseio.com",
    projectId: "example-aa3c3",
    storageBucket: "example.appspot.com",
    messagingSenderId: "xxxxxxxxxxxxxxxxx",
    appId: "1:745203185708:web:xxxxxxxxxxxxxxxxxx"
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
      if(result.estado == 0){
        $("#estado").text("Normal");
      }else if(result.estado == 1){
        $("#estado").text("Advertencia");
      }
      else{
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
 