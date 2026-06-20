__int64 __fastcall get_station_stats_cb(int *a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  _QWORD *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  unsigned int v24; // w21
  size_t v25; // x22
  unsigned int v26; // w24
  _QWORD *v28; // x25
  __int64 v29; // x0
  __int64 v30; // x0
  void *v31; // x0
  int v32; // w8
  unsigned int v33; // w23
  void *v34; // x0
  int v35; // w8
  unsigned int v36; // w23
  void *v37; // x0
  int v38; // w8
  unsigned int v39; // w23
  void *v40; // x0
  void *v41; // x0
  __int64 v42; // x9
  __int64 v43; // x10

  v4 = osif_request_get(a2);
  if ( !v4 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v5, v6, v7, v8, v9, v10, v11, v12, "get_station_stats_cb");
  v13 = v4;
  v14 = (_QWORD *)osif_request_priv(v4);
  if ( !*((_QWORD *)a1 + 12) || !*((_QWORD *)a1 + 16) )
  {
    qdf_trace_msg(0x48u, 8u, "%s: Invalid stats", v15, v16, v17, v18, v19, v20, v21, v22, "get_station_stats_cb");
    goto LABEL_16;
  }
  v23 = a1[30];
  v24 = 104 * a1[22];
  v25 = (unsigned int)(3 * v23);
  if ( *((_QWORD *)a1 + 7) )
  {
    v26 = 24 * a1[12];
    if ( !v24 )
      goto LABEL_15;
  }
  else
  {
    v26 = 0;
    if ( !v24 )
    {
LABEL_15:
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid stats, summary %d rssi %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "get_station_stats_cb",
        v24,
        (unsigned int)v25);
      goto LABEL_16;
    }
  }
  if ( !v23 )
    goto LABEL_15;
  if ( !v14[12] && !v14[16] && !v14[7] )
  {
    v28 = v14;
    v29 = _qdf_mem_malloc((unsigned int)(104 * a1[22]), "get_station_stats_cb", 625);
    v28[12] = v29;
    if ( !v29 )
      goto LABEL_16;
    v30 = _qdf_mem_malloc(v25, "get_station_stats_cb", 629);
    v28[16] = v30;
    if ( !v30 )
      goto LABEL_16;
    if ( v26 )
    {
      v31 = (void *)_qdf_mem_malloc(v26, "get_station_stats_cb", 634);
      v28[7] = v31;
      if ( !v31 )
        goto LABEL_16;
      qdf_mem_copy(v31, *((const void **)a1 + 7), v26);
    }
    v32 = *a1;
    if ( *a1 && *((_QWORD *)a1 + 1) )
    {
      v33 = 12672 * v32;
      v34 = (void *)_qdf_mem_malloc((unsigned int)(12672 * v32), "get_station_stats_cb", 644);
      v28[1] = v34;
      if ( !v34 )
        goto LABEL_16;
      qdf_mem_copy(v34, *((const void **)a1 + 1), v33);
    }
    v35 = a1[47];
    if ( v35 && *((_QWORD *)a1 + 24) )
    {
      v36 = 8 * v35;
      v37 = (void *)_qdf_mem_malloc((unsigned int)(8 * v35), "get_station_stats_cb", 654);
      v28[24] = v37;
      if ( !v37 )
        goto LABEL_16;
      qdf_mem_copy(v37, *((const void **)a1 + 24), v36);
    }
    v38 = a1[50];
    if ( v38 && *((_QWORD *)a1 + 26) )
    {
      v39 = 84 * v38;
      v40 = (void *)_qdf_mem_malloc((unsigned int)(84 * v38), "get_station_stats_cb", 664);
      v28[26] = v40;
      if ( !v40 )
        goto LABEL_16;
      *((_DWORD *)v28 + 50) = a1[50];
      qdf_mem_copy(v40, *((const void **)a1 + 26), v39);
    }
    v41 = (void *)v28[16];
    *((_DWORD *)v28 + 22) = a1[22];
    *((_DWORD *)v28 + 30) = a1[30];
    *((_DWORD *)v28 + 34) = a1[34];
    *((_DWORD *)v28 + 35) = a1[35];
    *((_DWORD *)v28 + 36) = a1[36];
    *((_DWORD *)v28 + 12) = a1[12];
    qdf_mem_copy(v41, *((const void **)a1 + 16), (unsigned int)v25);
    qdf_mem_copy((void *)v28[12], *((const void **)a1 + 12), v24);
    v43 = *((_QWORD *)a1 + 21);
    v42 = *((_QWORD *)a1 + 22);
    *((_DWORD *)v28 + 46) = a1[46];
    v28[21] = v43;
    v28[22] = v42;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: invalid context cookie %pK request %pK",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "get_station_stats_cb",
    a2,
    v13);
LABEL_16:
  osif_request_complete(v13);
  return osif_request_put(v13);
}
