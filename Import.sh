#!/bin/bash

cp -f `pwd`/Makefile ../../../
ln -s -f `pwd`/DataModel/CardData.cpp ../../../DataModel/
ln -s -f `pwd`/DataModel/CardData.h ../../../DataModel/
ln -s -f `pwd`/DataModel/Waveform.cpp ../../../DataModel/
ln -s -f `pwd`/DataModel/Waveform.h ../../../DataModel/
cp -f `pwd`/DataModel/DataModel.h ../../../DataModel/
ln -s -f `pwd`/Electronics ../../../Dependencies/
ln -s -f `pwd`/UserTools/Digitiser ../../InactiveTools/
ln -s -f `pwd`/UserTools/SaveASCII ../../InactiveTools/
ln -s -f `pwd`/configfiles/FakeDAQ ../../../configfiles/
ln -s -f `pwd`/configfiles/FakeDAQ/ToolChainConfig ../../../FakeDAQ
cd `pwd`/Electronics/
make
