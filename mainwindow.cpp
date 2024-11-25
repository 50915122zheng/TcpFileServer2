#include "mainwindow.h"
#include "tcpfilesender.h"
#include "tcpfileserver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    tabWidget(new QTabWidget(this)),
    fileSender(new TcpFileSender(this)),
    fileServer(new TcpFileServer(this))
{

    // 設定樣式表
    setStyleSheet(R"(
        QMainWindow {
            background-color: #f0f0f0;
        }
        QTabWidget::pane {
            border: 1px solid #cccccc;
            background: #ffffff;
        }
        QTabBar::tab {
            background: #e0e0e0;
            padding: 10px;
            border: 1px solid #aaaaaa;
            border-radius: 5px;
        }
        QTabBar::tab:selected {
            background: #ffffff;
            border-bottom: 2px solid #0078d7;
        }
        QPushButton {
            background-color: #0078d7;
            color: #ffffff;
            border: none;
            padding: 8px 15px;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #005bb5;
        }
        QLabel {
            font-size: 14px;
            color: #333333;
        }
        QProgressBar {
            text-align: center;
            color: #ffffff;
            border: 1px solid #cccccc;
            border-radius: 5px;
            background: #e0e0e0;
        }
        QProgressBar::chunk {
            background-color: #0078d7;
            border-radius: 5px;
        }
        QLineEdit {
            border: 1px solid #aaaaaa;
            border-radius: 5px;
            padding: 5px;
        }
    )");

    // 將子功能整合到標籤頁中
    tabWidget->addTab(fileSender, tr("TcpFileSender"));
    tabWidget->addTab(fileServer, tr("TCPFileServer"));
    tabWidget->setStyleSheet("QTabWidget { margin: 10px; }");
    tabWidget->setTabPosition(QTabWidget::North);
    tabWidget->setDocumentMode(true);
    tabWidget->setTabShape(QTabWidget::Rounded);

    // 設定主窗口的中心元件為標籤頁
    setCentralWidget(tabWidget);

    //固定窗口
    setFixedSize(500, 400);

    // 設定主窗口標題與大小
    setWindowTitle(tr("檔案傳輸系統"));
    resize(500, 400);
}

MainWindow::~MainWindow() {
    // 清理指標物件
    delete fileSender;
    delete fileServer;
    delete tabWidget;
}
