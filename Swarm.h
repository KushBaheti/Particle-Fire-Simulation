#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particlefiresimulation {

class Swarm {
public:
	const static int NPARTICLES = 5000;
	int lastTime;

private:
	Particle * m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() {return m_pParticles;};
	void update(int elapsed);
};

} /* namespace particlefiresimulation */

#endif /* SWARM_H_ */
