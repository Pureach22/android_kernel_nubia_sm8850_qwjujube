__int64 __fastcall cnss_set_cx_voltage_corner(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x20
  const char *v11; // x1
  __int64 v12; // x6
  __int64 v13; // x7
  __int64 result; // x0
  __int64 v15; // x0
  const char *v16; // x1
  const char *v17; // x5
  unsigned int v18; // w3
  unsigned int v19; // w4
  char v20; // [xsp+0h] [xbp-10h]
  char v21; // [xsp+0h] [xbp-10h]
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v23 = *(_QWORD *)(StatusReg + 1808);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_set_cx_voltage_corner",
    6u,
    6u,
    "Entering cnss_set_cx_voltage_corner\n",
    a7,
    a8,
    v20);
  if ( !a1 )
  {
    v15 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v9 + 2320);
    }
    v17 = "plat_priv is null\n";
    v18 = 6;
    v19 = 6;
    goto LABEL_23;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cx-mode", &v22, 1, 0) & 0x80000000) != 0 )
  {
    v15 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v9 + 2320);
    }
    v17 = "could not find cx mode\n";
    v18 = 3;
    v19 = 3;
LABEL_23:
    cnss_debug_ipc_log_print(v15, v16, "cnss_set_cx_voltage_corner", v18, v19, v17, v12, v13, v21);
    result = 4294967274LL;
    goto LABEL_24;
  }
  if ( v22 == 2 )
    result = 4294967258LL;
  else
    result = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
