__int64 __fastcall aw8693x_ram_get_f0(__int64 a1)
{
  char v1; // w8
  void *v3; // x0
  __int64 v4; // x2
  __int64 result; // x0
  char v6; // w21
  int v7; // w20
  void *v9; // x0
  __int64 v10; // x2
  unsigned int v11; // w8
  unsigned int v12; // w20
  unsigned int v13; // w8
  __int64 v14; // x3
  __int64 v15; // x3
  _BYTE v16[4]; // [xsp+0h] [xbp-20h] BYREF
  char v17[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v18[4]; // [xsp+8h] [xbp-18h] BYREF
  char v19[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v20[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(a1 + 6);
  v16[0] = 0;
  if ( (v1 & 1) == 0 )
  {
    v3 = &unk_16977;
    v4 = 1290;
    goto LABEL_5;
  }
  if ( *(unsigned __int8 *)(a1 + 1116) <= 4u )
  {
    v3 = &unk_151A3;
    v4 = 1294;
LABEL_5:
    printk(v3, "haptic_hv", v4, "aw8693x_ram_get_f0");
    result = 4294967262LL;
    goto LABEL_24;
  }
  *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 1128);
  aw8693x_stop(a1);
  i2c_w_bits(a1, 78, 4294967288LL, *(unsigned __int8 *)(a1 + 1173));
  printk(&unk_14F45, "haptic_hv", 591, "aw8693x_play_mode");
  *(_BYTE *)(a1 + 23) = 1;
  i2c_w_bits(a1, 8, 4294967292LL, 0);
  i2c_w_bits(a1, 8, 4294967291LL, 0);
  printk(&unk_16576, "haptic_hv", 504, "aw8693x_bst_mode_config");
  i2c_w_bits(a1, 6, 4294967263LL, 32);
  i2c_w_bits(a1, 76, 4294967231LL, 0);
  i2c_w_bits(a1, 24, 4294967263LL, 32);
  i2c_r_bytes(a1, 8, v16, 1);
  v6 = v16[0];
  i2c_w_bits(a1, 8, 4294967291LL, 4);
  i2c_w_bits(a1, 6, 4294967264LL, 13);
  v17[0] = 5;
  i2c_w_bytes(a1, 10, v17, 1);
  v18[0] = 0;
  i2c_w_bytes(a1, 11, v18, 1);
  i2c_w_bits(a1, 18, 4294967055LL, 32);
  printk(&unk_14720, "haptic_hv", 471, "aw8693x_play_go");
  v19[0] = 1;
  i2c_w_bytes(a1, 9, v19, 1);
  usleep_range_state(20000, 20500, 2);
  v7 = -100;
  while ( 1 )
  {
    v20[0] = 0;
    i2c_r_bytes(a1, 63, v20, 1);
    if ( !v20[0] )
      break;
    usleep_range_state(2000, 2500, 2);
    if ( __CFADD__(v7++, 1) )
    {
      v9 = &unk_13ECE;
      v10 = 495;
      goto LABEL_12;
    }
  }
  v9 = &unk_1668E;
  v10 = 490;
LABEL_12:
  printk(v9, "haptic_hv", v10, "aw8693x_wait_enter_standby");
  v21 = 0;
  i2c_r_bytes(a1, 39, &v21, 2);
  v11 = __rev16(v21);
  if ( v11 )
  {
    *(_DWORD *)(a1 + 96) = 0x3A9800 / v11;
    *(_DWORD *)(a1 + 112) = 0x3A9800 / v11;
    printk(&unk_14AD5, "haptic_hv", 1201, "aw8693x_read_f0");
    v12 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 96) = 0;
    printk(&unk_14AA7, "haptic_hv", 1196, "aw8693x_read_f0");
    v12 = -34;
  }
  v13 = *(unsigned __int8 *)(a1 + 48);
  if ( v13 <= 5 )
    v13 = 5;
  if ( v13 >= 0x19 )
    v14 = 25;
  else
    v14 = v13;
  i2c_w_bits(a1, 6, 4294967264LL, v14);
  i2c_w_bits(a1, 24, 4294967263LL, 0);
  if ( (v6 & 4) != 0 )
    v15 = 4;
  else
    v15 = 0;
  i2c_w_bits(a1, 8, 4294967291LL, v15);
  result = v12;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
