#include "DemoApp.h"
#include "Connect.h"

namespace demo {

void DemoApp::start() {
  auto const url = QUrl{QStringLiteral("qrc:/QbsHello/main.qml")};
  demo::connect<&QQmlApplicationEngine::objectCreated>(&m_engine, Qt::QueuedConnection)
      .ctx(this)
      .to([url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      });
  m_engine.load(url);
}

} // namespace demo
