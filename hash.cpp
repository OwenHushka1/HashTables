// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    cout << "hear" << endl;
    //TODO: Search the list at that specific index and return the node if found
    if(table[index]->key == key){
        return table[index];
    }
    else{
        cout << "here" << endl;
        node* nw = table[index];
        cout << "here" << endl;
        while(nw != NULL){
            nw = nw->next;
            if(nw->key == key){
                return nw;
            }
            cout << "got here too" << endl;
        }
        return NULL;
    }

}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    cout << "got here" << endl;
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        node *newNode = new node;
        newNode->key = key;
        int index = hashFunction(key);
        cout << "got here" << endl;
        if(table[index] == NULL){
            table[index] = newNode;
            return true;
        }
        else{
            table[index]->next = newNode;
            return true;
        }


     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        

        //TODO
    }

 }
