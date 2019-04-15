#ifndef BUTTON_H
#define BUTTON_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>

class Button
	: public QObject
	, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Button(const QString& normal,
		const QString& hovered,
		const QSize& size,
		const QPointF& pos);
	virtual ~Button() override;

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

signals:
	void clicked();

private:
	QPixmap m_normal;
	QPixmap m_hovered;
};

#endif // BUTTON_H