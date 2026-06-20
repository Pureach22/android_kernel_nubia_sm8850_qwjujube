__int64 __fastcall sme_radio_tx_mem_free(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( _cds_get_context(54, (__int64)"sme_radio_tx_mem_free", a1, a2, a3, a4, a5, a6, a7, a8) )
    return wma_unified_radio_tx_mem_free();
  else
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid wma handle",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "sme_radio_tx_mem_free");
}
