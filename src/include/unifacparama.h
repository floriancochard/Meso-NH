C         Include file : unifacparama.h
C
C         Purpose: Unifac parameters
C
C         Included in Unidriva.f
C
C        10 secondary compounds at 25C + H2O
C       (Data of Lyman, Reehl, Rosenblatt, 1990)
C
C       NMOL and NFUNC need to match DIMMOL and DIMFUN in unidriva.f
C
C revision History:  1. Developed by Betty Pun, AER, December, 1999 
C                 under CARB funding
C                   2. Modified by Betty Pun, AER, December, 1999 
C                      under CARB funding for Type B module
C                   3. updated for new POA mix and proper structures
C                      and for use in fortran, Rob Griffin, CIT 1/00
C
          REAL RG(17), QG(17), A(17,17)
          INTEGER NU(11,17)
C
C
C    no. of possible molecules      
          NMOL = 11
C
C
C   no. of functional groups
          NFUNC = 17
C
C
      DIMFUN = 17
C          max dimension of unifac parameter arrays for functional groups 
C          = NFUNC in unifacparamb.h
C 
      DIMMOL = 11
C          max dimension of unifac parameter arrays for functional groups 
C          = NMOL in unifacparamb.h
C    Z = 10 is a fixed parameter in Unifac
C
          Z = 10.0
C
         TINY = 1.0E-08
C
c    order CH3, CH2, CH, C=C, C=CH, aero, pah, tol, EB, OH
c     phenol, ketone, aldehyde, COOH, aroNO2, water, C
C
C     group volume parameters
C     dimension of RG is the same as NFUNC
          DATA RG  /0.9011, 0.6744, 0.4469, 0.6605, 0.8886,
     +              0.5313, 0.3562, 1.2663, 1.0396, 1.0000, 0.8952,
     +              1.6724, 0.9980, 1.3013, 1.4199, 0.9200, 0.2195/
C
C    group surface area parameters
C    dimension of QG is the same as NFUNC
          DATA QG  /0.8480, 0.5400, 0.2280, 0.4850, 0.6760,
     +              0.4000, 0.1200, 0.9680, 0.6600, 1.2000, 0.6800,
     +              1.4880, 0.9480, 1.2440, 1.1040, 1.4000, 0.0/
C
C   no. of groups in each molecule
c   that is the #CH3 in species 1-11, the #CH2 in species 1-11,
c   the #CH in species 1-11, etc.
c
c   start with CH3
C
      DATA  NU  /0, 0, 0, 2, 3, 0, 1, 2, 2, 2, 0,
C        CH2
     +      0, 0, 0, 12, 3, 0, 0, 0, 0, 2, 0,
C         CH
     +      0, 0, 0, 1, 2, 0, 0, 0, 2, 3, 0,
c       C=C
     +      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
c      C=CH
     +      0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0,
c    aro
     +      2, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0,
c      pah
     +      0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
c      tol
     +      2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
c        EB
     +      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
C       OH
     +      0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0,
c     phen
     +      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
c        ketone
     +      0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
c     aldehyde
     +      0, 1, 0, 0, 0, 0, 1, 2, 0, 1, 0,
c      COOH
     +      1, 1, 0, 0, 0, 2, 2, 0, 1, 0, 0,
c     aroNO2
     +      1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
c      water
     +      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
c        C
     +      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0/
C
c     CH3 with 1-17 then CH2 with 1-17 then CH with 1-17 etc.
c     start with CH3
c
C  interaction parameters group-group
      DATA A / 0.0, 0.0, 0.0, 2520.00, 2520.00, -11.1200, 
     +       -11.1200, -69.700, -69.700, 156.400, 10000.00,
     +       26.7600, 505.700, 315.300, 5541.00, 300.0, 0.0,
c       CH2
     +       0.0, 0.0,
     +       0.0, 2520.00, 2520.00, -11.1200, -11.1200, -69.700,
     +       -69.700, 156.400, 10000.00, 26.7600, 505.700,
     +       315.300, 5541.00, 300.0, 0.0,
c       CH
     +       0.0, 0.0, 0.0, 2520.00,
     +       2520.00, -11.1200, -11.1200, -69.700, -69.700,
     +       156.400, 10000.00, 26.7600, 505.700, 315.300,
     +       5541.00, 300.0, 0.0,
c        C=C
     +       -200.00, -200.00, -200.00, 0.0, 0.0,
     +       -97.7800, -97.7800, -269.700, -269.700, 8694.00,
     +       732.200, -82.9200, 0.0, 349.200, 0.0, 692.7, -200.00,
c      C=CH
     +       -200.00, -200.00, -200.00, 0.0, 0.0, -97.7800,
     +       -97.7800, -269.700, -269.700, 8694.00, 732.200,
     +       -82.9200, 0.0, 349.200, 0.0, 692.7, -200.00,
c        aro
     +       61.1300,
     +       61.1300, 61.1300, 340.700, 340.700, 0.0, 0.0,
     +       -146.800, -146.800, 89.600, 270.200, 140.100, 0.0,
     +       62.3200, 1824.00, 362.3, 61.1300,
c       pah
     +       61.1300, 61.1300, 61.1300,
     +       340.700, 340.700, 0.0, 0.0, -146.800, -146.800, 89.600,
     +       270.200, 140.100, 0.0, 62.3200, 1824.00, 362.3, 61.1300,
c       tol
     +       76.500, 76.500, 76.500, 4102.00, 4102.00, 167.00,
     +       167.00, 0.0, 0.0, 25.8200, 10000.00, 365.800, 0.0,
     +       268.200, -127.800, 377.6, 76.500,
c       EB
     +       76.500, 76.500, 76.500,
     +       4102.00, 4102.00, 167.00, 167.00, 0.0, 0.0, 25.8200,
     +       10000.00, 365.800, 0.0, 268.200, -127.800, 377.6,
     +       76.500,
c        OH
     +       986.500, 986.500, 986.500, 693.900, 693.900,
     +       636.100, 636.100, 803.200, 803.200, 0.0, -274.500, 
     +       164.500, -404.800, -151.00, 561.600, -229.1, 986.500,
c       phenol
     +       912.200,
     +       912.200, 912.200, 926.300, 926.300, 1174.00, 1174.00,
     +       674.300, 674.300, -442.100, 0.0, -246.800, 0.0, 0.0,
     +       0.0, 324.5, 912.200,
c       ketone
     +       476.400, 476.400, 476.400, 524.500,
     +       524.500, 25.7700, 25.7700, -52.100, -52.100, 84.00,
     +       -158.800, 0.0, 128.00, -297.800, 0.0, -195.4, 476.400,
c      aldehyde
     +       677.00,
     +       677.00, 677.00, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 441.800,
     +       0.0, -37.3600, 0.0, 0.0, 0.0, -257.3, 677.00,
c       COOH
     +       663.500, 663.500,
     +       663.500, 730.400, 730.400, 537.400, 537.400, 603.800,
     +       603.800, 119.00, 0.0, 669.400, 0.0, 0.0, 0.0, -14.090,
     +       663.500,
c       aro NO2
     +       543.00, 543.00, 543.00, 0.0, 0.0, 194.900, 194.900, 
     +       4448.00, 4448.00, 157.100, 0.0, 0.0, 0.0, 0.0, 0.0,
     +       399.50, 543.00,
c       water
     +       1318.00, 1318.00, 1318.00, 634.2, 634.2, 903.8,
     +       903.8, 5695.0, 5695.0, 353.5, -601.8, 472.5, 232.7,
     +       -66.17, 360.7, 0.0, 1318.00,
c      C
     +       0.0, 0.0,
     +       0.0, 2520.00, 2520.00, -11.1200, -11.1200, -69.700,
     +       -69.700, 156.400, 10000.00, 26.7600, 505.700,
     +       315.300, 5541.00, 300.0, 0.0/
C