#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<limits>
#include <math.h>

using namespace std;

float waga = 0;
float wzrost = 0;
float priming = 0;
float BSA = 0;
int SVC = 0;
int IVC = 0;
int KaniulaWspolna = 0;
int arg = 0;
float wymiarLinii = 0;
float przeplyw = 0;
float wymiarkaniulDLP = 0;
float indeksObjetosciowy = 0;
float hematokryt = 0;


int KaniuleZylne[15][4] =
{
	0, 12, 14, 18,
	3, 14, 15, 18,
	6, 16, 16, 20,
	8, 16, 18, 22,
	10, 18, 18, 24,
	12, 18, 20, 26,
	15, 20, 20, 26,
	20, 20, 24, 28,
	25, 24, 24, 28,
	30, 24, 28, 30,
	35, 26, 28, 34,
	40, 28, 28, 34,
	45, 30, 32, 36,
	55, 32, 34, 40,
	65, 34, 36, 40
};


float KaniuleTetnicze[15][4] =
{
	0, 0, 0.6, 8,
	3, 0, 0.9, 10,
	5, 0, 1.5, 12,
	11, 1, 2.5, 14,
	16, 1, 3.0, 16,
	23, 2, 4.0, 18,
	30, 2, 6.5, 20,
	46, 2, 0, 22,
	81, 2, 0, 24,
	120, 2, 0, 24
};


int main() 
{
// BLOK POBIERANIA DANYCH - START

	cout << "Podaj wzrost (w cm): ";
	    while(!(cin >> wzrost))
		{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Nie podano liczby! Sprobuj ponownie - podaj wzrost: ";
	    }
	cout << "Podaj wage (w kg): ";
		    while(!(cin >> waga))
		{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Nie podano liczby! Sprobuj ponownie - podaj wage: ";
	       }
	cout << "Podaj objetosc primingu (w ml): ";
		    while(!(cin >> priming))
		{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Nie podano liczby! Sprobuj ponownie - podaj objetosc primingu (w ml): ";
	       }
	       
 	cout << "Podaj parametr hematokrytu: ";
		    while(!(cin >> hematokryt))
		{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Nie podano liczby! Sprobuj ponownie - podaj parametr hematokrytu: ";
	       }	       
	cout << "Twoje parametry to: waga " <<waga <<"kg oraz wzrost " <<wzrost <<"cm. Objetosc primmingu wynosi " <<priming <<" ml, natomiast parametr hematokrytu jest rowny " <<hematokryt <<" procent."<<endl;
// BLOK POBIERANIA DANYCH - STOP
	
	cout << endl <<"Obliczanie pozostalych parametrow: " <<endl;
	
// 1. Wyliczanie powierzchni cia³a BSA wzglêdem zale¿noœci DuBoisa na podstawie masy i wzrostu
	
	BSA = 0.007184*pow(wzrost/100,0.725)*pow(waga,0.425);
	cout << "1. Powierzchnia ciala wedlug DuBoisa wynosi: " <<BSA <<"m2."<<endl;
	
// 2. Wyznaczanie rozmiaru kaniuli ¿ylnej wed³ug wagi:
	if (waga>=70) cout <<"2. Przekroczono wagê pacjenta nadajacego sie do kaniulacji!" <<endl;
	else
		{
		int j = 0;
		int k = 0;
		
		while (waga>k)
		{
		SVC = KaniuleZylne[j][1];
		IVC = KaniuleZylne[j][2];
		KaniulaWspolna = KaniuleZylne[j][3];
		j++;
		k = KaniuleZylne[j][0];
	    }
		cout << "2. Dobrane kaniule zylne wynosza kolejno: SVC: " <<SVC <<", IVC: " <<IVC <<" oraz kaniula wspolna: " << KaniulaWspolna <<"." <<endl;; 
	    }
	
// 3. Wyznaczanie rozmiaru kaniuli tetniczej wedlug wagi
	
	if (waga>120) cout <<"3. Przekroczono maksymalna wage pacjenta do kaniulacji tetniczej!" <<endl;
	else
		{
		int j = 0;
		int k = 0;
		
		while (waga>k)
		{
		wymiarLinii = KaniuleTetnicze[j][1];
		przeplyw = KaniuleTetnicze[j][2];
		wymiarkaniulDLP = KaniuleTetnicze[j][3];
		j++;
		k = KaniuleTetnicze[j][0];
	    }
	    
	    cout <<"3. Wymiar kaniul DLP wynosi " <<wymiarkaniulDLP;
	    
		if (wymiarLinii == 0) cout << " przy wymiarze linii kaniuli tetniczej 3/16 cala.";
		else if (wymiarLinii == 1) cout << " przy wymiarze linii kaniuli tetniczej 1/4 cala.";
		else if (wymiarLinii == 2) cout << " przy wymiarze linii kaniuli tetniczej 3/8 cala.";
		else cout <<". Nastapil blad wyznaczania rozmiaru linii kaniuli tetniczej!";
		
		if (!(przeplyw==0)) cout <<" Przeplyw w takiej kaniuli wynosi " <<przeplyw <<" litrow na minute." <<endl;
		else cout <<endl;	
	}
	
//4. Wyliczanie rzutu minutowego pompy wg BSA
	
	if ((przeplyw==0)) cout <<"4. Nie mozna wyznaczyc przeplywu minutowego pompy! Brak danych!" <<endl;
	else 
		{
		float rzutMinutowySerca = BSA * przeplyw;	
		cout << "4. Rzut minutowy serca wynosi: " <<rzutMinutowySerca <<"m2*l/min" <<endl;
	    }
	
//5. Wyliczanie objêtoœci krwii kr¹¿¹cej w zale¿noœci od masy

	if (waga>50) indeksObjetosciowy = 60;
	else if (waga>40) indeksObjetosciowy = 65;
	else if (waga>30) indeksObjetosciowy = 70;
	else if (waga>20) indeksObjetosciowy = 75;
	else if (waga>10) indeksObjetosciowy = 80;
	else if (waga<=10) indeksObjetosciowy = 85;
	else cout <<"B³ad wyznaczania objetosci krwii!" <<endl;


	float objetoscKrwii = waga*indeksObjetosciowy;
	cout << "5. Objetosc krwii w organizmie wynosi: " << objetoscKrwii <<" mililitrow." <<endl;

//6. Obliczanie wskaŸnika hemodilucji
	
	if (waga>50) indeksObjetosciowy = 60;
	else if (waga>40) indeksObjetosciowy = 65;
	else if (waga>30) indeksObjetosciowy = 70;
	else if (waga>20) indeksObjetosciowy = 75;
	else if (waga>10) indeksObjetosciowy = 80;
	else if (waga<=10) indeksObjetosciowy = 85;
	else cout <<"B³ad wyznaczania wskaznika demodilucji!" <<endl;

	float wskaznikHemodilucji=100*priming/(waga*indeksObjetosciowy+priming);
	cout << "6. Wskaznik hemodilucji wynosi: " <<wskaznikHemodilucji <<" procent." <<endl;
	
//7. Obliczanie HT na kr¹¿eniu pozaustrojowym
	
	float HT = ((hematokryt/100)*objetoscKrwii)/(objetoscKrwii+priming);
	cout << "7. HT na krazeniu pozaustrojowym wynosi: " <<HT;	
	
//8. Obliczanie poda¿y KKCz w celu uzyskania oczekiwanego Ht na kr¹¿eniu pozaustrojowym

	float KKCz = (((HT)*(objetoscKrwii+priming))-(objetoscKrwii*hematokryt/100))/0.7;
	cout << "8. Podaz KKCz celem uzyskania oczekiwanego HT na krazeniu pozaustrojowym wynosi: " << KKCz;

	
}

