__int64 __fastcall shutdown_store(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x20
  const char *v11; // x1
  __int64 v12; // x6
  __int64 v13; // x7
  const char *v14; // x1
  unsigned __int64 v22; // x9
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 152);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "shutdown_store",
    7u,
    7u,
    "Received shutdown notification\n",
    a7,
    a8,
    vars0);
  if ( v9 )
  {
    _X8 = (unsigned __int64 *)(v9 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 | 0x10000, _X8) );
    cnss_bus_update_status(v9);
    timer_delete((timer_t)(v9 + 6272));
    complete_all(v9 + 6312);
    complete_all(v9 + 6344);
    complete_all(v9 + 7960);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "shutdown_store",
      7u,
      7u,
      "Shutdown notification handled\n",
      v12,
      v13,
      vars0a);
  }
  return a4;
}
