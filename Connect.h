#pragma once
#include <QObject>

namespace demo {

template <auto method, class From, class Target> struct ConnectTo {
  From *from{};
  Target *target{};
  Qt::ConnectionType connectionType{};

  auto to(auto &&func) -> QMetaObject::Connection {
    return QObject::connect(from, method, target, func, connectionType);
  }
};

template <auto method, class From> struct Connect {
  From *from{};
  Qt::ConnectionType connectionType{};

  template <class Target> auto ctx(Target *target) {
    return ConnectTo<method, From, Target>{from, target, connectionType};
  }
  auto to(auto &&func) -> QMetaObject::Connection { return QObject::connect(from, method, func, connectionType); }
};

template <auto method, class From>
auto connect(From *from, Qt::ConnectionType connectionType = Qt::AutoConnection) -> Connect<method, From> {
  return Connect<method, From>{from, connectionType};
}

} // namespace demo
