#include <Arduino.h>
#include <IRremote.h>
#include <stdio.h>

IRrecv receiver(5);
decode_results results;


 
// Function to reverse bits of num
unsigned int reverseBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++) {
        if ((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
    }
    return reverse_num;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  receiver.enableIRIn();

  Serial.println("Waiting for ir codes :D");
      Serial.println((reverseBits(receiver.decodedIRData.command)>>17) | (reverseBits(receiver.decodedIRData.address)>>24), HEX);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(receiver.decode())
  {
    Serial.println(receiver.decodedIRData.command, HEX);
    Serial.println(receiver.decodedIRData.address, HEX);
    Serial.println(receiver.decodedIRData.numberOfBits);
    Serial.println((reverseBits(receiver.decodedIRData.command)>>17) | (reverseBits(receiver.decodedIRData.address)>>24), HEX);
    Serial.println("");
    receiver.resume();
  }
}