#include <iostream>
#include <cmath>
#include <string>

class Complex
{
public:
	float Re,
		  Im;

	Complex(float x = 0, float y = 0) {
		Re = x;
		Im = y;
	}
	void wyswietl() { std::cout << "Re: " << Re << " Im: " << Im << "i" << '\n'; }
	void modul() { std::cout << sqrt(pow(Re, 2) + pow(Im, 2)) << '\n'; }
	Complex operator +(Complex const& x) {
		Complex y;
		y.Re = Re + x.Re;
		y.Im = Im + x.Im;
		return y;
	}

	Complex operator -(Complex const& x) {
		Complex y;
		y.Re = Re - x.Re;
		y.Im = Im - x.Im;
		return y;
	}

	Complex operator *(Complex const& x) {
		Complex y;
		y.Re = Re*x.Re - Im*x.Im;
		y.Im = Im*x.Re- Re*x.Im;
		return y;
	}

	Complex operator /(Complex const& x) {
		Complex y;
		y.Re = (Re * x.Re + Im * x.Im) / (pow(x.Re, 2) + pow(x.Im, 2));
		y.Im = (Im * x.Re + Re * x.Im) / (pow(x.Re, 2) + pow(x.Im, 2));
		return y;
	}

	bool operator ==(Complex const& x) {
		if (Re == x.Re && Im == x.Im) return true;
		else return false;
	}

	friend std::ostream& operator <<(std::ostream &os, Complex const& x) {
		os << x.Re << '+' << x.Im << 'i';
		return os;
	}

	// dzielenie jeszcze i ==, przeladowanie zrzutowania na string
	// (z jakas wartosc)  cout << z;  wypisze Re + Im i (wartosc)
};

void prime_num() {
	int n;

	std::cin >> n;

	int* tab = new int[n];

	for (int i = 0; i < n; i++) {
		tab[i] = i + 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = tab[i]; j < n; j++) {
			if (tab[j] != 0 && tab[i] != 0) {
				if (tab[j] % tab[i] == 0) tab[j] = 0;
			}
		}
	}

	for (int j = 1; j < n; j++) {
		if(tab[j] != 0) std::cout << tab[j] << ',';
	}

	delete[] tab;
}

int main(void) {
	Complex a(6.5, 6.7),
			b(5.6, 10.5);

	a.wyswietl();
	a.modul();
	Complex c = a + b,
			c1 = a * b,
			c2 = a/b;
	c.wyswietl();
	c1.wyswietl();
	c2.wyswietl();

	if (a == b) std::cout << "Jest rowne\n";
	else std::cout << "Nie jest rowne \n";

	Complex z(2,2);

	std::cout << z;
	std::cout << "\n---------------------------- \n";
	prime_num();

	return 0;
}
//for (int i = 0; i < n; i++) {
//	std::cout << &(tab[i]) << '\n'; //addressy pamieci
//}
//std::cout << &(tab[0]) << '\n'; //adress pierszej pamieci
//tab++; //inkrementujemy
//std::cout << &(tab[0]) << '\n'; //address po inkrementacji czyli drugi
//std::cout << *tab << '\n'; // wypisuje wartosc w tablicy pod adresem 2
//std::cout << &(*tab) << '\n';// &x - referencja *x - dereferencja
// 
	//if (3 ^ 4 == 4 ^ 3) std::cout << "Rowne \n"; // ^ to XOR ktory jest przemieny
	/*
	100 //4
	011 //3
xor-----
	111
	*/