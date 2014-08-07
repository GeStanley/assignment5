#include <fstream>
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <stdexcept>

#include "MyPair.h"
#include "WordVector.h"
#include "WordMap.h"
#include "WordMultiSet.h"

// allow the following names into the current name space
using std::string;
using std::istream;
using std::ifstream;
using std::invalid_argument;
using std::toupper;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

// Test function prototypes
void TestWordVector  (istream& inputStream);
void TestWordMap     (istream& inputStream);
void TestWordMultiSet(istream& inputStream);

// helper function prototypes
void open_input_stream(ifstream& input_file_stream, string& filename) ;

int main()
{
   while (true)
   {
      string filename;
      cout << "Enter the name of the input file (enter empty name to quit): ";
      getline(cin, filename);
      if (filename.empty()) break;  // quit on empty file name
      ifstream inputStream;
      try
      {
         // test WordMap
         //open_input_stream(inputStream, filename);
         //TestWordMap(inputStream);
         //inputStream.close();

         // test WordMultiSet
         //open_input_stream(inputStream, filename);
         //TestWordMultiSet(inputStream);
         //inputStream.close();

         //test WordVector
         open_input_stream(inputStream, filename);
         TestWordVector(inputStream);
         inputStream.close();
      }
      catch (const std::invalid_argument ia)
      {
         cout << "Error: " << ia.what() << endl;
         string answer;
         do
         {
            cout << "Do you wish to try again (y/n)? ";
            getline(cin, answer);

         } while (answer.empty());  // don't accept an empty answer
         if (toupper(answer[0]) != 'Y') break;  // take it as a yes if answer begins with a y or Y
      }
   }
   cout << "bye" << endl;
   return 0;
}

//________________________________________________________________________________________________________________

void open_input_stream(ifstream& input_file_stream, string& filename)
{
   input_file_stream.open(filename);
   if (!input_file_stream)
   {
      throw std::invalid_argument("Could not open input file: " + filename);
   }
}
///
//________________________________________________________________________________________________________________

void TestWordVector(istream& inputStream)
{
   if (!inputStream.good())
      throw std::invalid_argument("bad input stream");

   WordVector wordvec(inputStream);
   int size = wordvec.size();
   wordvec.insert("BBB"); wordvec.insert("BBB"); wordvec.insert("BBB");
   wordvec.insert("AAA"); wordvec.insert("AAA"); wordvec.insert("AAA");
   wordvec.insert("CCC"); wordvec.insert("CCC"); wordvec.insert("CCC");
   assert(wordvec.lookup("BBB") == 3);
   assert(wordvec.lookup("AAA") == 3);
   assert(wordvec.lookup("CCC") == 3);
   assert(wordvec.size() == size + 3);

   wordvec.remove("AAA");
   assert(wordvec.lookup("AAA") == 0);
   wordvec.remove("CCC"); wordvec.remove("CCC");
   assert(wordvec.lookup("CCC") == 0);
   assert(wordvec.size() == size + 1);

   cout << "\n========================" << endl;
   cout << "TestWordVector: unsorted" << endl;
   cout << "========================" << endl;
   wordvec.print();
   wordvec.sort();
   cout << "\n======================" << endl;
   cout << "TestWordVector: sorted" << endl;
   cout << "======================" << endl;
   wordvec.print();

   cout << "----------------------------------" << endl;
   cout << "WordVector container size :" << wordvec.size() << endl;
   cout << "WordVector total frequency count :" << wordvec.sum_frequency_count() << endl;
   cout << "----------------------------------" << endl;
}
//________________________________________________________________________________________________________________
