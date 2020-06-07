#pragma once
// implement all kinds of sorting algorithms

#include<vector>



using namespace std;
class wayne_sortThem
{
public:
	wayne_sortThem(void);
	~wayne_sortThem(void);

	void selectionSort(vector<double> &vec1,const vector<double> &vec2);                       //selection sort
	void bubbleSort(vector<double> &vec1,const vector<double> &vec2);                          //bubble sort
	void insertionSort(vector<double> &vec1,const vector<double> &vec2);                       //insertion sort
	void quickSort(vector<double> &vec1,const vector<double> &vec2);                           //quick sort
	void quickSortSub(int left,int right,vector<double> &vec1);                                //use in quickSort

	//To be continued...
	//merge sort
	//bucket sort
	//sleep sort
	//stack sort
	
};

