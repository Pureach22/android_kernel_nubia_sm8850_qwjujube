__int64 __fastcall sde_encoder_clear_fence_error_in_progress(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v9; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result && (v8 = *(_QWORD *)result) != 0 && (v9 = *(_QWORD *)(v8 + 80)) != 0 )
  {
    if ( (*(_BYTE *)(result + 2308) & 1) == 0 && !*(_DWORD *)(v9 + 7940) && *(_BYTE *)(result + 2328) == 1 )
    {
      *(_BYTE *)(result + 2328) = 0;
      return sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_clear_fence_error_in_progress",
               2512,
               -1,
               *(_DWORD *)(v8 + 24),
               0,
               -1059143953,
               a8,
               vars0);
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    return _drm_dev_dbg(0, 0, 0, "invalid sde_encoder_phys.\n");
  }
  return result;
}
