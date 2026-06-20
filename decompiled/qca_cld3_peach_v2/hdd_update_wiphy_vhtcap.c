__int64 __fastcall hdd_update_wiphy_vhtcap(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[3];
  LODWORD(v31) = 0;
  BYTE4(v31) = 0;
  v11 = *(_QWORD *)(v10 + 328);
  if ( v11 )
  {
    wlan_mlme_get_vht_for_24ghz(*a1, (_BYTE *)&v31 + 4);
    if ( BYTE4(v31) == 1 )
    {
      wlan_mlme_cfg_get_vht_tx_mcs_map(*a1, &v31);
      *(_WORD *)(v11 + 64) = v31;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: 2GHz band disabled, skipping capability population",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_update_2g_wiphy_vhtcap");
  }
  v20 = a1[3];
  BYTE4(v31) = 0;
  LODWORD(v31) = 0;
  v21 = *(_QWORD *)(v20 + 336);
  if ( v21 )
  {
    if ( (unsigned int)wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(*a1, (_BYTE *)&v31 + 4) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get tx_bfee_ant_supp",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_update_5g_wiphy_vhtcap");
    *(_DWORD *)(v21 + 56) |= (BYTE4(v31) << 13) | 0x10000;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Updated wiphy vhtcap:0x%x, CSNAntSupp:%d, NumSoundDim:%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_update_5g_wiphy_vhtcap",
      v31,
      v32);
    wlan_mlme_cfg_get_vht_rx_mcs_map(*a1, &v31);
    *(_WORD *)(v21 + 60) = v31;
    result = wlan_mlme_cfg_get_vht_tx_mcs_map(*a1, &v31);
    *(_WORD *)(v21 + 64) = v31;
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: 5GHz band disabled, skipping capability population",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "hdd_update_5g_wiphy_vhtcap");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
