__int64 __fastcall sme_update_sta_inactivity_timeout(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *context; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21

  context = _cds_get_context(54, (__int64)"sme_update_sta_inactivity_timeout", a1, a2, a3, a4, a5, a6, a7, a8);
  v12 = _qdf_mem_malloc(8u, "sme_update_sta_inactivity_timeout", 8691);
  if ( !v12 )
    return 16;
  v21 = v12;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: sta_inactivity_timeout: %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "sme_update_sta_inactivity_timeout",
    *(unsigned int *)(a10 + 4));
  *(_BYTE *)v21 = *(_BYTE *)a10;
  *(_DWORD *)(v21 + 4) = *(_DWORD *)(a10 + 4);
  wma_update_sta_inactivity_timeout(context, v21);
  _qdf_mem_free(v21);
  return 0;
}
