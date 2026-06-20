__int64 __fastcall tdls_find_opclass(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int16 v22; // [xsp+4h] [xbp-Ch] BYREF
  char v23; // [xsp+6h] [xbp-Ah]
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22 = 0;
  if ( a1 )
  {
    if ( (unsigned int)wlan_reg_read_default_country(a1, &v22, a4, a5, a6, a7, a8, a9, a10, a11) )
      result = 0;
    else
      result = wlan_reg_dmn_get_opclass_from_channel(
                 (unsigned __int8 *)&v22,
                 a2,
                 a3,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: psoc is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "tdls_find_opclass");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
