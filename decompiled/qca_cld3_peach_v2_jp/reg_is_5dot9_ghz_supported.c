__int64 __fastcall reg_is_5dot9_ghz_supported(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  char v18; // w8

  psoc_obj = reg_get_psoc_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_obj )
  {
    v18 = *(_BYTE *)(psoc_obj + 91097);
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "reg_is_5dot9_ghz_supported");
    v18 = 0;
  }
  return v18 & 1;
}
