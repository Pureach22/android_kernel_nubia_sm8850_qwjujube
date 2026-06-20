__int64 __fastcall dp_display_mst_connector_update_link_info(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x11
  __int64 v4; // x10
  __int64 v5; // x11
  __int64 v6; // x10
  _QWORD *v7; // x9
  __int64 v8; // x10
  __int64 v9; // x12
  __int64 v10; // x13
  __int64 v11; // x9
  __int64 v12; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v16; // x0
  unsigned __int64 v17; // x19
  __int64 v18; // x0
  __int64 v19; // x0

  if ( a1 && a2 )
  {
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      v2 = *(_QWORD **)(a2 + 2768);
      if ( v2 )
      {
        v3 = *(_QWORD *)(*(_QWORD *)(a1 - 992) + 8LL);
        *v2 = **(_QWORD **)(a1 - 992);
        v2[1] = v3;
        v4 = *(_QWORD *)(a1 - 992);
        v5 = *(_QWORD *)(v4 + 52);
        v6 = *(_QWORD *)(v4 + 44);
        *(_QWORD *)((char *)v2 + 52) = v5;
        *(_QWORD *)((char *)v2 + 44) = v6;
        v7 = *(_QWORD **)(a1 - 992);
        v9 = v7[10];
        v8 = v7[11];
        v10 = v7[9];
        v11 = g_dp_display;
        v2[9] = v10;
        v2[10] = v9;
        v2[11] = v8;
        if ( !v11 || (v12 = *(_QWORD *)(v11 + 56)) == 0 )
          v12 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v12,
          "[d][%-4d]dp mst connector:%d link info updated\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a2 + 64));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]dp mst connector:%d link info updated\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 64));
        return 0;
      }
      else
      {
        if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v19 = 0;
        ipc_log_string(
          v19,
          "[e][%-4d]invalid panel for connector:%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(a2 + 64));
        printk(&unk_272CEF, "dp_display_mst_connector_update_link_info");
        return 4294967274LL;
      }
    }
    else
    {
      if ( !g_dp_display || (v16 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v16 = 0;
      v17 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v16, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(v17 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(v17 + 1800));
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v18 = 0;
    ipc_log_string(v18, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_connector_update_link_info");
    return 4294967274LL;
  }
}
