__int64 __fastcall wma_get_apf_caps_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x21
  _DWORD *v21; // x19
  _DWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  void (__fastcall *v40)(__int64, __int64); // x8
  __int64 v41; // x0

  context = _cds_get_context(53, (__int64)"wma_get_apf_caps_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 4294967274LL;
  if ( context[1812] )
  {
    v20 = context;
    v21 = (_DWORD *)*a10;
    v22 = (_DWORD *)_qdf_mem_malloc(0xCu, "wma_get_apf_caps_event_handler", 4915);
    if ( v22 )
    {
      v31 = (__int64)v22;
      *v22 = v21[1];
      v22[1] = v21[2];
      v22[2] = v21[3];
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: APF capabilities version: %d max apf filter size: %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wma_get_apf_caps_event_handler");
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: sending apf capabilities event to hdd",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wma_get_apf_caps_event_handler");
      v40 = (void (__fastcall *)(__int64, __int64))v20[1812];
      v41 = v20[1786];
      if ( *((_DWORD *)v40 - 1) != -1538054986 )
        __break(0x8228u);
      v40(v41, v31);
      _qdf_mem_free(v31);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Callback not registered",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_get_apf_caps_event_handler");
    return 4294967274LL;
  }
}
