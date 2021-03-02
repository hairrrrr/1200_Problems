/* Solution for "Titanic" problem,
   Ural Programming Contest 1999 */

#include <fstream.h>
#include <io.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

const double D=6875.;
const double R=3437.5;
const double C_PI=3.14159265358979323846;

int main ()
{
	ifstream in("input.txt");

	char s[300];

	// skip decoration stuff
	in.getline(s,299);
	in.getline(s,299);
	in.getline(s,299);
	// read the ship coordinates
	in.getline(s,299);

	if (strchr(s,'^')==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	double phi1, phi2, teta1, teta2;
	double degrees, minutes, seconds, sign;

	degrees=atof(s);

	char *p=strchr(s,'^');
	minutes=atof(p+1);

	p=strchr(s,'\'');

	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	seconds=atof(p+1);

	sign=0.;
	if (strstr(s,"SL")!=NULL)
		sign=-1.;
	if (strstr(s,"NL")!=NULL)
		sign=1.;

	if (fabs(sign)<0.5)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	phi1=sign*(degrees+minutes/60.+seconds/3600.);

	in >> s;
	in.getline(s,299);

	degrees=atof(s);

	p=strchr(s,'^');
	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}
	minutes=atof(p+1);

	p=strchr(s,'\'');

	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	seconds=atof(p+1);

	sign=0.;
	if (strstr(s,"WL")!=NULL)
		sign=-1.;
	if (strstr(s,"EL")!=NULL)
		sign=1.;

	if (fabs(sign)<0.5)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	teta1=sign*(degrees+minutes/60.+seconds/3600.);

	// skip one more line
	in.getline(s,299);

	// read the iceberg coordinates
	in.getline(s,299);

	p=strchr(s,'^');

	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	degrees=atof(s);

	minutes=atof(p+1);

	p=strchr(s,'\'');

	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	seconds=atof(p+1);

	sign=0.;
	if (strstr(s,"SL")!=NULL)
		sign=-1.;
	if (strstr(s,"NL")!=NULL)
		sign=1.;

	if (fabs(sign)<0.5)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	phi2=sign*(degrees+minutes/60.+seconds/3600.);

	in >> s;
	in.getline(s,299);

	degrees=atof(s);

	p=strchr(s,'^');
	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}
	minutes=atof(p+1);

	p=strchr(s,'\'');

	if (p==NULL)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	seconds=atof(p+1);

	sign=0.;
	if (strstr(s,"WL")!=NULL)
		sign=-1.;
	if (strstr(s,"EL")!=NULL)
		sign=1.;

	if (fabs(sign)<0.5)
	{
		cerr << "Input data error!" << endl;
		return 1;
	}

	teta2=sign*(degrees+minutes/60.+seconds/3600.);

	in.close();	

	// now calculate the euclids coordinates

	double x1,x2,y1,y2,z1,z2;

	phi1=phi1*C_PI/180.;
	phi2=phi2*C_PI/180.;
	teta1=teta1*C_PI/180.;
	teta2=teta2*C_PI/180.;

	x1=R*cos(phi1)*cos(teta1);
	y1=R*cos(phi1)*sin(teta1);
	z1=R*sin(phi1);

	x2=R*cos(phi2)*cos(teta2);
	y2=R*cos(phi2)*sin(teta2);
	z2=R*sin(phi2);

	double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));

	double k=dist/D;

	if ( k>1.  ) 
	{
		cerr << "Upper bound works!" << endl;
		k=1.;
	}

	if ( k<-1. )
	{
		cerr << "Lower bound works!" << endl;
		k=-1.;
	}

	double way=D*asin(k);

	ofstream out("output.txt");

	sprintf(s,"The distance to the iceberg: %4.2lf miles",way);

	out << s << endl;

	sprintf(s,"%16.10lf",way);

	cerr << s << endl;

	if ( way < 99.995 )
		out << "DANGER!" << endl;

	out.close();

	return 0;
}
