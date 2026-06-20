__int64 __fastcall wlan_hdd_get_channel_for_sap_restart(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *link_info_from_vdev; // x0
  __int64 v15; // x22
  __int64 *v16; // x25
  const char *v17; // x2
  unsigned int *v18; // x19
  __int64 *v19; // x24
  unsigned int v20; // w1
  __int64 result; // x0
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w2
  int chan_band_restrict; // w0
  unsigned __int8 v33; // w1
  bool v34; // zf
  __int64 v35; // x0
  __int64 *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double csa_chanwidth_from_phymode; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w9
  __int64 *v54; // x8
  long double v55; // q0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x7
  char v64; // w0
  unsigned int restarted; // w20
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w9
  __int64 v75; // x1
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x20
  unsigned __int8 v85; // w22
  __int64 *v86; // x21
  char v87[4]; // [xsp+10h] [xbp-30h] BYREF
  int v88; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v89; // [xsp+18h] [xbp-28h] BYREF
  __int64 v90; // [xsp+20h] [xbp-20h] BYREF
  __int64 v91; // [xsp+28h] [xbp-18h]
  char v92[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v93; // [xsp+38h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v92[0] = 0;
  v90 = 0;
  v91 = 0;
  v89 = 0;
  v88 = 5;
  v87[0] = 0;
  if ( !a3 )
  {
    v17 = "%s: Null parameters";
    goto LABEL_15;
  }
  link_info_from_vdev = (__int64 *)wlan_hdd_get_link_info_from_vdev();
  if ( !link_info_from_vdev )
  {
    v17 = "%s: Invalid vdev";
    goto LABEL_15;
  }
  v15 = *link_info_from_vdev;
  v16 = *(__int64 **)(*link_info_from_vdev + 24);
  if ( !v16 )
  {
    v17 = "%s: hdd_ctx is NULL";
    goto LABEL_15;
  }
  if ( (*(_QWORD *)(*(_QWORD *)(v15 + 52824) + 4416LL) & 2) != 0 )
  {
    if ( !v16[2] )
    {
      v17 = "%s: mac_handle is NULL";
      goto LABEL_15;
    }
    v18 = (unsigned int *)link_info_from_vdev[34];
    if ( !v18 )
    {
      v17 = "%s: sap_context is null";
      goto LABEL_15;
    }
    v19 = link_info_from_vdev;
    if ( (unsigned int)wlansap_context_get(link_info_from_vdev[34]) )
    {
      v17 = "%s: sap_context is invalid";
      goto LABEL_15;
    }
    policy_mgr_get_original_bw_for_sap_restart(a1, v87);
    if ( v87[0] == 1 )
      v22 = *((unsigned __int16 *)v18 + 749);
    else
      v22 = 9;
    LODWORD(v90) = v22;
    if ( policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) )
    {
      if ( (_policy_mgr_is_ll_lt_sap_restart_required(a1, "wlan_hdd_get_channel_for_sap_restart") & 1) != 0 )
      {
        v18[183] = 16;
        v31 = *a3;
LABEL_43:
        restarted = hdd_sap_restart_chan_switch_cb(a1, a2, v31, v90, 0);
        wlansap_context_put(v18);
        result = restarted;
        goto LABEL_18;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d freq %d, LL LT SAP dont need Channel change",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_hdd_get_channel_for_sap_restart",
        (unsigned __int8)a2,
        *v18);
LABEL_30:
      wlansap_context_put(v18);
      goto LABEL_17;
    }
    chan_band_restrict = wlansap_get_chan_band_restrict(v18, &v88);
    LODWORD(v89) = chan_band_restrict;
    if ( chan_band_restrict )
    {
      v33 = a2;
      v34 = chan_band_restrict == *v18;
      v35 = a1;
      v36 = v19;
      if ( !v34 )
        goto LABEL_37;
    }
    else
    {
      v33 = a2;
      v35 = a1;
      v36 = v19;
      if ( (v88 & 0xFFFFFFFD) == 9 )
      {
        queue_work_on(32, system_wq, v19 + 562);
        wlansap_context_put(v18);
        v17 = "%s: Stop SAP as no valid channel found";
        goto LABEL_15;
      }
    }
    if ( (policy_mgr_is_sap_restart_required_after_sta_disconnect(
            v35,
            v33,
            (unsigned int *)&v89,
            *((_BYTE *)v36 + 1416) != 0)
        & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Move the sap (vdev %d) to user configured channel %u",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "wlan_hdd_get_channel_for_sap_restart",
        (unsigned __int8)a2,
        (unsigned int)v89);
      v53 = v89;
      goto LABEL_35;
    }
    if ( *(_DWORD *)(v15 + 40) == 3 )
    {
      if ( !policy_mgr_go_scc_enforced(a1) )
      {
        wlansap_context_put(v18);
        v17 = "%s: p2p go no scc required";
        goto LABEL_66;
      }
      if ( *(_DWORD *)(v15 + 40) == 3
        && policy_mgr_go_scc_enforced(a1)
        && (policy_mgr_is_go_scc_strict(a1) & 1) == 0
        && *(_WORD *)(*((_QWORD *)v18 + 2) + 160LL) == 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: p2p go liberal mode enabled. Skipping CSA",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "wlan_hdd_get_channel_for_sap_restart");
        goto LABEL_30;
      }
    }
    ucfg_policy_mgr_get_mcc_scc_switch(*v16, v92);
    policy_mgr_get_chan_by_session_id(a1, a2, (_DWORD *)&v89 + 1);
    if ( (policy_mgr_is_restart_sap_required(*v16, a2, HIDWORD(v89), (unsigned __int8)v92[0], v18[378]) & 1) != 0 )
    {
      v74 = (unsigned __int16)wlansap_check_cc_intf(v18);
      LODWORD(v89) = v74;
      if ( v74 )
        v75 = v74;
      else
        v75 = HIDWORD(v89);
      csa_chanwidth_from_phymode = wlansap_get_csa_chanwidth_from_phymode(v18, v75, &v90);
      if ( v92[0] != 5
        && (unsigned int)policy_mgr_valid_sap_conc_channel_check(
                           *v16,
                           (unsigned int *)&v89,
                           HIDWORD(v89),
                           a2,
                           (unsigned int *)&v90) )
      {
        queue_work_on(32, system_wq, v19 + 562);
        wlansap_context_put(v18);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d can't move sap to chan(freq): %u, stopping SAP",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "wlan_hdd_get_channel_for_sap_restart",
          (unsigned __int8)a2,
          (unsigned int)v89);
        goto LABEL_17;
      }
      v53 = v89;
      if ( !(_DWORD)v89 )
      {
        v33 = a2;
        v35 = a1;
        v54 = v19;
        if ( (_DWORD)v90 == 7 )
        {
          if ( v18[378] == HIDWORD(v91) )
            goto LABEL_62;
          v53 = HIDWORD(v89);
          LODWORD(v89) = HIDWORD(v89);
        }
LABEL_36:
        if ( v53 )
        {
LABEL_37:
          wlan_hdd_set_sap_csa_reason(v35, v33, v88);
          v63 = (unsigned int)v90;
          if ( (_DWORD)v90 == 9 )
          {
            *(double *)&v55 = wlansap_get_csa_chanwidth_from_phymode(v18, (unsigned int)v89, &v90);
            v63 = (unsigned int)v90;
          }
          if ( v18[183] == 6 )
          {
            v64 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, long double))policy_mgr_check_bw_with_unsafe_chan_freq)(
                    *v16,
                    (unsigned int)v91,
                    (unsigned int)v63,
                    v55);
            v63 = (unsigned int)v90;
            if ( (v64 & 1) == 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: SAP bw shrink to 20M for unsafe from %d",
                *(double *)&v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                "wlan_hdd_get_channel_for_sap_restart",
                (unsigned int)v90);
              v63 = 0;
              LODWORD(v90) = 0;
            }
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: SAP CSA vdev %d, Freq: %d -> %d bw %d freq0 %d",
            *(double *)&v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "wlan_hdd_get_channel_for_sap_restart",
            (unsigned __int8)a2,
            *((unsigned int *)v19 + 180),
            (unsigned int)v89,
            v63,
            v91);
          v31 = v89;
          *((_DWORD *)v19 + 585) = 1;
          *a3 = v31;
          goto LABEL_43;
        }
LABEL_62:
        if ( v88 == 6 )
        {
          v84 = v35;
          v85 = v33;
          v86 = v54;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d Unable to find safe channel, Hence stop the SAP or Set Tx power",
            csa_chanwidth_from_phymode,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "wlan_hdd_get_channel_for_sap_restart",
            v33);
          wlan_hdd_set_sap_csa_reason(v84, v85, v88);
          hdd_stop_sap_set_tx_power(v84, v86);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d no channel found to switch",
            csa_chanwidth_from_phymode,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "wlan_hdd_get_channel_for_sap_restart",
            v33);
        }
        goto LABEL_30;
      }
LABEL_35:
      v33 = a2;
      v35 = a1;
      v54 = v19;
      goto LABEL_36;
    }
    wlansap_context_put(v18);
    v17 = "%s: SAP needn't restart";
LABEL_66:
    v20 = 8;
    goto LABEL_16;
  }
  v17 = "%s: SOFTAP_BSS_STARTED not set";
LABEL_15:
  v20 = 2;
LABEL_16:
  qdf_trace_msg(0x33u, v20, v17, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_get_channel_for_sap_restart");
LABEL_17:
  result = 16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
