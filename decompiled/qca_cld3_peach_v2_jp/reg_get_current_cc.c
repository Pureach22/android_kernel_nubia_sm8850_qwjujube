__int64 __fastcall reg_get_current_cc(
        __int64 a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _WORD *pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w9

  pdev_obj = (_WORD *)reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    qdf_trace_msg(0x51u, 2u, "%s: reg pdev priv is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "reg_get_current_cc");
    return 16;
  }
  v20 = *((unsigned __int8 *)a2 + 4);
  switch ( v20 )
  {
    case 3:
      qdf_mem_copy(a2, pdev_obj + 28352, 3u);
      break;
    case 2:
      *a2 = pdev_obj[28354];
      a2[1] = pdev_obj[28355];
      return 0;
    case 1:
      *a2 = pdev_obj[28356];
      return 0;
  }
  return 0;
}
