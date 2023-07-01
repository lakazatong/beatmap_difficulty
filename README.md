# beatmap_difficulty
Computes difficulty attributes from .osu files.
## Add to your repo
In your repo root folder
* `git submodule add https://github.com/lakazatong/beatmap_difficulty libs/beatmap_difficulty`
## Include
In your repo
* `#include "libs/beatmap_difficulty/difficulty.h"`

In the libs folder
* `#include "../beatmap_difficulty/difficulty.h"`

## Run isolated test
Uncomment test.c and write your tests, then run:

`make && test.exe`

You would need a way to run make on Windows.
Remove the .exe extension in the Makefile for Linux.
## Update your submodules
* `git submodule update --remote --merge`
## Remove a submodule
* `git submodule deinit -f path/to/submodule`
* `rm -rf .git/modules/path/to/submodule`
* `git rm -f path/to/submodule`

Taken from [here](https://gist.github.com/myusuf3/7f645819ded92bda6677?permalink_comment_id=3915500#gistcomment-3915500).