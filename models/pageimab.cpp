[PARAM] @annotated
KA        : 1       : absorption rate constant (1/hr)
CL        : 3.17    : Clearance (L/h)
V         : 39.4    : Volume (L) 
WT        : 70      : Weight (kg)

[FIXED] @annotated 
STD_WT   : 70  : Standard weight (kg)

[CMT] @annotated
GUT : Gut compartment (mg)
CENT : Central compartment (mg)

[PKMODEL]
ncmt=1, trans=11, depot=TRUE

[MAIN]
double KAi = KA*exp(EKA);
double CLi = CL*pow(WT/STD_WT,0.75)*exp(ECL);
double Vi = V*(WT/STD_WT)*exp(EV);

[OMEGA] @annotated @name IIV1
EKA : 0.04      : Eta on Ka

[OMEGA] @annotated @block @correlation @name IIV2
ECL : 0.07      : Eta on CL
EV  : 0.34 0.076 : Eta on V

//[SIGMA] @annotated
//PROP : 0.053 : Proportional error (variance)
//ADD  : 0.8  : Additive ((mg/L)^2)
  
[TABLE]
double CP = CENT/Vi;
//double DV = CP*(1+PROP) + ADD;

[CAPTURE] @annotated
CP     : predicted plasma concentration (mg/L)
//DV     : plasma concentration (mg/L)
CLi    : Individual Clearance (L/hr)
Vi     : Individual Volume (L)
WT     : Weight (kg)
