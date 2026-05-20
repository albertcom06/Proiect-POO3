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