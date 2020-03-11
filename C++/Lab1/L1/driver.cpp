#include "Wrapper.h"
#include "createInstance.h"





void loadRandomIntoSequence(IntegerSequence& s, Integer numberToLoad)
//! replaces s
//! restores numberToLoad
//! requires: numberToLoad >= 0
//! ensures: |s| = numberToLoad and s contains integers generated from rand() function
{
	for (int k = 0; k < numberToLoad; k++) {
		Integer y = rand() % 1000;
		s.add(0,y);
	} // end for
} // loadRandomIntoQueue

void displaySequence(IntegerSequence& s)
//! restores s
//! ensures: contents of s are displayed, separated by commas
{
	IntegerSequence sTemp;

	wcout << "<";
	for (int k = 0, z = s.length(); k < z; k++) {
		Integer y;

		s.remove(0,y);
		wcout << y;
		if (s.length() > 0) {
			wcout << ",";
		} // end if
		sTemp.add(0,y);
	} // end for
	wcout << ">";
	s.transferFrom(sTemp);
} // displayQueue



 


void moveLargestToFront(IntegerSequence& s)
//! updates s
//! requires: |s| > 0
//! ensures: the largest value found in s is moved to position zero and
//!          perms(#s, s)
{
	Integer largest, count, temp;	//stores current largest, counts up to s.length, hold value for teting
	{
		s.remove(0, largest);
		while (count < s.length())
		{
			s.remove(0, temp);
			if (temp > largest)
			{
				s.add(s.length() - 1, largest);
				largest = temp;   //temp > largest, assign new largest										
			}
			else  //temp < largest...
			{
				s.add((s.length() - 1), temp); // put temp in back of the sequence........
			}
			//wcout << "temp " << temp << "\n";
			//wcout << "large " << largest << "\n";
			count++;
		}

		s.add(0, largest);  //add largest to front of sequence
	}//end while loop
} // moveLargestToFront

  //-------------------------------------------------------------------

void reverse(IntegerSequence& s)
//! updates s
//! ensures: s = rev(#s)
{
	IntegerSequence sTemp;
	Integer count, temp;
	Integer len = s.length();
	for (count = 0; count < len; count++)
	{
		s.remove(0, temp);
		sTemp.add(0, temp);
	}
	s = sTemp;
} // reverse

//-------------------------------------------------------------------
// main executable body
//-------------------------------------------------------------------

int main(int argc, char* argv[])
{
	// Do not change the next 5 lines
	Integer numToLoad = 7;
	if (argc > 1) {
		// obtain from the command line the number of integers to load
		numToLoad = atoi(argv[1]);
	} // end if


	
	IntegerSequence s1, s2;

	wcout << "s1 = " << s1 << endl;
	loadRandomIntoSequence(s1, numToLoad);
	wcout << "s1 = " << s1 << " after loading " << numToLoad << " items into s1" << endl << endl;





	wcout << "Display s1 using displaySequence: ";
	displaySequence(s1);
	wcout << endl << endl;



	wcout << "s1 = " << s1 << " before moving largest to the front" << endl;
	moveLargestToFront(s1);
	wcout << "s1 = " << s1 << " with largest at the front" << endl << endl;



	wcout << "s1 = " << s1 << " before Reversing " << endl;
	reverse(s1);
	wcout << "s1 = " << s1 << " After Reversing" << endl << endl;

	system("pause");
	return 0;
}	// end main

