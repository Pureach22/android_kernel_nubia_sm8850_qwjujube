__int64 __fastcall dp_catalog_ctrl_mainlink_ctrl(__int64 a1, char a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x8
  __int64 v4; // x20
  __int64 v7; // x0
  int v8; // w0
  _DWORD *v9; // x8
  int v10; // w22
  _DWORD *v11; // x8
  _DWORD *v12; // x8
  _DWORD *v13; // x8
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
    {
      v10 = v8;
      if ( *(v9 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v9)(v4, v2, 0, v8 & 0xFFFFFFFC);
      __dsb(0xEu);
      v11 = *(_DWORD **)(a1 - 104);
      if ( *(v11 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v11)(v4, v2, 0, v10 | 2u);
      __dsb(0xEu);
      v12 = *(_DWORD **)(a1 - 104);
      if ( *(v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v12)(v4, v2, 0, v10 & 0xFFFFFFFC);
      __dsb(0xEu);
      v13 = *(_DWORD **)(a1 - 104);
      if ( *(v13 - 1) != -626862723 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v13)(v4, v2, 0, v10 | 1u);
      __dsb(0xEu);
    }
    else
    {
      if ( *(v9 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v9)(v4, v2, 0, v8 & 0xFFFFFFFE);
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_mainlink_ctrl");
  }
  return result;
}
