#include <iostream>
#include <vector>
#include <cstdio>

struct Book
{
    int pages_count;
    std::string title;
    Book(){
        pages_count=0;
        title=" ";
    }
};

void save_to_file(const char *filename, std::vector<Book>::iterator it, int book_count){
    FILE *file_write = fopen(filename,"wb");
        if(!file_write){
            std::cout<<"Error opening file!"<<std::endl;

        }
    for(int i=0;i<book_count;i++){
        fwrite(&*it,sizeof(Book),1,file_write);
        ++it;
    }
    fclose(file_write);
}

void search_in_file(const char *filename,const std::string& book_name){
    FILE *file_read = fopen(filename,"rb");
    if(!file_read){
        std::cout<<"Error opening file!"<<std::endl;
    }
    Book buf;

    while(!feof(file_read)){
    fread(&buf,sizeof(Book),1,file_read);
    if(buf.title == book_name){
        std::cout<<"Successfully found a book with name:"<<buf.title<<" and it has "<<buf.pages_count<<"pages. "<<std::endl;
    }
}
    fclose(file_read);
}

int main(int argc, char* argv[])
{
    if(argc==2)
    {
    std::vector<Book> books;
    Book b;
    int number_of_books;
    std::cout<<"Enter number of books: "<<std::endl;
    std::cin>>number_of_books;

    for(int i=0;i<number_of_books;i++){
        std::cout<<"Enter number of pages: "<<std::endl;
        std::cin>>b.pages_count;
        std::cout<<"Enter title: "<<std::endl;
        std::cin>>b.title;
        books.push_back(b);
    }
    save_to_file(argv[1],books.begin(),books.size());
    }
    if(argc==3){
        search_in_file(argv[1],argv[2]);
    }
    if(argc>3){
        std::cout<<"There must be 1 or 2 arguments: <File name> to fill existing file with books of <File name> <Book title> to search a book in a file by its title"<<std::endl;
    }
   return 0;

}
