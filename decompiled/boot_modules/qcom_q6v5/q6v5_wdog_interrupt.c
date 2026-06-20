__int64 __fastcall q6v5_wdog_interrupt(__int64 a1, __int64 **a2)
{
  int v3; // w8
  __int64 *v5; // x20
  void (__fastcall *v6)(__int64); // x8
  __int64 v7; // x1
  const char *v8; // x0
  char *v9; // x20
  __int64 v10; // x1
  _BYTE *v11; // x0
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 *v14; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((unsigned __int8 *)a2 + 320);
  v15[0] = 0;
  if ( v3 == 1 )
  {
    a1 = completion_done(a2 + 26);
    if ( (a1 & 1) == 0 )
      a1 = complete(a2 + 26);
  }
  if ( (*((_BYTE *)a2 + 284) & 1) != 0 )
  {
    v5 = *a2;
    v6 = (void (__fastcall *)(__int64))arch_timer_read_counter;
    if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
      __break(0x8228u);
    v6(a1);
    dev_err(v5, "rproc crash at cycle:%llu, recovery state: %s\n");
    v7 = *((unsigned int *)a2 + 68);
    a2[39] = a2[38];
    v8 = (const char *)qcom_smem_get(0xFFFFFFFFLL, v7, v15);
    v9 = (char *)v8;
    if ( (unsigned __int64)v8 <= 0xFFFFFFFFFFFFF000LL && v15[0] && *v8 )
    {
      dev_err(*a2, "watchdog received: %s\n", v8);
      qcom_q6v5_conditional_recovery((int)a2, v9);
    }
    else
    {
      dev_err(*a2, "watchdog without message\n");
    }
    ss_atomic_panic_intval = (unsigned __int8)get_ss_symbol_from_rproc_name((__int64)a2);
    dev_info(*a2, "ztedbg w byte %x\n", ss_atomic_panic_intval);
    v10 = *((unsigned int *)a2 + 69);
    if ( (_DWORD)v10 )
    {
      v11 = (_BYTE *)qcom_smem_get(*((unsigned int *)a2 + 70), v10, v15);
      if ( (unsigned __int64)v11 <= 0xFFFFFFFFFFFFF000LL && v15[0] && *v11 )
        dev_err(*a2, "%s\n", v11);
    }
    v12 = *a2;
    *((_BYTE *)a2 + 284) = 0;
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    v14 = a2[11];
    if ( v14 )
      qcom_notify_early_ssr_clients(v14, v13);
    if ( *((_BYTE *)a2[1] + 1204) == 1 )
    {
      queue_work_on(32, system_unbound_wq, a2 + 13);
    }
    else
    {
      _pm_stay_awake(a2[42], v13);
      rproc_report_crash(a2[1], 1);
    }
  }
  else
  {
    complete(a2 + 22);
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
