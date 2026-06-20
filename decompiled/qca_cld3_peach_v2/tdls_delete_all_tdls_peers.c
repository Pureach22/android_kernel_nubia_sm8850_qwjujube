__int64 __fastcall tdls_delete_all_tdls_peers(__int64 a1, __int64 a2)
{
  __int64 bsspeer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _WORD *v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int16 v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v51; // [xsp+8h] [xbp-38h] BYREF
  _WORD *v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v54)(); // [xsp+20h] [xbp-20h]
  __int64 v55; // [xsp+28h] [xbp-18h]
  __int64 v56; // [xsp+30h] [xbp-10h]
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = nullptr;
  v51 = 0;
  v52 = nullptr;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x10u);
  if ( bsspeer )
  {
    v13 = bsspeer;
    v14 = _qdf_mem_malloc(0xAu, "tdls_delete_all_tdls_peers", 1516);
    if ( v14 )
    {
      v23 = (_WORD *)v14;
      qdf_mem_copy((void *)(v14 + 4), (const void *)(v13 + 48), 6u);
      wlan_objmgr_peer_release_ref(v13, 0x10u, v24, v25, v26, v27, v28, v29, v30, v31);
      v32 = *(_WORD *)(a2 + 340);
      v23[1] = 10;
      *v23 = v32;
      qdf_mem_set(&v51, 0x30u, 0);
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev %d sending delete all peers req to PE",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "tdls_delete_all_tdls_peers",
        *(unsigned __int8 *)(a1 + 168));
      LOWORD(v51) = *v23;
      v52 = v23;
      v54 = tdls_delete_all_tdls_peers_flush_cb;
      v41 = scheduler_post_message_debug(
              0,
              0x35u,
              53,
              (unsigned __int16 *)&v51,
              0x606u,
              (__int64)"tdls_delete_all_tdls_peers");
      if ( v41 )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: post delete all peer req failed, status %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "tdls_delete_all_tdls_peers",
          v41);
        _qdf_mem_free((__int64)v23);
      }
    }
    else
    {
      v41 = 16;
      wlan_objmgr_peer_release_ref(v13, 0x10u, v15, v16, v17, v18, v19, v20, v21, v22);
    }
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: bss peer is null", v5, v6, v7, v8, v9, v10, v11, v12, "tdls_delete_all_tdls_peers");
    v41 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v41;
}
