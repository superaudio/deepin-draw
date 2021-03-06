#ifndef CALCULATERECT_H
#define CALCULATERECT_H

#include <QPointF>
#include <QtMath>
#include "shapesutils.h"

///* get a rect by diagPoints */
//QRect   diagPointsRect(DiagPoints diagPoints);

/* judge whether the point1 is on the point2 or not */
bool    pointClickIn(QPointF point2, QPointF point1, int padding = 4);

/* judge whether the point3 is on the segment*/
bool    pointOnLine(QPointF point1, QPointF point2, QPointF point3);

/* get the distance between two points*/
qreal getDistance(QPointF point1, QPointF point2);

/* get the point who splid a distance on a line */
QPointF  pointSplid(QPointF point1, QPointF point2, qreal padding);

/* get the rotate point by four points in a rectangle*/
QPointF  getRotatePoint(QPointF point1, QPointF point2,
                             QPointF point3, QPointF point4);
/* init FourPoints*/
FourPoints initFourPoints(FourPoints fourPoints);
FourPoints mainPointsOrder(FourPoints fourPoints);
/* get the four points from a rectangle which isn't rotated!*/
//FourPoints  fourPointsOnRect(DiagPoints diagPoints);

/* get the four points from a line */
FourPoints fourPointsOfLine(QList<QPointF> points);

/* get the rotate angle by three points*/
qreal  calculateAngle(QPointF point1, QPointF point2, QPointF point3);

/* get the new points after rotate with angle*/
QPointF  pointRotate(QPointF point1, QPointF point2, qreal angle);

/* the distance from a point(point3) to a line(point1, point2) */
qreal   pointToLineDistance(QPointF point1, QPointF point2, QPointF point3);

/* judge the direction of point3 of line(point1, point2) */
qreal pointLineDir(QPointF point1, QPointF point2, QPointF point3);

/*get another four points in rectangle (Top/Bottom/Left/Right) */
FourPoints getAnotherFPoints(FourPoints mainPoints);

/* calculate the control point of the beizer */
QPointF getControlPoint(QPointF point1, QPointF point2, bool direction) ;

/* get eight control points */
QList<QPointF> getEightControlPoint(FourPoints rectFPoints);

/* judge whether the clickOnPoint is on the bezier */
/* 0 <= pos.x() <= 1*/
bool pointOnBezier(QPointF point1, QPointF point2, QPointF point3,
                   QPointF point4, QPointF pos);

/* judge whether the clickOnPoint is on the ellipse */
bool pointOnEllipse(FourPoints rectFPoints, QPointF pos);

/* judge whether the clickOnPoint is in the ellipse*/

/* get the three points of arrow A/B/D */
QList<QPointF> pointOfArrow(QPointF startPoint, QPointF endPoint, qreal arrowLength);

/* judge whether the pos is on the points*/
bool pointOnArLine(QList<QPointF> points, QPointF pos, int padding = 4);

/* resize arbitrary curved, QPointF is ration */
QPointF relativePosition(FourPoints mainPoints, QPointF pos);
QPointF           getNewPosition(FourPoints mainPoints, QPointF re);

//bool pointInEllipse(QPointF point1, QPointF point2, QPointF point3, QPointF point4, QPointF pos);
/* handle resize of eight points in rectangle */
FourPoints resizePointPosition(QPointF point1, QPointF point2, QPointF point3, QPointF point4,
                          QPointF pos, int key, const QString &ration = "free", bool isShift = false);
FourPoints resizePointPositionByAlt(QPointF point1, QPointF point2, QPointF point3, QPointF point4,
                          QPointF pos, int key, const QString &rationName = "free", bool isShift = false);

FourPoints resizeByAltNoTiltKeepRation(FourPoints mainPoints, QPointF centerPos, const QString &rationName = "free");

/***************** first point1 *******************/
/* point1 in the first position */
FourPoints point1Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point1Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the second position*/
FourPoints point1Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point1Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the third position */
FourPoints point1Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point1Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the fourth position */
FourPoints point1Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point1Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point1 in the fifth position */
FourPoints point1Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift = false);
FourPoints point1Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift = false);
/* point1 in the sixth position */
FourPoints point1Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point1Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point1 in the seventh position */
FourPoints point1Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point1Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point1 in the eighth position */
FourPoints point1Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point1Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/***************** second point2 *******************/
/* point2 in the first position */
FourPoints point2Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point2Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the second position */
FourPoints point2Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point2Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the third position */
FourPoints point2Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point2Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the fourth position */
FourPoints point2Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point2Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point2 in the fifth position */
FourPoints point2Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift = false);
FourPoints point2Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point2 in the sixth position */
FourPoints point2Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point2Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point2 in the seventh position */
FourPoints point2Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point2Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point2 in the eighth position */
FourPoints point2Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point2Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/***************** third point3 *******************/
/* point3 in the first position */
FourPoints point3Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point3Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the second position */
FourPoints point3Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point3Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the third position */
FourPoints point3Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point3Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the fourth position */
FourPoints point3Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point3Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point3 in the fifth position */
FourPoints point3Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point3Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point3 in the sixth position */
FourPoints point3Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point3Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point3 in the seventh position */
FourPoints point3Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point3Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point3 in the eighth position */
FourPoints point3Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point3Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/***************** fourth point4 *******************/
/* point4 in the first position */
FourPoints point4Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point4Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the second position */
FourPoints point4Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point4Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the third position */
FourPoints point4Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point4Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the fourth position */
FourPoints point4Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point4Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point4 in the fifth position */
FourPoints point4Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point4Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point4 in the sixth position */
FourPoints point4Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point4Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point4 in the seventh position */
FourPoints point4Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point4Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point4 in the eighth position */
FourPoints point4Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point4Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/********************** fifth point5 ************************/
/* point5 in the first position */
FourPoints point5Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point5Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the second position */
FourPoints point5Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point5Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the third position */
FourPoints point5Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point5Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the fourth position */
FourPoints point5Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point5Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point5 in the fifth position */
FourPoints point5Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point5Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point5 in the sixth position */
FourPoints point5Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point5Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point5 in the seventh position */
FourPoints point5Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point5Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point5 in the eighth position */
FourPoints point5Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point5Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/********************** sixth point6 ************************/
/* point6 in the first position */
FourPoints point6Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point6Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the second position */
FourPoints point6Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point6Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the third position */
FourPoints point6Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point6Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the fourth position */
FourPoints point6Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point6Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point6 in the fifth position */
FourPoints point6Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point6Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point6 in the sixth position */
FourPoints point6Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point6Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point6 in the seventh position */
FourPoints point6Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point6Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point6 in the eighth position */
FourPoints point6Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point6Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/********************** seventh point7 ************************/
/* point7 in the first position */
FourPoints point7Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point7Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the second position */
FourPoints point7Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point7Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the third position */
FourPoints point7Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point7Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the fourth position */
FourPoints point7Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point7Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point7 in the fifth position */
FourPoints point7Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point7Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point7 in the sixth position */
FourPoints point7Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point7Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point7 in the seventh position */
FourPoints point7Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point7Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point7 in the eighth position */
FourPoints point7Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point7Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/********************** eighth point8 ************************/
/* point8 in the first position */
FourPoints point8Resize1(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point8Resize1ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the second position */
FourPoints point8Resize2(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point8Resize2ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the third position */
FourPoints point8Resize3(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point8Resize3ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the fourth position */
FourPoints point8Resize4(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
FourPoints point8Resize4ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift = false);
/* point8 in the fifth position */
FourPoints point8Resize5(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
FourPoints point8Resize5ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, const QString &rationName = "", bool isShift= false);
/* point8 in the sixth position */
FourPoints point8Resize6(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point8Resize6ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point8 in the seventh position */
FourPoints point8Resize7(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point8Resize7ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/* point8 in the eighth position */
FourPoints point8Resize8(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
FourPoints point8Resize8ByAlt(QPointF point1, QPointF point2, QPointF point3,
                         QPointF point4, QPointF pos, bool isShift= false);
/************************ micro-adjust  **************************/
FourPoints pointMoveMicro(FourPoints fourPoints,  QString dir);
FourPoints pointResizeMicro(FourPoints fourPoints, QString dir, bool isBig);
FourPoints point5ResizeMicro(FourPoints fourPoints, bool isBig);
FourPoints point6ResizeMicro(FourPoints fourPoints,  bool isBig);
FourPoints point7ResizeMicro(FourPoints fourPoints,  bool isBig);
FourPoints point8ResizeMicro(FourPoints fourPoints,  bool isBig);

/***********************  special process   ***************************/
bool pointInRect(FourPoints fourPoints, QPointF pos);
FourPoints getMainPoints(QPointF point1, QPointF point2, bool isShift = false);
FourPoints getRationFPoints(QPointF point1, QPointF point2, QString ration);
FourPoints getMainPointsByAlt(QPointF centerPos, QPointF pos, bool isShift = false);

/**************** divie the rectangle into nine parts ********************/
QList<QPointF> trisectionPoints(FourPoints fourPoints);
/****************  jude a point on rectangle ****************************/
bool pointOnRect(QRect rect, QPoint pos);

/********** The cut image has a proportional initialization point *******/
FourPoints getInitFourPointByCut(FourPoints mainPoints, const QString &rationName);

/*************************  Zoom point  ***********************/
FourPoints zoomPoints(FourPoints mainPoints, qreal zoomFactor);
QList<QPointF> zoomPointList(QList<QPointF> points, qreal zoomFactor);
#endif // CALCULATERECT_H
