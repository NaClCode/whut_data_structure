#include "../../include/service/QPressLabel.h"
void PressLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        pressed();
    }
    emit clickedWithCoordinates(x, y, value);
    QLabel::mousePressEvent(event);
}
