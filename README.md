# rucheConnect_IOT

                                                POLYTECH SORBONNE
                                                      EI2I4
                                                La ruche connectée
                         
        Présentation du projet                
   Dans le cadre de notre formation au sein de Polytech Sorbonne, il nous a été confié un projet consistant à réaliser une ruche connectée destinée à des apiculteurs.
Notre système doit être capable d’envoyer certaines données caractéristiques de la ruche et de son emplacement. Un cahier des charges à été conçu grâce à l’aide des apiculteurs.  Le système créer doit tout d’abord envoyer les données comme le poids total de la ruche, la température intérieur et extérieur, l’humidité extérieur ou encore des données caractéristiques du vent. Afin de faciliter l’utilisation de cette ruche connectée, nous devons fournir avec ce système une interface utilisateur à l’apiculteur. Notre système devra bien-sûr être totalement autonome et étanche.

Notre ruche connectée à pu être tester chez des apiculteurs afin de confirmer que notre système est fiable. Après une semaine passée chez un apiculteur, nous avons pu collecter des données cohérentes avec l’environnement de la ruche.
Nous avons pu amener à bien notre projet malgré un contexte difficile, dans un monde dans la tourmente avec la propagation du virus. Il nous a donc fallu près de 3 mois à raison de 2h par semaines pour parvenir à le concrétiser.

Caractéristiques :
Le suivi de la ruche consiste à obtenir ces données :
•	Poids 
•	Température intérieur/extérieur
•	Humidité
•	Vitesse du vent
avec l’utilisation d’un microcontrôleur et de différents capteurs.

     Conditions préalables
Avoir des connaissances dans la programmation de microcontrôleurs (C++).
Savoir lire une fiche technique et en extraire les données les plus importantes.
Connaitre des protocoles de communication comme I2C ou encore l'UART.
Savoir envoyer des données en utilisant Sigfox.

	Liste de matériel 


• STM32 Nucleo STM32 L432KC	
x1	https://www.st.com/en/evaluation-tools/nucleo-l432kc.html 

• Capteur de température Interne DS18B20	 	x1	https://www.gotronic.fr/art-capteur-de-temperature-grove-101990019-23842.htm

• Capteur de température, d'humidité DHT22	 	x1	https://www.gotronic.fr/art-capteur-d-humidite-et-de-t-grove-101020019-18964.htm

• Accéléromètre ADXL345	 	x1	https://www.gotronic.fr/art-accelerometre-3-axes-grove-101020054-18957.htm

• Capteur de poids	 	x1	https://fr.aliexpress.com/...

• Ensemble capteurs girouette anémomètre
LEXCA007	 	x1	https://www.amazon.fr/Cimoto-WH-SP-WS01-Instrument-Accessoires-An%C3%A9Mom%C3%A8Tre/dp/B083XR9X3R 

• Capteur de Son

Adafruit I2S MEMS Microphone Breakout	 	x1	 https://www.amazon.fr/Adafruit-I2S-MEMS-Microphone-Breakout/dp/B072P1MCCR?pd_rd_w=LxJTk&pf_rd_p=e4310615-97c3-4e0d-9f57-23cf57e7667d&pf_rd_r=MXPXGZNNY67294SHC221&pd_rd_r=45184595-237f-4975-853e-626672f25aac&pd_rd_wg=PclXY&pd_rd_i=B072P1MCCR&psc=1&ref_=pd_bap_d_rp_1_t

STM32-L476RG	 x1   			https://www.mouser.fr/ProductDetail/STMicroelectronics/NUCLEO-L476RG?qs=PRtH0mD6DWbM6mRV5DKjBQ==&gclid=CjwKCAiAu8SABhAxEiwAsodSZIBpuepHc-agLV2I75A6EUGy7IFRcOjObn0HcXxYk_EZfKa1jvdfuxoCd0EQAvD_BwE

• Panneau solaire SOL2W (Capteur de luminosité)	 	x2	https://www.gotronic.fr/art-cellule-solaire-sol2w-18995.htm 

• Batterie	 	x2	https://www.gotronic.fr/art-cellule-solaire-sol2w-18995.htm 

• LiPo Rider	 	x2	https://www.gotronic.fr/art-carte-lipo-rider-pro-106990008-19050.htm 

• Sigfox	 	x2	https://yadom.fr/carte-breakout-sfm10r1.html 


	Quels sont les pins utilisés ?
Nous utilisons 4 capteurs branchés sur notre microcontroleur.
Voici le branchement effectué sur notre NUCLEO L-432KC :
![Présentation du branchement](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/branchement.jpg)


	Utilisation de Sigfox et Ubidots
Dans notre projet différents software ont été utilisé pour mettre en place notre ruche connecter. La figure ci-dessous montre les parties de notre projet :
•	On a une partie devises qui permets de programmer les différents capteurs (Températures, Humidité, poids, accéléromètre…) mais aussi de mettre en place un protocoles d’envoi de données. Cette partie est géré par un soft en ligne qui est MBED (https://os.mbed.com/).
•	Une fois la procédure de programmation des capteurs est mise en place, le Soft Sigfox intervient pour l’envoie des données vers une interface web Ubidots pour permettre au client de suivre l’évolution des données du système.
•	Ubidots est le soft qui gère l’interface utilisateur c’est-à-dire la plateforme qui permet à l’utilisateur de communiqué avec sa ruche.
 
 ![creeationDeviceUbidots](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/creeationDeviceUbidots.png)	
MBED
Mbed OS fournit la plateforme logicielle Mbed C/C++ et les outils nécessaires à la création d'un micro logiciel de microcontrôleur qui fonctionne sur les appareils IoT. Il se compose des bibliothèques de base qui fournissent les pilotes de périphériques de microcontrôleurs, la mise en réseau, le RTOS et l'environnement d'exécution, les outils de construction et les scripts de test et de débogage. Ces connexions peuvent être sécurisées par des bibliothèques SSL/TLS compatibles telles que Mbed TLS ou wolfSSL, qui supporte mbed-rtos.
Sigfox

Sigfox est spécialisé dans le M2M (Machine to Machine) via des réseaux bas débit. Il contribue à l'Internet des objets en permettant l'interconnexion via une passerelle. Sa technologie radio UNB (« Ultra narrow band ») lui permet de bâtir un réseau cellulaire bas-débit, économe en énergie.
Dans notre projet on a utilisé un module Sigfox. Pour mettre en place le module Sigfox :
•	Vous devez enregistrer votre appareil auprès du back end Sigfox. Naviguez sur https://backend.sigfox.com/activate et vous trouverez une liste des kits de développement compatibles avec Sigfox, choisissez votre kit pour continuer.
•	Ensuite, vous devrez choisir un opérateur Sigfox pour le pays dans lequel vous allez activer votre appareil. Trouvez votre pays et sélectionnez l'opérateur pour continuer.
•	Une fois que votre appareil est enregistré dans le backend Sigfox, vous devriez le voir dans la section Appareil comme indiqué sur l'image ci-dessous :
 
![activationmoduleSigfox](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/activationmoduleSigfox.png)
Sigfox et Ubidots 
La gestion des données entre Sigfox et Ubidots passe par un "Callback". Le dispositif Sigfox sera chargé de lire les capteurs et d'envoyer les valeurs à Sigfox, le message sera décodé en utilisant la configuration personnalisée de la charge utile au niveau des configurations de rappel pour construire la demande de liaison montante du message vers Ubidots. 
 
Il est maintenant temps de mettre en place le rappel. Allez dans la section Dispositif et cliquez sur le dispositif enregistré :
 
![device](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/device.png)
device
Ensuite, vérifiez les informations relatives à votre appareil et sélectionnez "CALLBACKS" dans le menu à gauche de la page, comme vous pouvez le voir ci-dessous :

 ![callbacks](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/callbacks.png)

Sigfox callbacks allow you to report data to an external system like Ubidots. To setup a callback to Ubidots API, use these parameters:
•	Type : Data - Uplink
•	Channel: UTL
•	Custom payload config : value0::uint:8 value1::uint:8 value2::uint:8 value3::uint:8 value4::uint:8
•	URL pattern: https://industrial.api.ubidots.com/api/v1.6/devices/{device}/
•	Use HTTP method: POST
•	Send SNI : Checked
•	Headers : x-auth-token BBFF-SSwnDYhu1rEvidVo5vDVpgpMvam4Ky
•	Content Type : application/json
•	Body: 
{
  "Temperature" : {"value":"{customData#value0}"}, 
  "Humidity" : {"value":"{customData#value1}"},
  "TempIntern" : {"value":"{customData#value2}"},
  "Anemo" : {"value":"{customData#value3}"},
  "Poids" : {"value":"{customData#value4}"}
}
 ![callbacksOK](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/callbacksOK.png) 

Une fois que votre appareil est prêt, rendez-vous sur votre compte Ubidots pour visualiser le nouvel appareil créé avec les variables.
Dans le compte Ubidots, il faut crée un new devise dans le menu Devices voir figure ci-dessous.
 
Une fois le devise crée vous pouvez visualiser les différentes variables en cliquant dessus voir figure ci-dessous.
![creeationDeviceUbidots](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/creeationDeviceUbidots.png)

## Les pistes explorées

### Optimisation de la consommation d’énergie : 
	
Un scénario particulier a été mis en place pour réduire la consommation d’énergie, toute consommation est dû à l’utilisation des capteurs et des périphériques de la carte nucleo STM32L432KC, c’est pourquoi nous alimentons les capteurs chaque 30 minutes pour une durée de 10 secondes. 

Le graphe ci-dessous représente l’alimentation d’un capteur dans un  intervalle de 1800 secondes (30 minutes).

![Graphe](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/Scénario.png)

Afin de concrétiser ce scénario en Hardware, toute patte Vin d’un capteur est branchée à une broche Digital du micro-contrôleur. En Software, on mettra la patte Digital en output à 1, qui se traduit par 3.3v en sortie de cette patte, pour une durée de 10 secondes. 

![EasyEDA](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/EasyEDA.png)

### EasyEDA
Un autre moyen est envisageable pour réduire encore davantage la consommation, déconnecter les résistances SB09 et SB11, déconnecter toutes les LED’s de la carte est ne plus utiliser le programmeur. Pour ce faire, il faut éviter d’alimenter la carte depuis son port usb-b et l’alimenter depuis sa patte 3.3 volts. 

Pour alimenter le microcontrôleur depuis la patte 3.3 volts nous proposons le montage suivant : 

   

Réaliser avec un usb04d 0J9652 Pololu et régulateur de tension reg09b0J7031 Pololu

 

Pour donner le montage final suivant :


 


Nous vous rappelons que cette partie est une piste que nous avons explorée durant ce projet et qu’il y a du travail à faire dessus afin de rendre notre modèle plus exact. 


### Edge Impulse : 
Edge Impulse permet aux développeurs de créer la prochaine génération de dispositifs intelligents avec Machine Learning intégré, nous nous sommes servi de ce dernier pour déployer une librairie C++ qui nous permettra de détecter la présence de frelon, la présence d'essaimage et autres. Il faut savoir que pour avoir une bibliothèque capable de faire cela, il est impératif d’établir des traitements sur des pistes labellisées qui constituent notre base de données.

La base de données doit inclure des extraits sonores d’un frelon par exemple, une reine, le bruit à l’intérieur d’une ruche, un phénomène d'essaimage … etc. Elle devra contenir autant de pistes que les phénomènes ou n’importe son que nous souhaitons détecter.
	
La figure ci-dessous est l’interface de Edge Impulse et vous pouvez avoir plus d’informations sur l’utilisation de Edge Impulse sur ce lien. 
	

Tout traitement sur pistes sonores téléchargées depuis to bee or not to bee a été réalisé à l’aide du bloc MFCC avec le paramétrage suivant :
	
  

En sortie du bloc MFCC et pour toutes les pistes sonores nous avons obtenue le résultat  suivant :
 	
 


Quant à l'entraînement de notre modèle nous utilisons un réseau neuronal(Keras), voir figure ci-dessous : 
 

Notre modèle n’est pas très accurate, 53.6%, il faut augmenter la base de données, faire d’avantages de traitements sur notre base de données.


Une fois satisfait de vos résultats, le déploiement de la librairie C++ se fait sur l’onglet Deployment.

 ![Deployer](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/DeployerEdgeImpulse.png)

Ci-joint un [lien](https://drive.google.com/file/d/1Z95UNyn4BX0cGxKn5TqrYBqPZnzdIMo0/view?usp=sharing) pour téléchargr de nos librairies C++

### Utilisation des librairies C++ : 
	
Notre cible dans cette partie est un STM32L476RG, l’acquisition du son ce fait par un [Adafruit I2S MEMS Microphone Breakout](https://www.amazon.fr/Adafruit-I2S-MEMS-Microphone-Breakout/dp/B072P1MCCR?pd_rd_w=LxJTk&pf_rd_p=e4310615-97c3-4e0d-9f57-23cf57e7667d&pf_rd_r=MXPXGZNNY67294SHC221&pd_rd_r=45184595-237f-4975-853e-626672f25aac&pd_rd_wg=PclXY&pd_rd_i=B072P1MCCR&psc=1&ref_=pd_bap_d_rp_1_t). 
Pour la partie code, veuillez le télécharger [ici](https://github.com/ShawnHymel/ei-keyword-spotting/tree/master/embedded-demos/stm32cubeide/nucleo-l476-keyword-spotting) et suivez le tutoriel pour importer le projet sur STM32Cude et inclure votre bibliothèque C++.








