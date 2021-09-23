/**
 * @class AnimatedBackground
 *
 * Controls and renders a widget that is an animated background which will
 * both handle rotating backgrounds on a timer, shifting with a parallex and
 * custom overlays.
 */
#include "ui/widget/animatedbackground.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
AnimatedBackground::AnimatedBackground(QWidget *parent) : QWidget(parent)
{
  // By default, dither is always added as the base overlay, painted above the backgrounds
  overlays.append(QImage(":/image/background/dither.png"));

  // Background cycle timer
  QTimer *background_timer = new QTimer(this);
  connect(background_timer, SIGNAL(timeout()), this, SLOT(cycleBackground()));
  background_timer->start(BACKGROUND_CYCLE_TIME_MS);
}

/**
 * Rotate to the next background. Moves through the set of backgrounds from first to last before
 * looping back to the first image.
 */
void AnimatedBackground::cycleBackground()
{
  background_index++;
  if(background_index >= backgrounds.size())
    background_index = 0;
  update();
}

/**
 * Paint override event for rendering the images or any other custom widgets.
 */
void AnimatedBackground::paintEvent(QPaintEvent*)
{
  QPainter painter(this);

  if(backgrounds.size() > 0)
    paintImage(painter, backgrounds.at(background_index));

  QVectorIterator<QImage> overlay_iterator(overlays);
  while (overlay_iterator.hasNext())
    paintImage(painter, overlay_iterator.next());
}

/**
 * Paint an image into the viewport and scale it to fit.
 * @param painter paint controller
 * @param image info on the image to paint in the viewport
 */
void AnimatedBackground::paintImage(QPainter &painter, const QImage &image)
{
  painter.setWindow(image.rect());
  painter.drawImage(0, 0, image);
}

/* ---- PUBLIC FUNCTIONS ---- */

/**
 * Add a new background image, based on a provided path.
 * @param path resource or absolute path to an image file
 */
void AnimatedBackground::addBackground(QString path)
{
  QImage image(path);
  if(image.isNull())
    throw std::invalid_argument("Path=" + path.toStdString()
                                + " for background image is not found");
  backgrounds.append(image);
}

/**
 * Add a new overlay image, based on a provided path.
 * @param path resource or absolute path to an image file
 */
void AnimatedBackground::addOverlay(QString path)
{
  QImage image(path);
  if(image.isNull())
    throw std::invalid_argument("Path=" + path.toStdString()
                                + " for overlay image is not found");
  overlays.append(image);
}
