__int64 __fastcall dp_catalog_aux_clear_hw_interrupts_v500(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x19
  void (__fastcall *v4)(__int64, __int64, __int64); // x8
  void (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  __int64 v6; // x0
  void (__fastcall *v7)(__int64, __int64, __int64, __int64); // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 1192);
    v2 = *(_QWORD *)(v1 + 32);
    v3 = *(_QWORD *)(*(_QWORD *)(v1 + 24) + 32LL);
    v4 = *(void (__fastcall **)(__int64, __int64, __int64))v1;
    if ( *(_DWORD *)(*(_QWORD *)v1 - 4LL) != 625732792 )
      __break(0x8228u);
    v4(v2, v3, 220);
    v5 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 8);
    v6 = *(_QWORD *)(v1 + 32);
    if ( *((_DWORD *)v5 - 1) != 621108289 )
      __break(0x8228u);
    v5(v6, v3, 92, 31);
    __dsb(0xEu);
    v7 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 8);
    v8 = *(_QWORD *)(v1 + 32);
    if ( *((_DWORD *)v7 - 1) != 621108289 )
      __break(0x8228u);
    v7(v8, v3, 92, 159);
    __dsb(0xEu);
    v9 = *(_DWORD **)(v1 + 8);
    v10 = *(_QWORD *)(v1 + 32);
    if ( *(v9 - 1) != 621108289 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v10, v3, 92, 0);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_279170, "dp_catalog_aux_clear_hw_interrupts_v500");
  }
  return result;
}
