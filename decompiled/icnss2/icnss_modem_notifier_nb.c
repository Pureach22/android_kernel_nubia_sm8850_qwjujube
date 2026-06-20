__int64 __fastcall icnss_modem_notifier_nb(_BYTE *a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x21
  const char *v7; // x2
  __int64 v9; // x9
  int v10; // w8
  char v11; // w8
  __int64 v13; // x2
  __int64 v14; // x8
  unsigned __int64 v15; // x2
  __int64 v16; // x8
  __int64 v17; // x9
  _DWORD *v18; // x8
  __int64 result; // x0
  _BYTE *v20; // x0
  __int64 v21; // x22
  char v22; // w8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v32; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  _BYTE v37[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v38[3]; // [xsp+8h] [xbp-18h] BYREF

  v6 = a1 - 2768;
  v38[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    v7 = "UNKNOWN";
  else
    v7 = off_A88E0[a2 & 3];
  ipc_log_string(icnss_ipc_log_long_context, "icnss2: Modem-Notify: event %s(%lu)\n", v7, a2);
  if ( a2 == 3 )
  {
    if ( *(_BYTE *)(a3 + 8) == 1 )
    {
      printk("%sicnss2: Collecting msa0 segment dump\n", byte_13289B);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Collecting msa0 segment dump\n", (const char *)&unk_12DBF3);
      icnss_msa0_ramdump((__int64)v6);
    }
  }
  else if ( a2 == 2 )
  {
    if ( a1[3208] )
      complete(a1 + 3216);
    if ( (*(_BYTE *)(a3 + 8) & 1) == 0 && a1[3201] )
    {
      _X22 = (unsigned __int64 *)(a1 - 936);
      if ( (*((_QWORD *)a1 - 117) & 0x10000) != 0 )
        icnss_driver_event_post((__int64)v6, 7u, 3, 0);
      __asm { PRFM            #0x11, [X22] }
      do
        v32 = __ldxr(_X22);
      while ( __stxr(v32 | 0x4000000, _X22) );
    }
    v9 = -248;
    a1[482] = 1;
    v10 = *(unsigned __int8 *)(a3 + 8);
    _ZF = v10 == 0;
    v11 = v10 ^ 1;
    if ( !_ZF )
      v9 = -252;
    a1[2912] = v11;
    ++*(_DWORD *)&a1[v9];
    icnss_update_shutdown_state_to_fw((__int64)v6, a3);
    _X24 = (unsigned __int64 *)(a1 - 936);
    v13 = *((_QWORD *)a1 - 117);
    if ( (v13 & 0x100) != 0 )
    {
      __asm { PRFM            #0x11, [X24] }
      do
        v24 = __ldxr(_X24);
      while ( __stxr(v24 | 0x2000, _X24) );
      icnss_ignore_fw_timeout(1);
      if ( (*_X24 & 4) != 0 )
      {
        __asm { PRFM            #0x11, [X24] }
        do
          v26 = __ldxr(_X24);
        while ( __stxr(v26 & 0xFFFFFFFFFFFFFFFBLL, _X24) );
        v14 = *((_QWORD *)a1 - 344);
        v37[0] = *(_BYTE *)(a3 + 8);
        if ( v14 )
        {
          if ( *(_QWORD *)(v14 + 288) )
          {
            v15 = *_X24;
            v38[0] = 1;
            ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v15, 1);
            v16 = *((_QWORD *)a1 - 344);
            v17 = *((_QWORD *)a1 - 345);
            v38[1] = v37;
            v18 = *(_DWORD **)(v16 + 288);
            if ( *(v18 - 1) != -712363570 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD *))v18)(v17 + 16, v38);
          }
        }
      }
    }
    else
    {
      printk("%sicnss2: Modem went down, state: 0x%lx, crashed: %d\n", byte_13289B, v13, *(unsigned __int8 *)(a3 + 8));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Modem went down, state: 0x%lx, crashed: %d\n",
        (const char *)&unk_12DBF3,
        *_X24,
        *(unsigned __int8 *)(a3 + 8));
      __asm { PRFM            #0x11, [X24] }
      do
        v34 = __ldxr(_X24);
      while ( __stxr(v34 | 0x2000, _X24) );
      icnss_ignore_fw_timeout(1);
      v20 = (_BYTE *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
      v21 = (__int64)v20;
      if ( !v20 )
      {
        result = 32781;
        goto LABEL_27;
      }
      v22 = *(_BYTE *)(a3 + 8);
      *v20 = v22;
      v37[0] = v22;
      if ( (*_X24 & 4) != 0 )
      {
        __asm { PRFM            #0x11, [X24] }
        do
          v36 = __ldxr(_X24);
        while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFBLL, _X24) );
        v37[0] = *(_BYTE *)(a3 + 8);
        icnss_call_driver_uevent(v6, 1, (__int64)v37);
      }
      icnss_driver_event_post((__int64)v6, 5u, 1, v21);
      if ( *(_BYTE *)(a3 + 8) == 1 )
        mod_timer(a1 + 3248, jiffies + 15000LL);
    }
  }
  ipc_log_string(
    icnss_ipc_log_long_context,
    "icnss2: Exit %s,state: 0x%lx\n",
    "icnss_modem_notifier_nb",
    *((_QWORD *)a1 - 117));
  result = 1;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
