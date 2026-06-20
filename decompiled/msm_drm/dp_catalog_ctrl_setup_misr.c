__int64 __fastcall dp_catalog_ctrl_setup_misr(__int64 a1)
{
  __int64 v1; // x20
  void (__fastcall *v2)(__int64, __int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  __int64 v7; // x1
  void (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 192);
    v2 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    v3 = a1 - 232;
    v5 = a1 - 232;
    if ( *((_DWORD *)v2 - 1) != -626862723 )
      __break(0x8228u);
    v2(v5, v1, 192, 3);
    __dsb(0xEu);
    v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v6 - 1) != -626862723 )
      __break(0x8228u);
    v6(v3, v1, 192, 1);
    __dsb(0xEu);
    v7 = *(_QWORD *)(a1 - 208);
    v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    if ( *((_DWORD *)v8 - 1) != -626862723 )
      __break(0x8228u);
    v8(v3, v7, 208, 1281);
    __dsb(0xEu);
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_ctrl_setup_misr");
    return 4294967274LL;
  }
}
