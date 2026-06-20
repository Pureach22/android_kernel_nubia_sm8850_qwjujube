__int64 __fastcall aw8693x_play_mode(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // x0
  __int64 v4; // x3
  __int64 v5; // x0
  __int64 v6; // x3
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v15; // x3

  if ( a2 > 2u )
  {
    switch ( a2 )
    {
      case 3u:
        printk(&unk_14B30, "haptic_hv", 621, "aw8693x_play_mode");
        v10 = a1;
        v11 = 8;
        v12 = 4294967292LL;
        v13 = 0;
        *(_BYTE *)(a1 + 23) = 3;
LABEL_15:
        i2c_w_bits(v10, v11, v12, v13);
        v7 = a1;
        v8 = 76;
        v9 = 4294967231LL;
        goto LABEL_16;
      case 4u:
        printk(&unk_156A1, "haptic_hv", 629, "aw8693x_play_mode");
        *(_BYTE *)(a1 + 23) = 4;
        i2c_w_bits(a1, 8, 4294967292LL, 2);
        v5 = a1;
        v6 = 4;
        break;
      case 5u:
        printk(&unk_14F65, "haptic_hv", 601, "aw8693x_play_mode");
        *(_BYTE *)(a1 + 23) = 5;
        i2c_w_bits(a1, 8, 4294967292LL, 0);
        v5 = a1;
        v6 = 0;
        break;
      default:
        return printk(&unk_168A0, "haptic_hv", 639, "aw8693x_play_mode");
    }
    i2c_w_bits(v5, 8, 4294967291LL, v6);
    printk(&unk_143C9, "haptic_hv", 510, "aw8693x_bst_mode_config");
    i2c_w_bits(a1, 6, 4294967263LL, 0);
    v7 = a1;
    v8 = 76;
    v9 = 4294967231LL;
    v15 = 64;
    return i2c_w_bits(v7, v8, v9, v15);
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      printk(&unk_14F45, "haptic_hv", 591, "aw8693x_play_mode");
      *(_BYTE *)(a1 + 23) = 1;
      i2c_w_bits(a1, 8, 4294967292LL, 0);
      v3 = a1;
      v4 = 0;
      goto LABEL_14;
    }
    if ( a2 == 2 )
    {
      printk(&unk_164BD, "haptic_hv", 611, "aw8693x_play_mode");
      *(_BYTE *)(a1 + 23) = 2;
      i2c_w_bits(a1, 8, 4294967292LL, 1);
      v3 = a1;
      v4 = 4;
LABEL_14:
      i2c_w_bits(v3, 8, 4294967291LL, v4);
      printk(&unk_16576, "haptic_hv", 504, "aw8693x_bst_mode_config");
      v10 = a1;
      v11 = 6;
      v12 = 4294967263LL;
      v13 = 32;
      goto LABEL_15;
    }
    return printk(&unk_168A0, "haptic_hv", 639, "aw8693x_play_mode");
  }
  printk(&unk_14040, "haptic_hv", 574, "aw8693x_play_mode");
  *(_BYTE *)(a1 + 23) = 0;
  i2c_w_bits(a1, 69, 4294967263LL, 32);
  v7 = a1;
  v8 = 69;
  v9 = 4294967263LL;
LABEL_16:
  v15 = 0;
  return i2c_w_bits(v7, v8, v9, v15);
}
