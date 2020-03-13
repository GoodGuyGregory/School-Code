#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> // FloorMod Operators
#include <sstream>

// Global Constant
#define Ratio 0.6180339887

using namespace std;

// Hashing Functions:

int divideHash(int key, int n)
{
    int hash = key % n;
    return hash;
}

int multiplyHash(int key, int n)
{
    int hash = floor(n * fmod(key * Ratio, 1));
    return hash;
}

int main()
{
    string str;
    ifstream infile;

    vector<string> createdKeys;
    vector<string> dataHolder;

    // Cast Database
    vector<int> hashKeys;
    vector<string> hashTable;

    int collision_counter = 0;

    infile.open("acs2015_county_data.csv");

    // Test fstream Connection
    if (!infile.is_open())
    {
        cout << "File cannot be opened";
    }

    string line, holder, key;

    while (infile.good())
    {
        getline(infile, line, '\r');
        dataHolder.push_back(line);
        stringstream keyValues(line);
        string value;

        vector<string> stringKeys;

        while (getline(keyValues, value, ','))
        {
            stringKeys.push_back(value);
        }
        createdKeys.push_back(stringKeys[1] + stringKeys[2]);
    }
    infile.close();

    // Create Size of the Table:
    int linearConstraints = 2 * createdKeys.size() + 1;
    // Resize Table
    hashTable.resize(linearConstraints);

    // Cast Strings to Ints in Vector:
    for (int i = 0; i < createdKeys.size(); i++)
    {
        int concatString = 0;
        int stringsToCast = createdKeys[i].size();
        for (int j = 0; j < stringsToCast; j++)
        {
            concatString += createdKeys[i][j];
        }
        hashKeys.push_back(concatString);
    }

    hashKeys.begin();

    // Hash Keys:
    for (int i = 0; i < hashKeys.size(); i++)
    {
        int hashedValue;

        // MultiplicationHashing
        hashedValue = multiplyHash(hashKeys[i], createdKeys.size());

        if (hashTable[i] == NULL)
        {
            hash.push_back(hashedValue);
        }
        else
        {
            collision_counter++;
            // Collision Handling For Linear Probing:
            // hashKeys[i+1]
        }
    }

    return 0;
}

// The Linear Probing Technique:
//  in order to complete the assignment a hash function must be utilized to create the appropriate, key value pairs for the program.
// The Hashing Technique used for this program is the multiplyHash Function Written from the Inclass activity.
// The hashing creates a unique value pair which will generate a unique location inside of the hash table and produce a unique value for the element,
// Collisions are handled with the incremented values from the table, with a for loop that will check for the values inside of the hash table.
// The values are then compared if the the value is NULL after the table size is incremented then the value will be added into the hash table, and the
// corresponding value will be added to the string relation for the hash data input. The Table size is incremented from the initial reading of the file,
// When the file is read it produces a set amount of data from the input file. The hashtable incrementation alllows for a stable load factor for the process to remain close to
// Linear or Constant time complexity.
