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

signals:
  /* Fires when the button starts being hovered within its bounding box */
  void hovered();

protected:
  /* Enter event state triggered */
  virtual void enterEvent(QEvent *event);
};

#endif // MENUBUTTON_H
