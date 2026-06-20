__int64 __fastcall reg_chan_opclass_to_freq_auto(
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
  unsigned __int8 v11; // w19
  unsigned __int8 v12; // w20
  unsigned __int16 v13; // w8

  if ( (unsigned __int8)(a2 + 125) < 7u )
    return (unsigned __int16)reg_chan_opclass_to_freq(a1, a2, 1, a4, a5, a6, a7, a8, a9, a10, a11);
  v11 = a1;
  v12 = a2;
  v13 = reg_chan_opclass_to_freq(a1, a2, a3 & 1, a4, a5, a6, a7, a8, a9, a10, a11);
  a2 = v12;
  a1 = v11;
  if ( !v13 )
    return (unsigned __int16)reg_chan_opclass_to_freq(a1, a2, 1, a4, a5, a6, a7, a8, a9, a10, a11);
  return v13;
}
