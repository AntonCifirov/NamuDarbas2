#include "my_lib.h"
#include "Funkcijos.h"
#include "Generavimas.h"


int main() {

    vector<Duom> asmuo_vector;
    vector<Duom> varg_vector;
    vector<Duom> kiet_vector;


    list<Duom> asmuo_list;
    list<Duom> varg_list;
    list<Duom> kiet_list;

    int nd_sk;
    string failo_pavadinimas;
    string pavadinimas;
    string txt;
    double diff_nusk{};
    double diff_nusk_proc{};
    double diff_rusiavimas_vector{};
    double diff_rusiavimas_vector_proc{};
    double diff_rusiavimas_list{};
    double diff_rusiavimas_list_proc{};

    double count{};

    //Duom asmuo("Antony", "Pavarde", { 1,2,3 }, 4);
    //asmuo.print();

    
       for (int i = 2; i < 4; i++)
       {

           failo_pavadinimas = generuoja_faila(pow(10, (i + 3)), 4);
       }

  

       for (int i = 2; i < 4; i++)
       {
           failo_pavadinimas = "studentai" + to_string(int(pow(10, (i + 3))));
           cout << failo_pavadinimas << endl;



           //Realizacija su list<duom>
           //-------------------------------------------------------------------
           auto start1 = chrono::high_resolution_clock::now();

           Failo_nuskaitymas(failo_pavadinimas, asmuo_list);

           auto end1 = chrono::high_resolution_clock::now();
           chrono::duration<double> diff1 = end1 - start1;
           cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas naudojant list<Duom> klase truko " << diff1.count() << "sek\n";


           varg_list.clear();

           auto start3 = std::chrono::high_resolution_clock::now();

           Failo_rusiavimas_list_2str(asmuo_list, varg_list);

           auto end3 = std::chrono::high_resolution_clock::now();
           std::chrono::duration<double> diff3 = end3 - start3;
           cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 2 strategija list<Duom> klase truko:  " << diff3.count() << "sek\n";

           //-------------------------------------------------------------------

           auto start4 = chrono::high_resolution_clock::now();

           //Isvedimas_i_failus_list(failo_pavadinimas, varg_list, asmuo_list);
           Isvedimas_i_failus_list(failo_pavadinimas, varg_list, kiet_list);

           auto end4 = chrono::high_resolution_clock::now();
           chrono::duration<double> diff4 = end4 - start4;
           cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt naudojant list<Duom> klase truko : " << diff4.count() << "sek\n\n";

           //Realizacija su list<duom>
       //-------------------------------------------------------------------
           auto start5 = chrono::high_resolution_clock::now();

           Failo_nuskaitymas(failo_pavadinimas, asmuo_list);

           auto end5 = chrono::high_resolution_clock::now();
           chrono::duration<double> diff5 = end5 - start5;
           cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas naudojant list<duom> struktura truko " << diff5.count() << "sek\n";

       //-------------------------------------------------------------------

           auto start6 = std::chrono::high_resolution_clock::now();

           Failo_rusiavimas_list_2str(asmuo_list, varg_list);

           auto end6 = std::chrono::high_resolution_clock::now();
           std::chrono::duration<double> diff6 = end6 - start6;
           cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 2 strategija list<duom> struktura  truko:  " << diff6.count() << "sek\n";

           //-------------------------------------------------------------------

           auto start7 = chrono::high_resolution_clock::now();

           //Isvedimas_i_failus_list(failo_pavadinimas, varg_list, asmuo_list);
           Isvedimas_i_failus_list(failo_pavadinimas, varg_list, kiet_list);

           auto end7 = chrono::high_resolution_clock::now();
           chrono::duration<double> diff7 = end7 - start7;
           cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt naudojant list<duom> struktura  truko : " << diff7.count() << "sek\n\n";


       }





    
    return 0;
}

