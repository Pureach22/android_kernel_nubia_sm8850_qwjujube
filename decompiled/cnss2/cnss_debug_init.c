__int64 cnss_debug_init()
{
  __int64 v0; // x6
  __int64 v1; // x7
  __int64 v2; // x6
  __int64 v3; // x7
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  __int16 v12; // w9
  const char *v13; // x8
  char v14; // [xsp+0h] [xbp+0h]

  cnss_ipc_log_context = ipc_log_context_create(50, "cnss", 0);
  if ( cnss_ipc_log_context )
  {
    v4 = ipc_log_context_create(50, "cnss-long", 0);
    result = 0;
    cnss_ipc_log_long_context = v4;
    if ( v4 )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(StatusReg + 16);
      v13 = (const char *)(StatusReg + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "cnss_ipc_logging_init",
      3u,
      3u,
      "Unable to create IPC long log context\n",
      v2,
      v3,
      v14);
    ipc_log_context_destroy(cnss_ipc_log_context);
  }
  else
  {
    v8 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v10 = *(_DWORD *)(v8 + 16);
      v11 = (const char *)(v8 + 2320);
      if ( (v10 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v11;
    }
    cnss_debug_ipc_log_print(0, v9, "cnss_ipc_logging_init", 3u, 3u, "Unable to create IPC log context\n", v0, v1, v14);
  }
  return 4294967274LL;
}
