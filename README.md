# OS-Process-Management-C
Questa cartella contiene una serie di esercizi focalizzati sulla creazione di processi tramite fork(), la comunicazione tra processi (IPC) e la gestione dei segnali in ambiente Linux/Unix.

## 🏆 Obiettivi dell'Esercitazione 
L'obiettivo è padroneggiare le chiamate di sistema per:
- Generazione di processi figli (fork).
- Sincronizzazione base tra processi.
- Scambio di dati tramite Pipe o messaggi (Esercizi 3-6).
- Esecuzione di comandi di sistema e invio segnali (kill) (Esercizi 7-8).

## 📂 Struttura degli Esercizi
| Esercizio | Descrizione Breve |
| :--- | :--- |
| **01** | Creazione di un processo figlio F1 da un padre P. |
| **02** | Creazione di due processi figli (F1, F2) dallo stesso padre P. |
| **03-04** | Comunicazione PID e interi casuali tra F1 e P. |
| **05-06** | Inoltro di dati attraverso una catena di processi (F1 -> P -> F2). |
| **07** | Utilizzo di `exec` o `rename` per rinominare file tramite stringhe ricevute. |
| **08** | Invio di segnali di sistema (0-31) a un PID specifico scelto dall'utente. |



## 🚀 Come compilare ed eseguire
```bash
gcc -o esercizio1 Esercizio_1/esercizio1.c
./esercizio1
```
