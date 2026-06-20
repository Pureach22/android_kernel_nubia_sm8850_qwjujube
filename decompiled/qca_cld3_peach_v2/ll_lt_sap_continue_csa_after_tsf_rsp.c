__int64 __fastcall ll_lt_sap_continue_csa_after_tsf_rsp(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  __int64 v11; // x19
  unsigned int v12; // w19
  const char *v13; // x2
  __int64 result; // x0
  unsigned int ll_lt_sap_vdev_id; // w0
  int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x19
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x24
  __int64 v45; // x23
  __int64 v46; // x21
  __int64 v47; // x0
  __int64 v48; // x5
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w9
  __int64 v59; // x22
  __int64 v60; // x20
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int64 v69; // x23
  unsigned __int8 *v70; // x21
  bool is_twt_session_present; // w0
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _QWORD v81[24]; // [xsp+10h] [xbp-D0h] BYREF
  unsigned __int8 v82; // [xsp+D0h] [xbp-10h]
  __int64 v83; // [xsp+D8h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v13 = "%s: rsp is null";
LABEL_8:
    qdf_trace_msg(0xA1u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "ll_lt_sap_continue_csa_after_tsf_rsp");
    result = 16;
    goto LABEL_29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*a1, 0x34u);
  if ( !comp_private_obj )
  {
    v13 = "%s: psoc_ll_sap_obj is null";
    goto LABEL_8;
  }
  v11 = comp_private_obj;
  if ( (unsigned int)qdf_mc_timer_get_current_state(comp_private_obj + 40) != 21 )
  {
LABEL_28:
    result = 0;
    goto LABEL_29;
  }
  qdf_mc_timer_stop(v11 + 40);
  if ( policy_mgr_is_vdev_ll_lt_sap(*a1, *((_DWORD *)a1 + 2)) )
  {
    v12 = *((_DWORD *)a1 + 2);
  }
  else
  {
    ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(*a1);
    v16 = (unsigned __int8)ll_lt_sap_vdev_id;
    v12 = ll_lt_sap_vdev_id;
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: Invalid ll_sap vdev %d, get valid ll_sap vdev %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ll_lt_sap_continue_csa_after_tsf_rsp",
      *((unsigned int *)a1 + 2),
      (unsigned __int8)ll_lt_sap_vdev_id);
    *((_DWORD *)a1 + 2) = v16;
  }
  v25 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*a1, v12, 105);
  if ( v25 )
  {
    v34 = v25;
    v35 = wlan_objmgr_vdev_get_comp_private_obj(v25, 0x34u);
    if ( v35 )
    {
      v44 = *(_QWORD *)((char *)a1 + 44);
      v45 = *(_QWORD *)((char *)a1 + 52);
      v46 = v35;
      if ( v44 )
      {
        v47 = wlan_objmgr_psoc_get_comp_private_obj(*a1, 0x34u);
        if ( v47 )
        {
          if ( (*(_BYTE *)(v47 + 210) & 1) != 0 )
            goto LABEL_15;
        }
        else
        {
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: Invalid psoc ll sap priv obj",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "ll_lt_sap_get_bearer_switch_cap_for_csa");
        }
        v58 = *((_DWORD *)a1 + 3);
        WORD2(v81[0]) = *((_WORD *)a1 + 8);
        LODWORD(v81[0]) = v58;
        wlan_twt_get_wake_dur_and_interval();
        v48 = v44;
        goto LABEL_20;
      }
LABEL_15:
      v48 = 0;
LABEL_20:
      *(_QWORD *)(v46 + 16) = v48;
      *(_QWORD *)(v46 + 24) = v45 + 500000;
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: vdev_id %d twt_target_tsf %llu and non_twt_target_tsf %llu",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "ll_lt_sap_continue_csa_after_tsf_rsp",
        *((unsigned int *)a1 + 2));
      v59 = *(_QWORD *)(v46 + 16);
      v60 = *a1;
      memset(v81, 0, sizeof(v81));
      wlan_ll_sap_notify_chan_switch_started();
      v82 = 0;
      wlan_objmgr_iterate_peerobj_list(
        v34,
        (double (__fastcall *)(__int64, __int64, __int64))&ll_lt_sap_get_vdev_peer_entries,
        (__int64)v81,
        0x69u,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68);
      if ( v82 )
      {
        v69 = 0;
        v70 = (unsigned __int8 *)v81 + 6;
        do
        {
          if ( v69 == 31 )
            __break(0x5512u);
          is_twt_session_present = wlan_is_twt_session_present(v60, v70);
          if ( v59 && is_twt_session_present )
            wlan_ll_sap_send_action_frame();
          ++v69;
          v70 += 6;
        }
        while ( v69 < v82 );
      }
      wlan_ll_sap_send_continue_vdev_restart();
      wlan_objmgr_vdev_release_ref(v34, 0x69u, v72, v73, v74, v75, v76, v77, v78, v79, v80);
      goto LABEL_28;
    }
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "ll_lt_sap_continue_csa_after_tsf_rsp",
      *((unsigned int *)a1 + 2));
    wlan_objmgr_vdev_release_ref(v34, 0x69u, v49, v50, v51, v52, v53, v54, v55, v56, v57);
    result = 4;
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d is null",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ll_lt_sap_continue_csa_after_tsf_rsp",
      *((unsigned int *)a1 + 2));
    result = 16;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
