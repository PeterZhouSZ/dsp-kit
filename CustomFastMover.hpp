//
// Created by emb on 6/1/20.
//
// this subclass of FastMover allows an arbitrary transform function
// to be applied to the shape tables at class initialization time.

#ifndef CRONE_CUSTOMFASTMOVER_HPP
#define CRONE_CUSTOMFASTMOVER_HPP


#include "FastMover.hpp"

namespace dspkit {
    class CustomFastMover : FastMover {

    private:
        static float customShapeTables[FastMover::numTables][FastMover::tableSize];
        static bool didClassInit = false;

        static void classInit() {
            if (didClassInit) { return; }
            for (int tab=0; tab<numTables; ++tab) {
                for (int pos = 0; pos < numTables; ++pos) {
                    customShapeTables[tab][pos] = transform(shapeTables[tab][pos]);
                }
            }
            didClassInit = true;
        }

        virtual float transform(float x) = 0;

    public:
        CustomFastMover() {
            classInit();
            riseTable = customShapeTables[0];
            fallTable = customShapeTables[0];
        }

        void setRiseShape(int shapeTableIndex) {
            riseTable = customShapeTables[shapeTableIndex];
        }

        void setFallShape(int shapeTableIndex) {
            fallTable = customShapeTables[shapeTableIndex];
        }

    };
}


#endif //CRONE_CUSTOMFASTMOVER_HPP
