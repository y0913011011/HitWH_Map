﻿#include "mapnotes.h"
#include "ui_mapnotes.h"

MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);
}
void MapNotes::mousePressEvent(QMouseEvent *event){
    QPoint p_re = event->pos();
    QString str;
    str = QString("%1 , %2").arg(p_re.x()).arg(p_re.y());
    ui->label->setText(str);
}
void MapNotes::updateMapNotes(){

    re = route.getRoute(location);
    update();
}

void MapNotes::updateText(){
    string str;
    for(unsigned long long i=0;i<location.size();i++){
        int a = location.at(i);
        str += to_string(a);
        str += "->";
    }
    ui->yet->setText(QString::fromStdString(str));
}

void MapNotes::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // 设置画笔颜色
    static const QRgb colorTable[8] = {
        0x000000,0xFFA500, 0xCC6666, 0x66CC66, 0x00BFFF,
               0xBDB76B, 0xCC66CC,0x000000
    };
    //调色板
    QPen pen;
    pen.setWidth(3);
    QColor squreColor = colorTable[2];//绘制bubble
    pen.setColor(squreColor.light());
    painter.setPen(pen);
    painter.setBrush(squreColor);

    //按照坐标绘制路线
    QPoint* C;
    for(unsigned long long i=0;i<re.size();i++){
        C = new QPoint[re.at(i).getPointNumber()];
        for(unsigned long long j=0;j<re.at(i).getPointNumber();j++){
            C[j] = re.at(i).getPointList().at(j);
        }
        painter.drawPolyline(C,static_cast<int>(re.at(i).getPointNumber()));
    }
}

MapNotes::~MapNotes()
{
    delete ui;
}

void MapNotes::on_Bulid0_clicked()
{
    location.push_back(0);
    updateText();
}

void MapNotes::on_Build1_clicked()
{
    location.push_back(1);
    updateText();
}

void MapNotes::on_Bulid2_clicked()
{
    location.push_back(2);
    updateText();
}

vector<Road> MapNotes::getRe() const
{
    return re;
}

void MapNotes::setRe(const vector<Road> &value)
{
    re = value;
}

vector<int> MapNotes::getLocation() const
{
    return location;
}

void MapNotes::setLocation(const vector<int> &value)
{
    location = value;
}
