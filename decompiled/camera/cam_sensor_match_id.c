__int64 __fastcall cam_sensor_match_id(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 result; // x0
  int v4; // w10
  __int64 v5; // x20
  int v6; // w10
  unsigned int v7; // w10
  int v8; // w9
  unsigned __int16 v9; // w9
  int v10; // w8
  unsigned int v11; // w10
  unsigned int v12; // w21
  __int64 v13; // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+8h] [xbp-18h]
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 3656);
  v15 = 0;
  if ( v1 )
  {
    v2 = a1 + 4096;
    if ( (*(_BYTE *)(a1 + 7632) & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      v4 = *(_DWORD *)(a1 + 6480);
      v5 = a1;
      if ( v4 == 1 )
      {
        v7 = *(_DWORD *)(a1 + 7592);
        if ( v7 )
        {
          if ( (debug_mdl & 0x20) != 0 && !debug_priority )
          {
            v14 = a1 + 4096;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x20,
              4,
              "cam_sensor_match_id",
              1251,
              "%s read id: 0x%x -> 0x%x",
              (const char *)(a1 + 7560),
              2 * *(unsigned __int16 *)(*(_QWORD *)(a1 + 6496) + 20LL),
              v7);
            v2 = v14;
            v7 = *(_DWORD *)(v5 + 7592);
            a1 = v5;
          }
          *(_WORD *)(*(_QWORD *)(a1 + 6496) + 20LL) = v7 >> 1;
        }
      }
      else if ( v4 == 2 )
      {
        v6 = *(_DWORD *)(a1 + 7592);
        if ( v6 )
        {
          if ( (debug_mdl & 0x20) != 0 && !debug_priority )
          {
            v13 = a1 + 4096;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x20,
              4,
              "cam_sensor_match_id",
              1243,
              "%s read id: 0x%x -> 0x%x",
              (const char *)(a1 + 7560),
              *(unsigned __int16 *)(**(_QWORD **)(a1 + 6488) + 2LL),
              v6);
            v2 = v13;
            v6 = *(_DWORD *)(v5 + 7592);
            a1 = v5;
          }
          *(_WORD *)(**(_QWORD **)(a1 + 6488) + 2LL) = v6;
        }
      }
      result = camera_io_dev_read(
                 a1 + 6480,
                 *(unsigned int *)(v1 + 4),
                 &v15,
                 *(unsigned __int8 *)(v2 + 2944),
                 *(unsigned __int8 *)(v2 + 2945),
                 1);
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
      {
        v12 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_match_id",
          1264,
          "%s read id: 0x%x expected id 0x%x:",
          (const char *)(v5 + 7560),
          v15,
          *(_DWORD *)(v1 + 8));
        result = v12;
      }
      if ( (unsigned __int16)*(_DWORD *)(*(_QWORD *)(v5 + 3656) + 12LL) )
        v8 = *(_DWORD *)(*(_QWORD *)(v5 + 3656) + 12LL);
      else
        v8 = -1;
      v10 = v8 & -v8;
      v9 = v8 & v15;
      LOWORD(v10) = v10 - 1;
      if ( (_WORD)v10 )
      {
        do
        {
          v11 = (unsigned __int16)v10;
          v10 = (__int16)v10 >> 1;
          v9 >>= 1;
        }
        while ( v11 > 1 );
      }
      if ( *(_DWORD *)(v1 + 8) != v9 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          32,
          2,
          "cam_sensor_match_id",
          1269,
          "%s read id: 0x%x expected id 0x%x:",
          v5 + 7560);
        result = 4294967277LL;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_match_id",
      1232,
      " failed: %pK",
      nullptr);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
