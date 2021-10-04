/**
 * @class TextView
 *
 * Extension on {@link QLabel} adding specific settings unique to launcher for consistent
 * styling and control.
 */
#include "ui/widget/textview.h"

/**
 * Constructor.
 * @param text label string to paint
 * @param color font color
 * @param font_size size in pixels
 * @param padding width is top and bottom, height is left and right, in pixels
 * @param parent owning widget
 */
TextView::TextView(const QString &text, const QColor &color, int font_size, const QSize &padding,
                   QWidget *parent) : QLabel(text, parent)
{
  setStyleSheet(
        "QLabel {"
          "color:" + color.name() + ";"
          "font-family:bahnschrift;"
          "font-size:" + QString::number(font_size) + "px;"
          "padding:" + QString::number(padding.height()) + "px "
                     + QString::number(padding.width()) + "px;"
          "QFont::bold"
        "}");
}
