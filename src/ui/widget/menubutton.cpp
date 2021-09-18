/**
 * @class MenuButton
 *
 * Extension on {@link QPushButton} adding specific settings unique to the menu for
 * formatting and control.
 */
#include "ui/widget/menubutton.h"

/**
 * Constructor, with just text and the parent.
 * @param text string inside the button
 * @param parent top level owning widget, for garbage collection
 */
MenuButton::MenuButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
  setFlat(true);
  setStyleSheet(
        "QPushButton {"
          "border:0;"
          "color:white;"
          "font-family:bahnschrift;"
          "font-size:50px;"
          "padding:10px 25px;"
          "text-align:left"
        "}"
        "QPushButton:hover {"
          "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                            "stop:.30 #68c3fe, stop:1 transparent)"
        "}"
        "QPushButton:pressed {"
          "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                            "stop:.60 #68c3fe, stop:1 transparent)"
        "}");
}
