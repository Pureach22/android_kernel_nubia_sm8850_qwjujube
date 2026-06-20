__int64 __fastcall cnss_update_cpr_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w4
  const char *v10; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x0
  const char *v14; // x1
  unsigned __int64 v15; // x25
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  const char *v19; // x5
  __int64 v20; // x6
  __int64 v21; // x20
  unsigned int v22; // w28
  __int64 v23; // x27
  __int64 v24; // x26
  __int64 v25; // x23
  __int64 v26; // x6
  __int64 v27; // x7
  unsigned int v28; // w24
  const char *v29; // x1
  __int64 v30; // x8
  const char *v31; // x1
  unsigned int v32; // w8
  __int64 v33; // x7
  const char *v34; // x1
  const char *v35; // x1
  char v36; // [xsp+0h] [xbp-20h]
  __int64 v37; // [xsp+10h] [xbp-10h]

  v8 = *(_DWORD *)(a1 + 6740);
  if ( !v8 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v18;
    }
    v19 = "OL CPR Voltage %dm is not valid\n";
    goto LABEL_16;
  }
  if ( *(_QWORD *)(a1 + 528) != 4355 )
    return 4294967274LL;
  v10 = *(const char **)(a1 + 7656);
  if ( v10 && (*(_QWORD *)(a1 + 7640) || *(_QWORD *)(a1 + 7648)) )
    return cnss_aop_set_vreg_param(a1, v10, 0, 1u, v8);
  v15 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v16 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v16 = "soft_irq";
  }
  else
  {
    v16 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v16,
    "cnss_update_cpr_info",
    7u,
    7u,
    "AOP interface / OL CPR Vreg not configured\n",
    a7,
    a8,
    v36);
  if ( !*(_QWORD *)(a1 + 7496) )
  {
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v31 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v31 = "soft_irq";
    }
    else
    {
      v31 = (const char *)(v15 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v31,
      "cnss_update_cpr_info",
      7u,
      7u,
      "TCS CMD not configured for OL CPR update\n",
      v20,
      a8,
      v36);
    return 0;
  }
  if ( !*(_DWORD *)(a1 + 6736) )
  {
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(v15 + 2320);
    }
    v19 = "PMIC address 0x%x is not valid\n";
LABEL_16:
    cnss_debug_ipc_log_print(v13, v14, "cnss_update_cpr_info", 3u, 3u, v19, 0, a8, v36);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(a1 + 6728) )
    goto LABEL_39;
  v21 = 0;
  v22 = 0;
  v23 = 4;
  do
  {
    v24 = 0;
    v37 = v23;
    do
    {
      v25 = *(_QWORD *)(a1 + 7504) + v23;
      if ( (unsigned int)readl_relaxed_0(v25 - 4) == *(_DWORD *)(a1 + 6736) )
      {
        v28 = readl_relaxed_0(v25);
        v29 = "irq";
        if ( (*(_DWORD *)(v15 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
            v29 = "soft_irq";
          else
            v29 = (const char *)(v15 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v29,
          "cnss_update_cpr_info",
          7u,
          7u,
          "Got voltage %dmV from i: %d, j: %d\n",
          v28,
          (unsigned int)v21,
          v24);
        if ( v28 > v22 )
        {
          v30 = *(_QWORD *)(a1 + 7496);
          v22 = v28;
          *(_QWORD *)(a1 + 6728) = v25;
          *(_QWORD *)(a1 + 6720) = v23 + v30;
        }
      }
      ++v24;
      v23 += 16;
    }
    while ( v24 != 5 );
    ++v21;
    v23 = v37 + 200;
  }
  while ( v21 != 8 );
  if ( *(_QWORD *)(a1 + 6728) )
  {
LABEL_39:
    v32 = *(_DWORD *)(a1 + 6740);
    if ( v32 <= 0x3B6 )
      v33 = 950;
    else
      v33 = v32;
    *(_DWORD *)(a1 + 6740) = v33;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v34 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v34 = "soft_irq";
    }
    else
    {
      v34 = (const char *)(v15 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v34,
      "cnss_update_cpr_info",
      7u,
      7u,
      "Update TCS CMD data address %pa with voltage %dmV\n",
      a1 + 6720,
      v33,
      v36);
    writel_relaxed_0(*(unsigned int *)(a1 + 6740), *(_QWORD *)(a1 + 6728));
    return 0;
  }
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v35 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v35 = "soft_irq";
  }
  else
  {
    v35 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v35,
    "cnss_update_cpr_info",
    3u,
    3u,
    "Failed to find proper TCS CMD data address\n",
    v26,
    v27,
    v36);
  return 4294967274LL;
}
