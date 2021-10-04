/**
 * @class MenuButton
 *
 * Extension on {@link QPushButton} adding specific settings unique to the menu for
 * formatting and control.
 */
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>

class MenuButton : public QPushButton
{
  Q_OBJECT

public:
  /* Constructor, with just text and the parent */
  MenuButton(const QString &text, int font_size, QWidget *parent = nullptr);

private:
  /* Background filled even when the button is not hovered or pressed */
  bool background_filled = false;

  /* Font size of the text in the button */
  int font_size = 16;

signals:
  /* Fires when the button starts being hovered within its bounding box */
  void hovered();

private:
  /* Update the button stylesheet with the class configuration */
  void updateStyleSheet();

protected:
  /* Enter event state triggered */
  virtual void enterEvent(QEvent *event);

public:
  /* Sets if the background should be filled even when not hovered or pressed */
  void setBackgroundFilled(bool filled);
};

#endif // MENUBUTTON_H
