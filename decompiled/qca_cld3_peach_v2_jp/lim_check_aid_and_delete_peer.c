void __fastcall lim_check_aid_and_delete_peer(__int64 a1, __int64 a2)
{
  __int64 v4; // x26
  __int64 v5; // x27
  int v6; // w9
  int v7; // w8
  __int16 v8; // w24
  int v9; // w23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int8 *hash_entry; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int8 *v27; // x25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // [xsp+0h] [xbp-20h] BYREF
  int v62; // [xsp+8h] [xbp-18h] BYREF
  __int16 v63; // [xsp+Ch] [xbp-14h]
  int v64; // [xsp+10h] [xbp-10h] BYREF
  __int16 v65; // [xsp+14h] [xbp-Ch]
  __int64 v66; // [xsp+18h] [xbp-8h]

  v4 = 0;
  v5 = a2 + 7252;
  v6 = 1;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  v62 = 0;
  do
  {
    v7 = *(_DWORD *)(v5 + 4 * v4);
    v8 = 32 * v4;
    v9 = 0;
    LODWORD(v61) = v6;
    do
    {
      if ( (v7 & (1 << v9)) != 0 )
      {
        hash_entry = (unsigned __int8 *)dph_get_hash_entry(a1, v8 + (unsigned __int16)v9, a2 + 360);
        if ( hash_entry )
        {
          v27 = hash_entry;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Deleting %02x:%02x:%02x:**:**:%02x",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "lim_check_aid_and_delete_peer",
            hash_entry[338],
            hash_entry[339],
            hash_entry[340],
            hash_entry[343]);
          if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a2 + 16), v28, v29, v30, v31, v32, v33, v34, v35) )
            lim_send_deauth_mgmt_frame(a1, 3u, v27 + 338, a2, 0, v36, v37, v38, v39, v40, v41, v42, v43);
          qdf_mem_copy(&v62, v27 + 338, 6u);
          v65 = v63;
          v64 = v62;
          WORD2(v61) = 0;
          v52 = dph_lookup_hash_entry(
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  a1,
                  (unsigned __int8 *)&v64,
                  (_WORD *)&v61 + 2,
                  a2 + 360);
          if ( v52 && *(_BYTE *)(v52 + 344) == 4 )
            lim_del_sta(a1, v52, 0, a2);
          else
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: TDLS peer %02x:%02x:%02x:**:**:%02x not found",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "lim_tdls_del_sta",
              (unsigned __int8)v64,
              BYTE1(v64),
              BYTE2(v64),
              HIBYTE(v65),
              v61);
          dph_delete_hash_entry(v10, v11, v12, v13, v14, v15, v16, v17, a1, v27 + 338, *((_WORD *)v27 + 168), a2 + 360);
        }
        lim_release_peer_idx(a1, v8 + v9, a2);
        v7 = *(_DWORD *)(v5 + 4 * v4) & ~(1 << v9);
        *(_DWORD *)(v5 + 4 * v4) = v7;
      }
      ++v9;
    }
    while ( v9 != 32 );
    v6 = 0;
    v4 = 1;
  }
  while ( (v61 & 1) != 0 );
  _ReadStatusReg(SP_EL0);
}
