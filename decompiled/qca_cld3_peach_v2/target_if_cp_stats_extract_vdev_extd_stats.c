__int64 __fastcall target_if_cp_stats_extract_vdev_extd_stats(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  __int64 v15; // x0
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  int v26; // w23
  unsigned int vdev_prb_fils_stats; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  unsigned int v37; // w20

  v11 = *(unsigned int *)(a2 + 60);
  *(_DWORD *)(a3 + 188) = v11;
  if ( !(_DWORD)v11 )
    return 0;
  if ( (unsigned int)v11 >= 7 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: num_vdev_extd_stats is invalid: %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_cp_stats_extract_vdev_extd_stats");
    return 4;
  }
  v15 = _qdf_mem_malloc(8 * v11, "target_if_cp_stats_extract_vdev_extd_stats", 926);
  *(_QWORD *)(a3 + 192) = v15;
  if ( !v15 )
    return 2;
  v16 = _qdf_mem_malloc(28LL * *(unsigned int *)(a3 + 188), "target_if_cp_stats_extract_vdev_extd_stats", 930);
  if ( v16 )
  {
    v25 = v16;
    if ( !*(_DWORD *)(a3 + 188) )
    {
LABEL_11:
      _qdf_mem_free(v25);
      return 0;
    }
    v26 = 0;
    while ( 1 )
    {
      vdev_prb_fils_stats = wmi_extract_vdev_prb_fils_stats(a1);
      if ( vdev_prb_fils_stats )
        break;
      v36 = 8LL * (unsigned __int8)v26++;
      *(_BYTE *)(*(_QWORD *)(a3 + 192) + v36) = *(_DWORD *)v25;
      *(_BYTE *)(*(_QWORD *)(a3 + 192) + v36 + 1) = *(_BYTE *)(v25 + 20);
      *(_DWORD *)(*(_QWORD *)(a3 + 192) + v36 + 4) = *(_DWORD *)(v25 + 24);
      if ( *(_DWORD *)(a3 + 188) <= (unsigned int)(unsigned __int8)v26 )
        goto LABEL_11;
    }
    v37 = vdev_prb_fils_stats;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: wmi_extract_vdev_extd_stats failed",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "target_if_cp_stats_extract_vdev_extd_stats");
    _qdf_mem_free(v25);
  }
  else
  {
    v37 = 2;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: malloc failed for vdev extended stats",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_cp_stats_extract_vdev_extd_stats");
  }
  _qdf_mem_free(*(_QWORD *)(a3 + 192));
  *(_QWORD *)(a3 + 192) = 0;
  return v37;
}
