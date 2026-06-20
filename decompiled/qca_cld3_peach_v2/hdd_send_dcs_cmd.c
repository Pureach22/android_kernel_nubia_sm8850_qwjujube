__int64 __fastcall hdd_send_dcs_cmd(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( (ucfg_is_vdev_level_dcs_supported(a1, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0 )
    return ucfg_wlan_dcs_cmd_for_vdev(a1, a2, a3, v14, v15, v16, v17, v18, v19, v20, v21);
  else
    return ucfg_wlan_dcs_cmd(a1, a2, 1, v14, v15, v16, v17, v18, v19, v20, v21);
}
