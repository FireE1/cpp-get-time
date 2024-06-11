# cpp-get-time
This is a simple program, that prints time as 'time_t' and 'ctime'. Used as cheat sheet for me to write more complex programs.

## Why you need 'time_t' and 'ctime':
'time_t' format can be used to transfer/compare time between languages, so you dont need to force cast it to **SoMeThInG**. <br />
'ctime' gives you full information about time and date, so you can use it as... calendar?

## Why this program exist:
I was working on pet-project, that represent sending delayed queued messages to multiple social networks at the same time, so content creators can manage their social media convenient and efficient. 'time_t' can be stored in DB,  can be send from client to server and so on.

## Usage:
Pass one of arguments in console, such as ```now, from_now, zero```.

## Build requirements:
- C++17 (STL)
- Clang++ 17
