__int64 __fastcall ucfg_wlan_mlme_get_reg_tpc_info(
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
  __int64 cmpt_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    qdf_mem_copy(a2, (const void *)(cmpt_obj + 544), 0x198u);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev component object is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_wlan_mlme_get_reg_tpc_info");
    return 4;
  }
}
