Sistem de Gestiune Pariuri Sportive - Proiect POO
1. Descrierea Problemei
   Proiectul implementeaza un sistem de gestiune a evenimentelor sportive si a biletelor de pariuri. Obiectivul este de a simula un mediu real in care diferite sporturi au reguli de calcul diferite pentru cote si bonusuri, iar utilizatorul poate crea bilete complexe (acumulator) beneficiind de bonusuri progresive.

2. Detalii de Implementare si Cerinte Tehnice
   Ierarhia de Clase (Mostenire si Polimorfism)
   Proiectul foloseste o ierarhie de clase cu baza proprie, pornind de la clasa abstracta Sport.

Clase Derivate: Fotbal, Tenis si Baschet.

Functii Virtuale Pure:

calculeazaCastig(miza): Implementeaza formule specifice fiecarui sport (taxa la fotbal, bonus de suprafata la tenis, bonus de limita la baschet).

clone(): Implementeaza pattern-ul Prototype pentru a asigura copierea polimorfica corecta prin pointeri de baza.

Interfata Non-Virtuala (NVI): Metoda afisareEvenimente() din clasa de baza Sport controleaza fluxul de afisare, apeland metoda virtuala privata afisareSpecifica() din derivate.

Gestiunea Resurselor si Smart Pointers
Smart Pointers: Se utilizeaza std::shared_ptr pentru a gestiona colectia de evenimente din clasa Bilet si din oferta globala, prevenind scurgerile de memorie.

Copy-and-Swap Idiom: Clasa Bilet implementeaza constructorul de copiere (Deep Copy prin clone()), functia swap si operatorul de atribuire pentru a asigura gestiunea sigura a resurselor si siguranta la exceptii.

Exceptii (Ierarhie Proprie)
Proiectul include o ierarhie de exceptii derivate din std::runtime_error:

MizaInvalida: Aruncata daca miza biletului este negativa.

CotaInvalida: Aruncata daca datele din fisier contin cote mai mici sau egale cu 1.0.

EroarePariuri: Clasifica erori de business, cum ar fi incercarea de a paria pe egal (X) in tenis.

Functionalitati Avansate
Recursivitate: Calculul bonusului progresiv pentru bilete multiple este realizat prin metoda calculeazaProcentRecursiv. Aceasta adauga 5% bonus pentru fiecare meci ce depaseste pragul de 3 evenimente.

Dynamic Cast (RTTI): Utilizat in functiile verificaDetaliiFotbal si filtreazaDupaSport pentru a identifica tipul real al obiectului la runtime si a accesa functionalitati specifice (ex: getArePrelungiri() pentru Fotbal).

Atribute Statice: Variabila nrEvenimenteActive din clasa Sport monitorizeaza in timp real numarul de evenimente incarcate in memorie.

3. Structura Fisierelor
   sport.h/.cpp - Clasa de baza abstracta.

fotbal.h/.cpp, tenis.h/.cpp, baschet.h/.cpp - Specializari sportive.

bilet.h/.cpp - Gestionarea colectiei de pariuri si a bonusurilor.

erori.h - Definirea ierarhiei de exceptii.

main.cpp - Punctul de intrare (citire fisier, testare logica, afisare).

Meciuri_bilet - Fisierul de intrare cu datele meciurilor.

4. Exemplu de Utilizare (Main)
   In main.cpp, programul parcurge urmatoarele etape:

Incarca oferta dintr-un fisier text cu validare riguroasa.

Filtreaza polimorfic meciurile de Tenis folosind dynamic_cast.

Creeaza bilete cu mize diferite.

Demonstreaza sistemul de bonusare recursiva pentru „Biletul Gigant”.

Trateaza eventualele erori prin blocuri try-catch.

Autor:Comarniceanu Albert Nicolae

Grupa: 132

An academic: 2025-2026