__int64 __fastcall cnss_wlan_register_driver(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x1
  __int64 v4; // x6
  __int64 v5; // x7
  _QWORD *v6; // x0
  __int64 v7; // x6
  __int64 v8; // x21
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x0
  const char *v14; // x1
  unsigned __int64 v15; // x8
  __int16 v16; // w9
  const char *v17; // x8
  const char *v18; // x5
  unsigned int v19; // w3
  unsigned int v20; // w4
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x6
  __int64 v25; // x7
  unsigned int timeout; // w20
  __int64 v27; // x0
  __int64 v28; // x6
  __int64 v29; // x7
  unsigned __int64 v30; // x8
  const char *v31; // x1
  __int16 v32; // w9
  const char *v33; // x8
  const char *v34; // x5
  unsigned int v35; // w3
  unsigned int v36; // w4
  unsigned __int64 v37; // x8
  const char *v38; // x1
  unsigned __int64 v39; // x8
  __int16 v40; // w9
  const char *v41; // x8
  unsigned __int64 v42; // x8
  const char *v43; // x1
  __int16 v44; // w9
  const char *v45; // x8
  _DWORD *v46; // x22
  unsigned __int64 v47; // x26
  const char *v48; // x1
  unsigned __int64 v49; // x8
  const char *v50; // x1
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x9
  _QWORD *v53; // x20
  const char *v54; // x1
  __int16 v55; // w10
  const char *v56; // x9
  __int16 v57; // w9
  const char *v58; // x8
  __int16 v59; // w9
  const char *v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  const char *v63; // x1
  __int16 v64; // w9
  const char *v65; // x8
  __int16 v66; // w9
  const char *v67; // x8
  __int16 v68; // w9
  const char *v69; // x8
  __int16 v70; // w9
  const char *v71; // x8
  __int16 v72; // w9
  const char *v73; // x8
  unsigned __int64 v80; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 128);
  if ( (cnss_check_driver_loading_allowed() & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v17;
    }
    v18 = "No cnss2 dtsi entry present";
    v19 = 6;
    v20 = 6;
LABEL_15:
    cnss_debug_ipc_log_print(v13, v14, "cnss_wlan_register_driver", v19, v20, v18, v4, v5, vars0);
    return 4294967277LL;
  }
  v6 = (_QWORD *)cnss_bus_dev_to_plat_priv(0, v3);
  if ( !v6 )
  {
    v15 = _ReadStatusReg(SP_EL0);
    v10 = cnss_ipc_log_long_context;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v32 = *(_DWORD *)(v15 + 16);
      v33 = (const char *)(v15 + 2320);
      if ( (v32 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v33;
    }
    v34 = "plat_priv is not ready for register driver\n";
    v35 = 8;
    v36 = 7;
    goto LABEL_48;
  }
  v8 = v6[1];
  if ( (v6[69] & 0x1000000) != 0 )
  {
    if ( !v1 )
      return 4294967277LL;
    while ( 1 )
    {
      v4 = *(unsigned int *)(v1 + 4);
      if ( !(_DWORD)v4 )
        return 4294967277LL;
      v22 = v6[66];
      if ( v22 == v4 )
        break;
      v1 += 40;
      if ( !v1 )
        return 4294967277LL;
    }
    if ( v22 == 4369 )
    {
      if ( *(_DWORD *)(a1 + 136) != 2 )
      {
        v61 = _ReadStatusReg(SP_EL0);
        v13 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v61 + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else
        {
          v66 = *(_DWORD *)(v61 + 16);
          v67 = (const char *)(v61 + 2320);
          if ( (v66 & 0xFF00) != 0 )
            v14 = "soft_irq";
          else
            v14 = v67;
        }
        v18 = "WLAN HW disabled. fig_v2 only supported\n";
        goto LABEL_100;
      }
    }
    else if ( v22 == 4366 )
    {
      if ( *(_DWORD *)(a1 + 136) != 2 )
      {
        v51 = _ReadStatusReg(SP_EL0);
        v13 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v51 + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else
        {
          v64 = *(_DWORD *)(v51 + 16);
          v65 = (const char *)(v51 + 2320);
          if ( (v64 & 0xFF00) != 0 )
            v14 = "soft_irq";
          else
            v14 = v65;
        }
        v18 = "WLAN HW disabled. peach_v2 only supported\n";
        goto LABEL_100;
      }
    }
    else if ( v22 == 4359 && *(_DWORD *)(a1 + 136) != 2 )
    {
      v39 = _ReadStatusReg(SP_EL0);
      v13 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v39 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v68 = *(_DWORD *)(v39 + 16);
        v69 = (const char *)(v39 + 2320);
        if ( (v68 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v69;
      }
      v18 = "WLAN HW disabled. kiwi_v2 only supported\n";
LABEL_100:
      v19 = 3;
      v20 = 3;
      goto LABEL_15;
    }
    v52 = _ReadStatusReg(SP_EL0);
    v53 = v6;
    if ( (*(_DWORD *)(v52 + 16) & 0xF0000) != 0 )
    {
      v54 = "irq";
    }
    else
    {
      v55 = *(_DWORD *)(v52 + 16);
      v56 = (const char *)(v52 + 2320);
      if ( (v55 & 0xFF00) != 0 )
        v54 = "soft_irq";
      else
        v54 = v56;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v54,
      "cnss_wlan_register_driver",
      6u,
      6u,
      "WLAN register driver deferred for device ID: 0x%x due to HW disable\n",
      v4,
      v5,
      vars0);
    v53[809] = a1;
    return 0;
  }
  if ( (v6[69] & 0x400000) == 0 )
  {
    v9 = _ReadStatusReg(SP_EL0);
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v40 = *(_DWORD *)(v9 + 16);
      v41 = (const char *)(v9 + 2320);
      if ( (v40 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v41;
    }
    v34 = "pci probe not yet done for register driver\n";
    v35 = 6;
    v36 = 6;
LABEL_48:
    cnss_debug_ipc_log_print(v10, v11, "cnss_wlan_register_driver", v35, v36, v34, v7, v5, vars0);
    return 4294967285LL;
  }
  if ( (v6[69] & 0x4000000) != 0 )
  {
    v37 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v37 + 16) & 0xF0000) != 0 )
    {
      v38 = "irq";
    }
    else
    {
      v44 = *(_DWORD *)(v37 + 16);
      v45 = (const char *)(v37 + 2320);
      if ( (v44 & 0xFF00) != 0 )
        v38 = "soft_irq";
      else
        v38 = v45;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v38,
      "cnss_wlan_register_driver",
      3u,
      3u,
      "Driver has already registered\n",
      v7,
      v5,
      vars0);
    return 4294967279LL;
  }
  else if ( (v6[69] & 0x10000) != 0 )
  {
    v42 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v42 + 16) & 0xF0000) != 0 )
    {
      v43 = "irq";
    }
    else
    {
      v57 = *(_DWORD *)(v42 + 16);
      v58 = (const char *)(v42 + 2320);
      if ( (v57 & 0xFF00) != 0 )
        v43 = "soft_irq";
      else
        v43 = v58;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v43,
      "cnss_wlan_register_driver",
      7u,
      7u,
      "Reboot/Shutdown is in progress, ignore register driver\n",
      v7,
      v5,
      vars0);
    return 4294967274LL;
  }
  else if ( v1 && (v23 = (__int64)v6, (unsigned int)pci_dev_present(v1)) )
  {
    v24 = *(unsigned int *)(a1 + 136);
    if ( (_DWORD)v24 && (v25 = *(unsigned int *)(v23 + 512), (_DWORD)v24 != (_DWORD)v25) )
    {
      v62 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v62 + 16) & 0xF0000) != 0 )
      {
        v63 = "irq";
      }
      else
      {
        v70 = *(_DWORD *)(v62 + 16);
        v71 = (const char *)(v62 + 2320);
        if ( (v70 & 0xFF00) != 0 )
          v63 = "soft_irq";
        else
          v63 = v71;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v63,
        "cnss_wlan_register_driver",
        3u,
        3u,
        "Driver built for chip ver 0x%x, enumerated ver 0x%x, reject unsupported driver\n",
        v24,
        v25,
        vars0);
      return 4294967277LL;
    }
    else
    {
      _X8 = (unsigned __int64 *)(v23 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v80 = __ldxr(_X8);
      while ( __stxr(v80 | 0x800000, _X8) );
      if ( *(_BYTE *)(v23 + 7488) != 1 || (*(_QWORD *)(v23 + 552) & 0x20000) != 0 )
      {
        *(_DWORD *)(v23 + 6312) = 0;
        return cnss_driver_event_post(v23, 7u, 5, a1);
      }
      else
      {
        *(_QWORD *)(v8 + 40) = a1;
        timeout = cnss_get_timeout(v23, 3);
        *(_QWORD *)(v23 + 720) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v23 + 728) = v23 + 728;
        *(_QWORD *)(v23 + 736) = v23 + 728;
        *(_QWORD *)(v23 + 744) = cnss_wlan_reg_driver_work;
        init_timer_key(v23 + 752, &delayed_work_timer_fn, 0x200000, 0, 0);
        v27 = _msecs_to_jiffies(timeout);
        queue_delayed_work_on(32, system_wq, v23 + 720, v27);
        v30 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v30 + 16) & 0xF0000) != 0 )
        {
          v31 = "irq";
        }
        else
        {
          v72 = *(_DWORD *)(v30 + 16);
          v73 = (const char *)(v30 + 2320);
          if ( (v72 & 0xFF00) != 0 )
            v31 = "soft_irq";
          else
            v31 = v73;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v31,
          "cnss_wlan_register_driver",
          6u,
          6u,
          "WLAN register driver deferred for Calibration\n",
          v28,
          v29,
          vars0);
        return 0;
      }
    }
  }
  else
  {
    v46 = *(_DWORD **)(a1 + 128);
    if ( v46 )
    {
      v47 = _ReadStatusReg(SP_EL0);
      do
      {
        if ( !*v46 )
          break;
        v48 = "irq";
        if ( (*(_DWORD *)(v47 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v47 + 16) & 0xFF00) != 0 )
            v48 = "soft_irq";
          else
            v48 = (const char *)(v47 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v48,
          "cnss_wlan_register_driver",
          6u,
          6u,
          "Host driver is built for PCIe device ID 0x%x\n",
          (unsigned int)v46[1],
          v5,
          vars0);
        v46 += 10;
      }
      while ( v46 );
    }
    v49 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v49 + 16) & 0xF0000) != 0 )
    {
      v50 = "irq";
    }
    else
    {
      v59 = *(_DWORD *)(v49 + 16);
      v60 = (const char *)(v49 + 2320);
      if ( (v59 & 0xFF00) != 0 )
        v50 = "soft_irq";
      else
        v50 = v60;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v50,
      "cnss_wlan_register_driver",
      3u,
      3u,
      "Enumerated PCIe device id is 0x%x, reject unsupported driver\n",
      *(unsigned int *)(v8 + 24),
      v5,
      vars0);
    return 4294967277LL;
  }
}
