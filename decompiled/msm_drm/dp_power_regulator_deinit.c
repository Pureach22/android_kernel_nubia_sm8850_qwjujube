__int64 __fastcall dp_power_regulator_deinit(_QWORD *a1)
{
  __int64 v1; // x27
  __int64 v2; // x23
  _QWORD *v3; // x28
  unsigned __int64 StatusReg; // x24
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  const char *v7; // x22

  v1 = a1[2];
  v2 = 0;
  v3 = (_QWORD *)(*a1 + 24LL);
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    result = msm_dss_get_vreg(v1 + 16, *v3, *((unsigned int *)v3 - 2), 0);
    if ( (_DWORD)result )
    {
      ipc_log_context = get_ipc_log_context(result);
      v7 = "???";
      if ( (unsigned int)v2 <= 6 )
        v7 = off_2806F8[v2];
      ipc_log_string(ipc_log_context, "[e][%-4d]failed to deinit vregs for %s\n", *(_DWORD *)(StatusReg + 1800), v7);
      result = printk(&unk_25D19B, "dp_power_regulator_deinit");
    }
    ++v2;
    v3 += 6;
  }
  while ( v2 != 7 );
  return result;
}
