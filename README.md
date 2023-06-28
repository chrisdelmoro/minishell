<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/minishell/blob/main/resources/repo/minishellm.png" alt="Logo" width="150" height="150">

  <p align="center">
    This project objective is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed the student has to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Bonus-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-101-blue"/>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The Minishell project object is to write a shell that replicates several features and behavior of the Bourne Again Shell (BASH).

The features we are required to implement are:
1. Display a prompt when waiting for a new command.
2. Have a working history.
3. Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
4. Not use more than one global variable.
5. Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).
6. Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
7. Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
8. Implement redirections:
    * ```<``` should redirect input.
    * ```>``` should redirect output.
    * ```<<``` should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
    * ```>>``` should redirect output in append mode.
9. Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
10. Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.
11. Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.
12. Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
13. In interactive mode:
    * ```ctrl-C``` displays a new prompt on a new line.
    * ```ctrl-D``` exits the shell.
    * ```ctrl-\``` does nothing.
14. Implement the following builtins:
    * ```echo``` with option -n.
    * ```cd``` with only a relative or absolute path.
    * ```pwd``` with no options.
    * ```export``` with no options.
    * ```unset``` with no options.
    * ```env``` with no options or arguments.
    * ```exit``` with no options.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Clone the repo and make it to compile. Run the binary located at the /bin folder with random number as parameters. The program will
print several instructions on the terminal representing each action that eventually will sort the stack of numbers you prodived as parameters.
You will probably need a visualizer program to actually validate the final stack order. There are several visualizers on github and even online ones.

Here's a few:
* https://github.com/o-reo/push_swap_visualizer
* https://push-swap-visualizer.vercel.app/


<p align="right">(<a href="#top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html).

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmor@gmail.com

Project Link: [https://github.com/chrisdelmoro/minishell](https://github.com/chrisdelmoro/minishell)

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->