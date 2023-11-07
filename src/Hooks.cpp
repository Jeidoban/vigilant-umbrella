#include "Hooks.h"

namespace Hooks
{
    void Install() noexcept
    {
        REL::Relocation target{ REL::ID(153728), 0x04 };
        stl::write_thunk_call<UpdateMagazineAmmoCount>(target.address());
    }
} // namespace Hooks

// ID: 153728
// OFF: 0x04
