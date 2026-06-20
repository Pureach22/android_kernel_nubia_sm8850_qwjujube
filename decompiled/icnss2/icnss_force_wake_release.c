__int64 __fastcall icnss_force_wake_release(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w8
  unsigned int v10; // w12

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform driver not initialized\n");
    return 4294967274LL;
  }
  if ( (*(_QWORD *)(v1 + 1832) & 0x2000) != 0 || (*(_QWORD *)(v1 + 1832) & 4) == 0 )
  {
    ipc_log_string(icnss_ipc_soc_wake_context, "icnss2: FW down, ignoring SOC Wake release state: 0x%lx\n");
    return 4294967274LL;
  }
  ipc_log_string(icnss_ipc_soc_wake_context, "icnss2: Calling SOC Wake response, Ref_count: %d", *(_DWORD *)(v1 + 5488));
  if ( *(_DWORD *)(v1 + 5488) )
  {
    v3 = *(_DWORD *)(v1 + 5488);
    while ( (int)(v3 - 1) >= 1 )
    {
      _X14 = (unsigned int *)(v1 + 5488);
      __asm { PRFM            #0x11, [X14] }
      while ( 1 )
      {
        v10 = __ldxr(_X14);
        if ( v10 != v3 )
          break;
        if ( !__stlxr(v3 - 1, _X14) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v10 == v3;
      v3 = v10;
      if ( _ZF )
        goto LABEL_20;
    }
    if ( v3 == 1 )
      goto LABEL_21;
LABEL_20:
    ipc_log_string(
      icnss_ipc_soc_wake_context,
      "icnss2: SOC previous release pending, Ref count: %d",
      *(_DWORD *)(v1 + 5488));
  }
  else
  {
LABEL_21:
    icnss_soc_wake_event_post(v1, 1u, 0, 0);
  }
  return 0;
}
