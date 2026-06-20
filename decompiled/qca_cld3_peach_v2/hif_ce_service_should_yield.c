__int64 __fastcall hif_ce_service_should_yield(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x23
  unsigned __int64 v6; // x20

  v4 = sched_clock();
  v5 = *(_QWORD *)(a2 + 192);
  v6 = v4;
  if ( v4 <= v5 )
  {
    if ( (hif_max_num_receives_reached(a1, *(unsigned int *)(a2 + 208)) & 1) == 0 )
      return 0;
    *(_DWORD *)(a2 + 208) = 1024;
  }
  if ( *(_BYTE *)(a2 + 273) == 1 )
  {
    if ( (unsigned int)hif_napi_enabled(a1, *(unsigned int *)(a2 + 8)) )
      ((void (__fastcall *)(__int64, bool, bool))hif_napi_update_yield_stats)(a2, v6 > v5, v6 <= v5);
  }
  return 1;
}
