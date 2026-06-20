__int64 __fastcall mlme_set_chan_switch_in_progress(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BYTE *ext_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  ext_hdl = (_BYTE *)wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    v21 = a2 & 1;
    *ext_hdl = v21;
    mlo_set_chan_switch_in_progress(a1, v21);
    qdf_trace_msg(
      0x1Fu,
      4u,
      "%s: Set chan_switch_in_progress: %d vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "mlme_set_chan_switch_in_progress",
      v21,
      *(unsigned __int8 *)(a1 + 168));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlme_set_chan_switch_in_progress");
    return 16;
  }
}
