__int64 __fastcall extract_csa_ie_received_ev_params_tlv(
        __int64 a1,
        __int64 *a2,
        _BYTE *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  int v14; // w8
  const char *v16; // x2
  int v17; // w8
  int v18; // w9
  int v19; // w10
  int v20; // w9
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w11
  int v26; // w12
  int v27; // w13
  int v28; // w14
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( !a2 )
  {
    v16 = "%s: Invalid csa event buffer";
LABEL_8:
    qdf_trace_msg(0x31u, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "extract_csa_ie_received_ev_params_tlv");
    return 16;
  }
  v12 = *a2;
  *(_WORD *)(a4 + 24) = *(_DWORD *)(*a2 + 16);
  *(_BYTE *)(a4 + 26) = *(_WORD *)(v12 + 18);
  *(_BYTE *)(a4 + 27) = *(_BYTE *)(v12 + 19);
  *(_WORD *)(a4 + 28) = *(_DWORD *)(v12 + 20);
  if ( (wlan_get_connected_vdev_from_psoc_by_bssid(**(_QWORD **)(a1 + 760), (const void *)(a4 + 24), a3) & 1) == 0 )
  {
    v16 = "%s: VDEV is not connected with BSSID";
    goto LABEL_8;
  }
  v14 = *(_DWORD *)(v12 + 52);
  if ( (v14 & 1) != 0 )
  {
    v17 = *(unsigned __int8 *)(v12 + 27);
    v18 = *(_DWORD *)(a4 + 20);
    v19 = *(unsigned __int8 *)(a4 + 16);
    *(_BYTE *)a4 = v17;
    v20 = v18 | 1;
    *(_BYTE *)(a4 + 8) = *(_BYTE *)(v12 + 26);
  }
  else
  {
    if ( (v14 & 2) == 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: CSA Event error: No CSA IE present",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "extract_csa_ie_received_ev_params_tlv");
      return 4;
    }
    v17 = *(unsigned __int8 *)(v12 + 36);
    *(_BYTE *)a4 = v17;
    *(_BYTE *)(a4 + 8) = *(_BYTE *)(v12 + 34);
    v19 = *(unsigned __int8 *)(v12 + 35);
    v20 = *(_DWORD *)(a4 + 20) | 2;
    *(_BYTE *)(a4 + 16) = v19;
  }
  v21 = *(unsigned __int8 *)(a4 + 24);
  v22 = *(unsigned __int8 *)(a4 + 25);
  v23 = *(unsigned __int8 *)(a4 + 26);
  v24 = *(unsigned __int8 *)(a4 + 29);
  v25 = *(_DWORD *)(a4 + 4);
  v26 = *(_DWORD *)(a4 + 12);
  v27 = *(unsigned __int8 *)(a4 + 17);
  v28 = *(unsigned __int8 *)(a4 + 18);
  *(_DWORD *)(a4 + 20) = v20;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: CSA IE Received: BSSID %02x:%02x:%02x:**:**:%02x chan %d freq %d flag 0x%x width = %d freq1 = %d freq2 = %d op class = %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "extract_csa_ie_received_ev_params_tlv",
    v21,
    v22,
    v23,
    v24,
    v17,
    v25,
    v20,
    v26,
    v27,
    v28,
    v19);
  if ( *(_BYTE *)a4 )
    return 0;
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: CSA Event with channel %d. Ignore !!",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "extract_csa_ie_received_ev_params_tlv",
    0);
  return 16;
}
