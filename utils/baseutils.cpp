#include "baseutils.h"

#include <QPixmap>
#include <QProcess>
#include <QLayoutItem>
#include <QFile>
#include <QDebug>
#include <QImageReader>
#include <QCryptographicHash>
#include <QtMath>
#include <QApplication>
#include <QDesktopWidget>

#include "utils/configsettings.h"

QSize      initArtboardSize(QPoint pos)
{
    int artboardActualWidth = 0, artboardActualHeight = 0;
    QSize desktopSize = DScreenWindowsUtil::instance(pos
                                                     )->primaryScreen()->size();
    qDebug() << "init artboardSize:" << pos<<  desktopSize;
    artboardActualWidth = desktopSize.width();
    artboardActualHeight = desktopSize.height();

    return QSize(artboardActualWidth, artboardActualHeight);
}

QSize      getArtboardSize(QPoint pos)
{
    int artboardActualWidth = ConfigSettings::instance()->value("artboard", "width").toInt();
    int artboardActualHeight = ConfigSettings::instance()->value("artboard", "height").toInt();
    qDebug() << "origin artboardSize:" << artboardActualWidth << artboardActualHeight;

    if (artboardActualWidth == 0 || artboardActualHeight == 0)
    {
        QSize desktopSize = DScreenWindowsUtil::instance(pos
                                                         )->primaryScreen()->size();
        qDebug() << "init artboardSize:" << pos<<  desktopSize;

        artboardActualWidth = desktopSize.width();
        artboardActualHeight = desktopSize.height();
    }
    return QSize(artboardActualWidth, artboardActualHeight);
}

QSize      getCanvasSize(QSize artboardSize, QSize windowSize)
{
    qreal winWidth = qreal(windowSize.width()),
             winHeight = qreal(windowSize.height());
    qreal widthRation = qreal(artboardSize.width())/qreal(windowSize.width());
    qreal heightRation = qreal(artboardSize.height())/qreal(windowSize.height());
    qDebug() << "GetCanvasSize:" << widthRation << heightRation;

    if (widthRation > heightRation)
    {
        winHeight = qreal(artboardSize.height())/widthRation;
    } else {
        winWidth = qreal(artboardSize.width())/heightRation;
    }

    return QSize(int(winWidth), int(winHeight));
}

QCursor setCursorShape(QString cursorName)
{
    QCursor customShape = QCursor();
    if (cursorName == "rotate") {
        customShape = QCursor(QPixmap(
                      ":/theme/light/images/mouse_style/shape/rotate_mouse.png"), 5, 5);
    } else if (cursorName == "rectangle") {
        qDebug() << "rectangle ...";
        customShape = QCursor(QPixmap(
                      ":/theme/light/images/mouse_style/shape/mouse_rectangle.svg"), 7, 17);
    } else if (cursorName == "oval") {
        customShape = QCursor(QPixmap(
                      ":/theme/light/images/mouse_style/shape/mouse_oval.svg"), 7, 17);
    } else if (cursorName == "arrow") {
        customShape = QCursor(QPixmap(
                      ":/theme/light/images/mouse_style/shape/arrow_mouse.png"), 5, 5);
    } else if (cursorName == "text") {
        customShape = QCursor(QPixmap(
                      ":/theme/light/images/mouse_style/shape/text_mouse.png"), 5, 5);
    } else if (cursorName == "straightLine") {
        customShape = QCursor(QPixmap(QString(
                    ":/theme/light/images/mouse_style/shape/line_mouse.png")), 2, 9);
    } else if (cursorName == "arbitraryCurve") {
        customShape = QCursor(QPixmap(
                    ":/theme/light/images/mouse_style/shape/pen_mouse.png"), 4, 13);
    } else if (cursorName == "pickcolor") {
        customShape = QCursor(QPixmap(
                     ":/theme/light/images/mouse_style/shape/pen_mouse.png"), 2, 9);
    } else if (cursorName == "bottomleft" || cursorName == "bottomright"
               || cursorName == "topleft" || cursorName == "topright") {
        customShape = QCursor(QPixmap(
        QString(":/theme/light/images/mouse_style/shape/%1_mouse.svg").arg(cursorName)));
    }

    return customShape;
}

int stringWidth(const QFont &f, const QString &str)
{
    QFontMetrics fm(f);
    return fm.boundingRect(str).width();
}

QString getFileContent(const QString &file)
{
    QFile f(file);
    QString fileContent = "";
    if (f.open(QFile::ReadOnly))
    {
        fileContent = QLatin1String(f.readAll());
        f.close();
    }
    return fileContent;
}

QList<QColor> specifiedColorList()
{
    QList<QColor> colorList;
    colorList
    << QColor(Qt::transparent)  << QColor("#ff0c0c") << QColor("#fe3c3b")
    << QColor("#fd6867") << QColor("#fd9694") << QColor("#fcc4c1")
    << QColor("#f8e0d6") << QColor("#e4c299") << QColor("#f2aa46")
    << QColor("#fd9d0f") << QColor("#f6b443") << QColor("#eecb77")
    << QColor("#f0ee4e") << QColor("#f4fb00") << QColor("#f6f96d")
    << QColor("#f4f6a6") << QColor("#f3f3d6") << QColor("#e9eedc")
    << QColor("#dde8cb") << QColor("#ccdfb0") << QColor("#9cd972")
    << QColor("#4ec918") << QColor("#5cc850") << QColor("#6bc989")
    << QColor("#53ac6d") << QColor("#72b88e") << QColor("#7cc8cd")
    << QColor("#97d1d4") << QColor("#c9e1e1") << QColor("#c1dee7")
    << QColor("#93ceed") << QColor("#76c3f1") << QColor("#49b2f6")
    << QColor("#119fff") << QColor("#0192ea") << QColor("#3d7ddd")
    << QColor("#92cdfb") << QColor("#99cffa") << QColor("#ececf8")
    << QColor("#ccc9f9") << QColor("#b2acf9") << QColor("#958ef9")
    << QColor("#7c6ffa") << QColor("#8a47fb") << QColor("#6b1aef")
    << QColor("#952dfd") << QColor("#af39e4") << QColor("#c174da")
    << QColor("#c587d9") << QColor("#dbb4c1") << QColor("#cf8c86")
    << QColor("#b45f51") << QColor("#865e4f") << QColor("#694d48")
    << QColor("#ffffff") << QColor("#d4d4d4") << QColor("#919191")
    << QColor("#626262") << QColor("#404040") << QColor("#000000");
    return colorList;
}

QColor colorIndexOf(int index)
{
    QList<QColor> colorList = specifiedColorList();

    if (index < colorList.length())
        return colorList[index];

    return colorList[0];
}

int colorIndex(QColor color)
{
    QList<QColor> colorList = specifiedColorList();
    if (colorList.contains(color))
        return colorList.indexOf(color);

    return 0;
}

bool          isValidFormat(QString suffix)
{
    QStringList validFormat;
    validFormat << "bmp" << "jpg" << "jpeg" << "png" << "pbm"
                         << "pgm" << "xbm" << "xpm";
    if (validFormat.contains(suffix)) {
        return true;
    } else {
        return false;
    }
}

bool          isCommandExist(QString command)
{
    QProcess* proc = new QProcess;
    QString cm = QString("which %1\n").arg(command);
    proc->start(cm);
    proc->waitForFinished(1000);

    if (proc->exitCode() == 0) {
        return true;
    } else {
        return false;
    }
}

void   paintSelectedPoint(QPainter &painter, QPointF pos, QPixmap pointImg)
{
    painter.drawPixmap(pos, pointImg);
}

QVariantList cachePixmap(const QString &path)
{
    QImage tImg;

    QString format = DetectImageFormat(path);
    if (format.isEmpty()) {
        QImageReader reader(path);
        reader.setAutoTransform(true);
        if (reader.canRead()) {
            tImg = reader.read();
        }
    } else {
        QImageReader readerF(path, format.toLatin1());
        readerF.setAutoTransform(true);
        if (readerF.canRead()) {
            tImg = readerF.read();
        }
    }

    QPixmap p = QPixmap::fromImage(tImg);
    QVariantList vl;
    vl << QVariant(path) << QVariant(p);
    return vl;
}

// For more information about image file extension, see:
// https://en.wikipedia.org/wiki/Image_file_formats
QString DetectImageFormat(const QString &filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "DetectImageFormat() failed to open file:" << filepath;
        return "";
    }

    const QByteArray data = file.read(1024);

    // Check bmp file.
    if (data.startsWith("BM")) {
        return "bmp";
    }

    // Check dds file.
    if (data.startsWith("DDS")) {
        return "dds";
    }

    // Check gif file.
    if (data.startsWith("GIF8")) {
        return "gif";
    }

    // Check Max OS icons file.
    if (data.startsWith("icns")) {
        return "icns";
    }

    // Check jpeg file.
    if (data.startsWith("\xff\xd8")) {
        return "jpg";
    }

    // Check mng file.
    if (data.startsWith("\x8a\x4d\x4e\x47\x0d\x0a\x1a\x0a")) {
        return "mng";
    }

    // Check net pbm file (BitMap).
    if (data.startsWith("P1") || data.startsWith("P4")) {
        return "pbm";
    }

    // Check pgm file (GrayMap).
    if (data.startsWith("P2") || data.startsWith("P5")) {
        return "pgm";
    }

    // Check ppm file (PixMap).
    if (data.startsWith("P3") || data.startsWith("P6")) {
        return "ppm";
    }

    // Check png file.
    if (data.startsWith("\x89PNG\x0d\x0a\x1a\x0a")) {
        return "png";
    }

    // Check svg file.
    if (data.indexOf("<svg") > -1) {
        return "svg";
    }

    // TODO(xushaohua): tga file is not supported yet.

    // Check tiff file.
    if (data.startsWith("MM\x00\x2a") || data.startsWith("II\x2a\x00")) {
        // big-endian, little-endian.
        return "tiff";
    }

    // TODO(xushaohua): Support wbmp file.

    // Check webp file.
    if (data.startsWith("RIFFr\x00\x00\x00WEBPVP")) {
        return "webp";
    }

    // Check xbm file.
    if (data.indexOf("#define max_width ") > -1 &&
        data.indexOf("#define max_height ") > -1) {
        return "xbm";
    }

    // Check xpm file.
    if (data.startsWith("/* XPM */")) {
        return "xpm";
    }

    return "";
}

QString allImageformat()
{
    return QString("Files(*.bmp *.bmp24 *.ico *.jpg *.jpe *.jpeg *.jpeg24 *.jng *.pcd"
                   "*.pcx *.png *.tga *.tif *.tiff *.tiff24 *.psd *.xpm *.dds *.gif *.sgi *.j2k "
                   "*jp2 *.pct *.webp *.wdp *.cr2 *.pef *.arw *.nef *.icb *.dng *.vda "
                   "*.vst *.raf *.orf *.svg *.ptif *.mef *.mrw *.xbm);;");
}

QString createHash(const QString &str)
{
    return QString(QCryptographicHash::hash(str.toUtf8(),
                             QCryptographicHash::Md5).toHex());
}

QString sizeToHuman(const qlonglong bytes)
{
    qlonglong sb = 1024;
    if (bytes < sb) {
        return QString::number(bytes) + " B";
    }
    else if (bytes < sb * sb) {
        QString vs = QString::number((double)bytes / sb, 'f', 1);
        if (qCeil(vs.toDouble()) == qFloor(vs.toDouble())) {
            return QString::number((int)vs.toDouble()) + " KB";
        }
        else {
            return vs + " KB";
        }
    }
    else if (bytes < sb * sb * sb) {
        QString vs = QString::number((double)bytes / sb / sb, 'f', 1);
        if (qCeil(vs.toDouble()) == qFloor(vs.toDouble())) {
            return QString::number((int)vs.toDouble()) + " MB";
        }
        else {
            return vs + " MB";
        }
    }
    else {
        return QString::number(bytes);
    }
}

QCursor blurToolCursor(const int &lineWidth)
{
    QPixmap cursorPix = QPixmap(QSize(lineWidth + 2, lineWidth + 2));
    cursorPix.fill(QColor(Qt::transparent));
    QPen borderPen;
    borderPen.setWidth(3);
    borderPen.setColor(QColor(0, 0, 0, 26));
    QPainter painter(&cursorPix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setBrush(QBrush());
    painter.setPen(borderPen);
    painter.drawEllipse(cursorPix.rect().center(), lineWidth/2 - 1, lineWidth/2 - 1);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(Qt::white));
    painter.setPen(pen);
    painter.drawEllipse(cursorPix.rect().center(), lineWidth/2 - 1, lineWidth/2 - 1);

    return QCursor(cursorPix, -1, -1);
}

QCursor pickColorCursor()
{
    int tipWidth = 11;
    QPixmap cursorPix = QPixmap(QSize(tipWidth, tipWidth));
    cursorPix.fill(QColor(Qt::transparent));

    QPen whitePen;
    whitePen.setWidth(1);
    whitePen.setCapStyle(Qt::FlatCap);
    whitePen.setJoinStyle(Qt::RoundJoin);
    whitePen.setColor(QColor(255, 255, 255, 255));

    QPen blackPen;
    blackPen.setWidth(1);
    blackPen.setCapStyle(Qt::FlatCap);
    blackPen.setJoinStyle(Qt::RoundJoin);
    blackPen.setColor(QColor(0, 0, 0, 125));

    QPainter painter(&cursorPix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(blackPen);
    painter.drawEllipse(cursorPix.rect().center(), tipWidth/2 - 1, tipWidth/2 - 1);
    painter.drawEllipse(cursorPix.rect().center(), tipWidth/2 - 3, tipWidth/2 - 3);
    painter.setPen(whitePen);
    painter.drawEllipse(cursorPix.rect().center(), tipWidth/2 - 2, tipWidth/2 -2);

    return QCursor(cursorPix, -1, -1);
}

QString getStringFromShape(Toolshape shape)
{
    QJsonObject copyShapeObj;
    copyShapeObj.insert("type", shape.type);
    copyShapeObj.insert("index", shape.index);

    QJsonArray mainPoints;
    for(int k = 0; k < shape.mainPoints.length(); k++)
    {
        mainPoints.append(QJsonValue(double(shape.mainPoints[k].x())));
        mainPoints.append(QJsonValue(double(shape.mainPoints[k].y())));
    }
    copyShapeObj.insert("mainPoints", QJsonValue(mainPoints));
    copyShapeObj.insert("lineWidth", shape.lineWidth);
    copyShapeObj.insert("fillColor", shape.fillColor.name());
    copyShapeObj.insert("strokeColor", shape.strokeColor.name());
    copyShapeObj.insert("isBlur", shape.isBlur);
    copyShapeObj.insert("isMosaic", shape.isMosaic);
    copyShapeObj.insert("isStraight", shape.isStraight);
    copyShapeObj.insert("isHorFlip", shape.isHorFlip);
    copyShapeObj.insert("isVerFlip", shape.isVerFlip);
    copyShapeObj.insert("imagePath", shape.imagePath);
    copyShapeObj.insert("text", shape.text);
    copyShapeObj.insert("rotate", shape.rotate);
    copyShapeObj.insert("scaledRation", shape.scaledRation);
    QJsonArray size;
    for(int k = 0; k < 2; k++)
    {
        size.append(QJsonValue(shape.imageSize.width()));
        size.append(QJsonValue(shape.imageSize.height()));
    }
    copyShapeObj.insert("imageSize", QJsonValue(size));
    copyShapeObj.insert("fontSize", shape.fontSize);

    QJsonArray points;
    for(int k = 0; k < shape.points.length(); k++)
    {
        points.append(QJsonValue(double(shape.points[k].x())));
        points.append(QJsonValue(double(shape.points[k].y())));
    }
    copyShapeObj.insert("points", QJsonValue(points));
    QJsonArray portion;
    for(int k = 0; k < shape.portion.length(); k++)
    {
        portion.append(QJsonValue(double(shape.portion[k].x())));
        portion.append(QJsonValue(double(shape.portion[k].y())));
    }
    copyShapeObj.insert("portion", QJsonValue(portion));
    return QString(QJsonDocument(copyShapeObj).toJson());
}

Toolshape getShapeInfoFromJsonStr(QString jsonStr)
{
    Toolshape resultShape = Toolshape();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toLocal8Bit().data());
    if( jsonDoc.isNull() ){
        qDebug() << "jsonDoc isEmpty...";
        return  resultShape;
    } else {
        qDebug() << "jsonDoc is valid!";
    }

    QJsonObject jsonObj = jsonDoc.object();
    resultShape.type = jsonObj.value("type").toString();
    resultShape.index = jsonObj.value("index").toInt();
    QVariantList mainPoints = jsonObj.value("mainPoints").toArray().toVariantList();
    for(int j = 0; j < mainPoints.length(); j+=2)
    {
        resultShape.mainPoints[j/2] = QPointF(mainPoints[j].toReal(), mainPoints[j+1].toReal());
    }

    resultShape.lineWidth = jsonObj.value("lineWidth").toInt();
    resultShape.fillColor =  QColor(jsonObj.value("fillColor").toString());
    resultShape.strokeColor = QColor(jsonObj.value("strokeColor").toString());
    resultShape.isBlur = jsonObj.value("isBlur").toBool();
    resultShape.isMosaic = jsonObj.value("isMosaic").toBool();
    resultShape.isHorFlip = jsonObj.value("isHorFlip").toBool();
    resultShape.isVerFlip = jsonObj.value("isVerFlip").toBool();
    resultShape.imagePath = jsonObj.value("imagePath").toString();
    resultShape.text = jsonObj.value("text").toString();
    resultShape.rotate = jsonObj.value("rotate").toVariant().toReal();
    resultShape.scaledRation = jsonObj.value("scaledRation").toVariant().toReal();
    QVariantList sizeList = jsonObj.value("imageSize").toArray().toVariantList();
    if (sizeList.length() >= 2)
    {
        resultShape.imageSize = QSize(sizeList[0].toInt(), sizeList[1].toInt());
    }
    qDebug() << "ImageSize...........:" << resultShape.imageSize;
    resultShape.fontSize = jsonObj.value("fontSize").toVariant().toReal();

    QVariantList points = jsonObj.value("points").toArray().toVariantList();
    for(int j = 0; j < points.length(); j+=2)
    {
        resultShape.points.append(QPointF(points[j].toReal(), points[j+1].toReal()));
    }

    QVariantList portion = jsonObj.value("portion").toArray().toVariantList();
    for(int j = 0; j < portion.length(); j++)
    {
        resultShape.portion.append(QPointF(portion[j].toReal(), portion[j+1].toReal()));
    }
    return resultShape;
}
