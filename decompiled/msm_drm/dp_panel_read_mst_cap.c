__int64 __fastcall dp_panel_read_mst_cap(__int64 a1)
{
  __int64 v1; // x0
  char v2; // w19
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  int v7; // w19
  __int64 ipc_log_context; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( a1 )
  {
    v1 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 + 1192) + 24LL), 33, v9, 1);
    if ( (int)v1 <= 0 )
    {
      v7 = v1;
      ipc_log_context = get_ipc_log_context(v1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]dpcd mstm_cap read failed, rlen=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v7);
      v1 = printk(&unk_25D3DE, "dp_panel_read_mst_cap");
      v2 = 0;
    }
    else
    {
      v2 = v9[0];
    }
    v3 = get_ipc_log_context(v1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v3, "[d][%-4d]dp mst-cap: %d\n", *(_DWORD *)(StatusReg + 1800), v2 & 1);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp mst-cap: %d\n", *(_DWORD *)(StatusReg + 1800), v2 & 1);
  }
  else
  {
    v6 = get_ipc_log_context(0);
    ipc_log_string(v6, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_read_mst_cap");
    v2 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v2 & 1;
}
