#ifndef PROGRESSBOX_H
#define PROGRESSBOX_H

#include "progressline.h"
#include <QTimer>
#include <QVariantAnimation>

struct Bled{
    QPointF pos;
};

class ProgressBox : public ProgressLine
{
    Q_OBJECT
public:
    explicit ProgressBox(QWidget *parent = 0);
    void initConnections();

signals:
    void finished(const bool& successful);

public slots:
    void updateAnimation();
    void taskTimeOut();
    void startTask();
    void finishedTask(const bool result);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QTimer* m_taskTimer;
    QTimer* m_updateTimer;
    QList<Bled> m_bleds;
    QVariantAnimation* m_taskAni;
};

#endif // PROGRESSBOX_H