
#include <iostream>

using namespace std;



#include <stdio.h>

using namespace std;



#include <string.h>

using namespace std;



#include "trie.h"  


#include <string>

int main() {



    trie p{};

    string cmd;



     do {

     
        cin >> cmd;


        if (cmd == "clear") {
            p.clear();
           }


        if (cmd == "autocomplete") {

            std::string w;
            //std::cout << "Enter a word ";
            cin.ignore();
            std::getline(cin, w);

            p.autocomplete(w);
        }


        if (cmd == "e") {

            int check = 0;
            int split = 0;
            int step = 0;
            std::string w;
            //std::cout << "Enter a word ";
            cin.ignore();
            std::getline(cin, w);


            try {
                for (int i = 0; i < w.length(); i++)
                {

                    if (w[i] < 'a' || w[i]>'z') {

                        check = 1;
                    }
                }
                if (check == 1) {
                    throw invalid_argument("illegal argument");
                }
            }
            catch (const invalid_argument e)
            {
                cout << "illegal argument" << std::endl;
            }

            if (check != 1) {
               bool result = p.erase(p.root, w, step, split);

               if (result == true) {
                   std::cout << "success" << std::endl;

               }
               else {
                   std::cout << "failure" << std::endl;
               }
            }




        }

        if (cmd == "i") {

            int check = 0;
            std::string w;
            cin.ignore();
            std::getline(cin, w);
            int step = 0;

            try {
                for (int i = 0; i < w.length(); i++)
                {

                    if (w[i] < 'a' || w[i]>'z') {

                        check = 1;
                    }
                }
                if (check == 1) {
                    throw invalid_argument("illegal argument");
                }
            }
            catch (const invalid_argument e)
            {
                cout << "illegal argument" <<std::endl;
            }

            if (check != 1) {
                p.insert(p.root, w, step);
            }

        }

        if (cmd == "s") {

            int check = 0;
            std::string w;
            cin.ignore();
            std::getline(cin, w);

            int step = 0;
            
            try {
                for (int i = 0; i < w.length(); i++)
                {

                    if (w[i] < 'a' || w[i]>'z') {
                        
                        check = 1;
                    }
                }
                if (check == 1) {
                    throw invalid_argument("illegal argument");
                }
            }
                catch (const invalid_argument e)
                {
                    cout << "illegal argument" <<std::endl;
                }
            
        

            if (check != 1) {
                //bool result = true;
                bool result = p.search(p.root, w, step);

                if (result == true) {
                    std::cout << "found " << w << std::endl;
                }
                else {
                    std::cout << "not found " << std::endl;
                }
            }
        }

        if (cmd == "print") {

            int step = 0;         //for each level in the trie
            string str;  // for making word by collecting each letter 
            
            p.print(p.root, str, step);

        }

        if (cmd == "empty") {

           if (p.is_empty()) {
               std::cout << "empty 1"<< std::endl;
           }
           else {
               std::cout << "empty 0" << std::endl;
            }
        }

        if (cmd == "size") {
           int size  = p.size();

           std::cout << "number of words is " << size << std::endl;
        }


        //if (cmd == "clear") {
        //    p.clear();
        //}


     } while (cmd.compare("exit") != 0);

    }


