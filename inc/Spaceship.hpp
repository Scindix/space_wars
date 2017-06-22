#ifndef SPACESHIP_H
#define SPACESHIP_H
class Spaceship
{
public:
        Spaceship() {}
        virtual ~Spaceship() {}
protected:
	short laserEnergy;
	short shieldEnergy;
	short drivingEnergy;
	virtual void playRound() = 0;
private:
	int absolutePosition;
};
#endif //SPACESHIP_H
