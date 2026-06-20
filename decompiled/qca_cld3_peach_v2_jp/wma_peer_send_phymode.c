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
  __int64 v11; // x23
  unsigned __int16 *v12; // x21
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
  __int64 v26; // x6
  const char *v27; // x2
  __int64 v28; // x7
  int v29; // w8
  __int64 v30; // x4
  __int64 v31; // x5
  unsigned int v32; // w21
  unsigned int v33; // w0
  unsigned int v34; // w25
  unsigned int v35; // w23
  unsigned int ch_width_from_phy_mode; // w24
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // [xsp+8h] [xbp-38h]
  int v57; // [xsp+10h] [xbp-30h]
  int v58; // [xsp+18h] [xbp-28h]

  _ReadStatusReg(SP_EL0);
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
      v17 = wma_peer_phymode(v16, 1, v14 - 5 < 6, *((unsigned int *)v12 + 6), v14 - 11 < 0xA, v14 - 21 < 0xA, 0);
      if ( v17 == v14 )
      {
        v26 = *(unsigned __int8 *)(a2 + 48);
        v27 = "%s: Ignore update as old %d and new %d phymode are same for mac %02x:%02x:%02x:**:**:%02x";
        v28 = *(unsigned __int8 *)(a2 + 49);
        v29 = *(unsigned __int8 *)(a2 + 50);
        v56 = *(unsigned __int8 *)(a2 + 53);
        v30 = v14;
        v31 = v14;
LABEL_24:
        result = qdf_trace_msg(
                   0x36u,
                   8u,
                   v27,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   "wma_peer_send_phymode",
                   v30,
                   v31,
                   v26,
                   v28,
                   v29,
                   v56,
                   v57,
                   v58);
        goto LABEL_25;
      }
      v32 = v17;
      wlan_peer_set_phymode(a2, v17);
      v33 = wmi_host_to_fw_phymode(v32);
      v34 = *(unsigned __int8 *)(v11 + 104);
      v35 = v33;
      ch_width_from_phy_mode = wmi_get_ch_width_from_phy_mode(*v13, v33);
      if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
      {
        target_if_wmi_chan_width_to_phy_ch_width(ch_width_from_phy_mode);
        if ( (unsigned int)wmi_set_peer_param_send(*v13) )
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: vdev_id: %d peer set failed, id %d, val %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wma_set_peer_param",
            v34,
            4,
            ch_width_from_phy_mode);
        if ( !(unsigned int)wmi_set_peer_param_send(*v13) )
          goto LABEL_23;
        v45 = v34;
        v46 = 13;
        v47 = v35;
      }
      else
      {
        if ( (unsigned int)wmi_set_peer_param_send(*v13) )
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: vdev_id: %d peer set failed, id %d, val %d",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "wma_set_peer_param",
            v34,
            13,
            v35);
        if ( !(unsigned int)wmi_set_peer_param_send(*v13) )
          goto LABEL_23;
        v45 = v34;
        v46 = 4;
        v47 = ch_width_from_phy_mode;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: vdev_id: %d peer set failed, id %d, val %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wma_set_peer_param",
        v45,
        v46,
        v47);
LABEL_23:
      v29 = *(unsigned __int8 *)(a2 + 48);
      v27 = "%s: FW phymode %d old phymode %d new phymode %d bw %d macaddr %02x:%02x:%02x:**:**:%02x";
      v30 = v35;
      v31 = v14;
      v26 = v32;
      v28 = ch_width_from_phy_mode;
      v58 = *(unsigned __int8 *)(a2 + 53);
      v57 = *(unsigned __int8 *)(a2 + 50);
      v56 = *(unsigned __int8 *)(a2 + 49);
      goto LABEL_24;
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
