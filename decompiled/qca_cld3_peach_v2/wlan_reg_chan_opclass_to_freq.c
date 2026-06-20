__int64 __fastcall wlan_reg_chan_opclass_to_freq(
        unsigned __int8 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w3

  v11 = 0;
  if ( a1 && a2 )
    return (unsigned int)reg_chan_opclass_to_freq(a1, a2, a3 & 1, a4, a5, a6, a7, a8, a9, a10, a11);
  return v11;
}
