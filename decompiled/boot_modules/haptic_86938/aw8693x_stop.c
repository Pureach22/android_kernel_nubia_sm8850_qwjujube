__int64 __fastcall aw8693x_stop(__int64 a1)
{
  int v2; // w20
  __int64 result; // x0
  char v5[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_14A18, "haptic_hv", 681, "aw8693x_stop");
  *(_BYTE *)(a1 + 23) = 0;
  v5[0] = 1;
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  usleep_range_state(500, 600, 2);
  i2c_w_bits(a1, 8, 4294967292LL, 3);
  i2c_w_bytes(a1, 9, v5, 1);
  i2c_w_bits(a1, 69, 4294967291LL, 0);
  v2 = -100;
  while ( 1 )
  {
    v6[0] = 0;
    i2c_r_bytes(a1, 63, v6, 1);
    if ( !v6[0] )
      break;
    usleep_range_state(2000, 2500, 2);
    if ( __CFADD__(v2++, 1) )
    {
      printk(&unk_13ECE, "haptic_hv", 495, "aw8693x_wait_enter_standby");
      printk(&unk_15A7C, "haptic_hv", 692, "aw8693x_stop");
      printk(&unk_14040, "haptic_hv", 574, "aw8693x_play_mode");
      *(_BYTE *)(a1 + 23) = 0;
      i2c_w_bits(a1, 69, 4294967263LL, 32);
      result = i2c_w_bits(a1, 69, 4294967263LL, 0);
      goto LABEL_7;
    }
  }
  result = printk(&unk_1668E, "haptic_hv", 490, "aw8693x_wait_enter_standby");
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
