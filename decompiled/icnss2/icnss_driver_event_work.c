__int64 __fastcall icnss_driver_event_work(__int64 a1)
{
  __int64 v2; // x28
  __int64 v3; // x25
  _QWORD *v4; // x21
  _QWORD *v5; // x27
  __int64 v6; // x23
  _QWORD *v7; // x8
  __int64 v8; // x9
  __int64 v9; // x4
  const char *v10; // x2
  const char *v11; // x3
  __int64 v12; // x0
  int v13; // w2
  __int64 v14; // x25
  unsigned int v15; // w26
  unsigned int v16; // w0
  __int64 v17; // x2
  int v18; // w8
  int v19; // w1
  unsigned __int8 *v20; // x25
  unsigned int restarted; // w0
  __int64 v22; // x25
  int v23; // w2
  __int64 v24; // x8
  __int64 *v25; // x24
  __int64 v26; // x10
  int v27; // w27
  unsigned int v28; // w8
  unsigned int v29; // w24
  __int64 v30; // x20
  _QWORD *v31; // x25
  __int64 v32; // x8
  __int64 v33; // x2
  __int64 v34; // x9
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x0
  unsigned __int8 *v37; // x25
  __int64 v38; // x8
  int v39; // w8
  __int64 *v40; // x8
  __int64 v41; // x0
  __int16 v42; // w9
  __int64 v43; // x8
  __int64 v44; // x2
  void (__fastcall *v45)(__int64, __int64 *); // x8
  __int64 v46; // x0
  unsigned int *v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  unsigned int *v53; // x20
  unsigned __int64 v54; // x27
  const char *v55; // x25
  __int64 *v56; // x2
  int v57; // w2
  __int64 v58; // x8
  __int64 **v59; // x8
  __int64 v60; // x9
  unsigned int v61; // w8
  unsigned int v62; // w25
  __int64 v63; // x20
  _QWORD *v64; // x24
  __int64 v65; // x0
  __int64 v66; // x2
  __int64 v67; // x9
  __int64 (__fastcall *v68)(_QWORD); // x8
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x9
  void (__fastcall *v72)(_QWORD); // x8
  __int64 v73; // x0
  __int64 v74; // x0
  unsigned __int8 *v75; // x1
  __int64 v76; // x28
  __int64 v77; // x10
  int v78; // w8
  __int64 v79; // x3
  __int64 *v80; // x11
  __int64 *v81; // x12
  bool v82; // cc
  char *v83; // x13
  unsigned __int64 v84; // x12
  bool v85; // cc
  __int64 v87; // x0
  __int64 v88; // x2
  unsigned int v89; // w20
  __int64 v90; // x9
  __int64 (__fastcall *v91)(_QWORD); // x8
  __int64 v92; // x0
  unsigned int v93; // w0
  __int64 v94; // x0
  __int64 (__fastcall *v95)(_QWORD); // x8
  int v96; // w25
  const char *v97; // x25
  unsigned int inited; // w0
  __int64 v99; // x8
  unsigned int v100; // w8
  unsigned int ready; // w0
  __int64 v102; // x8
  __int64 v103; // x8
  __int64 v104; // x1
  __int64 v105; // x0
  const void *v106; // x0
  const void *v107; // x3
  unsigned int v108; // w8
  __int64 v109; // x9
  unsigned int v110; // w10
  unsigned int phy_ucode; // w0
  unsigned int aux; // w0
  __int64 v113; // x8
  const char *v114; // x25
  unsigned __int64 v117; // x9
  unsigned __int64 v120; // x9
  unsigned __int64 v123; // x9
  unsigned __int64 v126; // x9
  __int64 *v127; // x9
  unsigned __int64 v130; // x9
  unsigned __int64 v133; // x9
  unsigned __int64 v136; // x9
  unsigned __int64 v139; // x9
  __int64 v140; // x8
  __int64 v141; // x2
  void (__fastcall *v142)(__int64, __int64 *); // x8
  __int64 v143; // x0
  __int64 v144; // x3
  const char *v145; // x2
  __int64 v146; // x4
  const char *v147; // x3
  unsigned __int64 v150; // x9
  unsigned __int64 v153; // x9
  unsigned __int64 v156; // x9
  unsigned __int64 v159; // x9
  unsigned __int64 v162; // x9
  unsigned __int64 v165; // x9
  unsigned __int64 v168; // x9
  unsigned __int64 v171; // x9
  unsigned __int64 v174; // x9
  __int64 result; // x0
  unsigned int v182; // w8
  unsigned int v183; // w8
  unsigned int v186; // w8
  unsigned int v187; // w8
  unsigned int v188; // [xsp+Ch] [xbp-D4h]
  const void **v189; // [xsp+18h] [xbp-C8h]
  _QWORD *v190; // [xsp+40h] [xbp-A0h]
  unsigned int *v191; // [xsp+50h] [xbp-90h]
  __int64 *v192; // [xsp+60h] [xbp-80h]
  __int64 *v193; // [xsp+78h] [xbp-68h]
  __int64 *v194; // [xsp+80h] [xbp-60h]
  __int64 v195; // [xsp+88h] [xbp-58h]
  __int64 *v196; // [xsp+98h] [xbp-48h] BYREF
  __int64 **v197; // [xsp+A0h] [xbp-40h]
  __int64 v198; // [xsp+A8h] [xbp-38h] BYREF
  __int64 **v199; // [xsp+B0h] [xbp-30h]
  __int64 v200; // [xsp+B8h] [xbp-28h]
  __int64 v201; // [xsp+C0h] [xbp-20h]
  __int64 v202; // [xsp+C8h] [xbp-18h]
  __int64 v203; // [xsp+D0h] [xbp-10h]

  v203 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _X9 = (unsigned int *)(a1 + 1240);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v182 = __ldxr(_X9);
    v183 = v182 + 1;
  }
  while ( __stlxr(v183, _X9) );
  __dmb(0xBu);
  if ( v183 == 1 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a1 + 152),
      *(_DWORD *)(a1 + 1240));
    pm_stay_awake(*(_QWORD *)(a1 - 1672) + 16LL);
    ++*(_DWORD *)(a1 + 876);
  }
  v2 = a1 - 40;
  v3 = raw_spin_lock_irqsave(a1 - 40);
  v5 = (_QWORD *)(a1 - 72);
  v4 = *(_QWORD **)(a1 - 72);
  if ( v4 != (_QWORD *)(a1 - 72) )
  {
    v195 = a1 - 1680;
    v193 = (__int64 *)(a1 - 1672);
    v190 = (_QWORD *)(a1 - 1128);
    v192 = (__int64 *)(a1 - 1376);
    v6 = a1 + 1608;
    v189 = (const void **)(a1 - 1120);
    v194 = (__int64 *)(a1 - 1664);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v7 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v7 == v4 && (v8 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        *(_QWORD *)(v8 + 8) = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(v2, v3);
      v9 = *((unsigned int *)v4 + 4);
      v10 = "UNKNOWN";
      if ( (unsigned int)v9 <= 0x12 )
        v10 = off_A8830[v9];
      if ( *((_BYTE *)v4 + 20) )
        v11 = "-sync";
      else
        v11 = (const char *)&unk_12DBF3;
      v12 = ipc_log_string(icnss_ipc_log_context, "icnss2: Processing event: %s%s(%d), state: 0x%lx\n", v10, v11);
      v13 = *((_DWORD *)v4 + 4);
      switch ( v13 )
      {
        case 0:
          v14 = v4[8];
          LODWORD(v198) = 0;
          if ( a1 == 1680 )
          {
            v15 = -19;
            goto LABEL_368;
          }
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v117 = __ldxr(_X8);
          while ( __stxr(v117 | 0x400, _X8) );
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v120 = __ldxr(_X8);
          while ( __stxr(v120 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v123 = __ldxr(_X8);
          while ( __stxr(v123 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
          icnss_ignore_fw_timeout(0);
          if ( (*(_QWORD *)(a1 + 152) & 1) != 0 )
          {
            printk("%sicnss2: QMI Server already in Connected State\n", byte_130B32);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2: QMI Server already in Connected State\n",
              (const char *)&unk_12DBF3);
          }
          v15 = icnss_connect_to_fw_server(v195, v14);
          if ( v15 )
            goto LABEL_368;
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v150 = __ldxr(_X8);
          while ( __stxr(v150 | 1, _X8) );
          if ( *v192 == 43981 || *v192 == 30544 )
          {
            v15 = icnss_hw_power_on(v195);
            if ( v15 )
              goto LABEL_368;
          }
          v16 = wlfw_ind_register_send_sync_msg(v195);
          if ( (v16 & 0x80000000) != 0 )
          {
            if ( v16 == -114 )
              v15 = 0;
            else
              v15 = v16;
            goto LABEL_368;
          }
          if ( *(_BYTE *)(a1 + 4290) == 1 )
          {
            v17 = *(unsigned int *)(a1 + 4292);
            if ( (_DWORD)v17 == 1 )
              v18 = 1;
            else
              v18 = 0x7FFFFFFF;
            if ( (_DWORD)v17 )
              v19 = v18;
            else
              v19 = 0;
            if ( v19 == 0x7FFFFFFF )
            {
              ipc_log_string(icnss_ipc_log_context, "icnss2: Invalid rf subtype %d in DT\n", v17);
            }
            else
            {
              inited = wlfw_wlan_hw_init_cfg_msg(v195);
              if ( (inited & 0x80000000) != 0 )
                ipc_log_string(icnss_ipc_log_context, "icnss2: Sending rf_subtype failed ret %d\n", inited);
            }
          }
          v99 = *v192;
          if ( *v192 != 25680 && v99 != 30544 && v99 != 26448 )
            goto LABEL_255;
          if ( !(unsigned int)icnss_get_temperature(v195) )
          {
            ipc_log_string(icnss_ipc_log_context, "icnss2: Temperature: %d\n", v198);
            if ( (int)v198 <= 4999 )
            {
              v100 = *(_DWORD *)(a1 + 4104);
              if ( v100 <= 0x1F4 )
                v100 = 500;
              *(_DWORD *)(a1 + 4100) = v100;
            }
          }
          ready = wlfw_host_cap_send_sync(v195);
          if ( (ready & 0x80000000) != 0 )
            goto LABEL_290;
          v99 = *v192;
LABEL_255:
          if ( v99 != 43981 )
            goto LABEL_260;
          if ( !*(_QWORD *)(a1 + 144) )
          {
            printk("%sicnss2: Invalid MSA address\n", byte_130B32);
            ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid MSA address\n", (const char *)&unk_12DBF3);
            v15 = -22;
            goto LABEL_368;
          }
          ready = wlfw_msa_mem_info_send_sync_msg(v195);
          if ( (ready & 0x80000000) == 0 )
          {
            ready = wlfw_msa_ready_send_sync_msg(v195);
            if ( (ready & 0x80000000) == 0 )
            {
              v99 = *v192;
LABEL_260:
              if ( v99 == 25680 )
                icnss_hw_power_off(v195);
              v15 = wlfw_cap_send_sync_msg(v195);
              if ( (v15 & 0x80000000) != 0 )
                goto LABEL_368;
              v102 = *v192;
              if ( *v192 == 43981 )
              {
                if ( *(_BYTE *)(a1 + 3960) == 1 )
                {
                  v15 = icnss_power_on_chain1_reg(v195);
                  if ( v15 )
                    goto LABEL_368;
                  v102 = *v192;
                  goto LABEL_267;
                }
LABEL_297:
                if ( *(_BYTE *)(a1 + 4165) != 1
                  || (icnss_wlfw_bdf_dnld_send_sync(v195, 4),
                      v15 = icnss_wlfw_bdf_dnld_send_sync(v195, *(unsigned int *)(a1 - 1340)),
                      (v15 & 0x80000000) == 0) )
                {
                  if ( *v192 == 30544 )
                  {
                    phy_ucode = icnss_load_phy_ucode(v195);
                    if ( (phy_ucode & 0x80000000) != 0 )
                    {
                      v15 = phy_ucode;
                      v114 = "%sicnss2: Phy ucode image loading failed, ret = %d\n";
                      printk("%sicnss2: Phy ucode image loading failed, ret = %d\n", byte_130B32, phy_ucode);
LABEL_333:
                      ipc_log_string(icnss_ipc_log_context, v114, &unk_12DBF3, v15);
                      goto LABEL_334;
                    }
                    v15 = icnss_wlfw_phy_ucode_dnld_send_sync(v195);
                    if ( (v15 & 0x80000000) != 0 )
                    {
                      v114 = "%sicnss2: Phy ucode download to wlan fw failed, ret = %d\n";
                      printk("%sicnss2: Phy ucode download to wlan fw failed, ret = %d\n", byte_130B32, v15);
                      goto LABEL_333;
                    }
                  }
                  if ( *(_BYTE *)(a1 + 3768) == 1 )
                  {
                    aux = icnss_load_aux(v195);
                    if ( (aux & 0x80000000) != 0 )
                    {
                      v15 = aux;
                      v114 = "%sicnss2: AUX image loading failed, ret = %d\n";
                      printk("%sicnss2: AUX image loading failed, ret = %d\n", byte_130B32, aux);
                      goto LABEL_333;
                    }
                    v15 = icnss_wlfw_aux_dnld_send_sync(v195);
                    if ( (v15 & 0x80000000) != 0 )
                    {
                      v114 = "%sicnss2: AUX download to wlan fw failed, ret = %d\n";
                      printk("%sicnss2: AUX download to wlan fw failed, ret = %d\n", byte_130B32, v15);
                      goto LABEL_333;
                    }
                  }
                  v113 = *v192;
                  if ( *v192 == 30544 || v113 == 25680 )
                  {
                    v15 = icnss_wlfw_qdss_dnld_send_sync(v195);
                    if ( (v15 & 0x80000000) != 0 )
                    {
                      printk("%sicnss2: Failed to download qdss config file, ret = %d\n", byte_13289B, v15);
                      ipc_log_string(
                        icnss_ipc_log_context,
                        "%sicnss2: Failed to download qdss config file, ret = %d\n",
                        (const char *)&unk_12DBF3,
                        v15);
                    }
                    v113 = *v192;
                  }
                  if ( v113 == 25680 || v113 == 30544 || v113 == 26448 )
                  {
                    if ( !*(_DWORD *)(a1 + 4160) )
                      register_soc_wake_notif(*v193 + 16);
                    icnss_get_smp2p_info(v195, 1);
                    icnss_get_smp2p_info(v195, 2);
                  }
                  if ( *(_BYTE *)(a1 + 4288) == 1 )
                    icnss_get_smp2p_info(v195, 0);
                  if ( *v192 != 43981 )
                    goto LABEL_322;
                  if ( *(_BYTE *)(a1 + 4165) != 1 || (v15 = wlfw_cal_report_req(v195), (v15 & 0x80000000) == 0) )
                  {
                    wlfw_dynamic_feature_mask_send_sync_msg(v195, dynamic_feature_mask);
LABEL_322:
                    if ( !*(_DWORD *)(a1 + 1352) )
                      register_fw_error_notifications(*v193 + 16);
                    if ( !*(_DWORD *)(a1 + 1356) )
                      register_early_crash_notifications(*v193 + 16);
                    if ( *(_BYTE *)(a1 + 4166) == 1 )
                      queue_work_on(32, *(_QWORD *)(a1 + 4240), a1 + 4208);
                    goto LABEL_368;
                  }
                }
              }
              else
              {
LABEL_267:
                if ( v102 == 26448 || v102 == 25680 )
                {
                  v15 = icnss_hw_power_on(v195);
                  if ( v15 )
                    goto LABEL_368;
                  v102 = *v192;
                }
                if ( v102 != 25680 && v102 != 30544 && v102 != 26448 )
                  goto LABEL_297;
                v15 = wlfw_device_info_send_msg(v195);
                if ( (v15 & 0x80000000) != 0 )
                  goto LABEL_334;
                v103 = *(unsigned int *)(a1 + 4524);
                if ( (_DWORD)v103 )
                  *(_QWORD *)(a1 + 4488) = v103;
                v104 = *(_QWORD *)(a1 + 4512);
                if ( v104
                  && (v105 = dma_map_resource(*v193 + 16, v104, *(_QWORD *)(a1 + 4488), 0, 0),
                      *(_QWORD *)(a1 + 4480) = v105,
                      v105 == -1) )
                {
                  printk(
                    "%sicnss2: DMA map failed for lpass shared mem address:0x%llx\n",
                    byte_130B32,
                    *(_QWORD *)(a1 + 4512));
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2: DMA map failed for lpass shared mem address:0x%llx\n",
                    (const char *)&unk_12DBF3,
                    *(_QWORD *)(a1 + 4512));
                }
                else
                {
                  v106 = (const void *)devm_ioremap(*v193 + 16);
                  *(_QWORD *)(a1 - 1144) = v106;
                  if ( v106 )
                  {
                    ipc_log_string(
                      icnss_ipc_log_context,
                      "icnss2: Non-Secured Bar Address pa: %pa, va: 0x%pK\n",
                      (const void *)(a1 - 1152),
                      v106);
                    if ( *v190 )
                    {
                      v107 = (const void *)devm_ioremap(*v193 + 16);
                      *v189 = v107;
                    }
                    else
                    {
                      v107 = *v189;
                    }
                    if ( !v107 )
                    {
                      printk("%sicnss2: Ioremap failed for MHI info address\n", byte_130B32);
                      ipc_log_string(
                        icnss_ipc_log_context,
                        "%sicnss2: Ioremap failed for MHI info address\n",
                        (const char *)&unk_12DBF3);
                      v107 = *v189;
                    }
                    ipc_log_string(
                      icnss_ipc_log_context,
                      "icnss2: MHI state info Address pa: %pa, va: 0x%pK\n",
                      v190,
                      v107);
                    goto LABEL_297;
                  }
                  printk("%sicnss2: Ioremap failed for bar address\n", byte_130B32);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2: Ioremap failed for bar address\n",
                    (const char *)&unk_12DBF3);
                }
              }
LABEL_334:
              icnss_hw_power_off(v195);
              goto LABEL_368;
            }
          }
LABEL_290:
          v15 = ready;
LABEL_368:
          v32 = *((unsigned int *)v4 + 4);
          if ( (unsigned int)v32 >= 0x12 )
LABEL_401:
            __break(0x5512u);
LABEL_369:
          v145 = "UNKNOWN";
          ++*(_DWORD *)(a1 + 476 + 8 * v32 + 4);
          v146 = *((unsigned int *)v4 + 4);
          if ( (unsigned int)v146 <= 0x12 )
            v145 = off_A8830[v146];
          if ( *((_BYTE *)v4 + 20) )
            v147 = "-sync";
          else
            v147 = (const char *)&unk_12DBF3;
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2: Event Processed: %s%s(%d), ret: %d, state: 0x%lx\n",
            v145,
            v147,
            v146,
            v15,
            *(_QWORD *)(a1 + 152));
          v3 = raw_spin_lock_irqsave(v2);
          if ( *((_BYTE *)v4 + 20) == 1 )
          {
            *((_DWORD *)v4 + 14) = v15;
            complete(v4 + 3);
          }
          else
          {
            raw_spin_unlock_irqrestore(v2, v3);
            kfree(v4);
            v3 = raw_spin_lock_irqsave(v2);
          }
LABEL_6:
          v4 = (_QWORD *)*v5;
          if ( (_QWORD *)*v5 == v5 )
            goto LABEL_397;
          break;
        case 1:
          if ( a1 == 1680 )
          {
            v15 = -19;
            v32 = 1;
            goto LABEL_369;
          }
          printk("%sicnss2: WLAN FW Service Disconnected: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 152));
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: WLAN FW Service Disconnected: 0x%lx\n",
            (const char *)&unk_12DBF3,
            *(_QWORD *)(a1 + 152));
          icnss_clear_server(v195);
          if ( *(_BYTE *)(a1 + 4166) != 1 )
            goto LABEL_367;
          v15 = 0;
          *(_DWORD *)(a1 + 4200) = 0;
          goto LABEL_368;
        case 2:
          v15 = icnss_driver_event_fw_ready_ind(v195, 1);
          goto LABEL_368;
        case 3:
          if ( *v194 )
          {
            v15 = -17;
            v32 = 3;
            goto LABEL_369;
          }
          *v194 = v4[8];
          if ( (*(_QWORD *)(a1 - 1352) & 4) != 0 )
          {
            _X8 = (unsigned __int64 *)(a1 + 152);
            __asm { PRFM            #0x11, [X8] }
            do
              v165 = __ldxr(_X8);
            while ( __stxr(v165 | 4, _X8) );
            v88 = *(_QWORD *)(a1 + 152);
            if ( (v88 & 0x2000) != 0 )
            {
LABEL_390:
              printk("%sicnss2: FW is in bad state, state: 0x%lx\n", byte_130B32, v88);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: FW is in bad state, state: 0x%lx\n",
                (const char *)&unk_12DBF3,
                *(_QWORD *)(a1 + 152));
              v15 = -19;
              goto LABEL_368;
            }
          }
          else
          {
            v88 = *(_QWORD *)(a1 + 152);
            if ( (v88 & 0x2000) != 0 )
              goto LABEL_390;
          }
          if ( (*(_QWORD *)(a1 + 152) & 4) == 0 )
          {
            ipc_log_string(icnss_ipc_log_context, "icnss2: FW is not ready yet, state: 0x%lx\n");
            goto LABEL_367;
          }
          v15 = icnss_hw_power_on(v195);
          if ( !v15 )
          {
            v90 = a1 - 1664;
            if ( penv )
            {
              _X8 = (unsigned __int64 *)(penv + 1832);
              __asm { PRFM            #0x11, [X8] }
              do
                v171 = __ldxr(_X8);
              while ( __stxr(v171 | 0x20000, _X8) );
              v90 = a1 - 1664;
              *(_DWORD *)(penv + 3088) = 0;
            }
            v91 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v90 + 200LL);
            v92 = *v193 + 16;
            if ( *((_DWORD *)v91 - 1) != 711998475 )
              __break(0x8228u);
            v93 = v91(v92);
            if ( v93 == -517 )
            {
              v94 = *v193 + 16;
              v95 = *(__int64 (__fastcall **)(_QWORD))(*v194 + 200);
              if ( *((_DWORD *)v95 - 1) != 711998475 )
                __break(0x8228u);
              v15 = v95(v94);
              v96 = 2;
            }
            else
            {
              v15 = v93;
              v96 = 1;
            }
            if ( v15 )
            {
              printk(
                "%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",
                byte_130B32,
                v15,
                *(_QWORD *)(a1 + 152),
                v96);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",
                (const char *)&unk_12DBF3,
                v15,
                *(_QWORD *)(a1 + 152),
                v96);
              icnss_block_shutdown(0);
              goto LABEL_334;
            }
            if ( penv )
            {
              _X8 = (unsigned __int64 *)(penv + 1832);
              __asm { PRFM            #0x11, [X8] }
              do
                v174 = __ldxr(_X8);
              while ( __stxr(v174 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
              complete(penv + 3088);
            }
            _X8 = (unsigned __int64 *)(a1 + 152);
            __asm { PRFM            #0x11, [X8] }
            do
              v168 = __ldxr(_X8);
            while ( __stxr(v168 | 8, _X8) );
LABEL_367:
            v15 = 0;
          }
          goto LABEL_368;
        case 4:
          if ( (*(_QWORD *)(a1 + 152) & 8) == 0 )
          {
            v15 = 0;
            *v194 = 0;
            goto LABEL_368;
          }
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v126 = __ldxr(_X8);
          while ( __stxr(v126 | 0x4000, _X8) );
          v127 = (__int64 *)(a1 - 1664);
          v70 = penv;
          if ( penv )
          {
            _X8 = (unsigned __int64 *)(penv + 1832);
            __asm { PRFM            #0x11, [X8] }
            do
              v136 = __ldxr(_X8);
            while ( __stxr(v136 | 0x20000, _X8) );
            v127 = (__int64 *)(a1 - 1664);
            v70 = penv;
            *(_DWORD *)(penv + 3088) = 0;
          }
          v71 = *v127;
          if ( v71 )
          {
            v72 = *(void (__fastcall **)(_QWORD))(v71 + 208);
            v73 = *v193 + 16;
            if ( *((_DWORD *)v72 - 1) != 1820440776 )
              __break(0x8228u);
            v72(v73);
            v70 = penv;
          }
          if ( v70 )
          {
            _X8 = (unsigned __int64 *)(v70 + 1832);
            __asm { PRFM            #0x11, [X8] }
            do
              v139 = __ldxr(_X8);
            while ( __stxr(v139 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
            complete(penv + 3088);
          }
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v130 = __ldxr(_X8);
          while ( __stxr(v130 & 0xFFFFFFFFFFFFBFFFLL, _X8) );
          _X8 = (unsigned __int64 *)(a1 + 152);
          __asm { PRFM            #0x11, [X8] }
          do
            v133 = __ldxr(_X8);
          while ( __stxr(v133 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
          *v194 = 0;
          icnss_hw_power_off(v195);
          goto LABEL_367;
        case 5:
          v37 = (unsigned __int8 *)v4[8];
          if ( (*(_QWORD *)(a1 + 152) & 0x400) == 0 )
            goto LABEL_132;
          v38 = *v192;
          if ( *v192 == 25680 || v38 == 30544 || v38 == 26448 )
          {
            icnss_send_smp2p(v195, 0, 1u);
            icnss_send_smp2p(v195, 0, 2u);
          }
          if ( *(_BYTE *)(a1 + 4288) == 1 )
            icnss_send_smp2p(v195, 0, 0);
          v39 = *(unsigned __int8 *)(a1 + 1298);
          v196 = nullptr;
          v197 = nullptr;
          _ZF = v39 == 1;
          v40 = (__int64 *)(a1 - 1664);
          if ( !_ZF )
            goto LABEL_354;
          if ( *(_QWORD *)(a1 + 3824)
            && (v41 = kmemdup_noprof(*(_QWORD *)(a1 + 3824), *(unsigned __int16 *)(a1 + 3832), 2080),
                (*(_QWORD *)(a1 + 3840) = v41) != 0) )
          {
            v42 = *(_WORD *)(a1 + 3832);
            v196 = (__int64 *)v41;
            v43 = *v194;
            LOWORD(v197) = v42;
            if ( v43 && *(_QWORD *)(v43 + 288) )
            {
              v44 = *(_QWORD *)(a1 + 152);
              v198 = 2;
              ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v44, 2);
              v199 = &v196;
              v45 = *(void (__fastcall **)(__int64, __int64 *))(*v194 + 288);
              v46 = *v193 + 16;
              if ( *((_DWORD *)v45 - 1) != -712363570 )
                __break(0x8228u);
              v45(v46, &v198);
              v41 = *(_QWORD *)(a1 + 3840);
            }
            kfree(v41);
            *(_QWORD *)(a1 + 3840) = 0;
          }
          else
          {
            printk("%sicnss2: Unable to allocate memory for Hang event data\n", byte_130B32);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2: Unable to allocate memory for Hang event data\n",
              (const char *)&unk_12DBF3);
            v40 = (__int64 *)(a1 - 1664);
LABEL_354:
            v140 = *v40;
            if ( v140 && *(_QWORD *)(v140 + 288) )
            {
              v141 = *(_QWORD *)(a1 + 152);
              v198 = 2;
              ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v141, 2);
              v199 = &v196;
              v142 = *(void (__fastcall **)(__int64, __int64 *))(*v194 + 288);
              v143 = *v193 + 16;
              if ( *((_DWORD *)v142 - 1) != -712363570 )
                __break(0x8228u);
              v142(v143, &v198);
            }
          }
          if ( *(_BYTE *)(a1 + 1298) == 1 )
          {
            ipc_log_string(
              icnss_ipc_log_context,
              "icnss2: PD Down ignored as early indication is processed: %d, state: 0x%lx\n",
              *v37,
              *(_QWORD *)(a1 + 152));
            goto LABEL_366;
          }
          v144 = *(_QWORD *)(a1 + 152);
          if ( (v144 & 0x200) != 0 && *v37 == 1 )
          {
            printk(
              "%sicnss2: fatal: PD Down while recovery inprogress, crashed: %d, state: 0x%lx\n",
              byte_130B32,
              1,
              v144);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2: fatal: PD Down while recovery inprogress, crashed: %d, state: 0x%lx\n",
              (const char *)&unk_12DBF3,
              *v37,
              *(_QWORD *)(a1 + 152));
            goto LABEL_366;
          }
          if ( (*(_QWORD *)(a1 + 152) & 0x200) != 0 )
            goto LABEL_366;
          v74 = a1 - 1680;
          v75 = v37;
          goto LABEL_365;
        case 6:
          v37 = (unsigned __int8 *)v4[8];
          if ( (*(_QWORD *)(a1 + 152) & 0x400) != 0 )
          {
            *(_BYTE *)(a1 + 1298) = 1;
            if ( (*(_QWORD *)(a1 + 152) & 0x200) == 0 )
            {
              v74 = a1 - 1680;
              v75 = nullptr;
LABEL_365:
              icnss_fw_crashed(v74, v75);
            }
          }
          else
          {
LABEL_132:
            icnss_ignore_fw_timeout(0);
          }
LABEL_366:
          kfree(v37);
          goto LABEL_367;
        case 7:
          if ( !*v194 )
          {
            v15 = 0;
            v32 = 7;
            goto LABEL_369;
          }
          if ( !*(_QWORD *)(*v194 + 296) )
            goto LABEL_367;
          if ( (*(_BYTE *)(a1 + 1570) & 1) != 0
            || (*(_QWORD *)(a1 + 152) & 0x40000) != 0
            || (v33 = *(_QWORD *)(a1 + 152), (v33 & 0x8000) != 0) )
          {
            v97 = "%sicnss2: SSR/PDR is already in-progress during idle shutdown callback\n";
            printk("%sicnss2: SSR/PDR is already in-progress during idle shutdown callback\n", byte_130B32);
            goto LABEL_221;
          }
          ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver idle shutdown, state: 0x%lx\n", v33);
          v34 = a1 - 1664;
          if ( penv )
          {
            _X8 = (unsigned __int64 *)(penv + 1832);
            __asm { PRFM            #0x11, [X8] }
            do
              v153 = __ldxr(_X8);
            while ( __stxr(v153 | 0x20000, _X8) );
            v34 = a1 - 1664;
            *(_DWORD *)(penv + 3088) = 0;
          }
          print_optimize = 0;
          v35 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v34 + 296LL);
          v36 = *v193 + 16;
          if ( *((_DWORD *)v35 - 1) != 711998475 )
            __break(0x8228u);
          v15 = v35(v36);
          if ( !penv )
            goto LABEL_368;
          _X8 = (unsigned __int64 *)(penv + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v156 = __ldxr(_X8);
          while ( __stxr(v156 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
          goto LABEL_386;
        case 8:
          if ( !*v194 )
          {
            v15 = 0;
            v32 = 8;
            goto LABEL_369;
          }
          if ( !*(_QWORD *)(*v194 + 304) )
            goto LABEL_367;
          if ( (*(_BYTE *)(a1 + 1570) & 1) != 0
            || (*(_QWORD *)(a1 + 152) & 0x40000) != 0
            || (v66 = *(_QWORD *)(a1 + 152), (v66 & 0x8000) != 0) )
          {
            v97 = "%sicnss2: SSR/PDR is already in-progress during idle restart callback\n";
            printk("%sicnss2: SSR/PDR is already in-progress during idle restart callback\n", byte_130B32);
LABEL_221:
            ipc_log_string(icnss_ipc_log_context, v97, &unk_12DBF3);
            v15 = -16;
          }
          else
          {
            ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver idle restart, state: 0x%lx\n", v66);
            v67 = a1 - 1664;
            if ( penv )
            {
              _X8 = (unsigned __int64 *)(penv + 1832);
              __asm { PRFM            #0x11, [X8] }
              do
                v159 = __ldxr(_X8);
              while ( __stxr(v159 | 0x20000, _X8) );
              v67 = a1 - 1664;
              *(_DWORD *)(penv + 3088) = 0;
            }
            print_optimize = 0;
            v68 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v67 + 304LL);
            v69 = *v193 + 16;
            if ( *((_DWORD *)v68 - 1) != 711998475 )
              __break(0x8228u);
            v15 = v68(v69);
            if ( penv )
            {
              _X8 = (unsigned __int64 *)(penv + 1832);
              __asm { PRFM            #0x11, [X8] }
              do
                v162 = __ldxr(_X8);
              while ( __stxr(v162 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
LABEL_386:
              complete(penv + 3088);
            }
          }
          goto LABEL_368;
        case 9:
          if ( a1 == 1680 )
          {
            v15 = -19;
            v32 = 9;
            goto LABEL_369;
          }
          printk("%sicnss2: WLAN FW Initialization done: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 152));
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: WLAN FW Initialization done: 0x%lx\n",
            (const char *)&unk_12DBF3,
            *(_QWORD *)(a1 + 152));
          if ( *v192 == 26448 )
          {
            v15 = icnss_wlfw_qdss_dnld_send_sync(v195);
            if ( (v15 & 0x80000000) != 0 )
            {
              printk("%sicnss2: Failed to download qdss config file for WCN6750, ret = %d\n", byte_13289B, v15);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: Failed to download qdss config file for WCN6750, ret = %d\n",
                (const char *)&unk_12DBF3,
                v15);
            }
          }
          else
          {
            v15 = 0;
          }
          if ( (*(_QWORD *)(a1 + 152) & 0x200000) != 0 )
          {
            mod_timer(a1 + 4336, jiffies + 10000LL);
            v15 = wlfw_wlan_mode_send_sync_msg(v195, 7);
          }
          else
          {
            icnss_driver_event_fw_ready_ind(v195, 0);
          }
          goto LABEL_368;
        case 10:
          v61 = *(_DWORD *)(a1 + 1600);
          if ( !v61 )
            goto LABEL_289;
          v62 = 0;
          v63 = *v193;
          while ( 2 )
          {
            v64 = (_QWORD *)(v6 + 40LL * (int)v62);
            if ( v64[1] || !*v64 )
              goto LABEL_135;
            v65 = dma_alloc_attrs(v63 + 16, *v64, v64 + 2, 3264, 0);
            v64[1] = v65;
            if ( v65 )
            {
              v61 = *(_DWORD *)(a1 + 1600);
LABEL_135:
              if ( ++v62 >= v61 )
                goto LABEL_285;
              continue;
            }
            break;
          }
          printk(
            "%sicnss2: Failed to allocate QDSS memory for FW, size: 0x%zx, type: %u, chuck-ID: %d\n",
            byte_130B32,
            *v64,
            *((_DWORD *)v64 + 7),
            v62);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: Failed to allocate QDSS memory for FW, size: 0x%zx, type: %u, chuck-ID: %d\n",
            (const char *)&unk_12DBF3,
            *v64,
            *((_DWORD *)v64 + 7),
            v62);
          v61 = *(_DWORD *)(a1 + 1600);
LABEL_285:
          if ( v62 < v61 )
          {
            v108 = v62;
            do
            {
              v109 = v6 + 40LL * (int)v108++;
              *(_QWORD *)v109 = 0;
              v110 = *(_DWORD *)(a1 + 1600);
              *(_DWORD *)(v109 + 28) = 0;
            }
            while ( v108 < v110 );
            *(_DWORD *)(a1 + 1600) = v62;
          }
LABEL_289:
          ready = wlfw_qdss_trace_mem_info_send_sync(v195);
          goto LABEL_290;
        case 11:
          v22 = v4[8];
          v201 = 0;
          v202 = 0;
          v199 = nullptr;
          v200 = 0;
          v23 = *(_DWORD *)(v22 + 8);
          v196 = nullptr;
          v198 = 0;
          if ( v23 == 6 )
          {
            v27 = *(_DWORD *)(a1 + 1600);
            v25 = (__int64 *)(a1 + 1608);
            if ( !v27 )
            {
LABEL_229:
              printk("%sicnss2: FW Mem type %d not allocated. Invalid save request\n", byte_130B32, v23);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: FW Mem type %d not allocated. Invalid save request\n",
                (const char *)&unk_12DBF3,
                *(_DWORD *)(v22 + 8));
              goto LABEL_204;
            }
          }
          else
          {
            if ( v23 != 1 )
              goto LABEL_229;
            v24 = *(_QWORD *)(a1 + 112);
            v25 = &v198;
            v26 = *(unsigned int *)(a1 + 136);
            v27 = 1;
            v199 = *(__int64 ***)(a1 + 144);
            v200 = v24;
            v198 = v26;
          }
          if ( *(_DWORD *)(v22 + 4) )
          {
            v76 = 0;
            while ( 1 )
            {
              if ( v76 == 32 )
                goto LABEL_401;
              v77 = v22 + 16 + 16 * v76;
              v78 = 0;
              v196 = *(__int64 **)v77;
              v79 = *(unsigned int *)(v77 + 8);
              while ( 1 )
              {
                v80 = &v25[5 * v78];
                v81 = (__int64 *)v80[2];
                v82 = v196 != v81 || (unsigned int)v79 > (unsigned int)*v80;
                if ( !v82 )
                {
                  v87 = v80[1];
                  if ( v87 )
                    goto LABEL_186;
LABEL_203:
                  printk("%sicnss2: Fail to find matching va for pa %pa\n", byte_130B32, &v196);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2: Fail to find matching va for pa %pa\n",
                    (const char *)&unk_12DBF3,
                    &v196);
LABEL_204:
                  v15 = -22;
                  goto LABEL_218;
                }
                v83 = (char *)((char *)v196 - (char *)v81);
                v82 = v196 > v81;
                v84 = (unsigned __int64)v81 + (unsigned int)*v80;
                v85 = v82 && v84 > (unsigned __int64)v196;
                if ( v85 && (unsigned __int64)v196 + v79 <= v84 )
                  break;
                if ( v27 == ++v78 )
                  goto LABEL_203;
              }
              v87 = (__int64)&v83[v80[1]];
              if ( !v87 )
                goto LABEL_203;
LABEL_186:
              v15 = icnss_genl_send_msg(v87, 1u, (const char *)(v22 + 528), v79);
              if ( (v15 & 0x80000000) != 0 )
                goto LABEL_242;
              if ( ++v76 >= (unsigned __int64)*(unsigned int *)(v22 + 4) )
                goto LABEL_218;
            }
          }
          if ( !*(_DWORD *)(a1 + 1600) )
          {
            v15 = 0;
            goto LABEL_218;
          }
          v89 = 0;
          do
          {
            v15 = icnss_genl_send_msg(
                    *(_QWORD *)(v6 + 40LL * (int)v89 + 8),
                    1u,
                    (const char *)(v22 + 528),
                    *(_DWORD *)(v6 + 40LL * (int)v89));
            if ( (v15 & 0x80000000) != 0 )
            {
LABEL_242:
              printk("%sicnss2: Fail to save QDSS data: %d\n", byte_130B32, v15);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: Fail to save QDSS data: %d\n",
                (const char *)&unk_12DBF3,
                v15);
              break;
            }
            ++v89;
          }
          while ( v89 < *(_DWORD *)(a1 + 1600) );
LABEL_218:
          kfree(v22);
          v2 = a1 - 40;
          v5 = (_QWORD *)(a1 - 72);
          goto LABEL_368;
        case 12:
          v28 = *(_DWORD *)(a1 + 1600);
          if ( v28 )
          {
            v29 = 0;
            v30 = *v193;
            do
            {
              v31 = (_QWORD *)(v6 + 40LL * (int)v29);
              if ( v31[1] && *v31 )
              {
                ipc_log_string(
                  icnss_ipc_log_context,
                  "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
                  v31 + 2,
                  *v31,
                  *((_DWORD *)v31 + 7));
                dma_free_attrs(v30 + 16, *v31, v31[1], v31[2], 0);
                *v31 = 0;
                v31[1] = 0;
                v31[2] = 0;
                v28 = *(_DWORD *)(a1 + 1600);
                *((_DWORD *)v31 + 7) = 0;
              }
              ++v29;
            }
            while ( v29 < v28 );
          }
          v15 = 0;
          *(_DWORD *)(a1 + 1600) = 0;
          goto LABEL_368;
        case 13:
          v47 = (unsigned int *)v4[8];
          v201 = 0;
          v202 = 0;
          v199 = nullptr;
          v200 = 0;
          v191 = v47;
          v198 = 0;
          if ( (dump_enabled(v12) & 1) == 0 )
          {
            printk("%sicnss2: Dump collection is not enabled\n", byte_13289B);
            ipc_log_string(icnss_ipc_log_context, "%sicnss2: Dump collection is not enabled\n");
            goto LABEL_367;
          }
          v48 = *(_QWORD *)(a1 + 1256);
          v15 = 0;
          if ( !v48 )
            goto LABEL_368;
          if ( v48 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_368;
          v49 = *(_QWORD *)(a1 + 1264);
          v15 = 0;
          if ( !v49 )
            goto LABEL_368;
          if ( v49 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_368;
          v50 = *(_QWORD *)(a1 + 1272);
          v15 = 0;
          if ( !v50 )
            goto LABEL_368;
          if ( v50 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_368;
          v51 = *(_QWORD *)(a1 + 1280);
          v15 = 0;
          if ( !v51 )
            goto LABEL_368;
          if ( v51 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_368;
          v52 = *(_QWORD *)(a1 + 1288);
          v15 = 0;
          if ( !v52 || v52 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_368;
          v196 = (__int64 *)&v196;
          v197 = &v196;
          v53 = v191;
          if ( !v191[1] )
          {
            v188 = 0;
            v15 = 0;
            goto LABEL_283;
          }
          v54 = 0;
          v15 = 0;
          v55 = (const char *)(v191 + 8);
          v188 = 0;
          while ( 2 )
          {
            v201 = 0;
            v202 = 0;
            v199 = nullptr;
            v200 = 0;
            v198 = 0;
            if ( v54 == 10 )
              goto LABEL_401;
            v201 = devm_ioremap(*v193 + 16);
            if ( v201 )
            {
              v56 = v196;
              v202 = *((_QWORD *)v55 - 1);
              if ( v196 == &v198 || (__int64 **)v196[1] != &v196 )
              {
                _list_add_valid_or_report(&v198, &v196);
              }
              else
              {
                v196[1] = (__int64)&v198;
                v198 = (__int64)v56;
                v199 = &v196;
                v196 = &v198;
              }
              ipc_log_string(icnss_ipc_log_context, "icnss2: Started Dump colletcion for %s segment", v55);
              v57 = *((_DWORD *)v55 - 6);
              if ( v57 <= 2 )
              {
                if ( v57 == 1 )
                {
                  v58 = *(_QWORD *)(a1 + 1256);
                }
                else
                {
                  if ( v57 != 2 )
                    goto LABEL_128;
                  v58 = *(_QWORD *)(a1 + 1264);
                }
              }
              else
              {
                switch ( v57 )
                {
                  case 3:
                    v58 = *(_QWORD *)(a1 + 1272);
                    break;
                  case 4:
                    v58 = *(_QWORD *)(a1 + 1280);
                    break;
                  case 5:
                    v58 = *(_QWORD *)(a1 + 1288);
                    break;
                  default:
LABEL_128:
                    printk("%sicnss2: Invalid Segment type: %d", byte_130B32, v57);
                    v53 = v191;
                    ipc_log_string(
                      icnss_ipc_log_context,
                      "%sicnss2: Invalid Segment type: %d",
                      (const char *)&unk_12DBF3,
                      *((_DWORD *)v55 - 6));
                    if ( v15 )
                    {
LABEL_129:
                      printk("%sicnss2: Failed to dump m3 %s segment, err = %d\n", byte_130B32, v55, v15);
                      v53 = v191;
                      ipc_log_string(
                        icnss_ipc_log_context,
                        "%sicnss2: Failed to dump m3 %s segment, err = %d\n",
                        (const char *)&unk_12DBF3,
                        v55,
                        v15);
                      v188 = v15;
                    }
LABEL_122:
                    v59 = v199;
                    if ( *v199 == &v198 && (v60 = v198, *(__int64 **)(v198 + 8) == &v198) )
                    {
                      *(_QWORD *)(v198 + 8) = v199;
                      *v59 = (__int64 *)v60;
                    }
                    else
                    {
                      _list_del_entry_valid_or_report(&v198);
                    }
                    ++v54;
                    v55 += 48;
                    v198 = 0xDEAD000000000100LL;
                    v199 = (__int64 **)0xDEAD000000000122LL;
                    if ( v54 >= v53[1] )
                      goto LABEL_283;
                    continue;
                }
              }
              v15 = qcom_dump(&v196, *(_QWORD *)(v58 + 40));
              if ( v15 )
                goto LABEL_129;
              goto LABEL_122;
            }
            break;
          }
          printk("%sicnss2: Failed to ioremap M3 Dump region", byte_130B32);
          ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to ioremap M3 Dump region", (const char *)&unk_12DBF3);
          v15 = -12;
LABEL_283:
          icnss_wlfw_m3_dump_upload_done_send_sync(v195, *v53, v188);
          v5 = (_QWORD *)(a1 - 72);
          goto LABEL_368;
        case 14:
          v15 = icnss_process_wfc_call_ind_event(v195, v4[8]);
          goto LABEL_368;
        case 15:
          v15 = icnss_process_twt_cfg_ind_event(v195, v4[8]);
          goto LABEL_368;
        case 16:
          if ( a1 == 1680 )
          {
            v15 = -19;
            v32 = 16;
            goto LABEL_369;
          }
          v20 = (unsigned __int8 *)v4[8];
          if ( v20 )
          {
            restarted = icnss_wlfw_qdss_data_send_sync();
            goto LABEL_74;
          }
          v15 = -22;
          goto LABEL_368;
        case 17:
          v20 = (unsigned __int8 *)v4[8];
          if ( !v20 )
          {
            v15 = -22;
            v32 = 17;
            goto LABEL_369;
          }
          if ( a1 == 1680 )
          {
            v15 = -19;
          }
          else
          {
            restarted = wlfw_subsys_restart_level_msg(v195, *v20);
LABEL_74:
            v15 = restarted;
          }
          kfree(v20);
          goto LABEL_368;
        default:
          printk("%sicnss2: Invalid Event type: %d", byte_130B32, v13);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: Invalid Event type: %d",
            (const char *)&unk_12DBF3,
            *((_DWORD *)v4 + 4));
          kfree(v4);
          goto LABEL_6;
      }
    }
  }
LABEL_397:
  result = raw_spin_unlock_irqrestore(v2, v3);
  _X9 = (unsigned int *)(a1 + 1240);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v186 = __ldxr(_X9);
    v187 = v186 - 1;
  }
  while ( __stlxr(v187, _X9) );
  __dmb(0xBu);
  if ( (v187 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else if ( !v187 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: PM relax, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a1 + 152),
      *(_DWORD *)(a1 + 1240));
    result = pm_relax(*(_QWORD *)(a1 - 1672) + 16LL);
    ++*(_DWORD *)(a1 + 880);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
