#include <iostream>
#include <string>
#include <fstream> 

void szyfrowanie_Cezara(int k) {

    std::string  x,
        x_new;

    std::cout << "Podaj haslo: ";
    std::cin >> x;

    for (int i = 0; i < x.size(); i++) {
        char c = char(int(x[i]) + k);
        x_new.append(1, c);
        //std::cout << c ;
    }
    std::cout << "Haslo " << x << " to jest: " << x_new;
    std::ofstream myfile;
    myfile.open("example.txt");
    myfile << x_new;
    myfile.close();
}

int R(int x) {
    if (x > 1) {
        return R(x-1)+x; // R(4) -> R(3) + 4 -> R(2) + 3 -> R(1) + 2 -> 1 
    }
    else {
        return x;
    }
}

int silnia(int x) {
    if (x > 1) {
        return silnia(x - 1) * x; 
    }
    else {
        return x;
    }
}

int fibonacci(int x) {
    if (x > 2) {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
    else{
        return 1;
    }if(x == 0) {
        return 0;
    }
}

int NWD(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

std::string walidacja_IPv4() {
    std::string IP("1.1.1.1");
    //std::cin >> IP;
    int x = 0, 
        k = 0;

    while (x != -1) {
        x = IP.find('.'); // jesli nie ma kropek to rowne -1
        std::cout << IP.substr(0, IP.find('.')) << '\n';
        int ip;
        try {
            ip = std::stoi(IP.substr(0, x)); // jeśli będzie litera to dać wyjątek 
        }
        catch (...) { //łąpie wszystkie wyjątki dla stoi = std::invalid_argument, std::out_of_range 
            return "to nie jest adres ipv4";
        }
        if (ip < 256) {
            k++;
        }
        IP.erase(0, x + 1);

    }
    if (k == 4) return "To jest ipv4";
    else return "to nie jest adres ipv4";
}
/*
string stream SS; 

SS << strl łądujemy do SS stringa 
int x;
    SS >> x; rozładujemy go

python import dis - dis.dis(...) daje asseblera
*/
int main()
{
    for (int i = 65; i <= 122; i++) {
        char c = (char)i;
        std::cout << "ASCII SYMBOL " << c << ",ASCII VALUE " << i << "\n";
    }

    /*int k;
    std::cin >> k;
    szyfrowanie_Cezara(k);
    std::cout << R(5);*/
    std::cout << silnia(5) << '\n';
    std::cout << fibonacci(6) << '\n';
    std::cout << NWD(1122, 867) << '\n';
    std::cout << walidacja_IPv4();
    return 0;
}
//65-90 | 97-122
// Chat 8bit = 0-255
// unsigned int 32bit ma 0 - (2^32 - 1), jeśli przekroczymy to do np 2^32 wyskoczy 0
// 1 << 1 = 2 | << przesunięcie bitowe
/*
1. silnia n!
2. fibonacci n-ty wyraz
3. NWD - algorytm euklidesa
4. walidacja IPv4
find('.'), wycinamy substr()*/
//blazes.nowak@put.poznan.pl
/*
1.1.B.1
A.1.1.B
1.1.1
1.01.1.1
01.1.1.1
1.-1.1
1.1.1.1
1.1.-1.1
*/