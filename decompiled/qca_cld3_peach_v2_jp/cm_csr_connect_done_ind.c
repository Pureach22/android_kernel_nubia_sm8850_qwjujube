__int64 __fastcall cm_csr_connect_done_ind(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w19
  _QWORD *context; // x0
  __int64 v14; // x21
  __int64 psoc_ext_obj_fl; // x0
  __int64 result; // x0
  unsigned __int8 *v17; // x22
  unsigned int v18; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int user_mcc_duty_cycle_percentage; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w24
  __int64 v63; // x0
  __int64 mcc_duty_cycle_percentage; // x2
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int param; // w0
  unsigned int v74; // w24
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x8
  __int64 v84; // x4
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _BYTE v93[4]; // [xsp+Ch] [xbp-144h] BYREF
  __int64 v94; // [xsp+10h] [xbp-140h] BYREF
  unsigned __int64 v95; // [xsp+18h] [xbp-138h]
  int v96; // [xsp+20h] [xbp-130h]
  _DWORD s[72]; // [xsp+28h] [xbp-128h] BYREF
  __int64 v98; // [xsp+148h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a1 + 104);
  v96 = 0;
  v94 = 0;
  v95 = 0;
  v93[0] = 0;
  context = _cds_get_context(52, (__int64)"cm_csr_connect_done_ind", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v14 = (__int64)context;
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(context[2694]);
    if ( psoc_ext_obj_fl )
    {
      if ( *(_DWORD *)(a2 + 52) )
      {
        ((void (__fastcall *)(_QWORD))cm_csr_set_idle)(v12);
        sme_qos_update_hand_off(v12, 0);
        sme_qos_csr_event_ind(v14, v12, 6, 0);
LABEL_44:
        result = 0;
        goto LABEL_45;
      }
      v17 = (unsigned __int8 *)psoc_ext_obj_fl;
      v18 = policy_mgr_mode_specific_connection_count(*(_QWORD *)(v14 + 21552), 0, nullptr);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Current iface vdev_id:%d, Primary vdev_id:%d, Dual sta policy:%d, count:%d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "cm_csr_connect_done_ind",
        v12,
        v17[1105],
        v17[1104],
        v18);
      v27 = v17[1104];
      if ( v17[1105] != 255 && v18 == 2 && !v17[1104] )
      {
        if ( (policy_mgr_current_concurrency_is_mcc(*(_QWORD *)(v14 + 21552)) & 1) != 0 )
        {
          policy_mgr_get_mcc_adaptive_sch(*(_QWORD *)(v14 + 21552), v93);
          if ( v93[0] == 1 )
          {
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Disable mcc_adaptive_scheduler",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "cm_csr_connect_done_ind");
            policy_mgr_set_dynamic_mcc_adaptive_sch(*(_QWORD *)(v14 + 21552), 0);
            if ( (unsigned int)sme_set_mas(0) )
            {
              v44 = "%s: Failed to disable mcc_adaptive_sched";
LABEL_20:
              qdf_trace_msg(0x34u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "cm_csr_connect_done_ind");
              result = 4294967285LL;
              goto LABEL_45;
            }
          }
          mcc_duty_cycle_percentage = (unsigned int)wlan_mlme_get_mcc_duty_cycle_percentage(*(_QWORD *)(v14 + 21560));
          v63 = v12;
          goto LABEL_27;
        }
        v27 = v17[1104];
      }
      if ( v18 == 2 && v27 == 1 && (policy_mgr_current_concurrency_is_mcc(*(_QWORD *)(v14 + 21552)) & 1) != 0 )
      {
        policy_mgr_get_mcc_adaptive_sch(*(_QWORD *)(v14 + 21552), v93);
        if ( v93[0] == 1 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Enable mcc_adaptive_scheduler",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "cm_csr_connect_done_ind");
          policy_mgr_set_dynamic_mcc_adaptive_sch(*(_QWORD *)(v14 + 21552), 1);
          if ( (unsigned int)sme_set_mas(1) )
          {
            v44 = "%s: Failed to enable mcc_adaptive_sched";
            goto LABEL_20;
          }
        }
LABEL_28:
        if ( (*(_BYTE *)(a2 + 1) & 1) == 0 && wlan_vdev_is_open_mode(a1) )
        {
          WORD1(v94) = 20;
          v95 = 0xFFFFFFFF00000000LL;
          BYTE4(v94) = v12;
          LOWORD(v96) = -1;
          csr_roam_chk_lnk_set_ctx_rsp(v14, (__int64)&v94, v65, v66, v67, v68, v69, v70, v71, v72);
        }
        param = wlan_crypto_get_param(a1, 5u);
        if ( (param & 0x80000000) == 0 )
        {
          v74 = param;
          if ( (param & 0x4000) != 0 )
          {
            memset(s, 0, sizeof(s));
            v83 = *(_QWORD *)(a2 + 80);
            v84 = *(unsigned int *)(a2 + 72);
            if ( v83 && (unsigned int)v84 > 0x23 )
            {
              if ( !(unsigned int)wlan_get_crypto_params_from_rsn_ie(s, v83 + 36, (unsigned __int16)v84 - 36, nullptr)
                && (s[38] & 0x4000) == 0 )
              {
                v74 &= 0x7FFFBFFFu;
              }
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: invalid beacon probe rsp len %d",
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                "cm_update_rsn_ocv_cap",
                v84);
            }
          }
          if ( (unsigned int)wma_cli_set2_command(v12, 160, v74, 0, 1) )
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Failed to update wmi_vdev_param_rsn_capability for vdev id %d",
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              "cm_csr_connect_done_ind",
              v12);
        }
        if ( v17[2604] == 1 )
          sme_set_vdev_ies_per_band(v14, v12, *(_DWORD *)(a1 + 16));
        goto LABEL_44;
      }
      user_mcc_duty_cycle_percentage = wlan_mlme_get_user_mcc_duty_cycle_percentage(*(_QWORD *)(v14 + 21552));
      if ( !user_mcc_duty_cycle_percentage )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: no applicable user mcc/quota",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "cm_csr_connect_done_ind");
        goto LABEL_28;
      }
      v62 = user_mcc_duty_cycle_percentage;
      if ( v93[0] == 1 )
      {
        policy_mgr_set_dynamic_mcc_adaptive_sch(*(_QWORD *)(v14 + 21552), 0);
        if ( (unsigned int)sme_set_mas(0) )
          goto LABEL_28;
      }
      v63 = *(unsigned __int8 *)(a1 + 104);
      mcc_duty_cycle_percentage = v62;
LABEL_27:
      sme_cli_set_command(v63, 122887, mcc_duty_cycle_percentage, 1);
      goto LABEL_28;
    }
  }
  result = 4;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
