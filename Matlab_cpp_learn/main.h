//
// Created by lenovo on 2025/3/11.
//

#ifndef TEST_MIAN_H
#define TEST_MIAN_H
#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>

//基类：定义统一的接口
class FFTBase{
public:
    virtual  ~FFTBase() = default;

    //重载纯虚函数，分别是向量的还有矩阵的transform方法
    virtual Eigen::VectorXcd transform(const Eigen::VectorXd& X) = 0;
    virtual Eigen::MatrixXcd transform(const Eigen::MatrixXd& X) = 0;
};


//派生类：向量FFT变化类
class VectorFFT: public FFTBase
{
public:
    Eigen::VectorXcd transform(const Eigen::VectorXd& X) override
    {
        Eigen::FFT<double> fft;
        Eigen::VectorXcd y(X.size());
        fft.fwd(y,X);
        return y;
    }

    //对于输入矩阵的情况抛出异常
    Eigen::MatrixXcd transform(const Eigen::MatrixXd& X) override
    {
        throw std::invalid_argument("VectorFFT仅能接收向量作为参数，请重新输入");
    }
};


//派生类：矩阵FFT变化类
class MatrixFFT: public FFTBase
{
public:
    Eigen::MatrixXcd transform(const Eigen::MatrixXd& X) override
    {
        Eigen::FFT<double> fft;
        Eigen::MatrixXcd y(X.rows(), X.cols());
        for(int col = 0; col < X.cols(); ++col){
            Eigen::VectorXd x_col = X.col(col);
            Eigen::VectorXcd y_col;
            fft.fwd(y_col, x_col);
            y.col(col) = y_col;
        }
        return y;
    }

    //对于输入向量的情况抛出异常
    Eigen::VectorXcd transform(const Eigen::VectorXd& X) override
    {
        throw std::invalid_argument("MatrixFFT仅能接收矩阵作为参数，请重新输入");
    }
};




#endif //TEST_MIAN_H
