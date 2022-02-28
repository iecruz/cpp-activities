#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int x, y, z, ten = 1;
	string word;
	bool teen = false, place = false;
	cout << "Enter a number: "; cin >> x;
	while (ten <= x){
		ten = ten * 10;
	}
	ten = ten / 10;
	while (ten > 0){
		y = x / ten;
		if (ten == 10 || ten == 10000)
		{
			switch (y){
			case 1: 
				x = x - (y * ten);
				ten = ten / 10;
				z = x / ten;
				teen = true;
				switch (z){
				case 0:	word += "TEN "; break;
				case 1:	word += "ELEVEN "; break;
				case 2:	word += "TWELVE "; break;
				case 3:	word += "THIRTEEN "; break;
				case 4:	word += "FOURTEEN "; break;
				case 5:	word += "FIFTEEN "; break;
				case 6:	word += "SIXTEEN "; break;
				case 7:	word += "SEVENTEEN "; break;
				case 8:	word += "EIGHTEEN "; break;
				case 9:	word += "NINETEEN "; break;
				}
				break;
			case 2: word += "TWENTY "; break;
			case 3: word += "THIRTY "; break;
			case 4: word += "FOURTY "; break;
			case 5: word += "FIFTHY "; break;
			case 6: word += "SIXTY "; break;
			case 7: word += "SEVENTY "; break;
			case 8: word += "EIGHTY "; break;
			case 9: word += "NINETY "; break;
			}
			if (y != 0)
				place = true;
		}
		else{
			switch (y){
			case 1: word += "ONE "; break;
			case 2: word += "TWO "; break;
			case 3: word += "THREE "; break;
			case 4: word += "FOUR "; break;
			case 5: word += "FIVE "; break;
			case 6: word += "SIX "; break;
			case 7: word += "SEVEN "; break;
			case 8: word += "EIGHT "; break;
			case 9: word += "NINE "; break;
			}
			
				place = true;
		}
		if (place){
			switch (ten){
			case 100000: word += "HUNDRED "; break;
			case 1000: word += "THOUSAND "; break;
			case 100: word += "HUNDRED "; break;
			}
			place = false;
		}
		if (!(teen)){
			x = x - (y*ten);
			ten = ten / 10;
			teen = false;
		}
	}
	cout << "Word Equivalent: " << word;
	system("pause>0");
	return 0;
}