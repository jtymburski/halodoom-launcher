/**
 * @class TextView
 *
 * Extension on {@link QLabel} adding specific settings unique to launcher for consistent
 * styling and control.
 */
#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include <QLabel>

class TextView : public QLabel
{
  Q_OBJECT

public:
  /* Constructor */
  TextView(const QString &text, const QColor &color, int font_size, const QSize &padding,
           QWidget *parent = nullptr);
};

#endif // TEXTVIEW_H
