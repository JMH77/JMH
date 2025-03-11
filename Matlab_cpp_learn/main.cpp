#include "main.h"
using namespace std;

int main(){

    //�����ĸ���Ҷ�任
    Eigen::VectorXd x(8);
    x << 1,2,3,4,5,6,7,8;
    FFTBase* fft1 = new VectorFFT();
    Eigen::VectorXcd y = fft1->transform(x);
    cout << "�����ĸ���Ҷ�任���Ϊ��" << endl
    << y << endl;
    delete fft1;

    //����ĸ���Ҷ�任
    Eigen::MatrixXd X(8, 2);
    X <<    0, 8,
            1, 7,
            2, 6,
            3, 5,
            4, 4,
            5, 3,
            6, 2,
            7, 1;
    FFTBase* fft2 = new MatrixFFT();
    Eigen::MatrixXcd Y = fft2->transform(X);
    cout << "����ĸ���Ҷ�任���Ϊ��"  << endl
    << Y << endl;
    delete fft2;


    return 0;
}




// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.