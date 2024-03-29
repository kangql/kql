#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<map>
#include<vector>
#include<set>
using namespace std;
struct Node
{
    QString word;
    int times;
};

class QTextEdit;
class MySyntaxHighlighter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openFile();
    void saveFile();

public:
    QTextEdit *textEdit;

private:
    QAction *openAction;
    QAction *saveAction;

    QString s;
    QWidget *centralW,*rightW;
    QHBoxLayout *layout;
    map<QString,int> mp;
    vector<Node> v;
    set<QString> st;
    const static int R=100,C=100;//GridLayout的规模
    bool fill[R][C];//保存每一块是否被占用
    bool ok(int r,int c,int h,int l);//判断左上角放在gird(r,c)且规模为h*l的单词能否放下
    void set(int r,int c,int h,int l);//修改fill
    QGridLayout *g;

public:
    MySyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H
