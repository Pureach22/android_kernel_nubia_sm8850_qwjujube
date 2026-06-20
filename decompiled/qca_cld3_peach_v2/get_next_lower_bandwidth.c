__int64 __fastcall get_next_lower_bandwidth(unsigned int a1)
{
  if ( a1 > 7 )
    return 8;
  else
    return get_next_lower_bandwidth_get_next_lower_bw[a1];
}
