#include "Queen.h"
#include "path.h"
#include <iostream>

using namespace std;

void Queen::print() const
{
  cout << team << "'s Queen";
}

bool Queen::valid_move(const string& from, const string& to) const
{
  //"from" and "to" are distinct
  if (same(from,to))
    return false;

  //there is no piece of the same colour at destination
  if (cbptr->board.count(to) > 0 && (cbptr->board[to]->get_team() == team))
    return false;

  //right path
  if (!diag_path(from,to) && !str_path(from,to))
    return false;

  //there is no piece between source and destination squares
  if (cbptr->inBetween(from,to))
    return false;

  //move is successful
  return true;
}
