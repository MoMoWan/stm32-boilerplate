#!/usr/bin/env bash

pushd lib/libopencm3

for PLATFORM in f0 f1 f3 g0
do
  ./scripts/irq2nvic_h ./include/libopencm3/stm32/${PLATFORM}/irq.json
done

popd
