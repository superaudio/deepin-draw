#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QPainter>
#include <QMouseEvent>

class TextEdit : public QPlainTextEdit {
    Q_OBJECT

public:
    TextEdit(int index, QWidget* parent);
    ~TextEdit();

    const QColor getTextColor();
    int fontSize();

public slots:
    void setColor(QColor c);
    int getIndex();
    void updateCursor();
    void setCursorVisible(bool visible);
    void keepReadOnlyStatus();
    void setFontSize(int fontsize);
    void updateContentSize(QString content);
    void setFontsizeRation(qreal ration);
    void movePos(QPointF movePos);

signals:
    void repaintTextRect(TextEdit* edit,  QRectF newPositiRect);
    void backToEditing();
    void textEditSelected(int index);
    void showMenuInTextEdit();
    void hoveredOnTextEdit(int index);

protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);
    void inputMethodEvent(QInputMethodEvent* e);
    void keyPressEvent(QKeyEvent* e);
    void enterEvent(QEnterEvent* e);

private:
    int m_index;
    int m_fontSize;
    QColor m_textColor;
    QPainter* m_painter;

    QPointF m_pressPoint;
    QPointF m_startPos;
    bool m_isPressed;
    qreal m_fontsizeRation;
};

#endif // TEXTEDIT_H
