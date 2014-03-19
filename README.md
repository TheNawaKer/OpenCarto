OpenCarto - Projet LostIsland : Créer une carte d'altitude pour une île et permettre son survol.
==============================

1. Construire un tableau 2D contenant des valeurs d'altitude aussi appelé une heightmap. 
Le point d'altitude le plus bas est en noir, le point d'altitude le plus haut est en blanc. 
Vous pouvez utiliser un éditeur d'image tel que Gimp pour créer le fichier image, et lire ce fichier à partir de la bibliothèque que DevIL. 
Afin d'obtenir une île, il faut que les altitudes aux environs des bords de la carte soient au dessous du niveau de la mer.

2. Afficher en OpenGL le maillage correspondant au tableau en le stockant dans un VBO. Il faut pour cela générer un tableau d'indices indiquant dans quel ordre former les triangles. Vous pouvez modéliser le niveau de la mer par un grand rectangle bleu transparent couvrant toute
votre carte.

3. Ajouter un tableau de couleurs associant à chaque point une couleur en fonction de son altitude : bleu au dessous du niveau de la mer, vert entre 2 altitudes, marron au delà d'une certaine altitude, etc.

4. Permettre le déplacement de la caméra.

5. Plaquer une texture sur votre terrain. Cette texture peut être créée à partir d'un éditeur d'image tel que Gimp. Il doit être possible de choisir soit le mode couleur en fonction de l'altitude, soit le mode texture.

6. Calculer les normales à chaque point et activer l'éclairage.

7. Placer des objets dans la scène dont au moins un importé à partir d'un fichier.off.

==============================
3 Ressources
==============================
Heightmap, Wikipédia : http://en.wikipedia.org/wiki/Heightmap

Bibliothèque C de manipulation d'image DevIL : http://openil.sourceforge.net/

Génération d'une heighmap sous Gimp et importation dans Blender : http://en.wikibooks.org/...

Génération avancée d'une heighmap :http://linuxfr.org/...

Exemples OpenGL : http://warppipe.net/blog/?page_id=342