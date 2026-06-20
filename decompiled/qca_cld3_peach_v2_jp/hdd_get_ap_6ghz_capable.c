__int64 __fastcall hdd_get_ap_6ghz_capable(
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
  unsigned int v11; // w20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 link_info_from_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x24
  __int64 v32; // x23
  int v33; // w22
  _DWORD *v34; // x22
  const char *v35; // x2
  __int64 v36; // x4
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v47; // w23
  _DWORD *v48; // x8
  int v49; // w24
  unsigned int param; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w23
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int v69; // w8
  unsigned int v70; // w21
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: PSOC is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_ap_6ghz_capable");
    return 0;
  }
  v11 = a2;
  v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 5);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev is NULL %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_get_ap_6ghz_capable",
      (unsigned __int8)v11);
    return 0;
  }
  v21 = v12;
  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev(a1, v11);
  if ( !link_info_from_vdev )
  {
    v35 = "%s: Invalid vdev %d";
    goto LABEL_12;
  }
  v31 = *(_QWORD *)link_info_from_vdev;
  v32 = link_info_from_vdev;
  v33 = policy_mgr_qdf_opmode_to_pm_con_mode(
          a1,
          *(_DWORD *)(*(_QWORD *)link_info_from_vdev + 40LL),
          v11,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30);
  if ( !policy_mgr_is_beaconing_mode(v33) || !policy_mgr_is_6ghz_conc_mode_supported(a1, v33) )
  {
    v36 = *(unsigned int *)(v31 + 40);
    v35 = "%s: unexpected device mode %d";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v35, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_get_ap_6ghz_capable", v36);
LABEL_14:
    wlan_objmgr_vdev_release_ref(v21, 5u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    return 0;
  }
  v34 = *(_DWORD **)(v32 + 272);
  if ( (unsigned int)wlansap_context_get(v34) )
  {
    v35 = "%s: sap_context is get failed %d";
LABEL_12:
    v36 = (unsigned __int8)v11;
    goto LABEL_13;
  }
  if ( (*(_QWORD *)(v32 + 4416) & 2) != 0 )
  {
    v48 = (_DWORD *)(v32 + 2152);
    goto LABEL_22;
  }
  if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v32 + 720)) )
  {
    v47 = 2;
    goto LABEL_25;
  }
  v48 = v34;
  if ( v34 )
  {
LABEL_22:
    if ( wlan_reg_is_6ghz_chan_freq(*v48) )
      v47 = 2;
    else
      v47 = 0;
    goto LABEL_25;
  }
  v47 = 0;
LABEL_25:
  if ( (wlansap_is_6ghz_included_in_acs_range(v34) & 1) != 0 )
    v49 = 2;
  else
    v49 = v47;
  param = wlan_crypto_get_param(v21, 7u);
  if ( (param & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid mgmt cipher",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "hdd_get_ap_6ghz_capable");
    goto LABEL_14;
  }
  v59 = param;
  if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 1021) & 1) == 0 && ((v59 & 4) != 0 || v59 == 0) )
    v49 |= 4u;
  if ( (v59 & 0x8430400) != 0 )
    v69 = v49 | 4;
  else
    v69 = v49;
  v70 = v69 | 1;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev_id %d keymgmt 0x%08x capable 0x%x",
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    "hdd_get_ap_6ghz_capable",
    (unsigned __int8)v11,
    v59,
    v69 | 1u);
  wlansap_context_put(v34);
  wlan_objmgr_vdev_release_ref(v21, 5u, v71, v72, v73, v74, v75, v76, v77, v78, v79);
  return v70;
}
