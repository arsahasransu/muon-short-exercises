ifeq ($(strip $(MuonExercise1)),)
MuonExercise1 := self/src/MuonExercises/MuonExercises1/plugins
PLUGINS:=yes
MuonExercise1_files := $(patsubst src/MuonExercises/MuonExercises1/plugins/%,%,$(foreach file,MuonExercise1.cc,$(eval xfile:=$(wildcard src/MuonExercises/MuonExercises1/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/MuonExercises/MuonExercises1/plugins/$(file). Please fix src/MuonExercises/MuonExercises1/plugins/BuildFile.))))
MuonExercise1_BuildFile    := $(WORKINGDIR)/cache/bf/src/MuonExercises/MuonExercises1/plugins/BuildFile
MuonExercise1_LOC_USE := self  FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/L1Trigger DataFormats/TrackReco SimTracker/Records DataFormats/MuonReco DataFormats/Math CommonTools/UtilAlgos DataFormats/HepMCCandidate DataFormats/PatCandidates DataFormats/Common clhep root
MuonExercise1_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,MuonExercise1,MuonExercise1,$(SCRAMSTORENAME_LIB),src/MuonExercises/MuonExercises1/plugins))
MuonExercise1_PACKAGE := self/src/MuonExercises/MuonExercises1/plugins
ALL_PRODS += MuonExercise1
MuonExercises/MuonExercises1_forbigobj+=MuonExercise1
MuonExercise1_INIT_FUNC        += $$(eval $$(call Library,MuonExercise1,src/MuonExercises/MuonExercises1/plugins,src_MuonExercises_MuonExercises1_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
MuonExercise1_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,MuonExercise1,src/MuonExercises/MuonExercises1/plugins))
endif
ALL_COMMONRULES += src_MuonExercises_MuonExercises1_plugins
src_MuonExercises_MuonExercises1_plugins_parent := MuonExercises/MuonExercises1
src_MuonExercises_MuonExercises1_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_MuonExercises_MuonExercises1_plugins,src/MuonExercises/MuonExercises1/plugins,PLUGINS))
