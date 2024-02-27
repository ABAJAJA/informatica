#include <iostream> 
#include <fstream>

using namespace std;
class frazione{
	private:
		int numeratore;
		int denominatore;
	public:
		frazione()
		{
		
		}
		
		frazione(int num, int denom)
		{
			if(denom==0)
				denom=1;
			numeratore=num;
			denominatore=denom;
		}
		
		int trovamcm(int a, int b)
		{
			while(b!=0)
			{
				int temp=b;
				b=a%b;
				a=temp;
			}
			return a;
			
		}
		void setNum(int n)
		{
			numeratore=n;
		}
		
		void setDenom(int n)
		{
			if(n!=0)
				denominatore=n;
			
		}
		
		int calcolaFraz()
		{
			double ris;
			ris=numeratore/denominatore;
			return ris;
		}
		
		frazione operator+(const frazione &dep)
		{
			return frazione(numeratore * dep.denominatore + dep.numeratore * denominatore, denominatore * dep.denominatore);
		}
		
		frazione operator-(const frazione &dep)
		{
			return frazione(numeratore * dep.denominatore - dep.numeratore * denominatore,denominatore*dep.denominatore);
		}
		
		frazione operator*(const frazione &dep)
		{
			return frazione(numeratore* dep.numeratore, denominatore * dep.denominatore);
		}
		
		frazione operator/(const frazione &dep)
		{
			if(dep.numeratore!=0)
			{
				return frazione(numeratore * dep.denominatore, denominatore * dep.numeratore);
			}
			else
			{
				cout << "divisione per 0, errore";
				return frazione(1,1);
			}
		}
		
		friend ostream&operator<<(ostream &os, const frazione fraz)
		{
			os << '\n' <<fraz.numeratore <<'\n'<<'-'<<'-'<<'\n'<< fraz.denominatore;
			return os;
		}
		
		friend istream&operator>>(istream &is, frazione fraz)
		{
			cout << "inserisci il numeratore: ";
			fraz.setNum(fraz.numeratore);
			is >> fraz.numeratore;
			
			cout << "inserisci il denominatore: ";
			fraz.setDenom(fraz.denominatore);
			is >> fraz.denominatore;
			if(fraz.denominatore==0)
			{
				cout << "denominatore non valido, valore impostato a 1" << endl;
				fraz.denominatore=1;
			}
			return is;
			
		}
		
};
int main()
{
	frazione a,b;
	frazione c(2,3);
	frazione d(5,4);
	/*
	int scelta;
	cin>>scelta;
	switch(scelta) {
	  	case 1:
	   	cout<< "inserisci la prima frazione: " << endl;
	   	cin >> a;
	   	cout<< "inserisci la seconda frazione: " << endl;
	   	cin >> b;
	    break;
		case 2:
	  	frazione somma2= c + d; 
	  	cout << "somma:" << somma2 << endl;
		break;
		case 3:
		frazione sottraz= c - d;
		cout << "sottrazione:\n" << sottraz << endl;
	    break;
	    case 4:  	
	    default:
	    	break;   	
	}*/ 
	frazione somma= c + d; 
	cout << "somma:\n" << somma << endl;
	frazione sottraz= c - d;
	cout << "sottrazione:\n" << sottraz << endl;
	frazione moltiplicaz=c*d;
	cout << "moltiplicazione:\n" << moltiplicaz << endl;
	frazione divis = c / d;
	cout << "divisione\n" << divis << endl;
	
	
	return 0;
}
