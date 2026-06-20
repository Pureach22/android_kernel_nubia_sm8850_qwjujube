size_t __fastcall sde_fence_error_ctx_update(size_t result, int a2, int a3)
{
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    *(_DWORD *)(result + 40) = a2;
    *(_DWORD *)(result + 44) = a3;
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid fence\n");
    return sde_evtlog_log(sde_dbg_base_evtlog, "sde_fence_error_ctx_update", 854, -1, a2, a3, 60333, -1059143953, vars0);
  }
  return result;
}
