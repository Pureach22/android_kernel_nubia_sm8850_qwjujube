__int64 __fastcall hdd_we_set_ch_width(
        unsigned __int8 *a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: wmi_vdev_param_chwidth val %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_we_set_ch_width",
    a2);
  if ( a2 <= 4 )
    return hdd_update_channel_width(
             a1,
             a2,
             *((_DWORD *)*(&off_A07928 + a2) + 7),
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             255,
             0);
  qdf_trace_msg(0x33u, 2u, "%s: Invalid ch_width %d", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_we_set_ch_width", a2);
  return 4294967274LL;
}
