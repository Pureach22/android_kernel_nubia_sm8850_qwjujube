__int64 __fastcall reg_get_5g_chan_state(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  unsigned int v13; // w23
  _QWORD *v18; // x8
  __int64 v19; // x9
  unsigned __int16 *v20; // x24
  unsigned int v21; // w8
  unsigned int v22; // w10
  unsigned int chan_state; // w0
  __int16 v24; // w9
  unsigned int v25; // w26
  __int16 v26; // w8
  __int64 v27; // x1
  unsigned int v28; // w11
  __int64 v29; // x27
  __int16 v30; // w9
  __int16 v31; // w10
  __int64 v32; // x1
  unsigned int v33; // w12
  __int64 v34; // x21
  __int16 v35; // w9
  __int16 v36; // w10
  __int64 v37; // x1
  unsigned int v38; // w12
  __int64 v39; // x20
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x8
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v44) = 0;
  LOWORD(v44) = 0;
  if ( (unsigned int)a3 >= 5 )
  {
    v12 = jiffies;
    if ( reg_get_5g_chan_state___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: bw passed is not good", a5, a6, a7, a8, a9, a10, a11, a12, "reg_get_5g_chan_state");
      reg_get_5g_chan_state___last_ticks = v12;
      v13 = 4;
    }
    else
    {
LABEL_3:
      v13 = 4;
    }
    goto LABEL_64;
  }
  if ( a3 > 1 )
  {
    if ( a3 == 2 )
    {
      v18 = &unk_9E62D8;
      v19 = 21;
    }
    else if ( a3 == 3 )
    {
      v18 = &bw_bonded_array_pair_map;
      v19 = 10;
    }
    else
    {
      v18 = &unk_9E62C0;
      v19 = 21;
    }
LABEL_13:
    v20 = (unsigned __int16 *)v18[1];
    while ( 1 )
    {
      v21 = *v20;
      if ( v21 <= a2 )
      {
        v22 = v20[1];
        if ( v22 >= a2 )
          break;
      }
      --v19;
      v20 += 2;
      if ( !v19 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "reg_get_bonded_chan_entry",
          a2,
          (unsigned int)a3,
          0,
          v44,
          v45);
        v13 = 4;
        goto LABEL_64;
      }
    }
    v13 = 4;
    if ( v20 && v21 <= v22 )
    {
      do
      {
        v24 = 0;
        v25 = (unsigned __int16)v21;
        v26 = 101;
        while ( 1 )
        {
          v27 = (unsigned int)((v24 + v26) / 2);
          v28 = *(_DWORD *)(channel_map + 12LL * (int)v27);
          if ( v28 == v25 )
            break;
          if ( v28 >= v25 )
            v26 = v27 - 1;
          else
            v24 = v27 + 1;
          if ( v24 > v26 )
          {
            v29 = jiffies;
            if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x51u,
                8u,
                "%s: invalid channel center frequency %d",
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                a12,
                "reg_get_chan_enum_for_freq",
                v25);
              chan_state = 4;
              reg_get_chan_enum_for_freq___last_ticks = v29;
              goto LABEL_21;
            }
LABEL_20:
            chan_state = 4;
            goto LABEL_21;
          }
        }
        if ( (unsigned int)v27 > 0x65 )
          goto LABEL_20;
        chan_state = reg_get_chan_state(a1, v27, a4, 0);
LABEL_21:
        LOWORD(v21) = v25 + 20;
        if ( chan_state < v13 )
          v13 = chan_state;
      }
      while ( v20[1] >= (unsigned int)(unsigned __int16)v21 );
      if ( (v13 & 3) != 0 )
      {
        v35 = 0;
        v36 = 101;
        while ( 1 )
        {
          v37 = (unsigned int)((v35 + v36) / 2);
          v38 = *(_DWORD *)(channel_map + 12LL * (int)v37);
          if ( v38 == a2 )
            break;
          if ( v38 >= a2 )
            v36 = v37 - 1;
          else
            v35 = v37 + 1;
          if ( v35 > v36 )
          {
            v39 = jiffies;
            if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
              goto LABEL_3;
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: invalid channel center frequency %d",
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              "reg_get_chan_enum_for_freq",
              a2);
            reg_get_chan_enum_for_freq___last_ticks = v39;
            v13 = 4;
            goto LABEL_64;
          }
        }
        if ( (unsigned int)v37 > 0x65
          || (unsigned int)reg_get_min_max_bw_reg_chan_list(a1, v37, a4, (char *)&v44 + 4, &v44) )
        {
          goto LABEL_3;
        }
        v40 = 0xA1005100290051uLL >> (16 * (unsigned __int8)a3);
        v41 = 0x9F004F0027004FuLL >> (16 * (unsigned __int8)a3);
        if ( a3 == 4 )
        {
          LOWORD(v40) = 81;
          LOBYTE(v41) = 79;
        }
        if ( (unsigned __int16)v44 <= (unsigned int)(unsigned __int8)v41
          || WORD2(v44) >= (unsigned int)(unsigned __int16)v40 )
        {
          v13 = 0;
        }
      }
    }
    goto LABEL_64;
  }
  if ( a3 )
  {
    v18 = &unk_9E62F0;
    v19 = 43;
    goto LABEL_13;
  }
  v30 = 0;
  v31 = 101;
  while ( 1 )
  {
    v32 = (unsigned int)((v30 + v31) / 2);
    v33 = *(_DWORD *)(channel_map + 12LL * (int)v32);
    if ( v33 == a2 )
      break;
    if ( v33 >= a2 )
      v31 = v32 - 1;
    else
      v30 = v32 + 1;
    if ( v30 > v31 )
    {
      v34 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
        goto LABEL_3;
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: invalid channel center frequency %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_get_chan_enum_for_freq",
        a2);
      reg_get_chan_enum_for_freq___last_ticks = v34;
      v13 = 4;
      goto LABEL_64;
    }
  }
  if ( (unsigned int)v32 > 0x65 )
    goto LABEL_3;
  v13 = reg_get_chan_state(a1, v32, a4, 0);
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return v13;
}
