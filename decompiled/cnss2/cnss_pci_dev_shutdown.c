__int64 __fastcall cnss_pci_dev_shutdown(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x6
  __int64 v11; // x20
  __int64 v12; // x21
  unsigned __int64 v13; // x8
  const char *v14; // x1
  unsigned __int64 StatusReg; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  __int64 result; // x0
  _QWORD *v20; // x20
  __int64 v21; // x21
  unsigned __int64 v22; // x8
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  __int64 v33; // x1
  unsigned int v34; // w21
  _DWORD *v35; // x0
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  char v41; // w0
  unsigned __int64 v42; // x23
  const char *v43; // x1
  unsigned __int64 v44; // x8
  const char *v45; // x1
  __int64 v46; // x7
  unsigned int v47; // w8
  const char *v48; // x1
  __int16 v49; // w9
  const char *v50; // x8
  __int64 v51; // x6
  __int64 v52; // x7
  int v53; // w21
  __int64 v54; // x1
  __int64 v55; // x2
  __int64 v56; // x3
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  unsigned __int64 v61; // x8
  const char *v62; // x1
  unsigned __int64 v63; // x8
  const char *v64; // x1
  __int16 v65; // w9
  const char *v66; // x8
  __int64 v67; // x6
  __int64 v68; // x7
  unsigned __int64 v69; // x9
  const char *v70; // x1
  __int16 v71; // w9
  const char *v72; // x8
  __int64 v73; // x1
  __int64 v74; // x2
  __int64 v75; // x3
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  __int64 v79; // x7
  __int64 v80; // x1
  _DWORD *v81; // x0
  __int64 v82; // x1
  __int64 v83; // x2
  __int64 v84; // x3
  __int64 v85; // x4
  __int64 v86; // x5
  __int64 v87; // x6
  __int64 v88; // x7
  __int64 v89; // x7
  unsigned int v90; // w19
  unsigned __int64 v91; // x8
  const char *v92; // x1
  __int16 v93; // w9
  const char *v94; // x8
  __int16 v95; // w8
  const char *v96; // x9
  unsigned __int64 v97; // x8
  const char *v98; // x1
  __int16 v99; // w9
  const char *v100; // x8
  __int16 v101; // w9
  const char *v102; // x8
  unsigned __int64 v105; // x10
  unsigned __int64 v108; // x10
  unsigned __int64 v111; // x10
  unsigned __int64 v114; // x10
  unsigned __int64 v117; // x10
  unsigned __int64 v124; // x9
  unsigned __int64 v127; // x10
  unsigned __int64 v130; // x10
  char v131; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_pci_dev_shutdown",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      v131);
    return 4294967277LL;
  }
  v9 = *(unsigned int *)(a1 + 24);
  if ( (unsigned int)(v9 - 4352) <= 0x12 && ((1 << *(_DWORD *)(a1 + 24)) & 0x6448F) != 0 )
  {
    v12 = *(_QWORD *)a1;
    v11 = *(_QWORD *)(a1 + 8);
    if ( (*(_DWORD *)(*(_QWORD *)a1 + 700LL) & 0xFFFFFFFE) == 2 )
    {
      v13 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v24 = *(_DWORD *)(v13 + 16);
        v25 = (const char *)(v13 + 2320);
        if ( (v24 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v25;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_long_context,
        v14,
        "cnss_pci_pm_runtime_resume",
        7u,
        7u,
        "Runtime PM resume is requested by %ps\n",
        v8,
        a8,
        v131);
    }
    _pm_runtime_resume(v12 + 200, 0);
    result = cnss_pci_call_driver_remove((__int64 *)a1, v26, v27, v28, v29, v30, v31, v32);
    if ( (_DWORD)result != -11 )
    {
      v34 = result;
      v35 = (_DWORD *)cnss_bus_dev_to_plat_priv(*(_QWORD *)v11 + 16LL, v33);
      if ( v35 )
        cnss_setup_bus_bandwidth(v35, 0, 1, v36, v37, v38, v39, v40);
      *(_BYTE *)(a1 + 260) = 0;
      *(_DWORD *)(a1 + 224) = 0;
      if ( ((*(_QWORD *)(v11 + 552) & 0x10) != 0
         || (*(_QWORD *)(v11 + 552) & 0x20) != 0
         || (*(_QWORD *)(v11 + 552) & 0x40) != 0
         || (*(_QWORD *)(v11 + 552) & 0x80) != 0
         || (*(_QWORD *)(v11 + 552) & 8) != 0
         || *(_BYTE *)(v11 + 7958))
        && (*(_QWORD *)(v11 + 552) & 0x800) != 0 )
      {
        v41 = timer_delete((timer_t)(a1 + 400));
        v42 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v42 + 16) & 0xF0000) != 0 )
        {
          v43 = "irq";
        }
        else if ( (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
        {
          v43 = "soft_irq";
        }
        else
        {
          v43 = (const char *)(v42 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v43,
          "__cnss_del_rddm_timer",
          7u,
          7u,
          "Delete RDDM timer @%s(%d), ret %d\n",
          (__int64)"cnss_qca6290_shutdown",
          4050,
          v41);
        v47 = cnss_pci_collect_dump_info(a1, 0);
        if ( *(_BYTE *)(v11 + 544) )
        {
          v34 = v47;
        }
        else
        {
          v34 = v47;
          if ( (*(_DWORD *)(v42 + 16) & 0xF0000) != 0 )
          {
            v48 = "irq";
          }
          else if ( (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
          {
            v48 = "soft_irq";
          }
          else
          {
            v48 = (const char *)(v42 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v48,
            "cnss_qca6290_shutdown",
            3u,
            3u,
            "ASSERT at line %d\n",
            4054,
            v46,
            v131);
          __break(0x800u);
        }
      }
      if ( (cnss_is_device_powered_on(v11) & 1) != 0 )
      {
        cnss_pci_set_wlaon_pwr_ctrl(a1, 1, (*(_QWORD *)(v11 + 552) & 0x800LL) == 0);
        if ( !*(_BYTE *)(v11 + 280) )
        {
          _X8 = (unsigned __int64 *)(v11 + 552);
          __asm { PRFM            #0x11, [X8] }
          do
            v124 = __ldxr(_X8);
          while ( __stxr(v124 | 0x20000000, _X8) );
          v53 = *(unsigned __int8 *)(v11 + 7900);
          cnss_pci_power_off_mhi(a1, 0);
          if ( v53 == 1 )
          {
            if ( (*(_QWORD *)(*(_QWORD *)(a1 + 8) + 6680LL) & 0x80) != 0 )
            {
              v34 = 0;
            }
            else if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
            {
              cnss_pci_set_mhi_state(a1, 1);
              v34 = 0;
            }
            else
            {
              v61 = _ReadStatusReg(SP_EL0);
              if ( (*(_DWORD *)(v61 + 16) & 0xF0000) != 0 )
              {
                v62 = "irq";
              }
              else
              {
                v99 = *(_DWORD *)(v61 + 16);
                v100 = (const char *)(v61 + 2320);
                if ( (v99 & 0xFF00) != 0 )
                  v62 = "soft_irq";
                else
                  v62 = v100;
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v62,
                "cnss_pci_deinit_mhi",
                7u,
                7u,
                "MHI is already deinited\n",
                v59,
                v60,
                v131);
              v34 = 0;
            }
          }
          else
          {
            v34 = cnss_suspend_pci_link((_BYTE *)a1, v54, v55, v56, v57, v58, v59, v60);
            if ( v34 )
            {
              v69 = _ReadStatusReg(SP_EL0);
              if ( (*(_DWORD *)(v69 + 16) & 0xF0000) != 0 )
              {
                v70 = "irq";
              }
              else
              {
                v95 = *(_DWORD *)(v69 + 16);
                v96 = (const char *)(v69 + 2320);
                if ( (v95 & 0xFF00) != 0 )
                  v70 = "soft_irq";
                else
                  v70 = v96;
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v70,
                "cnss_qca6290_shutdown",
                3u,
                3u,
                "Failed to suspend PCI link, err = %d\n",
                v34,
                v68,
                v131);
            }
            if ( (*(_QWORD *)(*(_QWORD *)(a1 + 8) + 6680LL) & 0x80) == 0 )
            {
              if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
              {
                cnss_pci_set_mhi_state(a1, 1);
              }
              else
              {
                v97 = _ReadStatusReg(SP_EL0);
                if ( (*(_DWORD *)(v97 + 16) & 0xF0000) != 0 )
                {
                  v98 = "irq";
                }
                else
                {
                  v101 = *(_DWORD *)(v97 + 16);
                  v102 = (const char *)(v97 + 2320);
                  if ( (v101 & 0xFF00) != 0 )
                    v98 = "soft_irq";
                  else
                    v98 = v102;
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v98,
                  "cnss_pci_deinit_mhi",
                  7u,
                  7u,
                  "MHI is already deinited\n",
                  v67,
                  v68,
                  v131);
              }
            }
            cnss_power_off_device(v11);
          }
        }
      }
      else
      {
        v63 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v63 + 16) & 0xF0000) != 0 )
        {
          v64 = "irq";
        }
        else
        {
          v65 = *(_DWORD *)(v63 + 16);
          v66 = (const char *)(v63 + 2320);
          if ( (v65 & 0xFF00) != 0 )
            v64 = "soft_irq";
          else
            v64 = v66;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v64,
          "cnss_qca6290_shutdown",
          7u,
          7u,
          "Device is already powered off, ignore\n",
          v51,
          v52,
          v131);
      }
      result = v34;
      *(_DWORD *)(a1 + 360) = 0;
      _X8 = (unsigned __int64 *)(v11 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v105 = __ldxr(_X8);
      while ( __stxr(v105 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      _X8 = (unsigned __int64 *)(v11 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v108 = __ldxr(_X8);
      while ( __stxr(v108 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      if ( (*(_QWORD *)(v11 + 552) & 0x20) != 0 || (*(_QWORD *)(v11 + 552) & 0x80) != 0 )
      {
        _X8 = (unsigned __int64 *)(v11 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v117 = __ldxr(_X8);
        while ( __stxr(v117 & 0xFFFFFFFFFFFFF7FFLL, _X8) );
        *(_BYTE *)(a1 + 49) = 0;
      }
      _X8 = (unsigned __int64 *)(v11 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v111 = __ldxr(_X8);
      while ( __stxr(v111 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
      _X8 = (unsigned __int64 *)(v11 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v114 = __ldxr(_X8);
      while ( __stxr(v114 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
      dword_5BF90 = 0;
      print_optimize = 0;
      qword_5BF88 = 0;
    }
    return result;
  }
  if ( (_DWORD)v9 != 62 )
  {
    v44 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v44 + 16) & 0xF0000) != 0 )
    {
      v45 = "irq";
    }
    else
    {
      v49 = *(_DWORD *)(v44 + 16);
      v50 = (const char *)(v44 + 2320);
      if ( (v49 & 0xFF00) != 0 )
        v45 = "soft_irq";
      else
        v45 = v50;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v45,
      "cnss_pci_dev_shutdown",
      3u,
      3u,
      "Unknown device_id found: 0x%x\n",
      v9,
      a8,
      v131);
    return 4294967277LL;
  }
  v21 = *(_QWORD *)a1;
  v20 = *(_QWORD **)(a1 + 8);
  if ( (*(_DWORD *)(*(_QWORD *)a1 + 700LL) & 0xFFFFFFFE) == 2 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else
    {
      v71 = *(_DWORD *)(v22 + 16);
      v72 = (const char *)(v22 + 2320);
      if ( (v71 & 0xFF00) != 0 )
        v23 = "soft_irq";
      else
        v23 = v72;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v23,
      "cnss_pci_pm_runtime_resume",
      7u,
      7u,
      "Runtime PM resume is requested by %ps\n",
      v8,
      a8,
      v131);
  }
  _pm_runtime_resume(v21 + 200, 0);
  result = cnss_pci_call_driver_remove((__int64 *)a1, v73, v74, v75, v76, v77, v78, v79);
  if ( (_DWORD)result != -11 )
  {
    v81 = (_DWORD *)cnss_bus_dev_to_plat_priv(*v20 + 16LL, v80);
    if ( v81 )
      cnss_setup_bus_bandwidth(v81, 0, 1, v84, v85, v86, v87, v88);
    *(_BYTE *)(a1 + 260) = 0;
    *(_DWORD *)(a1 + 224) = 0;
    v90 = cnss_suspend_pci_link((_BYTE *)a1, v82, v83, v84, v85, v86, v87, v88);
    if ( v90 )
    {
      v91 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v91 + 16) & 0xF0000) != 0 )
      {
        v92 = "irq";
      }
      else
      {
        v93 = *(_DWORD *)(v91 + 16);
        v94 = (const char *)(v91 + 2320);
        if ( (v93 & 0xFF00) != 0 )
          v92 = "soft_irq";
        else
          v92 = v94;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v92,
        "cnss_qca6174_shutdown",
        3u,
        3u,
        "Failed to suspend PCI link, err = %d\n",
        v90,
        v89,
        v131);
    }
    cnss_power_off_device(v20);
    _X8 = v20 + 69;
    __asm { PRFM            #0x11, [X8] }
    do
      v127 = __ldxr(_X8);
    while ( __stxr(v127 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
    result = v90;
    _X8 = v20 + 69;
    __asm { PRFM            #0x11, [X8] }
    do
      v130 = __ldxr(_X8);
    while ( __stxr(v130 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
  }
  return result;
}
