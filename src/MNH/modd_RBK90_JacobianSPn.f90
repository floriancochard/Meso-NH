!MNH_LIC Copyright 1994-2019 CNRS, Meteo-France and Universite Paul Sabatier
!MNH_LIC This is part of the Meso-NH software governed by the CeCILL-C licence
!MNH_LIC version 1. See LICENSE, CeCILL-C_V1-en.txt and CeCILL-C_V1-fr.txt
!MNH_LIC for details. version 1.
!******************************************************************

! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! 
! Sparse Jacobian Data Structures File
! 
! Generated by KPP-2.2 symbolic chemistry Kinetics PreProcessor
!       (http://www.cs.vt.edu/~asandu/Software/KPP)
! KPP is distributed under GPL, the general public licence
!       (http://www.gnu.org/copyleft/gpl.html)
! (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa
! (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech
!     With important contributions from:
!        M. Damian, Villanova University, USA
!        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany
! 
! File                 : RBK90_JacobianSP.f90
! Time                 : Mon Apr 16 16:40:45 2007
! Working directory    : /home/pinjp/chimie_num/kpp/kpp-2.2.1.December2006/my-test-NumRec
! Equation file        : RBK90.kpp
! Output root filename : RBK90
! 
! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
! Modifications
!  P. Wautelet 08/02/2019: add missing NULL association for pointers


MODULE MODD_RBK90_JacobianSP_n
USE MODD_PARAMETERS, ONLY: JPMODELMAX
IMPLICIT NONE

TYPE RBK90_JacobianSP_t
 ! PUBLIC
 ! SAVE


! Sparse Jacobian Data


    INTEGER, DIMENSION(:), POINTER :: LU_IROW => NULL()
    INTEGER, DIMENSION(:), POINTER :: LU_ICOL => NULL()

    INTEGER, DIMENSION(:), POINTER :: LU_CROW => NULL()
    INTEGER, DIMENSION(:), POINTER :: LU_DIAG => NULL()

    INTEGER, DIMENSION(:), POINTER :: LU_DIM_SPECIES => NULL()

END TYPE RBK90_JacobianSP_t

TYPE(RBK90_JacobianSP_t), DIMENSION(JPMODELMAX), TARGET, SAVE :: RBK90_JacobianSP_MODEL

INTEGER, DIMENSION(:), POINTER :: LU_IROW=>NULL()
INTEGER, DIMENSION(:), POINTER :: LU_ICOL=>NULL()
INTEGER, DIMENSION(:), POINTER :: LU_CROW=>NULL()
INTEGER, DIMENSION(:), POINTER :: LU_DIAG=>NULL()
INTEGER, DIMENSION(:), POINTER :: LU_DIM_SPECIES=>NULL()

CONTAINS

SUBROUTINE RBK90_JacobianSP_GOTO_MODEL(KFROM, KTO)
INTEGER, INTENT(IN) :: KFROM, KTO
!
! Save current state for allocated arrays
RBK90_JacobianSP_MODEL(KFROM)%LU_IROW=>LU_IROW
RBK90_JacobianSP_MODEL(KFROM)%LU_ICOL=>LU_ICOL
RBK90_JacobianSP_MODEL(KFROM)%LU_CROW=>LU_CROW
RBK90_JacobianSP_MODEL(KFROM)%LU_DIAG=>LU_DIAG
RBK90_JacobianSP_MODEL(KFROM)%LU_DIM_SPECIES=>LU_DIM_SPECIES
!
! Current model is set to model KTO
LU_IROW=>RBK90_JacobianSP_MODEL(KTO)%LU_IROW
LU_ICOL=>RBK90_JacobianSP_MODEL(KTO)%LU_ICOL
LU_CROW=>RBK90_JacobianSP_MODEL(KTO)%LU_CROW
LU_DIAG=>RBK90_JacobianSP_MODEL(KTO)%LU_DIAG
LU_DIM_SPECIES=>RBK90_JacobianSP_MODEL(KTO)%LU_DIM_SPECIES

END SUBROUTINE RBK90_JacobianSP_GOTO_MODEL

END MODULE MODD_RBK90_JacobianSP_n