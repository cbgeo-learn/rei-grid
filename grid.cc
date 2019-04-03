#include <iostream>

const double x_start=0;
const double x_end=100;
const double y_start=0;
const double y_end=50;
const double dx=1;
const double dy=0.5;
const int NX=(x_end-x_start)/dx+1;
const int NY=(y_end-y_start)/dy+1;

int main() {


double xcoord[NX][NY];
double ycoord[NX][NY];
Particle lbm[NX][NY];


lbm[i][j].id

for (int i=0;i<NX;i++) {
	for (int j=0;j<NY;j++) {
		xcoord[i][j]=x_start+dx*i;
		ycoord[i][j]=y_start+dy*j;
   }
}
	std::cout<<xcoord[1000][5]<<","<<ycoord[10][5]<<std::endl;
}


