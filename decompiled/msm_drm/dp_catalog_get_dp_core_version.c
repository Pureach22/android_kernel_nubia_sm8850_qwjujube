__int64 __fastcall dp_catalog_get_dp_core_version(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x1
  _DWORD *v3; // x8
  __int64 v4; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 1228);
    if ( !v1 )
    {
      v2 = *(_QWORD *)(a1 - 136);
      v3 = *(_DWORD **)(a1 - 24);
      v4 = a1 - 144;
      if ( *(v3 - 1) != -1879227436 )
        __break(0x8228u);
      return ((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v3)(v4, v2, 0);
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_get_dp_core_version");
    return 0;
  }
  return v1;
}
