__int64 __fastcall wlfw_del_server(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x19
  unsigned __int64 v10; // x8
  const char *v11; // x1
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int16 v18; // w9
  const char *v19; // x8
  unsigned __int64 v25; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v9 = a1 - 856;
  if ( a1 != 856 && (a7 = *(_QWORD *)(a1 - 304), (a7 & 0x80000) != 0) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(StatusReg + 16);
      v19 = (const char *)(StatusReg + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v19;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v13,
             "wlfw_del_server",
             6u,
             6u,
             "WLFW server delete in progress, Ignore server delete, state: 0x%lx\n",
             a7,
             a8,
             vars0);
  }
  else
  {
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(v10 + 16);
      v15 = (const char *)(v10 + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "wlfw_del_server",
      7u,
      7u,
      "WLFW server exiting\n",
      a7,
      a8,
      vars0);
    if ( v9 )
    {
      _X8 = (unsigned __int64 *)(a1 - 304);
      __asm { PRFM            #0x11, [X8] }
      do
        v25 = __ldxr(_X8);
      while ( __stxr(v25 | 0x80000, _X8) );
    }
    return cnss_driver_event_post(v9, 1u, 0, 0);
  }
}
