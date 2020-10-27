#pragma once

namespace CardValue
{
    enum class Type {
        One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
    };

    static const Type All[] = { Type::One, Type::Two, Type::Three, Type::Four, Type::Five, Type::Six,
                                Type::Seven, Type::Eight, Type::Nine, Type::Ten, Type::Jack, Type::Queen, Type::King, Type::Ace };
}