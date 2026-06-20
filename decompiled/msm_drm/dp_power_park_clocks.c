__int64 __fastcall dp_power_park_clocks(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned int v6; // w19
  __int64 v7; // x0
  void *v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_park_clocks");
    return 4294967274LL;
  }
  v1 = a1 - 72;
  v2 = dp_power_park_module(a1 - 72, 3);
  if ( (_DWORD)v2 )
  {
    v6 = v2;
    v7 = get_ipc_log_context(v2);
    ipc_log_string(v7, "[e][%-4d]failed to park stream 0. err=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v6);
    v8 = &unk_26B56A;
LABEL_11:
    printk(v8, "dp_power_park_clocks");
    return v6;
  }
  if ( *(_BYTE *)(*(_QWORD *)v1 + 724LL) == 1 )
  {
    v3 = dp_power_park_module(v1, 4);
    if ( (_DWORD)v3 )
    {
      v6 = v3;
      v10 = get_ipc_log_context(v3);
      ipc_log_string(v10, "[e][%-4d]failed to park stream 1. err=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v6);
      v8 = &unk_2523BF;
      goto LABEL_11;
    }
  }
  result = dp_power_park_module(v1, 5);
  if ( (_DWORD)result )
  {
    v6 = result;
    v9 = get_ipc_log_context(result);
    ipc_log_string(v9, "[e][%-4d]failed to park link clock. err=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v6);
    v8 = &unk_21BE83;
    goto LABEL_11;
  }
  return result;
}
