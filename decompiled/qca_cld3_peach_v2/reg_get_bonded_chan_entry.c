unsigned __int16 *__fastcall reg_get_bonded_chan_entry(
        unsigned int a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  _QWORD *v12; // x10
  unsigned int v13; // w8
  __int64 v14; // x10
  bool v15; // zf
  unsigned int v16; // w9
  char v17; // w12
  unsigned __int16 *result; // x0
  unsigned int v19; // w13

  v11 = a1;
  if ( a2 == 7 )
  {
    v12 = &bw_bonded_array_pair_map;
    v13 = 7;
LABEL_5:
    v14 = v12[1];
    v15 = a2 != 7 || a3 == 0;
    v16 = 0;
    v17 = !v15;
    while ( 1 )
    {
      result = (unsigned __int16 *)(v14 + 4LL * v16);
      if ( (v17 & 1) != 0 )
      {
        if ( *(_DWORD *)(channel_map + 168) <= (unsigned int)v11 && *(_DWORD *)(channel_map + 492) >= (unsigned int)v11 )
        {
          v19 = *result;
          if ( v19 + 150 != a3 )
            goto LABEL_11;
        }
        else
        {
          v19 = *result;
          if ( (result[1] + v19) >> 1 != a3 )
            goto LABEL_11;
        }
        if ( v19 > (unsigned int)v11 )
          goto LABEL_11;
      }
      else if ( *result > (unsigned int)v11 )
      {
        goto LABEL_11;
      }
      if ( result[1] >= (unsigned int)v11 )
        return result;
LABEL_11:
      if ( ++v16 >= v13 )
        goto LABEL_23;
    }
  }
  if ( a2 - 1 > 3 )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Could not find bonded_chan_array for chwidth %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_bonded_chan_entry",
      a2);
  }
  else
  {
    v12 = *(&off_AD8160 + a2 - 1);
    v13 = *((unsigned __int16 *)v12 + 8);
    if ( *((_WORD *)v12 + 8) )
      goto LABEL_5;
LABEL_23:
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_bonded_chan_entry",
      v11);
  }
  return nullptr;
}
