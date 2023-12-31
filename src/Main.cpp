#include "Hooks.h"
#include "Settings.h"

// Hi random person that is reading this code, if you're here to see how I made this
// plugin, check out the README.md file for a more detailed explanation of what's going on.
// However I will try point out the order of what's going on. Follow along with the steps!

// SFSE message listener, use this to do stuff at specific moments during runtime
void Listener(SFSE::MessagingInterface::Message* message) noexcept
{
    if (message->type <=> SFSE::MessagingInterface::kPostLoad == 0) {
    }
    if (message->type <=> SFSE::MessagingInterface::kPostPostLoad == 0) {
        // Settings::LoadSettings();

        /*
         * Step 1: This is where the code I wrote starts. The rest of this page was pre-generated by the CommonlibSF template.
         * This is where my custom code is loaded, which is loaded in (installed) after you get into the actual gameplay of Starfield.
         * These if statements are essentially different points of loading where SFSE can load your code. In most cases I think
         * this is where you want to install your hooks.
         *
         * Go ahead to the Hooks.h file to go to the next step!
         */
        Hooks::Install();
    }
    if (message->type <=> SFSE::MessagingInterface::kPostDataLoad == 0) {
    }
}

// Main SFSE plugin entry point, initialize everything here
SFSEPluginLoad(const SFSE::LoadInterface* sfse)
{
    Init(sfse);

    logger::info("{} {} is loading...", Plugin::Name, Plugin::Version.string());

    if (const auto messaging{ SFSE::GetMessagingInterface() }; !messaging->RegisterListener(Listener))
        return false;

    logger::info("{} has finished loading.", Plugin::Name);

    return true;
}
