__int64 __fastcall lim_delete_all_peers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // w8
  __int64 v11; // x20
  int v12; // w8
  __int64 *v13; // x2
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned __int16 v16; // w1
  int v17; // w24
  _WORD *hash_entry; // x0
  __int64 v19; // x23
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char is_mlo_conn; // w0
  __int64 v30; // x1
  __int64 v31; // x21
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
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 result; // x0
  __int64 (__fastcall *v57)(__int64, __int64); // x8
  __int64 v58; // x0
  __int64 v59; // x1
  __int64 v60; // [xsp+0h] [xbp-30h] BYREF
  __int64 v61; // [xsp+8h] [xbp-28h] BYREF
  __int64 v62; // [xsp+10h] [xbp-20h]
  __int64 v63; // [xsp+18h] [xbp-18h]
  __int64 v64; // [xsp+20h] [xbp-10h]
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 88);
  v11 = *(_QWORD *)(a1 + 8608);
  WORD2(v60) = -1;
  LODWORD(v60) = -1;
  if ( v10 != 6 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: stop_bss_reason: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "lim_delete_all_peers",
      *(unsigned int *)(a1 + 10052),
      v60);
    if ( *(_DWORD *)(a1 + 10052) == 524 )
    {
      v12 = *(_DWORD *)(a1 + 88);
      WORD2(v61) = -1;
      LODWORD(v61) = -1;
      if ( v12 != 1 )
        goto LABEL_7;
      v13 = &v61;
      v14 = v11;
      v15 = 14;
    }
    else
    {
      v13 = &v60;
      v14 = v11;
      v15 = 3;
    }
    lim_send_disassoc_mgmt_frame(v14, v15, v13, a1, 0);
  }
LABEL_7:
  if ( *(unsigned __int16 *)(a1 + 376) >= 2u )
  {
    v16 = 1;
    v17 = 1;
    do
    {
      hash_entry = (_WORD *)dph_get_hash_entry(v11, v16, a1 + 360);
      if ( hash_entry )
      {
        v19 = (__int64)hash_entry;
        if ( (*hash_entry & 1) != 0 )
        {
          lim_mlo_notify_peer_disconn(a1, hash_entry);
          v20 = lim_del_sta(v11, v19, 0, a1);
          if ( v20 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: lim_del_sta failed with Status: %d",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "lim_delete_all_peers",
              v20);
          }
          else
          {
            lim_delete_dph_hash_entry(v11, (unsigned __int8 *)(v19 + 350), *(unsigned __int16 *)(v19 + 348), a1);
            is_mlo_conn = lim_is_mlo_conn(a1, v19);
            v30 = *(unsigned __int16 *)(v19 + 348);
            if ( (is_mlo_conn & 1) != 0 )
              lim_release_mlo_conn_idx(v11, v30, a1, 0);
            else
              lim_release_peer_idx(v11, v30, a1);
          }
        }
      }
      v16 = (unsigned __int8)++v17;
    }
    while ( *(unsigned __int16 *)(a1 + 376) > (unsigned int)(unsigned __int8)v17 );
  }
  v31 = *(_QWORD *)(a1 + 16);
  v63 = 0;
  v64 = 0;
  v62 = 0;
  if ( v31 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev id is %d for disconnect/deauth cmd",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "lim_flush_all_peer_from_serialization_queue",
      *(unsigned __int8 *)(a1 + 10));
    v63 = v31;
    HIDWORD(v62) = 6;
    v61 = 0x300000000LL;
    LOBYTE(v64) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v61, v32, v33, v34, v35, v36, v37, v38, v39);
    qdf_mem_set(&v61, 0x20u, 0);
    v63 = v31;
    HIDWORD(v62) = 6;
    v61 = 0x200000000LL;
    LOBYTE(v64) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v61, v40, v41, v42, v43, v44, v45, v46, v47);
    qdf_mem_set(&v61, 0x20u, 0);
    v63 = v31;
    HIDWORD(v62) = 6;
    v61 = 0x500000000LL;
    LOBYTE(v64) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v61, v48, v49, v50, v51, v52, v53, v54, v55);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "lim_flush_all_peer_from_serialization_queue");
  }
  result = lim_disconnect_complete(a1, 0);
  v57 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 21648);
  if ( v57 )
  {
    v58 = *(_QWORD *)(v11 + 21624);
    v59 = *(unsigned __int8 *)(a1 + 10);
    if ( *((_DWORD *)v57 - 1) != -1344763252 )
      __break(0x8228u);
    result = v57(v58, v59);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
