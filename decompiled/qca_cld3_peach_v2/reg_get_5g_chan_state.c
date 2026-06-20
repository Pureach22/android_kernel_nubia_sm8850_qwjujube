__int64 __fastcall reg_get_5g_chan_state(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x20
  unsigned int chan_state; // w20
  unsigned __int16 *bonded_chan_entry; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w9
  unsigned int v29; // w8
  unsigned __int16 *v30; // x23
  char v31; // w25
  unsigned __int64 v32; // x24
  unsigned int v33; // w0
  unsigned int v34; // w26
  __int16 v35; // w9
  __int16 v36; // w10
  __int64 v37; // x1
  unsigned int v38; // w11
  __int64 v39; // x27
  __int16 v40; // w9
  __int16 v41; // w10
  __int64 v42; // x1
  unsigned int v43; // w12
  __int64 v44; // x21
  __int16 v45; // w9
  __int16 v46; // w10
  __int64 v47; // x1
  unsigned int v48; // w12
  __int64 v49; // x20
  unsigned __int64 v51; // x9
  unsigned __int16 v52; // w8
  _WORD v55[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v56; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+18h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v55[0] = 0;
  if ( a3 >= 5 )
  {
    v13 = jiffies;
    if ( reg_get_5g_chan_state___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: bw passed is not good", a6, a7, a8, a9, a10, a11, a12, a13, "reg_get_5g_chan_state");
      reg_get_5g_chan_state___last_ticks = v13;
      chan_state = 4;
      goto LABEL_45;
    }
    goto LABEL_44;
  }
  if ( !a3 )
  {
    v40 = 0;
    v41 = 101;
    do
    {
      v42 = (unsigned int)((v40 + v41) / 2);
      v43 = *(_DWORD *)(channel_map + 12LL * (int)v42);
      if ( v43 == a2 )
      {
        if ( (unsigned int)v42 <= 0x65 )
        {
          chan_state = reg_get_chan_state(a1, v42, a4, 0);
          goto LABEL_45;
        }
        goto LABEL_44;
      }
      if ( v43 >= a2 )
        v41 = v42 - 1;
      else
        v40 = v42 + 1;
    }
    while ( v40 <= v41 );
    v44 = jiffies;
    if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: invalid channel center frequency %d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "reg_get_chan_enum_for_freq",
        a2);
      reg_get_chan_enum_for_freq___last_ticks = v44;
      chan_state = 4;
      goto LABEL_45;
    }
LABEL_44:
    chan_state = 4;
    goto LABEL_45;
  }
  bonded_chan_entry = reg_get_bonded_chan_entry(a2, a3, 0, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !bonded_chan_entry )
    goto LABEL_44;
  v28 = *bonded_chan_entry;
  v29 = bonded_chan_entry[1];
  v30 = bonded_chan_entry;
  if ( v28 > v29 )
    goto LABEL_44;
  v31 = 0;
  v32 = a5;
  chan_state = 4;
  while ( 2 )
  {
    v34 = (unsigned __int16)v28;
    if ( ((v32 >> v31) & 1) != 0 )
      goto LABEL_11;
    v35 = 0;
    v36 = 101;
    do
    {
      v37 = (unsigned int)((v35 + v36) / 2);
      v38 = *(_DWORD *)(channel_map + 12LL * (int)v37);
      if ( v38 == v34 )
      {
        if ( (unsigned int)v37 <= 0x65 )
        {
          v33 = reg_get_chan_state(a1, v37, a4, 0);
          goto LABEL_9;
        }
LABEL_8:
        v33 = 4;
        goto LABEL_9;
      }
      if ( v38 >= v34 )
        v36 = v37 - 1;
      else
        v35 = v37 + 1;
    }
    while ( v35 <= v36 );
    v39 = jiffies;
    if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
      goto LABEL_8;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: invalid channel center frequency %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "reg_get_chan_enum_for_freq",
      v34);
    v33 = 4;
    reg_get_chan_enum_for_freq___last_ticks = v39;
LABEL_9:
    LOWORD(v29) = v30[1];
    if ( v33 < chan_state )
      chan_state = v33;
LABEL_11:
    LOWORD(v28) = v34 + 20;
    ++v31;
    if ( (unsigned __int16)(v34 + 20) <= (unsigned int)(unsigned __int16)v29 )
      continue;
    break;
  }
  if ( (chan_state & 3) != 0 )
  {
    v45 = 0;
    v46 = 101;
    while ( 1 )
    {
      v47 = (unsigned int)((v45 + v46) / 2);
      v48 = *(_DWORD *)(channel_map + 12LL * (int)v47);
      if ( v48 == a2 )
        break;
      if ( v48 >= a2 )
        v46 = v47 - 1;
      else
        v45 = v47 + 1;
      if ( v45 > v46 )
      {
        v49 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
          goto LABEL_44;
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "reg_get_chan_enum_for_freq",
          a2);
        reg_get_chan_enum_for_freq___last_ticks = v49;
        chan_state = 4;
        goto LABEL_45;
      }
    }
    if ( (unsigned int)v47 > 0x65 || (unsigned int)reg_get_min_max_bw_reg_chan_list(a1, v47, a4, &v56, v55) )
      goto LABEL_44;
    v51 = 0x9F004F0027004FuLL >> (16 * (unsigned __int8)a3);
    if ( a3 == 4 )
      v52 = 81;
    else
      v52 = 0xA1005100290051uLL >> (16 * (unsigned __int8)a3);
    if ( a3 == 4 )
      LOBYTE(v51) = 79;
    if ( v55[0] <= (unsigned int)(unsigned __int8)v51 || v56 >= (unsigned int)v52 )
      chan_state = 0;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return chan_state;
}
