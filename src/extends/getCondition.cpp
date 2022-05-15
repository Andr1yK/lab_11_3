#pragma once

#ifndef _GETCONDITION_
#define _GETCONDITION_

bool getCondition(
  int cPhysics, int cRank, string cLastName,
  int physics, int rank, string lastName
) {
  bool byPhisics = cPhysics > physics;
  bool byRank = cPhysics == physics
    && cRank > rank;

  bool byLastName = cPhysics == physics
    && cRank == rank
    && cLastName > lastName;

  return byPhisics || byRank || byLastName;
}

#endif
