__int64 __fastcall sme_get_opclass(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 v24; // w2
  __int64 result; // x0
  __int16 v26; // [xsp+4h] [xbp-Ch] BYREF
  char v27; // [xsp+6h] [xbp-Ah]
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a1 + 21552);
  v27 = 0;
  v26 = 0;
  wlan_reg_read_current_country(v15, &v26, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (a3 & 2) == 0 )
  {
    if ( (a3 & 1) != 0 )
      v24 = 0;
    else
      v24 = 5;
    goto LABEL_7;
  }
  result = wlan_reg_dmn_get_opclass_from_channel(
             (unsigned __int8 *)&v26,
             a2,
             1u,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  *a4 = result;
  if ( !(_BYTE)result )
  {
    v24 = 3;
LABEL_7:
    result = wlan_reg_dmn_get_opclass_from_channel(
               (unsigned __int8 *)&v26,
               a2,
               v24,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23);
    *a4 = result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
