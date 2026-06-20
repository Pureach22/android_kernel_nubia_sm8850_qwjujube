__int64 __fastcall target_if_cp_stats_enable_cstats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    result = wmi_unified_pdev_param_send(v10);
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: wmi_handle is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_cp_stats_enable_cstats");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
