__int64 __fastcall wma_peer_flush_tids_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21

  context = _cds_get_context(54, (__int64)"wma_peer_flush_tids_send", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)_wma_validate_handle(context, "wma_peer_flush_tids_send") )
    return 4;
  v17 = *context;
  if ( (unsigned int)_wmi_validate_handle(
                       v17,
                       (__int64)"wma_peer_flush_tids_send",
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16) )
    return 4;
  else
    return wmi_unified_peer_flush_tids_send(v17);
}
