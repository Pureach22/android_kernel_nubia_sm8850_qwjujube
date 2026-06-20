_QWORD *__fastcall dp_rx_pdev_mon_status_buffers_free(
        unsigned __int8 *a1,
        __int64 a2,
        int *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x19
  __int64 v15; // x20

  if ( (unsigned int)a2 >= 5 )
  {
    __break(0x5512u);
    return (_QWORD *)dp_mon_drop_packets_for_mac(a1, a2, *a3 + 76LL, a4, a3[1]);
  }
  else
  {
    v14 = *((_QWORD *)a1 + 1);
    v15 = v14 + 120LL * (unsigned int)a2;
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Mon RX Status Desc Pool Free pdev[%d]",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_rx_pdev_mon_status_buffers_free",
      *a1,
      v12,
      v13);
    return dp_rx_desc_nbuf_free(v14, (int *)(v15 + 11936), 1);
  }
}
