__int64 __fastcall cam_sensor_cci_i2c_util(__int64 *a1)
{
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 (*v3)(void); // x8
  __int64 (*v4)(void); // x9
  unsigned int v5; // w19

  _ReadStatusReg(SP_EL0);
  v1 = *a1;
  if ( !v1 )
  {
    v5 = -19;
    goto LABEL_13;
  }
  v2 = **(_QWORD **)(v1 + 160);
  if ( !v2 || (v3 = *(__int64 (**)(void))(v2 + 56)) == nullptr )
  {
    v5 = -515;
LABEL_13:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_sensor_cci_i2c_util",
      245,
      "Failed rc = %d",
      v5);
    goto LABEL_14;
  }
  if ( !v4l2_subdev_call_wrappers || (v4 = *(__int64 (**)(void))(v4l2_subdev_call_wrappers + 56LL)) == nullptr )
    v4 = v3;
  if ( *((_DWORD *)v4 - 1) != 1356305480 )
    __break(0x8229u);
  v5 = v4();
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_13;
  v5 = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v5;
}
