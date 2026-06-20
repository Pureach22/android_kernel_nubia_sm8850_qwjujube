__int64 __fastcall dsi_display_bind(__int64 *a1, _QWORD *a2)
{
  unsigned __int64 v2; // x23
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x8
  size_t v9; // x0
  unsigned __int64 v10; // x2
  size_t v11; // x0
  __int64 v13; // x8
  size_t v14; // x2
  char *v15; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 v17; // x23
  unsigned __int64 file; // x0
  unsigned __int64 v19; // x24
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x0
  unsigned int v24; // w8
  __int64 v25; // x24
  const char *v26; // x3
  __int64 v27; // x24
  const char *v28; // x3
  __int64 v29; // x0
  int v30; // w4
  __int64 v31; // x8
  __int64 *v32; // x25
  int v33; // w0
  __int64 v34; // x8
  int v35; // w9
  __int64 v36; // x26
  int v37; // w25
  unsigned __int64 v38; // x0
  __int64 v39; // x24
  int v40; // w0
  int v41; // w0
  unsigned __int64 v42; // x0
  __int64 v43; // x0
  unsigned __int64 v44; // x0
  _QWORD *v45; // x8
  __int64 v46; // x10
  __int64 v47; // x11
  __int64 v48; // x9
  __int64 v49; // x10
  __int64 v50; // x11
  __int64 v51; // x9
  __int64 v52; // x10
  __int64 v53; // x8
  __int64 v54; // x12
  __int64 v55; // x8
  __int64 v56; // x9
  int v57; // w0
  const char *v58; // x4
  unsigned int v59; // w8
  __int64 v60; // x8
  __int64 v61; // x21
  __int64 v62; // x20
  __int64 v63; // x0
  int v65; // w0
  __int64 v66; // x0
  _QWORD *v67; // x8
  __int64 v68; // x10
  __int64 v69; // x11
  __int64 v70; // x9
  __int64 v71; // x10
  __int64 v72; // x8
  __int64 v73; // x10
  __int64 v74; // x8
  __int64 v75; // x8
  unsigned __int64 v78; // x9
  unsigned __int64 v84; // x9
  _QWORD v85[4]; // [xsp+0h] [xbp-2A0h] BYREF
  _QWORD s[39]; // [xsp+20h] [xbp-280h] BYREF
  char string[8]; // [xsp+158h] [xbp-148h] BYREF
  __int64 v88; // [xsp+160h] [xbp-140h]
  __int64 v89; // [xsp+168h] [xbp-138h]
  __int64 v90; // [xsp+170h] [xbp-130h]
  __int64 v91; // [xsp+178h] [xbp-128h]
  __int64 v92; // [xsp+180h] [xbp-120h]
  __int64 v93; // [xsp+188h] [xbp-118h]
  __int64 v94; // [xsp+190h] [xbp-110h]
  __int64 v95; // [xsp+198h] [xbp-108h]
  __int64 v96; // [xsp+1A0h] [xbp-100h]
  __int64 v97; // [xsp+1A8h] [xbp-F8h]
  __int64 v98; // [xsp+1B0h] [xbp-F0h]
  __int64 v99; // [xsp+1B8h] [xbp-E8h]
  __int64 v100; // [xsp+1C0h] [xbp-E0h]
  __int64 v101; // [xsp+1C8h] [xbp-D8h]
  __int64 v102; // [xsp+1D0h] [xbp-D0h]
  __int64 v103; // [xsp+1D8h] [xbp-C8h]
  __int64 v104; // [xsp+1E0h] [xbp-C0h]
  __int64 v105; // [xsp+1E8h] [xbp-B8h]
  __int64 v106; // [xsp+1F0h] [xbp-B0h]
  __int64 v107; // [xsp+1F8h] [xbp-A8h]
  __int64 v108; // [xsp+200h] [xbp-A0h]
  __int64 v109; // [xsp+208h] [xbp-98h]
  __int64 v110; // [xsp+210h] [xbp-90h]
  __int64 v111; // [xsp+218h] [xbp-88h]
  __int64 v112; // [xsp+220h] [xbp-80h]
  __int64 v113; // [xsp+228h] [xbp-78h]
  __int64 v114; // [xsp+230h] [xbp-70h]
  __int64 v115; // [xsp+238h] [xbp-68h]
  __int64 v116; // [xsp+240h] [xbp-60h]
  __int64 v117; // [xsp+248h] [xbp-58h]
  __int64 v118; // [xsp+250h] [xbp-50h]
  char v119[8]; // [xsp+258h] [xbp-48h] BYREF
  __int64 v120; // [xsp+260h] [xbp-40h]
  __int64 v121; // [xsp+268h] [xbp-38h]
  __int64 v122; // [xsp+270h] [xbp-30h]
  __int64 v123; // [xsp+278h] [xbp-28h]
  __int64 v124; // [xsp+280h] [xbp-20h]
  __int64 v125; // [xsp+288h] [xbp-18h]
  __int64 v126; // [xsp+290h] [xbp-10h]
  __int64 v127; // [xsp+298h] [xbp-8h]

  v127 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v85[0] = dsi_display_pre_release;
  v85[1] = dsi_display_pre_acquire;
  v85[2] = 0;
  v85[3] = dsi_display_get_io_resources;
  if ( !a2 || !a1 || a1 == &qword_10 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: invalid param(s), dev %pK, pdev %pK, master %pK\n",
      a1,
      a1 - 2,
      a2);
    LODWORD(v19) = -22;
    goto LABEL_127;
  }
  v5 = a2[19];
  v6 = a1[19];
  if ( !v5 || !v6 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: invalid param(s), drm %pK, display %pK\n",
      (const void *)a2[19],
      (const void *)a1[19]);
    LODWORD(v19) = -22;
    goto LABEL_127;
  }
  if ( !*(_QWORD *)(v6 + 272) && !*(_QWORD *)(v6 + 1584) )
  {
    LODWORD(v19) = 0;
    goto LABEL_127;
  }
  v7 = *(_QWORD *)(v6 + 264);
  if ( !v7 || *(_BYTE *)(v7 + 1274) != 1 || !*(_DWORD *)(v6 + 816) )
    goto LABEL_15;
  if ( !of_drm_find_bridge(*(_QWORD *)(v6 + 296)) )
  {
    v30 = 0;
    v31 = v6 + 296;
    goto LABEL_71;
  }
  if ( *(_DWORD *)(v6 + 816) >= 2u )
  {
    if ( of_drm_find_bridge(*(_QWORD *)(v6 + 560)) )
    {
      v8 = *(unsigned int *)(v6 + 816);
      if ( (unsigned int)v8 > 2 )
        goto LABEL_139;
      goto LABEL_15;
    }
    v31 = v6 + 560;
    v30 = 1;
LABEL_71:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: defer for bridge[%d] %s\n", v30, *(const char **)(*(_QWORD *)v31 + 16LL));
    LODWORD(v19) = -517;
    goto LABEL_127;
  }
LABEL_15:
  mutex_lock(v6 + 72);
  v2 = *(_QWORD *)(v6 + 264);
  if ( *(_BYTE *)(v2 + 1280) != 1 )
    goto LABEL_23;
  if ( !*(_DWORD *)(v6 + 160) )
    goto LABEL_22;
  if ( *(_BYTE *)(*(_QWORD *)(v6 + 168) + 2895LL) != 1 )
  {
LABEL_65:
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] split link is not supported by hw\n",
      *(const char **)(v6 + 32));
    *(_BYTE *)(v2 + 1280) = 0;
    LODWORD(v19) = -524;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] split link validation failed, rc=%d\n",
      *(const char **)(v6 + 32),
      -524);
    goto LABEL_126;
  }
  v8 = *(_QWORD *)(v6 + 192);
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v8 + 136);
    __asm { PRFM            #0x11, [X8] }
    do
      v78 = __ldxr(_X8);
    while ( __stxr(v78 | 4, _X8) );
    *(_DWORD *)(v2 + 1296) = *(_DWORD *)(*(_QWORD *)(v6 + 264) + 1352LL);
    if ( *(_DWORD *)(v6 + 160) >= 2u )
    {
      if ( *(_BYTE *)(*(_QWORD *)(v6 + 216) + 2895LL) != 1 )
        goto LABEL_65;
      _X8 = (unsigned __int64 *)(*(_QWORD *)(v6 + 240) + 136LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v84 = __ldxr(_X8);
      while ( __stxr(v84 | 4, _X8) );
      *(_DWORD *)(v2 + 1296) = *(_DWORD *)(*(_QWORD *)(v6 + 264) + 1352LL);
    }
LABEL_22:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Split link is enabled\n");
LABEL_23:
    v125 = 0;
    v126 = 0;
    v123 = 0;
    v124 = 0;
    v118 = 0;
    v117 = 0;
    v116 = 0;
    v115 = 0;
    v114 = 0;
    v113 = 0;
    v112 = 0;
    v111 = 0;
    v110 = 0;
    v109 = 0;
    v107 = 0;
    v108 = 0;
    v105 = 0;
    v106 = 0;
    v103 = 0;
    v104 = 0;
    v101 = 0;
    v102 = 0;
    v99 = 0;
    v100 = 0;
    v97 = 0;
    v98 = 0;
    v95 = 0;
    v96 = 0;
    v93 = 0;
    v94 = 0;
    v91 = 0;
    v92 = 0;
    v2 = *(_QWORD *)(v6 + 32);
    v121 = 0;
    v122 = 0;
    *(_QWORD *)v119 = 0;
    v120 = 0;
    v89 = 0;
    v90 = 0;
    *(_QWORD *)string = 0;
    v88 = 0;
    v9 = strnlen((const char *)v2, 0x100u);
    if ( v9 == -1 )
    {
      _fortify_panic(2, -1, 0);
LABEL_137:
      v11 = _fortify_panic(7, 256, v10);
LABEL_138:
      _fortify_panic(2, 256, v11 + 1);
      goto LABEL_139;
    }
    if ( v9 == 256 )
      v10 = 256;
    else
      v10 = v9 + 1;
    if ( v10 >= 0x101 )
      goto LABEL_137;
    sized_strscpy(string, v2);
    if ( strcmp(*(const char **)(v6 + 40), "secondary") )
      goto LABEL_39;
    v11 = strnlen(string, 0x100u);
    if ( v11 >= 0x101 )
      goto LABEL_138;
    if ( v11 == 256 )
      goto LABEL_39;
    _CF = v11 >= 0xF6;
    v13 = v11 + 10;
    v14 = v11 >= 0xF6 ? 255 - v11 : 10LL;
    v15 = &string[v11];
    v2 = _CF ? 255LL : v13;
    memcpy(v15, "_secondary", v14);
    if ( v2 <= 0xFF )
      break;
LABEL_140:
    __break(1u);
  }
  string[v2] = 0;
LABEL_39:
  dir = debugfs_create_dir(string, 0);
  v17 = dir;
  if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
  {
    file = debugfs_create_file("dump_info", 256, dir, v6, &dump_info_fops);
    LODWORD(v19) = file;
    if ( file && file < 0xFFFFFFFFFFFFF001LL )
    {
      v20 = debugfs_create_file("esd_trigger", 420, v17, v6, &esd_trigger_fops);
      LODWORD(v19) = v20;
      if ( v20 && v20 < 0xFFFFFFFFFFFFF001LL )
      {
        v21 = debugfs_create_file("esd_check_mode", 420, v17, v6, &esd_check_mode_fops);
        LODWORD(v19) = v21;
        if ( v21 && v21 < 0xFFFFFFFFFFFFF001LL )
        {
          v22 = debugfs_create_file("cmd_sched_params", 420, v17, v6, &dsi_command_scheduling_fops);
          LODWORD(v19) = v22;
          if ( v22 && v22 < 0xFFFFFFFFFFFFF001LL )
          {
            v23 = debugfs_create_file("misr_data", 384, v17, v6, &misr_data_fops);
            LODWORD(v19) = v23;
            if ( v23 && v23 <= 0xFFFFFFFFFFFFF000LL )
            {
              v24 = *(_DWORD *)(v6 + 160);
              if ( v24 )
              {
                v25 = *(_QWORD *)(v6 + 192);
                if ( v25 )
                {
                  v26 = *(const char **)(v25 + 16);
                  if ( v26 )
                  {
                    snprintf(v119, 0x40u, "%s_allow_phy_power_off", v26);
                    debugfs_create_bool(v119, 384, v17, v25 + 1352);
                    snprintf(v119, 0x40u, "%s_regulator_min_datarate_bps", *(const char **)(v25 + 16));
                    debugfs_create_u32(v119, 384, v17, v25 + 1356);
                    v24 = *(_DWORD *)(v6 + 160);
                  }
                }
                if ( v24 > 1 )
                {
                  v27 = *(_QWORD *)(v6 + 240);
                  if ( v27 )
                  {
                    v28 = *(const char **)(v27 + 16);
                    if ( v28 )
                    {
                      snprintf(v119, 0x40u, "%s_allow_phy_power_off", v28);
                      debugfs_create_bool(v119, 384, v17, v27 + 1352);
                      snprintf(v119, 0x40u, "%s_regulator_min_datarate_bps", *(const char **)(v27 + 16));
                      debugfs_create_u32(v119, 384, v17, v27 + 1356);
                    }
                  }
                }
              }
              debugfs_create_bool("ulps_feature_enable", 384, v17, *(_QWORD *)(v6 + 264) + 1961LL);
              debugfs_create_bool("ulps_suspend_feature_enable", 384, v17, *(_QWORD *)(v6 + 264) + 1962LL);
              debugfs_create_bool("ulps_status", 256, v17, v6 + 1218);
              debugfs_create_u32("clk_gating_config", 384, v17, v6 + 1612);
              v29 = *(_QWORD *)(v6 + 1592);
              *(_QWORD *)(v6 + 1336) = v17;
              dsi_parser_dbg_init(v29, v17);
              goto LABEL_75;
            }
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] debugfs create misr datafile failed, rc=%d\n",
              *(_QWORD *)(v6 + 32),
              (unsigned int)v23);
          }
          else
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] debugfs for cmd scheduling file failed, rc=%d\n",
              *(_QWORD *)(v6 + 32),
              (unsigned int)v22);
          }
        }
        else
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] debugfs for esd check mode failed, rc=%d\n",
            *(_QWORD *)(v6 + 32),
            (unsigned int)v21);
        }
      }
      else
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] debugfs for esd trigger file failed, rc=%d\n",
          *(_QWORD *)(v6 + 32),
          (unsigned int)v20);
      }
    }
    else
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] debugfs create dump info file failed, rc=%d\n",
        *(const char **)(v6 + 32),
        file);
    }
    debugfs_remove(v17);
    if ( (_DWORD)v19 )
    {
LABEL_63:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] debugfs init failed, rc=%d\n",
        *(_QWORD *)(v6 + 32),
        (unsigned int)v19);
      goto LABEL_126;
    }
  }
  else
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] debugfs create dir failed, rc = %d\n",
      *(const char **)(v6 + 32),
      dir);
    LODWORD(v19) = v17;
    if ( (_DWORD)v17 )
      goto LABEL_63;
  }
LABEL_75:
  *(_DWORD *)(v6 + 864) = 0;
  *(_DWORD *)(v6 + 860) = 0;
  memset(s, 0, sizeof(s));
  if ( *(_DWORD *)(v6 + 160) )
  {
    v32 = (__int64 *)(v6 + 168);
    v33 = dsi_ctrl_drv_init(*(_QWORD **)(v6 + 168), *(_QWORD *)(v6 + 1336));
    if ( v33 )
    {
      LODWORD(v19) = v33;
      LODWORD(v2) = 0;
      goto LABEL_78;
    }
    *(_DWORD *)(*(_QWORD *)(v6 + 168) + 12LL) = 0;
    v41 = dsi_phy_drv_init(*(__int64 **)(v6 + 192));
    if ( v41 )
    {
      LODWORD(v19) = v41;
      LODWORD(v2) = 0;
LABEL_89:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] Failed to initialize phy[%d], rc=%d\n",
        *(const char **)(v6 + 32),
        v2,
        v19);
      dsi_ctrl_drv_deinit(*v32);
      goto LABEL_121;
    }
    v45 = *(_QWORD **)(v6 + 168);
    s[10] = v5;
    v46 = v45[275];
    v47 = v45[279];
    s[6] = v45[274];
    s[7] = v46;
    v48 = v45[280];
    v49 = v45[281];
    s[20] = v47;
    s[21] = v48;
    v50 = v45[276];
    v51 = v45[277];
    s[22] = v49;
    v52 = v45[272];
    v53 = v45[273];
    v54 = *(_QWORD *)(v6 + 168);
    s[8] = v50;
    s[9] = v51;
    s[4] = v52;
    s[5] = v53;
    v55 = *(_QWORD *)(v54 + 2256);
    s[26] = *(_QWORD *)(v54 + 2296);
    v56 = *(_QWORD *)(v6 + 168);
    s[18] = v55;
    LODWORD(s[29]) = *(_DWORD *)(v56 + 8);
    if ( *(_DWORD *)(v6 + 160) < 2u )
    {
      v2 = 1;
    }
    else
    {
      v32 = (__int64 *)(v6 + 216);
      v57 = dsi_ctrl_drv_init(*(_QWORD **)(v6 + 216), *(_QWORD *)(v6 + 1336));
      LODWORD(v2) = 1;
      if ( v57 )
      {
        LODWORD(v19) = v57;
LABEL_78:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to initialize ctrl[%d], rc=%d\n",
          *(const char **)(v6 + 32),
          v2,
          v19);
LABEL_121:
        if ( (_DWORD)v2 )
        {
          v61 = v6 + 168 + 48LL * (unsigned int)v2;
          dsi_phy_drv_deinit();
          dsi_ctrl_drv_deinit(*(_QWORD *)(v61 - 48));
          dsi_ctrl_put(*(_QWORD *)(v61 - 48));
          dsi_phy_put(*(_QWORD *)(v61 - 24));
          if ( (_DWORD)v2 != 1 )
          {
            v62 = v6 + 168 + 48LL * (unsigned int)v2;
            dsi_phy_drv_deinit();
            dsi_ctrl_drv_deinit(*(_QWORD *)(v62 - 96));
            dsi_ctrl_put(*(_QWORD *)(v62 - 96));
            dsi_phy_put(*(_QWORD *)(v62 - 72));
          }
        }
        v63 = *(_QWORD *)(v6 + 1336);
        if ( v63 )
        {
          debugfs_remove(v63);
          *(_QWORD *)(v6 + 1336) = 0;
        }
        goto LABEL_126;
      }
      *(_DWORD *)(*(_QWORD *)(v6 + 216) + 12LL) = 1;
      v65 = dsi_phy_drv_init(*(__int64 **)(v6 + 240));
      if ( v65 )
      {
        LODWORD(v19) = v65;
        goto LABEL_89;
      }
      v67 = (_QWORD *)*v32;
      v2 = 2;
      v68 = *(_QWORD *)(*v32 + 2200);
      v69 = *(_QWORD *)(*v32 + 2208);
      s[13] = *(_QWORD *)(*v32 + 2192);
      s[14] = v68;
      v70 = v67[277];
      v71 = v67[272];
      v72 = v67[273];
      s[15] = v69;
      s[16] = v70;
      s[11] = v71;
      s[12] = v72;
      v73 = *(_QWORD *)(*v32 + 2240);
      v74 = *(_QWORD *)(*v32 + 2248);
      s[23] = *(_QWORD *)(*v32 + 2232);
      s[24] = v73;
      s[25] = v74;
      s[19] = *(_QWORD *)(*v32 + 2256);
      v75 = *v32;
      s[17] = v5;
      s[27] = *(_QWORD *)(v75 + 2296);
      HIDWORD(s[29]) = *(_DWORD *)(*v32 + 8);
    }
  }
  else
  {
    v2 = 0;
    v32 = nullptr;
  }
  v34 = *(_QWORD *)(*v32 + 2304);
  s[31] = dsi_post_clkoff_cb;
  s[32] = dsi_post_clkon_cb;
  s[28] = v34;
  s[30] = dsi_pre_clkoff_cb;
  s[33] = dsi_pre_clkon_cb;
  s[34] = &dsi_display_mgr_phy_configure;
  v35 = *(_DWORD *)(v6 + 836);
  s[35] = dsi_display_mgr_phy_pll_toggle;
  s[36] = v6;
  v8 = *(unsigned int *)(v6 + 840);
  LODWORD(s[37]) = v35;
  HIDWORD(s[37]) = *(_DWORD *)(v6 + 160);
  if ( (unsigned int)v8 >= 2 )
    goto LABEL_139;
  v36 = v6 + 168;
  LOBYTE(s[38]) = *(_BYTE *)(*(_QWORD *)(v6 + 168 + 48LL * (unsigned int)v8 + 24) + 120LL);
  snprintf((char *)s, 0x20u, "DSI_MNGR-%s", *(const char **)(v6 + 32));
  v37 = *(_DWORD *)(*(_QWORD *)(v6 + 168) + 1608LL);
  *(_DWORD *)(*(_QWORD *)(v6 + 264) + 2236LL) = v37;
  v38 = dsi_display_clk_mngr_register(s, *(unsigned int *)(*(_QWORD *)(v6 + 168) + 1608LL));
  LODWORD(v19) = v38;
  *(_QWORD *)(v6 + 1312) = v38;
  if ( !v38 || v38 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v6 + 1312) = 0;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dsi clock registration failed, rc = %d\n", v38);
    goto LABEL_121;
  }
  if ( v37 != 1 )
  {
    v42 = dsi_register_clk_handle(v38, "dsi_clk_client");
    v19 = v42;
    if ( !v42 || v42 >= 0xFFFFFFFFFFFFF001LL )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: failed to register %s client, rc = %d\n",
        "dsi_clk_client",
        v42);
LABEL_120:
      dsi_display_clk_mngr_deregister(*(_QWORD *)(v6 + 1312));
      goto LABEL_121;
    }
    v43 = *(_QWORD *)(v6 + 1312);
    *(_QWORD *)(v6 + 1320) = v19;
    v44 = dsi_register_clk_handle(v43, "mdp_event_client");
    LODWORD(v19) = v44;
    if ( !v44 || v44 >= 0xFFFFFFFFFFFFF001LL )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: failed to register %s client, rc = %d\n",
        "mdp_event_client",
        v44);
LABEL_119:
      dsi_deregister_clk_handle(*(_QWORD *)(v6 + 1320));
      goto LABEL_120;
    }
    *(_QWORD *)(v6 + 1328) = v44;
  }
  v8 = *(unsigned int *)(v6 + 840);
  if ( (unsigned int)v8 >= 3 )
  {
LABEL_139:
    __break(0x5512u);
    goto LABEL_140;
  }
  v39 = *(_QWORD *)(v6 + 264);
  dsi_phy_get_version(*(_QWORD *)(v36 + 48LL * (unsigned int)v8 + 24));
  *(_DWORD *)(v39 + 1300) = 2;
  v40 = dsi_display_mipi_host_init(v6);
  if ( v40 )
  {
    LODWORD(v19) = v40;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to initialize mipi host, rc=%d\n",
      *(const char **)(v6 + 32),
      v40);
    goto LABEL_121;
  }
  LODWORD(v19) = dsi_panel_drv_init(*(_QWORD *)(v6 + 264), v6 + 1264);
  if ( (_DWORD)v19 == -517 )
  {
LABEL_118:
    mipi_dsi_host_unregister(v6 + 1264);
    *(_QWORD *)(v6 + 1264) = 0;
    *(_QWORD *)(v6 + 1272) = 0;
    goto LABEL_119;
  }
  if ( (_DWORD)v19 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to initialize panel driver, rc=%d\n",
      *(const char **)(v6 + 32),
      v19);
    goto LABEL_118;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v6 + 264) + 1974LL) )
    v58 = "as sim panel";
  else
    v58 = (const char *)&unk_229BD3;
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: Successfully bind display panel '%s %s'\n", *(_QWORD *)(v6 + 32), v58);
  v59 = *(_DWORD *)(v6 + 160);
  *(_QWORD *)(v6 + 8) = v5;
  if ( v59 )
  {
    if ( *(_QWORD *)(v6 + 192) && *(_QWORD *)v36 )
    {
      *(_QWORD *)(*(_QWORD *)v36 + 80LL) = v5;
      LODWORD(v19) = dsi_phy_set_clk_freq(*(_QWORD *)(v6 + 192), (_DWORD *)(*(_QWORD *)(v6 + 168) + 2376LL));
      if ( !(_DWORD)v19 )
      {
        v59 = *(_DWORD *)(v6 + 160);
        goto LABEL_110;
      }
LABEL_114:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to set phy clk freq, rc=%d\n",
        *(_QWORD *)(v6 + 32),
        (unsigned int)v19);
      goto LABEL_126;
    }
LABEL_110:
    if ( v59 >= 2 )
    {
      if ( *(_QWORD *)(v6 + 240) )
      {
        v60 = *(_QWORD *)(v6 + 216);
        if ( v60 )
        {
          *(_QWORD *)(v60 + 80) = v5;
          LODWORD(v19) = dsi_phy_set_clk_freq(*(_QWORD *)(v6 + 240), (_DWORD *)(*(_QWORD *)(v6 + 216) + 2376LL));
          if ( (_DWORD)v19 )
            goto LABEL_114;
        }
      }
    }
  }
  dsi_display_setup_ops((_QWORD *)v6);
  msm_register_vm_event((__int64)a2, (__int64)a1, v85, v6);
  v66 = dsi_display_manager_register(v6);
  LODWORD(v19) = 0;
  if ( (unsigned int)dsi_display_get_display_node_count(v66) == 1
    && (*(_BYTE *)(*(_QWORD *)(v6 + 264) + 2212LL) & 1) == 0 )
  {
    if ( !strcmp(*(const char **)(v6 + 40), "secondary") )
    {
      drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: changing the display_type from secondary to primary\n");
      LODWORD(v19) = 0;
      *(_QWORD *)(v6 + 40) = "primary";
    }
    else
    {
      LODWORD(v19) = 0;
    }
  }
LABEL_126:
  mutex_unlock(v6 + 72);
LABEL_127:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v19;
}
