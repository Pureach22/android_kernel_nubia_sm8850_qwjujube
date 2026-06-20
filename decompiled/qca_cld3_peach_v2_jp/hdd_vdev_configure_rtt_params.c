__int64 __fastcall hdd_vdev_configure_rtt_params(__int64 a1)
{
  int v2; // w8
  unsigned int v3; // w19
  unsigned int v4; // w21
  int v5; // w22
  int v6; // w23
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 fine_time_meas_cap; // x0
  char rsta_11az_ranging_cap; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  int v20; // w6
  int v21; // w5
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  char v39[4]; // [xsp+8h] [xbp-28h] BYREF
  int v40; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v41; // [xsp+10h] [xbp-20h] BYREF
  __int64 v42; // [xsp+18h] [xbp-18h]
  __int64 v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 16);
  v3 = *(unsigned __int8 *)(a1 + 104);
  v40 = 0;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  if ( v2 )
  {
    v4 = 0;
    if ( v2 != 1 )
      goto LABEL_15;
    v5 = 64;
    v6 = 128;
    v7 = *(_QWORD *)(a1 + 152);
    if ( v7 )
      goto LABEL_4;
LABEL_6:
    v8 = 0;
    goto LABEL_7;
  }
  v5 = 1;
  v6 = 2;
  v7 = *(_QWORD *)(a1 + 152);
  if ( !v7 )
    goto LABEL_6;
LABEL_4:
  v8 = *(_QWORD *)(v7 + 80);
LABEL_7:
  v39[0] = 0;
  fine_time_meas_cap = ucfg_mlme_get_fine_time_meas_cap(v8, &v40);
  rsta_11az_ranging_cap = wifi_pos_get_rsta_11az_ranging_cap(fine_time_meas_cap);
  v19 = *(unsigned __int8 *)(a1 + 104);
  if ( v40 & v6 | rsta_11az_ranging_cap & 1 )
    v20 = (rsta_11az_ranging_cap & 2) + 1;
  else
    v20 = rsta_11az_ranging_cap & 2;
  if ( (v40 & v5) != 0 )
    v21 = v5;
  else
    v21 = 0;
  LODWORD(v41) = 125;
  HIDWORD(v41) = v20;
  LODWORD(v42) = 154;
  HIDWORD(v42) = v21;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev: %d initiator: %d responder: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hdd_vdev_configure_rtt_params",
    v19);
  ucfg_mlme_is_rtt_bw_downgrade_enabled(v8, v39);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev: %d enable dynamic downgrade RTT packet bandwidth: %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "hdd_vdev_configure_rtt_params",
    *(unsigned __int8 *)(a1 + 104),
    (unsigned __int8)v39[0]);
  LODWORD(v43) = 32788;
  HIDWORD(v43) = (unsigned __int8)v39[0];
  v4 = sme_send_multi_pdev_vdev_set_params(1, v3, &v41, 3);
  if ( v4 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set RTT_RESPONDER,INITIATOR params:%d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "hdd_vdev_configure_rtt_params",
      v4);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v4;
}
