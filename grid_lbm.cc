#include <iostream>

const double x_start=0;
const double x_end=100;
const double y_start=0;
const double y_end=50;
const double dx=1;
const double dy=0.5;
const int NX=(x_end-x_start)/dx;
const int NY=(y_end-y_start)/dy;

double function(double w, double rho);

int main() {


	double xcoord[NX][NY];
	double ycoord[NX][NY];
	double f0[NX][NY];
	double f1[NX][NY];
	double f2[NX][NY];
	double f3[NX][NY];
	double f4[NX][NY];
	double f5[NX][NY];
	double f6[NX][NY];
	double f7[NX][NY];
	double f8[NX][NY];
	double rho=100.;


	for (int i=0;i<NX;++i) {
		for (int j=0;j<NY;++j) {
			xcoord[i][j]=x_start+dx*i;
			ycoord[i][j]=y_start+dy*j;
			f0[i][j]=function(4./9.,rho);
			f1[i][j]=function(1./9.,rho);
			f2[i][j]=function(1./9.,rho);
			f3[i][j]=function(1./9.,rho);
			f4[i][j]=function(1./9.,rho);
			f5[i][j]=function(1./36.,rho);
			f6[i][j]=function(1./36.,rho);
			f7[i][j]=function(1./36.,rho);
			f8[i][j]=function(1./36.,rho);

   }
}
	int a=10;
	int b=5;
	std::cout<<"(x,y) = "<<xcoord[a][b]<<","<<ycoord[a][b]<<std::endl;
	std::cout<<"[f0,f1,f2,f3,f4,f5,f6,f7,f8] = ["<<f0[a][b]<<","<<f1[a][b]<<","<<f2[a][b]<<","<<f3[a][b]<<","<<f4[a][b]<<","<<f5[a][b]<<","<<f6[a][b]<<","<<f7[a][b]<<","<<f8[a][b]<<"]"<<std::endl;
}

double function(double w, double rho) {
	double f=w*rho;
	return f;
}


