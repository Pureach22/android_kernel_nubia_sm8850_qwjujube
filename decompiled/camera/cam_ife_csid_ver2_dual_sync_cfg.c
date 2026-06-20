__int64 __fastcall cam_ife_csid_ver2_dual_sync_cfg(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w8

  if ( a1 )
  {
    *(_DWORD *)(a1 + 32240) = *a2;
    *(_DWORD *)(a1 + 32196) = a2[1];
    v2 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_dual_sync_cfg",
        8512,
        "CSID[%u] sync_mode %d dual_core_idx: %d",
        *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_dual_sync_cfg",
      8502,
      "Invalid args %pK  %pK",
      nullptr,
      a2);
    return (unsigned int)-22;
  }
  return v2;
}
