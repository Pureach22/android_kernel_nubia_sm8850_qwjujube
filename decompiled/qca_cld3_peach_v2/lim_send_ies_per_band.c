__int64 __fastcall lim_send_ies_per_band(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 session_by_vdev_id; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  __int16 v26; // w8
  __int64 v27; // x0
  int v28; // w26
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x23
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  __int16 v49; // w9
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int *v59; // x8
  __int64 v60; // x23
  __int64 ini_vdev_config; // x0
  _BOOL4 v62; // w24
  char is_beamforming_supported; // w0
  int v64; // w23
  __int64 v65; // x0
  __int16 v66; // w8
  __int64 v67; // x0
  __int16 v68; // w8
  __int16 v69; // w9
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int *v79; // x8
  __int64 v80; // x25
  __int64 v81; // x0
  int v82; // w8
  __int64 v83; // x0
  char v84; // w0
  int v85; // w23
  int v86; // w8
  _BOOL4 v87; // w23
  __int64 v88; // x0
  _BOOL4 v89; // w25
  _BYTE v91[4]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v92; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v93; // [xsp+Eh] [xbp-22h] BYREF
  __int64 v94; // [xsp+16h] [xbp-1Ah]
  __int64 v95; // [xsp+1Eh] [xbp-12h]
  __int16 v96; // [xsp+26h] [xbp-Ah]
  __int64 v97; // [xsp+28h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( session_by_vdev_id )
    lim_disable_ht_he_dynamic_smps(
      session_by_vdev_id,
      *(_DWORD *)(session_by_vdev_id + 284),
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24);
  if ( a3 - 7 < 7 || a3 == 5 || !a3 )
  {
    v96 = 0;
    v95 = 0;
    v94 = 0;
    v93 = 0;
    v92 = 6701;
    lim_set_ht_caps(a1, (unsigned __int8 *)&v92, 0x1Cu);
    v26 = false;
    if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1288LL) & 1) != 0 )
    {
      v25 = wlan_reg_ch_to_freq(5u);
      if ( (wma_is_rx_ldpc_supported_for_channel(v25) & 1) != 0 )
        v26 = true;
    }
    v27 = *(_QWORD *)(a1 + 21624);
    v28 = *(_DWORD *)(a1 + 17192);
    LOWORD(v93) = v93 & 0xFFFE | v26;
    v29 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v27, a2, 1);
    if ( v29 )
    {
      v38 = v29;
      if ( (wlan_cm_get_force_20mhz_in_24ghz(v29, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
        LOBYTE(v28) = 0;
      wlan_objmgr_vdev_release_ref(v38, 1u, v39, v40, v41, v42, v43, v44, v45, v46, v47);
    }
    v48 = *(_QWORD *)(a1 + 21624);
    if ( (_BYTE)v28 )
      v49 = 66;
    else
      v49 = 0;
    LOWORD(v93) = v93 & 0xFFBD | v49;
    v50 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v48, a2, 1);
    if ( v50 )
    {
      v59 = (unsigned int *)BYTE4(v93);
      if ( BYTE4(v93) )
      {
        v60 = v50;
        ini_vdev_config = mlme_get_ini_vdev_config(v50, v51, v52, v53, v54, v55, v56, v57, v58);
        if ( ini_vdev_config )
        {
          v59 = (unsigned int *)*(unsigned int *)(ini_vdev_config + 24);
          v50 = v60;
          if ( (_DWORD)v59 == 1 )
            BYTE4(v93) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: nss chain dynamic config NULL",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "lim_populate_mcs_set_ht_per_vdev");
          v50 = v60;
        }
      }
      wlan_objmgr_vdev_release_ref(v50, 1u, v59, v51, v52, v53, v54, v55, v56, v57, v58);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Got NULL vdev obj, returning",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "lim_populate_mcs_set_ht_per_vdev");
    }
    is_beamforming_supported = ucfg_nan_is_beamforming_supported(*(_QWORD *)(a1 + 21624));
    if ( a4 == 11 && (is_beamforming_supported & 1) == 0 )
      *(_DWORD *)((char *)&v95 + 3) &= 0xFEDEFFFF;
    v64 = lim_send_ie((unsigned __int8)a2, 45, 1, &v93, 26);
    v66 = false;
    if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1288LL) & 1) != 0 )
    {
      v65 = wlan_reg_ch_to_freq(0x15u);
      if ( (wma_is_rx_ldpc_supported_for_channel(v65) & 1) != 0 )
        v66 = true;
    }
    v67 = *(_QWORD *)(a1 + 21624);
    v68 = v93 & 0xFFBC | v66;
    if ( *(_DWORD *)(a1 + 17196) )
      v69 = 66;
    else
      v69 = 0;
    LOWORD(v93) = v68 | v69;
    v70 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v67, a2, 1);
    if ( v70 )
    {
      v79 = (unsigned int *)BYTE4(v93);
      if ( BYTE4(v93) )
      {
        v80 = v70;
        v81 = mlme_get_ini_vdev_config(v70, v71, v72, v73, v74, v75, v76, v77, v78);
        if ( v81 )
        {
          v79 = (unsigned int *)*(unsigned int *)(v81 + 28);
          v70 = v80;
          if ( (_DWORD)v79 == 1 )
            BYTE4(v93) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: nss chain dynamic config NULL",
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            "lim_populate_mcs_set_ht_per_vdev");
          v70 = v80;
        }
      }
      wlan_objmgr_vdev_release_ref(v70, 1u, v79, v71, v72, v73, v74, v75, v76, v77, v78);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Got NULL vdev obj, returning",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "lim_populate_mcs_set_ht_per_vdev");
    }
    v62 = (v64 | (unsigned int)lim_send_ie((unsigned __int8)a2, 45, 2, &v93, 26)) == 0;
  }
  else
  {
    v62 = 1;
  }
  if ( a3 - 8 >= 6 && a3 )
  {
    v87 = 1;
  }
  else
  {
    LODWORD(v94) = 0;
    v93 = 0;
    v91[0] = 0;
    v92 = 3263;
    lim_set_vht_caps(a1, (unsigned __int8 *)&v92, 0xEu);
    v82 = 0;
    if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1288LL) & 1) != 0 )
    {
      v83 = wlan_reg_ch_to_freq(0x15u);
      if ( (wma_is_rx_ldpc_supported_for_channel(v83) & 1) != 0 )
        v82 = 16;
      else
        v82 = 0;
    }
    LODWORD(v93) = v93 & 0xFFFFFFEF | v82;
    lim_populate_mcs_set_vht_per_vdev(a1, &v92, a2, 1);
    v84 = ucfg_nan_is_beamforming_supported(*(_QWORD *)(a1 + 21624));
    if ( a4 == 11 && (v84 & 1) == 0 )
      LODWORD(v93) = v93 & 0xFFE7E7FF;
    v85 = lim_send_ie((unsigned __int8)a2, 191, 2, &v93, 12);
    wlan_mlme_get_vht_for_24ghz(*(_QWORD *)(a1 + 21624), v91);
    if ( v91[0] == 1 )
    {
      if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1288LL) & 1) != 0 )
      {
        v88 = wlan_reg_ch_to_freq(5u);
        if ( (wma_is_rx_ldpc_supported_for_channel(v88) & 1) != 0 )
          v86 = 16;
        else
          v86 = 0;
      }
      else
      {
        v86 = 0;
      }
      LODWORD(v93) = v93 & 0xFFFFFF83 | v86;
      lim_populate_mcs_set_vht_per_vdev(a1, &v92, a2, 0);
      v85 = 16 * (((unsigned int)lim_send_ie((unsigned __int8)a2, 191, 1, &v93, 12) | v85) != 0);
    }
    v87 = v85 == 0;
  }
  if ( a3 - 10 >= 4 && a3 )
  {
    v89 = 1;
    if ( a3 > 0xD )
      goto LABEL_74;
  }
  else if ( (unsigned int)lim_send_he_caps_ie(a1, a4, a2) )
  {
    v89 = 0;
  }
  else
  {
    v89 = lim_send_he_6g_band_caps_ie(a1, a2) == 0;
  }
  if ( ((1 << a3) & 0x3001) != 0
    && (a4 != 16 && a4 != 11 || (wlan_nan_is_eht_capable(*(_QWORD *)(a1 + 21624)) & 1) != 0) )
  {
    lim_send_eht_caps_ie(a1);
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  if ( v62 && v87 && v89 )
    return 0;
  else
    return 16;
}
