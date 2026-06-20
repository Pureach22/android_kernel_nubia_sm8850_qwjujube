__int64 __fastcall cds_chan_to_freq(unsigned __int8 a1)
{
  if ( a1 <= 0xDu )
    return 5 * (unsigned int)a1 + 2407;
  if ( a1 == 14 )
    return 2484;
  if ( a1 <= 0x1Au )
    return 20 * (unsigned int)a1 + 2212;
  if ( a1 == 170 )
    return 5852;
  return 5 * (unsigned int)a1 + 5000;
}
