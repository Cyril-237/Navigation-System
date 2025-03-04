#include "actionwindow.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>


ActionWindow::ActionWindow(const QString &title, QWidget *parent) : QWidget(parent)
{
    setWindowTitle(title);
    resize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel(title, this);
    titleLabel->setAlignment(Qt::AlignCenter);

    closeButton = new QPushButton("Fermer", this);

    layout->addWidget(titleLabel);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);
}

ActionWindow::~ActionWindow()
{

}

QPushButton *ActionWindow::getCloseButton() const
{
    return closeButton;
}
