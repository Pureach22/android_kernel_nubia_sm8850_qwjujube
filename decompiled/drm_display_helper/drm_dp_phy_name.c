const char *__fastcall drm_dp_phy_name(unsigned int a1)
{
  if ( a1 <= 8 )
    return drm_dp_phy_name_phy_names[a1];
  else
    return "<INVALID DP PHY>";
}
