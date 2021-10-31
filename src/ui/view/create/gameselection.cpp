/**
 * @class GameSelection
 *
 * Single selection properties for a rendered game option.
 */
#include "ui/view/create/gameselection.h"

/**
 * Returns the selection description. It can be multiple sentences.
 * @return description
 */
QString GameSelection::getDescription() const
{
  return description;
}

/**
 * Returns the selection image. It is the assigned image data to render.
 * @return image
 */
QString GameSelection::getImagePath() const
{
  return image_path;
}

/**
 * Returns the selection name. It should be relatively short.
 * @return name
 */
QString GameSelection::getName() const
{
  return name;
}

/**
 * Returns the type identifier, meant to encapsulate a weakly-typed enumerator.
 * @return type
 */
int GameSelection::getType() const
{
  return type;
}

/**
 * Build the {@link GameSelection} object from the configured builder.
 * @return built object
 */
GameSelection GameSelection::Builder::build()
{
  GameSelection game_selection;

  game_selection.description = this->description;
  game_selection.image_path = this->image_path;
  game_selection.name = this->name;
  game_selection.type = this->type;

  return game_selection;
}

/**
 * Sets the selection description. It can be multiple sentences.
 * @param description string
 * @return reference to the builder, for chaining
 */
GameSelection::Builder* GameSelection::Builder::setDescription(QString description)
{
  this->description = description;
  return this;
}

/**
 * Sets the selection image. It is the assigned image data to render.
 * @param image_path path of a valid image available
 * @return reference to the builder, for chaining
 */
GameSelection::Builder* GameSelection::Builder::setImagePath(QString image_path)
{
  this->image_path = image_path;
  return this;
}

/**
 * Sets the selection name. It should be relatively short.
 * @param name string
 * @return reference to the builder, for chaining
 */
GameSelection::Builder* GameSelection::Builder::setName(QString name)
{
  this->name = name;
  return this;
}

/**
 * Sets the selection type. This should be a unique identifier.
 * @param type weakly-typed enumerator
 * @return reference to the builder, for chaining
 */
GameSelection::Builder* GameSelection::Builder::setType(int type)
{
  this->type = type;
  return this;
}
