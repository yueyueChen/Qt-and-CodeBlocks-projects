#include "transactionthread.h"
#include <QtWidgets>

Transaction * const EndTransaction = 0;

TransactionThread::TransactionThread()
{
    start();
}
TransactionThread::~TransactionThread()
{
    {
        QMutexLocker locker(&mutex);
        while(!transactions.isEmpty())
            delete transactions.dequeue();
        transactions.enqueue(EndTransaction);
        transactionAdded.wakeOne();
    }
    wait();
}
void TransactionThread::addTransaction(Transaction *transact)
{
    QMutexLocker locker(&mutex);
    transactions.enqueue(transact);
    transactionAdded.wakeOne();
}
void TransactionThread::run()
{
    Transaction *transact = 0 ;
    QImage oldImage;

    forever
    {
        {
            QMutexLocker locker(&mutex);
            if(transactions.isEmpty())
                transactionAdded.wait(&mutex);
            transact = transactions.dequeue();
            if(transact == EndTransaction)
                break;
            oldImage = currentImage;
        }
        emit transactionStarted(transact->message());
        QImage newImage = transact->apply(oldImage);
        delete transact;
        {
            QMutexLocker locker(&mutex);
            currentImage = newImage;
            if(transactions.isEmpty())
                emit allTransactionsDone();
        }
    }
}
void TransactionThread::setImage(const QImage &image)
{
    QMutexLocker locker(&mutex);
    currentImage = image;
}
QImage TransactionThread::image()
{
    QMutexLocker locker(&mutex);
    return currentImage;
}

FlipTransaction::FlipTransaction(Qt::Orientation orientation)
{
    this->orientation = orientation;
}
QImage FlipTransaction::apply(const QImage &image)
{
    return image.mirrored(orientation==Qt::Horizontal,orientation==Qt::Vertical);
}
QString FlipTransaction::message()
{
    if(orientation==Qt::Horizontal)
        return QObject::tr("flipping image horizonally...");
    else
        return QObject::tr("flipping image vertically...");
}
ResizeTransaction::ResizeTransaction(const QSize &size)
{
    this->size = size;
}
QImage ResizeTransaction::apply(const QImage &image)
{
    return image.scaled(size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
}
QString ResizeTransaction::message()
{
    return QObject::tr("resize image...");
}
ConvertDepthTransaction::ConvertDepthTransaction(int depth)
{
    this->depth = depth;
}

QImage ConvertDepthTransaction::apply(const QImage &image)
{
    QImage::Format format;

    switch (depth) {
    case 1:
        format = QImage::Format_Mono;
        break;
    case 8:
        format = QImage::Format_Indexed8;
        break;
    case 24:
    default:
        format = QImage::Format_RGB32;
    }

    return image.convertToFormat(format);
}

QString ConvertDepthTransaction::message()
{
    return QObject::tr("Converting image depth...");
}

























