#include <math.h>
#include <stdio.h>

#define real double

// Solar constant W / m ^ 2
#define S0 1370

// Stefan - Boltzmann constant W / m2 / K4
#define SIGMA 0.00000005670367

// Temperature inertia (in years)
#define THETA 100.0

// Albedo, in this simulation albedo is considered constant
// in reality albedo can become lower with increased temperatures
// due to ice cap melting
#define ALBEDO 0.33

// Initial values

// Simulation starts in 2007
static const real t0 = 2007.0;
// Temperaturature in 2007 in K
static const real T0 = 288.45;
// CO2 concentration in 2007 in ppm
static const real CO20 = 370.0;

// Greenhouse gaz fraction
static real G(real T, real co2)
{
    return 3.35071874e-03 * T + 3.20986702e-05 * co2 - 0.561593690144655;
}

//VARIATION DE LA TEMPÉRATURE//

//Q.1
static real real_P_in() {
    return (1-ALBEDO)*(S0 / 4);
}

//Q.1
real real_P_out(real t, real T){
    return (1-G(T, CO20))*SIGMA * T * T * T * T;
}

//Q.2
real real_F(real t, real T) {
    return (real_P_in()-real_P_out(t, T))*(1/100);
}

int main(int argc, char **argv)
{
    printf("Simple climate simulation\n");

    return 0;
}
