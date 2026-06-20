__int64 __fastcall hdd_disable_sar(
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
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21

  if ( !*(_DWORD *)(a1 + 3688) )
    return qdf_trace_msg(0x33u, 8u, "FW SAR version: %d", a2, a3, a4, a5, a6, a7, a8, a9, 0);
  result = _qdf_mem_malloc(0x18u, "hdd_disable_sar", 1028);
  if ( result )
  {
    v11 = result;
    v12 = _qdf_mem_malloc(0x28u, "hdd_disable_sar", 1035);
    if ( !v12 )
    {
LABEL_6:
      _qdf_mem_free(*(_QWORD *)(v11 + 16));
      return _qdf_mem_free(v11);
    }
    *(_QWORD *)(v11 + 16) = v12;
    *(_QWORD *)v11 = 0x200000000LL;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)(v12 + 12) = 0x200000000LL;
    *(_QWORD *)(v12 + 32) = 0x200000000LL;
    *(_DWORD *)(v12 + 4) = 0;
    *(_DWORD *)(v12 + 24) = 1;
    qdf_trace_msg(0x33u, 8u, "Disable the SAR limit index for both the chains", v13, v14, v15, v16, v17, v18, v19, v20);
    result = sme_set_sar_power_limits(v21, v22, v23, v24, v25, v26, v27, v28);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(0x33u, 2u, "Failed to set sar power limits", v29, v30, v31, v32, v33, v34, v35, v36);
      goto LABEL_6;
    }
    v37 = *(_QWORD *)(a1 + 3872);
    if ( v37 )
    {
      *(_QWORD *)(a1 + 3872) = 0;
      _qdf_mem_free(*(_QWORD *)(v37 + 16));
      result = _qdf_mem_free(v37);
    }
    *(_QWORD *)(a1 + 3872) = v11;
  }
  return result;
}
