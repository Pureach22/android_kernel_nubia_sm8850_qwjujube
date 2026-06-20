__int64 __fastcall dp_display_mst_connector_update_edid(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 (*v5)(void); // x8
  unsigned int v6; // w20
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x0
  unsigned __int64 v10; // x19
  __int64 v12; // x0
  __int64 v13; // x0

  if ( a1 && a2 && a3 )
  {
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      v4 = *(_QWORD *)(a2 + 2768);
      if ( v4 )
      {
        v5 = *(__int64 (**)(void))(v4 + 1120);
        if ( *((_DWORD *)v5 - 1) != -2111984293 )
          __break(0x8228u);
        v6 = v5();
        if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v7 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v7,
          "[d][%-4d]dp mst connector:%d edid updated. mode_cnt:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a2 + 64),
          v6);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]dp mst connector:%d edid updated. mode_cnt:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 64),
            v6);
      }
      else
      {
        if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v13 = 0;
        ipc_log_string(
          v13,
          "[e][%-4d]invalid panel for connector:%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(a2 + 64));
        printk(&unk_272CEF, "dp_display_mst_connector_update_edid");
        return (unsigned int)-22;
      }
    }
    else
    {
      if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v9 = 0;
      v10 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v9, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(v10 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(v10 + 1800));
      return (unsigned int)-1;
    }
  }
  else
  {
    if ( !g_dp_display || (v12 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v12 = 0;
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_connector_update_edid");
    return (unsigned int)-22;
  }
  return v6;
}
