__int64 __fastcall lim_process_tdls_add_sta_rsp(
        __int64 a1,
        __int64 a2,
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
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w8
  __int64 v43; // x9
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w8
  __int64 v53; // x9
  __int16 v54; // w8
  __int64 v55; // x4
  unsigned __int8 v56; // w5
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned __int8 v73; // w20
  unsigned __int16 v75; // [xsp+14h] [xbp-3Ch] BYREF
  _QWORD v76[7]; // [xsp+18h] [xbp-38h] BYREF

  v14 = a1 + 0x2000;
  v76[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_tdls_add_sta_rsp";
  v75 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a4, a5, a6, a7, a8, a9, a10, a11);
  v23 = *(unsigned __int8 *)(v14 + 693);
  memset(v76, 0, 48);
  if ( v23 )
  {
    if ( *(_WORD *)(v14 + 496) )
    {
      LOWORD(v76[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v76) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v76[0]));
    }
  }
  v24 = dph_lookup_hash_entry(v15, v16, v17, v18, v19, v20, v21, v22, a1, (unsigned __int8 *)(a2 + 9), &v75, a3 + 360);
  if ( !v24 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: staMac: %02x:%02x:%02x:**:**:%02x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_process_tdls_add_sta_rsp",
      *(unsigned __int8 *)(a2 + 9),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 11),
      *(unsigned __int8 *)(a2 + 14));
    v52 = *(unsigned __int16 *)(a2 + 6);
    if ( v52 >= 0x20 )
    {
      if ( v52 > 0x3F )
      {
LABEL_20:
        lim_release_peer_idx(v44, v45, v46, v47, v48, v49, v50, v51, a1, *(unsigned __int16 *)(a2 + 6), a3);
LABEL_21:
        v56 = 16;
        goto LABEL_22;
      }
      v53 = 7256;
      LOBYTE(v52) = v52 - 32;
    }
    else
    {
      v53 = 7252;
    }
    *(_DWORD *)(a3 + v53) &= ~(1 << v52);
    goto LABEL_20;
  }
  v33 = v24;
  if ( *(_DWORD *)(a2 + 112) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev:%d TDLS add sta failed",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_process_tdls_add_sta_rsp",
      *(unsigned __int8 *)(a3 + 10));
    v42 = v75;
    if ( v75 >= 0x20u )
    {
      if ( v75 > 0x3Fu )
        goto LABEL_15;
      v43 = 7256;
      v42 = v75 - 32;
    }
    else
    {
      v43 = 7252;
    }
    *(_DWORD *)(a3 + v43) &= ~(1 << v42);
LABEL_15:
    lim_release_peer_idx(v34, v35, v36, v37, v38, v39, v40, v41, a1, *(unsigned __int16 *)(v33 + 348), a3);
    if ( (unsigned int)dph_delete_hash_entry(
                         v57,
                         v58,
                         v59,
                         v60,
                         v61,
                         v62,
                         v63,
                         v64,
                         a1,
                         (unsigned __int8 *)(a2 + 9),
                         *(_WORD *)(v33 + 348),
                         a3 + 360) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to delete Hash entry",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_process_tdls_add_sta_rsp");
    goto LABEL_21;
  }
  v54 = *(_WORD *)v24;
  *(_DWORD *)(v24 + 8) = 14;
  *(_WORD *)v24 = v54 | 1;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev:%d sta_mac: %02x:%02x:%02x:**:**:%02x",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "lim_process_tdls_add_sta_rsp",
    *(unsigned __int8 *)(a3 + 10),
    *(unsigned __int8 *)(a2 + 9),
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned __int8 *)(a2 + 11),
    *(unsigned __int8 *)(a2 + 14));
  v56 = 0;
LABEL_22:
  v73 = lim_send_sme_tdls_add_sta_rsp(a1, *(_BYTE *)(a3 + 10), (const void *)(a2 + 9), *(_BYTE *)(a2 + 116), v55, v56);
  _qdf_mem_free(a2);
  _ReadStatusReg(SP_EL0);
  return v73;
}
