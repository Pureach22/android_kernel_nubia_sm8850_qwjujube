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
  _QWORD *v44; // x25
  __int64 v45; // x24
  int v46; // w2
  unsigned int v47; // w8
  unsigned int v48; // w0
  int v49; // w3
  int v50; // w8
  unsigned int v51; // w24
  unsigned int v52; // w22
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x2
  const char *v70; // x2
  __int64 v71; // x5
  const char *v72; // x2
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w8
  unsigned int v82; // w8
  __int64 v83; // x5
  __int64 v84; // x4
  unsigned int v85; // w8
  unsigned int v86; // w8
  __int64 v87; // x0
  __int64 v88; // x1
  __int64 v89; // x2
  __int64 v90; // x4
  const char *v91; // x2
  unsigned int v92; // w8
  unsigned int v93; // w8
  unsigned int v94; // w8
  unsigned int v95; // w8
  unsigned int v96; // w8
  int v97; // w4
  unsigned int v98; // w8
  __int64 v99; // x9
  const char *v100; // x2
  __int64 v101; // [xsp+8h] [xbp-28h]

  _ReadStatusReg(SP_EL0);
  v12 = a2[3];
  v13 = a1[65];
  context = _cds_get_context(53, (__int64)"wma_process_cli_set_cmd", a3, a4, a5, a6, a7, a8, a9, a10);
  v23 = _cds_get_context(71, (__int64)"wma_process_cli_set_cmd", v15, v16, v17, v18, v19, v20, v21, v22);
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
        v51 = a2[1];
        v52 = HIBYTE(v51) & 3;
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
          BYTE1(v51),
          (unsigned __int8)v51,
          BYTE2(v51),
          v52,
          (v51 >> 26) & 3,
          v101,
          0,
          0);
        result = wma_set_mcc_channel_time_quota(
                   a1,
                   BYTE1(v51),
                   BYTE2(v51),
                   (unsigned __int8)v51,
                   v52,
                   (v51 >> 26) & 3,
                   v53,
                   v54,
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60);
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
        result = wma_vdev_set_param(*a1, a2[3], *a2, a2[1], v61, v62, v63, v64, v65, v66, v67, v68);
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
        v81 = *a2;
        if ( *a2 - 1 <= 1 )
        {
          if ( (unsigned int)wma_check_txrx_chainmask(
                               *(_DWORD *)(v33 + 688),
                               a2[1],
                               v73,
                               v74,
                               v75,
                               v76,
                               v77,
                               v78,
                               v79,
                               v80) )
          {
LABEL_69:
            v37 = "%s: Chainmask value is invalid";
            v38 = 8;
            goto LABEL_13;
          }
          v81 = *a2;
          if ( *a2 == 1 )
          {
            if ( (wma_is_tx_chainmask_valid(a2[1], v33) & 1) == 0 )
              goto LABEL_69;
            v81 = *a2;
          }
        }
        if ( v81 == 212 )
          wma_convert_ac_value();
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
            v47 = a2[1];
            if ( v46 == 1 )
            {
              v48 = cdp_aggr_cfg(v44, a2[3], v47);
              if ( v48 )
              {
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: cdp_aggr_cfg set ampdu failed ret %d",
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  "wma_process_cli_set_cmd",
                  v48);
                v47 = a2[1];
                v49 = 0;
              }
              else
              {
                v49 = 0;
                v47 = a2[1];
                *(_DWORD *)(v45 + 488LL * a2[3] + 48) = v47;
              }
            }
            else
            {
              v49 = 1;
            }
            result = wma_set_tx_rx_aggr_size(v12, v47, v47, v49, v24, v25, v26, v27, v28, v29, v30, v31);
            if ( !(_DWORD)result )
              goto LABEL_178;
            v90 = (unsigned int)result;
            v91 = "%s: set_aggr_size failed ret %d";
LABEL_125:
            result = qdf_trace_msg(
                       0x36u,
                       2u,
                       v91,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       "wma_process_cli_set_cmd",
                       v90);
            goto LABEL_14;
          }
          if ( v46 == 3 )
          {
            if ( (unsigned int)cds_get_conparam() != 5 )
            {
              result = wmi_crash_inject(*a1);
              goto LABEL_178;
            }
            v69 = "%s: Crash inject not allowed in FTM mode";
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
        v69 = "%s: Invalid vpdev command id";
LABEL_54:
        result = qdf_trace_msg(0x36u, 2u, v69, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd");
        goto LABEL_178;
    }
LABEL_124:
    v90 = (unsigned int)result;
    v91 = "%s: wma_vdev_set_param failed ret %d";
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
          v71 = a2[1];
          if ( !(_DWORD)result )
          {
            v43 = 0;
            *(_DWORD *)(v40 + 104) = v71;
            goto LABEL_179;
          }
          v72 = "%s: Set Q-PsPoll WakeIntv Failed vId %d val %d";
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
          v71 = a2[1];
          if ( !(_DWORD)result )
          {
            v43 = 0;
            *(_DWORD *)(v40 + 108) = v71;
            goto LABEL_179;
          }
          v72 = "%s: Set Q-SpecNoDataPsPoll Failed vId %d val %d";
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
        v71 = a2[1];
        if ( !(_DWORD)result )
        {
          v43 = 0;
          *(_DWORD *)(v40 + 96) = v71;
          goto LABEL_179;
        }
        v72 = "%s: Set Q-PsPollCnt Failed vdevId %d val %d";
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
        v71 = a2[1];
        if ( !(_DWORD)result )
        {
          v43 = 0;
          *(_DWORD *)(v40 + 100) = v71;
          goto LABEL_179;
        }
        v72 = "%s: Set Q-MaxTxBefWake Failed vId %d val %d";
      }
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 v72,
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
                 v71);
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
      v50 = *a2;
      v43 = 0;
      if ( (int)*a2 <= 3 )
      {
        if ( v50 > 1 )
        {
          if ( v50 == 2 )
          {
            *(_DWORD *)(v40 + 120) = a2[1];
          }
          else
          {
            if ( v50 != 3 )
              goto LABEL_179;
            *(_DWORD *)(v40 + 124) = a2[1];
          }
        }
        else
        {
          if ( !v50 )
          {
            *(_DWORD *)(v40 + 112) = a2[1];
            result = wmi_unified_vdev_set_gtx_cfg_send(*a1);
            goto LABEL_178;
          }
          if ( v50 != 1 )
            goto LABEL_179;
          *(_DWORD *)(v40 + 116) = a2[1];
        }
LABEL_146:
        result = wmi_unified_vdev_set_gtx_cfg_send(*a1);
        goto LABEL_178;
      }
      if ( v50 <= 5 )
      {
        if ( v50 == 4 )
        {
          *(_DWORD *)(v40 + 128) = a2[1];
        }
        else
        {
          if ( v50 != 5 )
            goto LABEL_179;
          *(_DWORD *)(v40 + 132) = a2[1];
        }
        goto LABEL_146;
      }
      if ( v50 == 6 )
      {
        *(_DWORD *)(v40 + 136) = a2[1];
        goto LABEL_146;
      }
      if ( v50 != 7 )
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
              v70 = "%s: dbglog_parser_type_init failed ret %d";
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
        v70 = "%s: dbglog_module_log_enable failed ret %d";
        goto LABEL_177;
      }
      switch ( (_DWORD)v41 )
      {
        case 1:
          result = dbglog_set_log_lvl(*a1, a2[1]);
          if ( (_DWORD)result )
          {
            v41 = (unsigned int)result;
            v70 = "%s: dbglog_set_log_lvl failed ret %d";
            goto LABEL_177;
          }
          goto LABEL_178;
        case 2:
          v87 = *a1;
          v88 = a2[1];
          v89 = 1;
          break;
        case 3:
          v87 = *a1;
          v88 = a2[1];
          v89 = 0;
          break;
        default:
          goto LABEL_129;
      }
      result = dbglog_vap_log_enable(v87, v88, v89);
      if ( (_DWORD)result )
      {
        v41 = (unsigned int)result;
        v70 = "%s: dbglog_vap_log_enable failed ret %d";
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
          v83 = (unsigned int)result;
          v84 = 65540;
        }
        else
        {
          if ( (_DWORD)v41 != 65541 )
            goto LABEL_129;
          result = wma_unified_fw_profiling_cmd(*a1, 65541, 0, 0);
          if ( !(_DWORD)result )
            goto LABEL_178;
          v83 = (unsigned int)result;
          v84 = 65541;
        }
      }
      else if ( (_DWORD)v41 == 65538 )
      {
        result = wma_unified_fw_profiling_cmd(*a1, 65538, a2[1], a2[2]);
        if ( !(_DWORD)result )
          goto LABEL_178;
        v83 = (unsigned int)result;
        v84 = 65538;
      }
      else
      {
        result = wma_unified_fw_profiling_cmd(*a1, 65539, 0, 0);
        if ( !(_DWORD)result )
          goto LABEL_178;
        v83 = (unsigned int)result;
        v84 = 65539;
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
                 v84,
                 v83);
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
        v70 = "%s: Set GreenAP Failed val %d";
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
        v70 = "%s: dbglog_report_enable failed ret %d";
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
        v70 = "%s: WMI_DBGLOG_MOD_WOW_LOG_LEVEL failed ret %d";
LABEL_177:
        result = qdf_trace_msg(0x36u, 2u, v70, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd", v41);
        goto LABEL_178;
      }
      goto LABEL_178;
    }
LABEL_129:
    v70 = "%s: Invalid param id 0x%x";
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
        v93 = a2[1];
        v43 = (v93 << 31) | 4;
        *(_BYTE *)(v40 + 86) = v93 != 0;
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
      v92 = a2[1];
      v43 = (v92 << 31) | 1;
      *(_BYTE *)(v40 + 84) = v92 != 0;
      goto LABEL_179;
    }
    if ( (_DWORD)v41 == 1 )
    {
      v85 = a2[1];
      v43 = (v85 << 31) | 2;
      *(_BYTE *)(v40 + 85) = v85 != 0;
      goto LABEL_179;
    }
    goto LABEL_129;
  }
  if ( (int)v41 > 6 )
  {
    switch ( (_DWORD)v41 )
    {
      case 7:
        v94 = a2[1];
        v43 = (v94 << 31) | 0x80;
        *(_BYTE *)(v40 + 91) = v94 != 0;
        goto LABEL_179;
      case 8:
        v95 = a2[1];
        v43 = (v95 << 31) | 0x100;
        *(_BYTE *)(v40 + 92) = v95 != 0;
        goto LABEL_179;
      case 0xA:
        v82 = a2[1];
        v43 = (v82 << 31) | 0x200;
        *(_BYTE *)(v40 + 93) = v82 != 0;
        goto LABEL_179;
    }
    goto LABEL_129;
  }
  v86 = a2[1];
  if ( (_DWORD)v41 == 5 )
  {
    v43 = (v86 << 31) | 0x20;
    *(_BYTE *)(v40 + 89) = v86 != 0;
  }
  else
  {
    v43 = (v86 << 31) | 0x40;
    *(_BYTE *)(v40 + 90) = v86 != 0;
  }
LABEL_179:
  v96 = a2[4];
  if ( v96 == 2 )
  {
    v97 = *a2;
    if ( (int)*a2 > 36 )
    {
      if ( v97 <= 39 )
      {
        if ( v97 == 37 )
        {
          *((_DWORD *)a1 + 132) = a2[1];
        }
        else if ( v97 == 38 )
        {
          *((_DWORD *)a1 + 133) = a2[1];
        }
        else
        {
          *((_DWORD *)a1 + 134) = a2[1];
        }
        goto LABEL_14;
      }
      switch ( v97 )
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
    if ( v97 > 2 )
    {
      switch ( v97 )
      {
        case 3:
          v98 = a2[1];
          *((_DWORD *)a1 + 141) = v98;
          v99 = context[1];
          if ( (*(_BYTE *)(v99 + 1032) & 1) == 0 )
          {
            v37 = "%s: Current band is not 2G";
            goto LABEL_12;
          }
          break;
        case 4:
          v98 = a2[1];
          *((_DWORD *)a1 + 142) = v98;
          v99 = context[1];
          if ( (*(_BYTE *)(v99 + 1032) & 2) == 0 )
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
      *(_BYTE *)(v99 + 4410) = v98;
      goto LABEL_14;
    }
    if ( v97 == 1 )
    {
      *((_DWORD *)a1 + 139) = a2[1];
      goto LABEL_14;
    }
    if ( v97 == 2 )
    {
      *((_DWORD *)a1 + 140) = a2[1];
      goto LABEL_14;
    }
LABEL_214:
    v100 = "%s: Invalid wma_cli_set pdev command/Not yet implemented 0x%x";
LABEL_224:
    result = qdf_trace_msg(0x36u, 8u, v100, v24, v25, v26, v27, v28, v29, v30, v31, "wma_process_cli_set_cmd");
    goto LABEL_14;
  }
  if ( v96 != 1 )
  {
    if ( v96 != 5 )
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
      v100 = "%s: vdev cmd is not part vdev_cli_config 0x%x";
      goto LABEL_224;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
