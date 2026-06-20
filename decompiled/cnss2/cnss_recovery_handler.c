__int64 __fastcall cnss_recovery_handler(__int64 a1)
{
  __int64 v2; // x7
  __int64 v3; // x6
  unsigned __int64 StatusReg; // x8
  const char *v5; // x1
  __int16 v6; // w9
  const char *v7; // x8
  __int64 result; // x0
  unsigned __int64 v15; // x9
  unsigned __int64 v18; // x10
  unsigned __int64 v21; // x10
  char v22; // [xsp+0h] [xbp+0h]

  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 | 0x200, _X8) );
  if ( !*(_BYTE *)(a1 + 544) )
    panic("subsys-restart: Resetting the SoC wlan crashed\n");
  cnss_bus_dev_shutdown(a1);
  cnss_bus_dev_ramdump(a1);
  if ( (*(_QWORD *)(a1 + 552) & 0x8000) == 0 )
  {
    v3 = *(_QWORD *)(a1 + 552);
    if ( (v3 & 0x800000) != 0 )
      goto LABEL_4;
LABEL_5:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else
    {
      v6 = *(_DWORD *)(StatusReg + 16);
      v7 = (const char *)(StatusReg + 2320);
      if ( (v6 & 0xFF00) != 0 )
        v5 = "soft_irq";
      else
        v5 = v7;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v5,
             "cnss_recovery_handler",
             7u,
             7u,
             "Host driver not registered yet, ignore Device Power Up, 0x%lx\n",
             v3,
             v2,
             v22);
  }
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
  v3 = *(_QWORD *)(a1 + 552);
  if ( (v3 & 0x800000) == 0 )
    goto LABEL_5;
LABEL_4:
  v3 = *(_QWORD *)(a1 + 552);
  if ( (v3 & 0x4000000) == 0 )
    goto LABEL_5;
  msleep(100);
  result = cnss_bus_dev_powerup(a1);
  if ( (_DWORD)result )
  {
    result = _pm_relax(*(_QWORD *)(a1 + 7440));
    _X8 = (unsigned __int64 *)(a1 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
  }
  return result;
}
