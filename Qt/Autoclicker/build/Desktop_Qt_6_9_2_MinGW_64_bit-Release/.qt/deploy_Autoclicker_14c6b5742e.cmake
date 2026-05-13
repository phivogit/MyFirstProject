include("D:/Hi/CD/MyFirstProject/Qt/Autoclicker/build/Desktop_Qt_6_9_2_MinGW_64_bit-Release/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Autoclicker-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/Hi/CD/MyFirstProject/Qt/Autoclicker/build/Desktop_Qt_6_9_2_MinGW_64_bit-Release/Autoclicker.exe"
    GENERATE_QT_CONF
)
