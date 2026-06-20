__int64 __fastcall dp_catalog_ctrl_phy_lane_cfg(__int64 a1, char a2, char a3)
{
  __int64 v3; // x21
  __int64 v5; // x22
  unsigned int v6; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  _DWORD *v9; // x8
  __int64 v11; // x0

  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 - 192);
    v5 = a1 - 232;
    v6 = (16 << (a2 & 1)) & 0xFFFFFFF0 | a3 & 0xF;
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]Shared Info = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v6);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Shared Info = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v6);
    v9 = *(_DWORD **)(a1 - 104);
    if ( *(v9 - 1) != -626862723 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v5, v3, 172, v6);
  }
  else
  {
    v11 = get_ipc_log_context(0);
    ipc_log_string(v11, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_phy_lane_cfg");
  }
}
