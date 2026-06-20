__int64 __fastcall icnss_call_driver_probe(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x2
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  int v6; // w0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  int v9; // w20
  unsigned int v11; // w21
  unsigned __int64 v14; // x9
  unsigned __int64 v21; // x9
  unsigned __int64 v24; // x10

  v1 = a1[2];
  if ( v1 && *(_QWORD *)(v1 + 200) )
  {
    v2 = a1[229];
    if ( (v2 & 8) != 0 )
      return 4294967274LL;
    ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver probe state: 0x%lx\n", v2);
    icnss_hw_power_on(a1);
    if ( penv )
    {
      _X8 = (unsigned __int64 *)(penv + 1832);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 | 0x20000, _X8) );
      *(_DWORD *)(penv + 3088) = 0;
    }
    v4 = *(__int64 (__fastcall **)(_QWORD))(a1[2] + 200LL);
    v5 = a1[1] + 16LL;
    if ( *((_DWORD *)v4 - 1) != 711998475 )
      __break(0x8228u);
    v6 = v4(v5);
    if ( v6 == -517 )
    {
      v7 = *(__int64 (__fastcall **)(_QWORD))(a1[2] + 200LL);
      v8 = a1[1] + 16LL;
      if ( *((_DWORD *)v7 - 1) != 711998475 )
        __break(0x8228u);
      v6 = v7(v8);
      v9 = 2;
    }
    else
    {
      v9 = 1;
    }
    if ( v6 < 0 )
    {
      v11 = v6;
      printk("%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n", byte_130B32, v6, a1[229], v9);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",
        (const char *)&unk_12DBF3,
        v11,
        a1[229],
        v9);
      icnss_block_shutdown(0);
      icnss_hw_power_off(a1);
      return v11;
    }
    if ( penv )
    {
      _X8 = (unsigned __int64 *)(penv + 1832);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
      complete(penv + 3088);
    }
    _X8 = a1 + 229;
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 8, _X8) );
  }
  return 0;
}
