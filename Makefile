NANOPB_DIR=../nanopb
API_DIR=../api
ABILITY_DIR=../api/ability
GEN_DIR=../api/gen-tiny
ARDUINO_DIR=src

SDK_DIR=visionseed
INCLUDE_DIR=$(SDK_DIR)
SRC_DIR=$(SDK_DIR)

.PHONY: release copy clean

all: release

copy:
	cd $(INCLUDE_DIR) && ln -s ../$(NANOPB_DIR)/*.h .
	cd $(INCLUDE_DIR) && ln -s ../$(API_DIR)/DataLink.h .
	cd $(INCLUDE_DIR) && ln -s ../$(API_DIR)/YtConfig.h .
	cd $(INCLUDE_DIR) && ln -s ../$(API_DIR)/YtLog.h .
	cd $(INCLUDE_DIR) && ln -s ../$(GEN_DIR)/*.h .
	cd $(INCLUDE_DIR) && ln -s ../$(ABILITY_DIR)/*.h .
	cd $(INCLUDE_DIR) && ln -s ../$(ARDUINO_DIR)/*.h .
	cd $(SRC_DIR) && ln -s ../$(NANOPB_DIR)/*.c .
	cd $(SRC_DIR) && ln -s ../$(API_DIR)/DataLink.cpp .
	cd $(SRC_DIR) && ln -s ../$(GEN_DIR)/*.c .
	cd $(SRC_DIR) && ln -s ../$(ARDUINO_DIR)/*.cpp .
	cd $(SRC_DIR) && ln -s ../$(ABILITY_DIR)/*.cpp .

dev:
	ln -s `pwd`/$(SDK_DIR) ~/Arduino/libraries/

release: clean copy
	cd $(SDK_DIR) && zip -r ../visionseed.zip --exclude="*.a" *
	zip -r yt-visionseed-sdk-arduino.zip --exclude="*.a" *

clean:
	-rm *.zip
	-rm $(INCLUDE_DIR)/*
	-rm $(SRC_DIR)/*
