#include "maindialog.h"

MainDialog::MainDialog(QWidget *parent)
  : QDialog(parent)
{
  // Fix the window size
  setFixedSize(1024, 768);

  // Only the close button should be enabled
  setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
}

MainDialog::~MainDialog()
{
}

