__int64 __fastcall cnss_debug_direct_cx(
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
  __int64 v14; // x0
  const char *v15; // x1
  const char *v16; // x2
  const char *v17; // x5
  unsigned int v18; // w3
  unsigned int v19; // w4
  char v21; // [xsp+0h] [xbp-10h]
  char v22; // [xsp+0h] [xbp-10h]
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v24 = *(_QWORD *)(StatusReg + 1808);
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
    "cnss_debug_direct_cx",
    6u,
    6u,
    "Entering cnss_debug_direct_cx\n",
    a7,
    a8,
    v21);
  if ( !a1 )
  {
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v9 + 2320);
    }
    v16 = "cnss_debug_direct_cx";
    v17 = "plat_priv is null\n";
    goto LABEL_27;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cx-mode", &v23, 1, 0) & 0x80000000) != 0 )
  {
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v9 + 2320);
    }
    v16 = "cnss_debug_direct_cx";
    v17 = "could not find cx mode\n";
    v18 = 3;
    v19 = 3;
    goto LABEL_28;
  }
  if ( v23 == 3 )
  {
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v9 + 2320);
    }
    v16 = "cnss_read_debug_register";
    v17 = "Entering negative cnss_read_debug_register function\n";
LABEL_27:
    v18 = 6;
    v19 = 6;
LABEL_28:
    cnss_debug_ipc_log_print(v14, v15, v16, v18, v19, v17, v12, v13, v22);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
