__int64 __fastcall cnss_setup_bus_bandwidth(
        _DWORD *a1,
        unsigned int a2,
        char a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w9
  unsigned __int64 StatusReg; // x20
  _QWORD *v11; // x22
  const char *v13; // x1
  __int64 result; // x0
  const char *v15; // x1
  _QWORD *v17; // x24
  unsigned int *v18; // x8
  unsigned int v19; // w0
  const char *v20; // x1
  __int64 v21; // x6
  unsigned int v22; // w19
  char v23; // [xsp+0h] [xbp-20h]

  if ( !a1[90] )
    return 4294967201LL;
  v8 = a1[92];
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( v8 <= a2 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_setup_bus_bandwidth",
      3u,
      3u,
      "Invalid bus bandwidth Type: %d",
      a2,
      a8,
      v23);
    return 4294967274LL;
  }
  else
  {
    v11 = a1 + 86;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v13,
      "cnss_setup_bus_bandwidth",
      8u,
      7u,
      "Bandwidth vote to %d, save %d\n",
      a2,
      a3 & 1,
      v23);
    v17 = v11;
    while ( 1 )
    {
      v17 = (_QWORD *)*v17;
      if ( v17 == v11 )
        break;
      v18 = (unsigned int *)(v17[4] + 8LL * a2);
      v19 = icc_set_bw(v17[3], *v18, v18[1]);
      if ( v19 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v20 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v20 = "soft_irq";
        }
        else
        {
          v20 = (const char *)(StatusReg + 2320);
        }
        v21 = a2;
        v22 = v19;
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v20,
          "cnss_setup_bus_bandwidth",
          3u,
          3u,
          "Could not set BW Cfg: %d, err = %d ICC Path: %s Val: %d %d\n",
          v21,
          v19,
          v17[2]);
        return v22;
      }
    }
    result = 0;
    if ( (a3 & 1) != 0 )
      a1[91] = a2;
  }
  return result;
}
