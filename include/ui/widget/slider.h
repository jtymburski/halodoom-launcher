/**
 * @class Slider
 *
 * Extension on {@link QSlider} adding specific settings unique to launcher for consistent
 * styling and control.
 */
#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

class Slider : public QSlider
{
  Q_OBJECT

public:
  /* Constructor */
  Slider(int value, int minValue, int maxValue, int height = 50, QWidget *parent = nullptr);
};

#endif // SLIDER_H
