__int64 __fastcall hdd_napi_create(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 all; // x0
  __int64 v17; // x19
  _QWORD *context; // x0
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 *v36; // x0
  __int64 *v37; // x21
  char napi_enabled; // w20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD *v47; // x0

  if ( _cds_get_context(61, (__int64)"hdd_napi_get_all", a1, a2, a3, a4, a5, a6, a7, a8)
    && (all = hif_napi_get_all()) != 0 )
  {
    v17 = all;
    context = _cds_get_context(61, (__int64)"hdd_napi_create", v8, v9, v10, v11, v12, v13, v14, v15);
    if ( !context )
      return (unsigned int)-14;
    v19 = hif_napi_create(context, hdd_napi_poll, 64, 16, 14);
    if ( (v19 & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: ERR(%d) creating NAPI instances",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_napi_create",
        v19);
      return v19;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: napi instances were created. Map=0x%x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_napi_create",
      v19);
    v36 = _cds_get_context(51, (__int64)"hdd_napi_create", v28, v29, v30, v31, v32, v33, v34, v35);
    if ( !v36 )
      return (unsigned int)-14;
    v37 = v36;
    napi_enabled = ucfg_dp_get_napi_enabled(*v36);
    v47 = _cds_get_context(61, (__int64)"hdd_napi_event", v39, v40, v41, v42, v43, v44, v45, v46);
    if ( v47 )
      v19 = hif_napi_event(v47, 1, napi_enabled & 1);
    else
      v19 = -14;
    *(_DWORD *)(v17 + 36) = *(_DWORD *)(v37[13] + 56);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to retrieve napi structure",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_napi_create");
    return (unsigned int)-14;
  }
  return v19;
}
