__int64 __fastcall dwc3_msm_probe(__int64 a1)
{
  const char **v1; // x20
  __int64 v3; // x22
  __int64 v4; // x0
  const char ***v5; // x19
  __int64 v6; // x0
  const char **v7; // x23
  int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x24
  unsigned __int64 v11; // x25
  const char **v12; // x8
  const char *v13; // x1
  __int64 v14; // x0
  const char *v15; // x3
  __int64 v16; // x0
  const char *v17; // x3
  const char *v18; // x0
  __int64 dir; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  _QWORD *v22; // x23
  __int64 v23; // x24
  unsigned __int64 redriver_by_phandle; // x0
  __int64 v25; // x25
  unsigned int named_gpio; // w0
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x8
  __int64 v30; // x0
  unsigned __int64 v31; // x8
  __int64 v32; // x0
  unsigned __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x1
  int v38; // w0
  unsigned __int64 v39; // x0
  __int64 v40; // x0
  unsigned __int64 v41; // x0
  unsigned __int64 v42; // x0
  unsigned __int64 v43; // x9
  __int64 v44; // x0
  unsigned __int64 v45; // x0
  __int64 v46; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x0
  int irq_byname; // w0
  const char *v50; // x26
  int v51; // w0
  int v52; // w0
  int v53; // w0
  int v54; // w0
  int v55; // w0
  _QWORD *resource_byname; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  unsigned __int64 v59; // x0
  unsigned __int64 v60; // x0
  __int64 v61; // x25
  __int64 v62; // x25
  unsigned __int64 v63; // x8
  char v64; // w9
  __int64 v65; // x0
  int v66; // w8
  unsigned __int64 v67; // x0
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x0
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x0
  unsigned __int64 v72; // x8
  __int64 compatible_node; // x0
  __int64 v74; // x0
  const char *v75; // x0
  __int64 next_available_child; // x0
  __int64 v77; // x23
  int matched; // w0
  int v79; // w8
  const char **v80; // x9
  int *v81; // x9
  int v82; // w0
  const char *v83; // x1
  unsigned __int64 phy_by_node; // x0
  const char *v85; // x1
  unsigned __int64 v86; // x0
  unsigned __int64 v87; // x0
  unsigned __int64 v88; // x0
  const char **v89; // x8
  const char **v90; // x9
  _DWORD *v91; // x9
  unsigned __int64 repeater_by_phandle; // x0
  __int64 (*v93)(void); // x8
  int v94; // w0
  const char **v95; // x23
  __int64 v96; // x0
  const char **v97; // x8
  unsigned __int64 v98; // x0
  _QWORD *v99; // x21
  __int64 v100; // x22
  unsigned int v101; // w23
  __int64 v102; // x0
  __int64 v103; // x24
  __int64 v104; // x0
  unsigned int v105; // w23
  __int64 v106; // x22
  char v107; // w26
  __int64 v108; // x24
  unsigned __int64 edev_by_phandle; // x0
  unsigned __int64 v110; // x28
  const char *edev_name; // x26
  size_t v112; // x0
  int v113; // w27
  int v114; // w26
  __int64 v115; // x27
  __int64 v116; // x26
  __int64 v117; // x0
  unsigned __int64 optional; // x0
  char v119; // w8
  __int64 v120; // x0
  unsigned int v121; // w0
  __int64 v122; // x8
  char *v123; // x9
  char v124; // t1
  int v125; // w8
  unsigned int v126; // w0
  __int64 v127; // x8
  char *v128; // x9
  char v129; // t1
  __int64 v130; // x8
  __int64 v131; // x20
  unsigned __int64 v132; // x8
  unsigned __int64 v133; // x0
  unsigned __int64 v134; // x0
  unsigned __int64 v135; // x0
  unsigned __int64 v143; // x9
  unsigned int v146; // w9
  __int64 v147; // [xsp+8h] [xbp-68h]
  __int64 v148; // [xsp+10h] [xbp-60h] BYREF
  char s[8]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v150; // [xsp+20h] [xbp-50h]
  __int64 v151; // [xsp+28h] [xbp-48h]
  __int64 v152; // [xsp+30h] [xbp-40h]
  __int64 (__fastcall *v153)(); // [xsp+38h] [xbp-38h]
  __int64 (__fastcall *v154)(); // [xsp+40h] [xbp-30h]
  __int64 v155; // [xsp+48h] [xbp-28h]
  const char ***v156; // [xsp+50h] [xbp-20h]
  __int64 v157; // [xsp+58h] [xbp-18h]
  __int64 v158; // [xsp+60h] [xbp-10h]
  __int64 v159; // [xsp+68h] [xbp-8h]

  v1 = (const char **)(a1 + 16);
  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v4 = devm_kmalloc(a1 + 16, 2824, 3520);
  if ( !v4 )
  {
    LODWORD(v11) = -12;
    goto LABEL_301;
  }
  v5 = (const char ***)v4;
  *(_QWORD *)(a1 + 168) = v4;
  v6 = *(_QWORD *)(a1 + 760);
  *v5 = v1;
  if ( !(unsigned int)of_device_is_compatible(v6, "qcom,dwc3-msm-fw-managed") )
    goto LABEL_12;
  v7 = *v5;
  *((_BYTE *)v5 + 2804) = 1;
  v8 = of_count_phandle_with_args(v7[93], "power-domains", 0);
  *((_DWORD *)v5 + 702) = v8;
  if ( v8 < 2 )
  {
    LODWORD(v11) = -22;
LABEL_70:
    dev_err(v1, "Failed to attach domains. Bail out\n");
    goto LABEL_283;
  }
  v9 = devm_kmalloc(v7, 8LL * (unsigned int)v8, 3520);
  v5[352] = (const char **)v9;
  if ( !v9 )
  {
    LODWORD(v11) = -12;
    goto LABEL_70;
  }
  if ( *((int *)v5 + 702) >= 1 )
  {
    v10 = 0;
    while ( 1 )
    {
      v5[352][v10] = (const char *)dev_pm_domain_attach_by_id(v7, (unsigned int)v10);
      if ( (unsigned __int64)v5[352][v10] >= 0xFFFFFFFFFFFFF001LL )
        break;
      if ( ++v10 >= *((int *)v5 + 702) )
        goto LABEL_12;
    }
    LODWORD(v11) = (unsigned int)v5[352][v10];
    goto LABEL_70;
  }
LABEL_12:
  v5[39] = (const char **)(v5 + 39);
  v5[40] = (const char **)(v5 + 39);
  v5[71] = (const char **)0xFFFFFFFE00000LL;
  v5[72] = (const char **)(v5 + 72);
  v5[73] = (const char **)(v5 + 72);
  v5[74] = (const char **)dwc3_resume_work;
  v5[75] = (const char **)0xFFFFFFFE00000LL;
  v5[76] = (const char **)(v5 + 76);
  v5[77] = (const char **)(v5 + 76);
  v5[78] = (const char **)dwc3_restart_usb_work;
  v5[82] = (const char **)0xFFFFFFFE00000LL;
  v5[83] = (const char **)(v5 + 83);
  v5[84] = (const char **)(v5 + 83);
  v5[85] = (const char **)dwc3_otg_sm_work;
  v5[116] = (const char **)0xFFFFFFFE00000LL;
  v5[117] = (const char **)(v5 + 117);
  v5[118] = (const char **)(v5 + 117);
  v5[119] = (const char **)msm_dwc3_perf_vote_work;
  init_timer_key(v5 + 120, &delayed_work_timer_fn, 0x200000, 0, 0);
  v12 = *v5;
  v152 = 0;
  v153 = nullptr;
  v150 = 0;
  v151 = 0;
  v13 = v12[14];
  *(_QWORD *)s = 0;
  if ( !v13 )
    v13 = *v12;
  v14 = ipc_log_context_create(12, v13, 0);
  v5[157] = (const char **)v14;
  if ( !v14 )
    dev_err(*v5, "Error getting ipc_log_ctxt\n");
  v15 = (*v5)[14];
  if ( !v15 )
    v15 = **v5;
  snprintf(s, 0x28u, "%s.ep_events", v15);
  v16 = ipc_log_context_create(24, s, 0);
  v5[158] = (const char **)v16;
  if ( !v16 )
    dev_err(*v5, "Error getting ipc_log_ctxt for ep_events\n");
  v17 = (*v5)[14];
  if ( !v17 )
    v17 = **v5;
  snprintf(s, 0x28u, "%s.trace", v17);
  dwc_trace_ipc_log_ctxt = ipc_log_context_create(36, s, 0);
  if ( !dwc_trace_ipc_log_ctxt )
    dev_err(*v5, "Error getting trace_ipc_log_ctxt for ep_events\n");
  v18 = (*v5)[14];
  if ( !v18 )
    v18 = **v5;
  dir = debugfs_create_dir(v18, 0);
  v5[323] = (const char **)dir;
  if ( dir )
  {
    debugfs_create_u8("qos_req_state", 420, dir, v5 + 324);
    debugfs_create_bool("qos_rec_start", 420, v5[323], (char *)v5 + 2593);
    debugfs_create_u8("qos_rec_index", 420, v5[323], (char *)v5 + 2594);
    debugfs_create_file("qos_rec_irq", 292, v5[323], v5, &qos_rec_irq_ops);
  }
  v20 = alloc_workqueue("dwc3_wq", 131074, 1);
  v5[80] = (const char **)v20;
  if ( !v20 )
  {
    printk(&unk_18713);
    LODWORD(v11) = -12;
    goto LABEL_301;
  }
  v21 = alloc_workqueue("k_sm_usb", 131078, 1);
  v5[81] = (const char **)v21;
  if ( !v21 )
  {
    destroy_workqueue(v5[80]);
    LODWORD(v11) = -12;
    goto LABEL_301;
  }
  v22 = *(_QWORD **)(a1 + 168);
  v23 = *v22;
  LODWORD(v148) = 0;
  redriver_by_phandle = usb_get_redriver_by_phandle(v3, "ssusb_redriver", 0);
  v22[58] = redriver_by_phandle;
  if ( redriver_by_phandle >= 0xFFFFFFFFFFFFF001LL )
  {
    v22[58] = 0;
    LODWORD(v11) = redriver_by_phandle;
    goto LABEL_32;
  }
  v25 = *v22;
  named_gpio = of_get_named_gpio(*(_QWORD *)(*v22 + 744LL), "gpios", 0);
  *((_DWORD *)v22 + 644) = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    dev_err(v25, "Failed to get gpio\n");
  }
  else if ( (devm_gpio_request_one(v25, named_gpio, 1, "dwc3-msm-orientation") & 0x80000000) != 0 )
  {
    dev_err(v25, "Failed to request gpio\n");
    *((_DWORD *)v22 + 644) = -22;
  }
  else
  {
    *((_BYTE *)v22 + 2580) = 1;
  }
  if ( (*((_BYTE *)v22 + 2804) & 1) == 0 )
  {
    v27 = devm_regulator_get(*v22, "USB3_GDSC");
    v22[55] = v27;
    if ( v27 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( v27 == -517 )
      {
LABEL_67:
        LODWORD(v11) = -517;
LABEL_125:
        dev_err(v1, "error getting clock or gdsc.\n");
LABEL_32:
        if ( (v11 & 0x80000000) != 0 )
          goto LABEL_282;
        goto LABEL_163;
      }
      v22[55] = 0;
    }
    v28 = devm_clk_get(*v22, "xo");
    if ( v28 > 0xFFFFFFFFFFFFF000LL )
      v28 = 0;
    v22[41] = v28;
    ((void (*)(void))clk_set_rate)();
    v29 = devm_clk_get(*v22, "iface_clk");
    v30 = *v22;
    v22[46] = v29;
    if ( v29 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v30, "failed to get iface_clk\n");
      LODWORD(v11) = *((_DWORD *)v22 + 92);
    }
    else
    {
      v31 = devm_clk_get(v30, "core_clk");
      v32 = *v22;
      v22[42] = v31;
      if ( v31 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v32, "failed to get core_clk\n");
        LODWORD(v11) = *((_DWORD *)v22 + 84);
      }
      else
      {
        v33 = _devm_reset_control_get(v32, "core_reset", 0, 0, 0, 1);
        v34 = *v22;
        v22[54] = v33;
        if ( v33 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v34, "failed to get core_reset\n");
          LODWORD(v11) = *((_DWORD *)v22 + 108);
        }
        else
        {
          if ( (of_property_read_variable_u32_array(*(_QWORD *)(v34 + 744), "qcom,core-clk-rate", v22 + 43, 1, 0)
              & 0x80000000) != 0 )
          {
            dev_err(*v22, "USB core-clk-rate is not present\n");
            LODWORD(v11) = -22;
            goto LABEL_125;
          }
          v35 = clk_round_rate(v22[42], v22[43]);
          v36 = *v22;
          v22[43] = v35;
          if ( (of_property_read_variable_u32_array(*(_QWORD *)(v36 + 744), "qcom,core-clk-rate-hs", v22 + 44, 1, 0)
              & 0x80000000) != 0 )
            v22[44] = v22[43];
          if ( (of_property_read_variable_u32_array(
                  *(_QWORD *)(*v22 + 744LL),
                  "qcom,core-clk-rate-disconnected",
                  v22 + 45,
                  1,
                  0)
              & 0x80000000) != 0 )
          {
            v37 = v22[43];
            v22[45] = v37;
          }
          else
          {
            v37 = v22[45];
          }
          v38 = clk_set_rate(v22[42], v37);
          if ( v38 )
            dev_err(*v22, "fail to set core_clk freq:%d\n", v38);
          v39 = devm_clk_get(*v22, "sleep_clk");
          v22[47] = v39;
          if ( v39 >= 0xFFFFFFFFFFFFF001LL )
          {
            dev_err(*v22, "failed to get sleep_clk\n");
            LODWORD(v11) = *((_DWORD *)v22 + 94);
          }
          else
          {
            clk_set_rate(v39, 32000);
            v40 = *v22;
            *((_DWORD *)v22 + 98) = 19200000;
            v41 = devm_clk_get(v40, "utmi_clk");
            v22[48] = v41;
            if ( v41 >= 0xFFFFFFFFFFFFF001LL )
            {
              dev_err(*v22, "failed to get utmi_clk\n");
              LODWORD(v11) = *((_DWORD *)v22 + 96);
            }
            else
            {
              clk_set_rate(v41, *((unsigned int *)v22 + 98));
              v42 = devm_clk_get(*v22, "bus_aggr_clk");
              if ( v42 <= 0xFFFFFFFFFFFFF000LL )
                v43 = v42;
              else
                v43 = 0;
              v44 = *v22;
              v22[51] = v43;
              v45 = devm_clk_get(v44, "noc_aggr_clk");
              v46 = *v22;
              if ( v45 <= 0xFFFFFFFFFFFFF000LL )
                v47 = v45;
              else
                v47 = 0;
              v22[52] = v47;
              if ( (of_property_match_string(*(_QWORD *)(v46 + 744), "clock-names", "cfg_ahb_clk") & 0x80000000) != 0 )
                goto LABEL_81;
              v48 = devm_clk_get(*v22, "cfg_ahb_clk");
              v22[53] = v48;
              if ( v48 < 0xFFFFFFFFFFFFF001LL )
                goto LABEL_81;
              v22[53] = 0;
              if ( (_DWORD)v48 == -517 )
                goto LABEL_67;
              LODWORD(v11) = v48;
              dev_err(*v22, "failed to get cfg_ahb_clk ret %d\n", v48);
            }
          }
        }
      }
    }
    if ( (_DWORD)v11 )
      goto LABEL_125;
  }
LABEL_81:
  *((_DWORD *)v22 + 188) = 1;
  _X8 = v22 + 86;
  __asm { PRFM            #0x11, [X8] }
  do
    v143 = __ldxr(_X8);
  while ( __stxr(v143 | 1, _X8) );
  if ( (of_property_read_variable_u32_array(v3, "qcom,lpm-to-suspend-delay-ms", (char *)v22 + 836, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)v22 + 209) = 0;
  irq_byname = platform_get_irq_byname(a1, "hs_phy_irq");
  *((_DWORD *)v22 + 129) = irq_byname;
  if ( irq_byname < 0 )
  {
    *((_DWORD *)v22 + 129) = 0;
  }
  else
  {
    irq_modify_status();
    v50 = "hs_phy_irq";
    v51 = devm_request_threaded_irq(
            v1,
            *((unsigned int *)v22 + 129),
            msm_dwc3_pwr_irq,
            msm_dwc3_pwr_irq_thread,
            139268,
            "hs_phy_irq",
            v22);
    if ( v51 )
      goto LABEL_100;
  }
  v52 = platform_get_irq_byname(a1, "pwr_event_irq");
  *((_DWORD *)v22 + 131) = v52;
  if ( (v52 & 0x80000000) == 0 )
  {
    irq_modify_status();
    v50 = "pwr_event_irq";
    v51 = devm_request_threaded_irq(
            v1,
            *((unsigned int *)v22 + 131),
            msm_dwc3_pwr_irq,
            msm_dwc3_pwr_irq_thread,
            139268,
            "pwr_event_irq",
            v22);
    if ( v51 )
    {
LABEL_100:
      LODWORD(v11) = v51;
      dev_err(v1, "irq req %s failed: %d\n\n", v50, v51);
      goto LABEL_32;
    }
    v53 = platform_get_irq_byname(a1, "dp_hs_phy_irq");
    *((_DWORD *)v22 + 133) = v53;
    if ( v53 < 0 )
    {
      *((_DWORD *)v22 + 133) = 0;
    }
    else
    {
      irq_modify_status();
      v50 = "dp_hs_phy_irq";
      v51 = devm_request_threaded_irq(
              v1,
              *((unsigned int *)v22 + 133),
              msm_dwc3_pwr_irq,
              msm_dwc3_pwr_irq_thread,
              139265,
              "dp_hs_phy_irq",
              v22);
      if ( v51 )
        goto LABEL_100;
    }
    v54 = platform_get_irq_byname(a1, "dm_hs_phy_irq");
    *((_DWORD *)v22 + 135) = v54;
    if ( v54 < 0 )
    {
      *((_DWORD *)v22 + 135) = 0;
    }
    else
    {
      irq_modify_status();
      v50 = "dm_hs_phy_irq";
      v51 = devm_request_threaded_irq(
              v1,
              *((unsigned int *)v22 + 135),
              msm_dwc3_pwr_irq,
              msm_dwc3_pwr_irq_thread,
              139265,
              "dm_hs_phy_irq",
              v22);
      if ( v51 )
        goto LABEL_100;
    }
    v55 = platform_get_irq_byname(a1, "ss_phy_irq");
    *((_DWORD *)v22 + 137) = v55;
    if ( v55 < 0 )
    {
      *((_DWORD *)v22 + 137) = 0;
    }
    else
    {
      irq_modify_status();
      v50 = "ss_phy_irq";
      v51 = devm_request_threaded_irq(
              v1,
              *((unsigned int *)v22 + 137),
              msm_dwc3_pwr_irq,
              msm_dwc3_pwr_irq_thread,
              139268,
              "ss_phy_irq",
              v22);
      if ( v51 )
        goto LABEL_100;
    }
    resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "core_base");
    if ( !resource_byname )
    {
      dev_err(v1, "missing memory base resource\n");
      goto LABEL_207;
    }
    v22[4] = *resource_byname;
    v57 = devm_ioremap(v1);
    v22[1] = v57;
    if ( !v57 )
    {
      dev_err(v1, "ioremap failed\n");
      goto LABEL_207;
    }
    if ( platform_get_resource_byname(a1, 512, "tcsr_dyn_en_dis") )
    {
      v58 = devm_ioremap(v1);
      v22[2] = v58;
      if ( !v58 )
      {
        dev_err(v1, "ioremap for tcsr_dyn_en_dis failed\n");
        goto LABEL_207;
      }
    }
    if ( platform_get_resource_byname(a1, 512, "ahb2phy_base") )
    {
      v59 = devm_ioremap(v1);
      v22[3] = v59;
      if ( v59 && v59 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( (*((_BYTE *)v22 + 2804) & 1) == 0 )
        {
          v60 = v22[55];
          if ( v60 )
          {
            if ( v60 <= 0xFFFFFFFFFFFFF000LL )
            {
              if ( (unsigned int)regulator_enable() )
                dev_err(*v22, "unable to enable usb3 gdsc\n");
              else
                qcom_clk_set_flags(v22[42], 2);
            }
          }
        }
        v61 = v22[53];
        if ( !(unsigned int)clk_prepare(v61) && (unsigned int)clk_enable(v61) )
          clk_unprepare(v61);
        if ( (unsigned int)readl_relaxed((unsigned int *)(v22[3] + 16LL)) != 17 )
        {
          writel_relaxed(0x11u, (unsigned int *)(v22[3] + 16LL));
          __dsb(0xFu);
        }
        v62 = v22[53];
        clk_disable(v62);
        clk_unprepare(v62);
        if ( (*((_BYTE *)v22 + 2804) & 1) == 0 )
        {
          v63 = v22[55];
          if ( v63 )
          {
            if ( v63 <= 0xFFFFFFFFFFFFF000LL )
            {
              qcom_clk_set_flags(v22[42], 3);
              if ( (unsigned int)regulator_disable(v22[55]) )
                dev_err(*v22, "unable to disable usb3 gdsc\n");
            }
          }
        }
      }
      else
      {
        dev_err(v23, "couldn't find ahb2phy_base addr.\n");
        v22[3] = 0;
      }
    }
    if ( platform_get_resource_byname(a1, 512, "ebc_desc") )
      v22[319] = devm_ioremap(v1);
    *(_QWORD *)s = 0;
    if ( !(unsigned int)of_property_read_string(*(_QWORD *)(*v22 + 744LL), "qcom,dbm-version", s)
      && !strcmp(*(const char **)s, "1.4") )
    {
      v22[62] = &dbm_1_4_regtable;
      *((_DWORD *)v22 + 126) = 4;
      *((_BYTE *)v22 + 508) = 1;
    }
    else
    {
      v64 = *((_BYTE *)v22 + 508);
      v22[62] = &dbm_1_5_regtable;
      *((_DWORD *)v22 + 126) = 8;
      if ( (v64 & 1) == 0 && !*((_DWORD *)v22 + 131) )
      {
        dev_err(v1, "need pwr_event_irq exiting L1\n");
LABEL_292:
        LODWORD(v11) = -22;
        goto LABEL_282;
      }
    }
    of_property_read_variable_u32_array(v3, "qcom,num-gsi-evt-buffs", v22 + 107, 1, 0);
    if ( *((_DWORD *)v22 + 214) )
    {
      of_get_property(v3, "qcom,gsi-reg-offset", &v148);
      if ( !(_DWORD)v148 )
      {
        dev_err(v23, "err provide qcom,gsi-reg-offset\n");
        goto LABEL_292;
      }
      v65 = devm_kmalloc(v23, (int)v148, 3520);
      v22[142] = v65;
      if ( !v65 )
      {
        LODWORD(v11) = -12;
        goto LABEL_282;
      }
      v66 = (int)v148 >> 2;
      *((_DWORD *)v22 + 286) = (int)v148 >> 2;
      if ( v66 != 6 )
      {
        dev_err(v23, "invalid reg offset count\n");
        goto LABEL_292;
      }
      of_property_read_variable_u32_array(*(_QWORD *)(v23 + 744), "qcom,gsi-reg-offset", v65, 6, 0);
    }
    *((_BYTE *)v22 + 749) = of_find_property(v3, "qcom,use-pdc-interrupts", 0) != 0;
    *((_BYTE *)v22 + 2561) = of_find_property(v3, "qcom,use-eusb2-phy", 0) != 0;
    *((_BYTE *)v22 + 758) = of_find_property(v3, "qcom,disable-host-ssphy-powerdown", 0) != 0;
    *((_BYTE *)v22 + 760) = of_find_property(v3, "qcom,enable_host_slow_suspend", 0) != 0;
    *((_BYTE *)v22 + 2560) = of_find_property(v3, "qcom,dis-sending-cm-l1-quirk", 0) != 0;
    *((_DWORD *)v22 + 176) = 1;
    of_property_read_variable_u32_array(v3, "qcom,default-bus-vote", v22 + 88, 1, 0);
    if ( *((_DWORD *)v22 + 176) >= 4u )
      *((_DWORD *)v22 + 176) = 3;
    v67 = of_icc_get(v23, "usb-ddr");
    if ( v67 <= 0xFFFFFFFFFFFFF000LL )
      v68 = v67;
    else
      v68 = 0;
    v22[89] = v68;
    v69 = of_icc_get(v23, "usb-ipa");
    if ( v69 <= 0xFFFFFFFFFFFFF000LL )
      v70 = v69;
    else
      v70 = 0;
    v22[90] = v70;
    v71 = of_icc_get(v23, "ddr-usb");
    if ( v71 <= 0xFFFFFFFFFFFFF000LL )
      v72 = v71;
    else
      v72 = 0;
    v22[91] = v72;
    if ( (of_property_read_variable_u32_array(v3, "qcom,pm-qos-latency", v22 + 109, 1, 0) & 0x80000000) != 0 )
      *((_DWORD *)v22 + 218) = 0;
    *((_BYTE *)v22 + 2562) = of_find_property(v3, "qcom,force-gen1", 0) != 0;
    compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-diag-dload");
    if ( compatible_node )
    {
      v74 = of_iomap(compatible_node, 0);
    }
    else
    {
      printk(&unk_16E5A);
      v74 = 0;
    }
    diag_dload = v74;
    v157 = 0;
    v158 = 0;
    v155 = 0;
    v156 = nullptr;
    v153 = nullptr;
    v154 = nullptr;
    v151 = 0;
    v152 = 0;
    *(_QWORD *)s = 0;
    v150 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v3, "qcom,wcd_usbss", 0, 0, 0, s) )
      v75 = nullptr;
    else
      v75 = *(const char **)s;
    if ( (of_device_is_available(v75) & 1) != 0 )
      *((_BYTE *)v22 + 2581) = 1;
LABEL_163:
    if ( (unsigned int)dma_set_mask(v1, -1) )
    {
      dev_err(v1, "setting DMA mask to 64 failed.\n");
      if ( (unsigned int)dma_set_mask_and_coherent(v1, 0xFFFFFFFFLL) )
      {
        dev_err(v1, "setting DMA mask to 32 failed.\n");
        LODWORD(v11) = -95;
        goto LABEL_282;
      }
    }
    else
    {
      dma_set_coherent_mask(v1, -1);
    }
    next_available_child = of_get_next_available_child(v3, 0);
    if ( next_available_child )
    {
      v77 = next_available_child;
      v148 = 0;
      matched = of_property_read_string(next_available_child, "maximum-speed", &v148);
      if ( !matched )
        matched = match_string(speed_names, 7, v148);
      v79 = matched & ~(matched >> 31);
      v80 = v5[5];
      *((_DWORD *)v5 + 283) = v79;
      if ( v80 )
        v81 = (int *)(v80[21] + 1232);
      else
        v81 = (int *)(v5 + 141);
      *v81 = v79;
      v82 = of_property_read_string(v77, "dr_mode", &v148);
      if ( !v82 )
        v82 = match_string(&usb_dr_modes, 4, v148);
      *((_DWORD *)v5 + 175) = v82 & ~(v82 >> 31);
      *((_DWORD *)v5 + 139) = of_irq_get(v77, 0);
      v157 = 0;
      v158 = 0;
      v155 = 0;
      v156 = nullptr;
      v153 = nullptr;
      v154 = nullptr;
      v151 = 0;
      v152 = 0;
      *(_QWORD *)s = 0;
      v150 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v77, "usb-phy", 0, 0, 0, s) )
        v83 = nullptr;
      else
        v83 = *(const char **)s;
      phy_by_node = devm_usb_get_phy_by_node(*v5, v83, 0);
      v5[56] = (const char **)phy_by_node;
      if ( phy_by_node >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (_DWORD)phy_by_node != -6 )
        {
          LODWORD(v11) = phy_by_node;
          if ( (_DWORD)phy_by_node != -19 )
          {
            dev_err(*v5, "unable to get hsphy device,ret:%d\n", (unsigned int)phy_by_node);
            goto LABEL_214;
          }
        }
        v5[56] = nullptr;
      }
      v157 = 0;
      v158 = 0;
      v155 = 0;
      v156 = nullptr;
      v153 = nullptr;
      v154 = nullptr;
      v151 = 0;
      v152 = 0;
      *(_QWORD *)s = 0;
      v150 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v77, "usb-phy", 0, 0, 1, s) )
        v85 = nullptr;
      else
        v85 = *(const char **)s;
      v86 = devm_usb_get_phy_by_node(*v5, v85, 0);
      v5[57] = (const char **)v86;
      if ( v86 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (_DWORD)v86 != -6 )
        {
          LODWORD(v11) = v86;
          if ( (_DWORD)v86 != -19 )
          {
            dev_err(*v5, "unable to get ssphy device,ret:%d\n", (unsigned int)v86);
            goto LABEL_214;
          }
        }
        v5[57] = nullptr;
      }
      v87 = devm_of_phy_get(*v5, v77, "usb2-phy");
      v5[59] = (const char **)v87;
      if ( v87 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (_DWORD)v87 != -6 )
        {
          LODWORD(v11) = v87;
          if ( (_DWORD)v87 != -19 )
          {
            dev_err(*v5, "failed to lookup usb2-phy,ret:%d\n", (unsigned int)v87);
            goto LABEL_214;
          }
        }
        v5[59] = nullptr;
      }
      v88 = devm_of_phy_get(*v5, v77, "usb3-phy");
      v11 = v88;
      v5[60] = (const char **)v88;
      if ( v88 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_195;
      if ( (_DWORD)v88 == -6 || (_DWORD)v88 == -19 )
      {
        v11 = 0;
        v5[60] = nullptr;
LABEL_195:
        v89 = v5[56];
        if ( !v89 && !v5[59]
          || ((v90 = v5[5]) == nullptr ? (v91 = v5 + 141) : (v91 = v90[21] + 1232),
              *v91 >= 5u && !(v11 | (unsigned __int64)v5[57])) )
        {
          LODWORD(v11) = -19;
          goto LABEL_282;
        }
        goto LABEL_218;
      }
      dev_err(*v5, "failed to lookup usb3-phy,ret:%d\n", (unsigned int)v88);
LABEL_214:
      if ( (_DWORD)v11 )
      {
        if ( (v11 & 0x80000000) != 0 )
          goto LABEL_282;
LABEL_228:
        v5[96] = (const char **)&unk_5;
        *((_DWORD *)v5 + 208) = 1;
        pm_runtime_set_autosuspend_delay(*v5, 1000);
        _pm_runtime_use_autosuspend(*v5, 1);
        v95 = *v5;
        device_set_wakeup_capable(*v5, 1);
        device_wakeup_enable(v95);
        if ( of_find_property(v3, "qcom,disable-dev-mode-pm", 0) )
        {
          _X8 = (unsigned int *)(*v5 + 60);
          __asm { PRFM            #0x11, [X8] }
          do
            v146 = __ldxr(_X8);
          while ( __stxr(v146 + 1, _X8) );
        }
        _mutex_init(v5 + 129, "&mdwc->suspend_resume_mutex", &dwc3_msm_probe___key_116);
        _mutex_init(v5 + 135, "&mdwc->role_switch_mutex", &dwc3_msm_probe___key_118);
        if ( of_find_property(v3, "usb-role-switch", 0) )
        {
          v151 = 0;
          v152 = 0;
          v153 = dwc3_msm_usb_role_switch_set_role;
          v154 = dwc3_msm_usb_role_switch_get_role;
          *(_QWORD *)s = 0;
          v150 = 0;
          LOBYTE(v155) = 1;
          *(_DWORD *)((char *)&v155 + 1) = 0;
          HIDWORD(v155) = 0;
          v156 = v5;
          v157 = 0;
          v96 = _dev_fwnode(v1);
          v97 = *v5;
          *(_QWORD *)s = v96;
          v98 = usb_role_switch_register(v97, s);
          v5[152] = (const char **)v98;
          if ( v98 > 0xFFFFFFFFFFFFF000LL )
          {
            LODWORD(v11) = v98;
            goto LABEL_281;
          }
        }
        v99 = *(_QWORD **)(a1 + 168);
        v100 = *(_QWORD *)(*v99 + 744LL);
        if ( of_find_property(v100, "extcon", 0) )
        {
          v101 = of_count_phandle_with_args(*(_QWORD *)(*v99 + 744LL), "extcon", 0);
          v102 = *v99;
          if ( (v101 & 0x80000000) != 0 )
          {
            dev_err(v102, "of_count_phandle_with_args failed\n");
            goto LABEL_281;
          }
          v103 = v101;
          v104 = devm_kmalloc(v102, 80LL * v101, 3520);
          v99[98] = v104;
          if ( !v104 )
          {
LABEL_281:
            usb_role_switch_unregister(v5[152]);
            icc_put(v5[89]);
            icc_put(v5[90]);
            icc_put(v5[91]);
            goto LABEL_282;
          }
          v147 = v100;
          if ( !v101 )
            goto LABEL_280;
          v105 = 0;
          v106 = 0;
          v107 = 0;
          v108 = 80 * v103;
          do
          {
            edev_by_phandle = extcon_get_edev_by_phandle(*v99, v105);
            v110 = edev_by_phandle;
            if ( edev_by_phandle >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( edev_by_phandle != -19 )
                goto LABEL_281;
            }
            else if ( edev_by_phandle )
            {
              *(_QWORD *)(v99[98] + v106 + 8) = v99;
              *(_QWORD *)(v99[98] + v106) = edev_by_phandle;
              *(_DWORD *)(v99[98] + v106 + 16) = v105;
              edev_name = (const char *)extcon_get_edev_name(edev_by_phandle);
              v112 = strlen(edev_name);
              if ( strnstr(edev_name, "eud", v112) )
                *(_BYTE *)(v99[98] + v106 + 72) = 1;
              *(_QWORD *)(v99[98] + v106 + 24) = dwc3_msm_vbus_notifier;
              v113 = extcon_register_notifier(v110, 1, v99[98] + v106 + 24);
              *(_QWORD *)(v99[98] + v106 + 48) = dwc3_msm_id_notifier;
              v114 = extcon_register_notifier(v110, 2, v99[98] + v106 + 48);
              if ( v113 < 0 || !(unsigned int)extcon_get_state(v110, 1) )
              {
                if ( (v114 & 0x80000000) == 0 )
                {
                  if ( (unsigned int)extcon_get_state(v110, 2) )
                  {
                    v115 = v99[98] + v106;
                    v116 = *(_QWORD *)(v115 + 8);
                    if ( v116 )
                    {
                      dwc3_dbg_print(
                        *(_QWORD *)(v116 + 1256),
                        0xFFu,
                        "extcon idx",
                        *(_DWORD *)(v115 + 16),
                        (const char *)&unk_16A05);
                      if ( *(_DWORD *)(v116 + 752) )
                      {
                        v117 = *(_QWORD *)(v116 + 1256);
                        *(_DWORD *)(v116 + 792) = *(_DWORD *)(v115 + 16);
                        *(_DWORD *)(v116 + 752) = 0;
                        dwc3_dbg_print(v117, 0xFFu, "id_state", 0, (const char *)&unk_16A05);
                        queue_work_on(32, *(_QWORD *)(v116 + 640), v116 + 568);
                      }
                    }
                  }
                }
                v107 = 1;
              }
              else
              {
                v107 = 1;
                dwc3_msm_vbus_notifier(v99[98] + v106 + 24, 1, v110);
              }
            }
            v106 += 80;
            ++v105;
          }
          while ( v108 != v106 );
          if ( (v107 & 1) == 0 )
          {
LABEL_280:
            dev_err(*v99, "no extcon device found\n");
            goto LABEL_281;
          }
          optional = devm_regulator_get_optional(v1, "dpdm");
          v119 = *((_BYTE *)v99 + 746);
          if ( optional > 0xFFFFFFFFFFFFF000LL )
            optional = 0;
          v99[149] = optional;
          if ( (v119 & 1) == 0 && optional && (unsigned int)regulator_is_enabled() )
          {
            v120 = v99[149];
            v99[146] = dwc_dpdm_cb;
            regulator_register_notifier(v120, v99 + 146);
            v100 = v147;
          }
          else
          {
            v100 = v147;
            if ( !v99[152] )
            {
              v126 = of_count_phandle_with_args(*(_QWORD *)(*v99 + 744LL), "extcon", 0);
              if ( (v126 & 0x80000000) != 0 )
              {
                dev_err(*v99, "of_count_phandle_with_args failed\n");
              }
              else if ( v126 )
              {
                v127 = v126;
                v128 = (char *)(v99[98] + 72LL);
                while ( 1 )
                {
                  v129 = *v128;
                  v128 += 80;
                  if ( (v129 & 1) == 0 )
                    break;
                  if ( !--v127 )
                    goto LABEL_261;
                }
                queue_work_on(32, v99[81], v99 + 82);
              }
            }
          }
        }
LABEL_261:
        if ( v99[152] )
        {
LABEL_296:
          *((_DWORD *)v5 + 643) = 1;
          v134 = class_create("charger");
          v5[144] = (const char **)v134;
          if ( v134 <= 0xFFFFFFFFFFFFF000LL )
          {
            v135 = device_create();
            v5[145] = (const char **)v135;
            if ( v135 <= 0xFFFFFFFFFFFFF000LL )
            {
              *(_QWORD *)(v135 + 152) = v5;
              if ( !(unsigned int)device_create_file(v5[145], &dev_attr_set_usb_online) )
              {
LABEL_300:
                LODWORD(v11) = 0;
                goto LABEL_301;
              }
              device_destroy(v5[144], 0);
            }
          }
          dev_err(v1, "fail to setup lpm_test_device\n");
          goto LABEL_300;
        }
        if ( v99[98] )
        {
          v121 = of_count_phandle_with_args(*(_QWORD *)(*v99 + 744LL), "extcon", 0);
          if ( (v121 & 0x80000000) != 0 )
          {
            dev_err(*v99, "of_count_phandle_with_args failed\n");
          }
          else if ( v121 )
          {
            v122 = v121;
            v123 = (char *)(v99[98] + 72LL);
            do
            {
              v124 = *v123;
              v123 += 80;
              if ( (v124 & 1) == 0 )
                goto LABEL_296;
            }
            while ( --v122 );
          }
        }
        v125 = *((_DWORD *)v99 + 175);
        if ( v125 == 1 )
          goto LABEL_271;
        if ( v125 == 3 )
        {
          if ( of_find_property(v100, "qcom,default-mode-host", 0) )
          {
LABEL_271:
            *((_DWORD *)v99 + 188) = 0;
LABEL_295:
            dwc3_ext_event_notify((__int64)v99);
            goto LABEL_296;
          }
          if ( of_find_property(v100, "qcom,default-mode-none", 0) )
            goto LABEL_295;
        }
        *((_BYTE *)v99 + 746) = 1;
        goto LABEL_295;
      }
      v89 = v5[56];
LABEL_218:
      if ( v89 )
      {
        repeater_by_phandle = usb_get_repeater_by_phandle(*v89, "usb-repeater", 0);
        if ( repeater_by_phandle <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( repeater_by_phandle && (v93 = *(__int64 (**)(void))(repeater_by_phandle + 80)) != nullptr )
          {
            if ( *((_DWORD *)v93 - 1) != -867545059 )
              __break(0x8228u);
            v94 = v93();
          }
          else
          {
            v94 = -22;
          }
          *((_DWORD *)v5 + 699) = v94;
        }
      }
      LODWORD(v11) = 0;
      goto LABEL_228;
    }
    dev_err(v1, "failed to find dwc3 child\n");
LABEL_207:
    LODWORD(v11) = -19;
    goto LABEL_282;
  }
  dev_err(v1, "get_irq for %s failed\n\n", "pwr_event_irq");
  LODWORD(v11) = -22;
LABEL_282:
  destroy_workqueue(v5[81]);
  destroy_workqueue(v5[80]);
  usb_put_redriver(v5[58]);
LABEL_283:
  if ( *((_BYTE *)v5 + 2804) == 1 )
  {
    v130 = *((unsigned int *)v5 + 702);
    if ( (int)v130 < 2 )
    {
      dev_err(*v5, "%s: PD count invalid\n", "dwc3_msm_modeled_domain_detach");
    }
    else
    {
      v131 = v130 - 1;
      do
      {
        v133 = (unsigned __int64)v5[352][v131];
        if ( v133 && v133 <= 0xFFFFFFFFFFFFF000LL )
          dev_pm_domain_detach();
        v132 = v131-- + 1;
      }
      while ( v132 > 1 );
    }
  }
LABEL_301:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
