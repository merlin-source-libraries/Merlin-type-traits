#!/bin/bash

if [ $# == 1 ]; then
	if [ ! -d $1 ]; then
		mkdir -p $1
	fi
	repository=$(pwd)
	cd $1
	if [ ! -d ./include ]; then
		mkdir include
	fi
	if [ -d "${repository}/include" ] && [ -f "${repository}/include/merlin_type_traits.hpp" ]; then
		cp "${repository}/include/merlin_type_traits.hpp" ./include/
	else
		echo "[Error] Sources not found - The installation script must be called from the repository (cd to Merlin-type-traits/)."
	fi
else
	echo "[Error] Expected 1 argument ($# given) - (Only) the installation directory is required."
fi

