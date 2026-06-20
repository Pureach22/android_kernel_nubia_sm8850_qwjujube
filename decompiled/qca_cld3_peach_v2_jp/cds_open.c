__int64 __fastcall cds_open(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x2
  __int64 v19; // x3
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 *v28; // x8
  __int64 v29; // x21
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w19
  __int64 result; // x0
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w20
  const void *v51; // x22
  unsigned __int16 *v52; // x20
  __int64 context; // x24
  __int64 v54; // x9
  int v55; // w8
  __int64 v56; // x23
  int conparam; // w0
  _QWORD *v58; // x0
  unsigned int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  _QWORD *updated; // x0
  const char *v69; // x2
  unsigned int v70; // w1
  __int64 is_fw_down; // x0
  unsigned int v72; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // w9
  __int64 v90; // x10
  __int64 v91; // x8
  __int64 v92; // x1
  unsigned int v93; // w0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  unsigned int v103; // w0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // [xsp+18h] [xbp-58h] BYREF
  __int64 (__fastcall **v125)(); // [xsp+20h] [xbp-50h] BYREF
  __int64 v126; // [xsp+28h] [xbp-48h]
  __int64 v127; // [xsp+30h] [xbp-40h]
  __int64 v128; // [xsp+38h] [xbp-38h] BYREF
  __int64 (__fastcall *v129)(); // [xsp+40h] [xbp-30h]
  __int64 (__fastcall *v130)(); // [xsp+48h] [xbp-28h]
  __int64 (__fastcall *v131)(); // [xsp+50h] [xbp-20h]
  __int64 v132; // [xsp+58h] [xbp-18h]
  __int64 v133; // [xsp+60h] [xbp-10h]
  __int64 v134; // [xsp+68h] [xbp-8h]

  v134 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v132 = 0;
  v133 = 0;
  v130 = nullptr;
  v131 = nullptr;
  v128 = 0;
  v129 = nullptr;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = nullptr;
  qdf_trace_msg(0x38u, 8u, "%s: Opening CDS", a2, a3, a4, a5, a6, a7, a8, a9, "cds_open");
  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__cds_get_context",
      "cds_open");
LABEL_13:
    result = 16;
    goto LABEL_14;
  }
  qdf_timer_module_init();
  v28 = (__int64 *)gp_cds_context;
  if ( gp_cds_context
    || (printk(&unk_94D98D, "cds_get_global_context", v18, v19), (v28 = (__int64 *)gp_cds_context) != nullptr) )
  {
    *(__int64 *)((char *)v28 + 113) = 0;
    *(__int64 *)((char *)v28 + 108) = 0;
    v29 = *v28;
    if ( !*v28 )
    {
LABEL_12:
      qdf_trace_msg(0x38u, 2u, "%s: Hdd Context is Null", v20, v21, v22, v23, v24, v25, v26, v27, "cds_open");
      goto LABEL_13;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context is Invalid",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "cds_init_log_completion");
    v29 = *(_QWORD *)gp_cds_context;
    if ( !*(_QWORD *)gp_cds_context )
      goto LABEL_12;
  }
  if ( !*(_QWORD *)(v29 + 104) )
    goto LABEL_12;
  v30 = dispatcher_enable();
  if ( !v30 )
  {
    v41 = cds_sched_open(gp_cds_context, gp_cds_context, 0);
    if ( v41 )
    {
      v50 = v41;
      qdf_trace_msg(0x38u, 1u, "%s: Failed to open CDS Scheduler", v42, v43, v44, v45, v46, v47, v48, v49, "cds_open");
LABEL_49:
      dispatcher_disable();
      result = v50;
      goto LABEL_14;
    }
    if ( gp_cds_context )
    {
      v51 = *(const void **)(gp_cds_context + 32);
      if ( v51 )
      {
        v52 = *(unsigned __int16 **)(gp_cds_context + 152);
        if ( v52 )
        {
          context = _cds_get_context(66, "cds_open");
          hdd_wlan_update_target_info(v29, v51);
          v54 = *(_QWORD *)(v29 + 104);
          v128 = context;
          v129 = ol_target_failure;
          v130 = ucfg_pmo_psoc_target_suspend_acknowledge;
          v131 = ucfg_pmo_psoc_handle_initial_wake_up;
          v55 = *(_DWORD *)(v54 + 136);
          v132 = a1;
          LODWORD(v133) = v55;
          v56 = _cds_get_context(64, "cds_open");
          conparam = hdd_get_conparam();
          v58 = htc_create(v51, &v128, v56, conparam);
          *(_QWORD *)(gp_cds_context + 40) = v58;
          if ( v58 )
          {
            ucfg_pmo_psoc_update_htc_handle(a1, v58);
            *((_BYTE *)v52 + 145) = *(_BYTE *)(*(_QWORD *)(v29 + 104) + 192LL);
            v59 = wma_open(a1, hdd_update_tgt_cfg, v52, *(unsigned int *)(v29 + 528));
            if ( v59 )
            {
              v50 = v59;
              qdf_trace_msg(
                0x38u,
                1u,
                "%s: Failed to open WMA module",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "cds_open");
              goto LABEL_46;
            }
            if ( !*((_DWORD *)v52 + 2) )
              wlan_mlme_set_sap_max_peers(a1, *v52);
            is_fw_down = _cds_get_context(62, "cds_open");
            *(_QWORD *)(gp_cds_context + 72) = 0;
            if ( is_fw_down )
            {
              v72 = htc_wait_target((_QWORD *)is_fw_down);
              if ( v72 )
              {
                v50 = v72;
                is_fw_down = qdf_trace_msg(
                               0x38u,
                               1u,
                               "%s: Failed to complete BMI phase. status: %d",
                               v73,
                               v74,
                               v75,
                               v76,
                               v77,
                               v78,
                               v79,
                               v80,
                               "cds_open",
                               v72);
                if ( v50 != 2 )
                  is_fw_down = cds_is_fw_down(v81, v82, v83, v84, v85, v86, v87, v88);
                goto LABEL_45;
              }
              qdf_trace_msg(
                0x38u,
                8u,
                "%s: target_type %d 8074:%d 6290:%d 6390: %d 6490: %d 6750: %d",
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "cds_open",
                *(unsigned int *)(v29 + 528),
                20,
                21,
                23,
                27,
                28);
              v89 = *(_DWORD *)(v29 + 528);
              v90 = v132;
              *(_BYTE *)(v29 + 7088) = 0;
              LODWORD(v127) = v89;
              v125 = &dp_ol_if_ops;
              v126 = v90;
              is_fw_down = (__int64)ucfg_dp_txrx_soc_attach((__int64 *)&v125, (_BYTE *)(v29 + 7088));
              v91 = gp_cds_context;
              *(_QWORD *)(gp_cds_context + 64) = is_fw_down;
              if ( is_fw_down )
              {
                v92 = is_fw_down;
                if ( a1 )
                {
                  *(_QWORD *)(a1 + 2808) = is_fw_down;
                  v92 = *(_QWORD *)(v91 + 64);
                }
                ucfg_dp_set_cmn_dp_handle(a1, v92);
                ucfg_dp_update_num_rx_rings();
                ucfg_pmo_psoc_update_dp_handle(a1, *(_QWORD *)(gp_cds_context + 64));
                ucfg_dp_recover_mon_conf_flags();
                cds_set_ac_specs_params(v52);
                cds_cfg_update_ac_specs_params(*(_QWORD *)(gp_cds_context + 72), v52);
                cds_cdp_cfg_attach(a1);
                v93 = mac_open(a1, &v124, *(_QWORD *)gp_cds_context, v52);
                if ( v93 )
                {
                  v50 = v93;
                  qdf_trace_msg(
                    0x38u,
                    1u,
                    "%s: Failed to open MAC",
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    "cds_open");
                  v102 = gp_cds_context;
                }
                else
                {
                  *(_QWORD *)(gp_cds_context + 8) = v124;
                  v103 = sme_open();
                  if ( v103 )
                  {
                    v50 = v103;
                    qdf_trace_msg(
                      0x38u,
                      1u,
                      "%s: Failed to open SME",
                      v104,
                      v105,
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      v111,
                      "cds_open");
                  }
                  else
                  {
                    cds_register_all_modules();
                    v112 = dispatcher_psoc_open(a1);
                    if ( !v112 )
                    {
                      ucfg_mc_cp_stats_register_pmo_handler();
                      qdf_hang_event_register_notifier(&cds_hang_event_notifier);
                      result = 0;
                      goto LABEL_14;
                    }
                    v50 = v112;
                    v121 = qdf_trace_msg(
                             0x38u,
                             1u,
                             "%s: Failed to open PSOC Components",
                             v113,
                             v114,
                             v115,
                             v116,
                             v117,
                             v118,
                             v119,
                             v120,
                             "cds_open");
                    cds_deregister_all_modules(v121);
                    sme_close(v124);
                  }
                  mac_close(v124);
                  v102 = gp_cds_context;
                  *(_QWORD *)(gp_cds_context + 8) = 0;
                }
                ucfg_dp_txrx_soc_detach(*(__int64 ***)(v102 + 64));
                *(_QWORD *)(gp_cds_context + 64) = 0;
                is_fw_down = ucfg_pmo_psoc_update_dp_handle(a1, 0);
                if ( a1 )
                  *(_QWORD *)(a1 + 2808) = 0;
                goto LABEL_45;
              }
            }
            v50 = 16;
LABEL_45:
            v122 = cds_shutdown_notifier_purge(is_fw_down);
            v123 = wma_close(v122);
            wma_wmi_service_close(v123);
LABEL_46:
            updated = *(_QWORD **)(gp_cds_context + 40);
            if ( updated )
            {
              htc_destroy(updated);
              *(_QWORD *)(gp_cds_context + 40) = 0;
              updated = (_QWORD *)ucfg_pmo_psoc_update_htc_handle(a1, 0);
            }
            goto LABEL_48;
          }
          v69 = "%s: Failed to Create HTC";
          v70 = 1;
        }
        else
        {
          v69 = "%s: Cds config is NULL";
          v70 = 2;
        }
        updated = (_QWORD *)qdf_trace_msg(0x38u, v70, v69, v42, v43, v44, v45, v46, v47, v48, v49, "cds_open");
        v50 = 16;
      }
      else
      {
        updated = (_QWORD *)qdf_trace_msg(
                              0x38u,
                              2u,
                              "%s: Module ID %d context is Null (via %s)",
                              v42,
                              v43,
                              v44,
                              v45,
                              v46,
                              v47,
                              v48,
                              v49,
                              "__cds_get_context",
                              61,
                              "cds_open");
        v50 = 16;
      }
    }
    else
    {
      updated = (_QWORD *)qdf_trace_msg(
                            0x38u,
                            2u,
                            "%s: cds context pointer is null (via %s)",
                            v42,
                            v43,
                            v44,
                            v45,
                            v46,
                            v47,
                            v48,
                            v49,
                            "__cds_get_context",
                            "cds_open");
      v50 = 16;
    }
LABEL_48:
    cds_sched_close(updated);
    goto LABEL_49;
  }
  v39 = v30;
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: Failed to enable dispatcher; status:%d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "cds_open",
    v30);
  result = v39;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
