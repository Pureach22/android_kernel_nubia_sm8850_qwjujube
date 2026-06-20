__int64 __fastcall dp_catalog_aux_clear_trans(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x9
  __int64 v6; // x0
  int v7; // w0
  _DWORD *v8; // x8
  _DWORD *v9; // x9
  __int64 v10; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 128);
    v3 = a1 - 144;
    if ( (a2 & 1) != 0 )
    {
      v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
      v6 = a1 - 144;
      if ( *((_DWORD *)v4 - 1) != -1879227436 )
        __break(0x8229u);
      v7 = v4(v6, v2, 56);
      v8 = *(_DWORD **)(a1 - 16);
      if ( *(v8 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v8)(v3, v2, 56, v7 & 0xFFFFFDFF);
    }
    else
    {
      v9 = *(_DWORD **)(a1 - 16);
      v10 = a1 - 144;
      if ( *(v9 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v10, v2, 56, 0);
    }
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_aux_clear_trans");
    return 4294967274LL;
  }
}
