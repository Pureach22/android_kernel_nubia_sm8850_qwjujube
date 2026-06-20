__int64 __fastcall cnss_daemon_connection_update_cb(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x9
  int v9; // w10
  const char *v11; // x1
  const char *v12; // x1
  const char *v13; // x1
  __int16 v14; // w10
  const char *v15; // x9
  __int64 result; // x0
  __int16 v17; // w10
  const char *v18; // x9
  __int16 v19; // w10
  const char *v20; // x9
  unsigned __int64 v27; // x9
  unsigned __int64 v30; // x10
  char v31; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( a1 )
  {
    if ( (a2 & 1) != 0 )
    {
      if ( v9 )
      {
        v11 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v11,
        "cnss_daemon_connection_update_cb",
        6u,
        6u,
        "CNSS Daemon connected\n",
        a7,
        a8,
        v31);
      _X8 = (unsigned __int64 *)(a1 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x200000, _X8) );
      return complete(a1 + 4112);
    }
    else
    {
      if ( v9 )
      {
        v13 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(StatusReg + 16);
        v20 = (const char *)(StatusReg + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v20;
      }
      result = cnss_debug_ipc_log_print(
                 cnss_ipc_log_context,
                 v13,
                 "cnss_daemon_connection_update_cb",
                 6u,
                 6u,
                 "CNSS Daemon disconnected\n",
                 a7,
                 a8,
                 v31);
      *(_DWORD *)(a1 + 4112) = 0;
      _X8 = (unsigned __int64 *)(a1 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 & 0xFFFFFFFFFFDFFFFFLL, _X8) );
    }
  }
  else
  {
    if ( v9 )
    {
      v12 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v15;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v12,
             "cnss_daemon_connection_update_cb",
             3u,
             3u,
             "%s: Invalid context\n",
             (__int64)"cnss_daemon_connection_update_cb",
             a8,
             v31);
  }
  return result;
}
