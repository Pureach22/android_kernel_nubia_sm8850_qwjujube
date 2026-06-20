__int64 __fastcall aw86320_play_atsin0(int a1, unsigned __int16 a2, int a3)
{
  unsigned int v4; // w20
  __int64 result; // x0
  int v7; // w10
  int v8; // w11
  unsigned int v9; // w20
  int v10; // w10
  unsigned int v11; // w19
  unsigned int v12; // w21
  _BYTE *v13; // x25
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6

  v4 = a2;
  result = printk(&unk_9B85, "aw86320", 566, "aw86320_play_atsin0", (unsigned __int16)a1, a2, (unsigned __int16)a3);
  if ( v4 <= 0x5A && (_WORD)a1 && (unsigned __int16)a3 <= 0x1F4u )
  {
    v7 = *(_DWORD *)(g_aw86320 + 840);
    v8 = *(_DWORD *)(g_aw86320 + 844) << 12;
    *(_DWORD *)(g_aw86320 + 16) = 1;
    v9 = 3538836 * v4 / 0x2800;
    v10 = v8 | (v7 << 14);
    if ( (unsigned __int16)a1 <= 0x3FEu )
      v11 = a1 | 0x2800;
    else
      v11 = 11263;
    v12 = v10 | a3;
    printk(&unk_A220, "aw86320", 588, "aw86320_play_atsin0", (unsigned __int16)v11, v9, (unsigned __int16)v12);
    v13 = (_BYTE *)g_aw86320;
    result = printk(&unk_9D7D, "aw86320", 297, "aw86320_play_mode", v14, v15, v16);
    if ( v13[838] == 1 )
      v13[1] = 1;
    if ( v13[837] == 1 )
      v13[1] = 2;
    if ( *(_BYTE *)(g_aw86320 + 1) == 1 )
    {
      printk(&unk_9CCA, "aw86320", 592, "aw86320_play_atsin0", 1, v17, v18);
      result = aw86320_play_stop(g_aw86320);
      if ( *(_DWORD *)(g_aw86320 + 16) == 1 )
      {
        printk(&unk_A5BA, "aw86320", 595, "aw86320_play_atsin0", v19, v20, v21);
        aw86320_timecheck_work_init(g_aw86320);
        haptic_i2c_write(g_aw86320, 37, 0);
        haptic_i2c_write(g_aw86320, 35, v9);
        haptic_i2c_write(g_aw86320, 36, v12);
        return haptic_i2c_write(g_aw86320, 37, v11);
      }
    }
  }
  return result;
}
