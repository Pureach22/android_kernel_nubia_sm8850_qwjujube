__int64 __fastcall wma_process_cli_set_cmd(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w23
  __int64 v13; // x25
  _QWORD *context; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x24
  int v34; // w4
  unsigned int v35; // w21
  __int64 result; // x0
  const char *v37; // x2
  unsigned int v38; // w1
  int v39; // w8
  __int64 v40; // x22
  __int64 v41; // x4
  unsigned int v42; // w8
  unsigned int v43; // w23
  _QWORD *v44; // x24
  __int64 v45; // x25
  int v46; // w2
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w24
  int v57; // w8
  unsigned int v58; // w24
  unsigned int v59; // w22
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  const char *v76; // x2
  const char *v77; // x2
  __int64 v78; // x5
  const char *v79; // x2
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w8
  unsigned int v89; // w8
  __int64 v90; // x5
  __int64 v91; // x4
  unsigned int v92; // w8
  unsigned int v93; // w8
  __int64 v94; // x0
  __int64 v95; // x1
  __int64 v96; // x2
  __int64 v97; // x4
  const char *v98; // x2
  unsigned int v99; // w8
  unsigned int v100; // w8
  unsigned int v101; // w8
  unsigned int v102; // w8
  unsigned int v103; // w9
  __int64 v104; // x0
  unsigned int v105; // w8
  int v106; // w4
  unsigned int v107; // w8
  __int64 v108; // x9
  const char *v109; // x2
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  int v118; // [xsp+Ch] [xbp-24h] BYREF
  unsigned __int64 v119; // [xsp+10h] [xbp-20h]
  int v120; // [xsp+18h] [xbp-18h]
  unsigned int v121; // [xsp+20h] [xbp-10h]
  unsigned int v122; // [xsp+24h] [xbp-Ch]
  __int64 v123; // [xsp+28h] [xbp-8h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[3];
  v13 = a1[65];
  context = _cds_get_context(53, (__int64)"wma_process_cli_set_cmd", a3, a4, a5, a6, a7, a8, a9, a10);
  v120 = 0;
  v119 = 0;
  v23 = _cds_get_context(71, (__int64)"wma_process_cli_set_cmd", v15, v16, v17, v18, v19, v20, v21, v22);
  v118 = 0;
  if ( !context )
  {
    v37 = "%s: Failed to get mac";
    goto LABEL_12;
  }
  v32 = a1[3];
  if ( !v32 || (v33 = *(_QWORD *)(v32 + 2800)) == 0 )
  {
    v37 = "%s: target psoc info is NULL";
LABEL_12:
    v38 = 2;
LABEL_13:
    result = qdf_trace_msg(0x36u, v38, v37, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd");
    goto LABEL_14;
  }
  v34 = *a2;
  if ( *a2 >= 0x1E004 )
  {
    if ( v34 > 122886 )
    {
      if ( v34 == 122887 )
      {
        v58 = a2[1];
        v59 = HIBYTE(v58) & 3;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Parsed input: Channel #1:%d, Channel #2:%d, quota 1:%dms band_1 0x%x band_2 0x%x",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_set_priv_cfg",
          BYTE1(v58),
          (unsigned __int8)v58,
          BYTE2(v58),
          v59,
          (v58 >> 26) & 3);
        result = wma_set_mcc_channel_time_quota(
                   a1,
                   BYTE1(v58),
                   BYTE2(v58),
                   (unsigned __int8)v58,
                   v59,
                   (v58 >> 26) & 3,
                   v60,
                   v61,
                   v62,
                   v63,
                   v64,
                   v65,
                   v66,
                   v67);
        goto LABEL_14;
      }
      if ( v34 != 139265 )
      {
        if ( v34 == 139266 )
        {
          result = wma_set_smps_params(a1, a2[3], a2[1]);
          goto LABEL_14;
        }
LABEL_45:
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid wma config command id:%d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_set_priv_cfg");
LABEL_49:
        v37 = "%s: Failed to set wma priv configuration";
        goto LABEL_12;
      }
      result = wma_set_mimops(a1, a2[3], a2[1]);
    }
    else
    {
      switch ( v34 )
      {
        case 122884:
          result = wma_set_txrx_fw_stats_level(a1, a2[3], a2[1]);
          break;
        case 122885:
          result = wma_txrx_fw_stats_reset(a1, a2[3], a2[1]);
          break;
        case 122886:
          v35 = a2[1];
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Parsed input: Channel #1:%d, latency:%dms",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wma_set_priv_cfg",
            (unsigned __int8)v35,
            BYTE1(v35));
          result = wma_set_mcc_channel_time_latency(a1, v35, BYTE1(v35));
          goto LABEL_14;
        default:
          goto LABEL_45;
      }
    }
    if ( !(_DWORD)result )
      goto LABEL_14;
    goto LABEL_49;
  }
  v39 = a2[4];
  v40 = v13 + 488LL * (int)v12;
  if ( v39 <= 3 )
  {
    switch ( v39 )
    {
      case 1:
        if ( (wma_is_vdev_valid(a2[3], v24, v25, v26, v27, v28, v29, v30, v31) & 1) == 0 )
        {
          v37 = "%s: Vdev id is not valid";
          goto LABEL_12;
        }
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: vdev id %d pid %d pval %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_process_cli_set_cmd",
          a2[3],
          *a2,
          a2[1]);
        result = wma_vdev_set_param(*a1, a2[3], *a2, a2[1], v68, v69, v70, v71, v72, v73, v74, v75);
        if ( !(_DWORD)result )
          goto LABEL_178;
        break;
      case 2:
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: pdev pid %d pval %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_process_cli_set_cmd");
        v88 = *a2;
        if ( *a2 - 1 <= 1 )
        {
          if ( (unsigned int)wma_check_txrx_chainmask(
                               *(_DWORD *)(v33 + 688),
                               a2[1],
                               v80,
                               v81,
                               v82,
                               v83,
                               v84,
                               v85,
                               v86,
                               v87) )
          {
LABEL_69:
            v37 = "%s: Chainmask value is invalid";
            v38 = 8;
            goto LABEL_13;
          }
          v88 = *a2;
          if ( *a2 == 1 )
          {
            if ( (wma_is_tx_chainmask_valid(a2[1], v33) & 1) == 0 )
              goto LABEL_69;
            v88 = *a2;
          }
        }
        v119 = __PAIR64__(a2[1], v88);
        if ( v88 == 212 )
          HIDWORD(v119) = wma_convert_ac_value();
        result = wmi_unified_pdev_param_send(*a1);
        if ( !(_DWORD)result )
          goto LABEL_178;
        break;
      case 3:
        v44 = v23;
        v45 = a1[65];
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: gen pid %d pval %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_process_cli_set_cmd");
        v46 = *a2;
        if ( (int)*a2 > 3 )
        {
          if ( v46 == 4 )
          {
            result = wma_capture_tsf(a1, a2[1]);
            goto LABEL_178;
          }
          if ( v46 == 5 )
          {
            result = wma_reset_tsf_gpio(a1, a2[1]);
            goto LABEL_178;
          }
        }
        else
        {
          if ( (unsigned int)(v46 - 1) < 2 )
          {
            if ( !v44 )
            {
              v37 = "%s: SOC context is NULL";
              goto LABEL_12;
            }
            if ( v46 == 1 )
            {
              v47 = cdp_aggr_cfg(v44, a2[3], a2[1]);
              if ( v47 )
              {
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: cdp_aggr_cfg set ampdu failed ret %d",
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  "wma_process_cli_set_cmd",
                  v47);
                v56 = 0;
              }
              else
              {
                v56 = 0;
                *(_DWORD *)(v45 + 488LL * a2[3] + 48) = a2[1];
              }
            }
            else
            {
              v56 = 1;
            }
            wlan_mlme_get_eht_mode(a1[3], &v118);
            if ( (v118 & 0xFFFFFFFE) == 2 )
            {
              result = wma_set_per_link_amsdu_cap(a1, a2, v56);
              if ( (_DWORD)result )
                goto LABEL_14;
              goto LABEL_178;
            }
            result = wma_set_tx_rx_aggr_size(v12, a2[1], a2[1], v56, v110, v111, v112, v113, v114, v115, v116, v117);
            if ( !(_DWORD)result )
              goto LABEL_178;
            v97 = (unsigned int)result;
            v98 = "%s: set_aggr_size failed ret %d";
LABEL_125:
            result = qdf_trace_msg(
                       0x36u,
                       2u,
                       v98,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       "wma_process_cli_set_cmd",
                       v97);
            goto LABEL_14;
          }
          if ( v46 == 3 )
          {
            if ( (unsigned int)cds_get_conparam() != 5 )
            {
              v103 = a2[2];
              v104 = *a1;
              v121 = a2[1];
              v122 = v103;
              result = wmi_crash_inject(v104);
              goto LABEL_178;
            }
            v76 = "%s: Crash inject not allowed in FTM mode";
            goto LABEL_54;
          }
        }
        result = wma_set_tsf_auto_report(a1, a2[3], v46, a2[1] != 0, v24, v25, v26, v27, v28, v29, v30, v31);
        if ( (_DWORD)result != 16 )
          goto LABEL_178;
        v41 = *a2;
        goto LABEL_129;
      default:
LABEL_53:
        v76 = "%s: Invalid vpdev command id";
LABEL_54:
        result = qdf_trace_msg(0x36u, 2u, v76, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd");
        goto LABEL_178;
    }
LABEL_124:
    v97 = (unsigned int)result;
    v98 = "%s: wma_vdev_set_param failed ret %d";
    goto LABEL_125;
  }
  if ( v39 > 5 )
  {
    if ( v39 == 6 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: QPOWER CLI CMD pid %d pval %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wma_process_cli_set_cmd");
      v41 = *a2;
      if ( (int)v41 > 7 )
      {
        if ( (_DWORD)v41 == 8 )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: QPOWER CLI CMD:Ps Poll Wake Inv val %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wma_process_cli_set_cmd",
            a2[1]);
          result = wma_unified_set_sta_ps_param(*a1, v12, 8, a2[1]);
          v78 = a2[1];
          if ( !(_DWORD)result )
          {
            v43 = 0;
            *(_DWORD *)(v40 + 104) = v78;
            goto LABEL_179;
          }
          v79 = "%s: Set Q-PsPoll WakeIntv Failed vId %d val %d";
        }
        else
        {
          if ( (_DWORD)v41 != 9 )
            goto LABEL_129;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: QPOWER CLI CMD:Spec NoData Ps Poll val %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wma_process_cli_set_cmd",
            a2[1]);
          result = wma_unified_set_sta_ps_param(*a1, v12, 9, a2[1]);
          v78 = a2[1];
          if ( !(_DWORD)result )
          {
            v43 = 0;
            *(_DWORD *)(v40 + 108) = v78;
            goto LABEL_179;
          }
          v79 = "%s: Set Q-SpecNoDataPsPoll Failed vId %d val %d";
        }
      }
      else if ( (_DWORD)v41 == 5 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: QPOWER CLI CMD:Ps Poll Cnt val %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_process_cli_set_cmd",
          a2[1]);
        result = wma_unified_set_sta_ps_param(*a1, v12, 5, a2[1]);
        v78 = a2[1];
        if ( !(_DWORD)result )
        {
          v43 = 0;
          *(_DWORD *)(v40 + 96) = v78;
          goto LABEL_179;
        }
        v79 = "%s: Set Q-PsPollCnt Failed vdevId %d val %d";
      }
      else
      {
        if ( (_DWORD)v41 != 7 )
          goto LABEL_129;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: QPOWER CLI CMD:Max Tx Before wake val %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_process_cli_set_cmd",
          a2[1]);
        result = wma_unified_set_sta_ps_param(*a1, v12, 7, a2[1]);
        v78 = a2[1];
        if ( !(_DWORD)result )
        {
          v43 = 0;
          *(_DWORD *)(v40 + 100) = v78;
          goto LABEL_179;
        }
        v79 = "%s: Set Q-MaxTxBefWake Failed vId %d val %d";
      }
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 v79,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wma_process_cli_set_cmd",
                 v12,
                 v78);
      goto LABEL_178;
    }
    if ( v39 == 7 )
    {
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: vdev id %d pid %d pval %d",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wma_process_cli_set_cmd",
                 a2[3],
                 (unsigned int)v34,
                 a2[1]);
      v57 = *a2;
      v43 = 0;
      if ( (int)*a2 <= 3 )
      {
        if ( v57 > 1 )
        {
          if ( v57 == 2 )
          {
            *(_DWORD *)(v40 + 120) = a2[1];
          }
          else
          {
            if ( v57 != 3 )
              goto LABEL_179;
            *(_DWORD *)(v40 + 124) = a2[1];
          }
        }
        else
        {
          if ( !v57 )
          {
            *(_DWORD *)(v40 + 112) = a2[1];
            result = wmi_unified_vdev_set_gtx_cfg_send(*a1);
            goto LABEL_178;
          }
          if ( v57 != 1 )
            goto LABEL_179;
          *(_DWORD *)(v40 + 116) = a2[1];
        }
LABEL_146:
        result = wmi_unified_vdev_set_gtx_cfg_send(*a1);
        goto LABEL_178;
      }
      if ( v57 <= 5 )
      {
        if ( v57 == 4 )
        {
          *(_DWORD *)(v40 + 128) = a2[1];
        }
        else
        {
          if ( v57 != 5 )
            goto LABEL_179;
          *(_DWORD *)(v40 + 132) = a2[1];
        }
        goto LABEL_146;
      }
      if ( v57 == 6 )
      {
        *(_DWORD *)(v40 + 136) = a2[1];
        goto LABEL_146;
      }
      if ( v57 != 7 )
        goto LABEL_179;
      *(_DWORD *)(v40 + 140) = a2[1];
      result = wmi_unified_vdev_set_gtx_cfg_send(*a1);
      if ( !(_DWORD)result )
        goto LABEL_178;
      goto LABEL_124;
    }
    goto LABEL_53;
  }
  if ( v39 == 4 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: dbg pid %d pval %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_process_cli_set_cmd");
    v41 = *a2;
    if ( (int)v41 <= 7 )
    {
      if ( (int)v41 > 3 )
      {
        if ( (int)v41 > 5 )
        {
          if ( (_DWORD)v41 != 6 )
          {
            result = dbglog_parser_type_init(*a1, a2[1]);
            if ( (_DWORD)result )
            {
              v41 = (unsigned int)result;
              v77 = "%s: dbglog_parser_type_init failed ret %d";
              goto LABEL_177;
            }
            goto LABEL_178;
          }
          result = dbglog_set_mod_log_lvl(*a1, a2[1]);
          if ( !(_DWORD)result )
            goto LABEL_178;
        }
        else
        {
          result = dbglog_module_log_enable(*a1, a2[1], (_DWORD)v41 == 4);
          if ( !(_DWORD)result )
            goto LABEL_178;
        }
        v41 = (unsigned int)result;
        v77 = "%s: dbglog_module_log_enable failed ret %d";
        goto LABEL_177;
      }
      switch ( (_DWORD)v41 )
      {
        case 1:
          result = dbglog_set_log_lvl(*a1, a2[1]);
          if ( (_DWORD)result )
          {
            v41 = (unsigned int)result;
            v77 = "%s: dbglog_set_log_lvl failed ret %d";
            goto LABEL_177;
          }
          goto LABEL_178;
        case 2:
          v94 = *a1;
          v95 = a2[1];
          v96 = 1;
          break;
        case 3:
          v94 = *a1;
          v95 = a2[1];
          v96 = 0;
          break;
        default:
          goto LABEL_129;
      }
      result = dbglog_vap_log_enable(v94, v95, v96);
      if ( (_DWORD)result )
      {
        v41 = (unsigned int)result;
        v77 = "%s: dbglog_vap_log_enable failed ret %d";
        goto LABEL_177;
      }
      goto LABEL_178;
    }
    if ( (int)v41 > 65537 )
    {
      if ( (int)v41 > 65539 )
      {
        if ( (_DWORD)v41 == 65540 )
        {
          result = wma_unified_fw_profiling_cmd(*a1, 65540, a2[1], a2[2]);
          if ( !(_DWORD)result )
            goto LABEL_178;
          v90 = (unsigned int)result;
          v91 = 65540;
        }
        else
        {
          if ( (_DWORD)v41 != 65541 )
            goto LABEL_129;
          result = wma_unified_fw_profiling_cmd(*a1, 65541, 0, 0);
          if ( !(_DWORD)result )
            goto LABEL_178;
          v90 = (unsigned int)result;
          v91 = 65541;
        }
      }
      else if ( (_DWORD)v41 == 65538 )
      {
        result = wma_unified_fw_profiling_cmd(*a1, 65538, a2[1], a2[2]);
        if ( !(_DWORD)result )
          goto LABEL_178;
        v90 = (unsigned int)result;
        v91 = 65538;
      }
      else
      {
        result = wma_unified_fw_profiling_cmd(*a1, 65539, 0, 0);
        if ( !(_DWORD)result )
          goto LABEL_178;
        v90 = (unsigned int)result;
        v91 = 65539;
      }
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Profile cmd failed for %d ret %d",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wma_process_cli_set_cmd",
                 v91,
                 v90);
      goto LABEL_178;
    }
    if ( (int)v41 > 16394 )
    {
      if ( (_DWORD)v41 != 16395 )
      {
        if ( (_DWORD)v41 == 65537 )
        {
          result = wma_unified_fw_profiling_cmd(*a1, 65537, a2[1], 0);
          if ( (_DWORD)result )
            result = qdf_trace_msg(
                       0x36u,
                       2u,
                       "%s: Profile cmd failed for %d ret %d",
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       "wma_process_cli_set_cmd",
                       65537,
                       (unsigned int)result);
          goto LABEL_178;
        }
        goto LABEL_129;
      }
      result = wmi_unified_green_ap_ps_send(*a1);
      if ( (_DWORD)result )
      {
        v41 = a2[1];
        v77 = "%s: Set GreenAP Failed val %d";
        goto LABEL_177;
      }
LABEL_178:
      v43 = 0;
      goto LABEL_179;
    }
    if ( (_DWORD)v41 == 8 )
    {
      result = dbglog_report_enable(*a1, a2[1] != 0);
      if ( (_DWORD)result )
      {
        v41 = (unsigned int)result;
        v77 = "%s: dbglog_report_enable failed ret %d";
        goto LABEL_177;
      }
      goto LABEL_178;
    }
    if ( (_DWORD)v41 == 9 )
    {
      result = dbglog_set_mod_wow_log_lvl(*a1, a2[1]);
      if ( (_DWORD)result )
      {
        v41 = (unsigned int)result;
        v77 = "%s: WMI_DBGLOG_MOD_WOW_LOG_LEVEL failed ret %d";
LABEL_177:
        result = qdf_trace_msg(0x36u, 2u, v77, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd", v41);
        goto LABEL_178;
      }
      goto LABEL_178;
    }
LABEL_129:
    v77 = "%s: Invalid param id 0x%x";
    goto LABEL_177;
  }
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: dbg pid %d pval %d",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "wma_process_cli_set_cmd");
  v41 = *a2;
  if ( (int)v41 <= 4 )
  {
    if ( (int)v41 > 1 )
    {
      if ( (_DWORD)v41 == 2 )
      {
        v100 = a2[1];
        v43 = (v100 << 31) | 4;
        *(_BYTE *)(v40 + 86) = v100 != 0;
      }
      else
      {
        v42 = a2[1];
        if ( (_DWORD)v41 == 3 )
        {
          v43 = (v42 << 31) | 8;
          *(_BYTE *)(v40 + 87) = v42 != 0;
        }
        else
        {
          v43 = (v42 << 31) | 0x10;
          *(_BYTE *)(v40 + 88) = v42 != 0;
        }
      }
      goto LABEL_179;
    }
    if ( !(_DWORD)v41 )
    {
      v99 = a2[1];
      v43 = (v99 << 31) | 1;
      *(_BYTE *)(v40 + 84) = v99 != 0;
      goto LABEL_179;
    }
    if ( (_DWORD)v41 == 1 )
    {
      v92 = a2[1];
      v43 = (v92 << 31) | 2;
      *(_BYTE *)(v40 + 85) = v92 != 0;
      goto LABEL_179;
    }
    goto LABEL_129;
  }
  if ( (int)v41 > 6 )
  {
    switch ( (_DWORD)v41 )
    {
      case 7:
        v101 = a2[1];
        v43 = (v101 << 31) | 0x80;
        *(_BYTE *)(v40 + 91) = v101 != 0;
        goto LABEL_179;
      case 8:
        v102 = a2[1];
        v43 = (v102 << 31) | 0x100;
        *(_BYTE *)(v40 + 92) = v102 != 0;
        goto LABEL_179;
      case 0xA:
        v89 = a2[1];
        v43 = (v89 << 31) | 0x200;
        *(_BYTE *)(v40 + 93) = v89 != 0;
        goto LABEL_179;
    }
    goto LABEL_129;
  }
  v93 = a2[1];
  if ( (_DWORD)v41 == 5 )
  {
    v43 = (v93 << 31) | 0x20;
    *(_BYTE *)(v40 + 89) = v93 != 0;
  }
  else
  {
    v43 = (v93 << 31) | 0x40;
    *(_BYTE *)(v40 + 90) = v93 != 0;
  }
LABEL_179:
  v105 = a2[4];
  if ( v105 == 2 )
  {
    v106 = *a2;
    if ( (int)*a2 > 36 )
    {
      if ( v106 <= 39 )
      {
        if ( v106 == 37 )
        {
          *((_DWORD *)a1 + 132) = a2[1];
        }
        else if ( v106 == 38 )
        {
          *((_DWORD *)a1 + 133) = a2[1];
        }
        else
        {
          *((_DWORD *)a1 + 134) = a2[1];
        }
        goto LABEL_14;
      }
      switch ( v106 )
      {
        case '(':
          *((_DWORD *)a1 + 135) = a2[1];
          goto LABEL_14;
        case ')':
          *((_DWORD *)a1 + 136) = a2[1];
          goto LABEL_14;
        case '<':
          *((_DWORD *)a1 + 138) = a2[1];
          goto LABEL_14;
      }
      goto LABEL_214;
    }
    if ( v106 > 2 )
    {
      switch ( v106 )
      {
        case 3:
          v107 = a2[1];
          *((_DWORD *)a1 + 141) = v107;
          v108 = context[1];
          if ( (*(_BYTE *)(v108 + 1032) & 1) == 0 )
          {
            v37 = "%s: Current band is not 2G";
            goto LABEL_12;
          }
          break;
        case 4:
          v107 = a2[1];
          *((_DWORD *)a1 + 142) = v107;
          v108 = context[1];
          if ( (*(_BYTE *)(v108 + 1032) & 2) == 0 )
          {
            v37 = "%s: Current band is not 5G";
            goto LABEL_12;
          }
          break;
        case 10:
          *((_DWORD *)a1 + 137) = a2[1];
          goto LABEL_14;
        default:
          goto LABEL_214;
      }
      *(_BYTE *)(v108 + 4626) = v107;
      goto LABEL_14;
    }
    if ( v106 == 1 )
    {
      *((_DWORD *)a1 + 139) = a2[1];
      goto LABEL_14;
    }
    if ( v106 == 2 )
    {
      *((_DWORD *)a1 + 140) = a2[1];
      goto LABEL_14;
    }
LABEL_214:
    v109 = "%s: Invalid wma_cli_set pdev command/Not yet implemented 0x%x";
LABEL_224:
    result = qdf_trace_msg(0x36u, 8u, v109, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd");
    goto LABEL_14;
  }
  if ( v105 != 1 )
  {
    if ( v105 != 5 )
      goto LABEL_14;
    if ( !(unsigned int)wma_vdev_set_param(*a1, a2[3], 0x2Eu, v43, v24, v25, v26, v27, v28, v29, v30, v31) )
    {
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: Sent packet power save cmd %d value %x to target",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wma_process_cli_set_cmd",
                 *a2,
                 v43);
      goto LABEL_14;
    }
    v37 = "%s: Failed to send wmi packet power save cmd";
    goto LABEL_12;
  }
  switch ( *a2 )
  {
    case 0x15u:
      *(_DWORD *)(v40 + 40) = a2[1];
      break;
    case 0x1Bu:
      *(_DWORD *)(v40 + 44) = a2[1];
      break;
    case 0x1Cu:
      *(_DWORD *)(v40 + 32) = a2[1];
      break;
    case 0x1Du:
      *(_DWORD *)(v40 + 20) = a2[1];
      break;
    case 0x1Eu:
      *(_DWORD *)(v40 + 24) = a2[1];
      break;
    case 0x1Fu:
      *(_DWORD *)(v40 + 28) = a2[1];
      break;
    case 0x22u:
      *(_DWORD *)(v40 + 16) = a2[1];
      break;
    case 0x2Cu:
      *(_DWORD *)(v40 + 36) = a2[1];
      break;
    case 0x32u:
      *(_DWORD *)(v40 + 56) = a2[1];
      break;
    case 0x33u:
      *(_DWORD *)(v40 + 60) = a2[1];
      break;
    case 0x34u:
      *(_DWORD *)(v40 + 64) = a2[1];
      break;
    case 0x35u:
      *(_DWORD *)(v40 + 68) = a2[1];
      break;
    case 0x36u:
      *(_DWORD *)(v40 + 72) = a2[1];
      break;
    case 0x37u:
      *(_DWORD *)(v40 + 76) = a2[1];
      break;
    case 0x3Eu:
      *(_DWORD *)(v40 + 80) = a2[1];
      break;
    case 0x6Au:
    case 0x6Bu:
      result = wma_set_he_vdev_param(v40, *a2, a2[1]);
      break;
    default:
      v109 = "%s: vdev cmd is not part vdev_cli_config 0x%x";
      goto LABEL_224;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
