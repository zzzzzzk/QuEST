#include <stdio.h>
#include <QuEST.h>

int main (int narg, char *varg[]) {
QuESTEnv env = createQuESTEnv();
Qureg qubits = createQureg(2, env);
initZeroState(qubits);

reportQuregParams(qubits);
reportQuESTEnv(env);

hadamard(qubits, 0);
ComplexMatrix2 u;
u.r0c0 = (Complex) {.real=0, .imag=1};
u.r0c1 = (Complex) {.real=0, .imag=0}; 
u.r1c0 = (Complex) {.real=0, .imag=0};
u.r1c1 = (Complex) {.real=1, .imag=0};
unitary(qubits, 1, u);
  
controlledUnitary(qubits, 0, 1, u);
hadamard(qubits, 0);

qreal prob;
prob = calcProbOfOutcome(qubits, 0, 0);
printf("Probability of qubit 0 being in state 0: %f\n", prob);

destroyQureg(qubits, env);
destroyQuESTEnv(env);
return(0);
}
