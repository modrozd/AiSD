// Project 3, AiSD 2020 - MAST
// Monika Drozd

#include <iostream>
using namespace std;

struct BTNode //drzewo binarne - syn w lewo lub prawo
{
    BTNode* left;
    BTNode* right;
    int level;
    int data;
};

// Zmienne globalne

int maxpath = 0;           // d�ugo�� najd�u�szej �cie�ki / wysoko�� drzewa
int minpath = 2147483647;  // d�ugo�� najkr�tszej �cie�ki
int* levelcount;          // tablica licznik�w
int leafcount = 0;         // liczba li�ci
int onechildcount = 0;     // liczba w�z��w z jedynakiem
int nodesum = 0;           // suma danych w�z��w

int n;                     // liczba w�z��w
BTNode* root;             // wskazanie korzenia drzewa


// Procedura inicjuje dane, odczytuje definicj� drzewa
// ze standardowego wej�cia i tworzy jego struktur� w
// pami�ci. Na wyj�ciu w zmiennej root zostaje umieszczony
// adres korzenia drzewa
//--------------------------------------------------------
void readBT()
{
    BTNode** vp;              // tablica wska�nik�w
    int i, d, l, r;

    cin >> n;                  // odczytujemy liczb� w�z��w drzewa binarnego

    vp = new BTNode * [n];   // tworzymy tablic� dynamiczn� wska�nik�w

    for (i = 0; i < n; i++)
        vp[i] = new BTNode;   // tworzymy dynamicznie w�ze�

    for (i = 0; i < n; i++)
    {
        cin >> d >> l >> r;      // odczytujemy tr�jk� liczb

        vp[i]->level = 0;    // zerujemy poziom w�z�a

        vp[i]->data = d;     // wprowadzamy do w�z�a dane

        vp[i]->left = l ? vp[l] : NULL;  // ustawiamy lewego syna, je�li istnieje

        vp[i]->right = r ? vp[r] : NULL;  // ustawiamy prawego syna, je�li istnieje
    }

    root = vp[0];           // zapami�tujemy korze� drzewa

    delete[] vp;             // usuwamy tablic� wska�nik�w

    // tworzymy tablic� licznik�w element�w na poziomach

    levelcount = new int[n];
    for (i = 0; i < n; i++) levelcount[i] = 0;
}

// Procedura przechodzi drzewo algorytmem DFS:preorder
// i odpowiednio przetwarza w�z�y zapisuj�c wyniki
// w zmiennych globalnych
void DFS(BTNode* v)
{
    if (v)
    {
        // przetwarzamy bie��cy w�ze�
        int children = 0; // liczba dzieci, 0, 1 lub 2
        if (v->left)
        {
            children++;
            v->left->level = v->level + 1;
        }
        if (v->right)
        {
            children++;
            v->right->level = v->level + 1;
        }
        // test na najd�u�sz� �cie�k�
        if (v->level > maxpath) maxpath = v->level;
        // test na najkr�tsz� �cie�k� do li�cia i zliczanie li�ci
        if (!children)
        {
            if (v->level < minpath) minpath = v->level;
            leafcount++;
        }
        // zliczanie w�z��w na bie��cym poziomie poziomie
        levelcount[v->level] ++;
        // zliczanie w�z��w z jednym synem
        if (children == 1) onechildcount++;
        // sumowanie zawarto�ci w�z��w
        nodesum += v->data;
        DFS(v->left);  // przechodzimy lewe poddrzewo
        DFS(v->right); // przechodzimy prawe poddrzewo
    }
}

// Procedura wy�wietla wyniki ko�cowe
void writeBT()
{
    cout << endl
        << "maxpath       = " << maxpath << endl
        << "minpath       = " << minpath << endl
        << endl;
    for (int i = 0; i <= maxpath; i++)
        cout << "level " << i << ": number of nodes = " << levelcount[i] << endl;
    cout << endl
        << "leafcount     = " << leafcount << endl
        << "onechildcount = " << onechildcount << endl
        << "nodesum       = " << nodesum << endl
        << endl;
}

// Procedura DFS:postorder usuwaj�ca drzewo
void DFSRelease(BTNode* v)
{
    if (v)
    {
        DFSRelease(v->left);   // usuwamy lewe poddrzewo
        DFSRelease(v->right);  // usuwamy prawe poddrzewo
        delete v;              // usuwamy sam w�ze�
    }
}

// Procedura sprz�ta pami��
void deleteBT()
{
    delete[] levelcount;
    DFSRelease(root);   // wykorzystujemy DFS:postorder do usuni�cia drzewa
}


int main()
{
    readBT();    // odczytaj i utw�rz drzewo
    DFS(root);   // przetw�rz drzewo
    writeBT();   // wypisz wyniki
    deleteBT();  // posprz�taj pami��

    return 0;
}
