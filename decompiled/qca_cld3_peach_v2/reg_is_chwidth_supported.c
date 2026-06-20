__int64 __fastcall reg_is_chwidth_supported(
        __int64 a1,
        unsigned int a2,
        bool *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 result; // x0

  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_obj )
  {
    v22 = pdev_obj;
    result = 0;
    *a3 = 0;
    if ( a2 <= 7 )
    {
      *a3 = (*((_QWORD *)*(&off_AD81C8 + a2) + 1) & *(_QWORD *)(v22 + 56768)) != 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_is_chwidth_supported");
    return 16;
  }
  return result;
}
