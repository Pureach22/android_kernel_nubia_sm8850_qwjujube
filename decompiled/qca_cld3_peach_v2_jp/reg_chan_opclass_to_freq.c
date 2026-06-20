__int64 __fastcall reg_chan_opclass_to_freq(
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
  __int64 v11; // x20
  char *v13; // x9
  unsigned __int64 v14; // x8
  int v15; // w14
  unsigned __int64 v16; // x10
  char *v17; // x11
  int v18; // t1
  char *v19; // x9
  __int64 v20; // x13
  __int64 v21; // x20

  if ( (a3 & 1) != 0 || (_UNKNOWN *)channel_map == &channel_map_global )
  {
    v13 = &global_op_class;
    v14 = 2496;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_us )
  {
    v13 = &us_op_class;
    v14 = 1920;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_eu )
  {
    v13 = &euro_op_class;
    v14 = 1632;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_china )
  {
    v13 = &china_op_class;
    v14 = 1344;
  }
  else
  {
    if ( (_UNKNOWN *)channel_map != &channel_map_jp )
    {
      v11 = jiffies;
      if ( reg_chan_opclass_to_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: Invalid channel map",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "reg_chan_opclass_to_freq");
        reg_chan_opclass_to_freq___last_ticks = v11;
        return 0;
      }
      return 0;
    }
    v13 = &japan_op_class;
    v14 = 1440;
  }
  v15 = (unsigned __int8)*v13;
  if ( !*v13 )
    return 0;
  v16 = 0;
  v17 = v13;
  while ( v15 != a2 )
  {
    v16 += 96LL;
    if ( v14 <= v16 )
      goto LABEL_30;
    v18 = (unsigned __int8)v17[96];
    v17 += 96;
    v15 = v18;
    if ( !v18 )
      return 0;
  }
  v19 = &v13[v16];
  v20 = 16;
  while ( v14 > v16 + v20 )
  {
    if ( !v19[v20] )
      goto LABEL_21;
    if ( (unsigned __int8)v19[v20] == a1 )
    {
      if ( v14 < (v16 | 0xC) )
        break;
      return *((_DWORD *)v17 + 3) + 5 * (unsigned int)a1;
    }
    if ( ++v20 == 86 )
    {
LABEL_21:
      v21 = jiffies;
      if ( reg_chan_opclass_to_freq___last_ticks_12 - jiffies + 125 >= 0 )
        return 0;
      qdf_trace_msg(0x51u, 2u, "%s: Channel not found", a4, a5, a6, a7, a8, a9, a10, a11, "reg_chan_opclass_to_freq");
      reg_chan_opclass_to_freq___last_ticks_12 = v21;
      return 0;
    }
  }
LABEL_30:
  __break(1u);
  return reg_chan_opclass_to_freq_auto();
}
