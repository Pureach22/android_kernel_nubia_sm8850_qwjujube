__int64 __fastcall mlo_get_cache_link_assoc_rsp(
        __int64 a1,
        unsigned __int8 a2,
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
  unsigned int v11; // w19
  __int64 v13; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x9
  int v25; // w7
  __int64 v26; // x24
  __int64 v27; // x8
  size_t v28; // x6
  const char *v29; // x2
  unsigned int v30; // w20
  void *v31; // x0
  size_t v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w19

  v11 = a2;
  if ( a2 == 255 )
    return 4;
  v13 = *(_QWORD *)(a1 + 1360);
  if ( !v13 )
  {
    v29 = "%s: invalid mlo_dev_ctx";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v29, a4, a5, a6, a7, a8, a9, a10, a11, "mlo_get_cache_link_assoc_rsp");
    return 4;
  }
  qdf_mutex_acquire(v13 + 1656);
  v24 = *(_QWORD *)(v13 + 2224);
  if ( !v24 )
  {
    qdf_mutex_release(v13 + 1656);
    v29 = "%s: invalid sta_ctx";
    goto LABEL_10;
  }
  if ( *(unsigned __int8 *)(v24 + 126) == v11 )
  {
    v25 = 0;
    v26 = v24 + 120;
    v27 = a1;
    v28 = *(unsigned int *)(v24 + 128);
    if ( !(_DWORD)v28 )
      goto LABEL_19;
  }
  else
  {
    v27 = a1;
    if ( *(unsigned __int8 *)(v24 + 150) == v11 )
    {
      v26 = v24 + 144;
      v25 = 1;
      v28 = *(unsigned int *)(v24 + 152);
      if ( !(_DWORD)v28 )
        goto LABEL_19;
    }
    else
    {
      if ( *(unsigned __int8 *)(v24 + 174) != v11 )
      {
LABEL_20:
        v41 = 4;
        goto LABEL_21;
      }
      v26 = v24 + 168;
      v25 = 2;
      v28 = *(unsigned int *)(v24 + 176);
      if ( !(_DWORD)v28 )
      {
LABEL_19:
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: vdev %d link %d len %d in slot %d !",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "mlo_get_cache_link_assoc_rsp",
          *(unsigned __int8 *)(v27 + 168),
          v11);
        goto LABEL_20;
      }
    }
  }
  if ( !*(_QWORD *)(v26 + 16) )
    goto LABEL_19;
  v30 = v25;
  v31 = (void *)_qdf_mem_malloc(v28, "mlo_get_cache_link_assoc_rsp", 2180);
  *(_QWORD *)(a3 + 8) = v31;
  if ( !v31 )
    goto LABEL_20;
  v32 = *(unsigned int *)(v26 + 8);
  *(_DWORD *)a3 = v32;
  qdf_mem_copy(v31, *(const void **)(v26 + 16), v32);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: vdev %d link %d get assc rsp len %d from slot %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "mlo_get_cache_link_assoc_rsp",
    *(unsigned __int8 *)(a1 + 168),
    v11,
    *(unsigned int *)(v26 + 8),
    v30);
  v41 = 0;
LABEL_21:
  qdf_mutex_release(v13 + 1656);
  return v41;
}
