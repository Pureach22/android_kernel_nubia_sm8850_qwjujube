__int64 __fastcall wlan_mgmt_txrx_beacon_frame_tx(
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
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2

  v10 = *(_QWORD *)(a1 + 88);
  if ( !v10 )
  {
    v24 = "%s: vdev unavailable for peer %pK";
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(v10 + 152);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v24 = "%s: psoc unavailable for peer %pK";
LABEL_12:
    qdf_trace_msg(0x4Bu, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_beacon_frame_tx", a1);
    return 29;
  }
  v13 = *(_QWORD *)(v12 + 2128);
  if ( !v13 )
  {
    qdf_trace_msg(0x4Bu, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_beacon_frame_tx");
    return 29;
  }
  v14 = *(__int64 (**)(void))(v13 + 8);
  if ( !v14 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: mgmt txrx tx op to send beacon frame is NULL for psoc: %pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mgmt_txrx_beacon_frame_tx",
      v12);
    return 16;
  }
  if ( *((_DWORD *)v14 - 1) != 1759603689 )
    __break(0x8228u);
  result = v14();
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Beacon send fail for peer %pK psoc %pK",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_mgmt_txrx_beacon_frame_tx",
      a1,
      v12);
    return 16;
  }
  return result;
}
