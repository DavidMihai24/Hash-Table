GHELESEL DAVID-MIHAI

Implementing a Hash Table

For this project, I used the following structures:

1. WordCount
2. WordList
3. HashTable
4. LinkedList

The first two structures were also the simplest, as they contained the least information. We used the WordCount structure to store a particular word and the number of occurrences of the word in the text. This information was useful when I needed to sort the list of words of a certain size after entering a new word.

On the other hand, WordList represents, in a way, the vertical column of words in the hash table. By "vertical column", I mean that WordList contained a number (representing the number of letters) and a simple generic list of words that were equal in length to that number of letters. Thus, this structure could be viewed by looking from top to bottom, starting with a word that has the most occurrences and continuing towards the words with the fewest occurrences. If the number of occurrences is the same, the lexicographic order is taken into account.

For the HashTable structure, we used a number M to store the number of elements in the hash table (in our case the number of letters), a function fh that calculates the index in the table of a given element, and finally v, a simple generic list containing in turn another list, as explained above (at the WordList structure).

Finally, **_LinkedList_** represents a simple linked generic list, this was the structure most used in this project.
