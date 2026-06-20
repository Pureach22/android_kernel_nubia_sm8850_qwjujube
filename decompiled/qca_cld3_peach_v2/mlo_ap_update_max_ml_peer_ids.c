__int64 __fastcall mlo_ap_update_max_ml_peer_ids(unsigned int a1, unsigned int a2)
{
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w21
  __int64 v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( mlo_ctx )
  {
    v13 = *(unsigned __int16 *)(mlo_ctx + 344);
    v14 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx + 128);
    if ( a2 )
      v23 = a2;
    else
      v23 = 1024;
    *(_WORD *)(v14 + 344) = v23;
    qdf_trace_msg(
      0x8Fu,
      4u,
      "%s: max_ml_peer_ids update from: %d to: %d for pdev: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlo_ap_update_max_ml_peer_ids",
      v13,
      v23,
      a1);
    qdf_trace_msg(
      0x8Fu,
      4u,
      "%s: max_peer support from target obtained :%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "mlo_ap_update_max_ml_peer_ids",
      a2);
    qdf_mutex_release(v14 + 128);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLO context is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_ap_update_max_ml_peer_ids");
    return 4;
  }
}
