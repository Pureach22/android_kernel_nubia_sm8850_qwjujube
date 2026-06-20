__int64 __fastcall dp_tx_mon_enqueue_mpdu_nbuf(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w9
  int v17; // w11
  int v18; // w9
  int v19; // w10
  __int64 *v20; // x9
  int v21; // w9

  result = _qdf_nbuf_alloc(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 24LL), 512, 512, 4, 0, "dp_tx_mon_enqueue_mpdu_nbuf", 192);
  if ( result )
  {
    if ( (*(_BYTE *)(a4 + 68) & 4) != 0 )
      v16 = *(unsigned __int16 *)(a4 + 66);
    else
      v16 = 0;
    v17 = *(_DWORD *)(a4 + 112);
    *(_QWORD *)(*(_QWORD *)(result + 216) + *(unsigned int *)(result + 212) + 8LL) = a4;
    v18 = v17 + v16;
    *(_QWORD *)result = 0;
    v19 = *(_DWORD *)(result + 116) + v18;
    *(_DWORD *)(result + 112) += v18;
    *(_DWORD *)(result + 116) = v19;
    v20 = (__int64 *)(a2 + 344LL * a3 + 696);
    if ( *v20 )
      v20 = *(__int64 **)(a2 + 344LL * a3 + 704);
    *v20 = result;
    v21 = *(_DWORD *)(a2 + 344LL * a3 + 712);
    *(_QWORD *)(a2 + 344LL * a3 + 704) = result;
    *(_DWORD *)(a2 + 344LL * a3 + 712) = v21 + 1;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Unable to allocate radiotap buffer\n",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_tx_mon_enqueue_mpdu_nbuf");
    return _qdf_nbuf_free(a4);
  }
  return result;
}
