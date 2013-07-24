#ifndef MOUSELISTENER_HEADER
#define MOUSELISTENER_HEADER

class MouseListener {

public:
	virtual void MouseMoved(int, int) = 0;
	virtual void MouseLeftButtonClicked() = 0;
	virtual void MouseRightButtonClicked() = 0;

protected:
	MouseListener();
	virtual ~MouseListener();
};

#endif // MOUSELISTENER_HEADER