# Side Effects

A method to make a function which has side effects into a pure function.

## Why

If you have a legacy code base, it's likely that your functions can't be unit tested without mocking a bunch of objects.  This is an alternate strategy that guards all of your "impure" code to optionally not run.  For regular production use, you pass in callback functions that are called to perform the state changes.  For unit testing, you don't pass in the functions.

## Instructions

Depends on which code you want to run.  See the README files in each subdirectory of the project

## License

MIT License

Copyright (c) [2016] [David Roberts]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Contribute

Feed free to send me a pull request or open an issue on github.
