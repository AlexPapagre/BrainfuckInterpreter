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

```bash
make
```

---

### Run 1 (enter code through user input in stdin)

```bash
./bf
```

---

### Run 2 (enter filename with bf code)

Example for file `helloWorld.bf`.

```bash
./bf helloWorld.bf
```

---

## Commands

Here’s how the 8 Brainfuck commands work.


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
            <td style="text-align:left;">If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command,<br>jump it forward to the command after the matching ] command.</td>
        </tr>
        <tr>
            <td style="text-align:center;">]</td>
            <td style="text-align:left;">If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command,<br>jump it back to the command after the matching [ command.</td>
        </tr>
    </tbody>
</table>
