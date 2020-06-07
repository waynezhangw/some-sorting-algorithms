#pragma once
//reading class
#include "wayne_sortThem.h"


#include<vector>

using namespace std;
class wayne_getThem
{
public:
	wayne_getThem(void);
	~wayne_getThem(void);

	void readODTrip();                                   // one million scale
	void readODTripSorted();
	double convertStringToDouble(string str1); 
	void makeFileOfVector(vector<double> &vec1);
	void run();  

private:
	vector<double> OGrid_X;                 
	vector<double> sorted_OGrid_X;         
	wayne_sortThem* obj_sort1;    // class object
};

