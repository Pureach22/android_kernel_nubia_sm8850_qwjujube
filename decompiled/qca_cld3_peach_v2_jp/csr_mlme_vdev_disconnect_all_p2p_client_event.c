__int64 __fastcall csr_mlme_vdev_disconnect_all_p2p_client_event(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(
              52,
              (__int64)"csr_mlme_vdev_disconnect_all_p2p_client_event",
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
  if ( context )
    return csr_roam_call_callback(context, a1, 0, 0x1Fu, 0, v11, v12, v13, v14, v15, v16, v17, v18);
  else
    return 16;
}
