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

• Sigfox	 	x1	https://yadom.fr/carte-breakout-sfm10r1.html 


	Quels sont les pins utilisés ?
Nous utilisons 4 capteurs branchés sur notre microcontroleur.
Voici le branchement effectué sur notre NUCLEO L-432KC :
![Présentation du branchement](https://github.com/wassimALLAL/rucheConnect_IOT/blob/main/image/branchement.jpg)

