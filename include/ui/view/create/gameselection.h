/**
 * @class GameSelection
 *
 * Single selection properties for a rendered game option.
 */
#ifndef GAMESELECTION_H
#define GAMESELECTION_H

#include <QString>

class GameSelection
{
public:
  class Builder;

private:
  /* Private blank constructor, use {@link Builder} */
  GameSelection() = default;

  /* Description string, can be multiple sentences */
  QString description;

  /* Assigned image path matching the selection */
  QString image_path;

  /* Name of the selection, should be relatively short */
  QString name;

  /* Type identifier */
  int type = -1;

public:
  /* Returns the selection description */
  QString getDescription() const;

  /* Returns the selection image */
  QString getImagePath() const;

  /* Returns the selection name */
  QString getName() const;

  /* Returns the type identifier, meant to encapsulate a weakly-typed enumerator */
  int getType() const;

  /* Builder nested class for constructing the selection immutable object */
  class Builder
  {
  private:
    QString description;
    QString image_path;
    QString name;
    int type;

  public:
    GameSelection build();
    Builder* setDescription(QString description);
    Builder* setImagePath(QString image_path);
    Builder* setName(QString name);
    Builder* setType(int type);
  };
};

#endif // GAMESELECTION_H
