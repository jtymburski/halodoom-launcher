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
 * @param font_size pixel (px) size of the button text font
 * @param parent top level owning widget, for garbage collection
 */
MenuButton::MenuButton(const QString &text, int font_size, QWidget *parent)
          : QPushButton(text, parent)
{
  this->font_size = font_size;

  setFlat(true);
  updateStyleSheet();
}

/**
 * Update the button stylesheet with the class configuration.
 */
void MenuButton::updateStyleSheet()
{
  setStyleSheet(
        "QPushButton {"
          + (background_filled
             ? QString("background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                        "stop:.60 rgba(104,195,254,128),"
                                                        "stop:1 transparent);")
             : QString("")) +
          "border:0;"
          "color:white;"
          "font-family:bahnschrift;"
          "font-size:" + QString::number(font_size-2) + "px;"
          "padding:0px 20px;"
          "text-align:left"
        "}"
        "QPushButton:hover {"
          "background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                           "stop:.30 rgb(104,195,254), stop:1 transparent)"
        "}"
        "QPushButton:pressed {"
          "background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                           "stop:.60 rgb(104,195,254), stop:1 transparent)"
        "}");
}

/**
 * Enter event state triggered by the QEvent system.
 * @param event triggering context
 */
void MenuButton::enterEvent(QEvent *event)
{
  emit hovered();
  QWidget::enterEvent(event);
}

/**
 * Sets if the background should be filled even when not hovered or pressed.
 * @param filled TRUE for the background to be filled. FALSE for fully transparent
 */
void MenuButton::setBackgroundFilled(bool filled)
{
  this->background_filled = filled;
  updateStyleSheet();
}
