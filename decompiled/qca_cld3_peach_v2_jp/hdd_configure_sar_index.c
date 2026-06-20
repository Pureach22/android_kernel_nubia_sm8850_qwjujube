__int64 __fastcall hdd_configure_sar_index(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x19
  _DWORD *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x21

  if ( !*(_DWORD *)(a1 + 3688) )
    return qdf_trace_msg(0x33u, 8u, "FW SAR version: %d", a3, a4, a5, a6, a7, a8, a9, a10, 0);
  result = _qdf_mem_malloc(0x18u, "hdd_configure_sar_index", 1085);
  if ( result )
  {
    v13 = result;
    v14 = (_DWORD *)_qdf_mem_malloc(0x28u, "hdd_configure_sar_index", 1092);
    if ( !v14 )
    {
LABEL_6:
      _qdf_mem_free(*(_QWORD *)(v13 + 16));
      return _qdf_mem_free(v13);
    }
    *(_QWORD *)(v13 + 16) = v14;
    *(_DWORD *)(v13 + 8) = 1;
    *(_QWORD *)v13 = 0x200000008LL;
    v14[1] = 0;
    v14[6] = 1;
    v14[3] = a2;
    v14[4] = 2;
    v14[8] = a2;
    v14[9] = 2;
    qdf_trace_msg(
      0x33u,
      8u,
      "Configure POW_Limit Index: %d for both the chains",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      a2);
    result = sme_set_sar_power_limits(v23, v24, v25, v26, v27, v28, v29, v30, *(_QWORD *)(a1 + 16), v13);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(0x33u, 2u, "Failed to set sar power limits", v31, v32, v33, v34, v35, v36, v37, v38);
      goto LABEL_6;
    }
    v39 = *(_QWORD *)(a1 + 3848);
    if ( v39 )
    {
      *(_QWORD *)(a1 + 3848) = 0;
      _qdf_mem_free(*(_QWORD *)(v39 + 16));
      result = _qdf_mem_free(v39);
    }
    *(_QWORD *)(a1 + 3848) = v13;
  }
  return result;
}
