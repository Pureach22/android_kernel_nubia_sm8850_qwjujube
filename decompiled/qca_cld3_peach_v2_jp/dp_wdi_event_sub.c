__int64 __fastcall dp_wdi_event_sub(
        __int64 a1,
        char a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x20
  _DWORD *v18; // x8
  __int64 v19; // x0
  unsigned int v20; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w9
  __int64 v31; // x10
  __int64 v32; // x11

  if ( a2 || (v12 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    v13 = "Invalid txrx_pdev in %s";
    goto LABEL_8;
  }
  if ( !a3 )
  {
    v13 = "Invalid callback in %s";
    goto LABEL_8;
  }
  if ( a4 - 306 <= 0xFFFFFFCD )
  {
    v13 = "Invalid event in %s";
LABEL_8:
    qdf_trace_msg(0x45u, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "dp_wdi_event_sub");
    return 4294967274LL;
  }
  v15 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
  if ( !v15 )
  {
    v20 = a4;
    v17 = a3;
    v29 = "%s: monitor soc is NULL";
    goto LABEL_18;
  }
  v16 = *(_QWORD *)(v15 + 416);
  v17 = a3;
  if ( !v16 || (v18 = *(_DWORD **)(v16 + 456)) == nullptr )
  {
    v20 = a4;
    v29 = "%s: callback not registered";
LABEL_18:
    qdf_trace_msg(0x92u, 8u, v29, a5, a6, a7, a8, a9, a10, a11, a12, "dp_monitor_set_pktlog_wifi3");
    goto LABEL_19;
  }
  v19 = *(_QWORD *)(a1 + 72);
  v20 = a4;
  if ( *(v18 - 1) != 1933913965 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, __int64))v18)(v19, a4, 1);
LABEL_19:
  v30 = v20 - 256;
  v31 = *(_QWORD *)(*(_QWORD *)(v12 + 95032) + 8LL * (v20 - 256));
  if ( v31 )
  {
    v32 = *(_QWORD *)(*(_QWORD *)(v12 + 95032) + 8LL * v30);
    while ( v32 != v17 )
    {
      v32 = *(_QWORD *)(v32 + 16);
      if ( !v32 )
      {
        result = 0;
        *(_QWORD *)(v17 + 16) = v31;
        *(_QWORD *)(v17 + 24) = 0;
        *(_QWORD *)(v31 + 24) = v17;
        goto LABEL_25;
      }
    }
    qdf_trace_msg(
      0x45u,
      4u,
      "Duplicate wdi subscribe event detected %s",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_wdi_event_sub");
    return 0;
  }
  else
  {
    result = 0;
    *(_QWORD *)(v17 + 16) = 0;
    *(_QWORD *)(v17 + 24) = 0;
LABEL_25:
    *(_QWORD *)(*(_QWORD *)(v12 + 95032) + 8LL * v30) = v17;
  }
  return result;
}
