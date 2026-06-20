__int64 __fastcall dp_rx_null_q_handle_invalid_peer_id_exception(
        _QWORD *a1,
        unsigned __int8 a2,
        __int64 a3,
        __int64 a4)
{
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x23
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  void (*v27)(void); // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8

  v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1[141] + 74392LL) + 1336LL);
  if ( *((_DWORD *)v7 - 1) != -640867646 )
    __break(0x8228u);
  v8 = v7(a3);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) && (unsigned __int8)wlan_cfg_get_pdev_idx(a1[5], a2) || !a1[9] )
  {
    qdf_trace_msg(
      0x82u,
      8u,
      "%s: %pK: pdev is null for pool_id = %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_rx_null_q_handle_invalid_peer_id_exception",
      a1,
      a2);
    return 0;
  }
  if ( !v8 )
    return 0;
  result = dp_peer_find_hash_find((__int64)a1, (unsigned __int16 *)(v8 + 10), 0, 0xFFu, 4u);
  if ( result )
  {
    v26 = result;
    if ( is_dp_verbose_debug_enabled == 1 )
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: MPDU sw_peer_id & ast_idx is corrupted",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "dp_rx_null_q_handle_invalid_peer_id_exception");
    v27 = *(void (**)(void))(*(_QWORD *)(a1[141] + 74392LL) + 1240LL);
    if ( *((_DWORD *)v27 - 1) != 343547449 )
      __break(0x8228u);
    v27();
    if ( a1 )
    {
      ++a1[1724];
      if ( (*(_BYTE *)(a4 + 68) & 4) != 0 )
        v36 = *(unsigned __int16 *)(a4 + 66);
      else
        v36 = 0;
      a1[1725] += (unsigned int)(*(_DWORD *)(a4 + 112) + v36);
    }
    if ( a4 )
      _qdf_nbuf_free(a4);
    dp_peer_unref_delete(v26, 4u, v28, v29, v30, v31, v32, v33, v34, v35);
    return 1;
  }
  return result;
}
