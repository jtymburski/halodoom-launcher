/**
 * @class PageHeader
 *
 * Controls and renders a widget for the header information on the generic page with a
 * title, back button, and any other shared functionality.
 */
#ifndef PAGEHEADER_H
#define PAGEHEADER_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "ui/widget/menubutton.h"

class PageHeader : public QWidget
{
  Q_OBJECT

public:
  /* Constructor with required options */
  PageHeader(QString main_title, QString back_name, QWidget *parent = nullptr);

signals:
  /* Back button selected in view */
  void selectBackButton();
};

#endif // PAGEHEADER_H
