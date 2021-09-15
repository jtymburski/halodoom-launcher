/**
 * @class AnimatedBackground
 *
 * Controls and renders a widget that is an animated background which will
 * both handle rotating backgrounds on a timer, shifting with a parallex and
 * custom overlays.
 */
#ifndef ANIMATEDBACKGROUND_H
#define ANIMATEDBACKGROUND_H

#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QWidget>

class AnimatedBackground : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  AnimatedBackground(QWidget *parent = nullptr);

private:
  /* Background images. Rendered first at the base, only one based on the index */
  QVector<QImage> backgrounds;
  int background_index = 0;

  /* Overlay images. All rendered in the order of the vector */
  QVector<QImage> overlays;

  /* Time between background switches, if multiple backgrounds are defined */
  const static int BACKGROUND_CYCLE_TIME_MS = 10000;

private slots:
  /* Rotate to the next background. Moves from First > Last > First .. */
  void cycleBackground();

protected:
  /* Paint override event for rendering the images */
  void paintEvent(QPaintEvent *event) override;

  /* Paint an image into the viewport and scale it to fit */
  void paintImage(QPainter &painter, const QImage &image);

public:
  /* Add a new background image, based on a provided path */
  void addBackground(QString path);

  /* Add a new overlay image, based on a provided path */
  void addOverlay(QString path);
};

#endif // ANIMATEDBACKGROUND_H
