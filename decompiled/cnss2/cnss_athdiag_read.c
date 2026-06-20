__int64 __fastcall cnss_athdiag_read(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 v6; // x8
  const char *v7; // x1
  __int64 v8; // x6
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  __int16 v13; // w9
  const char *v14; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
  {
    if ( *(_QWORD *)(v2 + 528) == 62 )
      return 0;
    v8 = *(_QWORD *)(v2 + 552);
    if ( (v8 & 4) != 0 )
      return cnss_wlfw_athdiag_read_send_sync();
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v14;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_athdiag_read",
      3u,
      3u,
      "Invalid state for athdiag read: 0x%lx\n",
      v8,
      v4,
      vars0);
  }
  else
  {
    v6 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v6 + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(v6 + 16);
      v12 = (const char *)(v6 + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v12;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "cnss_athdiag_read",
      3u,
      3u,
      "plat_priv is NULL!\n",
      v3,
      v4,
      vars0);
  }
  return 4294967274LL;
}
