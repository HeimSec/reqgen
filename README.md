# reqgen - Python Requirements Generator

"reqgen" is a command-line utility designed to simplify the management of Python project dependencies by automating the generation of a requirements.txt file.

## Why 'reqgen' | The conceptual idea
Managing project dependencies in Python can be complex, especially when working on multiple projects or collaborating with a team. <br>**"reqgen"** streamlines this process by offering...<br>
**Effortless Dependency Tracking**: <br>View, analyze, and create/update a requirements.txt file effortlessly.<br>
**Consistency Across Environments**: <br>Ensures consistent dependency installation across different development environments or deployment stages.<br>
**Time-Saving Automation**: <br>Automates the process of listing installed Python packages, reducing manual efforts and potential errors.<br>
**Simplified Replication**: <br>Facilitates replicating projects by specifying the exact set of dependencies and versions.<br>
<br>
> reqgen aims to provide a convenient interface for developers, making it easier to manage, track, and share project dependencies, enhancing overall development efficiency.
<br>
**View Dependencies**: <br>Analyze installed packages and their counts in the Python environment.<br>

**Generate 'requirements.txt'**: <br>Create or update a requirements.txt file listing all installed packages.<br>

**Effortless Management**: <br>Easily replicate project environments by sharing or using the requirements.txt file.<br>

## Screenshot
![reqgen](https://raw.githubusercontent.com/HeimSec/reqgen/main/ironcore%40lab_%20%7E_Development_Requirements-File-Generator%2015.11.2023%2023_23_24.png)


## Usage

To compile and use reqgen, follow these steps:

### Compilation

1. Clone the repository:

    ```bash
    git clone https://github.com/HeimSec/reqgen.git
    cd reqgen
    ```

2. Compile the code:

    ```bash
    gcc -o reqgen reqgen.c
    ```

### Running the Utility

Run the executable `reqgen`:

```bash
./reqgen
```

### This will prompt you with a menu to choose.
Analyze: Displays the total count of installed dependencies.<br>
Create: Generates a 'requirements.txt' file with installed Python packages.<br>
Exit: Closes the program.

### Flags
--ansi_colors or -c: Displays the eastereg that output all possible ANSI color constants also wich one used in the program.^^

### Contributions
Contributions and feature requests are welcome!<br>
Please feel free to open an issue or submit a pull request.

### License
This project is licensed under the MIT License.
