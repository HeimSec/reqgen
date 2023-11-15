# reqgen - Python Requirements Generator

reqgen is a command-line utility that generates a 'requirements.txt' file listing installed Python packages in your environment.<br>
It provides a simple interface to view dependencies or create the 'requirements.txt' file effortlessly.

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
--ansi_colors or -c: Displays soon the all possible ANSI color constants also wich one used in the program.

### Contributions
Contributions and feature requests are welcome!<br>
Please feel free to open an issue or submit a pull request.

### License
This project is licensed under the MIT License.
