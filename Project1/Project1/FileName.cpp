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
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // å �������� �˻�
    void searchByTitle(const string& title) const {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "�˻� ���: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "���� \"" << title << "\"�� �ش��ϴ� å�� �����ϴ�." << endl;
    }

    // �۰� �̸����� �˻�
    void searchByAuthor(const string& author) const {
        bool found = false;
        cout << "�۰� \"" << author << "\"�� å ���:" << endl;
        for (const auto& book : books) {
            if (book.author == author) {
                cout << "- " << book.title << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "�۰� \"" << author << "\"�� �ش��ϴ� å�� �����ϴ�." << endl;
        }
    }
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;          // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl;      // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �������� �˻�" << endl;   // å ������ ������� �˻�
        cout << "4. �۰� �̸����� �˻�" << endl; // �۰� �̸��� ������� �˻�
        cout << "5. ����" << endl;              // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: å �������� �˻�
            string title;
            cout << "�˻��� å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է�
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 4�� ����: �۰� �̸����� �˻�
            string author;
            cout << "�˻��� �۰� �̸�: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, author); // �۰� �̸� �Է�
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 5�� ����: ����
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
