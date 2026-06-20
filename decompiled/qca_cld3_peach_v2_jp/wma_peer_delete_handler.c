__int64 __fastcall wma_peer_delete_handler(
        __int64 a1,
        unsigned int **a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x22
  unsigned int v22; // w8
  unsigned int v23; // w9
  __int64 v24; // x21
  __int64 v25; // x4
  _QWORD *v26; // x0
  __int64 v27; // x19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  __int64 v37; // x21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  unsigned int v47; // w1
  __int64 result; // x0
  __int64 v49; // x3
  __int64 v50; // x0
  __int64 v51; // x2
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x20
  __int64 v55; // [xsp+8h] [xbp-18h] BYREF
  __int64 v56; // [xsp+10h] [xbp-10h] BYREF
  __int64 v57; // [xsp+18h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v55) = 0;
  LODWORD(v55) = 0;
  context = _cds_get_context(53, (__int64)"wma_peer_delete_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v46 = "%s: mac context is null";
    goto LABEL_12;
  }
  if ( !a2 || (v21 = *a2) == nullptr )
  {
    v46 = "%s: Invalid vdev delete event buffer";
LABEL_12:
    v47 = 2;
    goto LABEL_13;
  }
  v23 = v21[2];
  v22 = v21[3];
  v24 = (__int64)context;
  WORD2(v56) = v22;
  v25 = v21[1];
  LODWORD(v56) = v23;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Peer Delete Response, vdev %d Peer %02x:%02x:%02x:**:**:%02x",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wma_peer_delete_handler",
    v25,
    (unsigned __int8)v23,
    BYTE1(v23),
    BYTE2(v23),
    BYTE1(v22),
    v55,
    v56,
    v57);
  wlan_roam_debug_log(v21[1], 3u, 0xFFFFu, (__int64)&v56, 0, 0, 0);
  qdf_mem_copy(&v55, &v56, 6u);
  v26 = wma_find_remove_req_msgtype(a1, v21[1], (__int64)&v55, 0x1023u);
  if ( v26 )
  {
    v27 = (__int64)v26;
    wma_release_wakelock(a1 + 3128);
    qdf_mc_timer_stop(v27);
    qdf_mc_timer_destroy(v27);
    v36 = *(unsigned __int8 *)(v27 + 205);
    if ( v36 > 8 )
    {
      if ( *(unsigned __int8 *)(v27 + 205) <= 0xDu )
      {
        if ( v36 == 9 )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: wma delete peer completed vdev %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wma_peer_delete_handler",
            *(unsigned __int8 *)(v27 + 204));
          lim_cm_send_connect_rsp(v24, 0, *(_QWORD *)(v27 + 184), 14, 16, 0, 0);
          cm_free_join_req(*(_QWORD *)(v27 + 184));
        }
        else if ( v36 == 13 )
        {
          wma_pasn_peer_delete_handler(*(_QWORD *)(a1 + 24), &v56, v21[1], *(_QWORD *)(v27 + 184));
        }
        goto LABEL_33;
      }
      if ( v36 != 14 )
      {
        if ( v36 == 17 )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Delete PASN peer completed. Resume BSS peer create",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wma_peer_delete_handler");
          lim_continue_bss_peer_create(*(unsigned __int8 **)(v27 + 184));
        }
        goto LABEL_33;
      }
      v51 = *(_QWORD *)(v27 + 184);
      v52 = a1;
    }
    else
    {
      if ( v36 - 4 < 2 )
      {
        v49 = *(_QWORD *)(v27 + 184);
        v50 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)(v49 + 4));
        if ( (*(_DWORD *)(v50 + 16) & 0xFFFFFFFD) == 0 )
        {
          v54 = *(_QWORD *)(v27 + 184);
          wlan_cm_bss_peer_delete_rsp(v50, *(_DWORD *)v49, v28, v29, v30, v31, v32, v33, v34, v35);
          v53 = v54;
          goto LABEL_32;
        }
        wlan_vdev_mlme_sm_deliver_evt(v50, 0x1Au, 8u, v49, v28, v29, v30, v31, v32, v33, v34, v35);
        goto LABEL_33;
      }
      if ( v36 != 2 )
      {
        if ( v36 == 3 )
        {
          v37 = *(_QWORD *)(v27 + 184);
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Calling vdev detach handler",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wma_peer_delete_handler");
          wma_handle_vdev_detach(a1, *(_QWORD *)v37, v38, v39, v40, v41, v42, v43, v44, v45);
          mlme_vdev_self_peer_delete_resp(*(_QWORD *)v37);
LABEL_30:
          v53 = v37;
LABEL_32:
          _qdf_mem_free(v53);
        }
LABEL_33:
        _qdf_mem_free(v27);
        result = 0;
        goto LABEL_14;
      }
      v37 = *(_QWORD *)(v27 + 184);
      if ( !*(_BYTE *)(v37 + 8) )
        goto LABEL_30;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Sending peer del rsp to umac",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wma_peer_delete_handler");
      v52 = a1;
      v51 = v37;
    }
    wma_send_msg_high_priority(v52, 4132, v51, 0);
    goto LABEL_33;
  }
  v46 = "%s: Peer Delete response is not handled";
  v47 = 8;
LABEL_13:
  qdf_trace_msg(0x36u, v47, v46, v13, v14, v15, v16, v17, v18, v19, v20, "wma_peer_delete_handler");
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
