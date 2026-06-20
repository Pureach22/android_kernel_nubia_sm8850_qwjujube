__int64 __fastcall lim_check_conc_power_for_csa(
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
  char tpc_update_required_for_sta; // w22
  __int64 concurrent_session; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 cmpt_obj; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
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
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x8
  __int64 v74; // x2
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7

  tpc_update_required_for_sta = wlan_get_tpc_update_required_for_sta(
                                  *(_QWORD *)(a2 + 16),
                                  a3,
                                  a4,
                                  a5,
                                  a6,
                                  a7,
                                  a8,
                                  a9,
                                  a10);
  concurrent_session = lim_get_concurrent_session(a1, *(_BYTE *)(a2 + 10), *(_DWORD *)(a2 + 7036));
  if ( !concurrent_session )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: STA session doesn't exist",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "lim_check_conc_power_for_csa");
  v22 = concurrent_session;
  if ( (tpc_update_required_for_sta & 1) != 0
    && !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284))
    && wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v22 + 284)) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: SAP has moved from 6GHz, restore STA power",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_check_conc_power_for_csa");
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v22 + 16), v31, v32, v33, v34, v35, v36, v37, v38);
    result = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v40, v41, v42, v43, v44, v45, v46, v47);
    if ( cmpt_obj )
    {
      if ( result )
      {
        result = wlan_is_scc_tpc_power_supp_enabled(*(_QWORD *)(v22 + 16), v49, v50, v51, v52, v53, v54, v55, v56);
        if ( (result & 1) == 0 )
        {
          wlan_set_tpc_update_required_for_sta(*(_QWORD *)(a2 + 16), 0, v57, v58, v59, v60, v61, v62, v63, v64);
          v73 = *(_QWORD *)(v22 + 112);
          *(_BYTE *)(v22 + 10070) = 0;
          if ( v73 )
            v74 = v73 + 4548;
          else
            v74 = 0;
          return lim_set_tpc_power(a1, v22, v74, 0, v65, v66, v67, v68, v69, v70, v71, v72);
        }
      }
    }
  }
  else
  {
    result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284));
    if ( (result & 1) != 0 )
    {
      result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v22 + 284));
      if ( (result & 1) != 0 && *(_DWORD *)(*(_QWORD *)(a2 + 16) + 20LL) == 3 )
      {
        result = lim_is_power_change_required_for_sta(a1, v22, a2, v75, v76, v77, v78, v79, v80, v81, v82);
        if ( (result & 1) != 0 )
        {
          lim_set_tpc_power(a1, a2, 0, 0, v83, v84, v85, v86, v87, v88, v89, v90);
          result = lim_update_tx_power(a1, a2, v22, 0, v91, v92, v93, v94, v95, v96, v97, v98);
          if ( !(_DWORD)result )
            return wlan_set_tpc_update_required_for_sta(
                     *(_QWORD *)(a2 + 16),
                     1,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103,
                     v104,
                     v105,
                     v106);
        }
      }
    }
  }
  return result;
}
