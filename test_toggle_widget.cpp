#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  void initialStateIsOff();
  void clickTogglesOnThenOff();

};

// Implement the tests here

// The light should start off before anyone touches the button.
void TestToggleWidget::initialStateIsOff() {
  ToggleWidget w;

  QRadioButton *rb = w.findChild<QRadioButton *>();
  QVERIFY2(rb, "Could not find the radio button");

  QVERIFY(!w.isOn());
  QVERIFY(!rb->isChecked());
}

// Clicking the push button should flip the radio button each time: off -> on -> off.
void TestToggleWidget::clickTogglesOnThenOff() {
  ToggleWidget w;

  // The widget builds its children internally, so find them by type.
  QPushButton *pb = w.findChild<QPushButton *>();
  QRadioButton *rb = w.findChild<QRadioButton *>();
  QVERIFY2(pb, "Could not find the push button");
  QVERIFY2(rb, "Could not find the radio button");

  QVERIFY(!w.isOn());

  // First click: light turns on.
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
  QVERIFY(rb->isChecked());

  // Second click: light turns back off.
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(!w.isOn());
  QVERIFY(!rb->isChecked());

  // Third click: on again, to show it keeps toggling.
  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"