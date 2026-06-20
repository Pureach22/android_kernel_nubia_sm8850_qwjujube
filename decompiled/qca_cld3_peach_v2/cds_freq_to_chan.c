unsigned __int64 __fastcall cds_freq_to_chan(int a1)
{
  if ( (unsigned int)(a1 - 2408) <= 0x4B )
    return (unsigned __int8)(a1 - 103) / 5u;
  if ( a1 == 2484 )
    return 14;
  if ( (unsigned int)(a1 - 2408) > 0xA1F )
    return (unsigned int)(a1 - 5000) / 5uLL;
  return (a1 - 2512) / 0x14u + 15;
}
