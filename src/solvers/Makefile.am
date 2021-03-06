# $Id$

include $(top_srcdir)/src/Makefile.custom
include $(top_srcdir)/config/Make-rules

# Which programs to build. Only PROGRAMS_NORMAL will be installed.
PROGRAMS_NORMAL =  Perseus\
 GMAA\
 GMAA_ELSI\
 JESP \
 DICEPS \
 BFS \
 MMDP_QLearner \
 MMDP_Solver

if HAVE_CPLEX
PROGRAMS_NORMAL += DPLPC  # Not in default compile as it needs CPLEX
endif


##############
# Includedirs, libdirs, libs and cflags for all programs 
INCLUDEPATH		= -I..\
 -I$(top_srcdir)/src/base -I$(top_srcdir)/src/include\
 -I$(top_srcdir)/src/support -I$(top_srcdir)/src/planning\
 -I$(top_srcdir)/src/parser \
 $(MADP_INCLUDES) 
AM_LDFLAGS		= 
LDADD			= 
AM_CPPFLAGS		= -pipe $(MARCH_FLAGS) $(INCLUDEPATH)
if DARWIN
AM_CPPFLAGS += -DDARWIN
endif

noinst_PROGRAMS = 
bin_PROGRAMS = $(PROGRAMS_NORMAL)

# the GMAA-ICE script should be installed as well
install-exec-local:
	$(INSTALL_PROGRAM) ./GMAA-ICE $(DESTDIR)$(bindir)

# Build Perseus
Perseus_SOURCES = Perseus.cpp
Perseus_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
Perseus_LDFLAGS = $(AM_LDFLAGS) 
Perseus_DEPENDENCIES = $(MADPLIBS_NORMAL)
Perseus_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
Perseus_CXXFLAGS= $(CSTANDARD)
Perseus_CFLAGS=

# Build GMAA
GMAA_SOURCES = GMAA.cpp
GMAA_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD) $(LIBDAI_NORMAL)
GMAA_LDFLAGS = $(AM_LDFLAGS) 
GMAA_DEPENDENCIES = $(MADPLIBS_NORMAL)
GMAA_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
GMAA_CXXFLAGS= $(CSTANDARD)
GMAA_CFLAGS=

# Build GMAA_ELSI
GMAA_ELSI_SOURCES = GMAA_ELSI.cpp
GMAA_ELSI_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
GMAA_ELSI_LDFLAGS = $(AM_LDFLAGS) 
GMAA_ELSI_DEPENDENCIES = $(MADPLIBS_NORMAL)
GMAA_ELSI_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
GMAA_ELSI_CXXFLAGS= $(CSTANDARD)
GMAA_ELSI_CFLAGS=

# Build JESP
JESP_SOURCES = JESP.cpp
JESP_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
JESP_LDFLAGS = $(AM_LDFLAGS) 
JESP_DEPENDENCIES = $(MADPLIBS_NORMAL)
JESP_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
JESP_CXXFLAGS= $(CSTANDARD)
JESP_CFLAGS=


# Build DICEPS
DICEPS_SOURCES = DICEPS.cpp
DICEPS_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
DICEPS_LDFLAGS = $(AM_LDFLAGS) 
DICEPS_DEPENDENCIES = $(MADPLIBS_NORMAL)
DICEPS_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
DICEPS_CXXFLAGS= $(CSTANDARD)
DICEPS_CFLAGS=

# Build BFS
BFS_SOURCES = BFS.cpp
BFS_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
BFS_LDFLAGS = $(AM_LDFLAGS) 
BFS_DEPENDENCIES = $(MADPLIBS_NORMAL)
BFS_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
BFS_CXXFLAGS= $(CSTANDARD)
BFS_CFLAGS=


if HAVE_CPLEX
# Build DP-LPC
DPLPC_SOURCES = DP-LPC.cpp
DPLPC_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD) $(CPLEX_LIBS)
DPLPC_LDFLAGS = $(AM_LDFLAGS)  $(CPLEX_LDFLAGS)
DPLPC_DEPENDENCIES = $(MADPLIBS_NORMAL)
DPLPC_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
DPLPC_CXXFLAGS= $(CSTANDARD) $(CPLEX_INCLUDES) -DILOUSESTL 
DPLPC_CFLAGS=
endif 

# Build MMDP_QLearner
MMDP_QLearner_SOURCES = MMDP_QLearner.cpp
MMDP_QLearner_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
MMDP_QLearner_LDFLAGS = $(AM_LDFLAGS) 
MMDP_QLearner_DEPENDENCIES = $(MADPLIBS_NORMAL)
MMDP_QLearner_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
MMDP_QLearner_CXXFLAGS=
MMDP_QLearner_CFLAGS=

# Build MMDP_Solver
MMDP_Solver_SOURCES = MMDP_Solver.cpp
MMDP_Solver_LDADD = $(MADPLIBS_NORMAL) $(MADP_LD)
MMDP_Solver_LDFLAGS = $(AM_LDFLAGS) 
MMDP_Solver_DEPENDENCIES = $(MADPLIBS_NORMAL)
MMDP_Solver_CPPFLAGS= $(AM_CPPFLAGS) $(CPP_OPTIMIZATION_FLAGS)
MMDP_Solver_CXXFLAGS=
MMDP_Solver_CFLAGS=
