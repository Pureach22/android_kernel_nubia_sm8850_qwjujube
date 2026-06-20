__int64 __fastcall dp_display_mst_uninstall(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v8; // x21
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x19
  int v12; // w7
  __int64 v14; // x0
  unsigned __int64 v15; // x19
  __int64 v16; // x0
  char v17; // [xsp+0h] [xbp+0h]
  char v18; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v8 = (int *)(a1 - 1156);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_mst_uninstall",
      3674,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      v17);
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      *(_QWORD *)(a1 + 704) = 0;
      *(_QWORD *)(a1 + 696) = 0;
      *(_QWORD *)(a1 + 688) = 0;
      *(_QWORD *)(a1 + 680) = 0;
      *(_QWORD *)(a1 + 672) = 0;
      *(_BYTE *)(a1 + 665) = 0;
      if ( !g_dp_display || (v10 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v10 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v10, "[d][%-4d]dp mst drm uninstalled\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp mst drm uninstalled\n", *(_DWORD *)(StatusReg + 1800));
      sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_mst_uninstall", 3687, 8, 8738, *v8, -1059143953, v12, v18);
      return 0;
    }
    else
    {
      if ( !g_dp_display || (v14 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v14 = 0;
      v15 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v14, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(v15 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(v15 + 1800));
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    if ( !g_dp_display || (v16 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v16 = 0;
    ipc_log_string(v16, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_uninstall");
    return 4294967274LL;
  }
}
