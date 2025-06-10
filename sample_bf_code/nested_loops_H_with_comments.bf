++              # Set cell0 = 2 (outer loop counter)
[
    >+++        # Set cell1 = 3 (middle loop counter)
    [
        >++++   # Set cell2 = 4 (inner loop counter)
        [
            >+  # Increment cell3 (accumulator)
            <-  # Decrement cell2 (inner loop counter)
        ]
        <-      # Decrement cell1 (middle loop counter)
    ]
    <-          # Decrement cell0 (outer loop counter)
]
>>>             # Move pointer to cell3
++++++++++++++++++++++++++++++++++++++++++++++++  # Add 48 to cell3 (to get ASCII 72 'H')
.               # Output cell3 ('H')