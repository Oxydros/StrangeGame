//
// Created by Louis Ventre on 7/23/17.
//

#ifndef STRANGEGAME_CATEGORY_HPP
#define STRANGEGAME_CATEGORY_HPP

namespace Category
{
    enum Type : unsigned int
    {
        None = 0,
        Scene = 1 << 0,
        PlayerAircraft = 1 << 1,
        AlliedAircraft = 1 << 2,
        EnemyAircraft = 1 << 3,
    };
}

#endif //STRANGEGAME_CATEGORY_HPP
