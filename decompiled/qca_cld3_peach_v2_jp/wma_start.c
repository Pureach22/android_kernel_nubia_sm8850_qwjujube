__int64 __fastcall wma_start(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  _QWORD **v26; // x19
  __int64 v27; // x8
  _QWORD *v28; // x20
  unsigned int v29; // w21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x2
  unsigned int v74; // w0
  _QWORD *v75; // x0
  _QWORD v76[14]; // [xsp+0h] [xbp-70h] BYREF

  v76[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "wma_start");
  context = _cds_get_context(54, (__int64)"wma_start", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( context )
  {
    v25 = context[3];
    v26 = (_QWORD **)context;
    if ( v25 && (v27 = *(_QWORD *)(v25 + 2800)) != 0 )
      v28 = *(_QWORD **)(v27 + 16);
    else
      v28 = nullptr;
    if ( !(unsigned int)_wmi_validate_handle((__int64)v28, (__int64)"wma_start", v17, v18, v19, v20, v21, v22, v23, v24)
      && _cds_get_context(53, (__int64)"wma_start", v17, v18, v19, v20, v21, v22, v23, v24) )
    {
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v28,
                           0x1Eu,
                           (__int64)wma_wow_wakeup_host_event,
                           1u,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24) )
      {
        v39 = "%s: Failed to register wow wakeup host event handler";
LABEL_18:
        qdf_trace_msg(0x36u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "wma_start");
        v29 = 16;
        goto LABEL_8;
      }
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v28,
                           0x53u,
                           (__int64)wma_pdev_resume_event_handler,
                           1u,
                           v31,
                           v32,
                           v33,
                           v34,
                           v35,
                           v36,
                           v37,
                           v38) )
      {
        v39 = "%s: Failed to register PDEV resume event handler";
        goto LABEL_18;
      }
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: MCC TX Pause Event Handler register",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wma_start");
      wmi_unified_register_event_handler(
        v28,
        0x3Bu,
        (__int64)wma_mcc_vdev_tx_pause_evt_handler,
        1u,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Registering SAR2 response handler",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wma_start");
      if ( (unsigned int)wmi_unified_register_event_handler(
                           *v26,
                           0xCBu,
                           (__int64)wma_sar_rsp_evt_handler,
                           2u,
                           v56,
                           v57,
                           v58,
                           v59,
                           v60,
                           v61,
                           v62,
                           v63) )
      {
        v39 = "%s: Failed to register sar response event cb";
        goto LABEL_18;
      }
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v28,
                           0x63u,
                           (__int64)&wma_thermal_mgmt_evt_handler,
                           2u,
                           v31,
                           v32,
                           v33,
                           v34,
                           v35,
                           v36,
                           v37,
                           v38) )
      {
        v39 = "%s: Failed to register thermal mitigation event cb";
        goto LABEL_18;
      }
      if ( (unsigned int)cds_get_conparam() == 5 )
      {
LABEL_20:
        v29 = 0;
        goto LABEL_8;
      }
      v64 = wma_tx_attach((__int64)v26, v17, v18, v19, v20, v21, v22, v23, v24);
      if ( v64 )
      {
        v29 = v64;
        v73 = "%s: Failed to register tx management";
      }
      else
      {
        v74 = qdf_mc_timer_init((__int64)(v26 + 343), 0, (__int64)wma_log_completion_timeout, (__int64)v26);
        if ( !v74 )
        {
          if ( (unsigned int)wma_fips_register_event_handlers(v26) )
          {
            v39 = "%s: Failed to register FIPS event handler";
            goto LABEL_18;
          }
          if ( (unsigned int)wma_sar_register_event_handlers(v26) )
          {
            v39 = "%s: Failed to register SAR event handlers";
            goto LABEL_18;
          }
          if ( (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0x35u,
                               (__int64)wma_pdev_temperature_evt_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38) )
          {
            v39 = "%s: Failed to register get_temperature event cb";
            goto LABEL_18;
          }
          if ( (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0x41u,
                               (__int64)wma_vdev_tsf_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38) )
          {
            v39 = "%s: Failed to register tsf callback";
            goto LABEL_18;
          }
          if ( (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0xB1u,
                               (__int64)&wma_pdev_set_hw_mode_resp_evt_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38) )
          {
            v39 = "%s: Failed to register set hw mode resp event cb";
            goto LABEL_18;
          }
          if ( (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0xB2u,
                               (__int64)wma_pdev_hw_mode_transition_evt_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38)
            || (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0xB3u,
                               (__int64)wma_pdev_set_dual_mode_config_resp_evt_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38) )
          {
            v39 = "%s: Failed to register hw mode transition event cb";
            goto LABEL_18;
          }
          if ( (unsigned int)wmi_unified_register_event_handler(
                               v28,
                               0xB4u,
                               (__int64)wma_wlan_bt_activity_evt_handler,
                               2u,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38) )
          {
            v39 = "%s: Failed to register coex bt activity event handler";
            goto LABEL_18;
          }
          v75 = v26[3];
          v76[0] = wmi_unified_vdev_spectral_configure_cmd_send;
          v76[1] = wmi_unified_vdev_spectral_enable_cmd_send;
          memset(&v76[2], 0, 88);
          wlan_register_spectral_wmi_ops(v75, v76);
          goto LABEL_20;
        }
        v29 = v74;
        v73 = "%s: Failed to initialize log completion timeout";
      }
      qdf_trace_msg(0x36u, 2u, v73, v65, v66, v67, v68, v69, v70, v71, v72, "wma_start");
      goto LABEL_8;
    }
  }
  v29 = 4;
LABEL_8:
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v17, v18, v19, v20, v21, v22, v23, v24, "wma_start");
  _ReadStatusReg(SP_EL0);
  return v29;
}
