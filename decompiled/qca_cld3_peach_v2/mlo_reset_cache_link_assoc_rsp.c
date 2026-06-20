__int64 __fastcall mlo_reset_cache_link_assoc_rsp(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  const char *v23; // x2
  unsigned int v24; // w1

  if ( !a1 )
  {
    v23 = "%s: invalid mlo_dev_ctx";
    v24 = 2;
LABEL_12:
    qdf_trace_msg(0x8Fu, v24, v23, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_reset_cache_link_assoc_rsp");
    return 4;
  }
  qdf_mutex_acquire(a1 + 1656);
  if ( !*(_QWORD *)(a1 + 2224) )
  {
    qdf_mutex_release(a1 + 1656);
    v23 = "%s: sta_ctx not present";
    v24 = 8;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: reset link assoc rsp cache",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "mlo_reset_cache_link_assoc_rsp");
  v18 = *(_QWORD *)(a1 + 2224);
  v19 = *(_QWORD *)(v18 + 136);
  *(_BYTE *)(v18 + 126) = -1;
  if ( v19 )
  {
    _qdf_mem_free(v19);
    *(_QWORD *)(v18 + 136) = 0;
  }
  v20 = *(_QWORD *)(v18 + 160);
  *(_DWORD *)(v18 + 128) = 0;
  *(_BYTE *)(v18 + 150) = -1;
  if ( v20 )
  {
    _qdf_mem_free(v20);
    *(_QWORD *)(v18 + 160) = 0;
  }
  v21 = *(_QWORD *)(v18 + 184);
  *(_DWORD *)(v18 + 152) = 0;
  *(_BYTE *)(v18 + 174) = -1;
  if ( v21 )
  {
    _qdf_mem_free(v21);
    *(_QWORD *)(v18 + 184) = 0;
  }
  *(_DWORD *)(v18 + 176) = 0;
  qdf_mutex_release(a1 + 1656);
  return 0;
}
