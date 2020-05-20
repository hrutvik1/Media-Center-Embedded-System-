#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/e54ec12a/Blinky.o \
	${OBJECTDIR}/_ext/e54ec12a/GLCD_SPI_LPC1700.o \
	${OBJECTDIR}/_ext/e54ec12a/IRQ.o \
	${OBJECTDIR}/_ext/e54ec12a/KBD.o \
	${OBJECTDIR}/_ext/e54ec12a/LED.o \
	${OBJECTDIR}/_ext/e54ec12a/flappy.o \
	${OBJECTDIR}/_ext/e54ec12a/ie.o \
	${OBJECTDIR}/_ext/e54ec12a/nowpanic.o \
	${OBJECTDIR}/_ext/e54ec12a/paper.o \
	${OBJECTDIR}/_ext/e54ec12a/rockIcon.o \
	${OBJECTDIR}/_ext/e54ec12a/scissors.o \
	${OBJECTDIR}/_ext/e54ec12a/spongebob.o \
	${OBJECTDIR}/_ext/e54ec12a/usbdmain.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mediacenter

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mediacenter: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mediacenter ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/e54ec12a/Blinky.o: ../718projFinal/Blinky.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/Blinky.o ../718projFinal/Blinky.c

${OBJECTDIR}/_ext/e54ec12a/GLCD_SPI_LPC1700.o: ../718projFinal/GLCD_SPI_LPC1700.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/GLCD_SPI_LPC1700.o ../718projFinal/GLCD_SPI_LPC1700.c

${OBJECTDIR}/_ext/e54ec12a/IRQ.o: ../718projFinal/IRQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/IRQ.o ../718projFinal/IRQ.c

${OBJECTDIR}/_ext/e54ec12a/KBD.o: ../718projFinal/KBD.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/KBD.o ../718projFinal/KBD.c

${OBJECTDIR}/_ext/e54ec12a/LED.o: ../718projFinal/LED.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/LED.o ../718projFinal/LED.c

${OBJECTDIR}/_ext/e54ec12a/flappy.o: ../718projFinal/flappy.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/flappy.o ../718projFinal/flappy.c

${OBJECTDIR}/_ext/e54ec12a/ie.o: ../718projFinal/ie.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/ie.o ../718projFinal/ie.c

${OBJECTDIR}/_ext/e54ec12a/nowpanic.o: ../718projFinal/nowpanic.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/nowpanic.o ../718projFinal/nowpanic.c

${OBJECTDIR}/_ext/e54ec12a/paper.o: ../718projFinal/paper.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/paper.o ../718projFinal/paper.c

${OBJECTDIR}/_ext/e54ec12a/rockIcon.o: ../718projFinal/rockIcon.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/rockIcon.o ../718projFinal/rockIcon.c

${OBJECTDIR}/_ext/e54ec12a/scissors.o: ../718projFinal/scissors.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/scissors.o ../718projFinal/scissors.c

${OBJECTDIR}/_ext/e54ec12a/spongebob.o: ../718projFinal/spongebob.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/spongebob.o ../718projFinal/spongebob.c

${OBJECTDIR}/_ext/e54ec12a/usbdmain.o: ../718projFinal/usbdmain.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e54ec12a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e54ec12a/usbdmain.o ../718projFinal/usbdmain.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
