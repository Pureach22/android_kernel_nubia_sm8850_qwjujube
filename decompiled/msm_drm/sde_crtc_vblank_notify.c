__int64 __fastcall sde_crtc_vblank_notify(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w7
  int v7; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( *(_QWORD *)(a1 + 4424) )
    ++*(_DWORD *)(a1 + 4408);
  else
    *(_QWORD *)(a1 + 4424) = a2;
  v4 = *(_QWORD *)(a1 + 4496);
  *(_QWORD *)(a1 + 4432) = a2;
  kernfs_notify(v4);
  drm_crtc_handle_vblank(a1);
  v5 = a2 / 1000;
  _drm_dev_dbg(0, 0, 5, "crtc%d, ts:%llu\n", *(_DWORD *)(a1 + 112), v5);
  if ( a1 )
    v7 = *(_DWORD *)(a1 + 112);
  else
    v7 = -1;
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_vblank_notify", 3531, -1, v7, v5, -1059143953, v6, vars0);
}
