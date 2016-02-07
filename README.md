Videojuego Saltarin
Saltarin es un videojuego diseñado para dispositivos android donde nuestro personaje 
tendra que esquivar diferentes obstaculos, el codigo del videojuego es software libre
de licencia Apache 2.0
Estado del proyecto: Alfa.
 
1. Compilacion e instalacion
 1.1 Requerimientos.
 Android SDK: Descargue desde http://developer.android.com/intl/es/sdk/index.html
 Android NDK: Descargue desde  http://developer.android.com/intl/es/tools/sdk/ndk/index.html
 Motor o engine: cocos2dx http://www.cocos2d-x.org

 Crear el proyecto de cocos2dx, previamente debe de realizar los siquientes pasos:
 -Descargue el codigo fuente de cocos2dx desde http://www.cocos2d-x.org/download 
 -Configure las variables de entorno correctamente de cocos2dx como indica su documentacion.
 -Crear un nuevo proyecto usando cocos2dx lo llamaremos Saltarin, ejecutaremos el siguiente comando:

 cocos new saltarin -p org.linuxerodroide.saltarin -l cpp -d /path_donde_se_creara_proyecto/saltarin

 Creara  el proyecto saltarin en la ruta o path que se le indique.
 -Descargue el codigo del juego , ejecute el siguiente comando
 git clone https://github.com/luisrevilla/saltarin.git

 -Copiar el codigo fuente de satarin al directorio donde se creo el proyecto de cocos2dsx, debe de sustituir los archivos
 que estan ubicados en los siguientes subdirectorios:
 /path_donde_se_creara_proyecto/saltarin/Classes/
 /path_donde_se_creara_proyecto/saltarin/Resources/
 /path_donde_se_creara_proyecto/saltarin/proj.android/

 1.2 Compilar el juego
 cocos run -p android -j 4

 1.3 Instalacion el dispositivo movil, ejecute el comando:
 adb install -r bin/saltarin-debug.apk

2. Licencia: Apache 2.0 http://www.apache.org/licenses/LICENSE-2.0

3. Autor(s)
 - Luis Revilla (luis.revilla@gmail.com) 
   blog: http://linuxerodroide.blogspot.pe
