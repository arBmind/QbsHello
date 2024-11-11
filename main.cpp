#include "DemoApp.h"

int main(int argc, char *argv[]) {
  auto app = demo::DemoApp{argc, argv};
  app.start();
  return app.exec();
}
