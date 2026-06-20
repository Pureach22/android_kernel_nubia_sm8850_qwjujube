__int64 __fastcall wma_save_bss_params(__int64 a1, unsigned __int8 *a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  unsigned int v22; // w20
  const char *v23; // x2
  const char *v24; // x3
  unsigned int v25; // w0
  unsigned int v26; // w1
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w8
  int v38; // w9

  v3 = wma_vdev_set_he_config(a1, a2[151], a2);
  context = _cds_get_context(71, (__int64)"wma_cdp_find_peer_by_addr", v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !context )
  {
    v23 = "%s: Failed to get pdev/soc";
    v24 = "wma_cdp_find_peer_by_addr";
    v25 = 54;
    v26 = 2;
    goto LABEL_12;
  }
  if ( !*context || (v20 = *(_QWORD *)(*context + 72LL)) == 0 )
  {
    v23 = "%s invalid instance";
    v24 = "cdp_find_peer_exist";
    v25 = 69;
    v26 = 1;
LABEL_12:
    qdf_trace_msg(v25, v26, v23, v12, v13, v14, v15, v16, v17, v18, v19, v24);
    v22 = 16;
    goto LABEL_13;
  }
  v21 = *(__int64 (**)(void))(v20 + 16);
  v22 = 16;
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != 454466150 )
      __break(0x8228u);
    if ( (v21() & 1) != 0 )
      v22 = 0;
    else
      v22 = 16;
  }
LABEL_13:
  qdf_mem_copy(a2 + 29, a2, 6u);
  if ( a2 )
  {
    v35 = *a2;
    v36 = a2[1];
    v37 = a2[2];
    v38 = a2[5];
  }
  else
  {
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v38 = 0;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: update_bss %d nw_type %d bssid %02x:%02x:%02x:**:**:%02x status %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wma_save_bss_params",
    a2[292],
    *((unsigned int *)a2 + 2),
    v35,
    v36,
    v37,
    v38,
    v22);
  return v22;
}
