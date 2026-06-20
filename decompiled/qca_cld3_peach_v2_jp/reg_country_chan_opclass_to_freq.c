__int64 __fastcall reg_country_chan_opclass_to_freq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        unsigned __int8 a11,
        unsigned __int8 a12,
        char a13)
{
  int v13; // w23
  char *class_from_country; // x0
  char *v18; // x8
  __int64 v19; // x9
  __int64 v21; // x25
  __int64 v22; // x5
  char *v23; // x21
  __int64 i; // x8
  __int64 v25; // x21

  v13 = a12;
  if ( (unsigned int)a12 - 131 >= 7 )
    class_from_country = reg_get_class_from_country(a10, a1, a2, a3, a4, a5, a6, a7, a8);
  else
    class_from_country = &global_op_class;
  v18 = class_from_country;
  do
  {
    if ( !*v18 )
      break;
    if ( (unsigned __int8)*v18 == v13 )
    {
      v19 = 16;
      while ( v18[v19] )
      {
        if ( (unsigned __int8)v18[v19] == a11 )
          return *((_DWORD *)v18 + 3) + 5 * (unsigned int)a11;
        if ( ++v19 == 86 )
          break;
      }
    }
    v18 += 96;
  }
  while ( v18 );
  v21 = jiffies;
  if ( reg_country_chan_opclass_to_freq___last_ticks - jiffies + 125 < 0 )
  {
    v22 = a12;
    v23 = class_from_country;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Not found ch %d in op class %d ch list, strict %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "reg_country_chan_opclass_to_freq",
      a11,
      v22,
      a13 & 1);
    class_from_country = v23;
    reg_country_chan_opclass_to_freq___last_ticks = v21;
    if ( (a13 & 1) != 0 )
      return 0;
  }
  else if ( (a13 & 1) != 0 )
  {
    return 0;
  }
  while ( 2 )
  {
    if ( *class_from_country )
    {
      for ( i = 16; i != 86; ++i )
      {
        if ( !class_from_country[i] )
          break;
        if ( (unsigned __int8)class_from_country[i] == a11 )
          return *((_DWORD *)class_from_country + 3) + 5 * (unsigned int)a11;
      }
      class_from_country += 96;
      if ( class_from_country )
        continue;
    }
    break;
  }
  v25 = jiffies;
  if ( reg_country_chan_opclass_to_freq___last_ticks_15 - jiffies + 125 >= 0 )
    return 0;
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: Got invalid freq 0 for ch %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "reg_country_chan_opclass_to_freq",
    a11);
  reg_country_chan_opclass_to_freq___last_ticks_15 = v25;
  return 0;
}
