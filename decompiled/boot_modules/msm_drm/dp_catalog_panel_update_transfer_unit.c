__int64 __fastcall dp_catalog_panel_update_transfer_unit(unsigned int *a1)
{
  unsigned int *v2; // x22
  __int64 v3; // x3
  __int64 v4; // x20
  void (__fastcall *v5)(unsigned int *, __int64, __int64, __int64); // x8
  unsigned int *v6; // x0
  __int64 v7; // x1
  void (__fastcall *v8)(unsigned int *, __int64, __int64, __int64); // x8
  __int64 v9; // x3
  void (__fastcall *v10)(unsigned int *, __int64, __int64, __int64); // x8
  __int64 v11; // x3
  __int64 ipc_log_context; // x0

  if ( a1 && a1[51] < 2 )
  {
    v2 = a1 - 112;
    v3 = a1[48];
    v4 = *((_QWORD *)a1 - 69);
    v5 = *((void (__fastcall **)(unsigned int *, __int64, __int64, __int64))a1 - 56);
    v6 = a1 - 144;
    v7 = *((_QWORD *)a1 - 69);
    if ( *((_DWORD *)v5 - 1) != -626862723 )
      __break(0x8228u);
    v5(v6, v7, 48, v3);
    v8 = *(void (__fastcall **)(unsigned int *, __int64, __int64, __int64))v2;
    v9 = a1[47];
    if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -626862723 )
      __break(0x8228u);
    v8(a1 - 144, v4, 76, v9);
    v10 = *(void (__fastcall **)(unsigned int *, __int64, __int64, __int64))v2;
    v11 = a1[49];
    if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -626862723 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(unsigned int *, __int64, __int64, __int64))v10)(a1 - 144, v4, 52, v11);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_update_transfer_unit");
  }
}
