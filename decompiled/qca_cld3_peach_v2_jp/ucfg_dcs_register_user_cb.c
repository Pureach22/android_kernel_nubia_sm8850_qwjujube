__int64 __fastcall ucfg_dcs_register_user_cb(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
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
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  result = wlan_dcs_get_pdev_private_obj(a1, a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "ucfg_dcs_register_user_cb");
  *(_BYTE *)(result + 368) = a3;
  *(_QWORD *)(result + 376) = a4;
  return result;
}
