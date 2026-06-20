__int64 __fastcall wlan_get_t2lm_mapping_status(__int64 a1, char *a2)
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
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w8
  unsigned int v17; // w23
  char *v18; // x0
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
  if ( !bsspeer )
  {
    qdf_trace_msg(0x99u, 2u, "%s: peer not found", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_get_t2lm_mapping_status");
    return 29;
  }
  v13 = *(_DWORD **)(bsspeer + 784);
  v14 = bsspeer;
  if ( !v13 )
    goto LABEL_15;
  v15 = v13[55];
  if ( v15 && v13[68] != 1 || v13[81] != 2 )
  {
    if ( v15 == 4 )
    {
      v17 = 0;
    }
    else
    {
      qdf_mem_copy(a2, v13 + 55, 0x34u);
      v17 = 1;
    }
    if ( v13[68] != 4 )
    {
      v18 = &a2[52 * v17++];
      qdf_mem_copy(v18, v13 + 68, 0x34u);
    }
    if ( v13[81] == 4 )
    {
      if ( !v17 )
        goto LABEL_15;
    }
    else
    {
      qdf_mem_copy(&a2[52 * v17], v13 + 81, 0x34u);
    }
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: peer level T2LM info",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_get_t2lm_mapping_status");
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x99u,
    2u,
    "%s: Both DL/UL and BIDI T2LM IEs should not be present at the same time",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_get_peer_t2lm_mapping_status");
LABEL_15:
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: vdev level T2LM info",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_get_t2lm_mapping_status");
  v19 = *(_QWORD *)(a1 + 1360);
  qdf_mutex_acquire(v19 + 2528);
  qdf_mem_copy(a2, (const void *)(v19 + 2244), 0x34u);
  qdf_mutex_release(v19 + 2528);
LABEL_18:
  wlan_objmgr_peer_release_ref(v14, 0x5Au, v20, v21, v22, v23, v24, v25, v26, v27);
  return 0;
}
