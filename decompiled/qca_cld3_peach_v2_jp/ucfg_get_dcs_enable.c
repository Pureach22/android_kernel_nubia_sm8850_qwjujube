__int64 __fastcall ucfg_get_dcs_enable(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BYTE *pdev_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  pdev_private_obj = (_BYTE *)wlan_dcs_get_pdev_private_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_private_obj )
  {
    if ( *pdev_private_obj )
      return (unsigned __int8)pdev_private_obj[1];
  }
  else
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs pdev private object is null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_get_dcs_enable");
  }
  return 0;
}
