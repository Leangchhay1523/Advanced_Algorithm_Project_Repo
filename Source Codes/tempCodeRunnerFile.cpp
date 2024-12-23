
void printHeader(string text){
    int textLength = text.length();
    int sizeToPrint = textLength + 10;
    
    for (int i = 0; i < sizeToPrint; i++)
    {
        cout << "-";
    }
    cout << endl;
    
    cout << "---- " << "\033[1m" << text << "\033[0m" << " ----" << endl;
    
    for (int i = 0; i < sizeToPrint; i++)
    {
        cout << "-";
    }
    cout << endl << "Note : Input 0 to go back" << endl << endl;
}