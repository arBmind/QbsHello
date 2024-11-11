Project {
    AutotestRunner {}
    Product {
        name: "[Extras]"
        files: [
            ".buildbot.yml",
            ".clang-format",
            "README.md",
        ]
    }
    StaticLibrary {
        name: "DemoLib"

        cpp.cxxLanguageVersion: "c++20"

        files: [
            "Connect.h",
            "DemoApp.cpp",
            "DemoApp.h",
        ]

        Depends { name: "Qt.core" }
        Depends { name: "Qt.quick" }
        Export {
            Depends { name: "Qt.core" }
            Depends { name: "Qt.quick" }
        }
    }

    CppApplication {
        name: "QbsHello"
        install: true
        files: [
            "main.cpp",
        ]

        Depends { name: "DemoLib" }
        Group {
            Qt.core.resourcePrefix: "QbsHello/"

            files: ["main.qml"]
            fileTags: ["qt.qml.qml", "qt.core.resource_data"]
        }
    }

    CppApplication {
        name: "DemoTest"
        type: ["application", "autotest"]
        files: [
            "test.main.cpp",
        ]

        Depends { name: "DemoLib" }
    }
}
