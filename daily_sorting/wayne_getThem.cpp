#include "wayne_getThem.h"
#include "wayne_sortThem.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

wayne_getThem::wayne_getThem(void) {
	obj_sort1=new wayne_sortThem();
}


wayne_getThem::~wayne_getThem(void) {
	delete obj_sort1;
	obj_sort1=NULL;
}

void wayne_getThem::readODTrip() {
	ifstream fin("..\\data\\20170405-Trip-statistics-2CN100w.csv");
	string line;
	double tempX;
	int number=0;
	int times=100000;

	while(getline(fin,line)) {
		if(line=="end,") {
			break;
		}
		istringstream sin(line);   
		string field;
		int i=1;
		while (getline(sin,field,',')) {
			if(i==1) {
				tempX=convertStringToDouble(field);       
				i++;
				continue;
			}
			else {
				i++;
				continue;
			}	
		}
		number++;
		OGrid_X.push_back(tempX);
		if(number==times) {
			cout<<number<<endl;
			times=times+100000;
		}

	}
	if(number!=OGrid_X.size()) {
		cout<<"size warning"<<endl;
	}
	cout<<fixed<<setprecision(9)<<"waited  X coordinates reading over"<<endl<<"size:"<<OGrid_X.size()<<"  last element:  "<<OGrid_X[OGrid_X.size()-1]<<endl;
	
}

void wayne_getThem::readODTripSorted() {
	ifstream fin("..\\data\\20170405-Trip-statistics-2CN100w_sorted.csv");
	string line;
	double tempX;
	int number=0;
	int times=100000;

	while(getline(fin,line)) 
	{
		if(line=="end,") {
			break;
		}
		istringstream sin(line);   
		string field;
		int i=1;
		while (getline(sin,field,',')) {
			if(i==1) {   //only read row 4 X coordinates
				tempX=convertStringToDouble(field);       
				i++;
				continue;
			}
			else {
				i++;
				continue;
			}	
		}
		number++;
		sorted_OGrid_X.push_back(tempX);
		if(number==times) {
			cout<<number<<endl;
			times=times+100000;
		}
	}
	if(number!=sorted_OGrid_X.size()) {
		cout<<"size warning"<<endl;
	}
	cout<<fixed<<setprecision(9)<<"sorted X coordinates reading over"<<endl<<"size£º"<<sorted_OGrid_X.size()<<"  last element£º  "<<sorted_OGrid_X[sorted_OGrid_X.size()-1]<<endl;
}

double wayne_getThem::convertStringToDouble(string str1) {
	//string to double
	double n1;
	const char* ch= str1.c_str();
	n1=atof(ch);                   //if none number string, will convert to zero
	return n1;
}

void wayne_getThem::makeFileOfVector(vector<double> &vec1) {
	ofstream outfile1;
	outfile1.open("..\\result\\sortedVector.csv");
	for(unsigned int i=0;i<vec1.size();i++) {
		outfile1<<fixed<<setprecision(9)<<i<<","<<vec1[i]<<endl;
		if(vec1[i]!=sorted_OGrid_X[i]) {
			cout<<"something a little different: "<<i<<"   "<<vec1[i]<<"   "<<sorted_OGrid_X[i]<<endl;
		}
	}
	outfile1.close();
}

void wayne_getThem::run() {
	readODTrip();                                 //read waited X coordinates
	readODTripSorted();                           //read sorted X coordinates for testing
	vector<double> ME;                            //store the result
	//obj_sort1->selectionSort(ME,OGrid_X);         //runtime 35N s
	//obj_sort1->bubbleSort(ME,OGrid_X);            //runtime 193N s
	//obj_sort1->insertionSort(ME,OGrid_X);         //runtime 37N s
	obj_sort1->quickSort(ME,OGrid_X);             //runtime only N s
	makeFileOfVector(ME);                         //output to file and testing
}
