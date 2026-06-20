__int64 __fastcall sde_crtc_vblank_notify_work(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v4; // x0
  __int64 v5; // x21
  int v6; // w7
  __int64 v7; // x0
  _QWORD *v8; // x8
  _QWORD *v9; // x1
  __int64 v10; // x2
  __int64 v11; // x9
  char v13; // [xsp+0h] [xbp+0h]

  v1 = a1[5];
  if ( !v1 )
    return printk(&unk_25E167, "sde_crtc_vblank_notify_work");
  v2 = a1[8];
  if ( *(_QWORD *)(v1 + 4424) )
    ++*(_DWORD *)(v1 + 4408);
  else
    *(_QWORD *)(v1 + 4424) = v2;
  v4 = *(_QWORD *)(v1 + 4496);
  *(_QWORD *)(v1 + 4432) = v2;
  kernfs_notify(v4);
  drm_crtc_handle_vblank(v1);
  v5 = v2 / 1000;
  _drm_dev_dbg(0, 0, 5, "crtc%d, ts:%llu\n", *(_DWORD *)(v1 + 112), v5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_crtc_vblank_notify",
    3531,
    -1,
    *(_DWORD *)(v1 + 112),
    v5,
    -1059143953,
    v6,
    v13);
  v7 = raw_spin_lock_irqsave(v1 + 6036);
  v8 = a1 + 6;
  v9 = *(_QWORD **)(v1 + 6024);
  v10 = v1 + 6016;
  v11 = v7;
  if ( a1 + 6 == (_QWORD *)(v1 + 6016) || v9 == v8 || *v9 != v10 )
  {
    _list_add_valid_or_report(a1 + 6, v9);
  }
  else
  {
    *(_QWORD *)(v1 + 6024) = v8;
    a1[6] = v10;
    a1[7] = v9;
    *v9 = v8;
  }
  return raw_spin_unlock_irqrestore(v1 + 6036, v11);
}
