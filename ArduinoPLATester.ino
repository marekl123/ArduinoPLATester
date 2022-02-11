/*
 * Arduino PLA logic tester
 */

#define RCLK   10
#define SRCLK  11
#define SRDATA 12
#define CE     13

 // Array defining the inputs of the PLA
char arPLAin[30][16]  = { 
  { 'x', '1', '1', 'x', 'x', '1', '0', '1', 'x', 'x', '0', '1', 'x', '1', 'x', 'x' }, // p0
  { 'x', 'x', '1', 'x', 'x', '1', '1', '1', 'x', 'x', '0', '1', 'x', '1', 'x', 'x' }, // p1
  { 'x', 'x', '1', 'x', 'x', '1', '1', '1', 'x', 'x', '0', '1', '0', '0', 'x', 'x' }, // p2
  { 'x', 'x', '1', '0', 'x', '1', '1', '0', '1', 'x', '0', '1', 'x', '1', 'x', 'x' }, // p3
  { 'x', '1', 'x', '0', 'x', '1', '1', '0', '1', 'x', '0', '1', 'x', '1', 'x', 'x' }, // p4
  { 'x', 'x', '1', '0', 'x', '1', '1', '0', '1', 'x', '0', '1', '0', '0', 'x', 'x' }, // p5
  { 'x', 'x', 'x', 'x', '1', 'x', 'x', 'x', 'x', 'x', '1', 'x', 'x', '1', '0', '1' }, // p6
  { 'x', 'x', 'x', 'x', '1', 'x', 'x', 'x', 'x', 'x', '1', 'x', '0', '0', '0', '1' }, // p7
  { 'x', 'x', '1', '1', 'x', '1', '1', '0', '1', '1', '0', '1', 'x', '1', 'x', 'x' }, // p9
  { 'x', 'x', '1', '1', 'x', '1', '1', '0', '1', 'x', '0', '0', 'x', '1', 'x', 'x' }, // p10
  { 'x', '1', 'x', '1', 'x', '1', '1', '0', '1', '1', '0', '1', 'x', '1', 'x', 'x' }, // p11
  { 'x', '1', 'x', '1', 'x', '1', '1', '0', '1', 'x', '0', '0', 'x', '1', 'x', 'x' }, // p12
  { 'x', 'x', '1', '1', 'x', '1', '1', '0', '1', '1', '0', '1', '0', '0', 'x', 'x' }, // p13
  { 'x', 'x', '1', '1', 'x', '1', '1', '0', '1', 'x', '0', '0', '0', '0', 'x', 'x' }, // p14
  { 'x', '1', 'x', '1', 'x', '1', '1', '0', '1', '1', '0', '1', '0', '0', 'x', 'x' }, // p15
  { 'x', '1', 'x', '1', 'x', '1', '1', '0', '1', 'x', '0', '0', '0', '0', 'x', 'x' }, // p16
  { 'x', 'x', 'x', 'x', 'x', '1', '1', '0', '1', '1', '0', '1', '1', '0', 'x', 'x' }, // p17
  { 'x', 'x', 'x', 'x', 'x', '1', '1', '0', '1', 'x', '0', '0', '1', '0', 'x', 'x' }, // p18
  { 'x', '1', '1', 'x', 'x', '1', '0', '0', 'x', 'x', '0', '1', '0', 'x', 'x', 'x' }, // p19
  { 'x', 'x', 'x', 'x', 'x', '1', '0', '0', 'x', 'x', '0', 'x', '1', '0', 'x', 'x' }, // p20
  { 'x', 'x', '1', 'x', 'x', '1', '0', '1', 'x', 'x', '0', '1', '0', '0', 'x', 'x' }, // p21
  { 'x', 'x', 'x', 'x', 'x', '1', '1', '1', 'x', 'x', '0', 'x', '1', '0', 'x', 'x' }, // p22
  { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '1', 'x', '1', '0', '1', '1' }, // p23
  { 'x', 'x', 'x', 'x', 'x', '0', '0', 'x', '1', 'x', 'x', 'x', '1', '0', 'x', 'x' }, // p24
  { 'x', 'x', 'x', 'x', 'x', '0', '0', '1', 'x', 'x', 'x', 'x', '1', '0', 'x', 'x' }, // p25
  { 'x', 'x', 'x', 'x', 'x', '0', '1', 'x', 'x', 'x', 'x', 'x', '1', '0', 'x', 'x' }, // p26
  { 'x', 'x', 'x', 'x', 'x', '1', '0', '1', 'x', 'x', 'x', 'x', '1', '0', 'x', 'x' }, // p27
  { 'x', 'x', 'x', 'x', 'x', '1', '1', '0', '0', 'x', 'x', 'x', '1', '0', 'x', 'x' }, // p28
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p30
  { '0', 'x', 'x', 'x', 'x', '1', '1', '0', '1', 'x', '0', '0', 'x', 'x', 'x', 'x' }, // p31
};

// Array defining the outputs of the PLA  
char arPLAout[30][8]  = { 
  { '1', '0', 'x', 'x', 'x', 'x', 'x', 'x' }, // p0
  { '1', 'x', '0', 'x', 'x', 'x', 'x', 'x' }, // p1
  { '1', 'x', '0', 'x', 'x', 'x', 'x', 'x' }, // p2
  { '1', 'x', 'x', '0', 'x', 'x', 'x', 'x' }, // p3
  { '1', 'x', 'x', '0', 'x', 'x', 'x', 'x' }, // p4
  { '1', 'x', 'x', '0', 'x', 'x', 'x', 'x' }, // p5
  { '1', 'x', 'x', '0', 'x', 'x', 'x', 'x' }, // p6
  { '1', 'x', 'x', '0', 'x', 'x', 'x', 'x' }, // p7
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p9
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p10
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p11
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p12
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p13
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p14
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p15
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p16
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p17
  { '1', 'x', 'x', 'x', 'x', '0', 'x', 'x' }, // p18
  { '1', 'x', 'x', 'x', 'x', 'x', '0', 'x' }, // p19
  { '1', 'x', 'x', 'x', 'x', 'x', '0', 'x' }, // p20
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', '0' }, // p21
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', '0' }, // p22
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', '0' }, // p23
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p24
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p25
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p26
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p27
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p28
  { '1', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }, // p30
  { 'x', 'x', 'x', 'x', '0', 'x', 'x', 'x' }, // p31
};

void setup() {

  Serial.begin(57600);

  pinMode(RCLK, OUTPUT);   // Storage register clock (RCLK / STCP) D10
  pinMode(SRCLK, OUTPUT);  // Shift register clock (SRCLK / SHCP)  D11
  pinMode(SRDATA, OUTPUT); // Serial input (SRDATA / DS)           D12
  pinMode(CE, OUTPUT);     // Chip enable of the PLA (CE)          D13

  // Set Arduino inputs that will receive PLA outputs
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {

  int failed = 0;

  Serial.println();
  // Loop though all of the test cases (y in the matrix)
  for (int y=0; y<30;y++) 
  {
    // Disable the PLA chip by setting Chip Enable pin to HIGH
    digitalWrite(CE, true);
    
    // Set the Storage register clock (RCLK / STCP) on D10 to LOW
    // This makes sure we will not be putting anything on the storage register.
    digitalWrite(RCLK, false);

    Serial.print("Test case ");
    if (y<10) Serial.print('0');
    Serial.print(y + 1);
    Serial.print(": ");

    String actualTestcase = "xxxxxxxxxxxxxxxx";
    
    // Push all of the values from the current test case into the shift register
    for (int x=0; x<16; x++)
    {
      // Set the shift register clock (SRCLK / SHCP) on D11 to LOW
      digitalWrite(SRCLK, false);

      // Set the data bit according to contents of the array (SRDATA / DS) on D12
      if (arPLAin[y][x] == '1') {
        digitalWrite(SRDATA, true);
        actualTestcase.setCharAt(x, '1');

      }
      else if (arPLAin[y][x] == '0') {
        digitalWrite(SRDATA, false);
        actualTestcase.setCharAt(x, '0');
      }
      else {
        // When X write TRUE (FALSE would be OK as well)
        digitalWrite(SRDATA, true);
        actualTestcase.setCharAt(x, '1');
      }
      Serial.print(arPLAin[y][x]);


      // Wait a bit (50 uS)
      delayMicroseconds(50);

      // Set the shift register clock (SRCLK / SHCP) on D11 to HIGH
      // The value on SRDATA should be shifted on the rising clock pulse.
      digitalWrite(SRCLK, true);

      // Wait a bit (50 uS)
      delayMicroseconds(50);
    }

    Serial.println();
    Serial.print("Actual test : ");
    Serial.println(actualTestcase);
    Serial.println();

    // Set the shift  register clock (SRCLK / SHCP) on D11 to LOW
    digitalWrite(SRCLK, false);

    // Set the Storage register clock (RCLK / STCP) on D10 to HIGH
    // This will output the contents of the shift register to the storage register
    // And also to the PLA inputs, because with have OE of the LSHC595 chip connected to GND.
    digitalWrite(RCLK, true);

    // Enable the PLA chip by setting Chip Enable pin to LOW
    digitalWrite(CE, false);
    
    // Wait a bit (50 uS)
    delayMicroseconds(50);

    // Set the Storage register clock (RCLK / STCP) on D10 to LOW
    digitalWrite(RCLK, false);

    // Wait a bit (50 uS)
    delayMicroseconds(50);

    String expected = "xxxxxxxx";
    String tested = "xxxxxxxx";
    String actual = "xxxxxxxx";
    
    // Store expected output in a string (to be compared later)
    for (int x=0; x<8; x++) {
      expected[x] = arPLAout[y][x];
    }
    
    // Check if the testcase triggered the correct outputs and store the result in a string
    for (int x=0; x<8; x++) {
        int i = digitalRead(x+2);
        if (arPLAout[y][x] == 'x') {
          tested.setCharAt(x,'x');
        }
        else {
          // Convert integer 0 / 1 to character '0' / '1'
          tested.setCharAt(x, i + 48);
        }
        actual.setCharAt(x, i + 48);
    }

    Serial.print("Expected:");
    Serial.println(expected);
    Serial.print("Tested  :");
    Serial.println(tested);
    Serial.print("Actual  :");
    Serial.println(actual);

    if(expected == tested) {
      Serial.println("PASSED!");
    }
    else {
      Serial.println("FAILED!");
      failed++;
    }
    Serial.println();

    // Delay 50 us before next test.
    delayMicroseconds(50);

  }

  if (failed > 0) {
    Serial.print(failed);
    Serial.println(" TESTS FAILED!");
  }
  else {
    Serial.println("ALL TESTS PASSED!");
  }
  // Disable the Chip Enable on the PLA chip (set HIGH)
  digitalWrite(CE, true);

  // Halt
  while(1);
}
