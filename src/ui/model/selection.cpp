/**
 * @class Selection
 *
 * Single selection properties for a rendered game option.
 */
#include "ui/model/selection.h"

/**
 * Returns the selection description. It can be multiple sentences.
 * @return description
 */
QString Selection::getDescription() const
{
  return description;
}

/**
 * Returns the selection image. It is the assigned image data to render.
 * @return image
 */
QString Selection::getImagePath() const
{
  return image_path;
}

/**
 * Returns the selection name. It should be relatively short.
 * @return name
 */
QString Selection::getName() const
{
  return name;
}

/**
 * Returns the type identifier, meant to encapsulate a weakly-typed enumerator.
 * @return type
 */
int Selection::getType() const
{
  return type;
}


/**
 * Returns the loadout identifier, meant to encapsulate a weakly-typed enumerator.
 * @return loadout
 */
int Selection::getLoadOut() const
{
    return loadout;
}

/**
 * Build the {@link GameSelection} object from the configured builder.
 * @return built object
 */
Selection Selection::Builder::build()
{
  Selection game_selection;

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
Selection::Builder* Selection::Builder::setDescription(QString description)
{
  this->description = description;
  return this;
}

/**
 * Sets the selection image. It is the assigned image data to render.
 * @param image_path path of a valid image available
 * @return reference to the builder, for chaining
 */
Selection::Builder* Selection::Builder::setImagePath(QString image_path)
{
  this->image_path = image_path;
  return this;
}

/**
 * Sets the selection name. It should be relatively short.
 * @param name string
 * @return reference to the builder, for chaining
 */
Selection::Builder* Selection::Builder::setName(QString name)
{
  this->name = name;
  return this;
}


/**
 * Sets the selection type. This should be a unique identifier.
 * @param type weakly-typed enumerator
 * @return reference to the builder, for chaining
 */
Selection::Builder* Selection::Builder::setType(int type)
{
  this->type = type;
  return this;
}


/**
 * Sets the selection loadout. This should be a unique identifier.
 * @param loadout weakly-typed enumerator
 * @return reference to the builder, for chaining
 */
Selection::Builder* Selection::Builder::setLoadout(int loadout)
{
  this->loadout = loadout;
  return this;
}
