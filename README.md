# PM-project
Descrierea codului aplicaţiei
1. Mediu de dezvoltare: Arduino IDE
2. Librării şi surse 3rd-party:
  - Adafruit GFX library - pentru afisat grafica pe ecran
  - Adafruit Nokia 5110 LCD Library - pune la dispozitie o serie de functii pentru a usura interactiunea cu LCD-ul

3. Surse şi funcţii implementate:
  - project.ino:
      - definesc constantele (notele, butoanele, buzzerul, LED-urile)
      - functia void setup: declar pinii. Initializez comunicatia seriala si ecranul. Setez contrastul la 65 folosind functia setContrast(). Pentru a aplica modificarile pe LCD, folosesc display().
      - functia void loop: apelez drawMenu() care imi creeaza si afiseaza meniul pe ecran (am atasat poze la sectiunea Rezultate Obţinute). Verific starea butoanelor corespunzatoare LCD-ului folosind functiile checkIfDownButtonIsPressed() si checkIfSelectButtonIsPressed(). In functie de ce buton e apasat, si pe ce pagina ma aflu, execut actiunea necesara (fie de activare a unuia din cele trei moduri, fie de selectare a unei melodii).
      - checkIfDownButtonIsPressed(), checkIfSelectButtonIsPressed(): ma folosesc de starea anterioara a butonului pentru a vedea daca acesta a fost sau nu apasat.
  - freemode.ino: 
      - cat timp butonul este setat pe ON, ma aflu in Freestyle Mode. Verific daca vreunul din butoane este apasat, caz in care aprind LED-ul corespunzator cu digitalWrite(LED,HIGH) si redau sunetul cu ajutorul functiei tone(Buzz,NOTE).
  - play_song1.ino, play_song2.ino, play_song3.ino: 
      - fiecare program are retinuta o piesa in memoria locala. Setez tempoul, vectorul in care e retinuta piesa si durata notelor. Apoi, redau cu ajutorul buzzerului melodia. La final, se iese din functie si se intoarce in loop din project.
  - learn_song1.ino, learn_song2.ino, learn_song3.ino: 
      - fiecare program are retinuta o piesa in memoria locala. Retin piesa intr-un vector, apoi aprind pe rand LED-ul din dreptul notei care trebuie apasate. LED-ul se va stinge doar in momentul in care utilizatorul a apasat butonul corect, ajutand-ul astfel sa invete melodia dorita. La final, se iese din functie si se intoarce in loop din project.
