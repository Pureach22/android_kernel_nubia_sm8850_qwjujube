__int64 __fastcall hdd_set_primary_interface(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  __int64 *v5; // x23
  int v6; // w24
  __int64 *v7; // x21
  unsigned __int8 v8; // w8
  __int64 v9; // x0
  unsigned __int8 v10; // w20
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  const char *v21; // x2
  __int64 v22; // x0
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
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
  unsigned int dual_sta_policy; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x2
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int mcc_duty_cycle_percentage; // w0
  __int64 v83; // [xsp+0h] [xbp-10h] BYREF
  __int64 v84; // [xsp+8h] [xbp-8h]

  result = 0;
  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  LOBYTE(v83) = 0;
  v5 = *(__int64 **)(v4 + 24);
  if ( !*(_DWORD *)(v4 + 40) )
  {
    v6 = *(unsigned __int8 *)(a2 + 4);
    v7 = a1;
    v8 = *((_BYTE *)a1 + 8);
    v9 = *v5;
    BYTE4(v83) = 0;
    if ( v6 )
      v10 = v8;
    else
      v10 = -1;
    v11 = wlan_mlme_set_primary_interface(v9, v10);
    if ( v11 )
    {
      v20 = v11;
      v21 = "%s: could not set primary interface, %d";
LABEL_7:
      qdf_trace_msg(0x33u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_set_primary_interface", v20, v83);
      result = 4294967274LL;
      goto LABEL_20;
    }
    v22 = *v5;
    *((_BYTE *)v5 + 7095) = v10;
    v23 = policy_mgr_mode_specific_connection_count(v22, 0, nullptr);
    if ( v23 <= 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: STA + STA concurrency not present, count:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_set_primary_interface",
        v23);
      goto LABEL_19;
    }
    if ( (wlan_mlme_is_primary_interface_configured(*v5) & 1) != 0
      && ((ucfg_mlme_get_dual_sta_roaming_enabled(*v5) & 1) != 0
       && (((__int64 (__fastcall *)(__int64))policy_mgr_concurrent_sta_on_different_mac)(*v5) & 1) == 0
       || (ucfg_mlme_get_dual_sta_roaming_enabled(*v5) & 1) == 0) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Enable roaming on requested interface: %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_set_primary_interface",
        *((unsigned __int8 *)v7 + 8),
        v83,
        v84);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Enable roaming on requested interface: %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "hdd_set_primary_interface",
        *((unsigned __int8 *)v7 + 8));
      wlan_cm_roam_state_change(v5[1], *((unsigned __int8 *)v7 + 8), 2, 0x36u);
    }
    if ( (policy_mgr_current_concurrency_is_mcc(*v5) & 1) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: STA + STA concurrency not in MCC",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "hdd_set_primary_interface");
      goto LABEL_19;
    }
    dual_sta_policy = wlan_mlme_get_dual_sta_policy(*v5, (_BYTE *)&v83 + 4);
    if ( dual_sta_policy )
    {
      v20 = dual_sta_policy;
      v21 = "%s: could not get dual sta policy, %d";
      goto LABEL_7;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: is_set_primary_iface: %d, primary vdev id: %d, dual_sta_policy:%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_set_primary_interface",
      v6 != 0,
      v10,
      BYTE4(v83));
    if ( v6 && !BYTE4(v83) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Disable mcc_adaptive_scheduler",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "hdd_set_primary_interface");
      ucfg_policy_mgr_get_mcc_adaptive_sch(*v5, &v83);
      if ( (unsigned __int8)v83 == 1
        && (ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(*v5, 0), (unsigned int)sme_set_mas(0)) )
      {
        v73 = "%s: Fail to disable mcc adaptive sched.";
      }
      else
      {
        mcc_duty_cycle_percentage = wlan_mlme_get_mcc_duty_cycle_percentage(v5[1]);
        if ( (mcc_duty_cycle_percentage & 0x80000000) == 0 )
        {
          wlan_hdd_send_mcc_vdev_quota(v4, mcc_duty_cycle_percentage);
          goto LABEL_19;
        }
        v73 = "%s: Invalid mcc duty cycle";
      }
      qdf_trace_msg(0x33u, 2u, v73, v65, v66, v67, v68, v69, v70, v71, v72, "hdd_set_primary_interface", v83);
      result = 4294967274LL;
      goto LABEL_20;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Enable mcc_adaptive_scheduler",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "hdd_set_primary_interface",
      v83);
    ucfg_policy_mgr_get_mcc_adaptive_sch(*v5, &v83);
    if ( (unsigned __int8)v83 != 1 )
    {
LABEL_19:
      result = 0;
      goto LABEL_20;
    }
    ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(*v5, 1);
    result = sme_set_mas(1);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Fail to enable mcc_adaptive_sched.",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "hdd_set_primary_interface");
      result = 4294967285LL;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
