/**
 * @class ImageButton
 *
 * Extension on {@link QPushButton} to add background image and hover image visual elements.
 */
#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>

class ImageButton : public QPushButton
{
public:
  /* Constructor, with just text, image paths, and the parent */
  ImageButton(const QString &text, const QString &background_image_path,
              const QString &hover_image_path, QWidget *parent = nullptr);
};

#endif // IMAGEBUTTON_H
