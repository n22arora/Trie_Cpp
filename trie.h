#include <iostream>
#include <stdio.h>
#include <string.h>

#include <cstring>
#include <ctype.h>
#include <algorithm>


class trie; 
class trie_node;

class trie_node {
public:
    trie_node* word[26];
    bool end;
    trie_node();
    bool is_end();
};

class trie {

private:
    int size_of_trie; // tells about the size of trie basically it's the no of word in the trie
        int counter;  //to keep track of the size of the trie and update it according...helper variable just in case might delete later
   

public:

    trie_node* root;

    trie();  //done 

   
    void insert(trie_node* temp, string entry, int level);  // to insert a word in the trie //done

   
    bool erase(trie_node* temp, string key, int level, int& split);   // to erase a word from the trie 
    bool search(trie_node* temp, string key, int level);  // to search a word in the trie  // done

    void print(trie_node* temp, string str, int level);

    trie_node* search_prefix(trie_node* temp, string pre, int level);
    
    void autocomplete(string prefix);
    void print_tail(trie_node* curr, int level, string prefix, string str);
    bool is_empty(); //done

    void clear();

    int size();  //done

};

void trie::print_tail(trie_node* curr, int level, string prefix, string str) {

    if (curr->end == true) {
        std::cout << prefix + str << std::endl;
    }

    for (int i = 0; i < 26; i++) {

        if (curr->word[i] != NULL)
        {

            char ch = i + 'a';
            print_tail(curr->word[i], level + 1, prefix, str + ch);
        }
    }

}

trie_node* trie::search_prefix(trie_node* root, string pre, int level) {

    trie_node* temp = root;

    if (counter == 0) {

        return NULL;

    }

    if (level == pre.length()) {

        return temp;

    }

    //otherwise

    return search_prefix(temp->word[int(pre[level]) - 97], pre, level + 1);

}


void trie::autocomplete(string prefix) {

    trie_node* temp = this->root;
    int level = 0;
    string str;

    trie_node* curr = search_prefix(root, prefix, level);

    if (curr == NULL || counter == 0) {
        return;
    }
    else {

        print_tail(curr, level, prefix, str);
    }


}



void trie::clear() {
    trie_node* temp = this->root;


    for (int i = 0; i < 26; i++) {

        if (temp->word[i] != NULL) {
            trie_node* remove = temp;
            delete(remove->word[i]);
            remove->word[i] = nullptr;
        }
    }

    counter = 0;

    std::cout << "success" << std::endl;
}

bool trie::erase(trie_node* temp, string key, int level, int& split) {


    //int step = 0;

    //if tree is empty
    if (counter == 0) {
        return false;
    }

    int count = 0; //no of children

    for (int k = 0; k < 26; k++) {

        if (temp->word[int(key[level]) - 97] != NULL) {
            count++;
        }
    }


    if (level == key.length()) {

        if (temp->end == false) {
            return false;       //word doesn't exist
        }
        else {  //word exists

            if (count >= 1) {
                split = -1;
            }
            temp->end = false;
            return true;
        }
    }

    if (temp->end == true) {
        split = level;
    }

    if (count > 1) {
        split = level;
    }


    bool res = erase(temp->word[int(key[level]) - 97], key, level + 1, split);

    if (level == split) {
        //std::cout << "str";
        trie_node* remove = temp;
        delete(remove->word[int(key[level]) - 97]);
        remove->word[int(key[level]) - 97] = nullptr;
        counter--;
    }

    return res;
}


bool trie::search(trie_node* root, string key, int level)
{
    trie_node* temp = root;

    if (counter == 0) {

        return false;

    }

    if (temp->end && level == key.length()) {

        return true;

    }

    //otherwise

    return search(temp->word[int(key[level]) - 97], key, level + 1);
}



//print function
void trie::print(trie_node* temp, string str, int level) {

    if (temp->end == true)
    {

        std::cout << str << std::endl;
    }

    for (int i = 0; i < 26; i++)
    {

        if (temp->word[i] != NULL)
        {

            char ch = i + 'a';
            print(temp->word[i], str + ch, level + 1);
        }
    }

}


//is_empty function
bool trie::is_empty() {
    bool flag = false;

    if (this->root == nullptr) {
        flag = true;
    }

    return flag;
}


//size function
int trie::size() {

    return counter;

}


//constructor for trie 
trie::trie() {
    root = new trie_node{};
    size_of_trie = 0;
    counter = 0;
}



// is_end functions
bool trie_node::is_end() {

    bool flag = false;


    for (int i = 0; i < 26; i++) {

        if (!this->word[i]) {
            flag = true;
        }
    }

    return flag;

}

//insert function
void trie::insert(trie_node* temp, string entry, int level) {

    /*  trie_node* temp = this->root;*/

    if (search(temp, entry, level) == true) {
        std::cout << "failure" << std::endl;
        return;
    }

    if (level < entry.length()) {

        if (temp->word[(int(entry[level]) - 97)] == nullptr) {
            temp->word[(int(entry[level]) - 97)] = new trie_node;

        }

        insert(temp->word[(int(entry[level]) - 97)], entry, level + 1);
    }
    else {
        temp->end = true;
        counter++;

        std::cout << "success" << std::endl;
    }
}


//constructor for trie_node
trie_node::trie_node() {

    this->end = false;    // shows that we are at the leaf node

    int i = 0;

    for (i = 0; i < 26; i++) {
        this->word[i] = nullptr;
    }

}
