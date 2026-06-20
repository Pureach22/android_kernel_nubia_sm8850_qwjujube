__int64 __fastcall dp_catalog_aux_get_irq(__int64 a1)
{
  __int64 v1; // x20
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  int v6; // w0
  _DWORD *v7; // x10
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 136);
    v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 24);
    v3 = a1 - 144;
    v5 = a1 - 144;
    if ( *((_DWORD *)v2 - 1) != -1879227436 )
      __break(0x8228u);
    v6 = v2(v5, v1, 32);
    v7 = *(_DWORD **)(a1 - 16);
    *(_DWORD *)(a1 + 4) = v6 & 0xDB6DB6DF;
    if ( *(v7 - 1) != -626862723 )
      __break(0x822Au);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v7)(
             v3,
             v1,
             32,
             (2 * v6) & 0x12492490 | 0x24924920u);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_aux_get_irq");
  }
}
