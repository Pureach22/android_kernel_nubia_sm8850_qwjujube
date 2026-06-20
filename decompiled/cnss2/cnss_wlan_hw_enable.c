__int64 cnss_wlan_hw_enable()
{
  __int64 v0; // x19
  __int64 result; // x0
  __int64 v2; // x7
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x9
  unsigned int v5; // w19
  const char *v6; // x1
  __int16 v7; // w10
  const char *v8; // x9
  unsigned __int64 v15; // x10
  char v16; // [xsp+0h] [xbp+0h]

  v0 = plat_env;
  if ( !plat_env )
    return 4294967277LL;
  _X8 = (unsigned __int64 *)(plat_env + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 & 0xFFFFFFFFFEFFFFFFLL, _X8) );
  if ( (*(_QWORD *)(v0 + 552) & 0x400000) != 0 )
    goto LABEL_10;
  result = cnss_wlan_device_init(v0);
  v3 = *(_QWORD *)(v0 + 552);
  if ( !(_DWORD)result )
  {
    if ( (v3 & 0x2000000) != 0 )
      cnss_driver_event_post(v0, 5u, 0, 0);
LABEL_10:
    result = *(_QWORD *)(v0 + 6472);
    if ( result )
      return cnss_wlan_register_driver();
    return result;
  }
  if ( (v3 & 0x1000000) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = result;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v7 = *(_DWORD *)(StatusReg + 16);
      v8 = (const char *)(StatusReg + 2320);
      if ( (v7 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v8;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v6,
      "cnss_wlan_hw_enable",
      3u,
      3u,
      "ASSERT at line %d\n",
      6742,
      v2,
      v16);
    __break(0x800u);
    return v5;
  }
  return result;
}
