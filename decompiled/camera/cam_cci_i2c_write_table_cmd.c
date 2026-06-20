__int64 __fastcall cam_cci_i2c_write_table_cmd(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x11
  __int64 v4; // x8
  __int64 (*v5)(void); // x8
  __int64 (*v7)(void); // x9
  __int64 v8; // x0

  v2 = -22;
  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
    goto LABEL_20;
  if ( (unsigned int)(*(_DWORD *)(a2 + 12) - 5) < 0xFFFFFFFC || (unsigned int)(*(_DWORD *)(a2 + 16) - 5) < 0xFFFFFFFC )
  {
    v2 = -22;
    goto LABEL_20;
  }
  v3 = *(_QWORD *)(a1 + 16);
  if ( !*(_QWORD *)v3 )
  {
    v2 = -19;
    goto LABEL_19;
  }
  v4 = **(_QWORD **)(*(_QWORD *)v3 + 160LL);
  if ( !v4 || (v5 = *(__int64 (**)(void))(v4 + 56)) == nullptr )
  {
    v2 = -515;
LABEL_19:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_cci_i2c_write_table_cmd",
      135,
      "Failed rc = %d",
      v2);
    goto LABEL_20;
  }
  if ( !v4l2_subdev_call_wrappers || (v7 = *(__int64 (**)(void))(v4l2_subdev_call_wrappers + 56LL)) == nullptr )
    v7 = v5;
  if ( *((_DWORD *)v7 - 1) != 1356305480 )
    __break(0x8229u);
  v2 = v7();
  if ( (v2 & 0x80000000) != 0 )
    goto LABEL_19;
  v8 = *(unsigned __int16 *)(a2 + 20);
  v2 = 0;
  if ( (unsigned int)v8 < 0x15 )
  {
    if ( *(_WORD *)(a2 + 20) )
      usleep_range_state(
        1000LL * *(unsigned __int16 *)(a2 + 20),
        1000 * (unsigned int)*(unsigned __int16 *)(a2 + 20) + 1000,
        2);
  }
  else
  {
    msleep(v8);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v2;
}
