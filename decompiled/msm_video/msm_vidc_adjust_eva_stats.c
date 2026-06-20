__int64 __fastcall msm_vidc_adjust_eva_stats(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 v4; // x4

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 8048);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          22,
          119,
          "msm_vidc_adjust_eva_stats")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_DWORD *)(a1 + 1828) == 2 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_88A6E, "high", a1 + 340, "msm_vidc_adjust_eva_stats", v4);
    }
    v3 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
    a1,
    22,
    v3,
    "msm_vidc_adjust_eva_stats");
  return 0;
}
