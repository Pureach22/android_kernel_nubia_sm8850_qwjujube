__int64 __fastcall dp_display_mst_connector_uninstall(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v9; // x23
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x24
  int v15; // w7
  __int64 v17; // x0
  unsigned __int64 v18; // x20
  __int64 v19; // x0
  __int64 v20; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v9 = (int *)(a1 - 1156);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_mst_connector_uninstall",
      3765,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      vars0);
    mutex_lock(a1 + 560);
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      v11 = *(_QWORD *)(a2 + 2768);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 952);
        dp_panel_put(v11);
        if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v13 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v13,
          "[d][%-4d]dp mst connector uninstalled. conn:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a2 + 64));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]dp mst connector uninstalled. conn:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 64));
        mutex_unlock(a1 + 560);
        dp_audio_put(v12);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dp_display_mst_connector_uninstall",
          3793,
          8,
          8738,
          *v9,
          -1059143953,
          v15,
          vars0a);
        return 0;
      }
      else
      {
        if ( !g_dp_display || (v20 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v20 = 0;
        ipc_log_string(
          v20,
          "[e][%-4d]invalid panel for connector:%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(a2 + 64));
        printk(&unk_272CEF, "dp_display_mst_connector_uninstall");
        mutex_unlock(a1 + 560);
        return 4294967274LL;
      }
    }
    else
    {
      if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v17 = 0;
      v18 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v17, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(v18 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(v18 + 1800));
      mutex_unlock(a1 + 560);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v19 = 0;
    ipc_log_string(v19, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_connector_uninstall");
    return 4294967274LL;
  }
}
