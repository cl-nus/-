#include <iostream>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

struct point {
	int first;
	int second;
	int third;
};

double distance(point& p1, point& p2) {
	return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second)+
		(p1.third-p2.third)*(p1.third-p2.third));
}

struct compare {
	bool operator() (double a1, double a2) const {
		return a2<a1;
	}
};

int main() {
	multimap<double,string,compare> a;
	int n;
	cin >> n;
	point points[n];

	for (int i=0; i<n; i++)
		cin >> points[i].first >> points[i].second >> points[i].third;

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			string d;
			ostringstream oss(d);
			oss<<'('<<points[i].first<<','<<points[i].second<<','<<points[i].third<<")-("<<points[j].first<<','<<points[j].second<<','<<points[j].third<<")=";
			a.insert(multimap<double,string,compare>::value_type(distance(points[i],points[j]),oss.str()));
		}
	multimap<double,string>::iterator it,ie;
	it=a.begin();
	ie=a.end();
	while(it!=ie)
	{
		cout<<it->second<<fixed<<setprecision(2)<<it->first<<endl;
		it++;
	}
}

