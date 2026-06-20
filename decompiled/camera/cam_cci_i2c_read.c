__int64 __fastcall cam_cci_i2c_read(__int64 *a1, __int64 a2, _DWORD *a3, int a4, int a5, char a6)
{
  unsigned int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 (*v9)(void); // x8
  char v10; // w22
  __int64 (*v12)(void); // x9
  __int64 v13; // x2
  __int64 v14; // x4

  v6 = -22;
  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)(a4 - 5) >= 0xFFFFFFFC && (unsigned int)(a5 - 5) >= 0xFFFFFFFC )
  {
    v7 = *a1;
    if ( v7 )
    {
      v8 = **(_QWORD **)(v7 + 160);
      if ( v8 && (v9 = *(__int64 (**)(void))(v8 + 56)) != nullptr )
      {
        v10 = a6;
        if ( !v4l2_subdev_call_wrappers || (v12 = *(__int64 (**)(void))(v4l2_subdev_call_wrappers + 56LL)) == nullptr )
          v12 = v9;
        if ( *((_DWORD *)v12 - 1) != 1356305480 )
          __break(0x8229u);
        v6 = v12();
        a6 = v10;
        if ( (v6 & 0x80000000) == 0 )
        {
          v6 = 0;
          *a3 = 0;
          goto LABEL_19;
        }
      }
      else
      {
        v6 = -515;
      }
    }
    else
    {
      v6 = -19;
    }
    if ( (a6 & 1) != 0 )
    {
      v13 = 3;
      v14 = 39;
    }
    else
    {
      v13 = 1;
      v14 = 41;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x4000000000LL,
      v13,
      "cam_cci_i2c_read",
      v14,
      "rc = %d",
      v6);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v6;
}
