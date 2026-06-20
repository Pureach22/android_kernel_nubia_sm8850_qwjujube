__int64 __fastcall dp_catalog_ctrl_fec_config(__int64 a1, char a2)
{
  __int64 v2; // x21
  _DWORD *v3; // x8
  __int64 v4; // x22
  __int64 v7; // x0
  int v8; // w0
  _DWORD *v9; // x10
  __int64 v10; // x3
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 208);
    v3 = *(_DWORD **)(a1 - 112);
    v4 = a1 - 232;
    v7 = a1 - 232;
    if ( *(v3 - 1) != -1879227436 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v3)(v7, v2, 0);
    v9 = *(_DWORD **)(a1 - 104);
    if ( (a2 & 1) != 0 )
      v10 = v8 | 0x3C01000u;
    else
      v10 = v8 & 0xFE7FEFFF;
    if ( *(v9 - 1) != -626862723 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v9)(v4, v2, 0, v10);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_fec_config");
  }
  return result;
}
