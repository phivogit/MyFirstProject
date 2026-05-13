void studentGrading(string fileName) {
    ifstream file(fileName);
    int N = 0;
    file >> N;
    int gA = 0, gB = 0, gC = 0, gD = 0;
    for (int i = 0; i < N; i++) {
        double a, b, c, d;
        bool below5 = false;
        file >> a >> b >> c >> d;
        if (a < 5 || b < 5 || c < 5 || d < 5) {
            below5 = true;
        }
        if (!below5 && (a + b + c + d)/4 >= 8) gA++;
        else if (!below5 && (a + b + c + d)/4 >= 6.5) gB++;
        else if (!below5 && (a + b + c + d)/4 >= 5) gC++;
        else gD++;
    }
    file.close();
    cout << "A " << gA << endl;
    cout << "B " << gB << endl;
    cout << "C " << gC << endl;
    cout << "D " << gD << endl; 
}