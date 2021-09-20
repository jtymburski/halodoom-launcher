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
public:
  /* Constructor, with just text and the parent */
  MenuButton(const QString &text, int font_size, QWidget *parent = nullptr);
};

#endif // MENUBUTTON_H
