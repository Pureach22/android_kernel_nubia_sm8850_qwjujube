__int64 __fastcall sde_encoder_display_failure_notification(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x8
  unsigned int v10; // w6
  int v11; // w5
  __int64 v14; // x0
  unsigned int v15; // w8
  char v17; // [xsp+0h] [xbp+0h]

  if ( !a1 || !*(_QWORD *)a1 || (v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    printk(&unk_27D28A, "sde_encoder_display_failure_notification");
    return (unsigned int)-22;
  }
  v9 = *(_QWORD *)(a1 + 1360);
  if ( !v9 )
  {
    v10 = -22;
    if ( (_drm_debug & 4) == 0 )
      return v10;
    v11 = 1;
    goto LABEL_15;
  }
  v10 = *(_DWORD *)(v9 + 160);
  if ( v10 > 0xF )
  {
    if ( (_drm_debug & 4) == 0 )
      return (unsigned int)-22;
    v11 = 0;
LABEL_15:
    _drm_dev_dbg(0, 0, 0, "enc%d invalid cached CRTC: %d or crtc index: %d\n", *(_DWORD *)(a1 + 24), v11, v10);
    return (unsigned int)-22;
  }
  v14 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_display_failure_notification",
          9020,
          4,
          *(_DWORD *)(a1 + 24),
          -1059143953,
          v10,
          a8,
          v17);
  v15 = *(_DWORD *)(*(_QWORD *)(a1 + 1360) + 160LL);
  if ( v15 < 0x11 )
  {
    if ( (a2 & 1) != 0 )
    {
      sde_encoder_helper_switch_vsync(a1, 1);
      return 0;
    }
    else
    {
      *(_BYTE *)(a1 + 4920) = 1;
      kthread_queue_work(v8 + 80LL * v15 + 2432, a1 + 1104);
      kthread_flush_work(a1 + 1104);
      sde_encoder_helper_switch_vsync(a1, 1);
      sde_encoder_wait_for_event(a1, 1u);
      v10 = 0;
      *(_BYTE *)(a1 + 4920) = 0;
    }
    return v10;
  }
  __break(0x5512u);
  return sde_encoder_recovery_events_enabled(v14);
}
