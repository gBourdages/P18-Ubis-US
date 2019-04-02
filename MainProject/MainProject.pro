TEMPLATE     = vcapp
TARGET       = MainProject
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     +=
SOURCES     += MainProject.cpp
INCLUDEPATH += CommunicationFPGA
LIBS	      += CommunicationFPGA/CommunicationFPGA.lib
QT += widgets