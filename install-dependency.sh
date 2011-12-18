#!/bin/bash
cd depend;
tar -xvf jansson-2.2.1.tar.gz 
jansson-2.2.1/configure  
make
make install
