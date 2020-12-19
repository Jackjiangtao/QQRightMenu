#ifndef QQ_CUSTOM_MENU_H
#define QQ_CUSTOM_MENU_H

/**
* @author : ǰ���е�С��;
* @date   : 2018��05��18��
* @version: 1.0
* @note   : ģ��QQ�˵���ʽ��ʵ���Զ���˵���ͨ��ListWidget���ز˵���;
			1���Զ����ò˵��߶ȣ����ݵ�ǰ��ӵĲ˵��������˵��߶�;
			2���˵���ȿɸ��ݲ˵�������������;
			3���˵���͸���ȡ��˵��߿���Ӱ��ȡ��˵��Ľ�Բ�ǻ��Ⱦ�������;
			4�������˵�����ʽ���˵���������ɫ��ͼ��Ⱦ����������ã�
			   ����ֻ����һ��ģ�壬��ҿ����з�����չ;

*@ ���͵�ַ: https://blog.csdn.net/GoForwardToStep ;
**/


#include <QtWidgets/QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QIcon>
#include <QPainter>
#include <QListWidget>

#define MENU_ITEM_HEIGHT 30			// �˵���ĸ߶�;

class QQMenuItemWidget : public QWidget
{
	Q_OBJECT

public:
	QQMenuItemWidget()
		: m_isEnter(false)
		, m_itemIndex(0)
	{
		m_iconLabel = new QLabel;
		m_iconLabel->setFixedSize(QSize(20, 20));

		m_textLabel = new QLabel;
		m_textLabel->setStyleSheet("font-family:Microsoft YaHei;font-size:14px;");

		QHBoxLayout* hLayout = new QHBoxLayout(this);
		hLayout->addWidget(m_iconLabel);
		hLayout->addWidget(m_textLabel);
		hLayout->addStretch();
		hLayout->setSpacing(10);
		hLayout->setContentsMargins(10, 0, 0, 0);

		this->setFixedHeight(MENU_ITEM_HEIGHT);
		this->setAttribute(Qt::WA_TranslucentBackground);
	}

	// ���ò˵�������;
	void setMenuItemText(const QString& text)
	{
		m_textLabel->setText(text);
		m_textLabel->setScaledContents(true);
	}
	
	// ���ò˵���ͼ��;
	void setMenuItemIcon(const QIcon& icon)
	{
		m_iconLabel->setPixmap(icon.pixmap(QSize(20, 20)));
	}

	// ���ò˵���Index;
	void SetMenuItemIndex(const int& index)
	{
		m_itemIndex = index;
	}

private:
	void mouseReleaseEvent(QMouseEvent *event)
	{
		emit signalMenuClicked(m_itemIndex);
	}

	void enterEvent(QEvent *event)
	{
		m_isEnter = true;
		update();
	}

	void leaveEvent(QEvent *event)
	{
		m_isEnter = false;
		update();
	}

	void paintEvent(QPaintEvent *event)
	{
		if (m_isEnter)
		{
			QPainter painter(this);
			painter.fillRect(this->rect(), QColor(215, 215, 215, 150));
		}
	}

signals:
	// ֪ͨ�˵�����;
	void signalMenuClicked(int);

private:
	QLabel* m_iconLabel;
	QLabel* m_textLabel;
	int m_itemIndex;
	bool m_isEnter;
};

class QQCustomMenu : public QWidget
{
	Q_OBJECT

public:
	QQCustomMenu(QWidget *parent = Q_NULLPTR);
	// ��Ӳ˵���;
	void addMenuItem(const QIcon &icon, const QString &text);
	// ��ӷָ���;
	void addSeparator();

private:
	void initWidget();
	void paintEvent(QPaintEvent *event);

private slots:
	// ����Index�жϵ�ǰ������Ǹ��˵���;
	void onMenuItemClicked(int menuItemIndex);

private:
	QListWidget* m_menuItemListWidget;
	// ���ݵ�ǰ��ӵĲ˵���ͷָ����Զ�����˵��߶�;
	int m_currentMenuHeight;
	// ��¼�˵���Index;
	int m_menuItemIndex;
};
#endif