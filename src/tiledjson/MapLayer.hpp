#ifndef MAPLAYER_HPP
#define MAPLAYER_HPP

#include <string>

namespace te
{

enum LayerType {
    UnknownLayerType,
    TileLayer,
    ObjectGroup,
    ImageLayer
};

class MapLayer
{

protected:
	unsigned int			mWidth;
	unsigned int			mHeight;
	int						mX;
	int						mY;

	std::string				mName;

	float					mOpacity;

	LayerType				mType;

	bool					mVisible;

public:
	MapLayer();
	virtual ~MapLayer();


	void setHeight(unsigned int mHeight) {
		this->mHeight = mHeight;
	}
	void setName(const std::string& mName) {
		this->mName = mName;
	}
	void setOpacity(float mOpacity) {
		this->mOpacity = mOpacity;
	}
	void setType(const LayerType& mType) {
		this->mType = mType;
	}
	void setVisible(bool mVisible) {
		this->mVisible = mVisible;
	}
	void setWidth(unsigned int mWidth) {
		this->mWidth = mWidth;
	}
	void setX(int mX) {
		this->mX = mX;
	}
	void setY(int mY) {
		this->mY = mY;
	}
	unsigned int getHeight() const {
		return mHeight;
	}
	const std::string& getName() const {
		return mName;
	}
	float getOpacity() const {
		return mOpacity;
	}
	const LayerType& getType() const {
		return mType;
	}
	bool isVisible() const {
		return mVisible;
	}
	unsigned int getWidth() const {
		return mWidth;
	}
	int getX() const {
		return mX;
	}
	int getY() const {
		return mY;
	}
	
	bool getVisible(){
		return mVisible;
	}
	
};

}

#endif // MAPLAYER_HPP
