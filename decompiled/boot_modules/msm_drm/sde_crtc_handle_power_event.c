__int64 __fastcall sde_crtc_handle_power_event(int a1, int *a2)
{
  int v4; // w7
  __int64 v5; // x0
  int *v6; // x25
  __int64 i; // x20
  unsigned int (__fastcall *v8)(int *, __int64, int *); // x8
  __int64 v9; // x8
  __int64 *j; // x20
  __int64 v11; // x8
  __int64 *k; // x20
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x0
  int *v16; // x25
  __int64 m; // x20
  _DWORD *v18; // x8
  __int64 result; // x0
  char v20; // [xsp+0h] [xbp-20h]
  int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( !a2 )
  {
    result = printk(&unk_25E167, "sde_crtc_handle_power_event");
    goto LABEL_43;
  }
  mutex_lock(a2 + 1154);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_handle_power_event", 6109, -1, a2[28], a1, -1059143953, v4, v20);
  if ( a1 > 7 )
  {
    if ( a1 == 16 )
    {
      v13 = *(_QWORD *)(*(_QWORD *)a2 + 56LL);
      if ( v13 )
      {
        v14 = *(_QWORD *)(v13 + 8);
        if ( v14 )
        {
          v22[0] = sde_power_mmrm_get_requested_clk((int)v13 + 16, *(char **)(v14 + 1992));
          sde_crtc_event_notify((__int64 *)a2, -2147483637, (int *)v22, 8);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "crtc[%d]: MMRM cb notified clk:%lu\n", a2[28], v22[0]);
        }
        else
        {
          printk(&unk_27D28A, "sde_crtc_mmrm_cb_notification");
        }
      }
      else
      {
        printk(&unk_220A59, "sde_crtc_mmrm_cb_notification");
      }
      goto LABEL_42;
    }
    if ( a1 == 8 )
    {
      v5 = raw_spin_lock_irqsave(a2 + 1508);
      v6 = *((int **)a2 + 575);
      for ( i = v5; v6 != a2 + 1150; v6 = *(int **)v6 )
      {
        v8 = *((unsigned int (__fastcall **)(int *, __int64, int *))v6 - 1);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != 1979947765 )
            __break(0x8228u);
          if ( v8(a2, 1, v6 - 12) )
            printk(&unk_25E58F, "sde_crtc_handle_power_event");
        }
      }
      raw_spin_unlock_irqrestore(a2 + 1508, i);
      v9 = *(_QWORD *)a2;
      for ( j = *(__int64 **)(*(_QWORD *)a2 + 816LL); j != (__int64 *)(v9 + 816); j = (__int64 *)*j )
      {
        if ( ((*(_DWORD *)(*((_QWORD *)a2 + 251) + 20LL) >> *((_DWORD *)j + 15)) & 1) != 0 )
        {
          sde_encoder_virt_restore(j - 1);
          v9 = *(_QWORD *)a2;
        }
      }
      sde_core_perf_crtc_update_uidle(a2, 1);
      sde_cp_crtc_post_ipc(a2);
      goto LABEL_42;
    }
LABEL_16:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "event:%d not handled\n", a1);
    goto LABEL_42;
  }
  if ( a1 == 1 )
  {
    v11 = *(_QWORD *)a2;
    for ( k = *(__int64 **)(*(_QWORD *)a2 + 816LL); k != (__int64 *)(v11 + 816); k = (__int64 *)*k )
    {
      if ( ((*(_DWORD *)(*((_QWORD *)a2 + 251) + 20LL) >> *((_DWORD *)k + 15)) & 1) != 0 )
      {
        sde_encoder_idle_pc_enter(k - 1);
        v11 = *(_QWORD *)a2;
      }
    }
    v15 = raw_spin_lock_irqsave(a2 + 1508);
    v16 = *((int **)a2 + 575);
    for ( m = v15; v16 != a2 + 1150; v16 = *(int **)v16 )
    {
      v18 = *((_DWORD **)v16 - 1);
      if ( v18 )
      {
        if ( *(v18 - 1) != 1979947765 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(int *, _QWORD, int *))v18)(a2, 0, v16 - 12) )
          printk(&unk_268BC8, "sde_crtc_handle_power_event");
      }
    }
    raw_spin_unlock_irqrestore(a2 + 1508, m);
    sde_cp_crtc_pre_ipc(a2);
    goto LABEL_42;
  }
  if ( a1 != 2 )
    goto LABEL_16;
  sde_crtc_reset_sw_state((unsigned __int64 *)a2);
  sde_cp_crtc_suspend(a2);
  v21 = 0;
  sde_crtc_event_notify((__int64 *)a2, -2147483644, &v21, 4);
LABEL_42:
  result = mutex_unlock(a2 + 1154);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
