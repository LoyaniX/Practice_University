#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QCheckBox"
#include "QGridLayout"
#include "QMenuBar"
#include "QSpacerItem"
#include "QAction"
#include"QDialog"
#include"qcustomplot.h"
#include"math.h"
#include"QMessageBox"
#include"QTextStream"
#define PI  3.141592
#define E  2.718281
static int zz=0;

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    void Verify(QLineEdit *line,QString str);
private:
    int count;

    QMenu *File;
    QMenu *Edit;
    QMenu *Information;
    QAction *Reset;
    QAction *Close;
    QAction *Save;
    QAction *Metodich;
    QAction *Grafic;
    QAction *Info;
    QAction *Contact;

    QLabel *ProgramName;
    QLabel *CoderName;
    QLabel *NameLabel;
    QLineEdit *NameEdit;
    QLabel *GroupLabel;
    QLineEdit *GroupEdit;
    QLabel *NameRn;
    QLineEdit *EditRn;
    QLabel *LabelRn;
    QLabel *NameCn;
    QLineEdit *EditCn;
    QLabel *LabelCn;
    QLabel *NameRb1;
    QLineEdit *EditRb1;
    QLabel *LabelRb1;
    QLabel *NameRb2;
    QLineEdit *EditRb2;
    QLabel *LabelRb2;
    QLabel *NameRk;
    QLineEdit *EditRk;
    QLabel *LabelRk;
    QLabel *NameRe1;
    QLineEdit *EditRe1;
    QLabel *LabelRe1;
    QLabel *NameRe2;
    QLineEdit *EditRe2;
    QLabel *LabelRe2;
    QLabel *NameCe;
    QLineEdit *EditCe;
    QLabel *LabelCe;
    QLabel *NameCp;
    QLineEdit *EditCp;
    QLabel *LabelCp;
    QLabel *H21;
    QLineEdit *EditH21;
    QLabel *NameIkbo;
    QLineEdit *EditIkbo;
    QLabel *LabelIkbo;
    QLabel *NameUs;
    QLineEdit *EditUs;
    QLabel *LabelUs;
    QLabel *NameTmax;
    QLineEdit *EditTmax;
    QLabel *LabelTmax;
    QLabel *LabelMaterial;
	QLineEdit *EditMaterial;
    QLabel *NameFn;
    QLineEdit *EditFn;
    QLabel *LabelFn;
    QLabel *NameFv;
    QLineEdit *EditFv;
    QLabel *LabelFv;
    QPushButton *Calc;
    QCheckBox *Graf;
    QLabel *Shema;
    QPixmap pix;
    QPixmap fon;
private slots:
    void Ok();
    void TextChenged();
    void Exit();
    void SaveAs();
    void Metodichka();
    void Inform();
    void Cont();
    void Grafick();
signals:
    void MyTextChenged(QLineEdit *line,QString str);

};



class GrafikWindow : public QMainWindow
{
    Q_OBJECT

public:
    GrafikWindow(QWidget *parent = 0);
    ~GrafikWindow();


private:
    QMenu *Filem;
    QAction *Save;
    QCustomPlot *cPlot;
    QCPItemText *Fvtext;
    QCPItemText *Fntext;
public slots:
    void Saveas();
signals:


};




class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    ResultWindow(QWidget *parent = 0);
    ~ResultWindow();

private:
    QMenu *Filem;
    QAction *Save;
    QLabel *Lab;
    QLabel *LabUs;
    QLabel *Ukeq;
    QLabel *Ikq;
    QLabel *Ibq;
    QLabel *St;
    QLabel *dUke;
    QLabel *dIkq;
    QLabel *H11;
    QLabel *K;
    QLabel *Uoutmax;
    QLabel *Uoutplus;
    QLabel *Uoutminus;
    QGridLayout *Layout;
    QWidget *Widget;
    QLabel *Namel;
    QLabel *Group;
    double RB;
    double Rkn;
    double Uss;
    double b;
    double dIkbo;
    double dIkqq;
    double Uost;
    double Um;
    double Ukeqq;
    double Ikqq;
    double Ibqq;
    double Stt;
    double dUkeqq;
    double QIkqq;
    double H11q;
    double Kk;
    double Uoutmaxx;
    double Uoutpluss;
    double Uoutminuss;
public slots:
    void Saveas();
signals:

};


class ShowMetodich : public QMainWindow
{
    Q_OBJECT
public:
    ShowMetodich(QWidget *parent=0);
    ~ShowMetodich();
private:
    QPixmap img;
    QLabel *Image;
    QPushButton *LeftButton;
    QPushButton *RightButton;
    QHBoxLayout *layout;
   // unsigned int t;
public slots:
    void next();
    void prew();

};

#endif // MYMAINWINDOW_H
