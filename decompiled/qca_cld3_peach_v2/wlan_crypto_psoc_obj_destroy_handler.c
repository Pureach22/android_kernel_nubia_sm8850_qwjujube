__int64 __fastcall wlan_crypto_psoc_obj_destroy_handler(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  unsigned int v22; // w19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    crypto_flush_entries(a1);
    _qdf_mem_free(*(_QWORD *)(v11 + 80));
    *(_QWORD *)(v11 + 80) = 0;
    qdf_mutex_destroy(v11);
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: failed to get crypto obj in psoc",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_crypto_hash_deinit");
  }
  v12 = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( v12 )
  {
    v21 = v12;
    v22 = wlan_objmgr_psoc_component_obj_detach(a1, 14, v12);
    if ( v22 )
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: failed to detach crypto psoc priv object",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_crypto_psoc_obj_destroy_handler");
    _qdf_mem_free(v21);
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: failed to get crypto obj in psoc",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_crypto_psoc_obj_destroy_handler");
    return 16;
  }
  return v22;
}
