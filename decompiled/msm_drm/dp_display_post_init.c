__int64 __fastcall dp_display_post_init(__int64 a1)
{
  __int64 v1; // x0
  void *v2; // x0
  unsigned __int64 v4; // x20
  __int64 *v5; // x28
  __int64 v6; // x8
  __int64 v7; // x21
  unsigned __int64 v8; // x0
  unsigned int v9; // w22
  __int64 *v10; // x27
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x20
  const char *v15; // x19
  __int64 (*v17)(void); // x8
  unsigned int v18; // w0
  _BYTE *v19; // x1
  unsigned __int64 v20; // x0
  __int64 *v21; // x23
  __int64 v22; // x0
  __int64 v23; // x0
  void (__fastcall *v24)(unsigned __int64, __int64); // x8
  __int64 v25; // x1
  unsigned __int64 v26; // x0
  unsigned int dp_core_version; // w22
  __int64 v28; // x0
  int v29; // w0
  const char **v30; // x23
  const char ***v31; // x24
  const char **v32; // x8
  __int64 v33; // x0
  unsigned __int64 StatusReg; // x23
  const char *v35; // x24
  int v36; // w6
  int v37; // w0
  _DWORD *v38; // x8
  unsigned __int64 v39; // x0
  __int64 v40; // x0
  __int64 (*v41)(void); // x8
  int v42; // w0
  __int64 v43; // x9
  __int64 v44; // x0
  __int64 v45; // x0
  unsigned __int64 v46; // x0
  __int64 v47; // x0
  __int64 (*v48)(void); // x8
  int v49; // w0
  __int64 (*v50)(void); // x8
  int v51; // w0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x10
  __int64 v56; // x9
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x10
  __int64 v62; // x9
  __int64 v63; // x10
  unsigned __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x1
  __int64 v68; // x3
  __int64 v69; // x8
  unsigned __int64 v70; // x0
  int **v71; // x23
  unsigned __int64 v72; // x21
  __int64 v73; // x0
  int v74; // w0
  bool v75; // w28
  __int64 v76; // x8
  unsigned __int64 v77; // x24
  int *v78; // x9
  __int64 v79; // x10
  __int64 v80; // x9
  __int64 v81; // x8
  __int64 v82; // x8
  __int64 v83; // x10
  __int64 v84; // x8
  __int64 *v85; // x22
  __int64 (*v86)(void); // x8
  int v87; // w0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 *v90; // [xsp+8h] [xbp-188h]
  __int64 *v91; // [xsp+10h] [xbp-180h]
  __int64 *v92; // [xsp+18h] [xbp-178h]
  __int64 *v93; // [xsp+20h] [xbp-170h]
  _QWORD *v94; // [xsp+28h] [xbp-168h]
  __int64 *v95; // [xsp+30h] [xbp-160h]
  __int64 *v96; // [xsp+38h] [xbp-158h]
  __int64 v97; // [xsp+40h] [xbp-150h] BYREF
  __int64 v98; // [xsp+48h] [xbp-148h]
  __int64 v99; // [xsp+50h] [xbp-140h]
  __int64 v100; // [xsp+58h] [xbp-138h]
  __int64 v101; // [xsp+60h] [xbp-130h] BYREF
  __int64 v102; // [xsp+68h] [xbp-128h]
  int *v103; // [xsp+70h] [xbp-120h]
  __int64 v104; // [xsp+78h] [xbp-118h]
  __int64 v105; // [xsp+80h] [xbp-110h]
  __int64 v106; // [xsp+88h] [xbp-108h]
  __int64 v107; // [xsp+90h] [xbp-100h]
  __int64 v108; // [xsp+98h] [xbp-F8h]
  __int64 v109; // [xsp+A0h] [xbp-F0h]
  __int64 v110; // [xsp+A8h] [xbp-E8h]
  __int64 v111; // [xsp+B0h] [xbp-E0h]
  __int64 v112; // [xsp+B8h] [xbp-D8h] BYREF
  __int64 v113; // [xsp+C0h] [xbp-D0h]
  const char **v114; // [xsp+C8h] [xbp-C8h]
  __int64 v115; // [xsp+D0h] [xbp-C0h]
  __int64 v116; // [xsp+D8h] [xbp-B8h]
  __int64 v117; // [xsp+E0h] [xbp-B0h]
  __int64 v118; // [xsp+E8h] [xbp-A8h]
  __int64 v119; // [xsp+F0h] [xbp-A0h] BYREF
  const char **v120; // [xsp+F8h] [xbp-98h]
  __int64 v121; // [xsp+100h] [xbp-90h]
  __int64 v122; // [xsp+108h] [xbp-88h]
  __int64 v123; // [xsp+110h] [xbp-80h]
  __int64 v124; // [xsp+118h] [xbp-78h]
  __int64 v125; // [xsp+120h] [xbp-70h]
  __int64 v126; // [xsp+128h] [xbp-68h]
  _QWORD v127[12]; // [xsp+130h] [xbp-60h] BYREF

  v127[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    if ( !g_dp_display || (v1 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v1 = 0;
    ipc_log_string(v1, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v2 = &unk_275B6D;
LABEL_18:
    printk(v2, "dp_display_post_init");
    v9 = -22;
    goto LABEL_19;
  }
  v4 = a1 - 1168;
  if ( a1 == 1168 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( !g_dp_display || (v12 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v12 = 0;
    ipc_log_string(v12, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v2 = &unk_24B695;
    goto LABEL_18;
  }
  v5 = (__int64 *)(a1 - 1144);
  v6 = *(_QWORD *)(a1 - 1144);
  v125 = 0;
  v126 = 0;
  v7 = v6 + 16;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = v6 + 16;
  v120 = nullptr;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = nullptr;
  v111 = 0;
  v112 = v6 + 16;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v103 = nullptr;
  v104 = 0;
  v101 = v6 + 16;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = v6;
  v98 = 0;
  _mutex_init(a1 + 560, "&dp->session_lock", &dp_init_sub_modules___key);
  _mutex_init(a1 + 608, "&dp->accounting_lock", &dp_init_sub_modules___key_283);
  v8 = dp_parser_get(*v5);
  v9 = v8;
  v10 = (__int64 *)(a1 - 1032);
  *(_QWORD *)(a1 - 1032) = v8;
  if ( v8 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_BYTE *)(v8 + 742) = *(_BYTE *)(a1 + 34);
    v17 = *(__int64 (**)(void))(*v10 + 840);
    if ( *((_DWORD *)v17 - 1) != 1715108462 )
      __break(0x8228u);
    v18 = v17();
    if ( v18 )
    {
      v9 = v18;
      if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v23 = 0;
      ipc_log_string(v23, "[e][%-4d]device tree parsing failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_2343CC, "dp_init_sub_modules");
    }
    else
    {
      v19 = (_BYTE *)*v10;
      *(_BYTE *)(a1 + 33) = *(_BYTE *)(*v10 + 724);
      *(_BYTE *)(a1 + 35) = v19[728];
      *(_BYTE *)(a1 + 72) = v19[740];
      *(_BYTE *)(a1 + 73) = v19[741];
      v20 = dp_catalog_get(v7, (__int64)v19);
      v9 = v20;
      v21 = (__int64 *)(a1 - 1016);
      *(_QWORD *)(a1 - 1016) = v20;
      if ( v20 < 0xFFFFFFFFFFFFF001LL )
      {
        v24 = *(void (__fastcall **)(unsigned __int64, __int64))(v20 + 1184);
        v25 = *(unsigned __int8 *)(a1 + 34);
        v26 = v20 + 1152;
        if ( *((_DWORD *)v24 - 1) != 1657962687 )
          __break(0x8228u);
        v24(v26, v25);
        v96 = (__int64 *)(a1 - 1016);
        dp_core_version = dp_catalog_get_dp_core_version(*v21);
        v28 = *(_QWORD *)(*v5 + 760);
        memset(v127, 0, 80);
        v29 = _of_parse_phandle_with_args(v28, "qcom,dp-aux-switch", 0, 0, 0, v127);
        v30 = (const char **)v127[0];
        v31 = (const char ***)(a1 - 1136);
        if ( v29 )
          v32 = nullptr;
        else
          v32 = (const char **)v127[0];
        *v31 = v32;
        if ( !v32 )
        {
          if ( !g_dp_display || (v33 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v33 = 0;
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(v33, "[d][%-4d]cannot parse %s handle\n", *(_DWORD *)(StatusReg + 1800), "qcom,dp-aux-switch");
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]cannot parse %s handle\n",
              *(_DWORD *)(StatusReg + 1800),
              "qcom,dp-aux-switch");
          v30 = *v31;
          *(_BYTE *)(a1 + 657) = 1;
        }
        v35 = *v30;
        if ( !strcmp(*v30, "fsa4480") )
        {
          v36 = 1;
          *(_DWORD *)(a1 - 1152) = 1;
        }
        else
        {
          v37 = strcmp(v35, "wcd939x_i2c");
          v38 = (_DWORD *)(a1 - 1152);
          if ( v37 )
          {
            v36 = 0;
            *v38 = 0;
          }
          else
          {
            v36 = 2;
            *v38 = 2;
          }
        }
        v39 = dp_aux_get(v7, *v96, *v10, (__int64)v30, *(_QWORD *)(a1 - 1120), *(_QWORD *)(a1 + 64), v36);
        LODWORD(v30) = v39;
        v95 = (__int64 *)(a1 - 1008);
        *(_QWORD *)(a1 - 1008) = v39;
        if ( v39 < 0xFFFFFFFFFFFFF001LL )
        {
          v41 = *(__int64 (**)(void))(v39 + 32);
          if ( *((_DWORD *)v41 - 1) != -1716826136 )
            __break(0x8228u);
          v42 = v41();
          if ( v42 )
          {
            LODWORD(v30) = v42;
            if ( !g_dp_display || (v45 = *(_QWORD *)(g_dp_display + 56)) == 0 )
              v45 = 0;
            ipc_log_string(v45, "[e][%-4d]DRM DP AUX register failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_24552D, "dp_init_sub_modules");
          }
          else
          {
            v43 = *v10;
            LODWORD(v100) = dp_core_version;
            v98 = *v95;
            v99 = v43;
            v30 = (const char **)dp_pll_get(&v97);
            v94 = (_QWORD *)(a1 - 968);
            *(_QWORD *)(a1 - 968) = v30;
            if ( (unsigned __int64)v30 < 0xFFFFFFFFFFFFF001LL )
            {
              v46 = dp_power_get((__int64 *)*v10, (__int64 *)v30);
              LODWORD(v30) = v46;
              v93 = (__int64 *)(a1 - 1024);
              *(_QWORD *)(a1 - 1024) = v46;
              if ( v46 < 0xFFFFFFFFFFFFF001LL )
              {
                v48 = *(__int64 (**)(void))(v46 + 88);
                if ( *((_DWORD *)v48 - 1) != 1824872147 )
                  __break(0x8228u);
                v49 = v48();
                if ( v49 )
                {
                  LODWORD(v30) = v49;
                  if ( !g_dp_display || (v53 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                    v53 = 0;
                  ipc_log_string(
                    v53,
                    "[e][%-4d]Power client create failed\n",
                    *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
                  printk(&unk_24BB39, "dp_init_sub_modules");
                }
                else
                {
                  v50 = *(__int64 (**)(void))(*v93 + 104);
                  if ( *((_DWORD *)v50 - 1) != 1873135840 )
                    __break(0x8228u);
                  v51 = v50();
                  if ( v51 )
                  {
                    LODWORD(v30) = v51;
                    if ( !g_dp_display || (v54 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                      v54 = 0;
                    ipc_log_string(
                      v54,
                      "[e][%-4d]failed to initialize mmrm, rc = %d\n",
                      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                      (_DWORD)v30);
                    printk(&unk_23E8B1, "dp_init_sub_modules");
                  }
                  else
                  {
                    v30 = (const char **)dp_link_get(v7, *v95, dp_core_version);
                    *(_QWORD *)(a1 - 1000) = v30;
                    if ( (unsigned __int64)v30 < 0xFFFFFFFFFFFFF001LL )
                    {
                      v92 = (__int64 *)(a1 - 1000);
                      v55 = *(_QWORD *)(a1 + 16);
                      v56 = *v96;
                      v113 = *v95;
                      v114 = v30;
                      v115 = v56 + 432;
                      v116 = v55;
                      v57 = *v10;
                      v117 = 0;
                      v118 = v57;
                      v30 = (const char **)dp_panel_get(&v112);
                      v91 = (__int64 *)(a1 - 992);
                      *(_QWORD *)(a1 - 992) = v30;
                      if ( (unsigned __int64)v30 < 0xFFFFFFFFFFFFF001LL )
                      {
                        v59 = *v95;
                        v60 = *v93;
                        v61 = *v96 + 88;
                        v120 = v30;
                        v121 = v59;
                        v124 = v60;
                        v125 = v61;
                        v62 = *v10;
                        v63 = *v94;
                        v122 = *v92;
                        v123 = v62;
                        v126 = v63;
                        v64 = dp_ctrl_get(&v119);
                        v90 = (__int64 *)(a1 - 984);
                        *(_QWORD *)(a1 - 984) = v64;
                        if ( v64 < 0xFFFFFFFFFFFFF001LL )
                        {
                          *(_QWORD *)(*v91 + 952) = dp_audio_get(*v5, *v91, *v96 + 368);
                          v30 = *(const char ***)(*v91 + 952);
                          if ( (unsigned __int64)v30 < 0xFFFFFFFFFFFFF001LL )
                          {
                            *(_QWORD *)(a1 + 692) = 0;
                            *(_QWORD *)(a1 + 700) = 0;
                            v67 = *v10;
                            *(_QWORD *)(a1 + 676) = 0;
                            *(_QWORD *)(a1 + 684) = 0;
                            v68 = *(_QWORD *)(a1 - 1120);
                            *(_QWORD *)(a1 + 660) = 0;
                            *(_QWORD *)(a1 + 668) = 0;
                            *(_QWORD *)(a1 - 816) = dp_display_usbpd_disconnect_cb;
                            v69 = *v96;
                            *(_DWORD *)(a1 + 708) = 0;
                            *(_QWORD *)(a1 - 808) = dp_display_usbpd_attention_cb;
                            *(_QWORD *)(a1 - 824) = dp_display_usbpd_configure_cb;
                            v70 = dp_hpd_get(v7, v67, v69 + 1152, v68, a1 - 824);
                            v71 = (int **)(a1 - 1040);
                            *(_QWORD *)(a1 - 1040) = v70;
                            if ( v70 < 0xFFFFFFFFFFFFF001LL )
                            {
                              v74 = dp_display_initialize_hdcp(v4);
                              v75 = v74 != 0;
                              if ( !g_dp_display || (v76 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                                v76 = 0;
                              v77 = _ReadStatusReg(SP_EL0);
                              ipc_log_string(v76, "[i][%-4d]: hdcp_disabled = %d\n", *(_DWORD *)(v77 + 1800), v74 != 0);
                              if ( (_drm_debug & 4) != 0 )
                                printk(&unk_2617D5, *(unsigned int *)(v77 + 1800));
                              else
                                printk(&unk_23E8F1, "dp_init_sub_modules");
                              v78 = *v71;
                              v79 = *v92;
                              v102 = *v91;
                              v103 = v78;
                              v80 = *v10;
                              v81 = *v95;
                              v104 = v79;
                              v105 = v81;
                              v82 = *v96;
                              v83 = *v94;
                              v106 = a1 + 16;
                              v107 = v82;
                              v110 = v83;
                              v111 = a1;
                              v84 = *v90;
                              v108 = v80;
                              v109 = v84;
                              v72 = dp_debug_get(&v101);
                              v85 = (__int64 *)(a1 - 976);
                              *(_QWORD *)(a1 - 976) = v72;
                              if ( v72 >= 0xFFFFFFFFFFFFF001LL )
                              {
                                if ( !g_dp_display || (v89 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                                  v89 = 0;
                                ipc_log_string(
                                  v89,
                                  "[e][%-4d]failed to initialize debug, rc = %d\n",
                                  *(_DWORD *)(v77 + 1800),
                                  v72);
                                printk(&unk_2680E2, "dp_init_sub_modules");
                                *v85 = 0;
                              }
                              else
                              {
                                *(_QWORD *)(a1 + 712) = 0;
                                *(_BYTE *)(v72 + 2) = v75;
                                dp_display_update_hdcp_status(v4, 1);
                                dp_display_register_usb_notifier(v4);
                                v86 = *((__int64 (**)(void))*v71 + 3);
                                if ( !v86 )
                                  goto LABEL_127;
                                if ( *((_DWORD *)v86 - 1) != -1739071012 )
                                  __break(0x8228u);
                                v87 = v86();
                                if ( !v87 )
                                  goto LABEL_127;
                                LODWORD(v72) = v87;
                                if ( !g_dp_display || (v88 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                                  v88 = 0;
                                ipc_log_string(v88, "[e][%-4d]failed register hpd\n", *(_DWORD *)(v77 + 1800));
                                printk(&unk_2797BB, "dp_init_sub_modules");
                                dp_debug_put(*v85);
                              }
                              dp_hpd_put(*v71);
                            }
                            else
                            {
                              LODWORD(v72) = v70;
                              if ( !g_dp_display || (v73 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                                v73 = 0;
                              ipc_log_string(
                                v73,
                                "[e][%-4d]failed to initialize hpd, rc = %d\n",
                                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                                v72);
                              printk(&unk_23AFAC, "dp_init_sub_modules");
                              *v71 = nullptr;
                            }
                            dp_audio_put(*(_QWORD *)(*v91 + 952));
                            LODWORD(v30) = v72;
                          }
                          else
                          {
                            if ( !g_dp_display || (v66 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                              v66 = 0;
                            ipc_log_string(
                              v66,
                              "[e][%-4d]failed to initialize audio, rc = %d\n",
                              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                              (_DWORD)v30);
                            printk(&unk_24BB71, "dp_init_sub_modules");
                            *(_QWORD *)(*v91 + 952) = 0;
                          }
                          dp_ctrl_put(*v90);
                        }
                        else
                        {
                          LODWORD(v30) = v64;
                          if ( !g_dp_display || (v65 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                            v65 = 0;
                          ipc_log_string(
                            v65,
                            "[e][%-4d]failed to initialize ctrl, rc = %d\n",
                            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                            (_DWORD)v30);
                          printk(&unk_237A37, "dp_init_sub_modules");
                          *v90 = 0;
                        }
                        dp_panel_put(*v91);
                      }
                      else
                      {
                        if ( !g_dp_display || (v58 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                          v58 = 0;
                        ipc_log_string(
                          v58,
                          "[e][%-4d]failed to initialize panel, rc = %d\n",
                          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                          (_DWORD)v30);
                        printk(&unk_215270, "dp_init_sub_modules");
                        *v91 = 0;
                      }
                      dp_link_put(*v92);
                    }
                    else
                    {
                      if ( !g_dp_display || (v52 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                        v52 = 0;
                      ipc_log_string(
                        v52,
                        "[e][%-4d]failed to initialize link, rc = %d\n",
                        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                        (_DWORD)v30);
                      printk(&unk_24214F, "dp_init_sub_modules");
                      *(_QWORD *)(a1 - 1000) = 0;
                    }
                  }
                }
                dp_power_put(*v93);
              }
              else
              {
                if ( !g_dp_display || (v47 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                  v47 = 0;
                ipc_log_string(
                  v47,
                  "[e][%-4d]failed to initialize power, rc = %d\n",
                  *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                  (_DWORD)v30);
                printk(&unk_2680A1, "dp_init_sub_modules");
                *v93 = 0;
              }
              dp_pll_put(*v94);
            }
            else
            {
              if ( !g_dp_display || (v44 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                v44 = 0;
              ipc_log_string(
                v44,
                "[e][%-4d]failed to initialize pll, rc = %d\n",
                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                (_DWORD)v30);
              printk(&unk_259F76, "dp_init_sub_modules");
              *v94 = 0;
            }
          }
          dp_aux_put(*v95);
        }
        else
        {
          if ( !g_dp_display || (v40 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v40 = 0;
          ipc_log_string(
            v40,
            "[e][%-4d]failed to initialize aux, rc = %d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            (_DWORD)v30);
          printk(&unk_2117C6, "dp_init_sub_modules");
          *v95 = 0;
        }
        dp_catalog_put(*v96);
        v9 = (unsigned int)v30;
      }
      else
      {
        if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v22 = 0;
        ipc_log_string(
          v22,
          "[e][%-4d]failed to initialize catalog, rc = %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          v9);
        printk(&unk_276355, "dp_init_sub_modules");
        *v21 = 0;
      }
    }
    dp_parser_put(*v10);
    if ( v9 )
      goto LABEL_19;
LABEL_127:
    v9 = 0;
    *(_QWORD *)(a1 + 192) = 0;
    goto LABEL_19;
  }
  if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v11 = 0;
  ipc_log_string(v11, "[e][%-4d]failed to initialize parser, rc = %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v9);
  printk(&unk_24210D, "dp_init_sub_modules");
  *v10 = 0;
  if ( !v9 )
    goto LABEL_127;
LABEL_19:
  if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v13 = 0;
  v14 = _ReadStatusReg(SP_EL0);
  if ( v9 )
    v15 = "failed";
  else
    v15 = "success";
  ipc_log_string(v13, "[d][%-4d]%s\n", *(_DWORD *)(v14 + 1800), v15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s\n", *(_DWORD *)(v14 + 1800), v15);
  _ReadStatusReg(SP_EL0);
  return v9;
}
