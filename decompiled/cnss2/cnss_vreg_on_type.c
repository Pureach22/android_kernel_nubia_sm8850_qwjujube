__int64 __fastcall cnss_vreg_on_type(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x6
  const char *v10; // x1
  __int64 *v11; // x19
  __int64 *v12; // x23
  unsigned __int64 v13; // x25
  unsigned __int64 v14; // x8
  const char *v15; // x1
  int v16; // w8
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  __int64 result; // x0
  __int16 v21; // w9
  const char *v22; // x8
  unsigned int v23; // w20
  __int64 v24; // x0
  const char *v25; // x1
  const char *v26; // x1
  __int64 v27; // x6
  const char *v28; // x5
  __int64 v29; // x7
  __int64 v30; // x21
  unsigned __int64 v31; // x8
  int v32; // [xsp+0h] [xbp-10h]

  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = a2;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v21 = *(_DWORD *)(StatusReg + 16);
      v22 = (const char *)(StatusReg + 2320);
      if ( (v21 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v22;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_vreg_on_type",
      3u,
      3u,
      "Unsupported vreg type 0x%x\n",
      v9,
      a8,
      v32);
    return 4294967274LL;
  }
  v11 = (__int64 *)(a1 + 24);
  v12 = *(__int64 **)(a1 + 24);
  if ( v12 == (__int64 *)(a1 + 24) )
    return 0;
  v13 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v14 = v12[2];
    if ( !v14 || v14 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_7;
    v15 = "irq";
    v16 = *(_DWORD *)(v13 + 16) & 0xF0000;
    if ( *((_DWORD *)v12 + 14) )
    {
      if ( !v16 )
      {
        if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
          v15 = "soft_irq";
        else
          v15 = (const char *)(v13 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_vreg_on_single",
        7u,
        7u,
        "Regulator %s is already enabled\n",
        v12[3],
        a8,
        v32);
      goto LABEL_7;
    }
    if ( !v16 )
    {
      if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = (const char *)(v13 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_vreg_on_single",
      7u,
      7u,
      "Regulator %s is being enabled\n",
      v12[3],
      a8,
      v32);
    if ( *((_DWORD *)v12 + 8) )
    {
      if ( *((_DWORD *)v12 + 9) )
      {
        v17 = regulator_set_voltage(v12[2]);
        if ( v17 )
        {
          if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
          {
            v25 = "irq";
          }
          else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
          {
            v25 = "soft_irq";
          }
          else
          {
            v25 = (const char *)(v13 + 2320);
          }
          v29 = *((unsigned int *)v12 + 8);
          v27 = v12[3];
          v28 = "Failed to set voltage for regulator %s, min_uv: %u, max_uv: %u, err = %d\n";
          v23 = v17;
          v24 = cnss_ipc_log_context;
          v32 = *((_DWORD *)v12 + 9);
          goto LABEL_52;
        }
      }
    }
    if ( *((_DWORD *)v12 + 10) )
    {
      v18 = regulator_set_load(v12[2]);
      if ( (v18 & 0x80000000) != 0 )
        break;
    }
    if ( *((_DWORD *)v12 + 11) )
      _udelay();
    v19 = regulator_enable(v12[2]);
    if ( v19 )
    {
      v23 = v19;
      v24 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
      {
        v25 = "soft_irq";
      }
      else
      {
        v25 = (const char *)(v13 + 2320);
      }
      v27 = v12[3];
      v28 = "Failed to enable regulator %s, err = %d\n";
      v29 = v23;
LABEL_52:
      cnss_debug_ipc_log_print(v24, v25, "cnss_vreg_on_single", 3u, 3u, v28, v27, v29, v32);
      goto LABEL_53;
    }
    *((_DWORD *)v12 + 14) = 1;
LABEL_7:
    v12 = (__int64 *)*v12;
    if ( v12 == v11 )
      return 0;
  }
  v23 = v18;
  if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
  {
    v26 = "irq";
  }
  else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
  {
    v26 = "soft_irq";
  }
  else
  {
    v26 = (const char *)(v13 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v26,
    "cnss_vreg_on_single",
    3u,
    3u,
    "Failed to set load for regulator %s, load: %u, err = %d\n",
    v12[3],
    *((unsigned int *)v12 + 10),
    v18);
LABEL_53:
  v30 = v12[1];
  for ( result = v23; (__int64 *)v30 != v11; v30 = *(_QWORD *)(v30 + 8) )
  {
    v31 = *(_QWORD *)(v30 + 16);
    if ( v31 && v31 <= 0xFFFFFFFFFFFFF000LL && *(_DWORD *)(v30 + 56) )
    {
      cnss_vreg_off_single(v30);
      result = v23;
    }
  }
  return result;
}
