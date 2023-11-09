#pragma once

// Define your hook classes here
namespace Hooks
{
    void Install() noexcept; // Declaring our install function here.

    /*
     * Step 2: This is the class that contains our custom code. A lot of this
     * is boilerplate that I think SFSE needs to function and inject our code.
     * Basically I just changed the class name to be something that resembles
     * the function we're hooking into, which is updating the amount of ammo
     * in the magazine.
     */
    class UpdateMagazineAmmoCount : public Singleton<UpdateMagazineAmmoCount>
    {
    public:
        /*
         * Step 3: This is where our custom code is written. Essentially what is going on here is
         * we are writing a function that is going to be injected into the game's code (in memory at runtime).
         * SFSE handles most of the hard stuff of actually getting your code injected, but from what I understand,
         * SFSE creates something called a trampoline which overwrites a "call" instruction (in assembly) using the address of
         * your custom function instead of the original function. You can then make your code do whatever you want.
         *
         * In this case we are overwriting a function that takes three parameters, and we really know what the second one does.
         * (which is the new amount of ammo in a magazine after firing a weapon).
         */
        static std::int64_t thunk(std::int64_t probablyAPointer, std::int32_t newAmmoAmount, std::uint32_t noIdea)
        {
            // RE::ConsoleLog::GetSingleton()->Print("First arg: %d. Second arg: %d, Third arg: %d", probablyAPointer, newAmmoAmount, noIdea);
            if (newAmmoAmount == 1) {
                return func(probablyAPointer, 2, noIdea);
            }

            return func(probablyAPointer, newAmmoAmount, noIdea);
        }

        inline static REL::Relocation<decltype(thunk)> func;
    };

} // namespace Hooks
