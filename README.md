# rootchecker
Checks if the user is root in C. Created as a Proof of Concept.

## ABOUT
This is a simple program I wrote in C that just is a euid checker for Linux.
It doesn't do much however, theoretically, an attacker can use a similarly designed block of code to potentially do some pretty malicious things if a user is detected as running the program as root.
In the function if we look at the following lines 26-48, there is a check for a user's EUID.
```
switch (env.euid) {
  case 0:
    // we can execute some nasty stuff now...
    fprintf(stderr, "you really... you're root...\n");
    timeout;
    fprintf(stderr, "now we can do nasty things like start system processes, "
                    "overwrite system files, some pretty malicious stuff.\n");
    timeout;
    fprintf(stderr, "This is only a theoretical program however, I wouldn't do "
                    "such a thing.\n");
    break;

  default:
    // do a normal thing...
    fprintf(stderr, "You aren't root huh.\n");
    timeout;
    fprintf(stderr,
            "You can't do too much here. If I were a malicious program, I "
            "would just do a normal non-malicious process.\n");
    break;
  }
```
If you're running the program as a user, you will get the `default` case which in our case, lets the user know they aren't root. However, if we were to run the program as `root` we see that the program runs case `0` which prints out a completely different message.

In a real world scenario, case `0` may contain calls to functions containing malicious code, starting unwanted services, etc. 
## Why upload this?
I want a good looking portfolio :)
Just kidding, partially. I uploaded this as a proof of concept for security amateurs and reverse engineers to analyze so it can aid in malware analysis. Typically, when we use precompiled software, we are unable to see what happens inside the program we're running. The only way we can see what's happening is if we run a debugger or use a decompiler to reverse engineer the code, and take a look at what exactly the computer is doing at runtime. The code I uploaded is designed not to do anything except print out a couple of strings and check a users `euid`. However, the savvy computer user will check the binary and see what's going on. This was uploaded for the user to compile, and analyze what's happening inside the program.
