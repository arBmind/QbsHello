#pragma once
#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace demo {

class DemoApp : public QGuiApplication {
  Q_OBJECT

public:
  DemoApp(int &argc, char **argv, int flags = ApplicationFlags)
      : QGuiApplication{argc, argv, flags} {
    // TODO
  }

  void start();

private:
  QQmlApplicationEngine m_engine;
};

} // namespace demo
