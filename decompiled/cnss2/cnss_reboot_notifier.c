__int64 __fastcall cnss_reboot_notifier(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  unsigned __int64 v17; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v4 = a1 - 400;
  _X8 = (unsigned __int64 *)(a1 + 152);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 | 0x10000, _X8) );
  cnss_bus_update_status(v4);
  timer_delete((timer_t)(a1 + 5872));
  complete_all(a1 + 5912);
  complete_all(a1 + 5944);
  complete_all(a1 + 7560);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else
  {
    v8 = *(_DWORD *)(StatusReg + 16);
    v9 = (const char *)(StatusReg + 2320);
    if ( (v8 & 0xFF00) != 0 )
      v7 = "soft_irq";
    else
      v7 = v9;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v7,
    "cnss_reboot_notifier",
    7u,
    7u,
    "Reboot is in progress with action %d\n",
    a2,
    v5,
    vars0);
  return 0;
}
