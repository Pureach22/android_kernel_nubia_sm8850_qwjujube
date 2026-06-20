__int64 __fastcall dp_catalog_ctrl_phy_lane_cfg_v420(__int64 a1, char a2, char a3)
{
  _QWORD *v3; // x21
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  _DWORD *v8; // x8
  __int64 v9; // x0
  __int64 v11; // x0

  if ( a1 )
  {
    v3 = *(_QWORD **)(a1 + 1104);
    v4 = (16 << (a2 & 1)) & 0xFFFFFFF0 | a3 & 0xF;
    v5 = *(_QWORD *)(v3[3] + 32LL);
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]Shared Info = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v4);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Shared Info = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v4);
    v8 = (_DWORD *)v3[1];
    v9 = v3[4];
    if ( *(v8 - 1) != 621108289 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v8)(v9, v5, 200, v4);
  }
  else
  {
    v11 = get_ipc_log_context(0);
    ipc_log_string(v11, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_phy_lane_cfg_v420");
  }
}
