import qbs

CppApplication {
    consoleApplication: true
    files: [
        "sources/sensors.cpp",
        "include/sensors.h",
        "sources/doorssensors.cpp",
        "include/doorssensors.h",
        "sources/controller.cpp",
        "include/controller.h",
        "sources/controlunit.cpp",
        "include/controlunit.h",
        "main.cpp",
        "sources/worrymode.cpp",
        "include/worrymode.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
