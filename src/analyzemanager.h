// SPDX-License-Identifier: PolyForm-Noncommercial-1.0.0
// Copyright (c) 2026 Andrei Kozhevnikov <coderusinbox@gmail.com>

#pragma once

#include <QObject>
#include <QPoint>

class AnalyzeManager : public QObject
{
    Q_OBJECT
public:
    explicit AnalyzeManager(QObject *parent = nullptr);

    void analyzeDataAdded(const QString &location);

    Q_INVOKABLE void load();
    Q_INVOKABLE void remove(const QString &location);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void refine(const QString &location, const QString &id);

signals:
    void dataAdded(const QVariantMap &point);
};
