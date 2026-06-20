__int64 __fastcall mlo_free_cache_link_assoc_rsp(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  const char *v26; // x2

  v10 = a2;
  if ( a2 == 255 )
    return 4;
  v11 = *(_QWORD *)(a1 + 1360);
  if ( !v11 )
  {
    v26 = "%s: invalid mlo_dev_ctx";
LABEL_19:
    qdf_trace_msg(0x8Fu, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_free_cache_link_assoc_rsp");
    return 4;
  }
  qdf_mutex_acquire(v11 + 1656);
  v21 = *(_QWORD *)(v11 + 2224);
  if ( !v21 )
  {
    qdf_mutex_release(v11 + 1656);
    v26 = "%s: invalid sta_ctx";
    goto LABEL_19;
  }
  if ( *(unsigned __int8 *)(v21 + 126) == v10 )
  {
    v22 = *(_QWORD *)(v21 + 136);
    *(_BYTE *)(v21 + 126) = -1;
    if ( v22 )
    {
      _qdf_mem_free(v22);
      *(_QWORD *)(v21 + 136) = 0;
    }
    *(_DWORD *)(v21 + 128) = 0;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev %d link %d free from slot %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_free_cache_link_assoc_rsp",
      *(unsigned __int8 *)(a1 + 168),
      v10,
      0);
  }
  if ( *(unsigned __int8 *)(v21 + 150) == v10 )
  {
    v23 = *(_QWORD *)(v21 + 160);
    *(_BYTE *)(v21 + 150) = -1;
    if ( v23 )
    {
      _qdf_mem_free(v23);
      *(_QWORD *)(v21 + 160) = 0;
    }
    *(_DWORD *)(v21 + 152) = 0;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev %d link %d free from slot %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_free_cache_link_assoc_rsp",
      *(unsigned __int8 *)(a1 + 168),
      v10,
      1);
  }
  if ( *(unsigned __int8 *)(v21 + 174) == v10 )
  {
    v24 = *(_QWORD *)(v21 + 184);
    *(_BYTE *)(v21 + 174) = -1;
    if ( v24 )
    {
      _qdf_mem_free(v24);
      *(_QWORD *)(v21 + 184) = 0;
    }
    *(_DWORD *)(v21 + 176) = 0;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev %d link %d free from slot %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_free_cache_link_assoc_rsp",
      *(unsigned __int8 *)(a1 + 168),
      v10,
      2);
  }
  qdf_mutex_release(v11 + 1656);
  return 0;
}
