//
// Created by emb on 4/28/20.
//
// FastMover is a fast, single-stage envelope
// scales and fits one of a collection of shapes,
// between arbitrary points.
// uses a set of static shape tables, and no interpolation

#ifndef CRONE_FASTMOVER_HPP
#define CRONE_FASTMOVER_HPP

class FastMover {
public:
    typedef uint32_t idx_t;
private:
    // index-per-sample increment
    float inc;
    float phase;
public:
    // WIP / test: tables should be big, binary, numerous &c
    constexpr int numShapes = 1;
    constexpr int tableSize = 16;
    const float ShapeData[][numShapes];

};


#endif //CRONE_FASTMOVER_HPP
