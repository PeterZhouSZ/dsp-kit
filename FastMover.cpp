//
// Created by emb on 4/28/20.
//

#include "FastMover.hpp"

using dspkit::FastMover;
const float FastMover::shapeTables[FastMover::tableSize][FastMover::numTables] = {
        {
#include "easing_linear.inc"
        },
        {
#include "easing_in_back.inc"
        },
        {
#include "easing_in_bounce.inc"
        },
        {
#include "easing_in_circular.inc"
        },
        {
#include "easing_in_cubic.inc"
        },
        {
#include "easing_in_elastic.inc"
        },
        {
#include "easing_in_exponential.inc"
        },
        {
#include "easing_in_quadratic.inc"
        },
        {
#include "easing_in_quartic.inc"
        },
        {
#include "easing_in_quintic.inc"
        },
        {
#include "easing_in_sine.inc"
        },
        {
#include "easing_in_out_back.inc"
        },
        {
#include "easing_in_out_bounce.inc"
        },
        {
#include "easing_in_out_circular.inc"
        },
        {
#include "easing_in_out_cubic.inc"
        },
        {
#include "easing_in_out_elastic.inc"
        },
        {
#include "easing_in_out_exponential.inc"
        },
        {
#include "easing_in_out_quadratic.inc"
        },
        {
#include "easing_in_out_quartic.inc"
        },
        {
#include "easing_in_out_quintic.inc"
        },
        {
#include "easing_in_out_sine.inc"
        },
        {
#include "easing_out_back.inc"
        },
        {
#include "easing_out_bounce.inc"
        },
        {
#include "easing_out_circular.inc"
        },
        {
#include "easing_out_cubic.inc"
        },
        {
#include "easing_out_elastic.inc"
        },
        {
#include "easing_out_exponential.inc"
        },
        {
#include "easing_out_quadratic.inc"
        },
        {
#include "easing_out_quartic.inc"
        },
        {
#include "easing_out_quintic.inc"
        },
        {
#include "easing_out_sine.inc"
        },
};
