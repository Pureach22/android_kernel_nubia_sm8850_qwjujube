__int64 __fastcall cam_qup_i3c_poll(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        __int16 a4,
        unsigned int a5,
        unsigned int a6,
        int a7)
{
  int v7; // w19
  unsigned int v8; // w22
  int v13; // w25
  int v14; // w26
  unsigned int v15; // w0
  const char *v16; // x5
  __int64 v17; // x4
  __int64 v18; // x6
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v7 = a7;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(a7 - 101) > 0xFFFFFF9B )
  {
    v8 = -22;
    if ( a5 - 5 >= 0xFFFFFFFC && a6 - 5 >= 0xFFFFFFFC )
    {
      v13 = a3;
      v14 = (unsigned __int16)~a4;
      do
      {
        v20 = 0;
        v15 = cam_qup_i3c_read(a1, a2, &v20, a5, a6);
        if ( (v15 & 0x80000000) != 0 )
        {
          v8 = v15;
        }
        else
        {
          if ( (v20 & v14) == v13 )
            goto LABEL_14;
          v8 = 1;
        }
        usleep_range_state(1000, 1010, 2);
        --v7;
      }
      while ( v7 );
      if ( v8 == 1 )
      {
        v16 = "poll failed rc=%d(non-fatal)";
        v17 = 259;
        v18 = 1;
      }
      else
      {
        if ( (v8 & 0x80000000) == 0 )
        {
LABEL_14:
          v8 = 0;
          goto LABEL_17;
        }
        v16 = "poll failed rc=%d";
        v17 = 261;
        v18 = v8;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i3c_poll",
        v17,
        v16,
        v18);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_poll",
      239,
      "invalid delay = %d max_delay = %d",
      a7,
      100);
    v8 = -22;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v8;
}
