__int64 __fastcall wlan_convert_link_id_to_diag_band(__int64 a1, unsigned __int16 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  unsigned int v12; // w19
  __int64 ap_link_by_link_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  if ( wlan_mlo_get_mlpeer_by_peer_mladdr(a1, v24) )
  {
    v11 = 0;
    v12 = 0;
    while ( 1 )
    {
      if ( (((unsigned __int64)a2 >> v11) & 1) != 0 )
      {
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(v24[0], (unsigned int)v11);
        if ( !ap_link_by_link_id )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: link: %d info does not exist",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "wlan_convert_link_id_to_diag_band",
            (unsigned int)v11);
          goto LABEL_10;
        }
        v22 = wlan_reg_freq_to_band(**(unsigned __int16 **)(ap_link_by_link_id + 32));
        if ( v22 <= 2 )
          v12 |= 1LL << v22;
      }
      if ( ++v11 == 15 )
        goto LABEL_11;
    }
  }
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: ml peer not found",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_convert_link_id_to_diag_band");
LABEL_10:
  v12 = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v12;
}
