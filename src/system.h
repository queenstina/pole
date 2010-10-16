/*
 * system.h
 *
 *  Created on: Sep 15, 2010
 *      Author: baj
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <cstdlib>
#include <cmath>

#include "pole.h"

class Agent;
class Logger;

class System {
public:
	System() {
		pole_.perturbation();
	}

	void reset() {
		pole_.reset();
	}

	double get_reward() { //评价范围 [0.0, 2.0]
		return cos(pole_.theta()) + cos(pole_.dtheta()); //以保持不动为最佳
	}

	double simulate(Agent & agent, int max_steps = 1024, bool verbose = false, Logger *logger = 0);

private:
	Pole pole_;
};

#endif /* SYSTEM_H_ */
