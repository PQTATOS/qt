# game

Short description of my Aurora OS Application

The source code of the project is provided under
[the license](LICENSE.BSD-3-CLAUSE.md),
that allows it to be used in third-party applications.

## Project Structure

The project has a common structure
of an application based on C++ and QML for Aurora OS.

* **[ru.auroraos.vamp_clone.pro](ru.auroraos.vamp_clone.pro)** file
  describes the project structure for the qmake build system.
* **[icons](icons)** directory contains application icons for different screen resolutions.
* **[qml](qml)** directory contains the QML source code and the UI resources.
  * **[cover](qml/cover)** directory contains the application cover implementations.
  * **[icons](qml/icons)** directory contains the custom UI icons.
  * **[pages](qml/pages)** directory contains the application pages.
  * **[vamp_clone.qml](qml/vamp_clone.qml)** file
    provides the application window implementation.
* **[rpm](rpm)** directory contains the rpm-package build settings.
  **[ru.auroraos.vamp_clone.spec](rpm/ru.auroraos.vamp_clone.spec)** file is used by rpmbuild tool.
  It is generated from **[ru.auroraos.vamp_clone.yaml](rpm/ru.auroraos.vamp_clone.yaml)** file.
* **[src](src)** directory contains the C++ source code.
  * **[main.cpp](src/main.cpp)** file is the application entry point.
* **[translations](translations)** directory contains the UI translation files.
* **[ru.auroraos.vamp_clone.desktop](ru.auroraos.vamp_clone.desktop)** file
  defines the display and parameters for launching the application.