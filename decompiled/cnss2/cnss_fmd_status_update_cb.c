__int64 __fastcall cnss_fmd_status_update_cb(
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
  const char *v11; // x1
  __int16 v12; // w10
  const char *v13; // x9
  __int64 result; // x0
  unsigned __int64 v21; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else
  {
    v12 = *(_DWORD *)(StatusReg + 16);
    v13 = (const char *)(StatusReg + 2320);
    if ( (v12 & 0xFF00) != 0 )
      v11 = "soft_irq";
    else
      v11 = v13;
  }
  result = cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v11,
             "cnss_fmd_status_update_cb",
             7u,
             7u,
             "FMD status update: %d\n",
             a2 & 1,
             a8,
             vars0);
  if ( (a2 & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(a1 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 | 0x10000, _X8) );
    cnss_bus_update_status(a1);
    return cnss_bus_fmd_status(a1);
  }
  return result;
}
