__int64 __fastcall aw22xxx_set_breath_data(__int64 a1, _BYTE *a2)
{
  unsigned __int64 v3; // x20
  __int64 result; // x0
  bool v5; // cf

  v3 = 0;
  byte_58 = a2[8];
  byte_5E = a2[9];
  byte_64 = a2[10];
  byte_6A = a2[11];
  byte_70 = a2[12];
  byte_76 = a2[13];
  byte_7C = a2[14];
  byte_82 = a2[15];
  byte_88 = a2[16];
  byte_8E = a2[17];
  byte_94 = a2[18];
  byte_9A = a2[19];
  byte_A0 = a2[20];
  byte_A6 = byte_A0;
  byte_AC = byte_A0;
  byte_B2 = a2[21];
  byte_B8 = byte_B2;
  byte_BE = byte_B2;
  byte_C4 = a2[22];
  byte_CA = byte_C4;
  byte_D0 = byte_C4;
  byte_D6 = a2[23];
  byte_DC = byte_D6;
  byte_E2 = byte_D6;
  duration = a2[24];
  do
  {
    result = aw22xxx_i2c_write(a1, aw22xxx_blink_cfg[v3], aw22xxx_blink_cfg[v3 + 1]);
    v5 = v3 >= 0x92;
    v3 += 2LL;
  }
  while ( !v5 );
  return result;
}
