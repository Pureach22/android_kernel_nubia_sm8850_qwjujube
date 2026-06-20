__int64 __fastcall wlan_ipa_uc_loaded_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _BYTE *v10; // x22
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  char v40; // w10
  __int64 v41; // x4
  __int64 v42; // x9
  _DWORD *v43; // x9
  __int64 v44; // x5
  __int64 v45; // x20
  unsigned int v46; // w21
  __int64 v47; // x20
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 (*v50)(void); // x8
  unsigned int v51; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  __int64 v61; // x8
  void (*v62)(void); // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 (*v72)(void); // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x24
  unsigned __int8 *v82; // x23
  __int64 v83; // x21
  __int64 v84; // x8
  __int64 v85; // x20
  __int64 v86; // x1
  __int64 v87; // x0
  __int64 v88; // x8
  unsigned int (*v89)(void); // x8
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w2
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // x8
  __int64 v108; // x8
  __int64 v109; // x8
  __int64 v110; // x8
  __int64 v111; // x8
  __int64 v112; // x0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  int v129; // w1
  char v130; // [xsp+20h] [xbp-20h]
  int v131; // [xsp+28h] [xbp-18h]
  int v132; // [xsp+30h] [xbp-10h]

  v10 = (_BYTE *)(a1 + 4096);
  if ( *(_QWORD *)a1 )
    v11 = *(_QWORD *)(*(_QWORD *)a1 + 2120LL);
  else
    v11 = 0;
  qdf_trace_msg(0x61u, 4u, "%s: UC READY", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_uc_loaded_handler");
  if ( v10[2888] == 1 )
    return qdf_trace_msg(
             0x61u,
             4u,
             "%s: UC already loaded",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wlan_ipa_uc_loaded_handler");
  if ( !v11 )
    return qdf_trace_msg(
             0x61u,
             2u,
             "%s: qdf_dev is null",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wlan_ipa_uc_loaded_handler");
  if ( (**(_BYTE **)(a1 + 1464) & 0x40) != 0 )
  {
    v21 = wlan_ipa_setup_sys_pipe(a1);
    if ( v21 )
      return qdf_trace_msg(
               0x61u,
               2u,
               "%s: Fail to setup sys pipes (status=%d)",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "wlan_ipa_uc_loaded_handler",
               v21);
    *(_QWORD *)(a1 + 7336) = wlan_ipa_mcc_work_handler;
    *(_QWORD *)(a1 + 7304) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 7344) = a1;
    *(_QWORD *)(a1 + 7312) = a1 + 7312;
    *(_QWORD *)(a1 + 7320) = a1 + 7312;
    *(_QWORD *)(a1 + 7328) = _qdf_defer_func;
  }
  v30 = _qdf_mem_malloc(0x300u, "wlan_ipa_wdi_setup", 676);
  if ( v30 )
  {
    v39 = *(_QWORD *)(a1 + 1456);
    if ( v10[3340] == 1 )
    {
      v40 = *(_BYTE *)(v11 + 608);
      if ( !v39 )
        goto LABEL_25;
    }
    else
    {
      v40 = 0;
      if ( !v39 )
      {
LABEL_25:
        v47 = v30;
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v31, v32, v33, v34, v35, v36, v37, v38, "cdp_ipa_setup");
        _qdf_mem_free(v47);
        v41 = 16;
        goto LABEL_26;
      }
    }
    if ( *(_QWORD *)v39 )
    {
      v42 = *(_QWORD *)(*(_QWORD *)v39 + 152LL);
      if ( v42 )
      {
        v43 = *(_DWORD **)(v42 + 120);
        if ( v43 )
        {
          v44 = *(unsigned int *)(*(_QWORD *)(a1 + 1464) + 4LL);
          v45 = v30;
          v132 = (unsigned __int8)v10[3360];
          v131 = *(_DWORD *)(a1 + 7460);
          v130 = v10[2890];
          if ( *(v43 - 1) != -208635689 )
            __break(0x8229u);
          v46 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 (__fastcall *)(), __int64 (__fastcall *)(__int64, unsigned int, __int64), __int64 (__fastcall *)(), __int64, __int64, __int64, __int64, __int64, _BYTE, __int64, char, int, int, __int64 (__fastcall *)()))v43)(
                  v39,
                  0,
                  wlan_ipa_i2w_cb,
                  wlan_ipa_w2i_cb,
                  wlan_ipa_wdi_meter_notifier_cb,
                  v44,
                  a1,
                  1,
                  a1 + 3712,
                  a1 + 3716,
                  v40 & 1,
                  v30,
                  v130,
                  v131,
                  v132,
                  wlan_ipa_ast_notify_cb);
          _qdf_mem_free(v45);
          v41 = v46;
          if ( v46 )
            goto LABEL_26;
        }
        else
        {
          _qdf_mem_free(v30);
        }
        v48 = *(_QWORD *)(a1 + 1456);
        if ( v48 && *(_QWORD *)v48 && (v49 = *(_QWORD *)(*(_QWORD *)v48 + 152LL)) != 0 )
        {
          v50 = *(__int64 (**)(void))(v49 + 184);
          if ( !v50 )
            goto LABEL_46;
          if ( *((_DWORD *)v50 - 1) != -1922697876 )
            __break(0x8228u);
          v51 = v50();
          v41 = v51;
          if ( !v51 )
          {
LABEL_46:
            qdf_trace_msg(
              0x61u,
              4u,
              "%s: TX buffers mapped to IPA",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "wlan_ipa_uc_loaded_handler",
              v41);
            v60 = *(_QWORD *)(a1 + 1456);
            if ( v60 && *(_QWORD *)v60 && (v61 = *(_QWORD *)(*(_QWORD *)v60 + 152LL)) != 0 )
            {
              v62 = *(void (**)(void))(v61 + 8);
              if ( v62 )
              {
                if ( *((_DWORD *)v62 - 1) != 261447488 )
                  __break(0x8228u);
                v62();
              }
            }
            else
            {
              qdf_trace_msg(
                0x45u,
                1u,
                "%s invalid instance",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "cdp_ipa_set_doorbell_paddr");
            }
            wlan_ipa_add_rem_flt_cb_event(a1);
            result = wlan_ipa_init_perf_level(a1);
            if ( (_DWORD)result )
              result = qdf_trace_msg(
                         0x61u,
                         2u,
                         "%s: Failed to init perf level",
                         v73,
                         v74,
                         v75,
                         v76,
                         v77,
                         v78,
                         v79,
                         v80,
                         "wlan_ipa_uc_loaded_handler");
            v81 = 0;
            v82 = v10 + 3192;
            v83 = a1 + 1064;
            while ( 1 )
            {
              v84 = v82[v81];
              if ( (unsigned int)v84 <= 4 )
              {
                if ( (_DWORD)v84 == 4 )
                  goto LABEL_111;
                v85 = v83 + (v84 << 7);
                if ( *(unsigned __int8 *)(v85 + 52) <= 4u )
                {
                  v86 = *(_QWORD *)(v85 + 24);
                  if ( v86 )
                  {
                    v87 = *(_QWORD *)(a1 + 1456);
                    if ( !v87 || !*(_QWORD *)v87 || (v88 = *(_QWORD *)(*(_QWORD *)v87 + 152LL)) == 0 )
                    {
                      qdf_trace_msg(
                        0x45u,
                        1u,
                        "%s invalid instance",
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        v79,
                        v80,
                        "cdp_ipa_setup_iface");
LABEL_84:
                      result = qdf_trace_msg(
                                 0x61u,
                                 2u,
                                 "%s: Failed to setup iface %d",
                                 v90,
                                 v91,
                                 v92,
                                 v93,
                                 v94,
                                 v95,
                                 v96,
                                 v97,
                                 "wlan_ipa_uc_loaded_handler",
                                 *(unsigned __int8 *)(v85 + 52));
                      v107 = *v82;
                      if ( (unsigned int)v107 <= 4 )
                      {
                        if ( (_DWORD)v107 != 4 )
                        {
                          result = v83 + (v107 << 7);
                          if ( *(unsigned __int8 *)(result + 52) <= 4u )
                            result = wlan_ipa_cleanup_iface(
                                       (__int64 *)result,
                                       (unsigned __int8 *)(result + 36),
                                       v99,
                                       v100,
                                       v101,
                                       v102,
                                       v103,
                                       v104,
                                       v105,
                                       v106);
                          goto LABEL_88;
                        }
LABEL_111:
                        __break(0x5512u);
                        return wlan_ipa_opt_dp_wait_for_completion(result);
                      }
LABEL_88:
                      v108 = (unsigned __int8)v10[3193];
                      if ( (unsigned int)v108 <= 4 )
                      {
                        if ( (_DWORD)v108 == 4 )
                          goto LABEL_111;
                        result = v83 + (v108 << 7);
                        if ( *(unsigned __int8 *)(result + 52) <= 4u )
                          result = wlan_ipa_cleanup_iface(
                                     (__int64 *)result,
                                     (unsigned __int8 *)(result + 36),
                                     v99,
                                     v100,
                                     v101,
                                     v102,
                                     v103,
                                     v104,
                                     v105,
                                     v106);
                      }
                      v109 = (unsigned __int8)v10[3194];
                      if ( (unsigned int)v109 <= 4 )
                      {
                        if ( (_DWORD)v109 == 4 )
                          goto LABEL_111;
                        result = v83 + (v109 << 7);
                        if ( *(unsigned __int8 *)(result + 52) <= 4u )
                          result = wlan_ipa_cleanup_iface(
                                     (__int64 *)result,
                                     (unsigned __int8 *)(result + 36),
                                     v99,
                                     v100,
                                     v101,
                                     v102,
                                     v103,
                                     v104,
                                     v105,
                                     v106);
                      }
                      v110 = (unsigned __int8)v10[3195];
                      if ( (unsigned int)v110 <= 4 )
                      {
                        if ( (_DWORD)v110 == 4 )
                          goto LABEL_111;
                        result = v83 + (v110 << 7);
                        if ( *(unsigned __int8 *)(result + 52) <= 4u )
                          result = wlan_ipa_cleanup_iface(
                                     (__int64 *)result,
                                     (unsigned __int8 *)(result + 36),
                                     v99,
                                     v100,
                                     v101,
                                     v102,
                                     v103,
                                     v104,
                                     v105,
                                     v106);
                      }
                      v111 = (unsigned __int8)v10[3196];
                      if ( (unsigned int)v111 <= 4 )
                      {
                        if ( (_DWORD)v111 == 4 )
                          goto LABEL_111;
                        v112 = v83 + (v111 << 7);
                        if ( *(unsigned __int8 *)(v112 + 52) <= 4u )
                          wlan_ipa_cleanup_iface(
                            (__int64 *)v112,
                            (unsigned __int8 *)(v112 + 36),
                            v99,
                            v100,
                            v101,
                            v102,
                            v103,
                            v104,
                            v105,
                            v106);
                      }
                      cdp_ipa_iounmap_doorbell_vaddr(
                        *(_QWORD *)(a1 + 1456),
                        v99,
                        v100,
                        v101,
                        v102,
                        v103,
                        v104,
                        v105,
                        v106);
                      cdp_ipa_tx_buf_smmu_unmapping(
                        *(_QWORD *)(a1 + 1456),
                        v113,
                        v114,
                        v115,
                        v116,
                        v117,
                        v118,
                        v119,
                        v120);
                      result = *(_QWORD *)(a1 + 1456);
                      if ( result )
                        goto LABEL_55;
                      goto LABEL_105;
                    }
                    v89 = *(unsigned int (**)(void))(v88 + 136);
                    if ( v89 )
                    {
                      if ( *((_DWORD *)v89 - 1) != 1486385766 )
                        __break(0x8228u);
                      if ( v89() )
                        goto LABEL_84;
                      v86 = *(_QWORD *)(v85 + 24);
                    }
                    if ( *(_DWORD *)(v85 + 32) )
                      v98 = 2;
                    else
                      v98 = 4;
                    result = wlan_ipa_send_msg(v85, v86, v98, (const void *)(v85 + 36));
                    if ( !(_DWORD)result )
                      ++*(_QWORD *)(a1 + 3552);
                  }
                }
              }
              if ( ++v81 == 5 )
              {
                if ( *(_WORD *)(a1 + 3706) || *(_BYTE *)(a1 + 3710) )
                {
                  qdf_trace_msg(
                    0x61u,
                    8u,
                    "%s: Client already connected, enable IPA/FW PIPEs",
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    v79,
                    v80,
                    "wlan_ipa_uc_loaded_handler");
                  result = wlan_ipa_uc_handle_first_con(a1, v121, v122, v123, v124, v125, v126, v127, v128);
                }
                v129 = (unsigned __int8)v10[3352];
                v10[2888] = 1;
                if ( v129 != 3 )
                  return wlan_ipa_set_perf_level_bw(a1);
                return result;
              }
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "cdp_ipa_tx_buf_smmu_mapping",
            v41);
          v41 = 16;
        }
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: Failure to map Tx buffers for IPA(status=%d)",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_ipa_uc_loaded_handler",
          v41);
        result = *(_QWORD *)(a1 + 1456);
        if ( !result )
          goto LABEL_105;
LABEL_55:
        if ( *(_QWORD *)result && (v71 = *(_QWORD *)(*(_QWORD *)result + 152LL)) != 0 )
        {
          v72 = *(__int64 (**)(void))(v71 + 128);
          if ( v72 )
          {
            if ( *((_DWORD *)v72 - 1) != -1401535946 )
              __break(0x8228u);
            result = v72();
          }
        }
        else
        {
LABEL_105:
          result = qdf_trace_msg(
                     0x45u,
                     1u,
                     "%s invalid instance",
                     v63,
                     v64,
                     v65,
                     v66,
                     v67,
                     v68,
                     v69,
                     v70,
                     "cdp_ipa_cleanup");
        }
        goto LABEL_27;
      }
    }
    goto LABEL_25;
  }
  v41 = 2;
LABEL_26:
  result = qdf_trace_msg(
             0x61u,
             2u,
             "%s: Failure to setup IPA pipes (status=%d)",
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             "wlan_ipa_uc_loaded_handler",
             v41);
LABEL_27:
  if ( (**(_BYTE **)(a1 + 1464) & 0x40) != 0 )
  {
    result = cancel_work_sync(a1 + 7304);
    if ( a1 )
    {
      if ( *(_BYTE *)(a1 + 12) )
        *(_BYTE *)(a1 + 12) = 0;
      if ( *(_BYTE *)(a1 + 276) )
        *(_BYTE *)(a1 + 276) = 0;
      if ( *(_BYTE *)(a1 + 540) )
        *(_BYTE *)(a1 + 540) = 0;
      if ( *(_BYTE *)(a1 + 804) )
        *(_BYTE *)(a1 + 804) = 0;
    }
  }
  return result;
}
