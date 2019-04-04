#include <iostream>
#include <array>

const double x_start=0;
const double x_end=100;
const double y_start=0;
const double y_end=50;
const double dx=1;
const double dy=0.5;
const int NX=(x_end-x_start)/dx+1;
const int NY=(y_end-y_start)/dy+1;

struct Elements {
	std::array<double, 2> coords;
	double mass;
	unsigned int id;
};

Elements element[NX][NY];


int main() {

	int k=0;

	for (int i=0;i<NX;++i) {
		for (int j=0;j<NY;++j) {
			element[i][j].coords.at(0) =x_start+dx*i;
			element[i][j].coords.at(1)=y_start+dy*j;
			element[i][j].mass=12;
			element[i][j].id=k;
			++k;
		}
	}
		
	int a=2;
	int b=1;
	std::cout<<"(x,y) = "<<element[a][b].coords.at(0)<<","<<element[a][b].coords.at(1)<<std::endl;
	std::cout<<"Mass = "<<element[a][b].mass<<std::endl;
	std::cout<<"Element ID = "<<element[a][b].id<<std::endl;
}
	
