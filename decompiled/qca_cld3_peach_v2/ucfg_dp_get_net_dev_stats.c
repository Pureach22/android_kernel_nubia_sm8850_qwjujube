_QWORD *__fastcall ucfg_dp_get_net_dev_stats(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20

  if ( a1 )
  {
    result = (_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( result )
      return qdf_mem_copy(a2, (const void *)(result[4] + 2888LL), 0xB8u);
  }
  else
  {
    result = (_QWORD *)qdf_trace_msg(
                         0x45u,
                         2u,
                         "%s: vdev is null",
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         "dp_get_vdev_priv_obj");
  }
  v20 = jiffies;
  if ( ucfg_dp_get_net_dev_stats___last_ticks - jiffies + 125 < 0 )
  {
    result = (_QWORD *)qdf_trace_msg(
                         0x45u,
                         2u,
                         "%s: DP link not found",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         "ucfg_dp_get_net_dev_stats");
    ucfg_dp_get_net_dev_stats___last_ticks = v20;
  }
  return result;
}
