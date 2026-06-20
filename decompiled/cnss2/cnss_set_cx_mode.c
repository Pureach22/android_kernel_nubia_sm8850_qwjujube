__int64 __fastcall cnss_set_cx_mode(
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
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 result; // x0
  const char *v17; // x1
  const char *v18; // x1
  char v19; // [xsp+0h] [xbp-10h]
  char v20; // [xsp+0h] [xbp-10h]
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v22 = *(_QWORD *)(StatusReg + 1808);
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
    "cnss_set_cx_mode",
    6u,
    6u,
    "Entering cnss_set_cx_mode\n",
    a7,
    a8,
    v19);
  if ( a1 )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cx-mode", &v21, 1, 0) & 0x80000000) != 0 )
    {
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v18 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v18 = "soft_irq";
      }
      else
      {
        v18 = (const char *)(v9 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_set_cx_mode",
        3u,
        3u,
        "could not find cx mode\n",
        v14,
        v15,
        v20);
      result = 4294967274LL;
    }
    else if ( v21 == 2 )
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
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v17 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v17 = "soft_irq";
    }
    else
    {
      v17 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v17,
      "cnss_set_cx_mode",
      3u,
      3u,
      "plat priv is null\n",
      v12,
      v13,
      v20);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
