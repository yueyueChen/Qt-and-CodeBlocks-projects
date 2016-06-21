#ifndef FUNCTIONTEST_H
#define FUNCTIONTEST_H

#include <QtWidgets>
#include <QAbstractVideoFilter>

class MyFilterRunable : public QVideoFilterRunnable
{
public:
    QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);
};

class MyFilter : public QAbstractVideoFilter
{
    Q_OBJECT
public:
    QVideoFilterRunnable *createFilterRunnable()
    {
        return new MyFilterRunable;
    }

signals:
    void finished(QObject *result);
};

#endif // FUNCTIONTEST_H
