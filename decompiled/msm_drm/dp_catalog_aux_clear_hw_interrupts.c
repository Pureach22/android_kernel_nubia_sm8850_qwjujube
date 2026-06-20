__int64 __fastcall dp_catalog_aux_clear_hw_interrupts(__int64 a1)
{
  __int64 v1; // x20
  void (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v8; // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 104);
    v2 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
    v3 = a1 - 144;
    v5 = a1 - 144;
    if ( *((_DWORD *)v2 - 1) != -1879227436 )
      __break(0x8228u);
    v2(v5, v1, 188);
    v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 16);
    if ( *((_DWORD *)v6 - 1) != -626862723 )
      __break(0x8228u);
    v6(v3, v1, 76, 31);
    __dsb(0xEu);
    v7 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 16);
    if ( *((_DWORD *)v7 - 1) != -626862723 )
      __break(0x8228u);
    v7(v3, v1, 76, 159);
    __dsb(0xEu);
    v8 = *(_DWORD **)(a1 - 16);
    if ( *(v8 - 1) != -626862723 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v8)(v3, v1, 76, 0);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_aux_clear_hw_interrupts");
  }
  return result;
}
