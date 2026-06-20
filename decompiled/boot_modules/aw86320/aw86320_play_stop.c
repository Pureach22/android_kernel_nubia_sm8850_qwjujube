__int64 __fastcall aw86320_play_stop(_BYTE *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v8; // w20
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  void *v13; // x0
  __int64 v14; // x2
  __int64 result; // x0
  __int16 v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  aw86320_play_mode(a1, 0, a3, a4, a5, a6, a7);
  v8 = -100;
  while ( 1 )
  {
    v16 = 0;
    haptic_i2c_read(a1, 20, &v16);
    if ( (v16 & 0xF00) == 0 )
      break;
    usleep_range_state(2000, 2500, 2);
    if ( __CFADD__(v8++, 1) )
    {
      v13 = &unk_95B6;
      v14 = 550;
      goto LABEL_7;
    }
  }
  v13 = &unk_A33E;
  v14 = 544;
LABEL_7:
  result = printk(v13, "aw86320", v14, "aw86320_wait_enter_standby", v9, v10, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
