__int64 __fastcall wlan_hdd_pld_probe(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v14; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  _QWORD *context; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x21
  char is_ready; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int inited; // w20
  __int64 *v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 *v94; // x21
  unsigned int v95; // w0
  unsigned int vdevs; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  _QWORD v113[2]; // [xsp+0h] [xbp-10h] BYREF

  v113[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 8 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid bus type %d->%d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_pld_probe",
      a2,
      0xFFFFFFFFLL);
    result = 4294967274LL;
    goto LABEL_10;
  }
  v14 = dword_A301F0[a2];
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "hang_event_data",
    &g_fw_host_hang_event,
    390);
  v113[0] = 0;
  qdf_trace_msg(0x33u, 4u, "%s: probing driver", v16, v17, v18, v19, v20, v21, v22, v23, "hdd_soc_probe");
  result = _osif_psoc_sync_create_and_trans(v113, "hdd_soc_probe");
  if ( !(_DWORD)result )
  {
    osif_psoc_sync_register(a1, v113[0]);
    qdf_trace_msg(0x33u, 4u, "%s: probing driver", v25, v26, v27, v28, v29, v30, v31, v32, "__hdd_soc_probe");
    hdd_prevent_suspend(0);
    v33 = pld_request_pm_qos(a1, 1);
    cds_set_driver_state(2, v33, v34, v35, v36, v37, v38, v39, v40);
    cds_clear_driver_state(16, v41, v42, v43, v44, v45, v46, v47, v48);
    cds_clear_driver_state(8, v49, v50, v51, v52, v53, v54, v55, v56);
    context = _cds_get_context(64, (__int64)"hdd_init_qdf_ctx", v57, v58, v59, v60, v61, v62, v63, v64);
    if ( context )
    {
      context[5] = a1;
      v74 = (__int64)context;
      context[1] = a3;
      *((_DWORD *)context + 148) = v14;
      context[75] = a4;
      is_ready = ucfg_ipa_is_ready();
      if ( (unsigned int)cds_smmu_mem_map_setup(v74, is_ready & 1) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cds_smmu_mem_map_setup() failed",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "hdd_init_qdf_ctx");
      inited = hif_init_dma_mask(a1, v14);
      if ( !inited )
      {
        v85 = (__int64 *)hdd_context_create(a1);
        v94 = v85;
        if ( (unsigned __int64)v85 < 0xFFFFFFFFFFFFF001LL )
        {
          v95 = ucfg_dp_prealloc_init(*v85);
          if ( v95 )
          {
            inited = qdf_status_to_os_return(v95);
          }
          else
          {
            inited = hdd_wlan_startup(v94);
            if ( !inited )
            {
              vdevs = hdd_psoc_create_vdevs(v94);
              if ( !vdevs )
              {
                probe_fail_cnt = 0;
                cds_set_driver_state(1, v97, v98, v99, v100, v101, v102, v103, v104);
                cds_clear_driver_state(2, v105, v106, v107, v108, v109, v110, v111, v112);
                hdd_thermal_mitigation_register(v94, a1);
                hdd_ddr_bw_mitigation_register(v94, a1);
                hdd_set_sar_init_index(v94);
                inited = 0;
LABEL_21:
                pld_remove_pm_qos(a1);
                hdd_allow_suspend(0);
                if ( inited )
                {
                  hdd_start_complete(inited);
                  osif_psoc_sync_unregister(a1);
                  osif_psoc_sync_wait_for_ops(v113[0]);
                  osif_psoc_sync_trans_stop(v113[0]);
                  osif_psoc_sync_destroy(v113[0]);
                  result = inited;
                }
                else
                {
                  osif_psoc_sync_trans_stop(v113[0]);
                  hdd_start_complete(0);
                  result = 0;
                }
                goto LABEL_10;
              }
              inited = qdf_status_to_os_return(vdevs);
              hdd_wlan_exit(v94);
            }
            ucfg_dp_prealloc_deinit();
          }
          hdd_context_destroy(v94);
        }
        else
        {
          inited = (unsigned int)v85;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: consecutive probe failures:%u",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "__hdd_soc_probe",
          (unsigned __int8)++probe_fail_cnt);
      }
    }
    else
    {
      inited = -22;
    }
    cds_clear_driver_state(2, v66, v67, v68, v69, v70, v71, v72, v73);
    goto LABEL_21;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
