/**
 * @class PageHeader
 *
 * Controls and renders a widget for the header information on the generic page with a
 * title, back button, and any other shared functionality.
 */
#include "ui/widget/pageheader.h"

/**
 * Constructor with required options.
 * @param main_title center large text string to print at top of view
 * @param back_name button title for the back button in the top left
 * @param parent top level owning widget, for garbage collection
 */
PageHeader::PageHeader(QString main_title, QString back_name, QWidget *parent) : QWidget(parent)
{
  QGridLayout* layout = new QGridLayout(this);
  layout->setColumnStretch(1, 1);

  QLabel* label_title = new QLabel(main_title.toUpper(), this);
  label_title->setAlignment(Qt::AlignCenter);
  label_title->setStyleSheet(
        "QLabel {"
          "color:#68c4ff;"
          "font-family:bahnschrift;"
          "font-size:100px;"
          "QFont::bold"
        "}");
  layout->addWidget(label_title, 0, 0, 1, 3);

  MenuButton* button_back = new MenuButton("← " + back_name, 30, this);
  connect(button_back, SIGNAL(clicked()), this, SIGNAL(selectBackButton()));
  layout->addWidget(button_back, 0, 0);
}
