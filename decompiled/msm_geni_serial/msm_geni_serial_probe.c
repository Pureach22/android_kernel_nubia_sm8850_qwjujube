__int64 __fastcall msm_geni_serial_probe(__int64 a1)
{
  __int64 *v1; // x19
  __int64 matched; // x0
  __int64 v4; // x2
  unsigned int v5; // w24
  __int64 v6; // x23
  char v7; // w25
  unsigned int v8; // w22
  int id; // w0
  void *v10; // x0
  __int64 v11; // x27
  unsigned __int64 v12; // x20
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x0
  unsigned int v18; // w0
  __int64 v19; // x0
  unsigned int v20; // w0
  int v21; // w8
  int v22; // w9
  int v23; // w8
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x0
  _QWORD *resource_byname; // x0
  __int64 v28; // x0
  int irq; // w0
  unsigned __int64 v30; // x0
  __int64 *v31; // x24
  const char *v32; // x1
  unsigned __int64 v33; // x0
  unsigned __int64 v34; // x0
  __int64 v35; // x0
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x0
  int v38; // w0
  __int64 v39; // x8
  int v40; // w3
  __int64 v41; // x0
  unsigned int v42; // w8
  unsigned int v43; // w0
  __int64 v44; // x0
  unsigned int v45; // w0
  __int64 v46; // x1
  __int64 v47; // x0
  __int64 *v48; // x8
  __int64 v49; // x0
  unsigned __int64 dir; // x0
  const char **v51; // x8
  const char *v52; // x3
  __int64 v53; // x0
  int v54; // w0
  const char **v55; // x8
  const char *v56; // x3
  __int64 v57; // x0
  __int64 v58; // x8
  const char **v59; // x8
  const char *v60; // x3
  __int64 v61; // x0
  __int64 v62; // x8
  const char **v63; // x8
  const char *v64; // x3
  __int64 v65; // x0
  __int64 v66; // x8
  const char **v67; // x8
  const char *v68; // x3
  __int64 v69; // x0
  __int64 v70; // x8
  const char **v71; // x8
  const char *v72; // x3
  __int64 v73; // x0
  __int64 v74; // x8
  const char **v75; // x8
  const char *v76; // x3
  __int64 v77; // x0
  char v78; // w8
  int v79; // w28
  __int64 v80; // x9
  unsigned __int8 v81; // w0
  __int64 v82; // x8
  unsigned __int8 v83; // w0
  int v84; // w3
  unsigned int qup_hw_version; // w24
  __int64 v86; // x0
  __int64 property; // x0
  int v88; // w8
  __int64 v89; // x0
  __int64 (__fastcall *v90)(); // x8
  __int64 v91; // x1
  __int64 v92; // x0
  int v93; // w2
  __int64 v94; // x0
  __int64 v95; // x2
  void *v96; // x0
  __int64 v97; // x24
  __int64 v98; // x0
  __int64 v99; // [xsp+10h] [xbp-30h] BYREF
  __int64 v100; // [xsp+18h] [xbp-28h]
  __int64 v101; // [xsp+20h] [xbp-20h]
  _BYTE v102[11]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v103; // [xsp+38h] [xbp-8h]

  v1 = (__int64 *)(a1 + 16);
  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  matched = of_match_device(&msm_geni_device_tbl, a1 + 16);
  if ( !matched )
  {
    dev_err(v1, "%s: No matching device found\n", "msm_geni_serial_probe");
    v5 = -19;
    goto LABEL_26;
  }
  v6 = *(_QWORD *)(matched + 192);
  v7 = uart_line_id;
  if ( *(_QWORD *)(a1 + 760) )
  {
    if ( *(_QWORD *)(v6 + 40) )
    {
      id = of_alias_get_id();
      v8 = id & ~(id >> 31);
    }
    else
    {
      if ( (unsigned __int8)uart_line_id >= 0x3Fu )
      {
        dev_err(v1, "All UART ports already initialized\n");
        v5 = -19;
        goto LABEL_26;
      }
      v20 = of_alias_get_id();
      v8 = v20;
      if ( (v20 & 0x80000000) != 0 )
      {
        if ( (uart_line_id & 0x20) != 0 )
        {
          if ( (uart_line_id & 0x10) != 0 )
          {
            if ( (uart_line_id & 8) != 0 )
            {
              if ( (uart_line_id & 4) != 0 )
              {
                if ( (uart_line_id & 2) != 0 )
                  v8 = ((unsigned __int8)uart_line_id << 31 >> 31) & v20;
                else
                  v8 = 1;
              }
              else
              {
                v8 = 2;
              }
            }
            else
            {
              v8 = 3;
            }
          }
          else
          {
            v8 = 4;
          }
        }
        else
        {
          v8 = 5;
        }
      }
      if ( ((1 << v8) & (unsigned __int8)uart_line_id) != 0 )
      {
        dev_err(v1, "Already used line %d\n", v8);
        v5 = -19;
        goto LABEL_26;
      }
      if ( v8 <= 5 )
        uart_line_id |= 1 << v8;
    }
  }
  else
  {
    v8 = *(_DWORD *)(a1 + 8);
  }
  if ( *(_QWORD *)(v6 + 40) )
    v10 = &unk_15103;
  else
    v10 = &unk_15D9F;
  printk(v10, v8, v4);
  v11 = *(_QWORD *)(v6 + 40);
  if ( v11 )
  {
    if ( v8 )
      v12 = -6;
    else
      v12 = (unsigned __int64)&msm_geni_console_port;
    if ( !v12 )
    {
LABEL_134:
      dev_err(v1, "Invalid line %d(%d)\n", v8, v12);
      v5 = v12;
      if ( !(_DWORD)v12 )
        goto LABEL_25;
      goto LABEL_24;
    }
  }
  else
  {
    if ( v8 > 5 )
    {
      v12 = -6;
      goto LABEL_134;
    }
    v12 = (unsigned __int64)&msm_geni_serial_ports + 2040 * v8;
    if ( !v12 )
      goto LABEL_134;
  }
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_134;
  *(_DWORD *)(v12 + 1516) = 0;
  *(_BYTE *)(v12 + 1036) = v11 != 0;
  if ( !*(_QWORD *)(v6 + 40) )
  {
    if ( *(_QWORD *)(v12 + 520) )
    {
      v5 = -19;
LABEL_24:
      uart_line_id = v7;
LABEL_25:
      ipc_log_string(*(_QWORD *)(v12 + 960), "%s: ret:%d\n", "msm_geni_serial_probe", v5);
      _ftrace_dbg(v1, "%s: ret:%d\n");
      goto LABEL_26;
    }
    *(_QWORD *)(v12 + 344) = v1;
    *(_QWORD *)(v12 + 520) = v6;
    v14 = *(_QWORD *)(a1 + 112);
    *(_QWORD *)(v12 + 632) = v1;
    *(_QWORD *)(v12 + 720) = v1;
    *(_QWORD *)(v12 + 624) = v14;
    *(_QWORD *)(v12 + 640) = v14;
    v15 = *(_QWORD *)(a1 + 112);
    LODWORD(v99) = 0;
    v16 = *(_QWORD *)(v15 + 152);
    *(_QWORD *)(v12 + 728) = v16;
    if ( !v16 )
    {
      dev_err(v1, "SE Wrapper is NULL, deferring probe\n");
      v5 = -517;
      goto LABEL_24;
    }
    v17 = devm_clk_get(v1, "se-clk");
    *(_QWORD *)(v12 + 736) = v17;
    if ( v17 > 0xFFFFFFFFFFFFF000LL )
    {
      v5 = v17;
      dev_err(v1, "Err getting SE Core clk %d\n", v17);
      goto LABEL_24;
    }
    v18 = geni_icc_get(v12 + 712, "qup-memory");
    if ( v18 )
    {
      v5 = v18;
      if ( (*(_BYTE *)(v12 + 1036) & 1) == 0 )
      {
        v19 = *(_QWORD *)(v12 + 960);
        *(_DWORD *)(v12 + 1120) = 4;
        ipc_log_string(v19, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 4);
        _ftrace_dbg(*(_QWORD *)(v12 + 344), "%s uart_error_code %d");
      }
      goto LABEL_24;
    }
    if ( v11 )
      v21 = 1;
    else
      v21 = 50000;
    if ( v11 )
      v22 = 1;
    else
      v22 = 140000;
    *(_DWORD *)(v12 + 768) = v21;
    if ( v11 )
      v23 = 1;
    else
      v23 = 76800;
    *(_DWORD *)(v12 + 784) = v22;
    *(_DWORD *)(v12 + 800) = v23;
    *(_BYTE *)(v12 + 1037) = of_find_property(*(_QWORD *)(a1 + 760), "qcom,rumi_platform", 0) != 0;
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wakeup-byte", &v99, 1, 0) & 0x80000000) == 0 )
    {
      v93 = (unsigned __int8)v99;
      *(_BYTE *)(v12 + 924) = v99;
      dev_info(v1, "Wakeup byte 0x%x\n", v93);
    }
    v24 = devm_clk_get(v1, "se-clk");
    *(_QWORD *)(v12 + 648) = v24;
    if ( v24 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = v24;
      dev_err(v1, "Err getting SE Core clk %d\n", v24);
      if ( (*(_BYTE *)(v12 + 1036) & 1) != 0 )
        goto LABEL_24;
    }
    else
    {
      v25 = devm_clk_get(*(_QWORD *)(a1 + 112), "m-ahb");
      *(_QWORD *)(v12 + 656) = v25;
      if ( v25 >= 0xFFFFFFFFFFFFF001LL )
      {
        v5 = v25;
        dev_err(v1, "Err getting M AHB clk %d\n", (unsigned int)v25);
      }
      else
      {
        v26 = devm_clk_get(*(_QWORD *)(a1 + 112), "s-ahb");
        *(_QWORD *)(v12 + 664) = v26;
        if ( v26 < 0xFFFFFFFFFFFFF001LL )
        {
          resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "se_phys");
          if ( !resource_byname )
          {
            dev_err(v1, "Err getting IO region\n");
            v5 = -6;
            goto LABEL_24;
          }
          *(_QWORD *)(v12 + 328) = *resource_byname;
          v28 = devm_ioremap(v1);
          *(_QWORD *)(v12 + 16) = v28;
          if ( v28 )
          {
            *(_QWORD *)(v12 + 712) = v28;
            irq = platform_get_irq(a1, 1);
            *(_DWORD *)(v12 + 920) = irq;
            if ( irq < 0 && (*(_BYTE *)(v12 + 1036) & 1) == 0 )
              dev_info(v1, "No wakeup IRQ configured\n");
            v30 = devm_pinctrl_get(v1);
            v31 = (__int64 *)(v12 + 672);
            v32 = "No pinctrl config specified!\n";
            *(_QWORD *)(v12 + 672) = v30;
            if ( !v30 || v30 > 0xFFFFFFFFFFFFF000LL )
              goto LABEL_140;
            if ( (*(_BYTE *)(v12 + 1036) & 1) == 0 )
            {
              v33 = ((__int64 (*)(void))pinctrl_lookup_state)();
              if ( v33 && v33 < 0xFFFFFFFFFFFFF001LL )
                *(_QWORD *)(v12 + 680) = pinctrl_lookup_state(*(_QWORD *)(v12 + 672), "shutdown");
              else
                dev_info(v1, "No Shutdown config specified\n");
            }
            v34 = pinctrl_lookup_state(*(_QWORD *)(v12 + 672), "active");
            *(_QWORD *)(v12 + 688) = v34;
            if ( !v34 || v34 >= 0xFFFFFFFFFFFFF001LL )
            {
              v35 = *v31;
              v31 = (__int64 *)(v12 + 688);
              v36 = pinctrl_lookup_state(v35, "default");
              v32 = "No default config specified!\n";
              *(_QWORD *)(v12 + 688) = v36;
              if ( !v36 || v36 > 0xFFFFFFFFFFFFF000LL )
                goto LABEL_140;
            }
            v37 = pinctrl_lookup_state(*(_QWORD *)(v12 + 672), "sleep");
            v31 = (__int64 *)(v12 + 696);
            v32 = "No sleep config specified!\n";
            *(_QWORD *)(v12 + 696) = v37;
            if ( v37 && v37 <= 0xFFFFFFFFFFFFF000LL )
            {
              v38 = platform_get_irq(a1, 0);
              v39 = *(_QWORD *)(v12 + 344);
              v40 = *(_DWORD *)(v12 + 316);
              *(_DWORD *)(v12 + 168) = v38;
              v41 = devm_kasprintf(v39, 3264, "msm_serial_geni%d", v40);
              v42 = *(_DWORD *)(v12 + 168);
              *(_QWORD *)(v12 + 544) = v41;
              irq_modify_status(v42, 0, 4096);
              v43 = devm_request_threaded_irq(
                      *(_QWORD *)(v12 + 344),
                      *(unsigned int *)(v12 + 168),
                      msm_geni_serial_isr,
                      0,
                      4,
                      *(_QWORD *)(v12 + 544),
                      v12);
              if ( v43 )
              {
                v5 = v43;
                dev_err(
                  *(_QWORD *)(v12 + 344),
                  "%s: Failed to get IRQ ret %d\n",
                  "msm_geni_serial_get_irq_pinctrl",
                  v43);
                goto LABEL_24;
              }
              if ( *(int *)(v12 + 920) >= 1 )
              {
                v44 = alloc_workqueue("%s", byte_12);
                *(_QWORD *)(v12 + 1352) = v44;
                if ( !v44 )
                {
                  dev_err(
                    *(_QWORD *)(v12 + 344),
                    "%s:WQ alloc failed for Wakeup IRQ\n",
                    "msm_geni_serial_get_irq_pinctrl");
                  v5 = -12;
                  goto LABEL_24;
                }
                *(_QWORD *)(v12 + 1360) = 0xFFFFFFFE00000LL;
                *(_QWORD *)(v12 + 1368) = v12 + 1368;
                *(_QWORD *)(v12 + 1376) = v12 + 1368;
                *(_QWORD *)(v12 + 1384) = msm_geni_wakeup_work;
                init_timer_key(v12 + 1392, &delayed_work_timer_fn, 0x200000, 0, 0);
                irq_modify_status(*(unsigned int *)(v12 + 920), 0, 4096);
                v45 = devm_request_threaded_irq(
                        *(_QWORD *)(v12 + 344),
                        *(unsigned int *)(v12 + 920),
                        msm_geni_wakeup_isr,
                        0,
                        8194,
                        "hs_uart_wakeup",
                        v12);
                if ( v45 )
                {
                  v5 = v45;
                  dev_err(
                    *(_QWORD *)(v12 + 344),
                    "%s:Failed to get WakeIRQ ret%d\n",
                    "msm_geni_serial_get_irq_pinctrl",
                    v45);
                  destroy_workqueue(*(_QWORD *)(v12 + 1352));
                  goto LABEL_24;
                }
                *(_BYTE *)(v12 + 1042) = 0;
              }
            }
            else
            {
LABEL_140:
              dev_err(v1, v32);
              v5 = *(_DWORD *)v31;
              if ( v5 )
                goto LABEL_24;
            }
            if ( v11 )
              goto LABEL_187;
            v46 = *(_QWORD *)(a1 + 128);
            if ( !v46 )
              v46 = *v1;
            v47 = wakeup_source_register(*(_QWORD *)(v12 + 344), v46);
            *(_QWORD *)(v12 + 928) = v47;
            if ( v47 )
            {
LABEL_187:
              if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,split-tx-dma-tre", 0) )
                *(_BYTE *)(v12 + 2000) = 1;
              v48 = *(__int64 **)(v12 + 344);
              v101 = 0;
              memset(v102, 0, sizeof(v102));
              v49 = v48[14];
              v99 = 0;
              v100 = 0;
              if ( !v49 )
                v49 = *v48;
              dir = debugfs_create_dir(v49, 0);
              *(_QWORD *)(v12 + 592) = dir;
              if ( !dir || dir >= 0xFFFFFFFFFFFFF001LL )
                dev_err(*(_QWORD *)(v12 + 344), "Failed to create dbg dir\n");
              v101 = 0;
              memset(v102, 0, sizeof(v102));
              v99 = 0;
              v100 = 0;
              if ( v11 )
              {
                if ( !*(_QWORD *)(v12 + 984) )
                {
                  v51 = *(const char ***)(v12 + 344);
                  v52 = v51[14];
                  if ( !v52 )
                    v52 = *v51;
                  scnprintf(&v99, 35, "%s%s", v52, "_console");
                  v53 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 984) = v53;
                  if ( !v53 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in Misc IPC Log\n");
                }
              }
              else
              {
                if ( !*(_QWORD *)(v12 + 944) )
                {
                  v55 = *(const char ***)(v12 + 344);
                  v56 = v55[14];
                  if ( !v56 )
                    v56 = *v55;
                  scnprintf(&v99, 35, "%s%s", v56, "_rx");
                  v57 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 944) = v57;
                  if ( !v57 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in Rx IPC Log\n");
                }
                v58 = *(_QWORD *)(v12 + 936);
                v101 = 0;
                memset(v102, 0, sizeof(v102));
                v99 = 0;
                v100 = 0;
                if ( !v58 )
                {
                  v59 = *(const char ***)(v12 + 344);
                  v60 = v59[14];
                  if ( !v60 )
                    v60 = *v59;
                  scnprintf(&v99, 35, "%s%s", v60, "_tx");
                  v61 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 936) = v61;
                  if ( !v61 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in Tx IPC Log\n");
                }
                v62 = *(_QWORD *)(v12 + 952);
                v101 = 0;
                memset(v102, 0, sizeof(v102));
                v99 = 0;
                v100 = 0;
                if ( !v62 )
                {
                  v63 = *(const char ***)(v12 + 344);
                  v64 = v63[14];
                  if ( !v64 )
                    v64 = *v63;
                  scnprintf(&v99, 35, "%s%s", v64, "_pwr");
                  v65 = ipc_log_context_create(10, &v99, 0);
                  *(_QWORD *)(v12 + 952) = v65;
                  if ( !v65 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in Pwr IPC Log\n");
                }
                v66 = *(_QWORD *)(v12 + 960);
                v101 = 0;
                memset(v102, 0, sizeof(v102));
                v99 = 0;
                v100 = 0;
                if ( !v66 )
                {
                  v67 = *(const char ***)(v12 + 344);
                  v68 = v67[14];
                  if ( !v68 )
                    v68 = *v67;
                  scnprintf(&v99, 35, "%s%s", v68, "_misc");
                  v69 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 960) = v69;
                  if ( !v69 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in Misc IPC Log\n");
                }
                v70 = *(_QWORD *)(v12 + 992);
                v101 = 0;
                memset(v102, 0, sizeof(v102));
                v99 = 0;
                v100 = 0;
                if ( !v70 )
                {
                  v71 = *(const char ***)(v12 + 344);
                  v72 = v71[14];
                  if ( !v72 )
                    v72 = *v71;
                  scnprintf(&v99, 35, "%s%s", v72, "_irqstatus");
                  v73 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 992) = v73;
                  if ( !v73 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err in irqstatus IPC Log\n");
                }
                v74 = *(_QWORD *)(v12 + 976);
                v101 = 0;
                memset(v102, 0, sizeof(v102));
                v99 = 0;
                v100 = 0;
                if ( !v74 )
                {
                  v75 = *(const char ***)(v12 + 344);
                  v76 = v75[14];
                  if ( !v76 )
                    v76 = *v75;
                  scnprintf(&v99, 35, "%s%s", v76, "_new");
                  v77 = ipc_log_context_create(30, &v99, 0);
                  *(_QWORD *)(v12 + 976) = v77;
                  if ( !v77 )
                    dev_info(*(_QWORD *)(v12 + 344), "Err with New IPC Log\n");
                }
              }
              v78 = *(_BYTE *)(v12 + 1036);
              LODWORD(v101) = 0;
              v99 = 0;
              v100 = 0;
              if ( (v78 & 1) == 0 )
              {
                *(_QWORD *)(v12 + 1128) = 33;
                msm_geni_se_clks_on_off(v12, 1);
              }
              v79 = readl_relaxed((unsigned int *)(*(_QWORD *)(v12 + 16) + 104LL)) & 0xFF00;
              if ( v79 == 512 )
              {
                v80 = *(_QWORD *)(v12 + 16);
                *(_DWORD *)(v12 + 704) = 2;
                v81 = readl_relaxed((unsigned int *)(v80 + 104));
                v82 = *(_QWORD *)(v12 + 16);
                *(_DWORD *)(v12 + 1024) = v81;
                v83 = readl_relaxed((unsigned int *)(v82 + 108));
                v84 = *(_DWORD *)(v12 + 1024);
                *(_DWORD *)(v12 + 1028) = v83;
                scnprintf(&v99, 40, "FW Ver:0x%x%x", v84, v83);
                qup_hw_version = geni_se_get_qup_hw_version(v12 + 712);
                ipc_log_string(
                  *(_QWORD *)(v12 + 960),
                  "%s: FW Ver: %s HW Ver: 0x%x\n",
                  "msm_geni_serial_get_ver_info",
                  (const char *)&v99,
                  qup_hw_version);
                _ftrace_dbg(*(_QWORD *)(v12 + 344), "%s: FW Ver: %s HW Ver: 0x%x\n");
                *(_DWORD *)(v12 + 1012) = qup_hw_version >> 28;
                *(_DWORD *)(v12 + 1016) = HIWORD(qup_hw_version) & 0xFFF;
                *(_DWORD *)(v12 + 1020) = (unsigned __int16)qup_hw_version;
                msm_geni_serial_enable_interrupts(v12);
                v5 = 0;
                if ( (*(_BYTE *)(v12 + 1036) & 1) != 0 )
                  goto LABEL_127;
              }
              else
              {
                v97 = *(_QWORD *)(v12 + 344);
                v98 = readl_relaxed((unsigned int *)(*(_QWORD *)(v12 + 16) + 104LL));
                dev_err(v97, "%s: Invalid FW %d loaded.\n", "msm_geni_serial_get_ver_info", BYTE1(v98));
                v5 = -6;
                if ( (*(_BYTE *)(v12 + 1036) & 1) != 0 )
                {
LABEL_127:
                  if ( v79 == 512 )
                  {
                    *(_QWORD *)(v12 + 552) = 0x2000000010LL;
                    *(_DWORD *)(v12 + 560) = 16;
                    *(_DWORD *)(v12 + 188) = 64;
                    *(_DWORD *)(v12 + 1048) = 0;
                    _init_swait_queue_head(v12 + 1056, "&x->wait", &init_completion___key);
                    *(_DWORD *)(v12 + 1080) = 0;
                    _init_swait_queue_head(v12 + 1088, "&x->wait", &init_completion___key);
                    *(_DWORD *)(v12 + 1264) = 0;
                    _init_swait_queue_head(v12 + 1272, "&x->wait", &init_completion___key);
                    *(_DWORD *)(v12 + 1296) = 0;
                    _init_swait_queue_head(v12 + 1304, "&x->wait", &init_completion___key);
                    *(_DWORD *)(v12 + 1464) = 0;
                    _init_swait_queue_head(v12 + 1472, "&x->wait", &init_completion___key);
                    v86 = *(_QWORD *)(a1 + 760);
                    *(_QWORD *)(a1 + 168) = v12;
                    property = of_find_property(v86, "qcom,auto-suspend-disable", 0);
                    v88 = *(unsigned __int8 *)(v12 + 1036);
                    *(_BYTE *)(v12 + 1336) = property != 0;
                    v89 = *(_QWORD *)(v12 + 344);
                    if ( v88 == 1 )
                    {
                      v90 = handle_rx_console;
                      v91 = 4;
                    }
                    else
                    {
                      v91 = 4LL * *(unsigned int *)(v12 + 560);
                      v90 = handle_rx_hs;
                    }
                    *(_QWORD *)(v12 + 616) = v90;
                    v92 = devm_kmalloc(v89, v91, 3520);
                    *(_QWORD *)(v12 + 608) = v92;
                    if ( v92 )
                    {
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_loopback);
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_xfer_mode);
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_ver_info);
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_hs_uart_operation);
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_hs_uart_version);
                      device_create_file(*(_QWORD *)(v12 + 344), &dev_attr_capture_kpi);
                      dev_info(
                        v1,
                        "Serial port: %d added.FifoSize: %d is_console: %d\n",
                        v8,
                        *(_DWORD *)(v12 + 188),
                        v11 != 0);
                      *(_BYTE *)(v12 + 600) = 0;
                      *(_DWORD *)(v12 + 1120) = 0;
                      msm_geni_serial_init_gsi(v12);
                      if ( (*(_BYTE *)(v12 + 1036) & 1) == 0 )
                        *(_DWORD *)(v12 + 1112) = 0;
                      v5 = uart_add_one_port(v6, v12);
                      if ( v5 )
                        dev_err(v1, "Failed to register uart_port: %d\n", v5);
                      if ( (*(_BYTE *)(v12 + 1036) & 1) == 0 )
                      {
                        msm_geni_se_clks_on_off(v12, 1);
                        msm_geni_check_stop_engine(v12);
                        msm_geni_se_clks_on_off(v12, 0);
                        if ( *(_BYTE *)(v12 + 1336) == 1 )
                        {
                          _pm_runtime_set_status(v1, 0);
                          pm_runtime_forbid(v1);
                        }
                        else
                        {
                          _pm_runtime_set_status(v1, 2);
                          pm_runtime_set_autosuspend_delay(v1, 150);
                          _pm_runtime_use_autosuspend(v1, 1);
                          pm_runtime_enable(v1);
                        }
                      }
                      if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,suspend-ignore-children", 0) )
                        *(_WORD *)(*(_QWORD *)(v12 + 344) + 488LL) |= 0x100u;
                      if ( v11 )
                        v96 = &unk_1588A;
                      else
                        v96 = &unk_15130;
                      printk(v96, v8, v95);
                      if ( !v5 )
                        goto LABEL_25;
                    }
                    else
                    {
                      v5 = -12;
                    }
                  }
                  else
                  {
                    dev_err(v1, "Failed to Read FW ver: %d\n", v5);
                  }
                  goto LABEL_24;
                }
              }
              msm_geni_se_clks_on_off(v12, 0);
              goto LABEL_127;
            }
            dev_err(v1, "Failed to register wakeup_source\n");
          }
          else
          {
            dev_err(v1, "Err IO mapping serial iomem\n");
          }
          v5 = -12;
          goto LABEL_24;
        }
        v5 = v26;
        dev_err(v1, "Err getting S AHB clk %d\n", (unsigned int)v26);
      }
      if ( (*(_BYTE *)(v12 + 1036) & 1) != 0 )
        goto LABEL_24;
    }
    v94 = *(_QWORD *)(v12 + 960);
    *(_DWORD *)(v12 + 1120) = 2;
    ipc_log_string(v94, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 2);
    _ftrace_dbg(*(_QWORD *)(v12 + 344), "%s uart_error_code %d");
    goto LABEL_24;
  }
  dev_err(v1, "%s, Console Disabled\n", "msm_geni_serial_probe");
  v54 = pinctrl_pm_select_sleep_state(v1);
  if ( v54 )
    dev_err(v1, "failed to set pinctrl state to sleep %d\n", v54);
  v5 = 0;
  *(_QWORD *)(a1 + 168) = v12;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v5;
}
