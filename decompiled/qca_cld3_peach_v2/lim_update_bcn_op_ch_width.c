__int64 __fastcall lim_update_bcn_op_ch_width(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  result = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return qdf_trace_msg(
             0x35u,
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
             "lim_update_bcn_op_ch_width");
  if ( *(_DWORD *)(result + 24252) != a2 )
  {
    *(_DWORD *)(result + 24252) = a2;
    wlan_mlme_update_ch_width_from_ap(result, 1);
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: update vdev %d bcn eht/he/vht op chn width %d",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "lim_update_bcn_op_ch_width",
             *(unsigned __int8 *)(a1 + 168),
             a2);
  }
  return result;
}
