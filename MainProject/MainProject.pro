TEMPLATE     = vcapp
TARGET       = MainProject
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += MenuWindow.h
SOURCES     += MainProject.cpp MenuWindow.cpp
INCLUDEPATH += CommunicationFPGA
LIBS	      += CommunicationFPGA/CommunicationFPGA.lib
QT += widgets