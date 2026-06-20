__int64 __fastcall sde_crtc_complete_flip(__int64 *a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x20
  const void *v8; // x5
  int v9; // w6
  int v10; // w7
  int v11; // w4
  char v13; // [xsp+0h] [xbp+0h]

  v2 = *a1;
  v5 = raw_spin_lock_irqsave(*a1 + 424);
  v6 = a1[323];
  v7 = v5;
  if ( v6 && (!a2 || *(_QWORD *)(v6 + 32) == a2) )
  {
    v8 = (const void *)a1[323];
    a1[323] = 0;
    _drm_dev_dbg(0, 0, 5, "%s: send event: %pK\n", (const char *)a1 + 2176, v8);
    if ( a1 )
      v11 = *((_DWORD *)a1 + 28);
    else
      v11 = -1;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_complete_flip", 3431, 4, v11, -1059143953, v9, v10, v13);
    drm_crtc_send_vblank_event(a1, v6);
  }
  return raw_spin_unlock_irqrestore(v2 + 424, v7);
}
