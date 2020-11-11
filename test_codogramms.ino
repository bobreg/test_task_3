#define len_cmd 10
#define len_pack_1 5
#define len_pack_2 5
#define len_pack_3 4
//byte cmd[len_cmd] = {0x76, 0x78, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x31, 0xB9};
//byte cmd[len_cmd] = {0x76, 0x77, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09 , 0x99, 0x82};
byte pack1[len_pack_1] = {0x76, 0x77, 0x00, 0x01, 0x02};
byte pack2[len_pack_2] = {0x03, 0x04, 0x05, 0x06, 0x07};
byte pack3[len_pack_3] = {0x08, 0x09 , 0x99, 0x82};


void setup() {
  Serial.begin(115200);
  

}

void loop() {
  //Serial.write(cmd, len_cmd);
  Serial.write(pack1, len_pack_1);
  delay(10);
  Serial.write(pack2, len_pack_2);
  delay(30);
  Serial.write(pack3, len_pack_3);
  delay(60);
}
