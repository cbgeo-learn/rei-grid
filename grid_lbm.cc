#include <iostream>

const int NX=100;
const int NY=20;
double rho=100.;
const int Q=9;
double f[NX][NY][Q];

void initialize_density(double* rho, int NX, int NY);

int main() {


	initialize_density(&rho, NX, NY);


	int a=10;
	int b=5;
	std::cout<<"[f0,f1,f2,f3,f4,f5,f6,f7,f8] = ["<<f[a][b][0]<<","<<f[a][b][1]<<","<<f[a][b][2]<<","<<f[a][b][3]<<","<<f[a][b][4]<<","<<f[a][b][5]<<","<<f[a][b][6]<<","<<f[a][b][7]<<","<<f[a][b][8]<<"]"<<std::endl;
}

void initialize_density(double* rho, int NX, int NY) {

	for (int i=0;i<NX;++i) {
		for (int j=0;j<NY;++j) {
			f[i][j][0]=4./9.*(*rho);
			f[i][j][1]=f[i][j][2]=f[i][j][3]=f[i][j][4]=1./9.*(*rho);
			f[i][j][5]=f[i][j][6]=f[i][j][7]=f[i][j][8]=1./36.*(*rho);
		}
	}
}

