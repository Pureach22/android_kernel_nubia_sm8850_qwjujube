__int64 __fastcall ap_mlme_vdev_csa_complete(
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
  __int64 v9; // x8
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v9 = *(_QWORD *)(a1 + 504);
  v10 = *(unsigned __int8 *)(v9 + 104);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "ap_mlme_vdev_csa_complete",
    *(unsigned __int8 *)(v9 + 104));
  if ( (lim_is_csa_tx_pending(v10) & 1) != 0 )
    lim_send_csa_tx_complete(v10);
  else
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: CSAIE_TX_COMPLETE_IND already sent",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ap_mlme_vdev_csa_complete");
  return 0;
}
