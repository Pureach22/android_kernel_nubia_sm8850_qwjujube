__int64 __fastcall dp_catalog_hpd_get_interrupt(__int64 a1)
{
  unsigned int (__fastcall **v1)(__int64, __int64, __int64); // x22
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v6; // x0
  int v7; // w0
  _DWORD **v8; // x8
  int v9; // w19
  _DWORD *v10; // x8
  unsigned int (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = (unsigned int (__fastcall **)(__int64, __int64, __int64))(a1 - 1176);
    v2 = a1 - 1296;
    v3 = *(_QWORD *)(a1 - 1280);
    v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 1176);
    v6 = a1 - 1296;
    if ( *((_DWORD *)v4 - 1) != -1879227436 )
      __break(0x8228u);
    v7 = v4(v6, v3, 4);
    v8 = (_DWORD **)(a1 - 1168);
    v9 = v7;
    v10 = *v8;
    if ( *(v10 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v2, v3, 8, v7 & 0xF);
    v11 = *v1;
    if ( *((_DWORD *)*v1 - 1) != -1879227436 )
      __break(0x8228u);
    return v11(v2, v3, 12) & v9;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_hpd_get_interrupt");
    return 0;
  }
}
