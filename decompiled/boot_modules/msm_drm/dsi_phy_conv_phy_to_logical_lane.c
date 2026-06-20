__int64 __fastcall dsi_phy_conv_phy_to_logical_lane(unsigned __int8 *a1, unsigned int a2)
{
  if ( a2 > 8 )
    return 4294967274LL;
  if ( a1[4] == a2 )
    return 0;
  if ( a1[5] == a2 )
    return 1;
  if ( a1[6] == a2 )
    return 2;
  if ( a1[7] == a2 )
    return 3;
  return 4;
}
