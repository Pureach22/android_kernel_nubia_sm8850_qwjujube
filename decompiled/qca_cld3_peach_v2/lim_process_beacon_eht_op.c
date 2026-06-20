__int64 __fastcall lim_process_beacon_eht_op(
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
  __int64 v10; // x25
  _QWORD *v12; // x20
  unsigned int v14; // w21
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w22
  unsigned int v25; // w23
  unsigned int v26; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  const char *v44; // x3
  __int64 v45; // x20
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w24
  __int64 v63; // x8
  __int64 v64; // x0
  unsigned int peer_phymode; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int ch_width_from_phymode; // w0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  int v92; // w6
  __int64 v93; // x0
  unsigned __int16 *v94; // x8
  int v95; // w9
  unsigned int v96; // [xsp+14h] [xbp-3Ch] BYREF
  _QWORD v97[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v98; // [xsp+28h] [xbp-28h]
  __int64 v99; // [xsp+30h] [xbp-20h]
  __int64 v100; // [xsp+38h] [xbp-18h]
  unsigned int v101; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v102; // [xsp+48h] [xbp-8h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v101 = 8;
  v99 = 0;
  v100 = 0;
  v97[1] = 0;
  v98 = 0;
  v97[0] = 0;
  v96 = 0;
  if ( !a1 || !a2 || (v10 = *(_QWORD *)(a1 + 8608)) == 0 || (v12 = *(_QWORD **)(a1 + 16)) == nullptr )
  {
    v43 = "%s: invalid input parameters";
    goto LABEL_10;
  }
  v14 = wlan_reg_freq_to_chan(v12[27], *(_DWORD *)(a2 + 72), a3, a4, a5, a6, a7, a8, a9, a10);
  result = lim_get_cb_mode_for_freq(v10, a1, *(unsigned int *)(a1 + 284));
  if ( (_BYTE)result )
  {
    if ( (*(_BYTE *)(a2 + 2833) & 1) == 0 )
    {
      if ( (*(_BYTE *)(a2 + 2703) & 0x20) == 0 )
        goto LABEL_12;
      v24 = *(unsigned __int8 *)(a2 + 2714);
      v25 = *(unsigned __int8 *)(a2 + 2715);
      v26 = wlan_mlme_convert_he_6ghz_op_bw_to_phy_ch_width(
              *(_BYTE *)(a2 + 2713) & 3,
              v14,
              *(_BYTE *)(a2 + 2714),
              *(_BYTE *)(a2 + 2715));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: update bcn ch width from 6g he op",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "lim_process_beacon_eht_op");
      lim_update_bcn_op_ch_width(*(_QWORD *)(a1 + 16), v26, v35, v36, v37, v38, v39, v40, v41, v42);
      goto LABEL_16;
    }
    v26 = wlan_mlme_convert_eht_op_bw_to_phy_ch_width(*(_BYTE *)(a2 + 2838) & 7);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: update bcn ch width from eht op",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_process_beacon_eht_op");
    lim_update_bcn_op_ch_width(*(_QWORD *)(a1 + 16), v26, v54, v55, v56, v57, v58, v59, v60, v61);
    v24 = *(unsigned __int8 *)(a2 + 2839);
    v25 = *(unsigned __int8 *)(a2 + 2840);
    if ( (*(_BYTE *)(a2 + 2833) & 2) == 0 )
    {
LABEL_16:
      v62 = 0;
LABEL_17:
      v63 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
      if ( !v63 || (v64 = *(_QWORD *)(v63 + 80)) == 0 )
      {
        v43 = "%s: psoc object invalid";
        v44 = "lim_get_update_eht_bw_puncture_allow";
        goto LABEL_11;
      }
      peer_phymode = mlme_get_peer_phymode(v64, (_BYTE *)(a1 + 24), &v96);
      if ( peer_phymode )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: failed to get phy_mode %d mac: %02x:%02x:%02x:**:**:%02x",
                   v66,
                   v67,
                   v68,
                   v69,
                   v70,
                   v71,
                   v72,
                   v73,
                   "lim_get_update_eht_bw_puncture_allow",
                   peer_phymode,
                   *(unsigned __int8 *)(a1 + 24),
                   *(unsigned __int8 *)(a1 + 25),
                   *(unsigned __int8 *)(a1 + 26),
                   *(unsigned __int8 *)(a1 + 29));
        goto LABEL_12;
      }
      ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(v96, v66, v67, v68, v69, v70, v71, v72, v73);
      v92 = v26;
      if ( ch_width_from_phymode >= v26 )
        goto LABEL_34;
      if ( v26 == 7 && ch_width_from_phymode == 3 && (*(_QWORD *)(a1 + 10073) & 0x20000) == 0 )
      {
        v92 = 3;
LABEL_34:
        result = wlan_cm_sta_update_bw_puncture(
                   (__int64)v12,
                   a1 + 24,
                   v62,
                   v26,
                   v24,
                   v25,
                   v92,
                   v84,
                   v85,
                   v86,
                   v87,
                   v88,
                   v89,
                   v90,
                   v91);
        if ( !(_DWORD)result )
          result = wma_send_peer_phy_mode(a1 + 24, *(unsigned __int8 *)(a1 + 10), v96);
        goto LABEL_12;
      }
      v93 = _qdf_mem_malloc(0x24u, "lim_process_beacon_eht_op", 512);
      if ( v93 )
      {
        v94 = (unsigned __int16 *)v12[5];
        *(_BYTE *)v93 = *((_BYTE *)v94 + 2);
        LODWORD(v94) = *v94;
        *(_DWORD *)(v93 + 12) = v26;
        *(_WORD *)(v93 + 16) = v62;
        *(_BYTE *)(v93 + 19) = v24;
        *(_BYTE *)(v93 + 20) = v25;
        *(_DWORD *)(v93 + 4) = (_DWORD)v94;
        v95 = *(_DWORD *)(a1 + 24);
        *(_WORD *)(v93 + 32) = *(_WORD *)(a1 + 28);
        *(_DWORD *)(v93 + 28) = v95;
        result = lim_handle_sta_csa_param(*(_QWORD *)(a1 + 8608), v93, 0);
        goto LABEL_12;
      }
      v43 = "%s: csa_param allocation fails";
LABEL_10:
      v44 = "lim_process_beacon_eht_op";
LABEL_11:
      result = qdf_trace_msg(0x35u, 2u, v43, a3, a4, a5, a6, a7, a8, a9, a10, v44);
      goto LABEL_12;
    }
    v62 = *(unsigned __int16 *)(a2 + 2841);
    if ( (wlan_mlme_get_eht_disable_punct_in_us_lpi(*(_QWORD *)(v10 + 21624)) & 1) == 0 )
      goto LABEL_17;
    v74 = *(_DWORD *)(a2 + 72);
    LOWORD(v100) = v62;
    LOWORD(v97[0]) = v74;
    v99 = v26 | 0x2700000000LL;
    if ( v26 == 7 && wlan_reg_is_6ghz_chan_freq(v74) )
      HIDWORD(v98) = wlan_reg_chan_band_to_freq(
                       *(_QWORD *)(v10 + 21632),
                       v25,
                       4u,
                       v75,
                       v76,
                       v77,
                       v78,
                       v79,
                       v80,
                       v81,
                       v82);
    result = wlan_mlme_get_bw_no_punct(*(_QWORD *)(v10 + 21624), (__int64)v12, (unsigned __int16 *)v97, &v101);
    if ( (_DWORD)result )
      goto LABEL_17;
    if ( v101 != *(_DWORD *)(v12[4] + 24LL) )
      result = wlan_mlme_send_ch_width_update_with_notify(
                 *(_QWORD *)(v10 + 21624),
                 v12,
                 *(_BYTE *)(a1 + 10),
                 v101,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10);
  }
  else
  {
    v45 = jiffies;
    if ( lim_process_beacon_eht_op___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: chan banding is disabled skip bw update",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "lim_process_beacon_eht_op");
      lim_process_beacon_eht_op___last_ticks = v45;
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
