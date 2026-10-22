// SPDX-License-Identifier: PolyForm-Noncommercial-1.0.0
// Copyright (c) 2026 Andrei Kozhevnikov <coderusinbox@gmail.com>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "socketconnector.h"
#include "mytreemodel2.h"

int main(int argc, char *argv[])
{
    qputenv("QT_QUICK_CONTROLS_STYLE", "Fusion");

    QGuiApplication app(argc, argv);
    app.setApplicationName("qt-qaengine-inspector");
    app.setOrganizationName("qt-qaengine");
    app.setOrganizationDomain("qtqaengine.dev");

    QScopedPointer<SocketConnector> connector(new SocketConnector);
    connector->setProperty("applicationName", "inspector");
    qmlRegisterUncreatableType<AnalyzeManager>("qtqaengine.inspector", 1, 0, "AnalyzeManager", "AnalyzeManager");
    qmlRegisterSingletonInstance("qtqaengine.inspector", 1, 0, "SocketConnector", connector.get());

    qmlRegisterType<MyTreeModel2>("qtqaengine.inspector", 1, 0, "TreeModel");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qtqaengine.inspector", "Main");

    return app.exec();
}
