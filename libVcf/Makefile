.PHONY: all release debug
all: release 

LIB = lib-vcf.a
LIB_DBG = lib-dbg-vcf.a
BASE = PeopleSet VCFUtil PlinkInputFile PlinkOutputFile VCFInfo VCFInputFile VCFIndividual SiteSet VCFHeader BCFReader VCFExtractor VCFFilter

OBJ = $(BASE:=.o)

TABIX_INC = ../third/tabix
TABIX_LIB = ../third/tabix/libtabix.a
$(TABIX_INC) $(TABIX_LIB):
	(cd ../third; make tabix)

PCRE_INC = ../third/pcre/include
$(PCRE_INC):
	(cd ../third; make pcre)

GSL_INC = ../third/gsl/include
$(GSL_INC):
	(cd ../third; make gsl)

SAMTOOLS_INC = ../third/samtools
BCF_INC = ../third/samtools/bcftools 
$(SAMTOOLS_INC) $(BCF_INC):
	(cd ../third; make samtools)

THIRD_INC = $(TABIX_INC) $(PCRE_INC) $(BCF_INC)

### put BCF_INC ahead of TABIX, so correct kseq.h can be included
DEFAULT_CXXFLAGS = -std=c++0x -D__STDC_LIMIT_MACROS -I. -I.. -I../base -I$(SAMTOOLS_INC) -I$(BCF_INC) -I$(PCRE_INC) -I$(GSL_INC) -I$(TABIX_INC) -D_FILE_OFFSET_BITS=64 -D_USE_KNETFILE

# 'make release' will: clean current build; build with -O4 flags;
# NOTE: don't use -j flag!
release: CXXFLAGS = -O4 -DNDEBUG $(DEFAULT_CXXFLAGS)
release: $(LIB) 

debug: CXXFLAGS = -Wall -ggdb -O0 $(DEFAULT_CXXFLAGS)
debug: $(LIB_DBG)

$(LIB): $(OBJ) 
	ar rcs $@ $^
$(LIB_DBG): $(OBJ) 
	ar rcs $@ $^

%: %.cpp # remove implicit Makefile rule of converting ABC.cpp to ABC
%.o: %.cpp %.h $(THIRD_INC)
	g++ -c $(CXXFLAGS) $<

clean:
	rm -rf $(LIB) $(LIB_DBG) *.o *.d
