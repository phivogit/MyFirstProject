/********************************************************************************
** Form generated from reading UI file 'autoclicker.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCLICKER_H
#define UI_AUTOCLICKER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoClicker
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *Header;
    QHBoxLayout *horizontalLayout;
    QRadioButton *mouseOption;
    QRadioButton *keyboardOption;
    QStackedWidget *stackedWidget;
    QWidget *MousePage;
    QGridLayout *gridLayout_5;
    QFrame *MouseFrame;
    QGridLayout *gridLayout_2;
    QPushButton *changeMouseInpButton;
    QLabel *mouseInpLabel;
    QLabel *speedLable;
    QPushButton *activateKeyButton;
    QPushButton *ButtonStop;
    QLabel *activateLabel;
    QLineEdit *InpClickSpeed;
    QPushButton *ButtonStart;
    QCheckBox *enableButton;
    QWidget *KeyboardPage;
    QGridLayout *gridLayout_3;
    QFrame *KeyboardFrame;
    QGridLayout *_2;
    QLineEdit *KInpClickSpeed;
    QPushButton *KactivateKeyButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *KButtonStart;
    QLabel *KactivateLabel_4;
    QPushButton *KButtonStop;
    QLabel *KspeedLable_4;
    QPushButton *KchangeInpButton;
    QLabel *KKey;
    QCheckBox *KenableButton;
    QMenuBar *menubar;
    QMenu *menuBucket_Auto_Clicker;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AutoClicker)
    {
        if (AutoClicker->objectName().isEmpty())
            AutoClicker->setObjectName("AutoClicker");
        AutoClicker->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AutoClicker->sizePolicy().hasHeightForWidth());
        AutoClicker->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        font.setBold(false);
        AutoClicker->setFont(font);
        AutoClicker->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        AutoClicker->setAnimated(false);
        AutoClicker->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(AutoClicker);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMinimumSize(QSize(800, 0));
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        Header = new QGroupBox(centralwidget);
        Header->setObjectName("Header");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Header->sizePolicy().hasHeightForWidth());
        Header->setSizePolicy(sizePolicy2);
        Header->setMinimumSize(QSize(361, 0));
        QFont font1;
        font1.setPointSize(13);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        Header->setFont(font1);
        Header->setAutoFillBackground(false);
        Header->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayout = new QHBoxLayout(Header);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        mouseOption = new QRadioButton(Header);
        mouseOption->setObjectName("mouseOption");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mouseOption->sizePolicy().hasHeightForWidth());
        mouseOption->setSizePolicy(sizePolicy3);
        mouseOption->setBaseSize(QSize(1, 3));
        QFont font2;
        font2.setPointSize(14);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        mouseOption->setFont(font2);
        mouseOption->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        mouseOption->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        mouseOption->setChecked(true);

        horizontalLayout->addWidget(mouseOption);

        keyboardOption = new QRadioButton(Header);
        keyboardOption->setObjectName("keyboardOption");
        sizePolicy3.setHeightForWidth(keyboardOption->sizePolicy().hasHeightForWidth());
        keyboardOption->setSizePolicy(sizePolicy3);
        keyboardOption->setFont(font2);
        keyboardOption->setChecked(false);

        horizontalLayout->addWidget(keyboardOption);


        gridLayout_4->addWidget(Header, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy4);
        stackedWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        MousePage = new QWidget();
        MousePage->setObjectName("MousePage");
        sizePolicy1.setHeightForWidth(MousePage->sizePolicy().hasHeightForWidth());
        MousePage->setSizePolicy(sizePolicy1);
        MousePage->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MousePage->setAutoFillBackground(false);
        gridLayout_5 = new QGridLayout(MousePage);
        gridLayout_5->setObjectName("gridLayout_5");
        MouseFrame = new QFrame(MousePage);
        MouseFrame->setObjectName("MouseFrame");
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(false);
        font3.setHintingPreference(QFont::PreferDefaultHinting);
        MouseFrame->setFont(font3);
        MouseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        MouseFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(MouseFrame);
        gridLayout_2->setObjectName("gridLayout_2");
        changeMouseInpButton = new QPushButton(MouseFrame);
        changeMouseInpButton->setObjectName("changeMouseInpButton");
        sizePolicy2.setHeightForWidth(changeMouseInpButton->sizePolicy().hasHeightForWidth());
        changeMouseInpButton->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setHintingPreference(QFont::PreferDefaultHinting);
        changeMouseInpButton->setFont(font4);

        gridLayout_2->addWidget(changeMouseInpButton, 0, 0, 1, 1);

        mouseInpLabel = new QLabel(MouseFrame);
        mouseInpLabel->setObjectName("mouseInpLabel");
        mouseInpLabel->setFont(font4);

        gridLayout_2->addWidget(mouseInpLabel, 0, 1, 1, 2);

        speedLable = new QLabel(MouseFrame);
        speedLable->setObjectName("speedLable");
        speedLable->setFont(font3);

        gridLayout_2->addWidget(speedLable, 1, 0, 1, 1);

        activateKeyButton = new QPushButton(MouseFrame);
        activateKeyButton->setObjectName("activateKeyButton");

        gridLayout_2->addWidget(activateKeyButton, 2, 1, 1, 1);

        ButtonStop = new QPushButton(MouseFrame);
        ButtonStop->setObjectName("ButtonStop");

        gridLayout_2->addWidget(ButtonStop, 3, 2, 1, 2);

        activateLabel = new QLabel(MouseFrame);
        activateLabel->setObjectName("activateLabel");

        gridLayout_2->addWidget(activateLabel, 2, 0, 1, 1);

        InpClickSpeed = new QLineEdit(MouseFrame);
        InpClickSpeed->setObjectName("InpClickSpeed");

        gridLayout_2->addWidget(InpClickSpeed, 1, 1, 1, 1);

        ButtonStart = new QPushButton(MouseFrame);
        ButtonStart->setObjectName("ButtonStart");

        gridLayout_2->addWidget(ButtonStart, 3, 0, 1, 2);

        enableButton = new QCheckBox(MouseFrame);
        enableButton->setObjectName("enableButton");
        enableButton->setChecked(true);

        gridLayout_2->addWidget(enableButton, 0, 3, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(2, 3);
        gridLayout_2->setColumnStretch(3, 3);

        gridLayout_5->addWidget(MouseFrame, 0, 0, 1, 1);

        stackedWidget->addWidget(MousePage);
        KeyboardPage = new QWidget();
        KeyboardPage->setObjectName("KeyboardPage");
        gridLayout_3 = new QGridLayout(KeyboardPage);
        gridLayout_3->setObjectName("gridLayout_3");
        KeyboardFrame = new QFrame(KeyboardPage);
        KeyboardFrame->setObjectName("KeyboardFrame");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(KeyboardFrame->sizePolicy().hasHeightForWidth());
        KeyboardFrame->setSizePolicy(sizePolicy5);
        KeyboardFrame->setFont(font3);
        KeyboardFrame->setFrameShape(QFrame::Shape::StyledPanel);
        KeyboardFrame->setFrameShadow(QFrame::Shadow::Raised);
        _2 = new QGridLayout(KeyboardFrame);
        _2->setObjectName("_2");
        _2->setHorizontalSpacing(10);
        KInpClickSpeed = new QLineEdit(KeyboardFrame);
        KInpClickSpeed->setObjectName("KInpClickSpeed");

        _2->addWidget(KInpClickSpeed, 2, 1, 1, 2);

        KactivateKeyButton = new QPushButton(KeyboardFrame);
        KactivateKeyButton->setObjectName("KactivateKeyButton");

        _2->addWidget(KactivateKeyButton, 3, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _2->addItem(horizontalSpacer, 3, 3, 1, 1);

        KButtonStart = new QPushButton(KeyboardFrame);
        KButtonStart->setObjectName("KButtonStart");

        _2->addWidget(KButtonStart, 4, 0, 1, 2);

        KactivateLabel_4 = new QLabel(KeyboardFrame);
        KactivateLabel_4->setObjectName("KactivateLabel_4");

        _2->addWidget(KactivateLabel_4, 3, 0, 1, 1);

        KButtonStop = new QPushButton(KeyboardFrame);
        KButtonStop->setObjectName("KButtonStop");

        _2->addWidget(KButtonStop, 4, 2, 1, 2);

        KspeedLable_4 = new QLabel(KeyboardFrame);
        KspeedLable_4->setObjectName("KspeedLable_4");
        KspeedLable_4->setFont(font3);

        _2->addWidget(KspeedLable_4, 2, 0, 1, 1);

        KchangeInpButton = new QPushButton(KeyboardFrame);
        KchangeInpButton->setObjectName("KchangeInpButton");
        KchangeInpButton->setFont(font4);

        _2->addWidget(KchangeInpButton, 1, 0, 1, 1);

        KKey = new QLabel(KeyboardFrame);
        KKey->setObjectName("KKey");
        KKey->setFont(font4);

        _2->addWidget(KKey, 1, 1, 1, 1);

        KenableButton = new QCheckBox(KeyboardFrame);
        KenableButton->setObjectName("KenableButton");
        KenableButton->setChecked(true);

        _2->addWidget(KenableButton, 1, 3, 1, 1);

        _2->setColumnStretch(0, 1);
        _2->setColumnStretch(1, 3);
        _2->setColumnStretch(2, 3);
        _2->setColumnStretch(3, 3);

        gridLayout_3->addWidget(KeyboardFrame, 0, 0, 1, 1);

        stackedWidget->addWidget(KeyboardPage);

        gridLayout_4->addWidget(stackedWidget, 1, 0, 1, 1);

        AutoClicker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AutoClicker);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 35));
        menuBucket_Auto_Clicker = new QMenu(menubar);
        menuBucket_Auto_Clicker->setObjectName("menuBucket_Auto_Clicker");
        AutoClicker->setMenuBar(menubar);
        statusbar = new QStatusBar(AutoClicker);
        statusbar->setObjectName("statusbar");
        AutoClicker->setStatusBar(statusbar);
        QWidget::setTabOrder(changeMouseInpButton, InpClickSpeed);
        QWidget::setTabOrder(InpClickSpeed, activateKeyButton);
        QWidget::setTabOrder(activateKeyButton, KactivateKeyButton);
        QWidget::setTabOrder(KactivateKeyButton, KInpClickSpeed);
        QWidget::setTabOrder(KInpClickSpeed, KButtonStart);
        QWidget::setTabOrder(KButtonStart, KButtonStop);

        menubar->addAction(menuBucket_Auto_Clicker->menuAction());

        retranslateUi(AutoClicker);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AutoClicker);
    } // setupUi

    void retranslateUi(QMainWindow *AutoClicker)
    {
        AutoClicker->setWindowTitle(QCoreApplication::translate("AutoClicker", "AutoClicker", nullptr));
        Header->setTitle(QCoreApplication::translate("AutoClicker", "Auto Clicker", nullptr));
        mouseOption->setText(QCoreApplication::translate("AutoClicker", "Mouse", nullptr));
        keyboardOption->setText(QCoreApplication::translate("AutoClicker", "Keyboard", nullptr));
        changeMouseInpButton->setText(QCoreApplication::translate("AutoClicker", "Change Mouse", nullptr));
        mouseInpLabel->setText(QCoreApplication::translate("AutoClicker", "Left Mouse Button", nullptr));
        speedLable->setText(QCoreApplication::translate("AutoClicker", "Speed (ms / click)", nullptr));
        activateKeyButton->setText(QCoreApplication::translate("AutoClicker", "F6", nullptr));
        ButtonStop->setText(QCoreApplication::translate("AutoClicker", "Stop", nullptr));
        activateLabel->setText(QCoreApplication::translate("AutoClicker", "Activate", nullptr));
        ButtonStart->setText(QCoreApplication::translate("AutoClicker", "Start", nullptr));
        enableButton->setText(QCoreApplication::translate("AutoClicker", "Enable", nullptr));
        KactivateKeyButton->setText(QCoreApplication::translate("AutoClicker", "F7", nullptr));
        KButtonStart->setText(QCoreApplication::translate("AutoClicker", "Start", nullptr));
        KactivateLabel_4->setText(QCoreApplication::translate("AutoClicker", "Activate", nullptr));
        KButtonStop->setText(QCoreApplication::translate("AutoClicker", "Stop", nullptr));
        KspeedLable_4->setText(QCoreApplication::translate("AutoClicker", "Speed (ms / click)", nullptr));
        KchangeInpButton->setText(QCoreApplication::translate("AutoClicker", "Change key", nullptr));
        KKey->setText(QCoreApplication::translate("AutoClicker", "A", nullptr));
        KenableButton->setText(QCoreApplication::translate("AutoClicker", "Enable", nullptr));
        menuBucket_Auto_Clicker->setTitle(QCoreApplication::translate("AutoClicker", "Bucket Auto Clicker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoClicker: public Ui_AutoClicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCLICKER_H
