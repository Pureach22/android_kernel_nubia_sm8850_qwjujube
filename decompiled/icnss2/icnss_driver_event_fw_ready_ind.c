__int64 __fastcall icnss_driver_event_fw_ready_ind(__int64 a1, char a2)
{
  unsigned int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x10
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x8
  __int64 v12; // x2
  __int64 v13; // x2
  unsigned int v14; // w20
  __int64 v15; // x25
  unsigned int i; // w23
  _QWORD *v17; // x27
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 (__fastcall *v20)(_QWORD); // x8
  int v21; // w0
  int v22; // w21
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x10
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned __int64 v39; // x10
  unsigned __int64 v42; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v51; // x10
  unsigned __int64 v54; // x9
  unsigned __int64 v57; // x10
  unsigned __int64 v60; // x9

  if ( !a1 )
    return 4294967277LL;
  timer_delete((timer_t)(a1 + 6016));
  _X8 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr(_X8);
  while ( __stxr(v29 | 4, _X8) );
  _X8 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X8] }
  do
    v32 = __ldxr(_X8);
  while ( __stxr(v32 & 0xFFFFFFFFFFFEFFFFLL, _X8) );
  *(_DWORD *)(a1 + 5488) = 0;
  if ( *(_QWORD *)(a1 + 304) == 26448 )
  {
    v5 = *(_DWORD *)(a1 + 3280);
    if ( v5 )
    {
      v15 = *(_QWORD *)(a1 + 8);
      for ( i = 0; i < v5; ++i )
      {
        v17 = (_QWORD *)(a1 + 3288 + 40LL * (int)i);
        if ( v17[1] && *v17 )
        {
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
            v17 + 2,
            *v17,
            *((_DWORD *)v17 + 7));
          dma_free_attrs(v15 + 16, *v17, v17[1], v17[2], 0);
          *v17 = 0;
          v17[1] = 0;
          v17[2] = 0;
          v5 = *(_DWORD *)(a1 + 3280);
          *((_DWORD *)v17 + 7) = 0;
        }
      }
    }
    *(_DWORD *)(a1 + 3280) = 0;
  }
  printk("%sicnss2: WLAN FW is ready: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 1832));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: WLAN FW is ready: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(a1 + 1832));
  if ( *(_QWORD *)(a1 + 304) != 30544 || (a2 & 1) != 0 )
    icnss_hw_power_off(a1);
  if ( *(_QWORD *)(a1 + 8) )
  {
    if ( (*(_QWORD *)(a1 + 1832) & 0x200) == 0 )
    {
      if ( *(_BYTE *)(a1 + 5968) == 1 )
        icnss_setup_dms_mac(a1);
      goto LABEL_30;
    }
    _X9 = (unsigned int *)(a1 + 2920);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v35 = __ldxr(_X9);
      v36 = v35 - 1;
    }
    while ( __stlxr(v36, _X9) );
    __dmb(0xBu);
    if ( (v36 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else if ( !v36 )
    {
      ipc_log_string(
        icnss_ipc_log_long_context,
        "icnss2: PM relax, state: 0x%lx, count: %d\n",
        *(_QWORD *)(a1 + 1832),
        *(_DWORD *)(a1 + 2920));
      pm_relax(*(_QWORD *)(a1 + 8) + 16LL);
      ++*(_DWORD *)(a1 + 2560);
    }
    icnss_collect_host_dump_info(a1);
    if ( (*(_QWORD *)(a1 + 1832) & 8) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 16);
      if ( v6 )
      {
        if ( *(_QWORD *)(v6 + 216) )
        {
          v7 = *(_QWORD *)(a1 + 1832);
          if ( (v7 & 0x800) == 0 )
          {
            ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver shutdown state: 0x%lx\n", v7);
            v9 = *(_QWORD *)(a1 + 8);
            v8 = *(_QWORD *)(a1 + 16);
            print_optimize = 0;
            v10 = *(void (__fastcall **)(_QWORD))(v8 + 216);
            if ( *((_DWORD *)v10 - 1) != 1820440776 )
              __break(0x8228u);
            v10(v9 + 16);
            _X8 = (unsigned __int64 *)(a1 + 1832);
            __asm { PRFM            #0x11, [X8] }
            do
              v60 = __ldxr(_X8);
            while ( __stxr(v60 | 0x800, _X8) );
          }
        }
      }
    }
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 & 0xFFFFFFFFFFFBFFFFLL, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v45 = __ldxr(_X8);
    while ( __stxr(v45 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v48 = __ldxr(_X8);
    while ( __stxr(v48 & 0xFFFFFFFFFBFFFFFFLL, _X8) );
    v11 = *(_QWORD *)(a1 + 16);
    *(_BYTE *)(a1 + 2978) = 0;
    *(_BYTE *)(a1 + 3250) = 0;
    if ( v11 && *(_QWORD *)(v11 + 224) )
    {
      v12 = *(_QWORD *)(a1 + 1832);
      if ( (v12 & 0x2000) != 0 )
      {
        printk("%sicnss2: FW is in bad state, state: 0x%lx\n", byte_130B32, v12);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: FW is in bad state, state: 0x%lx\n",
          (const char *)&unk_12DBF3,
          *(_QWORD *)(a1 + 1832));
      }
      else
      {
        v13 = *(_QWORD *)(a1 + 1832);
        if ( (v13 & 8) == 0 )
        {
LABEL_30:
          v14 = icnss_call_driver_probe(a1);
LABEL_45:
          icnss_vreg_unvote(a1);
          return v14;
        }
        ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver reinit state: 0x%lx\n", v13);
        icnss_hw_power_on(a1);
        if ( penv )
        {
          _X8 = (unsigned __int64 *)(penv + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v54 = __ldxr(_X8);
          while ( __stxr(v54 | 0x20000, _X8) );
          *(_DWORD *)(penv + 3088) = 0;
        }
        v19 = *(_QWORD *)(a1 + 8);
        v18 = *(_QWORD *)(a1 + 16);
        print_optimize = 0;
        v20 = *(__int64 (__fastcall **)(_QWORD))(v18 + 224);
        if ( *((_DWORD *)v20 - 1) != 711998475 )
          __break(0x8228u);
        v21 = v20(v19 + 16);
        if ( v21 < 0 )
        {
          v22 = v21;
          printk("%sicnss2: fatal: Driver reinit failed: %d, state: 0x%lx\n", byte_130B32, v21, *(_QWORD *)(a1 + 1832));
          v14 = v22;
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: fatal: Driver reinit failed: %d, state: 0x%lx\n",
            (const char *)&unk_12DBF3,
            v22,
            *(_QWORD *)(a1 + 1832));
          icnss_block_shutdown(0);
          icnss_hw_power_off(a1);
          goto LABEL_45;
        }
        if ( penv )
        {
          _X8 = (unsigned __int64 *)(penv + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v57 = __ldxr(_X8);
          while ( __stxr(v57 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
          complete(penv + 3088);
        }
        _X8 = (unsigned __int64 *)(a1 + 1832);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 & 0xFFFFFFFFFFFFF7FFLL, _X8) );
      }
    }
    v14 = 0;
    goto LABEL_45;
  }
  printk("%sicnss2: Device is not ready\n", byte_130B32);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Device is not ready\n", (const char *)&unk_12DBF3);
  return 4294967277LL;
}
