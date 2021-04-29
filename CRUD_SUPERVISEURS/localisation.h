#ifndef LOCALISATION_H
#define LOCALISATION
#include <QtPositioning/qgeopositioninfosource.h>
QT_BEGIN_NAMESPACE
#include <QFile>
#include <QTimer>
QT_END_NAMESPACE


class localisation : public QGeoPositionInfoSource
{
    Q_OBJECT
public:
    localisation(QObject *parent = 0);

    QGeoPositionInfo lastKnownPosition(bool fromSatellitePositioningMethodsOnly = false) const;

    PositioningMethods supportedPositioningMethods() const;
    int minimumUpdateInterval() const;
    Error error() const;

public slots:
    virtual void startUpdates();
    virtual void stopUpdates();

    virtual void requestUpdate(int timeout = 5000);

private slots:
    void readNextPosition();

private:
    QFile *logFile;
    QTimer *timer;
    QGeoPositionInfo lastPosition;
};

#endif // LOCALISATION_H
