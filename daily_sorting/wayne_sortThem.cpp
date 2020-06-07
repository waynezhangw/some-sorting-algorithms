#include "wayne_sortThem.h"
#include <utility>      // std::swap
#include<iostream>

using namespace std;
wayne_sortThem::wayne_sortThem(void) {
}

wayne_sortThem::~wayne_sortThem(void) {
}

void wayne_sortThem::selectionSort(vector<double> &vec1,const vector<double> &vec2) {
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
			cout<<"improved bubble sort�� "<<i<<endl;          // only good for nearly sorted data
			break;
		}
	}
}

void wayne_sortThem::insertionSort(vector<double> &vec1,const vector<double> &vec2) {
	vec1=vec2;
	double temp;
	int times=10000;
	int insertPos;
	for(unsigned int i=1;i<vec2.size();i++) {
		temp=vec1[i];                                         //waiting for insertion
		insertPos=i;                                          //if no exchange below, it might already the biggest when inserting
		for(unsigned int j=i-1;j>=0 && temp<vec1[j];j--) {
			vec1[j+1]=vec1[j];                                //stable sort, relative order will not change
			insertPos=j;
			if(j==0) {
				//cout<<"j is unsigned,so no j-- when j==0, choose to break"<<endl;
				break;
			}
		}
		vec1[insertPos]=temp;
		if(i==times) {
			cout<<i<<endl;
			times=times+10000;
		}
	}
}

void wayne_sortThem::quickSort(vector<double> &vec1,const vector<double> &vec2) {
	vec1=vec2;
	quickSortSub(0,vec1.size()-1,vec1);                       //the implemention of quicksort
}
void wayne_sortThem::quickSortSub(int left,int right,vector<double> &vec1) {
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
		while(vec1[j]>=tempBi && i<j) j--;              //to find a value from right part that is bigger than base value, and then exchange that value to the front side
		while(vec1[i]<=tempBi && i<j) i++;

		if(i==j) {                           //time to move base value
			vec1[left]=vec1[j];             //move meeting value to the very left
			vec1[j]=tempBi;                 //move the original very left value to the meeting position
			break;                          //break when base value was exchanged
		}
		swap(vec1[i], vec1[j]);             // front and behind exchange
	}
	if(i!=j) {
		cout<<"i is not equal to j��how come!"<<endl;
		system("pause");
	}
	if(left<j-1) {
		quickSortSub(left,j-1,vec1);            //quicksort left sub
	}
	if(j+1<right) {
		quickSortSub(j+1,right,vec1);           //quicksort right sub
	}	
}
