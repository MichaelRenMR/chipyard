#########################################################################################
# vcs makefile
#########################################################################################

#########################################################################################
# general path variables
#########################################################################################
base_dir=$(abspath ../..)
sim_dir=$(abspath .)

#########################################################################################
# include shared variables
#########################################################################################
include $(base_dir)/variables.mk

#########################################################################################
# name of simulator (used to generate *.f arguments file)
#########################################################################################
sim_name = vcs

#########################################################################################
# vcs simulator types and rules
#########################################################################################
sim_prefix = simv
sim = $(sim_dir)/$(sim_prefix)-$(MODEL_PACKAGE)-$(CONFIG)
sim_debug = $(sim_dir)/$(sim_prefix)-$(MODEL_PACKAGE)-$(CONFIG)-debug

include $(base_dir)/vcs.mk

.PHONY: default debug
default: $(sim)
debug: $(sim_debug)

#########################################################################################
# simulaton requirements
#########################################################################################
SIM_FILE_REQS += \
	$(ROCKETCHIP_RSRCS_DIR)/vsrc/TestDriver.v

# copy files but ignore *.h files in *.f since vcs has +incdir+$(build_dir)
$(sim_files): $(SIM_FILE_REQS) | $(build_dir)
	cp -f $^ $(build_dir)
	$(foreach file,\
		$^,\
		$(if $(filter %.h,$(file)),\
			,\
			echo "$(addprefix $(build_dir)/, $(notdir $(file)))" >> $@;))

#########################################################################################
# import other necessary rules and variables
#########################################################################################
include $(base_dir)/common.mk

#########################################################################################
# vcs binary and arguments
#########################################################################################
VCS = vcs -full64

VCS_OPTS = $(VCS_CC_OPTS) $(VCS_NONCC_OPTS) $(PREPROC_DEFINES)

#########################################################################################
# vcs build paths
#########################################################################################
model_dir = $(build_dir)/$(long_name)
model_dir_debug = $(build_dir)/$(long_name).debug

#########################################################################################
# vcs simulator rules
#########################################################################################
$(sim): $(sim_vsrcs) $(sim_common_files) $(dramsim_lib) $(EXTRA_SIM_REQS)
	rm -rf $(model_dir)
	$(VCS) $(VCS_OPTS) $(EXTRA_SIM_SOURCES) -o $@ -Mdir=$(model_dir)

$(sim_debug): $(sim_vsrcs) $(sim_common_files) $(dramsim_lib) $(EXTRA_SIM_REQS)
	rm -rf $(model_dir_debug)
	$(VCS) $(VCS_OPTS) $(EXTRA_SIM_SOURCES) -o $@ -Mdir=$(model_dir_debug)  \
	+define+DEBUG -debug_access+all -kdb -lca

#########################################################################################
# create vcs vpd/fsdb rules
#########################################################################################
.PRECIOUS: $(output_dir)/%.vpd %.vpd
$(output_dir)/%.vpd: $(output_dir)/% $(sim_debug)
	(set -o pipefail && $(sim_debug) $(PERMISSIVE_ON) $(SIM_FLAGS) $(EXTRA_SIM_FLAGS) $(SEED_FLAG) $(VERBOSE_FLAGS) +vcdplusfile=$@ $(PERMISSIVE_OFF) $< </dev/null 2> >(spike-dasm > $<.out) | tee $<.log)

.PRECIOUS: $(output_dir)/%.fsdb %.fsdb
$(output_dir)/%.fsdb: $(output_dir)/% $(sim_debug)
	(set -o pipefail && $(sim_debug) $(PERMISSIVE_ON) $(SIM_FLAGS) $(EXTRA_SIM_FLAGS) $(SEED_FLAG) $(VERBOSE_FLAGS) +fsdbfile=$@ $(PERMISSIVE_OFF) $< </dev/null 2> >(spike-dasm > $<.out) | tee $<.log)


#########################################################################################
# general cleanup rules
#########################################################################################
.PHONY: clean clean-sim clean-sim-debug
clean:
	rm -rf $(gen_dir) $(sim_prefix)-* ucli.key

clean-sim:
	rm -rf $(model_dir) $(build_dir)/vc_hdrs.h $(sim) $(sim).daidir ucli.key

clean-sim-debug:
	rm -rf $(model_dir_debug) $(build_dir)/vc_hdrs.h $(sim_debug) $(sim_debug).daidir ucli.key


ROCKETFLAGS=USE_FSDB=1 CONFIG=RocketConfig
MEGABOOMFLAGS=USE_FSDB=1 CONFIG=MegaBoomConfig
DUALCHANNELMEGABOOMFLAGS=USE_FSDB=1 CONFIG=DualChannelMegaBoomConfig

read_tests_rocket:
	make run-binary-debug BINARY='../../mytests/11-2022/read/read4096.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read8192.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read16384.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read32768.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read524288.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read1048576.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read2097152.riscv' $(ROCKETFLAGS)

read_tests_boom:
	make run-binary-debug BINARY='../../mytests/11-2022/read/read4096.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read8192.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read16384.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read32768.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read524288.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read1048576.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read/read2097152.riscv' $(DUALCHANNELMEGABOOMFLAGS)

write_tests_rocket:
	make run-binary-debug BINARY='../../mytests/11-2022/write/write4096.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write8192.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write16384.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write32768.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write524288.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write1048576.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write2097152.riscv' $(ROCKETFLAGS)

write_tests_boom:
	make run-binary-debug BINARY='../../mytests/11-2022/write/write4096.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write8192.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write16384.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write32768.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write524288.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write1048576.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/write/write2097152.riscv' $(DUALCHANNELMEGABOOMFLAGS)

update_tests_rocket:
	make run-binary-debug BINARY='../../mytests/11-2022/update/update4096.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update8192.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update16384.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update32768.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update65536.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update524288.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update1048576.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update2097152.riscv' $(ROCKETFLAGS)

update_tests_boom:
	make run-binary-debug BINARY='../../mytests/11-2022/update/update4096.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update8192.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update16384.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update32768.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update65536.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update524288.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update1048576.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/update/update2097152.riscv' $(DUALCHANNELMEGABOOMFLAGS)

copy_tests_rocket:
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy4096.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy8192.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy16384.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy32768.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy65536.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy524288.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy1048576.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy2097152.riscv' $(ROCKETFLAGS)

copy_tests_boom:
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy4096.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy8192.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy16384.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy32768.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy65536.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy524288.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy1048576.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/copy/copy2097152.riscv' $(DUALCHANNELMEGABOOMFLAGS)

read2_tests_rocket:
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_4096.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_8192.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_16384.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_32768.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_65536.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_524288.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_1048576.riscv' $(ROCKETFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_2097152.riscv' $(ROCKETFLAGS)

read2_tests_boom:
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_4096.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_8192.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_16384.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_32768.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_65536.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_524288.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_1048576.riscv' $(DUALCHANNELMEGABOOMFLAGS)
	make run-binary-debug BINARY='../../mytests/11-2022/read2/read2_2097152.riscv' $(DUALCHANNELMEGABOOMFLAGS)

read_test_allBooms: 
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C4B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C8B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C4B8MegaBoomConfig USE_FSDB=1
	
read_test_badBooms: 
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C1B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C1B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C1B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C4B1MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C4B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C8B1MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C8B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C8B4MegaBoomConfig USE_FSDB=1
	

write_test_allBooms: 
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C1B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C1B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='..../mytests/11-2022/write/write65536.riscv' CONFIG=C1B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C2B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C2B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C2B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C4B1MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C4B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C4B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C4B8MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C8B1MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C8B2MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C8B4MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/write/write65536.riscv' CONFIG=C8B8MegaBoomConfig USE_FSDB=1

read_tests_boom_mshr:
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B2M16MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B2M32MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B2M64MegaBoomConfig USE_FSDB=1
	make run-binary-debug BINARY='../../mytests/11-2022/read/read65536.riscv' CONFIG=C2B2M4MegaBoomConfig USE_FSDB=1

