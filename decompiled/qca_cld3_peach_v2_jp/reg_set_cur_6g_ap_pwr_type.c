__int64 __fastcall reg_set_cur_6g_ap_pwr_type(
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
  __int64 pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v20 = "%s: pdev reg component is NULL";
    goto LABEL_5;
  }
  if ( a2 >= 4 )
  {
    v20 = "%s: Unsupported 6G AP power type";
LABEL_5:
    qdf_trace_msg(0x51u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "reg_set_cur_6g_ap_pwr_type");
    return 16;
  }
  *(_DWORD *)(pdev_obj + 58204) = a2;
  return 0;
}
