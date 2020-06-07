#include<iostream>
#include<time.h>     //use clock_t
#include<cstdlib>    //use system("pause")
#include<vector>
#include<string>

#include "wayne_getThem.h"

#define MY_PI 3.1415926535898

using namespace std;

int main()
{
	clock_t start,end;
	start=clock();    //start time
	for(int i=0;i<3;i++) {
		cout<<"This is a program for sorting experiment!"<<endl;
	}
	cout<<endl;

	wayne_getThem* try1=new wayne_getThem();
	try1->run();

	delete try1;
	try1=NULL;

	end=clock();     //end time
	cout<<"running time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
	system("pause");
	return 0;
}