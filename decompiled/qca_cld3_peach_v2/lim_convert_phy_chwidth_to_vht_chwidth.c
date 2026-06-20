__int64 __fastcall lim_convert_phy_chwidth_to_vht_chwidth(unsigned int a1)
{
  if ( a1 >= 8 )
    return 0;
  else
    return (unsigned int)(0x200000302010000uLL >> (8 * (unsigned __int8)a1));
}
