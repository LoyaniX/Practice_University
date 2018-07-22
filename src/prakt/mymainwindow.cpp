#include "mymainwindow.h"
#include"iostream"
#define widthh  100
#define hightt 22
QString Defalt[16]={
    "600",      //Rn
    "8",        //Cn
    "6032",     //Rb1
    "1300",     //Rb2
    "1500",     //Rk
    "16",       //Re1
    "360",      //Re2
    "390",    //Ce
    "4.3",     //Cp
    "40",       //h21
    "2",        //Ikbo
    "21",       //Us
    "60",       //Tmax
    "Si",     //Material
    "30",       //Fn
    "45100"     //Fv
};
double Defaltn[15]={
    600,      //Rn
    8,        //Cn
    6032,     //Rb1
    1300,     //Rb2
    1500,     //Rk
    16,       //Re1
    360,      //Re2
    375.5,    //Ce
    4.14,     //Cp
    40,       //h21
    2,        //Ikbo
    21,       //Us
    60,       //Tmax
    40,       //Fn
    16000     //Fv
};
QString Name;
QString Groupe;
QString im[6]={":/m1.png",":/m2.png",":/m3.png",":/m4.png",":/m5.png",":/m6.png"};
MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent){
    File = menuBar()->addMenu("Файл");
    Edit = menuBar()->addMenu("Расчет");
    Information = menuBar()->addMenu("Помощь");
    Close=new QAction(tr("Закрыть"),this);
    Close->setShortcut(tr("Ctrl+Q"));
    Metodich=new QAction(tr("Метод.указания"),this);
    Grafic=new QAction(tr("АЧХ"),this);
    Info=new QAction(tr("О парограмме"),this);
    Info->setShortcut(tr("Ctrl+I"));
    Contact=new QAction(tr("Обратная связь"),this);
    File->addAction(Close);
    Edit->addAction(Metodich);
    Edit->addAction(Grafic);
    Information->addAction(Info);
    Information->addAction(Contact);
    NameLabel=new QLabel("Ф.И.О");
    NameEdit=new QLineEdit("Лоян М.А.");
    GroupLabel=new QLabel("Группа");
    GroupEdit=new QLineEdit("Тзит-14-1");
    NameRn=new QLabel("Rн=");
    EditRn=new QLineEdit("600");
    LabelRn=new QLabel("Ом");
    NameCn=new QLabel("Cн=");
    EditCn=new QLineEdit("8");
    LabelCn=new QLabel("нФ");
    NameRb1=new QLabel("Rб1=");
    EditRb1=new QLineEdit("6032");
    LabelRb1=new QLabel("Oм");
    NameRb2=new QLabel("Rб2=");
    EditRb2=new QLineEdit("1300");
    LabelRb2=new QLabel("Ом");
    NameRk=new QLabel("Rк=");
    EditRk=new QLineEdit("1500");
    LabelRk=new QLabel("Ом");
    NameRe1=new QLabel("Rэ1=");
    EditRe1=new QLineEdit("16");
    LabelRe1=new QLabel("Ом");
    NameRe2=new QLabel("Rэ2=");
    EditRe2=new QLineEdit("360");
    LabelRe2=new QLabel("Ом");
    NameCe=new QLabel("Cе=");
    EditCe=new QLineEdit("390");
    LabelCe=new QLabel("мкФ");
    NameCp=new QLabel("Cp=");
    EditCp=new QLineEdit("4.3");
    LabelCp=new QLabel("мкФ");
    H21=new QLabel("h21=");
    EditH21=new QLineEdit("40");
    NameIkbo=new QLabel("Iкбо=");
    EditIkbo=new QLineEdit("2");
    LabelIkbo=new QLabel("мкА");
    NameUs=new QLabel("Us=");
    EditUs=new QLineEdit("21");
    LabelUs=new QLabel("B");
    NameTmax=new QLabel("Tmax=");
    EditTmax=new QLineEdit("60");
    LabelTmax=new QLabel("°C");
    LabelMaterial=new QLabel("Материал:");
    EditMaterial=new QLineEdit("Si");
    NameFn=new QLabel("Fн=");
    EditFn=new QLineEdit("30");
    LabelFn=new QLabel("Гц");
    NameFv=new QLabel("Fв=");
    EditFv=new QLineEdit("45100");
    LabelFv=new QLabel("Гц");

    EditRn->setFixedSize(widthh,hightt);
    EditCn->setFixedSize(widthh,hightt);
    EditRb1->setFixedSize(widthh,hightt);
    EditRb2->setFixedSize(widthh,hightt);
    EditRk->setFixedSize(widthh,hightt);
    EditRe1->setFixedSize(widthh,hightt);
    EditRe2->setFixedSize(widthh,hightt);
    EditCe->setFixedSize(widthh,hightt);
    EditCp->setFixedSize(widthh,hightt);
    EditH21->setFixedSize(widthh,hightt);
    EditIkbo->setFixedSize(widthh,hightt);
    EditUs->setFixedSize(widthh,hightt);
    EditTmax->setFixedSize(widthh,hightt);
    EditMaterial->setFixedSize(widthh,hightt);
    EditFn->setFixedSize(widthh,hightt);
    EditFv->setFixedSize(widthh,hightt);

    Graf=new QCheckBox("График АЧХ");

    Shema=new QLabel();
    Shema->setFixedSize(490,420);
    pix.load(":/shema.jpg");
    Shema->setPixmap(pix);
    Shema->setScaledContents(true);
    Calc=new QPushButton();
    Calc->setFixedSize(90,90);
    Calc->setShortcut(Qt::Key_Return);
    Calc->setStyleSheet(
       "QPushButton{"
           "background-color: transparent;"
           "border-image: url(:c.png);"
           "background: none;"
           "border: none;"
           "background-repeat: none;"
           "}"
           "QPushButton:pressed{"
           "border-image: url(:cal.png);"
           "}");

    QGridLayout *GridLayout=new QGridLayout;

    GridLayout->addWidget(NameLabel,0,0,1,1);
    GridLayout->addWidget(NameEdit,0,1,1,3);
    GridLayout->addWidget(GroupLabel,1,0,1,1);
    GridLayout->addWidget(GroupEdit,1,1,1,3);
    GridLayout->addWidget(NameRn,2,0,1,1);
    GridLayout->addWidget(EditRn,2,1,1,2);
    GridLayout->addWidget(LabelRn,2,3,1,1);
    GridLayout->addWidget(NameCn,3,0,1,1);
    GridLayout->addWidget(EditCn,3,1,1,2);
    GridLayout->addWidget(LabelCn,3,3,1,1);
    GridLayout->addWidget(NameRb1,4,0,1,1);
    GridLayout->addWidget(EditRb1,4,1,1,2);
    GridLayout->addWidget(LabelRb1,4,3,1,1);
    GridLayout->addWidget(NameRb2,5,0,1,1);
    GridLayout->addWidget(EditRb2,5,1,1,2);
    GridLayout->addWidget(LabelRb2,5,3,1,1);
    GridLayout->addWidget(NameRk,6,0,1,1);
    GridLayout->addWidget(EditRk,6,1,1,2);
    GridLayout->addWidget(LabelRk,6,3,1,1);
    GridLayout->addWidget(NameRe1,7,0,1,1);
    GridLayout->addWidget(EditRe1,7,1,1,2);
    GridLayout->addWidget(LabelRe1,7,3,1,1);
    GridLayout->addWidget(NameRe2,8,0,1,1);
    GridLayout->addWidget(EditRe2,8,1,1,2);
    GridLayout->addWidget(LabelRe2,8,3,1,1);
    GridLayout->addWidget(NameCe,9,0,1,1);
    GridLayout->addWidget(EditCe,9,1,1,2);
    GridLayout->addWidget(LabelCe,9,3,1,1);
    GridLayout->addWidget(NameCp,10,0,1,1);
    GridLayout->addWidget(EditCp,10,1,1,2);
    GridLayout->addWidget(LabelCp,10,3,1,1);
    GridLayout->addWidget(H21,11,0,1,1);
    GridLayout->addWidget(EditH21,11,1,1,2);
    GridLayout->addWidget(NameIkbo,12,0,1,1);
    GridLayout->addWidget(EditIkbo,12,1,1,2);
    GridLayout->addWidget(LabelIkbo,12,3,1,1);
    GridLayout->addWidget(NameUs,13,0,1,1);
    GridLayout->addWidget(EditUs,13,1,1,2);
    GridLayout->addWidget(LabelUs,13,3,1,1);
    GridLayout->addWidget(NameTmax,14,0,1,1);
    GridLayout->addWidget(EditTmax,14,1,1,2);
    GridLayout->addWidget(LabelTmax,14,3,1,1);
    GridLayout->addWidget(LabelMaterial,15,0,1,1);
    GridLayout->addWidget(EditMaterial,15,1,1,2);
    GridLayout->addWidget(NameFn,16,0,1,1);
    GridLayout->addWidget(EditFn,16,1,1,2);
    GridLayout->addWidget(LabelFn,16,3,1,1);
    GridLayout->addWidget(NameFv,17,0,1,1);
    GridLayout->addWidget(EditFv,17,1,1,2);
    GridLayout->addWidget(LabelFv,17,3,1,1);

    QLabel *lb=new QLabel();
    GridLayout->addWidget(lb,18,0,1,1);
    GridLayout->addWidget(Shema,0,6,13,10);
    GridLayout->addWidget(Calc,15,14,4,4);

    GridLayout->addWidget(Graf,16,11,1,2);

    QWidget *Widg=new QWidget;
    Widg->setStyleSheet("background-color:white;");
    Widg->setLayout(GridLayout);
    setCentralWidget(Widg);

    connect(EditRn,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditCn,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditRb1,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditRb2,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditRk,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditRe1,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditRe2,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditCe,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditCp,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditH21,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditIkbo,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditUs,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditTmax,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditMaterial,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditFn,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(EditFv,SIGNAL(textChanged(QString)),this,SLOT(TextChenged()));
    connect(Close,SIGNAL(triggered(bool)),this,SLOT(Exit()));
    connect(Info,SIGNAL(triggered(bool)),this,SLOT(Inform()));
    connect(Contact,SIGNAL(triggered(bool)),this,SLOT(Cont()));
    connect(Metodich,SIGNAL(triggered(bool)),this,SLOT(Metodichka()));
    connect(Grafic,SIGNAL(triggered(bool)),this,SLOT(Grafick()));
    connect(Calc,SIGNAL(clicked(bool)),this,SLOT(Ok()));
}


void MyMainWindow::TextChenged(){
    Calc->setEnabled(false);
    count=0;
    Verify(EditRn,Defalt[0]);
    Verify(EditCn,Defalt[1]);
    Verify(EditRb1,Defalt[2]);
    Verify(EditRb2,Defalt[3]);
    Verify(EditRk,Defalt[4]);
    Verify(EditRe1,Defalt[5]);
    Verify(EditRe2,Defalt[6]);
    Verify(EditCe,Defalt[7]);
    Verify(EditCp,Defalt[8]);
    Verify(EditH21,Defalt[9]);
    Verify(EditIkbo,Defalt[10]);
    Verify(EditUs,Defalt[11]);
    Verify(EditTmax,Defalt[12]);
    Verify(EditMaterial,Defalt[13]);
    Verify(EditFn,Defalt[14]);
    Verify(EditFv,Defalt[15]);
    if(count==16) Calc->setEnabled(true);
}

ResultWindow::ResultWindow(QWidget *parent):QMainWindow(parent){
     Filem = menuBar()->addMenu("Файл");
     Save=new QAction(tr("Сохранить"),this);
     Save->setShortcut(tr("Ctrl+S"));
     Filem->addAction(Save);
     setWindowTitle("Результат расчета");
     setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
     setFixedSize(300,250);

     Uost=0.5;
     Um=3.5;
     b=0.124;
     Stt=4;
     RB=(Defaltn[2]*Defaltn[3])/(Defaltn[2]+Defaltn[3]);
     Rkn=(Defaltn[0]*Defaltn[4])/(Defaltn[0]+Defaltn[4]);
     Ukeqq=(Uost+Um)/0.78+0.2;
     dUkeqq=0.22*Ukeqq;
     dIkbo=Defaltn[10]*pow(10,-3)*pow(E,b*(Defaltn[12]-25));
     dIkqq=Stt*dIkbo+0.002;
     Ikqq=Um/Rkn;
     Ibqq=Ikqq/Defaltn[9]*1000;
     Uss=Ukeqq+(Defaltn[4]+Defaltn[5]+Defaltn[6])*Ikqq;
     Ikqq=(Uss-Ukeqq)/(Defaltn[4]+Defaltn[5]+Defaltn[6])*1000+0.19;
     Ibqq=Ikqq/Defaltn[9]*1000-2;
     H11q=45/Ibqq*1000;
     Stt=1+RB/(Defaltn[5]+Defaltn[6]);
     Kk= Defaltn[9]*Rkn/(H11q+Defaltn[9]*Defaltn[5]);
     Uoutpluss=Rkn*(Ikqq-0.1)/1000;
     Uoutminuss=Ukeqq-Uost;
     if(Uoutminuss<=Uoutpluss){
         Uoutmaxx=Uoutminuss;
     }
     else{
         Uoutmaxx=Uoutpluss;
     }
     Lab=new QLabel(tr("<b>Режим покоя:<b>"));
     Ukeq=new QLabel("Ukeq = "+QString::number(Ukeqq,'g',2)+" В ");
     dUke=new QLabel("ΔUkeq = "+QString::number(dUkeqq,'g',3)+" В ");
     dIkq=new QLabel("ΔIkq = "+QString::number(dIkqq,'g',3)+" мА ");
     Ikq=new QLabel("Ikq = "+QString::number(Ikqq,'g',3)+" мА ");
     Ibq=new QLabel("Ibq = "+QString::number(Ibqq,'g',3)+" мкА ");
     H11=new QLabel("H11 = "+QString::number(H11q,'g',3)+" Ом ");
     St=new QLabel("Sт = "+QString::number(Stt,'g',3));
     Namel=new QLabel("<b>Ф.И.О:   <b>"+Name);
     Group=new QLabel("<b>Группа:   <b>"+Groupe);
     Uoutmax=new QLabel("Uвых.макс. = "+QString::number(Uoutmaxx,'g',3)+" В ");
     LabUs=new QLabel(tr("<b>Режим усиления:<b>"));
     K=new QLabel("K0 = "+QString::number(Kk,'g',4)+"  на средних частотах");
     Layout=new QGridLayout;
     Layout->addWidget(Lab,0,0,1,2);
     Layout->addWidget(Ukeq,1,0,1,1);
     Layout->addWidget(dUke,2,0,1,1);
     Layout->addWidget(dIkq,3,0,1,1);
     Layout->addWidget(Ikq,4,0,1,1);
     Layout->addWidget(Ibq,1,2,1,1);
     Layout->addWidget(H11,2,2,1,1);
     Layout->addWidget(St,3,2,1,1);
     Layout->addWidget(LabUs,5,0,1,2);
     Layout->addWidget(K,6,0,1,2);
     Layout->addWidget(Uoutmax,7,0,1,1);
     Layout->addWidget(Namel,8,0,1,2);
     Layout->addWidget(Group,9,0,1,2);
     Widget=new QWidget;
     Widget->setLayout(Layout);
     setCentralWidget(Widget);
     connect(Save,SIGNAL(triggered(bool)),this,SLOT(Saveas()));
}

void ResultWindow::Saveas(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить результат как", "", "Text Files(*.txt)");
    QFile File(fileName);
    File.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream(&File);
    stream<<trUtf8("Выполнил студент ")<<Name<<" \n";
    stream<<trUtf8("Группа ")<<Groupe<<" \n";
    stream<<trUtf8("Режим покоя:\n");
    stream<<"Ukeq = "<<QString::number(Ukeqq,'g',2)<<trUtf8(" В \n");
    stream<<"dUkeq = "<<QString::number(dUkeqq,'g',3)<<trUtf8(" В \n");
    stream<<"dIkq = "<<QString::number(dIkqq,'g',3)<<trUtf8(" мА \n");
    stream<<"Ikq = "<<QString::number(Ikqq,'g',3)<<trUtf8(" мА \n");
    stream<<"Ibq = "<<QString::number(Ibqq,'g',3)<<trUtf8(" мкА \n");
    stream<<"H11 = "<<QString::number(H11q,'g',3)<<trUtf8(" Ом \n");
    stream<<trUtf8("Sт = ")<<QString::number(Stt,'g',3)<<"\n";
    stream<<trUtf8("Режим усиления:\n");
    stream<<trUtf8("Uвых.макс = ")<<QString::number(Uoutmaxx,'g',3)<<trUtf8(" В \n");
    stream<<trUtf8("Uвых.+ = ")<<QString::number(Uoutpluss,'g',3)<<trUtf8(" В \t");
    stream<<trUtf8("Uвых.- = ")<<QString::number(Uoutminuss,'g',3)<<trUtf8(" В \n");
    stream<<"K0 = "<<QString::number(Kk,'g',4)<<trUtf8("  на средних частотах");
    stream.flush();
    File.close();
}

GrafikWindow::GrafikWindow(QWidget *parent):QMainWindow(parent){
    setWindowTitle("АЧХ");
    setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
    setMinimumSize(600,500);
    Filem = menuBar()->addMenu("Файл");
    Save=new QAction(tr("Сохранить"),this);
    Save->setShortcut(tr("Ctrl+S"));
    Filem->addAction(Save);
    cPlot=new QCustomPlot();
    cPlot->addGraph();
    cPlot->addGraph();
    cPlot->addGraph();
    cPlot->addGraph();
    QPen DotLine;
    QCPItemText *groupTracerText = new QCPItemText(cPlot);
    cPlot->addItem(groupTracerText);
    groupTracerText->position->setType(QCPItemPosition::ptAxisRectRatio);
    groupTracerText->setPositionAlignment(Qt::AlignRight|Qt::AlignTop);
    groupTracerText->position->setCoords(0.92, 0.25); // lower right corner of axis rect
    groupTracerText->setText(tr("Fv=45,1кГц"));
    groupTracerText->setTextAlignment(Qt::AlignLeft);
    groupTracerText->setFont(QFont(font().family(), 12));
    groupTracerText->setPadding(QMargins(8, 0, 0, 0));

    QCPItemLine *arrow = new QCPItemLine(cPlot);
    cPlot->addItem(arrow);
    arrow->start->setParentAnchor(groupTracerText->bottom);
    arrow->end->setCoords(45100, 14.14);
    arrow->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *groupTracerText1 = new QCPItemText(cPlot);
    cPlot->addItem(groupTracerText1);
    groupTracerText1->position->setType(QCPItemPosition::ptAxisRectRatio);
    groupTracerText1->setPositionAlignment(Qt::AlignRight|Qt::AlignTop);
    groupTracerText1->position->setCoords(0.2, 0.25); // lower right corner of axis rect
    groupTracerText1->setText(tr("Fn=30Гц"));
    groupTracerText1->setTextAlignment(Qt::AlignLeft);
    groupTracerText1->setFont(QFont(font().family(), 11));
    groupTracerText1->setPadding(QMargins(8, 0, 0, 0));

    QCPItemLine *arrow1 = new QCPItemLine(cPlot);
    cPlot->addItem(arrow1);
    arrow1->start->setParentAnchor(groupTracerText1->bottom);
    arrow1->end->setCoords(18, 14.14);
    arrow1->setHead(QCPLineEnding::esSpikeArrow);

    DotLine.setStyle(Qt::DotLine);
    DotLine.setWidthF(2);
    cPlot->graph(1)->setPen(DotLine);
    cPlot->graph(1)->setPen(QPen(Qt::gray));
    cPlot->graph(2)->setPen(DotLine);
    cPlot->graph(2)->setPen(QPen(Qt::gray));
    cPlot->graph(3)->setPen(DotLine);
    cPlot->graph(3)->setPen(QPen(Qt::gray));
    double Mv=1.4,
           Mn=1.4;
    QVector<double> k0(2), k(1000000), f(1000000), fv(100), kv(100), fn(100), kn(100),fq(1000000), kq(1000000);
    for(int r=0;r<100;r++){
        fv[r]=45100;
        kv[r]=r;
    }
    for(int r=0;r<100;r++){
        fn[r]=19;
        kn[r]=r ;
    }
    double K0=19.8;
    for (long int i=0; i<1000000; i=i+1){
        f[i]=i;
        if(i<=1000){
            k[i]=K0/sqrt(1+pow(1/(2*PI*i*4.14*pow(10,-6)*2100),2));
        }
        else{
            k[i]=K0/sqrt(1+pow((2*PI*i*8*pow(10,-9)*428),2));
        }
        fq[i]=i;
        kq[i]=14.14;

    }
    cPlot->graph(0)->setData(f,k);
    cPlot->graph(1)->setData(fv,kv);
    cPlot->graph(2)->setData(fn,kn);
    cPlot->graph(3)->setData(fq,kq);
    cPlot->xAxis->setLabel("f");
    cPlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
    cPlot->yAxis->setLabel("K");
    cPlot->xAxis->setRange(1,2000000);
    cPlot->yAxis->setRange(0, 23);
    cPlot->replot();
    setCentralWidget(cPlot);
    connect(Save,SIGNAL(triggered(bool)),this,SLOT(Saveas()));
}

void GrafikWindow::Saveas(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить график как", "", "Graphics file(*.png)");
    QFile File(fileName);
    QRect rec = QApplication::desktop()->screenGeometry();
    int heights = rec.height();
    int widths = rec.width();
    cPlot->savePng(fileName,widths,heights,1,1);
    File.close();
}

void MyMainWindow::Grafick(){
    GrafikWindow *wind=new GrafikWindow();
    wind->show();
}

void MyMainWindow::Ok(){
    Name=NameEdit->text();
    Groupe=GroupEdit->text();
    if(Graf->isChecked()){
       GrafikWindow *wind=new GrafikWindow();
       wind->show();
    }
    ResultWindow *Window=new ResultWindow();
    Window->show();
}

void MyMainWindow::Verify(QLineEdit *line,QString str){
    if(line->text()!=str){
        line->setStyleSheet("border: 1px solid red");
    }
    else{
        line->setStyleSheet("border: 1px solid gray");
        count++;
    }
}

ResultWindow::~ResultWindow(){

}

void MyMainWindow::Exit(){
    close();
}

void MyMainWindow::SaveAs(){

}

ShowMetodich::ShowMetodich(QWidget *parent):QMainWindow(parent){
    setWindowTitle("Методические указания ");
    setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
    setMaximumSize(1347,707);
    Image=new QLabel;
    Image->showFullScreen();
    LeftButton=new QPushButton;
    RightButton=new QPushButton;
    LeftButton->setShortcut(QKeySequence(Qt::Key_Left));
    RightButton->setShortcut(QKeySequence(Qt::Key_Right));
    LeftButton->setFixedSize(135,500);
    RightButton->setFixedSize(135,500);
    LeftButton->setStyleSheet(
       "QPushButton{"
           "background-color: transparent;"
           "background: none;"
           "border: none;"
           "background-repeat: none;"
           "}"
           "QPushButton:pressed{"
           "}");
    RightButton->setStyleSheet(
       "QPushButton{"
           "background-color: transparent;"
           "background: none;"
           "border: none;"
           "background-repeat: none;"
           "}"
           "QPushButton:pressed{"
           "}");
    layout=new QHBoxLayout;
    layout->addWidget(LeftButton);
    layout->addWidget(Image);
    layout->addWidget(RightButton);
    QWidget *widg=new QWidget;
    img.load(im[0]);
    Image->setPixmap(img);
    widg->setLayout(layout);
    setCentralWidget(widg);
    connect(LeftButton,SIGNAL(clicked(bool)),this,SLOT(prew()));
    connect(RightButton,SIGNAL(clicked(bool)),this,SLOT(next()));
}

void ShowMetodich::next(){
    if(zz<5){
        zz++;
        img.load(im[zz]);
        Image->setPixmap(img);
    }
}
void ShowMetodich::prew(){
    if(zz>0){
        zz--;
        img.load(im[zz]);
        Image->setPixmap(img);

    }
}
ShowMetodich::~ShowMetodich(){

}

void MyMainWindow::Metodichka(){
    ShowMetodich *mwindow=new ShowMetodich();
    mwindow->show();
}

void MyMainWindow::Inform(){
   QMessageBox *Mess=new QMessageBox;
   Mess->setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
   Mess->setIcon(QMessageBox::Information);
   Mess->setWindowTitle("Version");
   Mess->setText(tr("<b>Alpha version 1.0.1<b>"));
   Mess->exec();
}

void MyMainWindow::Cont(){
    QDialog *dial=new QDialog;
    QLabel *lbl=new QLabel;
    dial->setFixedSize(200,100);
    lbl->setText("Loyan Max\n"
                 "© LoyaiX,2014\n"
                 "loyamaksim@Gmail.com\n"
                 "loyamax@protonmail.com");
    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(lbl);
    dial->setLayout(layout);
    dial->setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
    dial->setWindowTitle("Обратная связь");
    dial->exec();
}

GrafikWindow::~GrafikWindow(){

}
MyMainWindow::~MyMainWindow(){

}

