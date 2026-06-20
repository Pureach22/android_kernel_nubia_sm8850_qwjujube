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
  unsigned __int8 *hash_entry; // x0
  unsigned __int8 *v19; // x23
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 result; // x0
  __int64 (__fastcall *v55)(__int64, __int64); // x8
  __int64 v56; // x0
  __int64 v57; // x1
  __int64 v58; // [xsp+0h] [xbp-30h] BYREF
  __int64 v59; // [xsp+8h] [xbp-28h] BYREF
  __int64 v60; // [xsp+10h] [xbp-20h]
  __int64 v61; // [xsp+18h] [xbp-18h]
  __int64 v62; // [xsp+20h] [xbp-10h]
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 88);
  v11 = *(_QWORD *)(a1 + 8608);
  WORD2(v58) = -1;
  LODWORD(v58) = -1;
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
      v58);
    if ( *(_DWORD *)(a1 + 10052) == 524 )
    {
      v12 = *(_DWORD *)(a1 + 88);
      WORD2(v59) = -1;
      LODWORD(v59) = -1;
      if ( v12 != 1 )
        goto LABEL_7;
      v13 = &v59;
      v14 = v11;
      v15 = 14;
    }
    else
    {
      v13 = &v58;
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
      hash_entry = (unsigned __int8 *)dph_get_hash_entry(v11, v16, a1 + 360);
      if ( hash_entry )
      {
        v19 = hash_entry;
        if ( (*(_WORD *)hash_entry & 1) != 0 )
        {
          v20 = lim_del_sta(v11, (__int64)hash_entry, 0, a1);
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
            lim_delete_dph_hash_entry(v11, v19 + 338, *((unsigned __int16 *)v19 + 168), a1);
            lim_release_peer_idx(v11, *((unsigned __int16 *)v19 + 168), a1);
          }
        }
      }
      v16 = (unsigned __int8)++v17;
    }
    while ( *(unsigned __int16 *)(a1 + 376) > (unsigned int)(unsigned __int8)v17 );
  }
  v29 = *(_QWORD *)(a1 + 16);
  v61 = 0;
  v62 = 0;
  v60 = 0;
  if ( v29 )
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
    v61 = v29;
    HIDWORD(v60) = 6;
    v59 = 0x300000000LL;
    LOBYTE(v62) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v59, v30, v31, v32, v33, v34, v35, v36, v37);
    qdf_mem_set(&v59, 0x20u, 0);
    v61 = v29;
    HIDWORD(v60) = 6;
    v59 = 0x200000000LL;
    LOBYTE(v62) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v59, v38, v39, v40, v41, v42, v43, v44, v45);
    qdf_mem_set(&v59, 0x20u, 0);
    v61 = v29;
    HIDWORD(v60) = 6;
    v59 = 0x500000000LL;
    LOBYTE(v62) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v59, v46, v47, v48, v49, v50, v51, v52, v53);
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
  v55 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 21576);
  if ( v55 )
  {
    v56 = *(_QWORD *)(v11 + 21552);
    v57 = *(unsigned __int8 *)(a1 + 10);
    if ( *((_DWORD *)v55 - 1) != -1344763252 )
      __break(0x8228u);
    result = v55(v56, v57);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
