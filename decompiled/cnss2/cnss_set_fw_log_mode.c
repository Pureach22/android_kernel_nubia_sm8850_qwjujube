__int64 __fastcall cnss_set_fw_log_mode(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x0
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  char v14; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v8 = cnss_bus_dev_to_plat_priv(a1, a2);
    if ( v8 )
    {
      if ( *(_QWORD *)(v8 + 528) == 62 )
        return 0;
      else
        return cnss_wlfw_ini_send_sync();
    }
    else
    {
      return 4294967277LL;
    }
  }
  else
  {
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
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_set_fw_log_mode",
      3u,
      3u,
      "Invalid dev pointer\n",
      a7,
      a8,
      v14);
    return 4294967274LL;
  }
}
