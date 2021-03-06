#include "editlabel.h"

#include <QHBoxLayout>
#include <QFontMetrics>
#include <QDebug>

#include "utils/global.h"

const QSize LINEEDIT_SIZE = QSize(28, 22);

EditLabel::EditLabel(QWidget *parent)
    : QLabel(parent)
    , m_titleSpacing(4)
{
    DRAW_THEME_INIT_WIDGET("EditLabel");
    m_titleLabel = new QLabel(this);
    m_titleLabel->setObjectName("EditLabel");
    m_edit = new QLineEdit(this);
    m_edit->setFixedSize(LINEEDIT_SIZE);
    m_edit->setObjectName("TitleEdit");
    QHBoxLayout* mLayout = new QHBoxLayout(this);
    mLayout->setMargin(0);
    mLayout->setSpacing(0);
    mLayout->addWidget(m_titleLabel);
    mLayout->addSpacing(m_titleSpacing);
    mLayout->addWidget(m_edit);
    mLayout->addStretch();

    connect(m_edit, &QLineEdit::editingFinished, this, [=]{
        emit editTextChanged(m_edit->text());
    });

    setLayout(mLayout);
}

void EditLabel::setTitle(QString title)
{
    m_titleLabel->setText(title);
    QFont font = m_titleLabel->font();
    QFontMetrics fm(font);
    m_titleLabel->setFixedWidth(fm.boundingRect(m_titleLabel->text()).width());
}

void EditLabel::setEditText(QString text)
{
    m_edit->setText(text);
}

void EditLabel::setEditWidth(int width)
{
    m_edit->setFixedWidth(width);
    this->updateGeometry();
}

void EditLabel::setTitleSpacing(int spacing)
{
    m_titleSpacing = spacing;
    this->updateGeometry();
}

QString EditLabel::editText()
{
    return m_edit->text();
}

EditLabel::~EditLabel() {}
