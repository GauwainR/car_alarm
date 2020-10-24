import qbs

CppApplication {
    consoleApplication: true
    files: [
        "sources/checkauthirizationcode.cpp",
        "include/checkauthirizationcode.h",
        "sources/checkpincode.cpp",
        "include/checkpincode.h",
        "sources/vehiclenotice.cpp",
        "include/vehiclenotice.h",
        "sources/controller.cpp",
        "include/controller.h",
        "sources/doorssensors.cpp",
        "include/doorssensors.h",
        "sources/sensors.cpp",
        "include/sensors.h",
        "main.cpp",
        "sources/worrymode.cpp",
        "include/worrymode.h",
        "sources/unitcontrol.cpp",
        "include/unitcontrol.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
