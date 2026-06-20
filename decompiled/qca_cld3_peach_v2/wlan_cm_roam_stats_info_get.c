__int64 __fastcall wlan_cm_roam_stats_info_get(
        __int64 a1,
        __int64 *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x9
  unsigned int v33; // w22
  unsigned int v34; // w23
  _QWORD *v35; // x12
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  __int64 v46; // x24
  unsigned int v47; // w28
  _QWORD *v48; // x1

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_cm_roam_stats_info_get");
    return 4;
  }
  v22 = ext_hdl;
  if ( !*(_DWORD *)(ext_hdl + 23600) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Enhanced roam stats not supported",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_cm_roam_stats_info_get");
    return 11;
  }
  qdf_mutex_acquire(ext_hdl + 23608);
  v31 = *(unsigned int *)(v22 + 23600);
  if ( !(_DWORD)v31 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: valid num: %d, start index:%u",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_cm_roam_stats_info_get",
      0,
      0);
LABEL_22:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Enhanced roam stats not existed",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_cm_roam_stats_info_get");
    qdf_mutex_release(v22 + 23608);
    return 4;
  }
  v32 = 0;
  v33 = 0;
  v34 = *(_DWORD *)(v22 + 23600);
  v35 = *(_QWORD **)(v22 + 23592);
  do
  {
    if ( *v35 )
    {
      if ( *v35 < *(_QWORD *)(*(_QWORD *)(v22 + 23592) + 1840LL * v33) )
        v33 = v32;
    }
    else
    {
      --v34;
    }
    ++v32;
    v35 += 230;
  }
  while ( v31 != v32 );
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: valid num: %d, start index:%u",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wlan_cm_roam_stats_info_get",
    v34,
    v33);
  if ( !v34 )
    goto LABEL_22;
  v45 = _qdf_mem_malloc(1840LL * v34, "wlan_cm_roam_stats_info_get", 4936);
  if ( v45 )
  {
    v46 = v45;
    v47 = 0;
    do
    {
      v48 = (_QWORD *)(*(_QWORD *)(v22 + 23592) + 1840LL * v33);
      if ( *v48 )
        memcpy((void *)(v46 + 1840LL * v47++), v48, 0x730u);
      if ( v33 + 1 == *(_DWORD *)(v22 + 23600) )
        v33 = 0;
      else
        ++v33;
    }
    while ( v47 < v34 );
    *a3 = v34;
    *a2 = v46;
    qdf_mutex_release(v22 + 23608);
    return 0;
  }
  else
  {
    qdf_mutex_release(v22 + 23608);
    return 2;
  }
}
