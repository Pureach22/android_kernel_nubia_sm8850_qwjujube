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
  char v34; // w8
  __int64 v35; // x9
  unsigned int v36; // w8
  __int64 v37; // x9
  __int16 v38; // w8
  __int64 v39; // x4
  unsigned __int8 v40; // w5
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned __int8 v57; // w20
  unsigned __int16 v59; // [xsp+14h] [xbp-3Ch] BYREF
  _QWORD v60[7]; // [xsp+18h] [xbp-38h] BYREF

  v14 = a1 + 0x2000;
  v60[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_tdls_add_sta_rsp";
  v59 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a4, a5, a6, a7, a8, a9, a10, a11);
  v23 = *(unsigned __int8 *)(v14 + 693);
  memset(v60, 0, 48);
  if ( v23 )
  {
    if ( *(_WORD *)(v14 + 496) )
    {
      LOWORD(v60[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v60) )
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
          LOWORD(v60[0]));
    }
  }
  v24 = dph_lookup_hash_entry(v15, v16, v17, v18, v19, v20, v21, v22, a1, (unsigned __int8 *)(a2 + 9), &v59, a3 + 360);
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
    v36 = *(unsigned __int16 *)(a2 + 6);
    if ( v36 >= 0x20 )
    {
      if ( v36 > 0x3F )
      {
LABEL_20:
        lim_release_peer_idx(a1, *(_WORD *)(a2 + 6), a3);
LABEL_21:
        v40 = 16;
        goto LABEL_22;
      }
      v37 = 7256;
      LOBYTE(v36) = v36 - 32;
    }
    else
    {
      v37 = 7252;
    }
    *(_DWORD *)(a3 + v37) &= ~(1 << v36);
    goto LABEL_20;
  }
  v33 = v24;
  if ( *(_DWORD *)(a2 + 100) )
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
    v34 = v59;
    if ( v59 >= 0x20u )
    {
      if ( v59 > 0x3Fu )
        goto LABEL_15;
      v35 = 7256;
      v34 = v59 - 32;
    }
    else
    {
      v35 = 7252;
    }
    *(_DWORD *)(a3 + v35) &= ~(1 << v34);
LABEL_15:
    lim_release_peer_idx(a1, *(_WORD *)(v33 + 336), a3);
    if ( (unsigned int)dph_delete_hash_entry(
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         v48,
                         a1,
                         (unsigned __int8 *)(a2 + 9),
                         *(_WORD *)(v33 + 336),
                         a3 + 360) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to delete Hash entry",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "lim_process_tdls_add_sta_rsp");
    goto LABEL_21;
  }
  v38 = *(_WORD *)v24;
  *(_DWORD *)(v24 + 8) = 14;
  *(_WORD *)v24 = v38 | 1;
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
  v40 = 0;
LABEL_22:
  v57 = lim_send_sme_tdls_add_sta_rsp(a1, *(_BYTE *)(a3 + 10), (const void *)(a2 + 9), *(_BYTE *)(a2 + 104), v39, v40);
  _qdf_mem_free(a2);
  _ReadStatusReg(SP_EL0);
  return v57;
}
