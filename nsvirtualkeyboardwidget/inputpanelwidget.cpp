#include "inputpanelwidget.h"

#include <QQuickItem>
#include <QScreen>
#include <QTimer>
#include <QApplication>


InputPanelWidget::InputPanelWidget(QWidget *parent)
    :QQuickWidget(parent), m_parent(parent)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setFocusPolicy(Qt::NoFocus);
    setClearColor(Qt::transparent);
    setAttribute(Qt::WA_AlwaysStackOnTop);
    setStyleSheet("background-color: transparent ; ");
    setResizeMode(QQuickWidget::SizeRootObjectToView);
    init();
}

InputPanelWidget::~InputPanelWidget()
{

}

bool InputPanelWidget::event(QEvent *evt)
{
    switch (evt->type()) {
    case QEvent::ApplicationActivate:
    case QEvent::ApplicationDeactivate:
    case QEvent::FocusIn:
    case QEvent::FocusOut:
        return false;
    default:
        break;
    }
    return QQuickWidget::event(evt);
}

void InputPanelWidget::inputPanelGeometryChanged(int x, int y, int width, int height)
{
    m_lastMask =  QRegion(x,y,width,height);
    qDebug() << "InputPanelView::inputPanelGeometryChanged mask : " << m_lastMask;
    setMask(m_lastMask);
}

void InputPanelWidget::inputPanelActiveChanged(bool active)
{
    qDebug() << "InputPanelView::inputPanelActiveChanged active : " << active;
    if(active)
    {
        setVisible(active);
        setMask(m_lastMask);
    }
    else
    {
        // hide();
        setVisible(active);
        setMask(QRegion(geometry()));
    }
}

void InputPanelWidget::init()
{
    setSource(QUrl("qrc:/virtualkeyboardarea.qml"));
    qDebug() << "InputPanelView::init geometry : " << geometry();
    QQuickItem *inputPanel = rootObject();

    inputPanel->setAcceptedMouseButtons(Qt::NoButton);
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(close()));
    connect(inputPanel, SIGNAL(inputPanelFocusChanged(bool)),this, SLOT(inputPanelActiveChanged(bool)));
    connect(inputPanel, SIGNAL(inputPanelGeometryChanged(int,int,int,int)),this, SLOT(inputPanelGeometryChanged(int,int,int,int)));
    inputPanelActiveChanged(false);
    setMask(geometry());
}
