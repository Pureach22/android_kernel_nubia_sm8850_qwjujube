__int64 __fastcall q6v5_fatal_interrupt(__int64 a1, __int64 **a2)
{
  int v3; // w8
  __int64 *v5; // x20
  __int64 (__fastcall *v6)(__int64); // x8
  __int64 v7; // x2
  const char *v8; // x3
  __int64 v9; // x1
  const char *v10; // x0
  char *v11; // x20
  __int64 v12; // x1
  const char *v13; // x0
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 *v16; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((unsigned __int8 *)a2 + 320);
  v17[0] = 0;
  if ( v3 == 1 )
  {
    a1 = completion_done(a2 + 26);
    if ( (a1 & 1) == 0 )
      a1 = complete(a2 + 26);
  }
  if ( *((_BYTE *)a2 + 284) == 1 )
  {
    v5 = *a2;
    v6 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
    if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
      __break(0x8228u);
    v7 = v6(a1);
    if ( *((_BYTE *)a2[1] + 1204) )
      v8 = "disabled and lead to device crash";
    else
      v8 = "enabled and kick recovery process";
    dev_err(v5, "rproc crash at cycle:%llu, recovery state: %s\n", v7, v8);
    v9 = *((unsigned int *)a2 + 68);
    a2[39] = a2[38];
    v10 = (const char *)qcom_smem_get(0xFFFFFFFFLL, v9, v17);
    v11 = (char *)v10;
    if ( (unsigned __int64)v10 <= 0xFFFFFFFFFFFFF000LL && v17[0] && *v10 )
    {
      dev_err(*a2, "fatal error received: %s\n", v10);
      qcom_q6v5_conditional_recovery((int)a2, v11);
    }
    else
    {
      dev_err(*a2, "fatal error without message\n");
    }
    ss_atomic_panic_intval = (unsigned __int8)get_ss_symbol_from_rproc_name((__int64)a2);
    dev_info(*a2, "ztedbg f byte %x\n", ss_atomic_panic_intval);
    v12 = *((unsigned int *)a2 + 69);
    if ( (_DWORD)v12 )
    {
      v13 = (const char *)qcom_smem_get(*((unsigned int *)a2 + 70), v12, v17);
      if ( (unsigned __int64)v13 <= 0xFFFFFFFFFFFFF000LL && v17[0] && *v13 )
        dev_err(*a2, "%s\n", v13);
    }
    v14 = *a2;
    *((_BYTE *)a2 + 284) = 0;
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    v16 = a2[11];
    if ( v16 )
      qcom_notify_early_ssr_clients(v16, v15);
    if ( *((_BYTE *)a2[1] + 1204) == 1 )
    {
      queue_work_on(32, system_unbound_wq, a2 + 13);
    }
    else
    {
      _pm_stay_awake(a2[42], v15);
      rproc_report_crash(a2[1], 2);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
