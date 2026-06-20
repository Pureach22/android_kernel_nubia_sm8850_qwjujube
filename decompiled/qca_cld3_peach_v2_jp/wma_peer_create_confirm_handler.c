__int64 __fastcall wma_peer_create_confirm_handler(
        __int64 *a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 **v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x25
  int v31; // w8
  int v32; // w9
  __int64 **v33; // x21
  _QWORD *v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x24
  unsigned int v44; // w23
  __int64 v45; // x22
  const char *v46; // x2
  __int64 result; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w2
  unsigned int v57; // w19
  _QWORD *peer_by_mac; // x0
  __int64 v59; // x22
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int v68; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v69; // [xsp+Ch] [xbp-14h]
  __int64 v70; // [xsp+18h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_peer_create_confirm_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = (__int64 **)_cds_get_context(
                      71,
                      (__int64)"wma_peer_create_confirm_handler",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( !a2 )
  {
    v46 = "%s: Invalid peer create conf evt buffer";
    goto LABEL_12;
  }
  v30 = *a2;
  v31 = *(_DWORD *)(*a2 + 8);
  v32 = *(_DWORD *)(*a2 + 12);
  v68 = v31;
  v69 = v32;
  if ( !(v31 | (unsigned __int16)v32) || !(v69 ^ 0xFFFF | ~v68) || (v31 & 1) != 0 )
  {
    v46 = "%s: Invalid bssid";
LABEL_12:
    qdf_trace_msg(0x36u, 2u, v46, v22, v23, v24, v25, v26, v27, v28, v29, "wma_peer_create_confirm_handler");
    goto LABEL_13;
  }
  v33 = v21;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev:%d Peer create confirm for bssid: %02x:%02x:%02x:**:**:%02x",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wma_peer_create_confirm_handler",
    *(unsigned int *)(v30 + 4),
    (unsigned __int8)v31,
    BYTE1(v31),
    BYTE2(v31),
    BYTE1(v32));
  v34 = wma_find_remove_req_msgtype((__int64)a1, *(_DWORD *)(v30 + 4), 0, 0x11C5u);
  if ( v34 )
  {
    v43 = v34[23];
    v44 = *((unsigned __int8 *)v34 + 205);
    v45 = (__int64)v34;
    qdf_mc_timer_stop((__int64)v34);
    qdf_mc_timer_destroy(v45);
    switch ( v44 )
    {
      case 0xAu:
        goto LABEL_9;
      case 0xFu:
        wma_send_msg_high_priority(a1, 4130, v43, 0);
        _qdf_mem_free(v45);
        goto LABEL_17;
      case 0xCu:
LABEL_9:
        _qdf_mem_free(v43);
        _qdf_mem_free(v45);
        wma_pasn_handle_peer_create_conf(a1, &v68, v44, *(unsigned int *)(v30 + 16), *(unsigned int *)(v30 + 4));
LABEL_17:
        wma_release_wakelock(a1 + 391);
        result = 0;
        goto LABEL_14;
    }
    _qdf_mem_free(v43);
    _qdf_mem_free(v45);
    wma_release_wakelock(a1 + 391);
    if ( !*(_DWORD *)(v30 + 16) )
    {
      if ( v33 )
      {
        peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], &v68, 8u);
        if ( peer_by_mac )
        {
          v59 = (__int64)peer_by_mac;
          wma_cdp_peer_setup(v33, v48, v49, v50, v51, v52, v53, v54, v55);
          wlan_objmgr_peer_release_ref(v59, 8u, v60, v61, v62, v63, v64, v65, v66, v67);
          result = 0;
          v56 = 0;
          if ( !context )
            goto LABEL_14;
          goto LABEL_20;
        }
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: DP SOC context is NULL",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "wma_peer_create_confirm_handler");
      }
    }
    wma_remove_peer(a1, &v68, *(_DWORD *)(v30 + 4), *(_DWORD *)(v30 + 16) != 0, v48, v49, v50, v51, v52, v53, v54, v55);
    v56 = 16;
    result = 4294967274LL;
    if ( !context )
      goto LABEL_14;
LABEL_20:
    v57 = result;
    lim_send_peer_create_resp((__int64)context, *(unsigned int *)(v30 + 4), v56);
    result = v57;
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev:%d Failed to lookup peer create request msg",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wma_peer_create_confirm_handler",
    *(unsigned int *)(v30 + 4));
LABEL_13:
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
