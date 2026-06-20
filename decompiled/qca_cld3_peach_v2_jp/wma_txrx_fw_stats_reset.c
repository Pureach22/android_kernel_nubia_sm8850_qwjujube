__int64 __fastcall wma_txrx_fw_stats_reset(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        int a11)
{
  __int64 **context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 **v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  _DWORD *v32; // x8
  __int64 result; // x0
  _QWORD v34[9]; // [xsp+8h] [xbp-48h] BYREF

  v34[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v34, 0, 64);
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_txrx_fw_stats_reset", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v22 = context;
    qdf_mem_set(v34, 0x40u, 0);
    HIDWORD(v34[0]) = a11;
    if ( *v22 )
    {
      v31 = **v22;
      if ( v31 )
      {
        v32 = *(_DWORD **)(v31 + 328);
        if ( v32 )
        {
          if ( *(v32 - 1) != 151513730 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 **, _QWORD, _QWORD *, _QWORD, _QWORD))v32)(v22, a10, v34, 0, 0);
        }
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v23, v24, v25, v26, v27, v28, v29, v30, "cdp_fw_stats_get");
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: SOC context is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_txrx_fw_stats_reset");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
