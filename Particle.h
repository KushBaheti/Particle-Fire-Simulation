#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particlefiresimulation {

class Particle {
public:
	double m_x;
	double m_y;
//	double m_xspeed;
//	double m_yspeed;

private:
	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);

private:
	void init();
};

} /* namespace particlefiresimulation */

#endif /* PARTICLE_H_ */
