/**
 * @class ImageButton
 *
 * Extension on {@link QPushButton} to add background image and hover image visual elements.
 */
#include "ui/widget/imagebutton.h"

/**
 * Constructor, with just text, image paths, and the parent.
 * @param text string inside the button. It will replace spaces with new line character
 * @param background_image_path render image when the user is not interacting with the button
 * @param hover_image_path render image when the user is hovering over the button
 * @param parent top level owning widget, for garbage collection
 */
ImageButton::ImageButton(const QString &text, const QString &background_image_path,
                         const QString &hover_image_path, QWidget *parent)
           : QPushButton(QString(text).replace(' ', '\n'), parent)
{
  setFlat(true);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setStyleSheet(
        "QPushButton {"
          "border:0;"
          "border-image:url(" + background_image_path + ") 0 0 0 0 stretch stretch;"
          "color:white;"
          "font-family:bahnschrift;"
          "font-size:50px"
        "}"
        "QPushButton:hover {"
          "border-image:url(" + hover_image_path + ") 0 0 0 0 stretch stretch"
        "}");
}
