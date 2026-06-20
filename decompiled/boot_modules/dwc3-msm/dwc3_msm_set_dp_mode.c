__int64 __fastcall dwc3_msm_set_dp_mode(__int64 a1, char a2, int a3)
{
  __int64 v3; // x19
  __int64 v6; // x0
  int v7; // w8
  int v8; // w9
  int v9; // w8
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x9
  _DWORD *v14; // x9
  unsigned int started; // w20
  __int64 v17; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 || !*(_QWORD *)(v3 + 40) )
  {
    dev_err(a1, "dwc3-msm is not initialized yet.\n");
    return 4294967285LL;
  }
  flush_work(v3 + 568);
  _flush_workqueue(*(_QWORD *)(v3 + 648));
  ipc_log_string(
    *(_QWORD *)(v3 + 1256),
    "%s: DP: cur_state:%d new_state:%d lanes:%d\n",
    "dwc3_msm_set_dp_mode",
    *(_DWORD *)(v3 + 2572),
    a2 & 1,
    a3);
  if ( (a2 & 1) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v3 + 1256),
      "%s: DP not connected, refcnt:%d\n",
      "dwc3_msm_set_dp_mode",
      *(_DWORD *)(v3 + 2568));
    mutex_lock(v3 + 1080);
    v7 = *(_DWORD *)(v3 + 2568);
    v8 = *(_DWORD *)(v3 + 696);
    *(_BYTE *)(v3 + 1232) = 0;
    v9 = v7 - 1;
    *(_DWORD *)(v3 + 2572) = 1;
    *(_DWORD *)(v3 + 2568) = v9;
    if ( v8 == 4 )
    {
      if ( !v9 )
        dwc3_start_stop_host(v3, 0);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v3 + 1256), "%s: resetting params for USB ss\n", "dwc3_msm_clear_dp_only_params");
      v12 = *(_QWORD *)(v3 + 456);
      *(_BYTE *)(v3 + 1232) = 0;
      if ( v12 )
        *(_DWORD *)(v12 + 16) &= ~0x200u;
      phy_set_mode_ext(*(_QWORD *)(v3 + 480), 0, 1);
      v13 = *(_QWORD *)(v3 + 40);
      if ( v13 )
        v14 = (_DWORD *)(*(_QWORD *)(v13 + 168) + 1232LL);
      else
        v14 = (_DWORD *)(v3 + 1128);
      *v14 = *(_DWORD *)(v3 + 1132);
      usb_redriver_notify_disconnect(*(_QWORD *)(v3 + 464));
    }
    v17 = *(_QWORD *)(v3 + 456);
    if ( v17 )
      *(_DWORD *)(v17 + 16) &= ~0x400u;
    phy_set_mode_ext(*(_QWORD *)(v3 + 480), 1, 1);
    mutex_unlock(v3 + 1080);
    return 0;
  }
  v6 = *(_QWORD *)(v3 + 1256);
  if ( *(_DWORD *)(v3 + 2572) != a3 )
  {
    ipc_log_string(v6, "%s: Set DP lanes:%d refcnt:%d\n", "dwc3_msm_set_dp_mode", a3, *(_DWORD *)(v3 + 2568));
    if ( a3 == 2 )
    {
      if ( (*(_BYTE *)(v3 + 736) & 1) == 0 )
      {
        msleep(20);
        return 4294967285LL;
      }
      mutex_lock(v3 + 1080);
      v10 = *(_DWORD *)(v3 + 2568);
      *(_DWORD *)(v3 + 2572) = 2;
      *(_DWORD *)(v3 + 2568) = v10 + 1;
      mutex_unlock(v3 + 1080);
      usb_redriver_release_lanes(*(_QWORD *)(v3 + 464), ((*(_DWORD *)(v3 + 1240) >> 2) & 1) == 0, 2);
      _pm_runtime_resume(*(_QWORD *)(v3 + 40) + 16LL, 4);
      v11 = *(_QWORD *)(v3 + 456);
      if ( v11 )
        *(_DWORD *)(v11 + 16) |= 0x400u;
      phy_set_mode_ext(*(_QWORD *)(v3 + 480), 1, 2);
      _pm_runtime_idle(*(_QWORD *)(v3 + 40) + 16LL, 4);
      ipc_log_string(
        *(_QWORD *)(v3 + 1256),
        "%s: Set DP 2 lanes: success, refcnt:%d\n",
        "dwc3_msm_set_dp_mode",
        *(_DWORD *)(v3 + 2568));
      return 0;
    }
    flush_work(v3 + 568);
    _flush_workqueue(*(_QWORD *)(v3 + 648));
    mutex_lock(v3 + 1080);
    if ( *(_DWORD *)(v3 + 752) )
    {
      if ( (*(_BYTE *)(v3 + 746) & 1) == 0 )
      {
        while ( (*(_QWORD *)(v3 + 688) & 8) != 0 )
          msleep(20);
        ipc_log_string(*(_QWORD *)(v3 + 1256), "%s: USB is not active.\n", "dwc3_msm_set_dp_mode");
        dwc3_msm_set_dp_only_params(v3);
        goto LABEL_36;
      }
      started = dwc3_start_stop_device(v3, 0);
      if ( !started )
      {
        dwc3_msm_set_dp_only_params(v3);
        dwc3_start_stop_device(v3, 1);
LABEL_36:
        if ( *(_DWORD *)(v3 + 2572) != 2 )
          ++*(_DWORD *)(v3 + 2568);
        started = 0;
        *(_DWORD *)(v3 + 2572) = 4;
      }
    }
    else
    {
      started = dwc3_start_stop_host(v3, 0);
      if ( !started )
      {
        dwc3_msm_set_dp_only_params(v3);
        dwc3_start_stop_host(v3, 1);
        goto LABEL_36;
      }
    }
    ipc_log_string(
      *(_QWORD *)(v3 + 1256),
      "%s: Set DP 4 lanes: %d refcnt:%d\n",
      "dwc3_msm_set_dp_mode",
      started,
      *(_DWORD *)(v3 + 2568));
    mutex_unlock(v3 + 1080);
    return started;
  }
  ipc_log_string(v6, "%s: DP lane already configured\n", "dwc3_msm_set_dp_mode");
  return 0;
}
