__int64 __fastcall sub_67B374(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int128 *v3; // x18

  __ldaxp(v3);
  return wmi_unified_set_enable_disable_mcc_adaptive_scheduler_cmd(a1, a2, a3);
}
