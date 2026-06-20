__int64 __fastcall dp_set_peer_txq_flush_config(
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
  if ( a1 )
    return target_if_peer_txq_flush_config(*(_QWORD *)(a1 + 16));
  qdf_trace_msg(0x45u, 2u, "%s: soc is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_set_peer_txq_flush_config");
  return 4294967274LL;
}
