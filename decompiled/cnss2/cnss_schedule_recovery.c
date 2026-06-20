_DWORD *__fastcall cnss_schedule_recovery(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x20
  __int64 v7; // x1
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  _DWORD *result; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = a2;
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  v6 = v3;
  if ( (*(_QWORD *)(v3 + 552) & 0x800) == 0 )
    cnss_bus_update_status(v3);
  if ( (*(_QWORD *)(v6 + 552) & 0x20) != 0 || (*(_QWORD *)(v6 + 552) & 0x80) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v10 = *(_DWORD *)(StatusReg + 16);
      v11 = (const char *)(StatusReg + 2320);
      if ( (v10 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v11;
    }
    return (_DWORD *)cnss_debug_ipc_log_print(
                       cnss_ipc_log_context,
                       v9,
                       "cnss_schedule_recovery",
                       7u,
                       7u,
                       "Driver unload or idle shutdown is in progress, ignore schedule recovery\n",
                       v4,
                       v5,
                       vars0);
  }
  else
  {
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 || (_ReadStatusReg(DAIF) & 0x80) != 0 )
      v7 = 2336;
    else
      v7 = 3520;
    result = (_DWORD *)_kmalloc_cache_noprof(of_find_compatible_node, v7, 4);
    if ( result )
    {
      *result = v2;
      return (_DWORD *)cnss_driver_event_post(v6, 9u, 0, (__int64)result);
    }
  }
  return result;
}
