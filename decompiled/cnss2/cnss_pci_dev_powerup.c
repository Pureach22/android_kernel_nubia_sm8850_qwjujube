__int64 __fastcall cnss_pci_dev_powerup(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  __int64 v10; // x19
  int v11; // w24
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x6
  __int64 v20; // x7
  unsigned __int64 v21; // x8
  const char *v22; // x1
  unsigned __int64 StatusReg; // x8
  const char *v24; // x1
  unsigned __int64 v25; // x8
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  unsigned int v29; // w21
  unsigned int v30; // w0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  unsigned __int64 v38; // x8
  __int64 v39; // x0
  const char *v40; // x1
  __int16 v41; // w9
  const char *v42; // x8
  unsigned __int64 v43; // x8
  const char *v44; // x1
  unsigned int v45; // w0
  __int64 v46; // x1
  __int64 v47; // x2
  __int64 v48; // x3
  __int64 v49; // x4
  __int64 v50; // x5
  __int64 v51; // x6
  __int64 v52; // x7
  unsigned __int64 v53; // x8
  const char *v54; // x1
  __int16 v55; // w9
  const char *v56; // x8
  __int16 v57; // w9
  const char *v58; // x8
  int v59; // w8
  int timeout; // w22
  __int64 v61; // x1
  __int64 v62; // x2
  __int64 v63; // x3
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x6
  __int64 v67; // x7
  unsigned int started; // w0
  __int64 v69; // x7
  unsigned __int64 v70; // x24
  const char *v71; // x1
  __int64 v72; // x1
  __int64 v73; // x2
  __int64 v74; // x3
  __int64 v75; // x4
  __int64 v76; // x5
  __int64 v77; // x6
  unsigned __int64 v78; // x8
  const char *v79; // x2
  const char *v80; // x27
  unsigned int v81; // w26
  unsigned int v82; // w28
  unsigned __int64 v83; // x22
  unsigned int v84; // w0
  __int64 v85; // x7
  unsigned int v86; // w0
  unsigned int v87; // w0
  __int64 v88; // x7
  const char *v89; // x1
  __int64 v90; // x25
  const char *v91; // x19
  unsigned int input_gpio_value; // w0
  __int64 v93; // x7
  __int64 v94; // x6
  __int64 v95; // x7
  __int64 v96; // x7
  const char *v97; // x1
  unsigned int v98; // w19
  __int64 v99; // x0
  __int64 v100; // x21
  const char *v101; // x25
  __int64 v102; // x0
  unsigned int raw_value; // w0
  __int64 v104; // x7
  const char *v105; // x1
  __int64 v106; // x21
  const char *v107; // x25
  __int16 v108; // w9
  const char *v109; // x8
  const char *v110; // x1
  __int64 v111; // x1
  __int64 v112; // x2
  __int64 v113; // x3
  __int64 v114; // x4
  __int64 v115; // x5
  __int64 v116; // x6
  __int64 v117; // x7
  __int64 v118; // x20
  int v119; // w8
  __int64 v120; // x0
  const char *v121; // x1
  __int64 v122; // x7
  unsigned int v123; // w23
  __int16 v124; // w9
  const char *v125; // x8
  __int64 v126; // x1
  __int64 v127; // x2
  __int64 v128; // x3
  __int64 v129; // x4
  __int64 v130; // x5
  __int64 v131; // x6
  __int64 v132; // x7
  __int64 v133; // x1
  __int64 v134; // x2
  __int64 v135; // x3
  __int64 v136; // x4
  __int64 v137; // x5
  __int64 v138; // x6
  __int64 v139; // x7
  __int64 v140; // x6
  __int64 v141; // x7
  unsigned __int64 v142; // x8
  const char *v143; // x1
  __int16 v144; // w9
  const char *v145; // x8
  const char *v146; // x1
  __int16 v147; // w9
  const char *v148; // x8
  unsigned __int64 v156; // x10
  unsigned __int64 v159; // x10
  char v160; // [xsp+0h] [xbp-10h]
  char v161; // [xsp+0h] [xbp-10h]
  unsigned int v162; // [xsp+0h] [xbp-10h]
  char v163; // [xsp+0h] [xbp-10h]
  char v164; // [xsp+0h] [xbp-10h]
  unsigned int v165; // [xsp+4h] [xbp-Ch]
  unsigned int v166; // [xsp+4h] [xbp-Ch]
  __int64 v167; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(StatusReg + 16);
      v28 = (const char *)(StatusReg + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v24 = "soft_irq";
      else
        v24 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "cnss_pci_dev_powerup",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      v160);
    return (unsigned int)-19;
  }
  v8 = *(unsigned int *)(a1 + 24);
  if ( (unsigned int)(v8 - 4352) > 0x12 || ((1 << *(_DWORD *)(a1 + 24)) & 0x6448F) == 0 )
  {
    if ( (_DWORD)v8 == 62 )
    {
      v10 = *(_QWORD *)(a1 + 8);
      v30 = cnss_power_on_device(v10, 0);
      if ( !v30 )
      {
        v45 = cnss_resume_pci_link((_QWORD *)a1, v31, v32, v33, v34, v35, v36, v37);
        if ( v45 )
        {
          v29 = v45;
          v53 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v53 + 16) & 0xF0000) != 0 )
          {
            v54 = "irq";
          }
          else
          {
            v144 = *(_DWORD *)(v53 + 16);
            v145 = (const char *)(v53 + 2320);
            if ( (v144 & 0xFF00) != 0 )
              v54 = "soft_irq";
            else
              v54 = v145;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v54,
            "cnss_qca6174_powerup",
            3u,
            3u,
            "Failed to resume PCI link, err = %d\n",
            v45,
            v52,
            v160);
        }
        else
        {
          v29 = cnss_pci_call_driver_probe((_QWORD *)a1, v46, v47, v48, v49, v50, v51, v52);
          if ( !v29 )
            return v29;
          cnss_suspend_pci_link((_BYTE *)a1, v126, v127, v128, v129, v130, v131, v132);
        }
LABEL_141:
        cnss_power_off_device(v10);
        return v29;
      }
      v29 = v30;
      v38 = _ReadStatusReg(SP_EL0);
      v39 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v38 + 16) & 0xF0000) != 0 )
      {
        v40 = "irq";
      }
      else
      {
        v124 = *(_DWORD *)(v38 + 16);
        v125 = (const char *)(v38 + 2320);
        if ( (v124 & 0xFF00) != 0 )
          v40 = "soft_irq";
        else
          v40 = v125;
      }
      v79 = "cnss_qca6174_powerup";
      goto LABEL_116;
    }
    v43 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v43 + 16) & 0xF0000) != 0 )
    {
      v44 = "irq";
    }
    else
    {
      v55 = *(_DWORD *)(v43 + 16);
      v56 = (const char *)(v43 + 2320);
      if ( (v55 & 0xFF00) != 0 )
        v44 = "soft_irq";
      else
        v44 = v56;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v44,
      "cnss_pci_dev_powerup",
      3u,
      3u,
      "Unknown device_id found: 0x%x\n",
      v8,
      a8,
      v160);
    return (unsigned int)-19;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v25 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v25 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v41 = *(_DWORD *)(v25 + 16);
      v42 = (const char *)(v25 + 2320);
      if ( (v41 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v42;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v26,
      "cnss_qca6290_powerup",
      3u,
      3u,
      "mhi not initiated, exit\n",
      0,
      a8,
      v160);
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 8);
  v11 = *(_DWORD *)(v10 + 112);
  if ( *(_BYTE *)(v10 + 280) )
  {
    cnss_pci_clear_dump_info(a1);
    cnss_pci_power_off_mhi(a1, 0);
    cnss_suspend_pci_link((_BYTE *)a1, v12, v13, v14, v15, v16, v17, v18);
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 8) + 6680LL) & 0x80) == 0 )
    {
      if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
      {
        cnss_pci_set_mhi_state(a1, 1);
      }
      else
      {
        v21 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
        {
          v22 = "irq";
        }
        else
        {
          v57 = *(_DWORD *)(v21 + 16);
          v58 = (const char *)(v21 + 2320);
          if ( (v57 & 0xFF00) != 0 )
            v22 = "soft_irq";
          else
            v22 = v58;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v22,
          "cnss_pci_deinit_mhi",
          7u,
          7u,
          "MHI is already deinited\n",
          v19,
          v20,
          v160);
      }
    }
    cnss_power_off_device(v10);
  }
  *(_DWORD *)(a1 + 236) = 0;
  v59 = *(unsigned __int8 *)(v10 + 7880);
  *(_DWORD *)(v10 + 7568) = 0;
  if ( v59 != 1 || (cnss_is_device_powered_on(v10) & 1) == 0 || *(_BYTE *)(a1 + 48) != 1 )
  {
    v29 = cnss_power_on_device(v10, 0);
    if ( !v29 )
    {
      v80 = "irq";
      v81 = 500;
      v82 = 1;
      v83 = _ReadStatusReg(SP_EL0);
      v167 = v10;
      v160 = v11;
      while ( 1 )
      {
        v87 = cnss_resume_pci_link((_QWORD *)a1, v72, v73, v74, v75, v76, v77, v37);
        if ( !v87 )
          goto LABEL_45;
        v29 = v87;
        v89 = v80;
        if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
            v89 = "soft_irq";
          else
            v89 = (const char *)(v83 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v89,
          "cnss_qca6290_powerup",
          3u,
          3u,
          "Failed to resume PCI link, err = %d\n",
          v87,
          v88,
          v160);
        v90 = cnss_ipc_log_context;
        v91 = v80;
        if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
            v80 = "soft_irq";
          else
            v80 = (const char *)(v83 + 2320);
        }
        input_gpio_value = cnss_get_input_gpio_value(v167, v165);
        cnss_debug_ipc_log_print(
          v90,
          v80,
          "cnss_qca6290_powerup",
          7u,
          7u,
          "Value of SW_CTRL GPIO: %d\n",
          input_gpio_value,
          v93,
          v161);
        if ( (*(_QWORD *)(v167 + 6680) & 0x800) != 0 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xF0000) != 0 )
          {
            v121 = "irq";
          }
          else if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
          {
            v121 = "soft_irq";
          }
          else
          {
            v121 = (const char *)(v83 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v121,
            "cnss_qca6290_powerup",
            7u,
            7u,
            "Ignore PCI link resume failure\n",
            v94,
            v95,
            v162);
          return 0;
        }
        if ( v29 != -11 || v81 == 2500 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xF0000) != 0 )
          {
            v110 = "irq";
          }
          else if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
          {
            v110 = "soft_irq";
          }
          else
          {
            v110 = (const char *)(v83 + 2320);
          }
          v10 = v167;
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v110,
            "cnss_qca6290_powerup",
            3u,
            3u,
            "ASSERT at line %d\n",
            3966,
            v95,
            v162);
          __break(0x800u);
          goto LABEL_141;
        }
        cnss_power_off_device(v167);
        v80 = v91;
        if ( v81 == 2000 )
        {
          v97 = v91;
          if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
              v97 = "soft_irq";
            else
              v97 = (const char *)(v83 + 2320);
          }
          v98 = v162;
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v97,
            "cnss_qca6290_powerup",
            7u,
            7u,
            "Retry #%d. Set BT_EN GPIO(%u) low\n",
            4,
            v162,
            v162);
          if ( (v98 & 0x80000000) == 0 )
          {
            v99 = gpio_to_desc(v98);
            gpiod_direction_output_raw(v99, 0);
          }
          v100 = cnss_ipc_log_context;
          v101 = v80;
          if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
              v101 = "soft_irq";
            else
              v101 = (const char *)(v83 + 2320);
          }
          v102 = gpio_to_desc(v98);
          raw_value = gpiod_get_raw_value(v102);
          cnss_debug_ipc_log_print(
            v100,
            v101,
            "cnss_qca6290_powerup",
            7u,
            7u,
            "BT_EN GPIO val: %d\n",
            raw_value,
            v104,
            v163);
        }
        v105 = v80;
        if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
            v105 = "soft_irq";
          else
            v105 = (const char *)(v83 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v105,
          "cnss_qca6290_powerup",
          7u,
          7u,
          "Retry to resume PCI link #%d\n",
          v82,
          v96,
          v162);
        v106 = cnss_ipc_log_context;
        v107 = v80;
        v10 = v167;
        if ( (*(_DWORD *)(v83 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
            v107 = "soft_irq";
          else
            v107 = (const char *)(v83 + 2320);
        }
        v84 = cnss_get_input_gpio_value(v167, v166);
        cnss_debug_ipc_log_print(
          v106,
          v107,
          "cnss_qca6290_powerup",
          7u,
          7u,
          "Value of SW_CTRL GPIO: %d\n",
          v84,
          v85,
          v164);
        msleep(v81);
        v86 = cnss_power_on_device(v167, 0);
        v81 += 500;
        ++v82;
        if ( v86 )
        {
          v29 = v86;
          break;
        }
      }
    }
    v78 = _ReadStatusReg(SP_EL0);
    v39 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v78 + 16) & 0xF0000) != 0 )
    {
      v40 = "irq";
      v79 = "cnss_qca6290_powerup";
    }
    else
    {
      v108 = *(_DWORD *)(v78 + 16);
      v109 = (const char *)(v78 + 2320);
      v79 = "cnss_qca6290_powerup";
      if ( (v108 & 0xFF00) != 0 )
        v40 = "soft_irq";
      else
        v40 = v109;
    }
LABEL_116:
    cnss_debug_ipc_log_print(v39, v40, v79, 3u, 3u, "Failed to power on device, err = %d\n", v29, v37, v160);
    return v29;
  }
LABEL_45:
  cnss_pci_set_wlaon_pwr_ctrl(a1, 0, 0);
  timeout = cnss_get_timeout(v10, 0);
  started = cnss_pci_start_mhi(a1, v61, v62, v63, v64, v65, v66, v67);
  if ( started )
  {
    v29 = started;
    v70 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v70 + 16) & 0xF0000) != 0 )
    {
      v71 = "irq";
    }
    else if ( (*(_DWORD *)(v70 + 16) & 0xFF00) != 0 )
    {
      v71 = "soft_irq";
    }
    else
    {
      v71 = (const char *)(v70 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v71,
      "cnss_qca6290_powerup",
      3u,
      3u,
      "fatal: Failed to start MHI, err = %d\n",
      started,
      v69,
      v160);
    if ( (*(_QWORD *)(v10 + 552) & 0x800) == 0 )
    {
      v123 = 0;
      if ( !*(_BYTE *)(a1 + 49) && timeout )
      {
        if ( (*(_QWORD *)(v10 + 552) & 0x200) == 0 )
        {
          cnss_schedule_recovery(*(_QWORD *)a1 + 200LL, 0);
          return 0;
        }
        if ( (*(_DWORD *)(v70 + 16) & 0xF0000) != 0 )
        {
          v146 = "irq";
        }
        else if ( (*(_DWORD *)(v70 + 16) & 0xFF00) != 0 )
        {
          v146 = "soft_irq";
        }
        else
        {
          v146 = (const char *)(v70 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v146,
          "cnss_qca6290_powerup",
          3u,
          3u,
          "ASSERT at line %d\n",
          3980,
          v122,
          v160);
        v123 = 1;
        __break(0x800u);
      }
      goto LABEL_126;
    }
LABEL_125:
    v123 = 0;
LABEL_126:
    cnss_pci_set_wlaon_pwr_ctrl(a1, 1, 1);
    cnss_pci_power_off_mhi(a1, v123);
    cnss_suspend_pci_link((_BYTE *)a1, v133, v134, v135, v136, v137, v138, v139);
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 8) + 6680LL) & 0x80) == 0 )
    {
      if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
      {
        cnss_pci_set_mhi_state(a1, 1);
      }
      else
      {
        v142 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v142 + 16) & 0xF0000) != 0 )
        {
          v143 = "irq";
        }
        else
        {
          v147 = *(_DWORD *)(v142 + 16);
          v148 = (const char *)(v142 + 2320);
          if ( (v147 & 0xFF00) != 0 )
            v143 = "soft_irq";
          else
            v143 = v148;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v143,
          "cnss_pci_deinit_mhi",
          7u,
          7u,
          "MHI is already deinited\n",
          v140,
          v141,
          v160);
      }
    }
    goto LABEL_141;
  }
  if ( (*(_QWORD *)(v10 + 6680) & 4) != 0 )
  {
    _X8 = (unsigned __int64 *)(v10 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v156 = __ldxr(_X8);
    while ( __stxr(v156 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
    _X8 = (unsigned __int64 *)(v10 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v159 = __ldxr(_X8);
    while ( __stxr(v159 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
    return 0;
  }
  else
  {
    cnss_set_pin_connect_status(v10);
    if ( (*(_QWORD *)(v10 + 6680) & 0x10) != 0 )
    {
      v29 = cnss_pci_call_driver_probe((_QWORD *)a1, v111, v112, v113, v114, v115, v116, v117);
      if ( !v29 )
        return v29;
      goto LABEL_125;
    }
    if ( timeout )
    {
      v118 = jiffies;
      if ( (*(_QWORD *)(v10 + 552) & 8LL) != 0 )
        v119 = 60000;
      else
        v119 = 30000;
      v120 = _msecs_to_jiffies((unsigned int)(v119 + timeout));
      mod_timer(v10 + 6272, v120 + v118);
      return 0;
    }
    else
    {
      return 0;
    }
  }
}
