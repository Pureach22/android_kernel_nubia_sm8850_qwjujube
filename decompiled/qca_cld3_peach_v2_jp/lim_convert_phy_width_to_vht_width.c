__int64 __fastcall lim_convert_phy_width_to_vht_width(unsigned int a1)
{
  unsigned int v1; // w8

  if ( a1 <= 2 )
    v1 = a1 == 2;
  else
    v1 = 2;
  if ( a1 == 4 )
    return 3;
  else
    return v1;
}
