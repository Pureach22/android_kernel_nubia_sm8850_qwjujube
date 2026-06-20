__int64 __fastcall wma_peer_send_phymode(
        __int64 result,
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
  __int64 v11; // x26
  unsigned __int16 *v12; // x27
  __int64 *v13; // x22
  unsigned int v14; // w19
  __int64 v16; // x0
  int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w28
  unsigned int v27; // w21
  unsigned int v28; // w23
  unsigned int v29; // w25
  unsigned int ch_width_from_phy_mode; // w24
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int8 v40; // w28
  int v41; // w27
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
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
  __int64 v74; // x4
  __int64 v75; // x5
  __int64 v76; // x6
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned __int16 v85; // [xsp+24h] [xbp-1Ch]
  unsigned __int16 v86[2]; // [xsp+28h] [xbp-18h] BYREF
  int v87; // [xsp+2Ch] [xbp-14h]
  unsigned int v88; // [xsp+30h] [xbp-10h]
  unsigned int v89; // [xsp+34h] [xbp-Ch]
  __int64 v90; // [xsp+38h] [xbp-8h]

  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 68) != 1 )
  {
    v11 = result;
    result = (__int64)_cds_get_context(54, (__int64)"wma_peer_send_phymode", a3, a4, a5, a6, a7, a8, a9, a10);
    if ( result )
    {
      v12 = *(unsigned __int16 **)(v11 + 40);
      v13 = (__int64 *)result;
      v14 = *(_DWORD *)(a2 + 72);
      if ( wlan_reg_is_24ghz_ch_freq(*v12) )
      {
        if ( v14 == 2 || *((_DWORD *)v12 + 7) == 2 )
          v16 = 1;
        else
          v16 = 2;
      }
      else
      {
        v16 = 0;
      }
      v17 = wma_peer_phymode(
              v16,
              1,
              v14 - 5 < 6,
              *((unsigned int *)v12 + 6),
              v14 - 11 < 0xA,
              v14 - 21 < 0xA,
              v14 - 31 < 0xA);
      v26 = v17 - 31;
      v27 = v17;
      if ( (unsigned int)(v17 - 31) <= 9 )
      {
        v85 = v12[16];
        goto LABEL_16;
      }
      if ( v17 != v14 )
      {
        v85 = 0;
LABEL_16:
        wlan_peer_set_phymode(a2, v17);
        v28 = wmi_host_to_fw_phymode(v27);
        v29 = *(unsigned __int8 *)(v11 + 168);
        ch_width_from_phy_mode = wmi_get_ch_width_from_phy_mode(*v13, v28);
        if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
        {
          v86[0] = 0;
          v31 = target_if_wmi_chan_width_to_phy_ch_width(ch_width_from_phy_mode);
          if ( v26 > 9 )
          {
            v88 = ch_width_from_phy_mode;
            v89 = v29;
            v87 = 4;
            if ( (unsigned int)wmi_set_peer_param_send(*v13) )
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: vdev_id: %d peer set failed, id %d, val %d",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "wma_set_peer_param",
                v29,
                4,
                ch_width_from_phy_mode);
          }
          else
          {
            v40 = v31;
            wlan_reg_extract_puncture_by_bw(
              *((_DWORD *)v12 + 6),
              v85,
              *v12,
              *((unsigned __int8 *)v12 + 4),
              v31,
              v86,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39);
            v41 = v40 | (v86[0] << 8);
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: new punct: 0x%x",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "wma_set_bw_n_phy_mode");
            wlan_util_vdev_peer_set_param_send(
              v11,
              (unsigned __int8 *)(a2 + 48),
              0,
              v41,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57);
          }
          v88 = v28;
          v89 = v29;
          v87 = 13;
          if ( !(unsigned int)wmi_set_peer_param_send(*v13) )
            goto LABEL_28;
          v74 = v29;
          v75 = 13;
          v76 = v28;
        }
        else
        {
          v88 = v28;
          v89 = v29;
          v87 = 13;
          if ( (unsigned int)wmi_set_peer_param_send(*v13) )
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: vdev_id: %d peer set failed, id %d, val %d",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "wma_set_peer_param",
              v29,
              13,
              v28);
          v88 = ch_width_from_phy_mode;
          v89 = v29;
          v87 = 4;
          if ( !(unsigned int)wmi_set_peer_param_send(*v13) )
            goto LABEL_28;
          v74 = v29;
          v75 = 4;
          v76 = ch_width_from_phy_mode;
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: vdev_id: %d peer set failed, id %d, val %d",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "wma_set_peer_param",
          v74,
          v75,
          v76);
LABEL_28:
        result = qdf_trace_msg(
                   0x36u,
                   8u,
                   "%s: FW phymode %d old phymode %d new phymode %d bw %d macaddr %02x:%02x:%02x:**:**:%02x",
                   v66,
                   v67,
                   v68,
                   v69,
                   v70,
                   v71,
                   v72,
                   v73,
                   "wma_peer_send_phymode",
                   v28,
                   v14,
                   v27,
                   ch_width_from_phy_mode,
                   *(unsigned __int8 *)(a2 + 48),
                   *(unsigned __int8 *)(a2 + 49),
                   *(unsigned __int8 *)(a2 + 50),
                   *(unsigned __int8 *)(a2 + 53));
        goto LABEL_29;
      }
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: Ignore update as old %d and new %d phymode are same for mac %02x:%02x:%02x:**:**:%02x",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "wma_peer_send_phymode",
                 v14,
                 v14,
                 *(unsigned __int8 *)(a2 + 48),
                 *(unsigned __int8 *)(a2 + 49),
                 *(unsigned __int8 *)(a2 + 50),
                 *(unsigned __int8 *)(a2 + 53));
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
