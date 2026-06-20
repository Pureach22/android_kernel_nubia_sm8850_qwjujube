__int64 __fastcall sap_get_bw_score_multiplier(unsigned int a1)
{
  if ( a1 >= 8 )
    return 1;
  else
    return (unsigned int)(0x1001010808040201uLL >> (8 * (unsigned __int8)a1));
}
