__int64 __fastcall reg_is_regdmn_en302502_applicable(
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
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  char v17; // w0
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  __int16 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v19 = 0;
  if ( (unsigned int)reg_get_curr_regdomain(a1, (unsigned __int16 *)&v19, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Failed to get reg domain",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "reg_is_regdmn_en302502_applicable");
    v17 = 0;
  }
  else
  {
    v17 = reg_en302_502_regdmn(v19);
  }
  _ReadStatusReg(SP_EL0);
  return v17 & 1;
}
