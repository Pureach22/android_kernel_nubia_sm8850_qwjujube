__int64 __fastcall dp_wdi_event_unsub(
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
  __int64 v13; // x20
  __int64 v14; // x8
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w21
  const char *v20; // x2
  __int64 v21; // x9
  __int64 v22; // x10

  if ( a2 || !a3 || (v13 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "Invalid callback or pdev in %s", a5, a6, a7, a8, a9, a10, a11, a12, "dp_wdi_event_unsub");
    return 4294967274LL;
  }
  v14 = *(_QWORD *)(*(_QWORD *)(v13 + 8) + 20056LL);
  if ( !v14 )
  {
    v18 = a4;
    v20 = "%s: monitor soc is NULL";
    goto LABEL_13;
  }
  v15 = *(_QWORD *)(v14 + 416);
  if ( !v15 || (v16 = *(_DWORD **)(v15 + 456)) == nullptr )
  {
    v18 = a4;
    v20 = "%s: callback not registered";
LABEL_13:
    qdf_trace_msg(0x92u, 8u, v20, a5, a6, a7, a8, a9, a10, a11, a12, "dp_monitor_set_pktlog_wifi3");
    goto LABEL_14;
  }
  v17 = *(_QWORD *)(a1 + 72);
  v18 = a4;
  if ( *(v16 - 1) != 1933913965 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD))v16)(v17, a4, 0);
LABEL_14:
  v21 = *(_QWORD *)(a3 + 16);
  v22 = *(_QWORD *)(a3 + 24);
  if ( !v22 )
  {
    *(_QWORD *)(*(_QWORD *)(v13 + 95032) + 8LL * (v18 - 256)) = v21;
    if ( !v21 )
      goto LABEL_17;
    goto LABEL_16;
  }
  *(_QWORD *)(v22 + 16) = v21;
  if ( v21 )
LABEL_16:
    *(_QWORD *)(v21 + 24) = *(_QWORD *)(a3 + 24);
LABEL_17:
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  return 0;
}
