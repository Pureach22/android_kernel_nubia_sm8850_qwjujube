__int64 __fastcall sub_2157AC(long double a1, long double a2, long double a3, float a4)
{
  __int64 v4; // x21

  LOWORD(a4) = *(_WORD *)(v4 + 744);
  return wmi_unified_process_ll_stats_set_cmd(a1, a2, a3, a4);
}
