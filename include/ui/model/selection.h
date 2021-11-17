/**
 * @class Selection
 *
 * Single selection properties for a rendered game option.
 */
#ifndef SELECTION_H
#define SELECTION_H

#include <QString>

class Selection
{
public:
  class Builder;

private:
  /* Private blank constructor, use {@link Builder} */
  Selection() = default;

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
    Selection build();
    Builder* setDescription(QString description);
    Builder* setImagePath(QString image_path);
    Builder* setName(QString name);
    Builder* setType(int type);
  };
};

#endif // SELECTION_H
