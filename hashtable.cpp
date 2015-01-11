#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int TABLE_SIZE = 100;

template <class Tv>
class HashTable
{
  private:
    vector< vector< pair<string, Tv> > > table;
    unsigned long hashfunc(string key);
  public:
    void insert(string key, Tv value);
    Tv value(string key);
    HashTable();
};

template <class Tv>
HashTable<Tv>::HashTable()
{
  table.push_back(vector< pair<Tv, string> >(1, make_pair("", "")));
}

template <class Tv>
unsigned long HashTable<Tv>::hashfunc(string key)
{
  unsigned long hash = 5381;
  int c;
  for(int i = 0; i < key.size(); i++) {
    c = key[i];
    hash = c + (hash << 6) + (hash << 16) - hash;
  }
  return hash % TABLE_SIZE;
}

template <class Tv>
Tv HashTable<Tv>::value(string key)
{
  int hash = hashfunc(key);
  Tv value;
  for(int i = 0; i < table[hash].size(); i++) {
    if(table[hash][i].first == key) {
      value = table[hash][i].second;
      break;
    }
  }
  return value;
}

template <class Tv>
void HashTable<Tv>::insert(string key, Tv value)
{
  int hash = hashfunc(key);
  if(table.size() < hash + 1) {
    table.resize(hash + 1);
  }
  table[hash].push_back(make_pair(key, value));
}

int main(int argc, char **argv)
{
  HashTable<string> map;
  ifstream file("names.txt");
  string fname, lname;

  while(file >> fname >> lname) {
    map.insert(fname, lname);
  }

  file.clear();
  file.seekg(0, ios::beg);

  while(file >> fname >> lname) {
    cout << fname << " " << map.value(fname) << endl;
  }

  file.close();
}
