__int64 __fastcall dp_power_mmrm_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x28
  unsigned int v9; // w26
  __int64 v10; // x27
  unsigned __int64 StatusReg; // x23
  __int64 ipc_log_context; // x0
  int *v13; // x1
  int *v14; // x1
  int v15; // t1
  __int64 v16; // x0

  v4 = *(_QWORD *)(a1 - 56);
  v9 = 0;
  v10 = 48;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v13 = (int *)(*(_QWORD *)(a1 - 72) + v10);
    v15 = *v13;
    v14 = v13 - 8;
    if ( v15 )
    {
      v16 = msm_dss_mmrm_register(v4 + 16, v14, a4, a3, a2 + 377);
      if ( (_DWORD)v16 )
      {
        v9 = v16;
        ipc_log_context = get_ipc_log_context(v16);
        ipc_log_string(ipc_log_context, "[e][%-4d]mmrm register failed rc=%d\n", *(_DWORD *)(StatusReg + 1800), v9);
        printk(&unk_21BEE6, "dp_power_mmrm_init");
      }
      else
      {
        v9 = 0;
      }
    }
    v10 += 48;
  }
  while ( v10 != 384 );
  return v9;
}
