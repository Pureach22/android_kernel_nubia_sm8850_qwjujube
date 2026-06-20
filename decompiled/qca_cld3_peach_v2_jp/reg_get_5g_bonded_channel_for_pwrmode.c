__int64 __fastcall reg_get_5g_bonded_channel_for_pwrmode(
        __int64 a1,
        unsigned __int16 a2,
        int a3,
        _QWORD *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *v16; // x9
  __int64 v17; // x8
  unsigned __int16 *v18; // x22
  unsigned int v19; // w23
  unsigned int v20; // w21
  unsigned int channel_state_for_pwrmode; // w0
  __int64 v22; // x20

  if ( a3 <= 1 )
  {
    if ( !a3 )
      return (unsigned int)reg_get_channel_state_for_pwrmode(a1, a2, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    if ( a3 != 1 )
      goto LABEL_23;
    v16 = &unk_9E62F0;
    v17 = 43;
LABEL_11:
    v18 = (unsigned __int16 *)v16[1];
    while ( *v18 > (unsigned int)a2 || v18[1] < (unsigned int)a2 )
    {
      --v17;
      v18 += 2;
      if ( !v17 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "reg_get_bonded_chan_entry");
        goto LABEL_24;
      }
    }
    *a4 = v18;
    if ( !v18 )
      goto LABEL_25;
    v19 = *v18;
    v20 = 4;
    if ( v19 <= v18[1] )
    {
      do
      {
        channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                      a1,
                                      (unsigned __int16)v19,
                                      a5,
                                      a6,
                                      a7,
                                      a8,
                                      a9,
                                      a10,
                                      a11,
                                      a12,
                                      a13);
        LOWORD(v19) = v19 + 20;
        if ( channel_state_for_pwrmode < v20 )
          v20 = channel_state_for_pwrmode;
      }
      while ( v18[1] >= (unsigned int)(unsigned __int16)v19 );
    }
    return v20;
  }
  switch ( a3 )
  {
    case 2:
      v16 = &unk_9E62D8;
      v17 = 21;
      goto LABEL_11;
    case 3:
      v16 = &bw_bonded_array_pair_map;
      v17 = 10;
      goto LABEL_11;
    case 4:
      v16 = &unk_9E62C0;
      v17 = 21;
      goto LABEL_11;
  }
LABEL_23:
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: Could not find bonded_chan_array for chwidth %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "reg_get_bonded_chan_entry",
    (unsigned int)a3);
LABEL_24:
  *a4 = 0;
LABEL_25:
  v22 = jiffies;
  if ( reg_get_5g_bonded_channel_for_pwrmode___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: bonded_chan_ptr_ptr is NULL",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "reg_get_5g_bonded_channel_for_pwrmode");
    reg_get_5g_bonded_channel_for_pwrmode___last_ticks = v22;
  }
  return 4;
}
