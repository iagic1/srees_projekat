# srees_projekat
Aplikacija za računanje parametara transformatora, vodova/kablova

IZVORI INFORMACIJA:
https://drive.google.com/drive/folders/1qLmLwImqO_oc3IfQiqUCvNHCmYQY-s4R
Dodatno -> NatID - za instalaciju (ovo radi u posljednoj verziji)
Predavanja (BA06 pa nadalje) - okvirne upute kako funkcioniše

ZA POKRETANJE:
Mislim da tamo ne piše, projekat se treba buildat u CMake-u: staviti putanju SRES (ne ulaziti dublje), staviti gdje će se buildati, zatim Configure, Generate i Open project

URAĐENI PRIMJERI:
DRIVE: Dodatno, Laboratorijske vježbe, Tutorijali - LV5 pa nadalje

GUIDE ŠTA RADITI DALJE:
- Dodati preostale šeme transformatora:
-   res/symbols: ovdje dodati, pratiti postojeće šeme
-   res/main.xml: ovdje dodati ime šeme i putanju do nje - TO SE IME KORISTI U PROGRAMU
-   src/ViewTransformators.h - ovdje se dodaju na sljedeći način:
-     dodat gui::Symbol varijablu
-     definisati je u konstruktoru kao _symbol(":IME_ŠEME")
-     dodati je u niz na dnu - td::vector<gui::Symbol> _syarray
-   src/ThreePhaseTransf.h - ovdje se dodaju na sljedeći način:
-     dodati u niz na dnu - std::vector<Transformer> t i to kao {ID, "IME_ŠEME", "KOJA DVA TRANSF ČINE ŠEMU", TIP, SATNI_BROJ},
-     TIP - Yy je 1, Yd je 2, Dy je 3, Dd je 4
- Dodati formule:
-  src/ViewFormulasCanvas.h - ovdje se trebaju dodati kao i slike, samo što će biti:
-     gui::Image _img;
-     mislim da se crtanje slika ne razlikuje previše od simbola, ali to se može provjeriti u \Work\CPProjects\GUI\TestNavigator\src\ViewCanvas.h
- Za dodavanje koda vezanog za Dd već treba fino preći src/ThreePhaseTransf.h ali otp:
-    td::Decimal4 - decimalni broj, za njeg je dovoljno varijabla.getValue().dec4Val() (prvo čita iz numeric edita vrijednost, drugo pretvara u td::Decimal4)
-    td::cmplx - kompleksni broj sa običnim realnim vrijednostima, zato je porebno i .getAsFloat()
-    funkcije elementWise i matrixMultiplication mogu biti od pomoći

!!!SAVJET!!! POKRENUTI KOD SVAKIH MALO JER SAMO ŠTO NE IZBACI GREŠKU NE ZNAČI DA JE UREDU!!!

Sretno :)
