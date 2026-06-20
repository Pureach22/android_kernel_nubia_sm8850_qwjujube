__int64 __fastcall wlan_hdd_send_mcc_vdev_quota(
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
  if ( a1 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: send mcc vdev quota to fw: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_send_mcc_vdev_quota",
      a2);
    sme_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 122887, a2, 1);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid adapter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_send_mcc_vdev_quota");
    return 4294967274LL;
  }
}
