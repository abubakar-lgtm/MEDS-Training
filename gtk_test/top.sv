module top(
    input logic a,
    input logic b,
    input logic cin,
    output logic sum,
    output logic cout
);

    // Full Adder logic
    always_comb begin
        sum = a ^ b ^ cin;    // Sum is XOR of a, b, and cin
        cout = (a & b) | (b & cin) | (cin & a); // Carry out logic
    end

endmodule
