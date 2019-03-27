#include"morris.cpp"

int main() {
    string str = "124##5##36##7##";
    TreeNode* root = create(str);
    //printPre(root);
    cout << endl << "morris pre" << endl;
    morrisPre(root);
    cout << endl << "moriis mid" << endl;
    morrisIn(root);
    cout << endl << "moriis post" << endl;
    morrisPost(root);
    return 0;
}
