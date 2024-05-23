#include <iostream>
#include <string>

using namespace std;

struct Note {
    string lastName;
    string firstName;
    string phoneNumber;
    int birthDate[3];
};

struct TreeNode {
    Note data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(const Note& person) {
    TreeNode* newNode = new TreeNode();
    newNode->data = person;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, const Note& person) {
    if (root == nullptr)
        return createNode(person);

    if (person.birthDate[2] < root->data.birthDate[2] ||
        (person.birthDate[2] == root->data.birthDate[2] && person.birthDate[1] < root->data.birthDate[1]) ||
        (person.birthDate[2] == root->data.birthDate[2] && person.birthDate[1] == root->data.birthDate[1] && person.birthDate[0] < root->data.birthDate[0])) {
        root->left = insertNode(root->left, person);
    }
    else
        root->right = insertNode(root->right, person);

    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << "Last Name: " << root->data.lastName << endl;
    cout << "First Name: " << root->data.firstName << endl;
    cout << "Phone Number: " << root->data.phoneNumber << endl;
    cout << "Birth Date: " << root->data.birthDate[0] << "/" << root->data.birthDate[1] << "/" << root->data.birthDate[2] << endl;
    cout << endl;
    inOrderTraversal(root->right);
}

TreeNode* searchByPhoneNumber(TreeNode* root, const string& phoneNumber) {
    if (root == nullptr || root->data.phoneNumber == phoneNumber)
        return root;

    TreeNode* foundNode = searchByPhoneNumber(root->left, phoneNumber);
    if (foundNode != nullptr)
        return foundNode;

    return searchByPhoneNumber(root->right, phoneNumber);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;

    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Note person;
        cout << "Enter data for person " << i + 1 << ":" << endl;
        cout << "Last name: ";
        getline(cin, person.lastName);
        cout << "First name: ";
        getline(cin, person.firstName);
        cout << "Phone number: ";
        getline(cin, person.phoneNumber);
        cout << "Birth date (day month year): ";
        cin >> person.birthDate[0] >> person.birthDate[1] >> person.birthDate[2];
        cin.ignore();

        root = insertNode(root, person);
    }

    cout << "\nSorted list by birth dates:" << endl;
    inOrderTraversal(root);

    string searchPhoneNumber;
    cout << "\nEnter phone number to search for: ";
    getline(cin, searchPhoneNumber);
    TreeNode* foundNode = searchByPhoneNumber(root, searchPhoneNumber);
    if (foundNode != nullptr) {
        cout << "Person found:" << endl;
        cout << "Last Name: " << foundNode->data.lastName << endl;
        cout << "First Name: " << foundNode->data.firstName << endl;
        cout << "Phone Number: " << foundNode->data.phoneNumber << endl;
        cout << "Birth Date: " << foundNode->data.birthDate[0] << "/" << foundNode->data.birthDate[1] << "/" << foundNode->data.birthDate[2] << endl;
    }
    else
        cout << "Person with phone number '" << searchPhoneNumber << "' not found." << endl;

    deleteTree(root);

    return 0;
}