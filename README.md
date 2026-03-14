Praktikum Informatik 2
======================

Dieses Projekt enthält CodeBlocks-Projekte und Beispieldateien. Die Inhalte zu den verschiedenen
Aufgaben werden im Laufe des Semesters sukzessive hier ergänzt.

Bevor Sie mit der Arbeit an ihrem ersten PIN2 Projekt beginnen, sollten Sie
folgende Punkte beachten:

Fork erzeugen
-------------

Klicken Sie auf **Fork** und anschließend auf Ihren Namen. Nach einem kurzen
Moment befinden Sie sich in Ihrer eigenen Kopie (=Fork) des Projekts PIN2.

Betreuer hinzufügen
-------------------

Damit Ihre Betreuer Ihre Arbeit bewerten können, wird der Gruppe
 *PIN2/Dozenten* automatisch Zugriff mit *Maintainer*-Rechten gewährt, dafür
müssen Sie niemand explizit hinzufügen. 


Projekt klonen
--------------

Damit Sie an Ihrem Projekt arbeiten können, müssen Sie zunächst eine lokale
Kopie ihres Projekts erzeugen. Starten Sie `Git Bash` und wechseln Sie in das
Verzeichnis in dem Sie ihre lokale Kopie erstellen wollen. Verwenden Sie
`git clone` zum Erstellen der lokalen Kopie. Verwenden Sie dabei die Adresse
ihres Forks z.B. `https://gitlab.oth-regensburg.de/abc12345/pin2_s2026.git`


 Upstream Remote hinzufügen
--------------------------

Das Projekt wird im Laufe des Semesters immer wieder ergänzt. Damit Sie diese
Ergänzungen in Ihren Fork übernehmen können, müssen Sie einen zusätzlichen
`remote` zu Ihrem Projekt hinzufügen.

Wechseln sie zunächst in Ihre lokale Kopie:

    cd pin2_s2026

Verwenden Sie `git remote` um das `upstream`-Projekt hinzuzufügen:

    git remote add upstream https://gitlab.oth-regensburg.de/EI/LV/PIN2/pin2_s2026.git

Sie können nun die Ergänzungen am `upstream`-Projekt durch den Aufruf von

    git pull upstream master

in Ihrem Projektverzeichnis übernehmen.


**Denken Sie beim Lösen der Aufgaben unbedingt an regelmäßige Commits!**

Alle weiteren Informationen zum Praktikum finden Sie im E-Learning Kurs:

https://elearning.oth-regensburg.de/course/view.php?id=7992
