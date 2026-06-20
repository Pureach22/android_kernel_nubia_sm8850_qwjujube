__int64 __fastcall cnss_dms_init(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x7
  unsigned int v4; // w19
  unsigned __int64 v5; // x8
  __int64 v6; // x0
  const char *v7; // x1
  unsigned __int64 StatusReg; // x8
  __int16 v9; // w9
  const char *v10; // x8
  const char *v11; // x5
  __int16 v12; // w9
  const char *v13; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = qmi_handle_init(a1 + 145, 256, qmi_dms_ops, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    v4 = v2;
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v10;
    }
    v11 = "Failed to initialize DMS handle, err: %d\n";
    goto LABEL_15;
  }
  a1[103] = 0xFFFFFFFE00000LL;
  a1[104] = a1 + 104;
  a1[105] = a1 + 104;
  a1[106] = cnss_dms_server_exit_work;
  v4 = qmi_add_lookup(a1 + 145, 2, 1, 0);
  if ( (v4 & 0x80000000) != 0 )
  {
    v5 = _ReadStatusReg(SP_EL0);
    v6 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(v5 + 16);
      v13 = (const char *)(v5 + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v13;
    }
    v11 = "Failed to add DMS lookup, err: %d\n";
LABEL_15:
    cnss_debug_ipc_log_print(v6, v7, "cnss_dms_init", 3u, 3u, v11, v4, v3, vars0);
  }
  return v4;
}
