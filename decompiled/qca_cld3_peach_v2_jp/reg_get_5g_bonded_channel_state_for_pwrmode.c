__int64 __fastcall reg_get_5g_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
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
  unsigned int v12; // w19
  __int64 v13; // x21
  __int64 result; // x0
  __int64 v15; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int16 v36; // w9
  __int16 v37; // w10
  unsigned int v38; // w1
  unsigned int v39; // w12
  __int64 v40; // x20
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  _WORD v44[2]; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v45; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v46[2]; // [xsp+10h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v44[0] = 0;
  if ( !a3 )
  {
    v15 = jiffies;
    if ( reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Invalid ch_params",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_get_5g_bonded_channel_state_for_pwrmode");
      reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks = v15;
      result = 4;
      goto LABEL_19;
    }
    goto LABEL_6;
  }
  v12 = *a3;
  if ( *a3 >= 5 )
  {
    v13 = jiffies;
    if ( reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks_57 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: bw (%d) passed is not good",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_get_5g_bonded_channel_state_for_pwrmode",
        v12);
      reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks_57 = v13;
      result = 4;
      goto LABEL_19;
    }
LABEL_6:
    result = 4;
    goto LABEL_19;
  }
  result = reg_get_5g_bonded_channel_for_pwrmode(a1, a2, v12, v46, a4, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (result & 0xFFFFFFFB) != 0 )
  {
    v27 = result;
    if ( reg_get_pdev_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26) )
    {
      v36 = 0;
      v37 = 101;
      while ( 1 )
      {
        v38 = (v36 + v37) / 2;
        v39 = *(_DWORD *)(channel_map + 12LL * (int)v38);
        if ( v39 == a2 )
          break;
        if ( v39 >= a2 )
          v37 = v38 - 1;
        else
          v36 = v38 + 1;
        if ( v36 > v37 )
        {
          v40 = jiffies;
          if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
            goto LABEL_6;
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "reg_get_chan_enum_for_freq");
          reg_get_chan_enum_for_freq___last_ticks = v40;
          result = 4;
          goto LABEL_19;
        }
      }
      if ( v38 > 0x65
        || (unsigned int)reg_get_min_max_bw_reg_chan_list(
                           a1,
                           v38,
                           a4,
                           &v45,
                           v44,
                           v28,
                           v29,
                           v30,
                           v31,
                           v32,
                           v33,
                           v34,
                           v35) )
      {
        goto LABEL_6;
      }
      v41 = 0xA1005100290015uLL >> (16 * (unsigned __int8)v12);
      v42 = 0x9F004F00270013uLL >> (16 * (unsigned __int8)v12);
      if ( v12 == 4 )
      {
        LOWORD(v41) = 81;
        LOBYTE(v42) = 79;
      }
      if ( v44[0] <= (unsigned int)(unsigned __int8)v42 || v45 >= (unsigned int)(unsigned __int16)v41 )
        result = 0;
      else
        result = v27;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg obj is NULL",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "reg_get_5g_bonded_channel_state_for_pwrmode");
      result = 4;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
