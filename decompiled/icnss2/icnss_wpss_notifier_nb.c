__int64 __fastcall icnss_wpss_notifier_nb(_BYTE *a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x20
  const char *v7; // x23
  char v8; // w9
  __int64 v10; // x8
  __int64 v11; // x8
  _BYTE *v12; // x0
  __int64 result; // x0
  unsigned __int64 v19; // x8
  char v20; // w8
  __int64 v21; // x22
  unsigned __int64 v23; // x9
  _BYTE v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v6 = a1 - 2792;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    v7 = "UNKNOWN";
  else
    v7 = off_A88E0[a2 & 3];
  printk("%sicnss2: WPSS-Notify: event %s(%lu)\n", byte_13289B, v7, a2);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: WPSS-Notify: event %s(%lu)\n", (const char *)&unk_12DBF3, v7, a2);
  if ( a2 == 3 )
  {
    if ( *(a1 - 32) == 1 )
    {
      printk("%sicnss2: Collecting msa0 segment dump\n", byte_13289B);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Collecting msa0 segment dump\n", (const char *)&unk_12DBF3);
      icnss_msa0_ramdump(v6);
      *(a1 - 32) = 0;
    }
    goto LABEL_18;
  }
  if ( a2 != 2 )
  {
LABEL_18:
    printk("%sicnss2: Exit %s,state: 0x%lx\n", byte_13289B, "icnss_wpss_notifier_nb", *((_QWORD *)a1 - 120));
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Exit %s,state: 0x%lx\n",
      (const char *)&unk_12DBF3,
      "icnss_wpss_notifier_nb",
      *((_QWORD *)a1 - 120));
    result = 1;
    goto LABEL_19;
  }
  v8 = a1[3304];
  *(a1 - 32) = *(_BYTE *)(a3 + 8);
  if ( (v8 & 1) != 0 )
    timer_delete(a1 + 3264);
  _X23 = (unsigned __int64 *)(a1 - 960);
  a1[458] = 1;
  printk(
    "%sicnss2: WPSS went down, state: 0x%lx, crashed: %d\n",
    byte_13289B,
    *((_QWORD *)a1 - 120),
    *(unsigned __int8 *)(a3 + 8));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: WPSS went down, state: 0x%lx, crashed: %d\n",
    (const char *)&unk_12DBF3,
    *((_QWORD *)a1 - 120),
    *(unsigned __int8 *)(a3 + 8));
  v10 = *((_QWORD *)a1 - 311);
  if ( v10 == 43981 || v10 == 30544 )
    icnss_update_shutdown_state_to_fw(v6, a3);
  __asm { PRFM            #0x11, [X23] }
  do
    v19 = __ldxr(_X23);
  while ( __stxr(v19 | 0x2000, _X23) );
  icnss_ignore_fw_timeout(1);
  v11 = -272;
  if ( *(_BYTE *)(a3 + 8) )
    v11 = -276;
  ++*(_DWORD *)&a1[v11];
  v12 = (_BYTE *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
  if ( v12 )
  {
    v20 = *(_BYTE *)(a3 + 8);
    v21 = (__int64)v12;
    *v12 = v20;
    v24[0] = v20;
    if ( (*_X23 & 4) != 0 )
    {
      __asm { PRFM            #0x11, [X23] }
      do
        v23 = __ldxr(_X23);
      while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFBLL, _X23) );
      v24[0] = *(_BYTE *)(a3 + 8);
      icnss_call_driver_uevent(v6, 1, (__int64)v24);
    }
    icnss_driver_event_post((__int64)v6, 5u, 1, v21);
    if ( *(_BYTE *)(a3 + 8) == 1 )
      mod_timer(a1 + 3224, jiffies + 15000LL);
    goto LABEL_18;
  }
  result = 32781;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
