#include <iostream>
#include <string>
using namespace std;

#define MAX_CAP 100000
#define ERROR -1

class Node
{
public:
        Node(string word);
        string word;
        int count;
};

Node::Node(string word) : word(word), count(1) {}

class HashTable
{
private:
        Node** hashTable;
        int size;
        int capacity;
        unsigned long getHash(string word);
        bool checkSize();
        int increment(int number);
        void increaseSize();
        int findLast(string word, int index);
public:
        HashTable();
        void insert(string word);
        void remove(string word);
        int getValue(string word);
        ~HashTable();
};

HashTable::HashTable() : capacity(MAX_CAP), size(0)
{
        this->hashTable = new Node * [this->capacity];
        for (int i = 0; i < this->capacity; i++)
                this->hashTable[i] = nullptr;
}

unsigned long HashTable::getHash(string word)
{
        unsigned long hash = 0;
        for (int i = 0; i < word.length(); i++) {
                hash += word[i];
                hash = (hash * 17) % capacity;
        }
        return hash;
}

bool HashTable::checkSize()
{
        return this->size > (this->capacity / 2);
}

int HashTable::increment(int number) {
        return (++number) % this->capacity;
}

void HashTable::increaseSize()
{
        int cap = this->capacity;
        this->capacity *= 2;
        Node** temp = this->hashTable;
        this->hashTable = new Node * [this->capacity];
        this->size = 0;

        for (int i = 0; i < capacity; i++)
                this->hashTable[i] = nullptr;

        for (int i = 0; i < cap; i++)
                if (temp[i])
                        insert(temp[i]->word);

        delete[] temp;
}

void HashTable::insert(string word)
{
        int hash = getHash(word);
        while (this->hashTable[hash])
        {
                if (this->hashTable[hash]->word == word)
                {
                        this->hashTable[hash]->count++;
                        return;
                }
                hash = increment(hash);
        }
        this->hashTable[hash] = new Node(word);
        this->size++;
        if (checkSize()) increaseSize();
}

void HashTable::remove(string word)
{
        int hash = getHash(word);
        while (this->hashTable[hash])
        {
                if (this->hashTable[hash]->word == word)
                        break;

                hash = increment(hash);
        }

        if (!this->hashTable[hash])
                return;

        int last = findLast(word, hash);

        if (last != ERROR)
        {
                this->hashTable[hash]->count = this->hashTable[last]->count;
                this->hashTable[hash]->word = this->hashTable[last]->word;
                delete this->hashTable[last];
                this->hashTable[last] = nullptr;
        }
        else
        {
                delete this->hashTable[hash];
                this->hashTable[hash] = nullptr;
        }
        this->size--;
}

int HashTable::findLast(string word, int index)
{
        int hash = getHash(word);
        index = (++index) % this->capacity;

        int lastIndex = ERROR;
        while (this->hashTable[index])
        {
                if (getHash(this->hashTable[index]->word) == hash)
                        lastIndex = index;

                index = increment(index);
        }
        return lastIndex;
}

int HashTable::getValue(string word)
{
        int hash = getHash(word);
        while (this->hashTable[hash])
        {
                if (this->hashTable[hash]->word == word)
                        return this->hashTable[hash]->count;

                hash = increment(hash);
        }
        return 0;
}

HashTable::~HashTable() {
        delete this->hashTable;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        HashTable hashTable;
        string inputLine;
        while (inputLine != "q")
        {
                cin >> inputLine;
                if (inputLine[0] == '?')
                {
                        inputLine.erase(0, 1);
                        cout << hashTable.getValue(inputLine) << endl;
                }
                else if (inputLine[0] == '-')
                {
                        inputLine.erase(0, 1);
                        hashTable.remove(inputLine);
                }
                else hashTable.insert(inputLine);
        }
        return 0;
}
