__int64 __fastcall cnss_power_on_device(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x27
  unsigned __int64 StatusReg; // x25
  int v11; // w8
  const char *v12; // x1
  const char *v13; // x1
  __int64 result; // x0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x6
  __int64 v22; // x7
  const char *v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  const char *v30; // x1
  unsigned __int64 v37; // x9
  unsigned int v38; // w0
  __int64 v39; // x7
  unsigned int v40; // w20
  const char *v41; // x1
  __int64 v42; // x20
  __int64 *v43; // x22
  unsigned __int64 v44; // x8
  const char *v45; // x1
  int v46; // w8
  unsigned int v47; // w0
  __int64 v48; // x24
  unsigned int v49; // w0
  unsigned int v50; // w0
  const char *v51; // x1
  __int64 v52; // x2
  __int64 v53; // x3
  __int64 v54; // x4
  __int64 v55; // x5
  __int64 v56; // x6
  __int64 v57; // x7
  const char *v58; // x1
  __int64 v59; // x6
  __int64 v60; // x7
  const char *v61; // x1
  unsigned int v62; // w21
  const char *v63; // x1
  __int64 v64; // x7
  unsigned int v65; // w0
  __int64 v66; // x7
  const char *v67; // x1
  __int64 v68; // x2
  __int64 v69; // x3
  __int64 v70; // x4
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  __int64 v74; // x2
  __int64 v75; // x3
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  __int64 v79; // x7
  const char *v80; // x1
  unsigned __int64 v81; // x8
  const char *v82; // x1
  unsigned __int64 v85; // x10
  unsigned __int64 v88; // x10
  unsigned __int64 v91; // x10
  char v92; // [xsp+0h] [xbp-10h]
  char v93; // [xsp+0h] [xbp-10h]
  char v94; // [xsp+0h] [xbp-10h]
  char v95; // [xsp+0h] [xbp-10h]

  v8 = a1 + 4096;
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( *(_BYTE *)(a1 + 6513) )
  {
    if ( v11 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_power_on_device",
      7u,
      7u,
      "Already powered up",
      a7,
      a8,
      v92);
    return 0;
  }
  if ( v11 )
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
    cnss_ipc_log_context,
    v13,
    "cnss_power_on_device",
    6u,
    6u,
    "Device id: 0x%lx\n",
    *(_QWORD *)(a1 + 528),
    a8,
    v92);
  if ( (*(_QWORD *)(a1 + 528) == 4369 || of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "fig-direct-cx", 0))
    && (cnss_set_cx_mode(a1, 0, v15, v16, v17, v18, v19, v20) & 0x80000000) != 0 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v23 = "soft_irq";
    }
    else
    {
      v23 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_power_on_device",
      3u,
      3u,
      "Failed to set to Legacy Mode\n",
      v21,
      v22,
      v93);
  }
  cnss_wlan_hw_disable_check(a1);
  if ( (*(_QWORD *)(a1 + 552) & 0x1000000) != 0 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v30 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v30 = "soft_irq";
    }
    else
    {
      v30 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v30,
      "cnss_power_on_device",
      7u,
      7u,
      "Avoid WLAN Power On. WLAN HW Disbaled",
      v28,
      v29,
      v93);
    return 4294967274LL;
  }
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 | 0x40000000, _X8) );
  if ( (*(_BYTE *)(v8 + 3784) & 1) != 0 )
  {
    result = 4294967201LL;
    goto LABEL_113;
  }
  v38 = cnss_vreg_on_type(a1, 0, v24, v25, v26, v27, v28, v29);
  if ( v38 )
  {
    v40 = v38;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v41 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v41 = "soft_irq";
    }
    else
    {
      v41 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v41,
      "cnss_power_on_device",
      3u,
      3u,
      "Failed to turn on vreg, err = %d\n",
      v38,
      v39,
      v93);
    result = v40;
    goto LABEL_113;
  }
  v42 = a1 + 40;
  v43 = *(__int64 **)(a1 + 40);
  if ( v43 == (__int64 *)(a1 + 40) )
  {
LABEL_56:
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v51 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v51 = "soft_irq";
    }
    else
    {
      v51 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v51,
      "cnss_power_on_device",
      6u,
      6u,
      "Device id: 0x%lx\n",
      *(_QWORD *)(a1 + 528),
      v39,
      v93);
    if ( *(_QWORD *)(a1 + 528) == 4369 )
    {
      if ( (unsigned int)cnss_init_direct_cx_host_sol_gpio((_DWORD *)a1) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v58 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v58 = "soft_irq";
        }
        else
        {
          v58 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v58,
          "cnss_power_on_device",
          3u,
          3u,
          "Failed to init DCX Host SOL\n",
          v56,
          v57,
          v94);
      }
      if ( (cnss_set_direct_cx_host_sol_value(a1, 1u, v52, v53, v54, v55, v56, v57) & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v61 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v61 = "soft_irq";
        }
        else
        {
          v61 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v61,
          "cnss_power_on_device",
          3u,
          3u,
          "Failed to assert Host SOL\n",
          v59,
          v60,
          v94);
      }
    }
    v65 = cnss_select_pinctrl_enable(a1);
    if ( v65 )
    {
      v62 = v65;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v67 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v67 = "soft_irq";
      }
      else
      {
        v67 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v67,
        "cnss_power_on_device",
        3u,
        3u,
        "Failed to select pinctrl state, err = %d\n",
        v65,
        v66,
        v94);
      cnss_clk_off(a1 + 40);
      goto LABEL_112;
    }
    *(_BYTE *)(v8 + 2417) = 1;
    _X8 = (unsigned __int64 *)(a1 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v88 = __ldxr(_X8);
    while ( __stxr(v88 & 0xFFFFFFFFEFFFFFFFLL, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v91 = __ldxr(_X8);
    while ( __stxr(v91 & 0xFFFFFFFFDFFFFFFFLL, _X8) );
    cnss_enable_dev_sol_irq(a1);
    cnss_set_host_sol_value(a1, 0, v68, v69, v70, v71, v72, v73);
    return 0;
  }
  while ( 1 )
  {
    v44 = v43[2];
    if ( !v44 || v44 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_39;
    v45 = "irq";
    v46 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
    if ( *((_DWORD *)v43 + 10) )
    {
      if ( !v46 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          v45 = "soft_irq";
        else
          v45 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v45,
        "cnss_clk_on_single",
        7u,
        7u,
        "Clock %s is already enabled\n",
        v43[3],
        v39,
        v93);
      goto LABEL_39;
    }
    if ( !v46 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        v45 = "soft_irq";
      else
        v45 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v45,
      "cnss_clk_on_single",
      7u,
      7u,
      "Clock %s is being enabled\n",
      v43[3],
      v39,
      v93);
    if ( *((_DWORD *)v43 + 8) )
    {
      v47 = clk_set_rate(v43[2]);
      if ( v47 )
        break;
    }
    v48 = v43[2];
    v49 = clk_prepare(v48);
    if ( v49 )
    {
      v62 = v49;
LABEL_78:
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v63 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v63 = "soft_irq";
      }
      else
      {
        v63 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v63,
        "cnss_clk_on_single",
        3u,
        3u,
        "Failed to enable clock %s, err = %d\n",
        v43[3],
        v62,
        v93);
      goto LABEL_105;
    }
    v50 = clk_enable(v48);
    if ( v50 )
    {
      v62 = v50;
      clk_unprepare(v48);
      goto LABEL_78;
    }
    *((_DWORD *)v43 + 10) = 1;
LABEL_39:
    v43 = (__int64 *)*v43;
    if ( v43 == (__int64 *)v42 )
      goto LABEL_56;
  }
  v62 = v47;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v80 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v80 = "soft_irq";
  }
  else
  {
    v80 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v80,
    "cnss_clk_on_single",
    3u,
    3u,
    "Failed to set frequency %u for clock %s, err = %d\n",
    *((unsigned int *)v43 + 8),
    v43[3],
    v47);
LABEL_105:
  while ( 1 )
  {
    v43 = (__int64 *)v43[1];
    if ( v43 == (__int64 *)v42 )
      break;
    v81 = v43[2];
    if ( v81 && v81 <= 0xFFFFFFFFFFFFF000LL )
      cnss_clk_off_single(v43);
  }
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v82 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v82 = "soft_irq";
  }
  else
  {
    v82 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v82,
    "cnss_power_on_device",
    3u,
    3u,
    "Failed to turn on clocks, err = %d\n",
    v62,
    v64,
    v95);
LABEL_112:
  cnss_vreg_off_type((_QWORD *)a1, 0, v74, v75, v76, v77, v78, v79);
  result = v62;
LABEL_113:
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v85 = __ldxr(_X8);
  while ( __stxr(v85 & 0xFFFFFFFFBFFFFFFFLL, _X8) );
  return result;
}
