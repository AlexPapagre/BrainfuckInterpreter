# Brainfuck Interpreter

This is a Brainfuck Interpreter written in C. It supports all standard Brainfuck commands and handles input/output with proper memory management.

---

## Features

- Supports Brainfuck commands: `><+-.,[]`
- Dynamic command buffer resizing
- Proper input handling for `,` commands
- Error handling for memory and range issues
- Supports input from file or standard input

---

## Usage

### Compile

To compile the project, run:

```bash
make
```

This will build the program and create an executable file called `bf`.

---

### Run (Mode 1)

Enter Brainfuck code manually via standard input:

```bash
./bf
```

You'll be prompted to type your code. Press `Enter` after an empty row when you're done.

---

### Run (Mode 2)

Run a Brainfuck program from a file.

For example, if you have a file called `helloWorld.bf` inside the `sample_bf_code` directory:

```bash
./bf sample_bf_code/helloWorld.bf
```

---

### Clean

Remove the compiled executable file `bf`:

```bash
make clean
```

Use this if you want to rebuild from scratch or delete the executable entirely.

---

## Brainfuck Commands

Brainfuck is a minimalist programming language with only 8 commands. These commands operate on an array of memory cells (usually bytes) and a data pointer that moves along the cells. Understanding these commands is key to writing and reading Brainfuck programs.


<table>
    <thead>
        <tr>
            <th style="text-align:center;">Character</th>
            <th style="text-align:center;">Instruction Performed</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="text-align:center;">&gt;</td>
            <td style="text-align:left;">Increment the data pointer by one (to point to the next cell to the right).</td>
        </tr>
        <tr>
            <td style="text-align:center;">&lt;</td>
            <td style="text-align:left;">Decrement the data pointer by one (to point to the next cell to the left).</td>
        </tr>
        <tr>
            <td style="text-align:center;">+</td>
            <td style="text-align:left;">Increment the byte at the data pointer by one.</td>
        </tr>
        <tr>
            <td style="text-align:center;">-</td>
            <td style="text-align:left;">Decrement the byte at the data pointer by one.</td>
        </tr>
        <tr>
            <td style="text-align:center;">.</td>
            <td style="text-align:left;">Output the byte at the data pointer.</td>
        </tr>
        <tr>
            <td style="text-align:center;">,</td>
            <td style="text-align:left;">Accept one byte of input, storing its value in the byte at the data pointer.</td>
        </tr>
        <tr>
            <td style="text-align:center;">[</td>
            <td style="text-align:left;">If the byte at the data pointer is zero,<br>then instead of moving the instruction pointer forward to the next command,<br>jump it forward to the command after the matching ] command.</td>
        </tr>
        <tr>
            <td style="text-align:center;">]</td>
            <td style="text-align:left;">If the byte at the data pointer is nonzero,<br>then instead of moving the instruction pointer forward to the next command,<br>jump it back to the command after the matching [ command.</td>
        </tr>
    </tbody>
</table>

---

## Example: Hello World

Here’s a classic Brainfuck program that prints **"Hello World!"**:

```brainfuck
>+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.>>>++++++++[<++++>-]<.>>>++++++++++[<+++++++++>-]<---.<<<<.+++.------.--------.>>+.
```

### How it works

- The code uses a loop (`[ ]`) to efficiently set initial values in memory cells.
- The pointer (`>`, `<`) moves between cells to set up ASCII codes for characters.
- The `+` and `-` commands increment or decrement cell values.
- The `.` command outputs the current cell’s ASCII character.
- Together, these commands print "Hello World!" one character at a time.

---

## Example: Simple Input/Output Test

This simple Brainfuck program takes 8 characters as input and immediately outputs them back.

```brainfuck
,.,.,.,.,.,.,.,.
```

### How it works

- The `,` command reads one character from user input into the current cell.
- The `.` command outputs the character stored in the current cell.
- This program repeats the sequence 8 times, reading and then immediately outputting each character.
