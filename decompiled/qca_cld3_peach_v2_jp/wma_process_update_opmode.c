__int64 __fastcall wma_process_update_opmode(__int64 *a1, unsigned int *a2)
{
  __int64 peer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8
  unsigned int v25; // w25
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w23
  unsigned int ch_width_from_phy_mode; // w24
  unsigned int v36; // w22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x26
  unsigned int v55; // w23
  unsigned int v56; // w27
  unsigned int v57; // w25
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int16 *v66; // x27
  unsigned __int64 v67; // x8
  __int64 v68; // x8
  int v69; // w24
  __int64 v71; // x0
  int v72; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7

  peer = wlan_objmgr_get_peer(a1[3], *(_BYTE *)(a1[4] + 40), (_BYTE *)a2 + 6, 8u);
  if ( !peer )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: peer object invalid",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "wma_process_update_opmode");
  v13 = peer;
  if ( *(_DWORD *)(peer + 68) == 1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: self peer wrongly used",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wma_process_update_opmode");
    return wlan_objmgr_peer_release_ref(v13, 8u, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(peer + 760);
    v24 = *(_QWORD *)(v13 + 768);
    v25 = *(_DWORD *)(v13 + 72);
    if ( (v24 & 1) == 0 )
    {
LABEL_9:
      raw_spin_unlock(v13 + 760);
      goto LABEL_10;
    }
  }
  else
  {
    raw_spin_lock_bh(peer + 760);
    v24 = *(_QWORD *)(v13 + 768) | 1LL;
    *(_QWORD *)(v13 + 768) = v24;
    v25 = *(_DWORD *)(v13 + 72);
    if ( (v24 & 1) == 0 )
      goto LABEL_9;
  }
  *(_QWORD *)(v13 + 768) = v24 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v13 + 760);
LABEL_10:
  wlan_objmgr_peer_release_ref(v13, 8u, v26, v27, v28, v29, v30, v31, v32, v33);
  v34 = wmi_host_to_fw_phymode(v25);
  ch_width_from_phy_mode = wmi_get_ch_width_from_phy_mode(*a1, v34);
  v36 = target_if_phy_ch_width_to_wmi_chan_width(*a2);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: ch_width: %d, fw phymode: %d peer_phymode: %d, op_mode chwidth: %d, wmi opmode chwidth %d",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "wma_process_update_opmode",
    ch_width_from_phy_mode,
    v34,
    v25,
    *a2,
    v36);
  if ( ch_width_from_phy_mode < v36 )
  {
    v45 = target_if_wmi_chan_width_to_phy_ch_width(ch_width_from_phy_mode);
    v54 = a1[4];
    if ( v54 )
    {
      v55 = *a2;
      v56 = *(_DWORD *)(v13 + 68);
      v57 = v45;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: peer type %d bw old %d new %d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wma_update_peer_phymode",
        v56,
        v45,
        *a2);
      if ( v56 - 6 >= 0xFFFFFFFE )
      {
        v66 = *(unsigned __int16 **)(*(_QWORD *)(v13 + 88) + 40LL);
        if ( (wlan_is_valid_dnw(v54, *v66, v57, v55) & 1) != 0 )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v67 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v67 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v67 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v13 + 760);
            v68 = *(_QWORD *)(v13 + 768);
            v69 = *(_DWORD *)(v13 + 72);
            if ( (v68 & 1) == 0 )
            {
LABEL_18:
              raw_spin_unlock(v13 + 760);
LABEL_19:
              if ( wlan_reg_is_24ghz_ch_freq(*v66) )
              {
                if ( v69 == 2 || *((_DWORD *)v66 + 7) == 2 )
                  v71 = 1;
                else
                  v71 = 2;
              }
              else
              {
                v71 = 0;
              }
              v72 = wma_peer_phymode(
                      v71,
                      1,
                      (unsigned int)(v69 - 5) < 6,
                      v55,
                      (unsigned int)(v69 - 11) < 0xA,
                      (unsigned int)(v69 - 21) < 0xA,
                      0);
              v34 = wmi_host_to_fw_phymode(v72);
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: BW update from 80 to 160MHz, fw_phymode %d",
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "wma_process_update_opmode",
                v34);
              goto LABEL_30;
            }
          }
          else
          {
            raw_spin_lock_bh(v13 + 760);
            v68 = *(_QWORD *)(v13 + 768) | 1LL;
            *(_QWORD *)(v13 + 768) = v68;
            v69 = *(_DWORD *)(v13 + 72);
            if ( (v68 & 1) == 0 )
              goto LABEL_18;
          }
          *(_QWORD *)(v13 + 768) = v68 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v13 + 760);
          goto LABEL_19;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x36u, 2u, "%s: null param", v46, v47, v48, v49, v50, v51, v52, v53, "wma_update_peer_phymode");
    }
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid peer bw update %d, self bw %d",
             v58,
             v59,
             v60,
             v61,
             v62,
             v63,
             v64,
             v65,
             "wma_process_update_opmode",
             *a2,
             ch_width_from_phy_mode);
  }
LABEL_30:
  wma_set_peer_param(a1, (__int64)a2 + 6, 4u, v36, *((unsigned __int16 *)a2 + 2));
  result = wma_get_fw_wlan_feat_caps(13);
  if ( (result & 1) != 0 )
    return wma_set_peer_param(a1, (__int64)a2 + 6, 0xDu, v34, *((unsigned __int16 *)a2 + 2));
  return result;
}
