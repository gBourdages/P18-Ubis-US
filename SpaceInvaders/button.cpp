#include "button.h"

Button::Button(const QString& ressourcePath,
	const QString& hoveredPath,
	const QSize& size,
	const QPointF& pos)
{
	m_normal.load(ressourcePath);
	m_hovered.load(hoveredPath);

	m_normal = m_normal.scaled(size);
	m_hovered = m_hovered.scaled(size);

	setPixmap(m_normal);
	setPos(pos);

	setAcceptedMouseButtons(Qt::LeftButton);
	setAcceptHoverEvents(true);
}

Button::~Button()
{
	qDebug() << "Button deleted";
}

void
Button::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	emit clicked();
}

void
Button::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	setPixmap(m_hovered.scaled(boundingRect().width() + 10,
		boundingRect().height() + 10));
	setPos(mapToParent(-5, -5));
	QGraphicsPixmapItem::hoverEnterEvent(event);
}

void
Button::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	setPixmap(m_normal);
	setPos(mapToParent(5, 5));
	QGraphicsPixmapItem::hoverLeaveEvent(event);
}