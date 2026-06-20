__int64 __fastcall dp_tx_inspect_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x0

  qdf_trace_msg(0x45u, 4u, "%s Tx inspect path", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_inspect_handler");
  if ( a2 )
  {
    ++*(_QWORD *)(a2 + 488);
    v14 = *(_QWORD *)(a3 + 8);
    if ( (*(_BYTE *)(v14 + 68) & 4) != 0 )
      v15 = *(unsigned __int16 *)(v14 + 66);
    else
      v15 = 0;
    *(_QWORD *)(a2 + 496) += (unsigned int)(*(_DWORD *)(v14 + 112) + v15);
  }
  _qdf_nbuf_unmap(*(_QWORD *)(a1 + 24), *(_QWORD *)(a3 + 8), 1);
  v16 = *(_QWORD *)(a3 + 8);
  if ( v16 )
    v16 = _qdf_nbuf_free(v16);
  return dp_tx_desc_release(v16, a3, *(unsigned __int8 *)(a3 + 67));
}
