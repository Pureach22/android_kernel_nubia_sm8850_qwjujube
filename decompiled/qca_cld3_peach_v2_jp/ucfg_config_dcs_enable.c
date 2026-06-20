__int64 __fastcall ucfg_config_dcs_enable(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
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

  result = wlan_dcs_get_pdev_private_obj(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !result )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "ucfg_config_dcs_enable");
  *(_BYTE *)(result + 1) |= a3;
  return result;
}
