__int64 __fastcall lim_process_sme_channel_change_request(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w22
  char channel_reg_power_for_freq; // w0
  const char *v14; // x2
  __int64 result; // x0
  char v16; // w24
  __int64 session_by_bssid; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  __int64 v27; // x3
  __int64 v28; // x5
  __int16 v29; // w8
  int v30; // w9
  unsigned int v31; // w8
  bool v32; // cf
  unsigned int v33; // w8
  char v34; // w9
  unsigned int v35; // w8
  unsigned int v36; // w8
  char v37; // w9
  int v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  _BOOL4 is_24ghz_ch_freq; // w23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w8
  _BOOL4 v58; // w23
  unsigned int v59; // w9
  unsigned int v60; // w8
  int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w8
  __int64 v71; // x0
  int v72; // w8
  int v73; // w8
  int v74; // w8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x0
  int v84; // w8
  unsigned int v85; // w1
  _BYTE v86[4]; // [xsp+1Ch] [xbp-14h] BYREF
  int v87; // [xsp+20h] [xbp-10h] BYREF
  __int16 v88; // [xsp+24h] [xbp-Ch]
  __int64 v89; // [xsp+28h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v88 = 0;
  v87 = 0;
  v86[0] = 0;
  if ( !a2 )
  {
    v14 = "%s: msg_buf is NULL";
    goto LABEL_5;
  }
  v10 = *((_DWORD *)a2 + 1);
  channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(a1[2695], v10, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( channel_reg_power_for_freq != 127 )
  {
    v16 = channel_reg_power_for_freq;
    wlan_mlme_get_mac_vdev_id(a1[2695], *a2, &v87);
    session_by_bssid = pe_find_session_by_bssid(a1, &v87, v86);
    if ( !session_by_bssid )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "lim_process_sme_channel_change_request",
                 (unsigned __int8)v87,
                 BYTE1(v87),
                 BYTE2(v87),
                 HIBYTE(v88));
      goto LABEL_6;
    }
    v26 = session_by_bssid;
    if ( *(_DWORD *)(session_by_bssid + 88) == 1
      && (policy_mgr_is_sap_allowed_on_dfs_freq(a1[2695], *a2, v10, v18, v19, v20, v21, v22, v23, v24, v25) & 1) == 0 )
    {
      goto LABEL_14;
    }
    v27 = *(unsigned int *)(v26 + 284);
    if ( (_DWORD)v27 == v10
      && *(_DWORD *)(v26 + 7176) == *((_DWORD *)a2 + 3)
      && *(unsigned __int8 *)(v26 + 7184) == a2[17] )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Target channel and mode is same as current channel and mode channel freq %d and mode %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_process_sme_channel_change_request",
        v10);
LABEL_14:
      result = lim_abort_channel_change(a1, *a2);
      goto LABEL_6;
    }
    v28 = *(unsigned int *)(v26 + 7176);
    if ( *(_DWORD *)(v26 + 88) == 1 )
      v29 = 3;
    else
      v29 = 5;
    v30 = *(unsigned __int8 *)(v26 + 154);
    *(_WORD *)(v26 + 152) = v29;
    qdf_trace_msg(
      0x35u,
      8u,
      "SAP CSA: %d --> %d, ch_bw %d --> %d, nw_type %d, dot11mode %d, old dot11mode %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v27,
      v10,
      v28,
      *((unsigned int *)a2 + 3),
      *((unsigned int *)a2 + 6),
      *((_DWORD *)a2 + 5),
      v30);
    v31 = *((_DWORD *)a2 + 5);
    if ( v31 != *(unsigned __int8 *)(v26 + 154) )
    {
      v32 = v31 >= 0xE;
      v33 = 0x3FA1u >> v31;
      v34 = !v32;
      *(_BYTE *)(v26 + 155) = v34 & v33;
      v35 = *((_DWORD *)a2 + 5);
      v32 = v35 >= 0xE;
      v36 = 0x3F01u >> v35;
      v37 = !v32;
      *(_BYTE *)(v26 + 7170) = v37 & v36;
      *(_BYTE *)(v26 + 8676) = ((unsigned __int8)*((_DWORD *)a2 + 5) < 0xEu) & (0x3C01u >> *((_DWORD *)a2 + 5));
    }
    if ( wlan_reg_is_6ghz_chan_freq(v10)
      && ((v38 = *(unsigned __int8 *)(v26 + 154), (unsigned int)(v38 - 7) < 7) || v38 == 5 || !*(_BYTE *)(v26 + 154))
      && policy_mgr_is_vdev_ll_lt_sap(a1[2694], *(unsigned __int8 *)(v26 + 10)) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: For LL LT vdev %d allow 6 Ghz freq %d for dot11mode %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "lim_process_sme_channel_change_request",
        *(unsigned __int8 *)(v26 + 10),
        v10,
        *(unsigned __int8 *)(v26 + 154));
    }
    else
    {
      v47 = *((_DWORD *)a2 + 5);
      if ( ((unsigned int)(v47 - 10) < 4 || !v47) && (*(_DWORD *)(v26 + 7036) == 6 || *(_BYTE *)(v26 + 8676) == 1) )
      {
        lim_update_session_he_capable_chan_switch(a1, v26, v10);
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v10);
        if ( ((is_24ghz_ch_freq ^ wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v26 + 284))) & 1) != 0
          || *(_DWORD *)(v26 + 7176) != *((_DWORD *)a2 + 3) )
        {
          *(_DWORD *)(v26 + 284) = v10;
          *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
          lim_copy_bss_he_cap(v26);
          lim_update_he_bw_cap_mcs(v26, 0);
        }
      }
      else if ( wlan_reg_is_6ghz_chan_freq(v10) )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Invalid target_freq %d for dot11mode %d cur HE %d",
                   v49,
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   v56,
                   "lim_process_sme_channel_change_request",
                   v10,
                   *((unsigned int *)a2 + 5),
                   *(unsigned __int8 *)(v26 + 8676));
        goto LABEL_6;
      }
    }
    v57 = *((_DWORD *)a2 + 5);
    if ( v57 <= 0xD && ((1 << v57) & 0x3001) != 0 && *(_DWORD *)(v26 + 7036) == 6 )
    {
      v58 = wlan_reg_is_24ghz_ch_freq(v10);
      if ( ((v58 ^ wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v26 + 284))) & 1) != 0
        || (v59 = *(_DWORD *)(v26 + 7176), v60 = *((_DWORD *)a2 + 3), v59 != v60) && (v59 > 2 || v60 >= 3) )
      {
        *(_DWORD *)(v26 + 284) = v10;
        *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
      }
    }
    *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
    *(_BYTE *)(v26 + 7174) = a2[16];
    *(_BYTE *)(v26 + 7184) = a2[17];
    *(_DWORD *)(v26 + 164) = a2[8];
    v61 = *((_DWORD *)a2 + 3);
    *(_DWORD *)(v26 + 284) = v10;
    LOBYTE(v61) = v61 != 0;
    *(_BYTE *)(v26 + 160) = v61;
    *(_BYTE *)(v26 + 161) = v61;
    if ( wlan_reg_is_6ghz_chan_freq(v10) )
    {
      v70 = 2;
    }
    else if ( wlan_reg_is_5ghz_ch_freq(v10) )
    {
      v70 = 1;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(v10) )
    {
      v70 = 0;
    }
    else
    {
      v70 = 3;
    }
    v71 = *(_QWORD *)(v26 + 16);
    *(_DWORD *)(v26 + 168) = v70;
    if ( (mlme_get_cac_required(v71, v62, v63, v64, v65, v66, v67, v68, v69) & 1) != 0 )
      v72 = *((_DWORD *)a2 + 7);
    else
      v72 = 0;
    *(_DWORD *)(v26 + 10048) = v72;
    v73 = *((_DWORD *)a2 + 8);
    *(_BYTE *)(v26 + 7032) = v16;
    *(_DWORD *)(v26 + 10064) = v73;
    lim_update_bcn_probe_filter(a1, v26);
    v74 = *(_DWORD *)(v26 + 168);
    if ( v74 )
      v74 = *(unsigned __int8 *)(a1[1] + 1061LL);
    *(_DWORD *)(v26 + 7028) = v74;
    *(_BYTE *)(v26 + 154) = *((_DWORD *)a2 + 5);
    *(_DWORD *)(v26 + 96) = *((_DWORD *)a2 + 6);
    qdf_mem_copy((void *)(v26 + 252), a2 + 36, 0xDu);
    qdf_mem_copy((void *)(v26 + 265), a2 + 49, 0xDu);
    v83 = *(_QWORD *)(v26 + 16);
    if ( *(_DWORD *)(v26 + 92) == 3 )
    {
      v84 = *(_DWORD *)(v83 + 20);
      if ( v84 == 3 )
      {
        mlme_set_chan_switch_in_progress(v83, 1, v75, v76, v77, v78, v79, v80, v81, v82);
        v83 = *(_QWORD *)(v26 + 16);
        v85 = 21;
      }
      else
      {
        if ( v84 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Invalid vdev state to change channel",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "lim_mon_change_channel");
          goto LABEL_71;
        }
        v85 = 0;
      }
    }
    else
    {
      mlme_set_chan_switch_in_progress(v83, 1, v75, v76, v77, v78, v79, v80, v81, v82);
      v83 = *(_QWORD *)(v26 + 16);
      if ( *(_DWORD *)(v83 + 20) == 2 )
        v85 = 23;
      else
        v85 = 25;
    }
    wlan_vdev_mlme_sm_deliver_evt(v83, v85, 0x2A28u, v26, v75, v76, v77, v78, v79, v80, v81, v82);
LABEL_71:
    lim_check_conc_power_for_csa(a1, v26);
    lim_dump_session_info(a1, v26);
    result = lim_dump_he_info(a1, v26);
    goto LABEL_6;
  }
  v14 = "%s: Invalid max tx power";
LABEL_5:
  result = qdf_trace_msg(0x35u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_sme_channel_change_request");
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
