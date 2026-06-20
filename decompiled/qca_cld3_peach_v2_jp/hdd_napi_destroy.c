__int64 __fastcall hdd_napi_destroy(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 all; // x8
  int v11; // w27
  _QWORD *context; // x0
  _QWORD *v13; // x21
  unsigned int v14; // w20
  unsigned int i; // w24
  int v16; // w26
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  all = hdd_napi_ctx;
  if ( !hdd_napi_ctx )
  {
    if ( !_cds_get_context(61, (__int64)"hdd_napi_get_all", a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      hdd_napi_ctx = 0;
LABEL_16:
      if ( _cds_get_context(61, (__int64)"hdd_napi_destroy", a2, a3, a4, a5, a6, a7, a8, a9) )
        v14 = hif_napi_cpu_deinit();
      else
        v14 = 0;
LABEL_18:
      hdd_napi_ctx = 0;
      return v14;
    }
    all = hif_napi_get_all();
    hdd_napi_ctx = all;
    if ( !all )
      goto LABEL_16;
  }
  v11 = *(_DWORD *)(all + 28);
  if ( !v11 )
    goto LABEL_16;
  context = _cds_get_context(61, (__int64)"hdd_napi_destroy", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v13 = context;
    v14 = 0;
    for ( i = 1; i != 13; ++i )
    {
      v16 = 1 << (i - 1);
      if ( (v11 & v16) != 0 )
      {
        if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD))hif_napi_destroy)(v13, i, a1) & 0x80000000) != 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: cannot destroy napi %d: (pipe:%d), f=%d\n",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "hdd_napi_destroy",
            i - 1,
            i,
            a1);
        }
        else
        {
          ++v14;
          v11 &= ~v16;
        }
      }
    }
    if ( !v11 )
      goto LABEL_18;
  }
  else
  {
    return 0;
  }
  return v14;
}
