#include <iostream>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash{
private:
    static const int tableSize = 10;

    struct item {
        string name;
        string drink;
        item* next;
    };

    item* HashTable[tableSize];


public:
    hash();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
};


hash::hash()
{
/* Hash table init */
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item; /* use new to allocate struct !! */
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

int hash::Hash(string key)
{
    int hash = 0;
    int index;

/* Simple Hash Func 1 */    index = key.length();

/* Simple Hash Func 2 */    
    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i])*17 + 7;
        cout << "hash = " << hash << endl;
    }

    index = hash % tableSize;
    return index;
}

void hash::AddItem(string name, string drink)
{
    int index = Hash(name);

    if(HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    } else {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(Ptr->next != NULL){
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index]->name == "empty"){
        return 0;
    } else {
        item* Ptr = HashTable[index];
        count++;
        while(Ptr->next != NULL){
            Ptr = Ptr->next;
            count++;
        }
    }
   
   return count; 
}

void hash::PrintTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "--------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "# of items = " << number << endl;
        cout << "--------------------\n";
    }
}

void hash::PrintItemsInIndex(int index)
{ 
    if(HashTable[index]->name == "empty"){
        return;
    } else {
        item* Ptr = HashTable[index];
        cout << "--------------------\n";
        cout << "index = " << index << endl;
        cout << Ptr->name << endl;
        cout << Ptr->drink << endl << endl;

        while(Ptr->next != NULL){
            Ptr = Ptr->next;
           cout << Ptr->name << endl;
           cout << Ptr->drink << endl << endl;
        }
        cout << "--------------------\n";
    }
}

int main(int argc, char** argv)
{
    int index;
    hash hashy;

    hashy.AddItem("Paul", "Water");
    hashy.AddItem("John", "Lemonade");
    hashy.AddItem("Kate", "Coke");
    hashy.AddItem("Kerry", "Pepsi");
    hashy.AddItem("James", "Sprite");
    hashy.AddItem("Lucy", "WhiteRussian");
    hashy.AddItem("Kelvin", "ScrewDriver");
    hashy.AddItem("Sara", "RootBeer");
    hashy.AddItem("Andy", "OrangeJuice");
    hashy.AddItem("Johny", "Gatorade");

    hashy.PrintTable();
    hashy.PrintItemsInIndex(9);


    return 0;
}
