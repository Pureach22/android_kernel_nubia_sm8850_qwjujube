__int64 __fastcall sde_encoder_phys_phys_self_refresh_helper(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _QWORD **v8; // x20
  int v9; // w6
  int v10; // w7
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  unsigned int v14; // w5
  int v15; // w4
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v8 = (_QWORD **)(a1 - 2544);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_phys_self_refresh_helper",
    8415,
    2,
    4369,
    -1059143953,
    a7,
    a8,
    vars0);
  if ( !v8 || (v11 = *v8) == nullptr || !*v11 || (v12 = *(_QWORD *)(*v11 + 56LL)) == 0 )
  {
    printk(&unk_27D28A, "sde_encoder_phys_phys_self_refresh_helper");
    return 0;
  }
  v13 = v11[170];
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 + 160);
    if ( v14 <= 0xF )
    {
      kthread_queue_work(v12 + 80LL * v14 + 1152, v11 + 143);
      return 0;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      v15 = 0;
LABEL_11:
      _drm_dev_dbg(0, 0, 0, "invalid cached CRTC: %d or crtc index: %d\n", v15, v14);
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    v14 = -22;
    v15 = 1;
    goto LABEL_11;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_phys_self_refresh_helper",
    8430,
    -1,
    60333,
    -1059143953,
    v9,
    v10,
    vars0a);
  return 0;
}
