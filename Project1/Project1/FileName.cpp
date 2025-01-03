#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 제목으로 검색
    void searchByTitle(const string& title) const {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "검색 결과: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "제목 \"" << title << "\"에 해당하는 책이 없습니다." << endl;
    }

    // 작가 이름으로 검색
    void searchByAuthor(const string& author) const {
        bool found = false;
        cout << "작가 \"" << author << "\"의 책 목록:" << endl;
        for (const auto& book : books) {
            if (book.author == author) {
                cout << "- " << book.title << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "작가 \"" << author << "\"에 해당하는 책이 없습니다." << endl;
        }
    }
};

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;          // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl;      // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 제목으로 검색" << endl;   // 책 제목을 기반으로 검색
        cout << "4. 작가 이름으로 검색" << endl; // 작가 이름을 기반으로 검색
        cout << "5. 종료" << endl;              // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 책 제목으로 검색
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 4번 선택: 작가 이름으로 검색
            string author;
            cout << "검색할 작가 이름: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, author); // 작가 이름 입력
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 5번 선택: 종료
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
