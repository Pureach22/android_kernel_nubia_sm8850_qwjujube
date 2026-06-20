__int64 __fastcall wlan_send_peer_level_tid_to_link_mapping(
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
  _DWORD *v10; // x21
  int v12; // w22
  __int64 result; // x0
  _DWORD *v14; // x20
  const char *v15; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7

  if ( !a2 )
  {
    v15 = "%s: peer is null";
LABEL_9:
    qdf_trace_msg(0x99u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_send_peer_level_tid_to_link_mapping");
    return 29;
  }
  v10 = *(_DWORD **)(a2 + 784);
  if ( !v10 )
  {
    v15 = "%s: ml peer is null";
    goto LABEL_9;
  }
  if ( v10 == (_DWORD *)-220LL || v10[55] == 4 )
  {
    v12 = 0;
    result = 29;
    v14 = v10 + 68;
    if ( v10 == (_DWORD *)-272LL )
      goto LABEL_13;
LABEL_11:
    if ( *v14 != 4 )
    {
      v12 = 1;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: send peer-level mapping to FW for dir: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_send_peer_level_tid_to_link_mapping",
        1);
      wlan_mlo_dev_t2lm_notify_link_update(a1, (__int64)v14, v32, v33, v34, v35, v36, v37, v38, v39);
      result = wlan_send_tid_to_link_mapping(a1, (__int64)v14, v40, v41, v42, v43, v44, v45, v46, v47);
    }
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: send peer-level mapping to FW for dir: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_send_peer_level_tid_to_link_mapping",
    0);
  wlan_mlo_dev_t2lm_notify_link_update(a1, (__int64)(v10 + 55), v16, v17, v18, v19, v20, v21, v22, v23);
  result = wlan_send_tid_to_link_mapping(a1, (__int64)(v10 + 55), v24, v25, v26, v27, v28, v29, v30, v31);
  v12 = 1;
  v14 = v10 + 68;
  if ( v10 != (_DWORD *)-272LL )
    goto LABEL_11;
LABEL_13:
  if ( v10 == (_DWORD *)-324LL || v10[81] == 4 )
  {
    if ( !v12 )
    {
      v48 = result;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: No peer-level mapping present",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_send_peer_level_tid_to_link_mapping");
      return v48;
    }
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: send peer-level mapping to FW for dir: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_send_peer_level_tid_to_link_mapping",
      2);
    wlan_mlo_dev_t2lm_notify_link_update(a1, (__int64)(v10 + 81), v49, v50, v51, v52, v53, v54, v55, v56);
    return wlan_send_tid_to_link_mapping(a1, (__int64)(v10 + 81), v57, v58, v59, v60, v61, v62, v63, v64);
  }
  return result;
}
