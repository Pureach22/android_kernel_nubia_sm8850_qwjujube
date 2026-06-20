__int64 __fastcall reg_freq_to_chan_for_chlist(
        unsigned int *a1,
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
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 result; // x0
  __int64 v14; // x8
  unsigned int *v15; // x10
  unsigned int v16; // t1
  __int64 v17; // x20
  unsigned int *v18; // x9
  unsigned int *v19; // x10

  if ( a2 - 2412 <= 0x3C )
    return (unsigned __int8)(a2 - 108) / 5u + 1;
  if ( a2 == 2484 )
    return 14;
  if ( a2 - 5180 <= 0x2C1 )
    return (unsigned __int16)(a2 - 5180) / 5u + 36;
  if ( a2 == 5935 )
    return 2;
  if ( a2 - 5955 < 0x489 )
    return (unsigned __int16)(a2 - 5955) / 5u + 1;
  if ( a3 )
  {
    v14 = 0;
    v15 = a1;
    while ( 1 )
    {
      v16 = *v15;
      v15 += 9;
      if ( v16 >= a2 )
        break;
      if ( a3 == ++v14 )
        goto LABEL_18;
    }
  }
  else
  {
    LODWORD(v14) = 0;
  }
  if ( (_DWORD)v14 == a3 )
    goto LABEL_18;
  v18 = &a1[9 * (unsigned int)v14];
  if ( *v18 == a2 )
    return *((unsigned __int8 *)v18 + 4);
  if ( !(_DWORD)v14 )
  {
LABEL_18:
    v17 = jiffies;
    if ( reg_freq_to_chan_for_chlist___last_ticks_104 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: invalid frequency %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "reg_freq_to_chan_for_chlist",
        v11,
        v12);
      result = 0;
      reg_freq_to_chan_for_chlist___last_ticks_104 = v17;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v19 = &a1[9 * (unsigned int)(v14 - 1)];
    if ( *((_BYTE *)v19 + 4) && *((_BYTE *)v18 + 4) )
    {
      return *((unsigned __int8 *)v19 + 4) + (a2 - *v19) / 5;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Frequency %d invalid in current reg domain",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "reg_freq_to_chan_for_chlist",
        v11,
        v12);
      return 0;
    }
  }
  return result;
}
