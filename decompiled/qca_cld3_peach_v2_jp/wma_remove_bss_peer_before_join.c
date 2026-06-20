__int64 __fastcall wma_remove_bss_peer_before_join(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 result; // x0
  __int64 v15; // x8
  unsigned int bss_peer_mac; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // [xsp+0h] [xbp-10h] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_18;
  v11 = a1[65];
  if ( !v11 )
    goto LABEL_18;
  v12 = (unsigned __int8)a2;
  WORD2(v53) = 0;
  LODWORD(v53) = 0;
  if ( (unsigned __int8)a2 >= 6u )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev id %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_remove_bss_peer_before_join",
      (unsigned __int8)a2,
      v53,
      v54);
    result = 4;
    goto LABEL_19;
  }
  v15 = *(_QWORD *)(v11 + 488LL * (unsigned __int8)a2);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev, %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_remove_bss_peer_before_join",
      (unsigned __int8)a2,
      v53,
      v54);
    result = 16;
    goto LABEL_19;
  }
  if ( (*(_DWORD *)(v15 + 16) & 0xFFFFFFFD) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: unexpected mode %d vdev %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_remove_bss_peer_before_join",
      v53,
      v54);
    result = 16;
    goto LABEL_19;
  }
  bss_peer_mac = wlan_vdev_get_bss_peer_mac(v15, &v53, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( bss_peer_mac )
  {
    v27 = "%s: Failed to get bssid for vdev_id: %d";
LABEL_13:
    v28 = bss_peer_mac;
    qdf_trace_msg(
      0x36u,
      2u,
      v27,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wma_remove_bss_peer_before_join",
      v12,
      v53,
      v54);
    result = v28;
    goto LABEL_19;
  }
  bss_peer_mac = wma_remove_peer(a1, &v53, a2, 0, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( bss_peer_mac )
  {
    v27 = "%s: wma_remove_peer failed vdev_id:%d";
    goto LABEL_13;
  }
  if ( (cds_get_driver_state(v19, v20, v21, v22, v23, v24, v25, v26) & 8) != 0 )
  {
LABEL_18:
    result = 16;
    goto LABEL_19;
  }
  if ( (wmi_service_enabled(*a1, 0x6Eu, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Wait for the peer delete. vdev_id %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wma_remove_bss_peer_before_join",
      v12,
      v53,
      v54);
    if ( wma_fill_hold_req(a1, a2, 0x1023u, 9u, &v53, a3, 0x1F40u) )
    {
      result = 24;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to allocate request. vdev_id %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wma_remove_bss_peer_before_join",
        v12);
      result = 2;
    }
  }
  else
  {
    result = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
