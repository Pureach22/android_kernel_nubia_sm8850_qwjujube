__int64 __fastcall dp_rx_tm_get_pending(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 (*v9)(void); // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned int v20; // w19

  if ( !result )
    return result;
  if ( !*(_QWORD *)result )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_soc_get_dp_txrx_handle");
    return 0;
  }
  v9 = *(__int64 (**)(void))(**(_QWORD **)result + 624LL);
  if ( !v9 )
    return 0;
  if ( *((_DWORD *)v9 - 1) != -1355198606 )
    __break(0x8228u);
  result = v9();
  if ( result )
  {
    v18 = *(unsigned __int8 *)(result + 16);
    if ( *(_BYTE *)(result + 16) )
    {
      v19 = *(_QWORD *)(result + 40);
      v20 = 0;
      do
      {
        if ( *(_QWORD *)v19 )
          v20 += *(_DWORD *)(*(_QWORD *)v19 + 456LL);
        --v18;
        v19 += 8;
      }
      while ( v18 );
      if ( v20 )
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: pending frames in thread queue %d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_rx_tm_get_pending",
          v20);
        return v20;
      }
    }
    return 0;
  }
  return result;
}
