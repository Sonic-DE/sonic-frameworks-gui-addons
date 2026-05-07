/*
    SPDX-FileCopyrightText: 2020 David Edmundson <davidedmundson@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ksystemclipboard.h"
#include "kguiaddons_debug.h"

#include "qtclipboard_p.h"

#include <QDebug>
#include <QGuiApplication>
#include <QMimeData>

KSystemClipboard *KSystemClipboard::instance()
{
    if (!qGuiApp || qGuiApp->closingDown()) {
        return nullptr;
    }
    static KSystemClipboard *systemClipboard = nullptr;

    if (!systemClipboard) {
        systemClipboard = new QtClipboard(qApp);
    }

    return systemClipboard;
}

QString KSystemClipboard::text(QClipboard::Mode mode)
{
    const QMimeData *data = mimeData(mode);
    if (data) {
        return data->text();
    }
    return QString();
}

KSystemClipboard::KSystemClipboard(QObject *parent)
    : QObject(parent)
{
}

#include "moc_ksystemclipboard.cpp"
