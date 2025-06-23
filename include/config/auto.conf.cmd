deps_config := \
	/home/xiucong/ysyx-workbench/npc/csrc/device/Kconfig \
	/home/xiucong/ysyx-workbench/npc/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
