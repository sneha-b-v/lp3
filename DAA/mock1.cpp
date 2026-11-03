
// Write a program to implement Huffman Encoding using a greedy strategy.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    int frequency;
    Node *left, *right;

    Node(char ch, int freq)
    {
        data = ch;
        frequency = freq;
        left = right = nullptr;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

void printCodes(Node *root, string code)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of characters must be positive." << endl;
        return 0;
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;

    cout << "Enter character and frequency:" << endl;

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;
        cin >> ch >> freq;

        if (freq <= 0)
        {
            cout << "Frequency must be positive." << endl;
            return 0;
        }

        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$',
                                left->frequency + right->frequency);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "Huffman Codes:" << endl;
    printCodes(pq.top(), "");

    return 0;
}