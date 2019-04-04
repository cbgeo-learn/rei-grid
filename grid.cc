#include <iostream>

const double x_start=0;
const double x_end=100;
const double y_start=0;
const double y_end=50;
const double dx=1;
const double dy=0.5;
const int NX=(x_end-x_start)/dx;
const int NY=(y_end-y_start)/dy;

int main() {


double xcoord[NX][NY];
double ycoord[NX][NY];
double mass[NX][NY];
double id[NX][NY];

for (int i=0;i<NX;i++) {
	for (int j=0;j<NY;j++) {
		xcoord[i][j]=x_start+dx*i;
		ycoord[i][j]=y_start+dy*j;
		id[i][j]=i*NX+j;
		if(j<50) {
			mass[i][j]=12;
		} else {
			mass[i][j]=24;
		}
   }
}
	std::cout<<"(x,y) = "<<xcoord[10][5]<<","<<ycoord[10][5]<<std::endl;
	std::cout<<"Mass = "<<mass[10][5]<<std::endl;
	std::cout<<"Element ID = "<<id[10][5]<<std::endl;
}


