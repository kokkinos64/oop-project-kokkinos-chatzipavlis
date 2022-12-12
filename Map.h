// This is Map.h

class MapObject
{
private:
	bool isNight;

public:
	bool getNighttime(void);

	void setNight(bool dn)
	{
		isNight = dn;

		cout << "Daytime changed.\n";
	}
};