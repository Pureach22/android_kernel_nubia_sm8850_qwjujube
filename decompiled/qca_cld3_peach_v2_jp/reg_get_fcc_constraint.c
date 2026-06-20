__int64 __fastcall reg_get_fcc_constraint(
        __int64 a1,
        int a2,
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
  char v20; // w8

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "reg_get_fcc_constraint");
LABEL_6:
    v20 = 0;
    return v20 & 1;
  }
  if ( a2 != 2472 && a2 != 2467 )
    goto LABEL_6;
  v20 = *(_BYTE *)(pdev_obj + 56753);
  return v20 & 1;
}
