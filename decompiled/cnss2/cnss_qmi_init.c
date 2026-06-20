__int64 __fastcall cnss_qmi_init(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x7
  unsigned int v4; // w8
  __int64 v5; // x3
  unsigned int v6; // w19
  unsigned __int64 v7; // x8
  __int64 v8; // x0
  const char *v9; // x1
  unsigned __int64 StatusReg; // x8
  __int16 v11; // w9
  const char *v12; // x8
  const char *v13; // x5
  __int16 v14; // w9
  const char *v15; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  cnss_get_qrtr_info();
  v2 = qmi_handle_init(a1 + 856, 0x2000, qmi_wlfw_ops, &qmi_wlfw_msg_handlers);
  if ( (v2 & 0x80000000) != 0 )
  {
    v6 = v2;
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v12;
    }
    v13 = "Failed to initialize WLFW QMI handle, err: %d\n";
    goto LABEL_21;
  }
  if ( (cnss_is_dual_wlan_enabled() & 1) != 0 && *(_DWORD *)(a1 + 7808) )
  {
    v4 = *(_DWORD *)(a1 + 7812);
    if ( v4 <= 1 )
      v5 = 1;
    else
      v5 = v4;
  }
  else
  {
    v5 = 1;
  }
  v6 = qmi_add_lookup(a1 + 856, 69, 1, v5);
  if ( (v6 & 0x80000000) != 0 )
  {
    v7 = _ReadStatusReg(SP_EL0);
    v8 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(v7 + 16);
      v15 = (const char *)(v7 + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v15;
    }
    v13 = "Failed to add WLFW QMI lookup, err: %d\n";
LABEL_21:
    cnss_debug_ipc_log_print(v8, v9, "cnss_qmi_init", 3u, 3u, v13, v6, v3, vars0);
  }
  return v6;
}
