__int64 __fastcall cm_csr_send_set_ie(
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
  __int64 cmpt_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( cmpt_obj )
    return csr_send_set_ie(
             *(unsigned __int8 *)(cmpt_obj + 179),
             *(unsigned __int8 *)(cmpt_obj + 180),
             *(unsigned __int8 *)(a1 + 168));
  else
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Failed to get vdev mlme obj!",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "cm_csr_send_set_ie");
}
