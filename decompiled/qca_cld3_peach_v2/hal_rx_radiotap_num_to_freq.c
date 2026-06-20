__int64 __fastcall hal_rx_radiotap_num_to_freq(int a1, unsigned int a2)
{
  int v3; // w8

  if ( a2 - 5921 < 0x1D )
    return 5935;
  if ( a2 >> 1 > 0xB9E )
    return (unsigned int)(5 * a1 + 5950);
  if ( (unsigned __int16)a1 == 14 )
    return 2484;
  if ( (unsigned __int16)a1 <= 0xDu )
    return (unsigned int)(5 * a1 + 2407);
  if ( (unsigned __int16)a1 <= 0x1Au )
    return (unsigned int)(20 * a1 + 2212);
  v3 = 5 * a1;
  if ( (unsigned __int16)(a1 - 183) > 0xDu )
    return (unsigned int)(v3 + 5000);
  else
    return (unsigned int)(v3 + 4000);
}
