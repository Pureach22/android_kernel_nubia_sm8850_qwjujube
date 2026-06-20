__int64 __fastcall dp_catalog_get_dp_phy_version(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x20
  __int64 v6; // x0
  int v7; // w0
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x8
  int v9; // w21
  int v10; // w0
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  int v12; // w21
  int v13; // w0
  _DWORD *v14; // x8
  int v15; // w21
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 1232);
    if ( !v1 )
    {
      v2 = *(_QWORD *)(a1 - 104);
      v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
      v4 = a1 - 144;
      v6 = a1 - 144;
      if ( *((_DWORD *)v3 - 1) != -1879227436 )
        __break(0x8228u);
      v7 = v3(v6, v2, 12);
      v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
      v9 = v7;
      if ( *((_DWORD *)v8 - 1) != -1879227436 )
        __break(0x8228u);
      v10 = v8(v4, v2, 8);
      v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
      v12 = (v10 << 16) | (v9 << 24);
      if ( *((_DWORD *)v11 - 1) != -1879227436 )
        __break(0x8228u);
      v13 = v11(v4, v2, 4);
      v14 = *(_DWORD **)(a1 - 24);
      v15 = v12 | (v13 << 8);
      if ( *(v14 - 1) != -1879227436 )
        __break(0x8228u);
      v1 = v15 | ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v14)(v4, v2, 0);
      *(_DWORD *)(a1 + 1232) = v1;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_get_dp_phy_version");
    return 0;
  }
  return v1;
}
