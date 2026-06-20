__int64 __fastcall cam_wrapper_icc_get(__int64 a1, int a2, int a3, const char *a4, char a5)
{
  __int64 v7; // x22
  const char *v8; // x23
  char v9; // w24
  __int64 result; // x0
  __int64 v11; // x19
  _QWORD v12[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v13[3]; // [xsp+18h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v13[1] = 0;
  v12[0] = 0;
  v12[1] = 0;
  if ( (debug_bypass_drivers & 0x10) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_icc_get",
      25,
      "Bypass icc get for %d %d",
      a2,
      a3);
    result = 3735928559LL;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v7 = a1;
      v8 = a4;
      v9 = a5;
      ktime_get_real_ts64(v13);
      a1 = v7;
      a5 = v9;
      a4 = v8;
    }
    result = cam_icc_get_path(a1, a2, a3, a4, a5 & 1);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v11 = result;
      ktime_get_real_ts64(v12);
      result = v11;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
