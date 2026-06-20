__int64 __fastcall cnss_set_cxpc(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x19
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 result; // x0
  const char *v13; // x1
  const char *v14; // x1
  char v15; // [xsp+0h] [xbp-10h]
  char v16; // [xsp+0h] [xbp-10h]
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = v2;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v7 = "soft_irq";
  }
  else
  {
    v7 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(cnss_ipc_log_context, v7, "cnss_set_cxpc", 6u, 6u, "Entering cnss_set_cxpc\n", v3, v4, v15);
  if ( v6 )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)v6 + 760LL), "cx-mode", &v17, 1, 0) & 0x80000000) != 0 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v14 = "soft_irq";
      }
      else
      {
        v14 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_set_cxpc",
        3u,
        3u,
        "could not find cx mode\n",
        v10,
        v11,
        v16);
      result = 4294967274LL;
    }
    else if ( v17 == 2 )
    {
      result = 4294967258LL;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
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
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v13, "cnss_set_cxpc", 3u, 3u, "plat priv is null\n", v8, v9, v16);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
