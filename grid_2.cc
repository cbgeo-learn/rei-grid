#include <iostream>

int main() {

	double x_start;
	double x_end;
	double y_start;
	double y_end;
	double dx;
	double dy;

	std::cout<<"Enter x_start: ";
	std::cin>>x_start;
	std::cout<<"Enter x_end: ";
	std::cin>>x_end;
	std::cout<<"Enter y_start: ";
	std::cin>>y_start;
	std::cout<<"Enter y_end: ";
	std::cin>>y_end;
	std::cout<<"Enter dx: ";
	std::cin>>dx;
	std::cout<<"Enter dy: ";
	std::cin>>dy;
	
	const int NX=(x_end-x_start)/dx; 	
	const int NY=(y_end-y_start)/dy;
	
	double xcoord[NX][NY];
	double ycoord[NX][NY];
	double mass[NX][NY];
	double id[NX][NY];
	
	for (int i=0;i<NX;i++) {
		for (int j=0;j<NY;j++) {
			xcoord[i][j]=x_start+dx*i;
			ycoord[i][j]=y_start+dy*j;
			id[i][j]=i*(NX)+j;
			if(j<50) { 
				mass[i][j]=12;
			} else {
				mass[i][j]=24;
			}
	       	}
	}
	
	int i,j;
	std::cout<<"Enter i index of the element: ";
	std::cin>>i;
	std::cout<<"Enter j index of the element: ";
	std::cin>>j;
	std::cout<<""<<std::endl;
	std::cout<<"Element Info: "<<std::endl;
	std::cout<<"(x,y) = "<<xcoord[i][j]<<","<<ycoord[i][j]<<std::endl;
	std::cout<<"Mass = "<<mass[i][j]<<std::endl;
	std::cout<<"Element ID = "<<id[i][j]<<std::endl;
}


