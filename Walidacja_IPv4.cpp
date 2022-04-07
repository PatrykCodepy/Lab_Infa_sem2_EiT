#include <iostream>
#include <string>
#include <cstdio>

std::string walidacja_IPv4(std::string IP) {
    //std::string IP("1.1.1.1");
    //std::cin >> IP;   
    int x = 0,
        k = 0;

    //while (IP.find('.') != std::string::npos) {
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
    else return "To nie jest adres ipv4";
}
/*
string stream SS;

SS << strl łądujemy do SS stringa
int x;
    SS >> x; rozładujemy go

python import dis - dis.dis(...) daje asseblera
*/
int main(){
    std::ios::sync_with_stdio(0);
    std::string IP;
    std::cin >> IP;
    std::cout << walidacja_IPv4(IP);
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