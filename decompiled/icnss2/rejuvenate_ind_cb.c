_WORD *__fastcall rejuvenate_ind_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _WORD *result; // x0
  int v8; // w20
  int v9; // w21
  int v10; // w23
  _QWORD *v11; // x0
  __int64 v12; // x20
  unsigned __int64 v19; // x9
  char v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received Rejuvenate Indication\n");
  if ( a3 )
  {
    if ( *(_BYTE *)a4 )
      v8 = *(unsigned __int8 *)(a4 + 1);
    else
      v8 = 0;
    *(_BYTE *)(a1 + 2355) = v8;
    if ( *(_BYTE *)(a4 + 2) )
      v9 = *(unsigned __int8 *)(a4 + 3);
    else
      v9 = 0;
    *(_BYTE *)(a1 + 2356) = v9;
    if ( *(_BYTE *)(a4 + 4) )
      v10 = *(unsigned __int16 *)(a4 + 6);
    else
      v10 = 0;
    *(_WORD *)(a1 + 2358) = v10;
    v11 = (_QWORD *)(a1 + 2496);
    if ( *(_BYTE *)(a4 + 8) )
    {
      memcpy(v11, (const void *)(a4 + 9), 0x81u);
    }
    else
    {
      *(_BYTE *)(a1 + 2624) = 0;
      *(_QWORD *)(a1 + 2608) = 0;
      *(_QWORD *)(a1 + 2616) = 0;
      *(_QWORD *)(a1 + 2592) = 0;
      *(_QWORD *)(a1 + 2600) = 0;
      *(_QWORD *)(a1 + 2576) = 0;
      *(_QWORD *)(a1 + 2584) = 0;
      *(_QWORD *)(a1 + 2560) = 0;
      *(_QWORD *)(a1 + 2568) = 0;
      *(_QWORD *)(a1 + 2544) = 0;
      *(_QWORD *)(a1 + 2552) = 0;
      *(_QWORD *)(a1 + 2528) = 0;
      *(_QWORD *)(a1 + 2536) = 0;
      *(_QWORD *)(a1 + 2512) = 0;
      *(_QWORD *)(a1 + 2520) = 0;
      *v11 = 0;
      *(_QWORD *)(a1 + 2504) = 0;
    }
    printk(
      "%sicnss2_qmi: Cause for rejuvenation: 0x%x, requesting sub-system: 0x%x, line number: %u, function name: %s\n",
      byte_13289B,
      v8,
      v9,
      v10,
      (const char *)(a1 + 2496));
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Cause for rejuvenation: 0x%x, requesting sub-system: 0x%x, line number: %u, function name: %s\n",
      (const char *)&unk_12DBF3,
      *(unsigned __int8 *)(a1 + 2355),
      *(unsigned __int8 *)(a1 + 2356),
      *(unsigned __int16 *)(a1 + 2358),
      (const char *)(a1 + 2496));
    ++*(_DWORD *)(a1 + 2032);
    result = (_WORD *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
    v12 = (__int64)result;
    if ( result )
    {
      *result = 257;
      v20[0] = 1;
      _X8 = (unsigned __int64 *)(a1 + 1208);
      __asm { PRFM            #0x11, [X8] }
      do
        v19 = __ldxr(_X8);
      while ( __stxr(v19 | 0x8000, _X8) );
      icnss_call_driver_uevent((_QWORD *)(a1 - 624), 1, (__int64)v20);
      result = (_WORD *)icnss_driver_event_post(a1 - 624, 5u, 0, v12);
    }
  }
  else
  {
    result = (_WORD *)printk(byte_12E112);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
