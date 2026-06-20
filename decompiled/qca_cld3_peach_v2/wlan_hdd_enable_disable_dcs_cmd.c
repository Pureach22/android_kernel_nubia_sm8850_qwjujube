__int64 __fastcall wlan_hdd_enable_disable_dcs_cmd(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a4 == 1 )
    ucfg_config_dcs_disable(a1, a2, 2, a5, a6, a7, a8, a9, a10, a11, a12);
  else
    ucfg_config_dcs_enable(a1, a2, 2, a5, a6, a7, a8, a9, a10, a11, a12);
  return hdd_send_dcs_cmd(a1, a2, a3, v15, v16, v17, v18, v19, v20, v21, v22);
}
