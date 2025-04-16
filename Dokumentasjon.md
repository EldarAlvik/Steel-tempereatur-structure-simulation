# Forsøk på stål-simulator live

Dette prosjektet er en begynnelse på en 2-dimensjonell implementasjon av en simulator for stål ved forskjellige temperaturer. Planen er å videreutvikle og implementere mer av dette prosjektet fremover.

-Laget av Eldar Alvik
---

## GitHub Link
https://github.com/EldarAlvik/Steel-tempereatur-structure-simulation

## Refleksjon
Jeg føler dette prosjektet har vært veldig moro selv om jeg har bitt over litt for mye og endt opp med å ikke kunne fullføre alt jeg ønsket.

Det jeg slet mest med var å definere simuleringslogikken, siden det er den vanskeligste delen. Det tok meg godt og vel halvannen uke å pønske ut hvordan dette skulle settes opp.

Angående KI har jeg brukt den til å lage sjekklister for hva som må implementeres. Dette har jeg funnet som en god måte å bruke verktøyet på - jeg ba den ikke om å lage hele koden, men bare gi meg funksjonsnavn. Det har vært et nyttig verktøy for å få svar på spørsmål.

Dette prosjektet har gjort at jeg har lært utrolig mye på kort tid.

Planen for videre utvikling av programmet og rammene for dette er godt forankret, og det er dette jeg har brukt mye tid på for å gjøre videre implementering enklere. Simulasjonslogikken er allerede påbegynt, men ble for omfattende for å kunne implementeres fullstendig.

Til fremtidige prosjekter vil det være lurt å legge en grundigere plan og snevre inn omfanget tidligere.

## Brukerinstrukser

Programmet kompileres og kjøres ved hjelp av TDT4102-utvidelsen i VS Code.  
I `main.cpp` kalles `runSimulation()` uten argument. Deretter initialiseres simulatoren.
For øyeblikket beveger atomene seg helt tilfeldig.

Per nå kan man:
- Starte simulatoren
- Sette simulatoren på pause
- Restarte simulatoren
- Lagre tilstanden
- Laste simulatoren

---

## Programstruktur

Programmet består av følgende hovedkomponenter:

- **`main.cpp`**  
  Starter programmet, initialiserer simulasjonsmiljøet og GUI.

- **`simulationControl.cpp/.h`**  
  Kontrollerer hovedsimuleringssløyfen, håndterer atomvisualisering og brukergrensesnitt.

- **`simulationLogic/simulation.cpp/.h`**  
  Implementerer kjernesimuleringmekanikk, temperaturkontroll og atomhåndtering.

- **`atomAndStructure/atom.cpp/.h`**  
  Definerer atomatferd med spesialiserte Carbon- og Iron-klasser.

- **`atomAndStructure/grain.cpp/.h`**  
  Representerer krystallinske strukturer dannet av atomer.

- **`atomAndStructure/phaseTransformer.cpp/.h`**  
  Håndterer fasetransformasjonslogikk basert på temperatur og kjølingshastighet.

- **`simulationLogic/environment.cpp/.h`**  
  Administrerer rutenettssystemet for atomplassering og bevegelse.

- **`animation/buttonLogic.cpp/.h`**  
  Implementerer UI-kontroll callbacks for simuleringshåndtering.

- **`animation/animation.cpp/.h`**  
  Gir simuleringsvinduet og renderingsfunksjonalitet.

---

## Hovedfunksjonalitet

### 1. Simulation-klassen
- Administrerer atomsamlinger og deres atferd
- Kontrollerer temperatur- og kjølingshastighetparametere
- Tilbyr oppdateringslogikk for simuleringsprogresjon
- Håndterer lagring og lasting av simuleringstilstander

### 2. Atom-systemet
- Base Atom-klasse med avledede Carbon og Iron-typer
- Posisjonssporing gjennom koordinatsystem
- Kornbinding og fasetransformasjonskapasiteter
- Bevegelseslogikk basert på temperatur og begrensninger

### 3. GridCoordinate-systemet
- Organiserer atomer i et 2D-rutenett for effektive romlige operasjoner
- Kontrollerer atomplassering og bevegelse innenfor grenser
- Tilrettelegger for nabodeteksjon for fasetransformasjoner

### 4. Animation-systemet
- Renderer simuleringstilstand med fargekodede atomer
- Gir interaktive kontroller gjennom GUI-elementer
- Viser simuleringsstatistikk og parametere

---
