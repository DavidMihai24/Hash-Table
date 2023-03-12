[//]: # "GHELESEL David-Mihai"

###Implementarea Tabelei Hash

Pentru realizarea acestui proiect, am folosit urmatoarele structuri:

1. WordCount
2. WordList
3. HashTable
4. LinkedList

Primele doua structuri erau si cele mai simple, deoarece contineau
cea mai putina informatie. Am folosit structura **_WordCount_** pentru a
stoca un anumit cuvant si numarul de aparitii al cuvantului in text. Aceasta
informatie mi-a fost de folos atunci cand trebuie sa sortez lista de cuvinte
de o anumita dimensiune, dupa introducerea unui cuvant nou.

Pe de alta parte,
**_WordList_** reprezenta, intr-un fel, coloana verticala a cuvintelor din
tabela hash. Prin "coloana verticala", ma refer la faptul ca **_WordList_**
continea un numar (ce reprezenta numarul de litere) si o lista generica
simplu inlantuita de cuvinte care aveau lungimea egala cu numarul de litere
respectiv. Astfel, daca am vizualiza pe verticala desenul din pdf-ul temei,
aceasta structura ar putea fi vizualizata uitandu-ne de sus in jos, incepand
cu un cuvant care are cele mai multe aparitii si continuand inspre cuvintele
cu mai putine aparitii. Desigur, daca numarul de aparitii este acelasi, se ia
in considerarea ordinea lexicografica.

Structura **_HashTable_** urmeaza modelul dat in descrierea din pdf-ul cu enuntul
temei. Astfel, am folosit un numar M pentru a stoca numarul de elemente din tabela hash
(in cazul nostru numarul de litere), o functie fh care calculeaza indexul din tabel
al unui anumit element si, in cele din urma, v, o lista generica simplu inlantuita care continea
la randul sau o alta lista, dupa cum am explicat mai sus prin expunerea
scopului lui WordList.

In final, **_LinkedList_** reprezinta o lista generica simplu inlantuita, aceasta
a fost structura cea mai folosita in acest proiect.
