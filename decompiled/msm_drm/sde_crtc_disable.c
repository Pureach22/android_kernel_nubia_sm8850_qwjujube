__int64 __fastcall sde_crtc_disable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x25
  __int64 v4; // x23
  __int64 v5; // x26
  __int64 v6; // x1
  int v7; // w7
  int v8; // w6
  int v9; // w7
  unsigned int v10; // w8
  __int64 v11; // x0
  _QWORD *v12; // x27
  __int64 i; // x20
  _DWORD *v14; // x8
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  int v20; // w6
  int v21; // w7
  __int64 v22; // x8
  __int64 *v23; // x20
  __int64 v24; // x8
  __int64 *j; // x21
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 v28; // x20
  __int64 v29; // x21
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x21
  __int64 v33; // x20
  __int64 v34; // x0
  __int64 v35; // x20
  __int64 result; // x0
  void *v37; // x0
  char v38; // [xsp+0h] [xbp-30h]
  char v39; // [xsp+0h] [xbp-30h]
  int v40; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+28h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  if ( !a1 || (v1 = *(_QWORD *)a1) == 0 || (v3 = *(_QWORD *)(v1 + 56)) == 0 || (v4 = *(_QWORD *)(a1 + 2008)) == 0 )
  {
    v37 = &unk_25E167;
LABEL_68:
    result = printk(v37, "sde_crtc_disable");
    goto LABEL_69;
  }
  v5 = *(_QWORD *)(v3 + 8);
  if ( !v5 )
  {
    printk(&unk_234896, "_sde_crtc_get_kms");
    v37 = &unk_234896;
    goto LABEL_68;
  }
  if ( (*(_WORD *)(*(_QWORD *)(v1 + 8) + 488LL) & 7) != 0 )
  {
    v37 = &unk_24FBDF;
    goto LABEL_68;
  }
  v6 = *(_QWORD *)(a1 + 2008);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "crtc%d\n", *(_DWORD *)(a1 + 112));
    v6 = *(_QWORD *)(a1 + 2008);
  }
  if ( (unsigned int)sde_crtc_get_intf_mode((__int64 *)a1, v6) - 5 <= 0xFFFFFFFD )
  {
    if ( *(_QWORD *)(a1 + 5488) == a1 + 5488 )
      kthread_flush_work(a1 + 5440);
    if ( *(_QWORD *)(a1 + 5560) == a1 + 5560 )
      kthread_flush_work(a1 + 5512);
    if ( *(_QWORD *)(a1 + 5632) == a1 + 5632 )
      kthread_flush_work(a1 + 5584);
    if ( *(_QWORD *)(a1 + 5704) == a1 + 5704 )
      kthread_flush_work(a1 + 5656);
    if ( *(_QWORD *)(a1 + 5776) == a1 + 5776 )
      kthread_flush_work(a1 + 5728);
    if ( *(_QWORD *)(a1 + 5848) == a1 + 5848 )
      kthread_flush_work(a1 + 5800);
    if ( *(_QWORD *)(a1 + 5920) == a1 + 5920 )
      kthread_flush_work(a1 + 5872);
    if ( *(_QWORD *)(a1 + 5992) == a1 + 5992 )
      kthread_flush_work(a1 + 5944);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_crtc_flush_vblank_events",
      5472,
      -1,
      *(_DWORD *)(a1 + 112),
      8738,
      -1059143953,
      v7,
      v38);
    drm_crtc_vblank_off(a1);
  }
  mutex_lock(a1 + 4616);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_disable", 6228, 4, *(_DWORD *)(a1 + 112), -1059143953, v8, v9, v38);
  sde_cp_crtc_suspend(a1);
  mutex_unlock(a1 + 4616);
  v10 = *(_DWORD *)(a1 + 160);
  if ( v10 >= 0x10 )
    goto LABEL_74;
  kthread_flush_worker(v3 + 80LL * v10 + 2432);
  mutex_lock(a1 + 4616);
  kthread_cancel_delayed_work_sync(a1 + 7776);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_crtc_disable",
    6240,
    -1,
    *(_DWORD *)(a1 + 112),
    *(unsigned __int8 *)(a1 + 4512),
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 2008) + 9LL),
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 2008) + 8LL),
    *(_DWORD *)(a1 + 7872));
  *(_BYTE *)(a1 + 4512) = 0;
  *(_DWORD *)(a1 + 7872) = 0;
  sde_core_perf_crtc_update_uidle(a1, 0);
  if ( *(_DWORD *)(a1 + 4712) )
  {
    printk(&unk_268B97, "sde_crtc_disable");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_crtc_disable",
      6251,
      -1,
      *(_DWORD *)(a1 + 112),
      *(_DWORD *)(a1 + 4712),
      17476,
      -1059143953,
      v39);
    sde_core_perf_crtc_release_bw(a1);
    *(_DWORD *)(a1 + 4712) = 0;
  }
  v11 = raw_spin_lock_irqsave(a1 + 6032);
  v12 = *(_QWORD **)(a1 + 4600);
  for ( i = v11; v12 != (_QWORD *)(a1 + 4600); v12 = (_QWORD *)*v12 )
  {
    v14 = (_DWORD *)*(v12 - 1);
    if ( v14 )
    {
      if ( *(v14 - 1) != 1979947765 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD *))v14)(a1, 0, v12 - 6) )
        printk(&unk_268BC8, "sde_crtc_disable");
    }
  }
  v15 = raw_spin_unlock_irqrestore(a1 + 6032, i);
  v22 = *(_QWORD *)a1;
  v23 = *(__int64 **)(*(_QWORD *)a1 + 816LL);
  if ( v23 != (__int64 *)(*(_QWORD *)a1 + 816LL) )
  {
    do
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(a1 + 2008) + 20LL) >> *((_DWORD *)v23 + 15)) & 1) != 0 )
      {
        v15 = sde_encoder_in_cont_splash(v23 - 1);
        if ( (_DWORD)v15 )
          goto LABEL_45;
        v22 = *(_QWORD *)a1;
      }
      v23 = (__int64 *)*v23;
    }
    while ( v23 != (__int64 *)(v22 + 816) );
  }
  if ( !*(_QWORD *)(a1 + 8016) )
    v15 = sde_core_perf_crtc_update(a1, 4);
LABEL_45:
  v24 = *(_QWORD *)a1;
  *(_QWORD *)(a1 + 8016) = 0;
  for ( j = *(__int64 **)(v24 + 816); j != (__int64 *)(v24 + 816); j = (__int64 *)*j )
  {
    if ( ((*(_DWORD *)(*(_QWORD *)(a1 + 2008) + 20LL) >> *((_DWORD *)j + 15)) & 1) != 0 )
    {
      v15 = sde_encoder_register_frame_event_callback(j - 1, 0, 0);
      *(_QWORD *)(v4 + 472) = 0;
      *(_BYTE *)(v4 + 480) = 0;
      if ( (*(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x200) != 0 )
        v15 = sde_encoder_control_idle_pc(j - 1, 1);
    }
    v24 = *(_QWORD *)a1;
  }
  v26 = *(_QWORD *)(a1 + 7384);
  if ( v26 )
  {
    if ( !*(_DWORD *)(v3 + 5912) )
      v15 = sde_power_handle_unregister_event(v3 + 16);
    *(_QWORD *)(a1 + 7384) = 0;
  }
  v27 = *(_QWORD *)(a1 + 2008);
  if ( *(_BYTE *)(v27 + 9) == 1 && (*(_BYTE *)(v27 + 8) & 1) != 0 )
    goto LABEL_64;
  if ( (*(_QWORD *)(a1 + 7928) & 1) == 0 )
    goto LABEL_58;
  v28 = *(_QWORD *)(a1 + 2208);
  if ( !v28 )
  {
    if ( (_drm_debug & 4) != 0 )
      v15 = _drm_dev_dbg(0, 0, 0, "invalid crtc params %d\n", 0);
LABEL_58:
    v28 = 0;
  }
  v29 = *(_QWORD *)(a1 + 3232);
  v30 = ktime_get(v15);
  v31 = sde_fence_signal(v29, v30, 1, v28);
  if ( *(int *)(v4 + 464) >= 1 )
  {
    v32 = 0;
    while ( v32 != 16 )
    {
      v33 = *(_QWORD *)(v4 + 336 + 8 * v32);
      v34 = ktime_get(v31);
      v31 = sde_connector_commit_reset(v33, v34);
      if ( ++v32 >= *(int *)(v4 + 464) )
        goto LABEL_64;
    }
LABEL_74:
    __break(0x5512u);
  }
LABEL_64:
  v35 = *(_QWORD *)(a1 + 2008);
  sde_crtc_clear_cached_mixer_cfg(a1, v26, v16, v17, v18, v19, v20, v21);
  memset((void *)(a1 + 2200), 0, 0x180u);
  *(_DWORD *)(a1 + 2192) = 0;
  *(_BYTE *)(a1 + 2196) = 0;
  *(_WORD *)(v35 + 481) = 0;
  *(_BYTE *)(v35 + 6920) = 0;
  sde_crtc_static_img_control((_DWORD *)a1, 0, 0);
  sde_cp_crtc_disable(a1);
  v40 = 0;
  sde_crtc_event_notify((__int64 *)a1, -2147483646, &v40, 4);
  if ( *(_BYTE *)(a1 + 7924) == 1 )
  {
    *(_DWORD *)(a1 + 7920) = 0;
    *(_QWORD *)(a1 + 7912) = 0;
  }
  result = mutex_unlock(a1 + 4616);
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
