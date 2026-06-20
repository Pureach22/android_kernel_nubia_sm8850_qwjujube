__int64 __fastcall cam_cci_i2c_poll(
        __int64 *a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        int a5,
        int a6,
        unsigned int a7)
{
  unsigned int v7; // w19
  unsigned int v12; // w25
  unsigned __int16 v13; // w24
  unsigned __int16 v14; // w25
  int v15; // w28
  int v16; // w24
  __int16 v17; // w26
  unsigned int v18; // w0
  int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v7 = a7;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    v13 = a3;
    v14 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_cci_i2c_poll",
      208,
      "addr: 0x%x data: 0x%x dt: %d",
      a2,
      a3,
      a5);
    a3 = v13;
    a4 = v14;
    if ( v7 > 0x64 )
      goto LABEL_4;
  }
  else if ( a7 > 0x64 )
  {
LABEL_4:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_cci_i2c_poll",
      212,
      "invalid delay = %d max_delay = %d",
      v7,
      100);
    v12 = -22;
    goto LABEL_19;
  }
  if ( v7 )
  {
    v15 = a4;
    v16 = a3;
    v17 = ~a4;
    do
    {
      v20 = 0;
      v18 = cam_cci_i2c_read(a1, a2, &v20, a6, a5, 0);
      if ( (v18 & 0x80000000) != 0 )
      {
        v12 = v18;
      }
      else
      {
        if ( (unsigned __int16)(v20 & v17) == v16 )
          goto LABEL_18;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x4000000000LL,
          2,
          "cam_cci_i2c_compare",
          193,
          "mismatch: reg_data 0x%x: data: 0x%x, data_mask: 0x%x",
          (unsigned __int16)v20,
          v16,
          v15);
        v12 = 1;
      }
      usleep_range_state(1000, 1010, 2);
      --v7;
    }
    while ( v7 );
    if ( v12 == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_cci_i2c_poll",
        226,
        "poll failed rc=%d(non-fatal)",
        1);
      goto LABEL_19;
    }
    if ( (v12 & 0x80000000) == 0 )
    {
LABEL_18:
      v12 = 0;
      goto LABEL_19;
    }
  }
  else
  {
    v12 = -22;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_cci_i2c_poll",
    229,
    "poll failed rc=%d",
    v12);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v12;
}
