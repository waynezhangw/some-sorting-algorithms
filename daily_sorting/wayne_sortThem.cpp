#include "wayne_sortThem.h"
#include <utility>      // std::swap
#include<iostream>
#include <algorithm>

using namespace std;
wayne_sortThem::wayne_sortThem(void) {
}

wayne_sortThem::~wayne_sortThem(void) {
}


bool wayne_sortThem::ascending(double& x, double& y) {
	return x < y;
}
bool wayne_sortThem::descending(double& x, double& y) {
	return x > y;
}

void wayne_sortThem::selectionSort(vector<double> &vec1,const vector<double> &vec2) {
	cout << "selectionSort:" << endl;
	vec1=vec2; 
	int times=10000;
	int temp_i;
	for(unsigned int i=0;i<vec2.size()-1;i++) {                     //only use to n-1
		temp_i=i;
		for(unsigned int j=i+1;j<vec2.size();j++) {
			if(vec1[j]<vec1[temp_i]) {                               //non descending order
				temp_i=j;
			}
		}
		if(temp_i!=i) {
			swap(vec1[i], vec1[temp_i]);                  //non stable(5,8,5,2,9; 5 and 2 will swap, so the original two "5" will change)
		}
		if(i==times) {
			cout<<i<<endl;
			times=times+10000;
		}
	}
}

void wayne_sortThem::bubbleSort(vector<double> &vec1,const vector<double> &vec2) {
	cout << "bubbleSort:" << endl;
	vec1=vec2;
	int times=10000;
	bool flag=true;
	for(unsigned int i=0;i<vec2.size()-1;i++) {
		flag=false;
		for(unsigned int j=0;j<vec2.size()-i-1;j++) {
			if(vec1[j]>vec1[j+1]) {
				swap(vec1[j], vec1[j+1]);    // stable sort, relative order will not change
				flag=true;
			}
		}
		if(i==times) {
			cout<<i<<endl;
			times=times+10000;
		}
		if(!flag) {                      //if flag is false here, proved that the second for not exchange, so it is already sorted
			cout<<"improved bubble sort£º "<<i<<endl;          // only good for nearly sorted data
			break;
		}
	}
}

void wayne_sortThem::insertionSort(vector<double> &vec1,const vector<double> &vec2, bool (*comp)(double& a, double& b)) {
	cout << "insertionSort:" << endl;
	vec1=vec2;
	double temp;
	int times=10000;
	int insertPos;
	for(unsigned int i=1;i<vec2.size();i++) {
		temp=vec1[i];                                         //waiting for insertion
		insertPos=i;                                          //if no exchange below, it might already the biggest when inserting
		for(unsigned int j=i-1;j>=0 && comp(temp, vec1[j]);j--) {
			vec1[j+1]=vec1[j];                                //stable sort, relative order will not change
			insertPos=j;
			if(j==0) {
				//cout<<"j is unsigned,so no j-- when j==0, choose to break"<<endl;
				break;
			}
		}
		vec1[insertPos]=temp;
		/*if(i==times) {
			cout<<i<<endl;
			times=times+10000;
		}*/
	}
}

void wayne_sortThem::quickSort(vector<double> &vec1,const vector<double> &vec2, bool (*comp)(double& a, double& b)) {
	cout << "quickSort:" << endl;
	vec1=vec2;
	quickSortSub(0,vec1.size()-1,vec1, comp);                       //the implemention of quicksort
}
void wayne_sortThem::quickSortSub(int left,int right,vector<double> &vec1, bool (*comp)(double& a, double& b)) {
	int i=left;                                                //start from the very left to the right until meet j
	int j=right;                                               //start from the very right to the left until meet i
	double tempBi=vec1[left];                                  //store base value for comparison(random algorithm will sample a index between left and right)
	if(i>j) {                                                  //i cannot beyond j
		cout<<"i is now at the rightside of j"<<endl;
		system("pause");
		return;
	}
	while(i!=j && i<j) {
		//start from the right side
		while(!comp(vec1[j], tempBi) && i<j) j--;              //to find a value from right part that is bigger than base value, and then exchange that value to the front side
		while(!comp(tempBi, vec1[i]) && i<j) i++;

		if(i==j) {                           //time to move base value
			vec1[left]=vec1[j];             //move meeting value to the very left
			vec1[j]=tempBi;                 //move the original very left value to the meeting position
			break;                          //break when base value was exchanged
		}
		swap(vec1[i], vec1[j]);             // front and behind exchange
	}
	if(i!=j) {
		cout<<"i is not equal to j£¬how come!"<<endl;
		system("pause");
	}
	if(left<j-1) {
		quickSortSub(left,j-1,vec1, comp);            //quicksort left sub
	}
	if(j+1<right) {
		quickSortSub(j+1,right,vec1, comp);           //quicksort right sub
	}	
}

void wayne_sortThem::heapSortLazy(vector<double>& vec1, const vector<double>& vec2, bool (*comp)(double& a, double& b)) {
	cout << "heapSortLazy:" << endl;
	vec1 = vec2;
	for (unsigned int i = 0; i < vec1.size(); i++) {
		std::make_heap(vec1.begin(), vec1.end() - i, comp);
		std::pop_heap(vec1.begin(), vec1.end() - i, comp);
	}
}

void wayne_sortThem::heapSort(vector<double>& vec1, const vector<double>& vec2, bool (*comp)(double& a, double& b)) {
	cout << "heapSort:" << endl;
	vec1 = vec2;
	this->buildHeap(vec1, comp);
	int currentSize = (int)vec1.size();
	for (int i = 1; i < (int)vec1.size(); i++) {
		std::swap(vec1[0], vec1[currentSize - i]);
		this->adjustHeap(vec1, currentSize - i, 0, comp);
	}
}
void wayne_sortThem::buildHeap(vector<double>& vec, bool (*comp)(double& a, double& b)) {
	int heapSize = (int)vec.size();
	for (int i = heapSize / 2; i >= 0; i--) {
		this->adjustHeap(vec, heapSize, i, comp);
	}
}
void wayne_sortThem::adjustHeap(vector<double>& vec, int heapSize, int index, bool (*comp)(double& a, double& b)) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	if (left < heapSize && !comp(vec[left], vec[largest])) largest = left;
	if (right < heapSize && !comp(vec[right], vec[largest])) largest = right;
	if (largest != index) {
		std::swap(vec[largest], vec[index]);
		this->adjustHeap(vec, heapSize, largest, comp);
	}
}