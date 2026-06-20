__int64 __fastcall reg_get_5g_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
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
  unsigned __int16 *v27; // x28
  unsigned int v28; // w22
  __int64 v29; // x8
  int v30; // w10
  unsigned int v31; // w24
  __int64 v32; // x27
  __int16 v33; // w25
  int channel_state_for_pwrmode; // w0
  __int64 v35; // x8
  unsigned int v36; // w9
  _WORD *v37; // x10
  unsigned int v38; // w22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int16 v47; // w9
  __int16 v48; // w10
  unsigned int v49; // w1
  unsigned int v50; // w12
  __int64 v51; // x20
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x9
  __int64 v55; // x9
  unsigned __int16 *v56; // x11
  int v57; // t1
  unsigned int v58; // [xsp+0h] [xbp-20h]
  _WORD v60[2]; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v61; // [xsp+Ch] [xbp-14h] BYREF
  unsigned __int16 *v62[2]; // [xsp+10h] [xbp-10h] BYREF

  v62[1] = *(unsigned __int16 **)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = nullptr;
  v61 = 0;
  v60[0] = 0;
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
      goto LABEL_37;
    }
    goto LABEL_6;
  }
  v12 = *(_DWORD *)a3;
  if ( *(_DWORD *)a3 >= 5u )
  {
    v13 = jiffies;
    if ( reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks_66 - jiffies + 125 < 0 )
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
      reg_get_5g_bonded_channel_state_for_pwrmode___last_ticks_66 = v13;
      result = 4;
      goto LABEL_37;
    }
LABEL_6:
    result = 4;
    goto LABEL_37;
  }
  result = reg_get_5g_bonded_channel_for_pwrmode(
             a1,
             a2,
             v12,
             v62,
             a4,
             *(_WORD *)(a3 + 22),
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12);
  if ( a1 )
  {
    v27 = v62[0];
    if ( v62[0] )
    {
      if ( *(_BYTE *)(a3 + 20) == 1 )
      {
        v28 = *v62[0];
        if ( v28 <= v62[0][1] )
        {
          v32 = 0;
          v33 = 0;
          v31 = 3;
          v58 = result;
          do
          {
            channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                          a1,
                                          v28,
                                          a4,
                                          v19,
                                          v20,
                                          v21,
                                          v22,
                                          v23,
                                          v24,
                                          v25,
                                          v26);
            v35 = 1LL << v32;
            v28 += 20;
            ++v32;
            if ( (channel_state_for_pwrmode & 0xFFFFFFFB) != 0 )
              LOWORD(v35) = 0;
            if ( channel_state_for_pwrmode == 2 )
              v31 = 2;
            v33 |= v35;
          }
          while ( v28 <= v27[1] );
          if ( v33 )
          {
            v36 = *(_DWORD *)a3;
            v29 = a3;
            if ( *(_DWORD *)a3 == 2 )
            {
              result = v58;
              v37 = &unk_AD80C8;
            }
            else
            {
              result = v58;
              if ( v36 == 7 )
              {
                v37 = &bw_puncture_bitmap_pair_map;
              }
              else
              {
                if ( v36 != 3 )
                  goto LABEL_26;
                v37 = &unk_AD80B0;
              }
            }
            v55 = (unsigned __int16)v37[8];
            if ( !v37[8] )
              goto LABEL_26;
            v56 = *((unsigned __int16 **)v37 + 1);
            if ( !v56 )
              goto LABEL_26;
            while ( 1 )
            {
              v57 = *v56++;
              v30 = v57;
              if ( v57 == (unsigned __int16)(v57 | v33) )
                break;
              if ( !--v55 )
                goto LABEL_26;
            }
            if ( !v30 )
              goto LABEL_26;
          }
          else
          {
            LOWORD(v30) = 0;
            v29 = a3;
          }
        }
        else
        {
          v29 = a3;
          LOWORD(v30) = 0;
          v31 = 3;
        }
        result = v31;
        *(_WORD *)(v29 + 18) = v30;
      }
    }
  }
LABEL_26:
  if ( (result & 0xFFFFFFFB) != 0 )
  {
    v38 = result;
    if ( reg_get_pdev_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26) )
    {
      v47 = 0;
      v48 = 101;
      while ( 1 )
      {
        v49 = (v47 + v48) / 2;
        v50 = *(_DWORD *)(channel_map + 12LL * (int)v49);
        if ( v50 == a2 )
          break;
        if ( v50 >= a2 )
          v48 = v49 - 1;
        else
          v47 = v49 + 1;
        if ( v47 > v48 )
        {
          v51 = jiffies;
          if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 >= 0 )
            goto LABEL_6;
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "reg_get_chan_enum_for_freq");
          reg_get_chan_enum_for_freq___last_ticks = v51;
          result = 4;
          goto LABEL_37;
        }
      }
      if ( v49 > 0x65
        || (unsigned int)reg_get_min_max_bw_reg_chan_list(
                           a1,
                           v49,
                           a4,
                           &v61,
                           v60,
                           v39,
                           v40,
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46) )
      {
        goto LABEL_6;
      }
      v52 = 0xA1005100290015uLL >> (16 * (unsigned __int8)v12);
      v53 = 0x9F004F00270013uLL >> (16 * (unsigned __int8)v12);
      if ( v12 == 4 )
      {
        LOWORD(v52) = 81;
        LOBYTE(v53) = 79;
      }
      if ( v60[0] <= (unsigned int)(unsigned __int8)v53 || v61 >= (unsigned int)(unsigned __int16)v52 )
        result = 0;
      else
        result = v38;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg obj is NULL",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "reg_get_5g_bonded_channel_state_for_pwrmode");
      result = 4;
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
