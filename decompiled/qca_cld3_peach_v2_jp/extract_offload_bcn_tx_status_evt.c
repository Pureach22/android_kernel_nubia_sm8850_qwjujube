__int64 __fastcall extract_offload_bcn_tx_status_evt(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        _DWORD *a11,
        _DWORD *a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8

  if ( a10 )
  {
    v14 = *a10;
    *a11 = *(_DWORD *)(*a10 + 4);
    *a12 = *(_DWORD *)(v14 + 8);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid offload bcn tx status event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_offload_bcn_tx_status_evt",
      v12,
      v13);
    return 4;
  }
}
