# Arduino con firebase con CLiente web
Este es un ejemplo sencillo del uso de firebase con su base de datos realTimeDataBase, inmerso con arduino y un cliente web. Para este ejemplo usaremos un cliente utilizando el Hosting que nos ofrece  Firebase esto si asi lo desean para mejor comonidad (opcional); escribimos los datos desde arduino a firebase, y son leidos por el cliente, al mismo tiempo lo escrito por el cliente puede ser leido por arduino haciendo así una conexión asigcrona  en tiempo real. para este ejemplo usaremos lo siguiete.
![Home](https://github.com/Armando687/arduino-firebase/blob/master/img/home.png)
![Controll-temperatura](https://github.com/Armando687/arduino-firebase/blob/master/img/temperature.png)
![control-open-close](https://github.com/Armando687/arduino-firebase/blob/master/img/controll-open-cloose.png)
## Material
* modulo wifi 
* sensor de temperatura (analogico) NOTA: se puede utilizar un sendor Digital pero se tendrian que hacer los cambios pertinentes en el codigo para su correcto funcionamiento. 
* 3 servomotores (puerta y dos ventanas)
* resistemcias de 10k
* 2 Led Blanco
* cables para conexion (el que sea mejor de su preferencia).
* protoBar
## Configuraciones-ClienteWEB
Para el funcionamiento correcto debe realizar las siguientes configuraciones e intalar los elementos necesarios
* Cree un proyecto en firebase, si tiene proplemas puede seguir la documentacion proporcionada por la plataforma [Documentacion de Firebase](https://firebase.google.com/docs/web/setup?authuser=0#create-project)
* Posteriormente remplace los key que te proporciona el proyecto de firabase, en los archivos js del cliente web `firebase.js` y `open-clode.js` el fracmento de codigo a remplazar sera similar a este . 
 * `var firebaseConfig = {
        apiKey: "api-key",
        authDomain: "project-id.firebaseapp.com",
        databaseURL: "https://project-id.firebaseio.com",
        projectId: "project-id",
        storageBucket: "project-id.appspot.com",
        messagingSenderId: "sender-id",
    } `
* finalmente compruebe que todo se realizo correctamente probando los ejemplos existem en el directorio `./src` por se la primera prueba debera escribir por primera vez la coleccion de datos, este se encuentra comentado en el archivo `firebase.js`, para el ejemplo de los servo motores son simplemente botones que realizaran su funcion automáticamente con una acción.
## Configuraciones-Ardunio.
* Instale las librerias para el uso de wifiESP8266, desde al administrador de bibliotecas de ArduinoIDE
* Inatale los modulos wifi para el uso de placas wifi en arduino siga la siguiente documentación [aquí](https://github.com/esp8266/Arduino)
* Instale las librerias base de Firebase para arduino siguiendo la documentación [aqui](https://github.com/FirebaseExtended/firebase-arduino)
 descarque el proyecto, cambien el nombre a `firebase-arduino` y agrequelo al directorio de las librerias de arduinoIDE 
* Finalmente preeuebe los ejemplos demo existentes en este proyeto para ejemplo.
### NOTA: 
Una vez que tenga el proyecto totalmente funcional, podria probar utilizando el Hosting gratuito que te ofrece firebase [Documentacion](https://firebase.google.com/docs/hosting?authuser=0)

