#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
class LinkedHashEntry {

public:

      LinkedHashEntry(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
      }
      int getKey() { return this->key; }
      int getValue() { return this->value; }
      void setValue(int value) {  this->value= value;  }
      LinkedHashEntry *getNext() {  return next;  }
      void setNext(LinkedHashEntry *next) {  this->next = next;}

private:
      int key;
      int value;
      LinkedHashEntry *next;
};
const int TABLE_SIZE = 128;
//clas hash
class HashMap {
private:
      LinkedHashEntry **table;
public:
      HashMap() {
        table = new LinkedHashEntry*[TABLE_SIZE];
        for (int i = 0; i< TABLE_SIZE; i++)
        {
              table[i] = NULL;

        }
      }
      ~HashMap() {
          for(int i = 0; i< TABLE_SIZE; i++){

              if (table[i] != NULL) {
                  LinkedHashEntry *prevEntry = NULL;
                  LinkedHashEntry *entry = table[i];
                  while (entry != NULL) {
                      prevEntry = entry;
                      entry = entry->getNext();
                      delete prevEntry;

                   }

               }
          }
          delete[] table;

        }


      int get(int key) {
          int hash = (key % TABLE_SIZE);
          if (table[hash] == NULL)
            return -1;

          LinkedHashEntry *entry = table[hash];
          while(entry && entry->getKey() != key)
            entry=entry->getNext();
          if(!entry)
              return -1;
          return entry->getValue();
      }
      //function input data in hash table
      void put(int key,int value)
      {
        int hash=(key%TABLE_SIZE);
        //cout << hash << endl;

        if(!table[hash])
        {
            //cout << "-->" << endl;
            table[hash]= new LinkedHashEntry(key,value);
            return;
        }
        //table[hash]= new LinkedHashEntry(key,value);
        LinkedHashEntry *entry= table[hash];

        while(entry->getNext())
        {
            entry=entry->getNext();
            /*if(entry->getValue()==value)
            {
                return;
            }*/
        }
        entry->setNext(new LinkedHashEntry(key,value));
      }
     //fuction for remove data in hash table
      void remove(int key)
      {
        int hash=(key%TABLE_SIZE);
        if(!table[hash])
            return;

        /*if (table[hash]->getKey() == key) {
                    LinkedHashEntry *temp = table[hash];
                    table[hash] = table[hash]->getNext();
                    delete temp;
                    return;
        }*/
        LinkedHashEntry *temporal=table[hash];
        LinkedHashEntry *temporal1=table[hash];
        temporal1=temporal1->getNext();
        while(temporal->getNext()!=NULL)
        {
            if(temporal->getKey()==key)
                delete temporal;
            table[hash]=temporal1;
            temporal1=temporal1->getNext();
            temporal=table[hash];
        }
        /*
        LinkedHashEntry *prevEntry = nullptr;
        LinkedHashEntry *entry = table[hash];
        while (entry && entry->getKey() != key) {
              prevEntry = entry;
              entry = entry->getNext();
        }

        if (!entry) return;

        prevEntry->setNext(entry->getNext());
        delete entry;
        */
      }

      //overload operator << for print hash table
      friend std::ostream& operator <<(std::ostream & out ,HashMap &hash)
      {
          for (int i = 0; i < TABLE_SIZE; ++i) {
            LinkedHashEntry *entry =hash.table[i];
            if(entry)
            {
                out << "[" << i << "]->" ;
            }
            while(entry)
            {
                out << "(" << entry->getKey() << ":" << entry->getValue()  << ")->" ;
                entry=entry->getNext();
            }
            if(hash.table[i])
            {
                out << "null\n";
            }

          }
          return out;
      }
};
#endif // LINKEDLIST_H
