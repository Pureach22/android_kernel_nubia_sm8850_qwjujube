__int64 __fastcall hdd_convert_phy_bw_to_nl_bw(int a1)
{
  if ( (unsigned int)(a1 - 1) > 6 )
    return 1;
  else
    return dword_A05550[a1 - 1];
}
