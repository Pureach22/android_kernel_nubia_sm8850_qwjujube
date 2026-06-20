__int64 __fastcall wlan_hdd_sta_set_vht_rate(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  unsigned int v21; // w23
  unsigned int v22; // w21
  unsigned int v23; // w22

  qdf_trace_msg(0x33u, 8u, "%s: Rate code %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_sta_set_vht_rate", a2);
  v20 = 0xFFFF;
  if ( a2 == 0xFFFF )
  {
    v21 = 0;
    v22 = 0;
    v23 = 0;
  }
  else
  {
    v22 = (a2 >> 4) & 3;
    v23 = a2 & 0xF;
    v21 = 3;
    v20 = hdd_assemble_rate_code(3u, v22, v23);
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: wmi_vdev_param_fixed_rate val %d rix %d preamble %x nss %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_hdd_sta_set_vht_rate",
    v20,
    v23,
    v21,
    v22);
  return wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 27, v20, 1);
}
