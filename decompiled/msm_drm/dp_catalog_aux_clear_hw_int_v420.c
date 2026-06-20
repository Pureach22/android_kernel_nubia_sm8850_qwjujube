__int64 __fastcall dp_catalog_aux_clear_hw_int_v420(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w9
  __int64 v3; // x0
  __int64 v4; // x19
  void (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x2
  __int64 v7; // x1
  void (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  _DWORD *v12; // x8
  __int64 v13; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 1192);
    v2 = (unsigned int)dp_catalog_get_dp_phy_version(*(_QWORD *)(v1 + 32)) >> 29;
    v3 = *(_QWORD *)(v1 + 32);
    v4 = *(_QWORD *)(*(_QWORD *)(v1 + 24) + 32LL);
    v5 = *(void (__fastcall **)(__int64, __int64, __int64))v1;
    if ( v2 <= 2 )
      v6 = 216;
    else
      v6 = 224;
    v7 = *(_QWORD *)(*(_QWORD *)(v1 + 24) + 32LL);
    if ( *((_DWORD *)v5 - 1) != 625732792 )
      __break(0x8228u);
    v5(v3, v7, v6);
    v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 8);
    v9 = *(_QWORD *)(v1 + 32);
    if ( *((_DWORD *)v8 - 1) != 621108289 )
      __break(0x8228u);
    v8(v9, v4, 88, 31);
    __dsb(0xEu);
    v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 8);
    v11 = *(_QWORD *)(v1 + 32);
    if ( *((_DWORD *)v10 - 1) != 621108289 )
      __break(0x8228u);
    v10(v11, v4, 88, 159);
    __dsb(0xEu);
    v12 = *(_DWORD **)(v1 + 8);
    v13 = *(_QWORD *)(v1 + 32);
    if ( *(v12 - 1) != 621108289 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v12)(v13, v4, 88, 0);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_aux_clear_hw_int_v420");
  }
  return result;
}
