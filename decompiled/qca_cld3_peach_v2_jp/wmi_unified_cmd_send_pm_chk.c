__int64 __fastcall wmi_unified_cmd_send_pm_chk(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0

  if ( (a5 & 1) == 0
    || (wmi_is_qmi_stats_enabled(a1) & 1) == 0
    || !wmi_is_target_suspended(a1)
    || (result = wmi_unified_cmd_send_over_qmi(a1, a2, a3, a4), (_DWORD)result) )
  {
    *(_DWORD *)(a1 + 888) = 0;
    return wmi_unified_cmd_send_fl(
             a1,
             a2,
             a3,
             a4,
             "wmi_unified_cmd_send_pm_chk",
             0x400u,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13);
  }
  return result;
}
