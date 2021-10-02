#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
struct Book
{
    int pages_count;
    char* title;

    Book(){
        pages_count = 0;
        title = nullptr;
    };
    ~Book(){delete(title);};
};

void search(char* file_name, char* book_title){

}
void save(char* file_name){


}

void fill_array(vector<Book> books){
    int count;
    Book b;
    cin >> count;
    for (int i=0; i<count;i++){
        cout<<"title "<< endl;
        cin >> b.title;
        cin >> b.pages_count;
        books.emplace_back(b);
    }

}
int main(int argc, char* argv[])
{
    cout<<argc<<endl;
    vector<Book> books;

    fill_array(books);

    if (argc ==2){

        save(argv[2]);
    }
    if (argc == 3){
        search(argv[2],argv[3]);
    }
   system("pause");
   return 0;

}
