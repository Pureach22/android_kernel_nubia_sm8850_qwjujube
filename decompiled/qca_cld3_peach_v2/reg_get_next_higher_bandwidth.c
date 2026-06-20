__int64 __fastcall reg_get_next_higher_bandwidth(unsigned int a1)
{
  if ( a1 > 7 )
    return 8;
  else
    return next_higher_bw[a1];
}
