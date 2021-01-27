#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QDial>
#include <QSpinBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLCDNumber>
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
QWidget *window = new QWidget;
window->setWindowTitle("Radio Control Center");

QLCDNumber *treblelcd = new QLCDNumber;
QLCDNumber *channellcd = new QLCDNumber;
QLCDNumber *lcd = new QLCDNumber;
QLCDNumber *basslcd = new QLCDNumber;


//QSpinBox *spinBox = new QSpinBox;
QSlider *slider = new QSlider(Qt::Vertical);
//QObject::connect(lcd, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
QObject::connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

//QSpinBox *bassBox = new QSpinBox;
//QSpinBox *trebleBox = new QSpinBox;
QDial *bassDialer = new QDial;
QDial *trebleControl = new QDial;
//QObject::connect(bassBox, SIGNAL(valueChanged(int)), bassDialer, SLOT(setValue(int)));
QObject::connect(bassDialer, SIGNAL(valueChanged(int)), basslcd, SLOT(display(int)));
//QObject::connect(trebleBox, SIGNAL(valueChanged(int)), trebleControl, SLOT(setValue(int)));
QObject::connect(trebleControl, SIGNAL(valueChanged(int)), treblelcd, SLOT(display(int)));

QLabel *bass_label = new QLabel;
bass_label->setText("Bass Control");
QLabel *treble_label = new QLabel;
treble_label->setText("Treble Control");
QLabel *channel_label = new QLabel;
channel_label->setText("Channel Control");
QLabel *volume_label = new QLabel;
volume_label->setText("Volume Control");

//QSpinBox *channelControl = new QSpinBox;
QDial *channelControlset = new QDial;

bassDialer->setNotchesVisible(true);
trebleControl->setNotchesVisible(true);
channelControlset->setNotchesVisible(true);

//QObject::connect(channelControl, SIGNAL(valueChanged(int)), channelControlset, SLOT(setValue(int)));
QObject::connect(channelControlset, SIGNAL(valueChanged(int)), channellcd, SLOT(display(int)));

QPushButton *turnOffButton = new QPushButton;
turnOffButton->setText("Close");
QObject::connect(turnOffButton, SIGNAL(clicked()),window, SLOT(close()));

QRadioButton *fmControl = new QRadioButton;
fmControl->setText("FM");

QRadioButton *amControl = new QRadioButton;
amControl->setText("AM");

bassDialer->setRange(0,100);
trebleControl->setRange(0,100);
//bassBox->setRange(0,100);
//trebleBox->setRange(0,100);
//lcd->setRange(0, 100);
slider->setRange(0, 100);
channelControlset->setRange(0,200);
//channelControl->setRange(0,200);
//lcd->setValue(50);

QHBoxLayout *layout = new QHBoxLayout;
QVBoxLayout *topRightLayout = new QVBoxLayout;
topRightLayout->addWidget(amControl);
topRightLayout->addWidget(fmControl);
topRightLayout->addWidget(bass_label);
topRightLayout->addWidget(basslcd);
topRightLayout->addWidget(bassDialer);
topRightLayout->addWidget(treble_label);
topRightLayout->addWidget(treblelcd);
topRightLayout->addWidget(trebleControl);
topRightLayout->addWidget(channel_label);
topRightLayout->addWidget(channellcd);
topRightLayout->addWidget(channelControlset);
topRightLayout->addWidget(turnOffButton);

QHBoxLayout *leftLayout = new QHBoxLayout;
leftLayout->addLayout(topRightLayout);
leftLayout->addWidget(lcd);
leftLayout->addWidget(slider);
}
