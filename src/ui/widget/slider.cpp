/**
 * @class Slider
 *
 * Extension on {@link QSlider} adding specific settings unique to launcher for consistent
 * styling and control.
 */
#include "ui/widget/slider.h"

/**
 * Constructor.
 * @param value starting point for the slider
 * @param minValue minimum (left) end of the slider
 * @param maxValue maximum (right) end of the slider
 * @param parent owning widget
 */
Slider::Slider(int value, int minValue, int maxValue, int height, QWidget *parent)
      : QSlider(Qt::Horizontal, parent)
{
  setMinimum(minValue);
  setMaximum(maxValue);
  setSliderPosition(value);
  setTracking(true);

  setStyleSheet(
        "QSlider {"
          "height:"
              +QString::number(height) + "px;"
          "margin:10px 0px"
        "}"
        "QSlider::handle:horizontal {"
          "background-color:rgba(255, 255, 255, 255);"
          "width:20"
        "}"
        "QSlider::groove:horizontal {"
          "background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, "
                                           "stop:0 rgba(104,196,255,10),"
                                           "stop:1 rgba(104,196,255,50))"
        "}"
        "QSlider::sub-page:horizontal {"
          "background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, "
                                           "stop:0 rgba(104,196,255,10),"
                                           "stop:1 rgba(104,196,255,180))"
        "}");
}
