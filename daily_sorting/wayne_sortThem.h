#pragma once
// implement all kinds of sorting algorithms

#include<vector>



using namespace std;
class wayne_sortThem
{
public:
	wayne_sortThem(void);
	~wayne_sortThem(void);

	static bool ascending(double& x, double& y);
	static bool descending(double& x, double& y);

	void selectionSort(vector<double> &vec1,const vector<double> &vec2);                       //selection sort
	void bubbleSort(vector<double> &vec1,const vector<double> &vec2);                          //bubble sort
	void insertionSort(vector<double> &vec1,const vector<double> &vec2, bool (*comp)(double& a, double& b));                       //insertion sort

	void quickSort(vector<double> &vec1,const vector<double> &vec2, bool (*comp)(double& a, double& b));      //quick sort
	void quickSortSub(int left,int right,vector<double> &vec1, bool (*comp)(double& a, double& b));           //use in quickSort

	void heapSortLazy(vector<double>& vec1, const vector<double>& vec2, bool (*comp)(double& a, double& b));  //heap sort STL

	void heapSort(vector<double>& vec1, const vector<double>& vec2, bool (*comp)(double& a, double& b));      //heap sort step by step
	void buildHeap(vector<double>& vec, bool (*comp)(double& a, double& b));
	void adjustHeap(vector<double>& vec, int heapSize, int index, bool (*comp)(double& a, double& b));

	//To be continued...
	//merge sort
	//bucket sort
	//sleep sort
	//stack sort
	
};

