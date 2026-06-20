__int64 __fastcall dp_catalog_aux_write_data(_DWORD *a1)
{
  __int64 v1; // x1
  _DWORD *v2; // x8
  _DWORD *v3; // x0
  __int64 v4; // x3
  unsigned int v5; // t1
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *((_QWORD *)a1 - 16);
    v2 = *((_DWORD **)a1 - 2);
    v5 = *a1;
    v3 = a1 - 36;
    v4 = v5;
    if ( *(v2 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v2)(v3, v1, 52, v4);
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_aux_write_data");
    return 4294967274LL;
  }
}
