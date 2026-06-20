__int64 __fastcall tdls_check_6g_freq_allowed(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  __int64 v23; // x23
  __int64 v24; // x22
  unsigned int v25; // w0
  unsigned int v26; // w20
  unsigned int v27; // w21
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int8 v37; // w22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  unsigned int operation_chan_freq; // w0
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned __int8 v57; // w22
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int8 chan_enum_for_freq; // w21
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7

  if ( (wlan_vdev_mlme_is_mlo_vdev(a2, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
  {
    if ( wlan_reg_is_6ghz_chan_freq(a3) )
    {
      if ( !a1
        || !wlan_reg_is_6ghz_chan_freq(a3)
        || (wlan_cfg80211_tdls_is_fw_6ghz_capable(a1) & 1) == 0
        || (chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(a3, v66, v67, v68, v69, v70, v71, v72, v73),
            (wlan_reg_is_6ghz_psc_chan_freq(a3, v75, v76, v77, v78, v79, v80, v81, v82) & 1) == 0)
        || (wlan_reg_is_freq_idx_enabled(a1, chan_enum_for_freq, 6u, v66, v67, v68, v69, v70, v71, v72, v73) & 1) == 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: 6GHz freq:%d not allowed for TDLS",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "tdls_check_6g_freq_allowed",
          a3);
        return 0;
      }
    }
    return 1;
  }
  v22 = *(_QWORD *)(a2 + 216);
  if ( !v22 )
    return 0;
  v23 = *(_QWORD *)(a2 + 1360);
  if ( !v23 )
    return 0;
  v24 = *(_QWORD *)(v23 + 24);
  if ( !v24
    || (unsigned int)wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v23 + 24), 0x11u, v14, v15, v16, v17, v18, v19, v20, v21)
    || (v25 = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)v24),
        v26 = *(unsigned __int8 *)(v24 + 168),
        v27 = v25,
        wlan_objmgr_vdev_release_ref(v24, 0x11u, v28, v29, v30, v31, v32, v33, v34, v35, v36),
        !wlan_reg_is_6ghz_chan_freq(v27))
    || wlan_reg_is_6ghz_chan_freq(v27)
    && (wlan_cfg80211_tdls_is_fw_6ghz_capable(v22) & 1) != 0
    && (v37 = wlan_reg_get_chan_enum_for_freq(v27, v14, v15, v16, v17, v18, v19, v20, v21),
        (wlan_reg_is_6ghz_psc_chan_freq(v27, v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0)
    && (wlan_reg_is_freq_idx_enabled(v22, v37, 6u, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
  {
    v46 = *(_QWORD *)(v23 + 32);
    if ( !v46 )
      return 1;
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(
                         *(_QWORD *)(v23 + 32),
                         0x11u,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21) )
      return 1;
    operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)v46);
    v26 = *(unsigned __int8 *)(v46 + 168);
    v27 = operation_chan_freq;
    wlan_objmgr_vdev_release_ref(v46, 0x11u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
    if ( !wlan_reg_is_6ghz_chan_freq(v27) )
      return 1;
    if ( wlan_reg_is_6ghz_chan_freq(v27) && (wlan_cfg80211_tdls_is_fw_6ghz_capable(v22) & 1) != 0 )
    {
      v57 = wlan_reg_get_chan_enum_for_freq(v27, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( (wlan_reg_is_6ghz_psc_chan_freq(v27, v58, v59, v60, v61, v62, v63, v64, v65) & 1) != 0
        && (wlan_reg_is_freq_idx_enabled(v22, v57, 6u, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      {
        return 1;
      }
    }
  }
  qdf_trace_msg(
    0,
    2u,
    "%s: vdev:%d 6g freq:%d not allowed for tdls",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "tdls_is_6g_freq_allowed_in_ml_vdev",
    v26,
    v27);
  return 0;
}
