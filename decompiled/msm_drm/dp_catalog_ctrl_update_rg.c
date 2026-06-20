__int64 __fastcall dp_catalog_ctrl_update_rg(__int64 a1, unsigned int a2, int a3, int a4)
{
  __int64 v5; // x22
  unsigned int v9; // w23
  __int64 v10; // x25
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x26
  _DWORD *v13; // x10
  __int64 v14; // x2
  __int64 v16; // x0

  if ( a1 && a2 < 2 )
  {
    v5 = *(_QWORD *)(a1 - 208);
    v9 = a4 | (a3 << 16);
    v10 = a1 - 232;
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]ch: %d x_int:%d y_frac_enum:%d rg:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      a2,
      a3,
      a4,
      v9);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]ch: %d x_int:%d y_frac_enum:%d rg:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        a3,
        a4,
        v9);
    v13 = *(_DWORD **)(a1 - 104);
    if ( a2 == 1 )
      v14 = 1276;
    else
      v14 = 1272;
    if ( *(v13 - 1) != -626862723 )
      __break(0x822Au);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v13)(v10, v5, v14, v9);
  }
  else
  {
    v16 = get_ipc_log_context(a1);
    ipc_log_string(v16, "[e][%-4d]invalid input. ch %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    return printk(&unk_22627D, "dp_catalog_ctrl_update_rg");
  }
}
