#ifndef INPUTPANELWIDGET_H
#define INPUTPANELWIDGET_H

#include <QQuickWidget>

class InputPanelWidget : public QQuickWidget
{
    Q_OBJECT
private:
    QRegion m_lastMask;
    QWidget* m_parent;
public:
    explicit InputPanelWidget(QWidget *parent = Q_NULLPTR);
    ~InputPanelWidget();
protected:
    bool event(QEvent *) Q_DECL_OVERRIDE;
signals:

public slots:
    void inputPanelGeometryChanged(int,int,int,int);
    void inputPanelActiveChanged(bool);
    void init();
};



#endif // INPUTPANELWIDGET_H
