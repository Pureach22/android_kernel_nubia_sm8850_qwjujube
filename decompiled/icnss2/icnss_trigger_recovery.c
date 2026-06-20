__int64 __fastcall icnss_trigger_recovery(__int64 a1)
{
  _DWORD *v1; // x19
  __int64 v2; // x2
  __int64 result; // x0
  __int64 v4; // x2
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x9

  v1 = *(_DWORD **)(a1 + 152);
  if ( *v1 != 1522293436 )
  {
    printk("%sicnss2: Invalid drvdata: magic 0x%x\n", byte_130B32, *v1);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid drvdata: magic 0x%x\n", (const char *)&unk_12DBF3, *v1);
    return 4294967274LL;
  }
  v2 = *((_QWORD *)v1 + 229);
  if ( (v2 & 0x200) != 0 )
  {
    printk("%sicnss2: PD recovery already in progress: state: 0x%lx\n", byte_130B32, v2);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: PD recovery already in progress: state: 0x%lx\n",
      (const char *)&unk_12DBF3,
      *((_QWORD *)v1 + 229));
    return 0xFFFFFFFFLL;
  }
  if ( *((_BYTE *)v1 + 5968) == 1 )
  {
    ipc_log_string(icnss_ipc_log_long_context, "icnss2: Initiate Root PD restart");
    result = icnss_send_smp2p(v1, 3, 0);
    if ( (_DWORD)result )
      return result;
    _X8 = (unsigned __int64 *)(v1 + 458);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 | 0x1000, _X8) );
    return 0;
  }
  v4 = *((_QWORD *)v1 + 229);
  if ( (v4 & 0x100) == 0 )
  {
    printk("%sicnss2: PD restart not enabled to trigger recovery: state: 0x%lx\n", byte_130B32, v4);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: PD restart not enabled to trigger recovery: state: 0x%lx\n",
      (const char *)&unk_12DBF3,
      *((_QWORD *)v1 + 229));
    return 4294967201LL;
  }
  printk("%sicnss2: Initiate PD restart at WLAN FW, state: 0x%lx\n", byte_1337E7, v4);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Initiate PD restart at WLAN FW, state: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *((_QWORD *)v1 + 229));
  result = pdr_restart_pd(*((_QWORD *)v1 + 708), *((_QWORD *)v1 + 709));
  if ( !(_DWORD)result )
  {
    _X8 = (unsigned __int64 *)(v1 + 458);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 0x1000, _X8) );
    return 0;
  }
  return result;
}
