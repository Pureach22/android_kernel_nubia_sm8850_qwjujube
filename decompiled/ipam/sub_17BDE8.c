__int64 __fastcall sub_17BDE8(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7)
{
  char v7; // cf
  char v8; // zf
  float v9; // s25
  float v10; // s31

  if ( !v8 & v7 )
    *(float *)&a7 = v9;
  else
    *(float *)&a7 = v10;
  return ipa_wdi_reg_intf(a1, a2, a3, a4, a5, a6, a7);
}
