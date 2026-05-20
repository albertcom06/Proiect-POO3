# Proiect POO3 : Sistem gestiune pariuri sportive
**Autor**:Comarniceanu Albert
---

## 1. Introducere si Descrierea Schemei de Lucru (Tema Proiectului)
Proiectul implementeaza o aplicatie software scrisa in limbajul C++, ce simuleaza functionarea unui „Sistem de Pariuri Sportive” (inspirat din platforme reale precum Superbet). Scopul principal al aplicatiei este gestionarea eficienta, polimorfica si sigura a unei oferte de evenimente sportive dinamica, precum si procesarea biletelor de pariuri plasate de utilizatori.

Problema fundamentala rezolvata de acest sistem consta in modelarea unui domeniu de activitate in care entitatile (meciurile) au comportamente si atribute diferite in functie de specificul sportului (Fotbal, Tenis, Baschet), dar care trebuie tratate uniform de catre motorul de calcul al biletelor. Sistemul automatizeaza citirea datelor dintr-un fisier extern (`Meciuri_bilet`), instantierea memoriei prin mecanisme sigure de gestionare a pointerilor (`std::shared_ptr`), aplicarea de algoritmi recursivi pentru calculul bonusurilor de multiplicare si securizarea plasarii biletelor pe baza profilelor de utilizatori.

---

## 2. Evolutia Proiectului: Modificari si adaugari fata de etapele 1 si 2
Versiunea finala (Proiectul 3) este rezultatul indeplinirii treptate a celor 3 teme.

- **In Proiectul 1**, accentul a fost pus pe incapsularea de baza. S-au definit clasele fundamentale (`Sport`, `Fotbal`, `Bilet`), s-au implementat constructorii, destructorii si metodele de acces de baza. Gestiunea memoriei era rudimentara, bazata pe alocare statica sau pointeri clasici.
- **In Proiectul 2**, s-a realizat trecerea catre programarea polimorfica. Clasa `Sport` a devenit o clasa abstracta prin introducerea functiilor virtuale pure (precum `calculeazaCastig` si `afisareSpecifica`). S-au adaugat clasele derivate `Tenis` si `Baschet`. A fost introdus conceptul de *Constructor virtual* prin functia `clone()`, utilizata pentru copierea profunda a biletelor. Tot acum s-a implementat si gestiunea customizata a erorilor prin ierarhia proprie de exceptii (`EroarePariuri`, `MizaInvalida`, `CotaInvalida`), derivate din `std::runtime_error`.
- **In Proiectul 3 (Versiunea Curenta)**, codul a fost ridicat la un nou nivel prin adaugarea a doi piloni majori: **Sabloane (Templates)** si **(Design Patterns)**. Clasa `Bilet` a fost complet transformata intr-o clasa sablon (`Bilet<T>`), permitand atasarea de metadate dinamice fiecarui bilet (cum ar fi string-uri pentru coduri promotionale sau int-uri pentru ID-uri de utilizatori). Totodata, logica de control a fost distribuita prin trei design patterns decuplate: *Singleton*, *Factory Method* și *Proxy*.

---

## 3. Analiza Implementarii Sabloanelor (Templates)
In loc de a crea clase separate pentru diferite tipuri de bilete (bilet cu cod promotional, 
bilet cu ID de client), am transformat clasa `Bilet` 
intr-o structura generica: `template <typename T> class Bilet`.

Atributul `T detaliuBilet` stocheaza informatia specifica contextului în care biletul a fost emis. 
Acest mecanism a fost testat cu succes in `main.cpp` prin instantierea biletelor ca `Bilet<std::string>` 
(pentru coduri promotionale ca text) si `Bilet<int>` (pentru ID-uri numerice de sistem). 
Sprijinirea acestui sablon a necesitat mutarea intregii implementari a metodelor din `bilet.cpp` 
direct in header-ul `bilet.h`. Aceasta decizie este esentiala deoarece compilatorul C++ are nevoie de vizualizarea completa a sablonului in
momentul apelului in `main.cpp`,pentru a putea evita erorile clasice de legare.

De asemenea, am implementat un operator friend template (`operator<<`) care depinde de tipul `T` pentru 
afisarea directa in `std::cout`, precum si o funcție liberă template `afiseazaMesajSistem<T>` 
destinata jurnalizării (logging) acțiunilor administrative din agenție.