__int64 __fastcall wma_stats_ext_req(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v12; // x0
  unsigned int v13; // w22
  unsigned int *v14; // x20
  size_t v15; // x2
  __int64 v16; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  __int64 v27; // x21
  __int64 v28; // x0
  char v29; // w22
  __int64 v30; // x22
  __int64 v31; // x0
  char v33; // w23
  unsigned int v34; // w19

  if ( !a1 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: wma handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_stats_ext_req");
    return 16;
  }
  v12 = (unsigned int *)_qdf_mem_malloc(a2[1] + 12LL, "wma_stats_ext_req", 4322);
  if ( !v12 )
    return 2;
  v13 = *a2;
  v14 = v12;
  *v12 = *a2;
  v15 = a2[1];
  v12[1] = v15;
  if ( (_DWORD)v15 )
  {
    qdf_mem_copy(v12 + 3, a2 + 2, v15);
    v13 = *v14;
  }
  v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[3], v13, 8);
  if ( v16 )
  {
    v26 = *(_QWORD *)(v16 + 1360);
    v27 = v16;
    if ( !v26 )
    {
LABEL_18:
      wlan_objmgr_vdev_release_ref(v27, 8u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
      goto LABEL_19;
    }
    v28 = *(_QWORD *)(v26 + 24);
    if ( v28 && (v29 = *(_BYTE *)(v28 + 168), wlan_cm_is_vdev_connected(v28, v18, v19, v20, v21, v22, v23, v24, v25)) )
    {
      v30 = 1LL << v29;
      v31 = *(_QWORD *)(v26 + 32);
      if ( !v31 )
        goto LABEL_17;
    }
    else
    {
      LODWORD(v30) = 0;
      v31 = *(_QWORD *)(v26 + 32);
      if ( !v31 )
      {
LABEL_17:
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: mlo connected links bitmap[0x%x]",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "wma_stats_ext_req_vdev_id_bitmap",
          (unsigned int)v30);
        v14[2] = v30;
        goto LABEL_18;
      }
    }
    v33 = *(_BYTE *)(v31 + 168);
    if ( wlan_cm_is_vdev_connected(v31, v18, v19, v20, v21, v22, v23, v24, v25) )
      LODWORD(v30) = v30 | (1LL << v33);
    goto LABEL_17;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: vdev object is NULL for vdev_id %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wma_stats_ext_req_vdev_id_bitmap",
    v13);
LABEL_19:
  v34 = wmi_unified_stats_ext_req_cmd(*a1);
  _qdf_mem_free((__int64)v14);
  return v34;
}
