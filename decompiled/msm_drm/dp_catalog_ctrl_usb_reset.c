__int64 __fastcall dp_catalog_ctrl_usb_reset(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v5; // x21
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  void (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v9; // x8
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v11)(__int64, __int64, __int64, __int64); // x8
  __int64 v12; // x3
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  void (__fastcall *v15)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v16; // x8
  __int64 result; // x0
  __int64 v18; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 152);
    v5 = a1 - 232;
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]Program PHYMODE to DP only\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Program PHYMODE to DP only\n", *(_DWORD *)(StatusReg + 1800));
    v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v8 - 1) != -626862723 )
      __break(0x8228u);
    v8(v5, v2, 28, 10);
    v9 = *(_DWORD **)(a1 - 104);
    if ( *(v9 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v9)(v5, v2, 0, 2);
    v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v10 - 1) != -626862723 )
      __break(0x8228u);
    v10(v5, v2, 4, 1);
    __dsb(0xEu);
    v11 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( (a2 & 1) != 0 )
      v12 = 3;
    else
      v12 = 2;
    if ( *((_DWORD *)v11 - 1) != -626862723 )
      __break(0x8228u);
    v11(v5, v2, 16, v12);
    v13 = *(_DWORD **)(a1 - 104);
    if ( *(v13 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v13)(v5, v2, 12, 0);
    v14 = *(_DWORD **)(a1 - 104);
    if ( *(v14 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v14)(v5, v2, 4, 0);
    __dsb(0xEu);
    v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v15 - 1) != -626862723 )
      __break(0x8228u);
    v15(v5, v2, 8, 1);
    v16 = *(_DWORD **)(a1 - 104);
    if ( *(v16 - 1) != -626862723 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v16)(v5, v2, 28, 0);
    __dsb(0xEu);
  }
  else
  {
    v18 = get_ipc_log_context(0);
    ipc_log_string(v18, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_usb_reset");
  }
  return result;
}
