__int64 __fastcall dp_catalog_aux_enable(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x21
  __int64 v7; // x0
  int v8; // w0
  _DWORD *v9; // x8
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 128);
    v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
    v4 = a1 - 144;
    v7 = a1 - 144;
    if ( *((_DWORD *)v3 - 1) != -1879227436 )
      __break(0x8228u);
    v8 = v3(v7, v2, 48);
    v9 = *(_DWORD **)(a1 - 16);
    if ( (a2 & 1) != 0 )
    {
      if ( *(v9 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v4, v2, 48, v8 | 1u);
      __dsb(0xEu);
      v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 16);
      if ( *((_DWORD *)v10 - 1) != -626862723 )
        __break(0x8228u);
      v10(v4, v2, 60, 0xFFFF);
      v9 = *(_DWORD **)(a1 - 16);
      v11 = v4;
      v12 = v2;
      v13 = 64;
      v14 = 0xFFFF;
    }
    else
    {
      v14 = v8 & 0xFFFFFFFE;
      v11 = v4;
      v12 = v2;
      v13 = 48;
    }
    if ( *(v9 - 1) != -626862723 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))v9)(v11, v12, v13, v14);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_aux_enable");
  }
}
