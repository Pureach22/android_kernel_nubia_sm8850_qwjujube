__int64 __fastcall aw8693x_get_f0(__int64 a1)
{
  int v2; // w8
  char v3; // w20
  __int16 v4; // w9
  unsigned int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w8
  int v8; // w9
  int v9; // w9
  int v10; // w21
  void *v12; // x0
  __int64 v13; // x2
  unsigned int v14; // w8
  unsigned int v15; // w21
  _BYTE v16[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v17; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+11h] [xbp-Fh]
  _WORD v19[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 1128);
  v16[0] = 0;
  *(_DWORD *)(a1 + 96) = v2;
  aw8693x_stop();
  printk(&unk_14A18, "haptic_hv", 525, "aw8693x_vbat_ref_config");
  i2c_w_bits(a1, 77, 4294967183LL, 32);
  i2c_w_bits(a1, 78, 4294967288LL, *(unsigned __int8 *)(a1 + 1173));
  printk(&unk_156A1, "haptic_hv", 629, "aw8693x_play_mode");
  *(_BYTE *)(a1 + 23) = 4;
  i2c_w_bits(a1, 8, 4294967292LL, 2);
  i2c_w_bits(a1, 8, 4294967291LL, 4);
  printk(&unk_143C9, "haptic_hv", 510, "aw8693x_bst_mode_config");
  i2c_w_bits(a1, 6, 4294967263LL, 0);
  i2c_w_bits(a1, 76, 4294967231LL, 64);
  i2c_w_bits(a1, 24, 4294967263LL, 32);
  i2c_w_bits(a1, 29, 4294967167LL, *(unsigned __int8 *)(a1 + 1216) << 7);
  i2c_r_bytes(a1, 8, v16, 1);
  v3 = v16[0];
  i2c_w_bits(a1, 8, 4294967291LL, 4);
  i2c_w_bits(a1, 29, 4294967168LL, *(unsigned __int8 *)(a1 + 1178));
  v4 = *(_WORD *)(a1 + 1184);
  v17 = *(_BYTE *)(a1 + 1179);
  v18 = v4;
  i2c_w_bytes(a1, 30, &v17, 3);
  if ( *(_BYTE *)(a1 + 1187) )
  {
    i2c_w_bytes(a1, 34, a1 + 1187, 1);
    v5 = *(_DWORD *)(a1 + 1128);
    if ( !v5 )
    {
LABEL_3:
      result = 4294967262LL;
      goto LABEL_4;
    }
  }
  else
  {
    printk(&unk_1447C, "haptic_hv", 1245, "aw8693x_get_f0");
    v5 = *(_DWORD *)(a1 + 1128);
    if ( !v5 )
      goto LABEL_3;
  }
  v7 = 0x3A980 / v5;
  v8 = v7 - (*(unsigned __int8 *)(a1 + 1183) + *(unsigned __int8 *)(a1 + 1187)) - 8;
  if ( v8 >= 255 )
    v8 = 255;
  v9 = v8 & ~(v8 >> 31);
  if ( v7 >= 0xFF )
    LOBYTE(v7) = -1;
  v17 = v7;
  LOBYTE(v18) = v9;
  i2c_w_bytes(a1, 25, &v17, 2);
  printk(&unk_14720, "haptic_hv", 471, "aw8693x_play_go");
  LOBYTE(v19[0]) = 1;
  i2c_w_bytes(a1, 9, v19, 1);
  usleep_range_state(20000, 20500, 2);
  v10 = -100;
  while ( 1 )
  {
    LOBYTE(v19[0]) = 0;
    i2c_r_bytes(a1, 63, v19, 1);
    if ( !LOBYTE(v19[0]) )
      break;
    usleep_range_state(2000, 2500, 2);
    if ( __CFADD__(v10++, 1) )
    {
      v12 = &unk_13ECE;
      v13 = 495;
      goto LABEL_16;
    }
  }
  v12 = &unk_1668E;
  v13 = 490;
LABEL_16:
  printk(v12, "haptic_hv", v13, "aw8693x_wait_enter_standby");
  v19[0] = 0;
  i2c_r_bytes(a1, 39, v19, 2);
  v14 = __rev16(v19[0]);
  if ( v14 )
  {
    *(_DWORD *)(a1 + 96) = 0x3A9800 / v14;
    *(_DWORD *)(a1 + 112) = 0x3A9800 / v14;
    printk(&unk_14AD5, "haptic_hv", 1201, "aw8693x_read_f0");
    v15 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 96) = 0;
    printk(&unk_14AA7, "haptic_hv", 1196, "aw8693x_read_f0");
    v15 = -34;
  }
  i2c_w_bits(a1, 24, 4294967263LL, 0);
  i2c_w_bits(a1, 8, 4294967291LL, v3 & 4);
  printk(&unk_14A18, "haptic_hv", 525, "aw8693x_vbat_ref_config");
  i2c_w_bits(a1, 77, 4294967183LL, 64);
  result = v15;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
