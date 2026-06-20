__int64 __fastcall wlan_mlo_peer_alloc_aid(__int64 a1, char a2, char a3, unsigned int a4)
{
  __int64 mlo_ctx; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v18; // x26
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w23
  unsigned int v28; // w4
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w0
  unsigned int v38; // w7
  unsigned int v39; // w24
  unsigned int v40; // w22
  unsigned int v41; // w27
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x4
  __int64 v51; // x4
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x2
  unsigned int v55; // w19

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s:  MLO mgr context is NULL, assoc id alloc failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_mlo_peer_alloc_aid");
    return 0xFFFF;
  }
  if ( (_BYTE)a4 == 0xFF && (a2 & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s:  is MLO peer %d, link_ix %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_mlo_peer_alloc_aid",
      0,
      255);
    return 0xFFFF;
  }
  v18 = mlo_ctx;
  qdf_mutex_acquire(mlo_ctx + 64);
  v27 = *(unsigned __int16 *)(a1 + 256);
  v28 = *(unsigned __int16 *)(a1 + 258);
  if ( v27 > v28 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MAX AID %d is less than start aid %d ",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "_wlan_mlo_peer_alloc_aid");
LABEL_8:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLO aid allocation failed (reached max)",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_mlo_peer_alloc_aid");
    v37 = 0xFFFF;
    goto LABEL_20;
  }
  v38 = (unsigned __int16)(v28 - v27) / 3u;
  v39 = v27 + 2 * v38;
  v40 = v38 + v27;
  v41 = (unsigned __int16)((unsigned __int16)(v28 - v27) / 3u + v27);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: max_aid = %d start_aid = %d tot_aid = %d pool_1_max_aid = %d aid_end1 = %d aid_end2 = %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "_wlan_mlo_peer_alloc_aid",
    v41,
    (unsigned __int16)(v27 + 2 * ((unsigned __int16)(v28 - v27) / 3u)));
  if ( v41 == v40 && v41 <= (unsigned __int16)v39 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: T2LM peer = %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "_wlan_mlo_peer_alloc_aid",
      a3 & 1);
    v50 = a2 & 1;
    if ( (a3 & 1) != 0 )
    {
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))wlan_mlo_alloc_aid)(
              a1,
              v40,
              v39,
              a4,
              v50);
      if ( (_WORD)v37 != 0xFFFF )
        goto LABEL_20;
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))wlan_mlo_alloc_aid)(
              a1,
              v39,
              *(unsigned __int16 *)(a1 + 258),
              a4,
              a2 & 1);
      if ( (_WORD)v37 != 0xFFFF )
        goto LABEL_20;
      v51 = a2 & 1;
      v52 = a1;
      v53 = v40;
      v54 = v27;
    }
    else
    {
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))wlan_mlo_alloc_aid)(
              a1,
              v27,
              v40,
              a4,
              v50);
      if ( (_WORD)v37 != 0xFFFF )
        goto LABEL_20;
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))wlan_mlo_alloc_aid)(
              a1,
              v39,
              *(unsigned __int16 *)(a1 + 258),
              a4,
              a2 & 1);
      if ( (_WORD)v37 != 0xFFFF )
        goto LABEL_20;
      v51 = a2 & 1;
      v52 = a1;
      v53 = v39;
      v54 = v40;
    }
  }
  else
  {
    v54 = *(unsigned __int16 *)(a1 + 258);
    v51 = a2 & 1;
    v52 = a1;
    v53 = v27;
  }
  v37 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))wlan_mlo_alloc_aid)(v52, v53, v54, a4, v51);
  if ( (_WORD)v37 == 0xFFFF )
    goto LABEL_8;
LABEL_20:
  v55 = v37;
  qdf_mutex_release(v18 + 64);
  return v55;
}
