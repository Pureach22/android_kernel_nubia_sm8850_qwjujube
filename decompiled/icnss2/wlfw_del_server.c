__int64 __fastcall wlfw_del_server(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x2
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x9

  v1 = a1 - 624;
  if ( a1 == 624 )
  {
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: WLFW server delete\n");
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 1208);
    if ( (v2 & 0x100000) != 0 )
    {
      printk(
        "%sicnss2_qmi: WLFW server delete / icnss remove in progress, Ignore server delete:  0x%lx\n",
        byte_13289B,
        v2);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2_qmi: WLFW server delete / icnss remove in progress, Ignore server delete:  0x%lx\n",
               (const char *)&unk_12DBF3,
               *(_QWORD *)(a1 + 1208));
    }
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: WLFW server delete\n");
    _X8 = (unsigned __int64 *)(a1 + 1208);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 | 0x100000, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 1208);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 0x2000, _X8) );
  }
  return icnss_driver_event_post(v1, 1u, 0, 0);
}
