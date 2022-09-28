# ArchitectureLogicielsLab2
Lab2
INSTRUCTIONS À SUIVRE
***À noter que le projet a été développé pour Python 3.10 à la base, les autres versions n'ont pas été testées, mais le tout devrait fonctionner tout de même si la version est assez récente.

1. Téléchargez la vidéo voulue sur votre ordinateur et noter l'emplacement de celle-ci avec son nom et son extension (ex-> C:/Example.avi)

2. Installer la version la plus récente de Python sur votre ordinateur en retenant son emplacement dans les fichiers

3. Aller chercher le projet sur github au lien suivant-> https://github.com/samm56784/ArchitectureLogicielsLab2

4. Enregistrer le projet sur l'ordinateur et l'ouvrir

5. Aller dans les propriétés du projet, en haut de la fenêtre, changer la configuration pour le mode Release et la plateforme pour x64

6. Dans les propriétés générales, mettre le nom de la cible comme étant labo2 et mettre le type de configuration en .dll

7. Toujours dans les propriétés, dans les paramètres avancés, mettre l'entension du fichier cible en .pyd

8. Encore dans les propriétés, dans les répertoires VC++, ajouter dans les répertoires Include, l'emplacement de sauvegarde de la bibliothèque include de Python (ex-> C:/Python310/include) 
et ajouter également dans les répertoires de bibliothèques, l'emplacement de sauvegarde de la bibliothèque de Python (ex-> C:/Python310/libs)

9. Nettoyer, compiler et générer votre solution par la suite

10. Ouvrir la console Python et inscrire les instructions suivants les >>> :
>>> import sys
Pour la ligne suivante, il faut mettre le chemin du projet entre les guillemets où se trouve votre application Python en utilisant des frontslashs entre les fichiers
>>> sys.path.append("C:/labo2/x64/Release")
>>> import labo2
Pour la ligne suivante, il faut mettre le chemin de l'étape 1 entre les guillemets
>>> labo2.start("C:/Example.avi")

11. Votre vidéo téléchargée à l'étape 1 partira et vous pourrai inscrire les commandes voulues dans la console Python pour jouer avec votre vidéo

12. Voici les instructions des touches 
P – Play ou Pause
A – Avance accélérée (1.25x)
R – Retour au début
Q - Quitter

