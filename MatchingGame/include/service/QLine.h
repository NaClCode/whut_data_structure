#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <vector>

class GameLine : public QWidget {
    Q_OBJECT
public:
    GameLine(QWidget* parent = nullptr) : QWidget(parent) {
        connect(&timer, &QTimer::timeout, this, &GameLine::onTimeout);
    }

    void drawLineBetweenPoints(const std::vector<QPoint>& points) {
        this->points = points;
        shouldDrawLines = true;
        this->update(); // 触发重绘
        timer.start(1000); // 1秒后触发onTimeout
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QWidget::paintEvent(event);
        if (shouldDrawLines && !points.empty()) {
            QPainter painter(this);
            painter.setPen(Qt::black); // 设置线条颜色
            for (int i = 1; i < points.size(); i++) {
                painter.drawLine(points[i-1], points[i]);
            }
        }
    }

private slots:
    void onTimeout() {
        shouldDrawLines = false;
        timer.stop();
        this->update(); // 再次更新绘图区域以清除线条
    }

private:
    QTimer timer;
    std::vector<QPoint> points;
    bool shouldDrawLines = false;
};
#ifndef QLINE_H
#define QLINE_H

#endif // QLINE_H
