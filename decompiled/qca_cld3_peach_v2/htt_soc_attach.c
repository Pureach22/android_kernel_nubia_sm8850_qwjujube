__int64 __fastcall htt_soc_attach(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x0
  _QWORD *v14; // x0

  v4 = _qdf_mem_malloc(0x88u, "htt_soc_attach", 2580);
  if ( !v4 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: HTT attach failed", v5, v6, v7, v8, v9, v10, v11, v12, "htt_soc_attach");
    return v4;
  }
  v13 = (_QWORD *)_qdf_mem_malloc(0x240u, "htt_soc_attach", 2588);
  *(_QWORD *)(v4 + 24) = v13;
  if ( !v13 )
  {
LABEL_7:
    _qdf_mem_free(v4);
    return 0;
  }
  *v13 = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 32LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 64LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 96LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 128LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 160LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 192LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 224LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 256LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 288LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 320LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 352LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 384LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 416LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 448LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 480LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 512LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 24) + 544LL) = -1;
  v14 = (_QWORD *)_qdf_mem_malloc(0x1A0u, "htt_soc_attach", 2594);
  *(_QWORD *)(v4 + 32) = v14;
  if ( !v14 )
  {
    _qdf_mem_free(*(_QWORD *)(v4 + 24));
    goto LABEL_7;
  }
  *v14 = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 32LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 64LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 96LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 128LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 160LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 192LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 224LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 256LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 288LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 320LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 352LL) = -1;
  *(_QWORD *)(*(_QWORD *)(v4 + 32) + 384LL) = -1;
  *(_QWORD *)(v4 + 8) = a1;
  *(_QWORD *)(v4 + 48) = a2;
  *(_DWORD *)(v4 + 120) = 0;
  *(_QWORD *)(v4 + 128) = 0;
  return v4;
}
