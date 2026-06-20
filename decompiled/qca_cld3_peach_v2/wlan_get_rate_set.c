__int64 __fastcall wlan_get_rate_set(
        __int64 a1,
        _BYTE *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  bool is_24ghz_ch_freq; // w20
  unsigned int v15; // w28
  char *v16; // x24
  unsigned __int64 v17; // x26
  int v18; // w25
  _BYTE *v19; // x27
  __int64 result; // x0
  int v21; // w9
  char v22; // w23
  int v23; // w8
  unsigned int v24; // w8
  int v25; // w8
  unsigned int v26; // w28
  __int64 v27; // x24
  char *v28; // x26
  char v29; // w23
  unsigned int v30; // w8
  int v31; // w9
  unsigned int v32; // w11
  unsigned __int64 v33; // x8
  int v34; // w12
  unsigned __int8 v36; // w9
  unsigned int v37; // w10
  int v38; // w10
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int64 v47; // x8
  unsigned __int8 *v48; // x13
  char v49; // w11
  int v50; // w12
  unsigned __int8 v51; // w9
  unsigned int v52; // w10
  int v53; // w10
  unsigned __int8 *v54; // [xsp+38h] [xbp-28h]
  unsigned __int8 v55[16]; // [xsp+40h] [xbp-20h] BYREF
  _QWORD v56[2]; // [xsp+50h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v55, 0, 13);
  if ( !a3 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: pe session is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_get_rate_set");
    result = 4;
    goto LABEL_230;
  }
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a3[71]);
  qdf_mem_set(a3 + 63, 0xDu, 0);
  qdf_mem_set((char *)a3 + 265, 0xDu, 0);
  qdf_mem_set(v55, 0xDu, 0);
  v54 = (unsigned __int8 *)a3 + 253;
  if ( a2[34] )
  {
    v15 = (unsigned __int8)a2[35];
    if ( a2[35] )
    {
      v16 = (char *)a3 + 253;
      v17 = 0;
      v18 = 0;
      v19 = a2 + 36;
      while ( !is_24ghz_ch_freq )
      {
        if ( v17 >= 0xC )
          goto LABEL_232;
        v22 = v19[v17];
        v23 = v22 & 0x7F;
        if ( (unsigned int)(v23 - 12) <= 0x3C && ((1LL << ((unsigned __int8)v23 - 12)) & 0x1000001001001041LL) != 0
          || v23 == 96
          || v23 == 108 )
        {
          goto LABEL_15;
        }
LABEL_8:
        if ( ++v17 >= v15 )
          goto LABEL_75;
      }
      if ( v17 > 0xB )
        goto LABEL_232;
      v22 = v19[v17];
LABEL_15:
      if ( (wlan_rates_is_dot11_rate_supported(a1, v22) & 1) == 0 )
        goto LABEL_8;
      v24 = v22 & 0x7F;
      if ( v24 > 0x17 )
      {
        if ( (v22 & 0x7Fu) > 0x47 )
        {
          if ( v24 == 72 )
          {
            v21 = v18 & 0x200;
          }
          else if ( v24 == 96 )
          {
            v21 = v18 & 0x400;
          }
          else
          {
            v21 = v18;
            if ( v24 == 108 )
              v21 = v18 & 0x800;
          }
        }
        else if ( v24 == 24 )
        {
          v21 = v18 & 0x40;
        }
        else if ( v24 == 36 )
        {
          v21 = v18 & 0x80;
        }
        else
        {
          v21 = v18;
          if ( v24 == 48 )
            v21 = v18 & 0x100;
        }
      }
      else if ( (v22 & 0x7Fu) > 0xB )
      {
        if ( v24 == 12 )
        {
          v21 = v18 & 0x10;
        }
        else if ( v24 == 18 )
        {
          v21 = v18 & 0x20;
        }
        else
        {
          v21 = v18;
          if ( v24 == 22 )
            v21 = v18 & 8;
        }
      }
      else if ( v24 == 2 )
      {
        v21 = v18 & 1;
      }
      else if ( v24 == 4 )
      {
        v21 = v18 & 2;
      }
      else
      {
        v21 = v18;
        if ( v24 == 11 )
          v21 = v18 & 4;
      }
      if ( v21 )
        goto LABEL_8;
      if ( (v22 & 0x7Fu) > 0x17 )
      {
        if ( (v22 & 0x7Fu) > 0x47 )
        {
          switch ( v24 )
          {
            case 'H':
              v25 = 512;
              goto LABEL_72;
            case '`':
              v25 = 1024;
              goto LABEL_72;
            case 'l':
              v25 = 2048;
              goto LABEL_72;
          }
        }
        else
        {
          switch ( v24 )
          {
            case 0x18u:
              v25 = 64;
              goto LABEL_72;
            case 0x24u:
              v25 = 128;
              goto LABEL_72;
            case 0x30u:
              v25 = 256;
              goto LABEL_72;
          }
        }
      }
      else if ( (v22 & 0x7Fu) > 0xB )
      {
        switch ( v24 )
        {
          case 0xCu:
            v25 = 16;
            goto LABEL_72;
          case 0x12u:
            v25 = 32;
            goto LABEL_72;
          case 0x16u:
            v25 = 8;
            goto LABEL_72;
        }
      }
      else
      {
        switch ( v24 )
        {
          case 2u:
            v25 = 1;
            goto LABEL_72;
          case 4u:
            v25 = 2;
            goto LABEL_72;
          case 0xBu:
            v25 = 4;
LABEL_72:
            v18 |= v25;
            break;
        }
      }
      *v16++ = v22;
      ++*((_BYTE *)a3 + 252);
      v15 = (unsigned __int8)a2[35];
      goto LABEL_8;
    }
    v18 = 0;
    if ( !a2[849] )
      goto LABEL_103;
    goto LABEL_76;
  }
  v18 = 0;
LABEL_75:
  if ( a2[849] )
  {
LABEL_76:
    v26 = (unsigned __int8)a2[850];
    if ( a2[850] )
    {
      v27 = 0;
      v28 = (char *)a3 + 266;
      while ( v27 != 12 )
      {
        v29 = a2[v27 + 851];
        if ( (wlan_rates_is_dot11_rate_supported(a1, v29) & 1) != 0 )
        {
          v30 = v29 & 0x7F;
          if ( v30 > 0x17 )
          {
            if ( (v29 & 0x7Fu) > 0x47 )
            {
              v31 = v18 & 0x200;
              if ( v30 != 72 )
              {
                v31 = v18 & 0x400;
                if ( v30 != 96 )
                {
                  v31 = v18;
                  if ( v30 == 108 )
                    v31 = v18 & 0x800;
                }
              }
            }
            else
            {
              v31 = v18 & 0x40;
              if ( v30 != 24 )
              {
                v31 = v18 & 0x80;
                if ( v30 != 36 )
                {
                  v31 = v18;
                  if ( v30 == 48 )
                    v31 = v18 & 0x100;
                }
              }
            }
          }
          else if ( (v29 & 0x7Fu) > 0xB )
          {
            v31 = v18 & 0x10;
            if ( v30 != 12 )
            {
              v31 = v18 & 0x20;
              if ( v30 != 18 )
              {
                v31 = v18;
                if ( v30 == 22 )
                  v31 = v18 & 8;
              }
            }
          }
          else
          {
            v31 = v18 & 1;
            if ( v30 != 2 )
            {
              v31 = v18 & 2;
              if ( v30 != 4 )
              {
                v31 = v18;
                if ( v30 == 11 )
                  v31 = v18 & 4;
              }
            }
          }
          if ( !v31 )
          {
            *v28++ = v29;
            ++*((_BYTE *)a3 + 265);
            v26 = (unsigned __int8)a2[850];
          }
        }
        if ( ++v27 >= (unsigned __int64)v26 )
          goto LABEL_103;
      }
LABEL_232:
      __break(0x5512u);
LABEL_233:
      __break(1u);
    }
  }
LABEL_103:
  if ( *((_BYTE *)a3 + 252) )
    goto LABEL_229;
  wlan_populate_basic_rates(v55, !is_24ghz_ch_freq, 1);
  v32 = v55[0];
  if ( v55[0] )
  {
    v33 = 1;
    while ( 1 )
    {
      if ( v33 == 13 )
        goto LABEL_232;
      v36 = v55[v33];
      v37 = v36 & 0x7F;
      if ( v37 > 0x17 )
      {
        if ( (v36 & 0x7Fu) > 0x47 )
        {
          if ( v37 == 72 )
          {
            v34 = v18 & 0x200;
          }
          else if ( v37 == 96 )
          {
            v34 = v18 & 0x400;
          }
          else
          {
            v34 = v18;
            if ( v37 == 108 )
              v34 = v18 & 0x800;
          }
        }
        else if ( v37 == 24 )
        {
          v34 = v18 & 0x40;
        }
        else if ( v37 == 36 )
        {
          v34 = v18 & 0x80;
        }
        else
        {
          v34 = v18;
          if ( v37 == 48 )
            v34 = v18 & 0x100;
        }
      }
      else if ( (v36 & 0x7Fu) > 0xB )
      {
        if ( v37 == 12 )
        {
          v34 = v18 & 0x10;
        }
        else if ( v37 == 18 )
        {
          v34 = v18 & 0x20;
        }
        else
        {
          v34 = v18;
          if ( v37 == 22 )
            v34 = v18 & 8;
        }
      }
      else if ( v37 == 2 )
      {
        v34 = v18 & 1;
      }
      else if ( v37 == 4 )
      {
        v34 = v18 & 2;
      }
      else
      {
        v34 = v18;
        if ( v37 == 11 )
          v34 = v18 & 4;
      }
      if ( !v34 )
        break;
LABEL_108:
      if ( v33++ >= v32 )
        goto LABEL_165;
    }
    if ( (v36 & 0x7Fu) > 0x17 )
    {
      if ( (v36 & 0x7Fu) > 0x47 )
      {
        switch ( v37 )
        {
          case 'H':
            v38 = 512;
            goto LABEL_163;
          case '`':
            v38 = 1024;
            goto LABEL_163;
          case 'l':
            v38 = 2048;
            goto LABEL_163;
        }
      }
      else
      {
        switch ( v37 )
        {
          case 0x18u:
            v38 = 64;
            goto LABEL_163;
          case 0x24u:
            v38 = 128;
            goto LABEL_163;
          case 0x30u:
            v38 = 256;
            goto LABEL_163;
        }
      }
    }
    else if ( (v36 & 0x7Fu) > 0xB )
    {
      switch ( v37 )
      {
        case 0xCu:
          v38 = 16;
          goto LABEL_163;
        case 0x12u:
          v38 = 32;
          goto LABEL_163;
        case 0x16u:
          v38 = 8;
          goto LABEL_163;
      }
    }
    else
    {
      switch ( v37 )
      {
        case 2u:
          v38 = 1;
          goto LABEL_163;
        case 4u:
          v38 = 2;
          goto LABEL_163;
        case 0xBu:
          v38 = 4;
LABEL_163:
          v18 |= v38;
          break;
      }
    }
    *v54 = v36;
    v32 = v55[0];
    ++v54;
    ++*((_BYTE *)a3 + 252);
    goto LABEL_108;
  }
LABEL_165:
  if ( !is_24ghz_ch_freq
    || (v55[0] = 8,
        v56[0] = 0x6C6048302418120CLL,
        qdf_mem_copy(&v55[1], v56, 8u),
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Default OFDM Rates",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_populate_basic_rates"),
        ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 8, &v55[1], v55[0]),
        v47 = *((unsigned __int8 *)a3 + 252),
        v47 > 0xB) )
  {
LABEL_229:
    result = 0;
    goto LABEL_230;
  }
  v48 = v54;
  v49 = *((_BYTE *)a3 + 252);
  do
  {
    if ( v47 > 0xB )
      goto LABEL_233;
    v51 = v55[v47 + 1];
    v52 = v51 & 0x7F;
    if ( v52 > 0x17 )
    {
      if ( (v51 & 0x7Fu) > 0x47 )
      {
        if ( v52 == 72 )
        {
          v50 = v18 & 0x200;
        }
        else if ( v52 == 96 )
        {
          v50 = v18 & 0x400;
        }
        else
        {
          v50 = v18;
          if ( v52 == 108 )
            v50 = v18 & 0x800;
        }
      }
      else if ( v52 == 24 )
      {
        v50 = v18 & 0x40;
      }
      else if ( v52 == 36 )
      {
        v50 = v18 & 0x80;
      }
      else
      {
        v50 = v18;
        if ( v52 == 48 )
          v50 = v18 & 0x100;
      }
    }
    else if ( (v51 & 0x7Fu) > 0xB )
    {
      if ( v52 == 12 )
      {
        v50 = v18 & 0x10;
      }
      else if ( v52 == 18 )
      {
        v50 = v18 & 0x20;
      }
      else
      {
        v50 = v18;
        if ( v52 == 22 )
          v50 = v18 & 8;
      }
    }
    else if ( v52 == 2 )
    {
      v50 = v18 & 1;
    }
    else if ( v52 == 4 )
    {
      v50 = v18 & 2;
    }
    else
    {
      v50 = v18;
      if ( v52 == 11 )
        v50 = v18 & 4;
    }
    if ( !v50 )
    {
      if ( (v51 & 0x7Fu) > 0x17 )
      {
        if ( (v51 & 0x7Fu) > 0x47 )
        {
          switch ( v52 )
          {
            case 'H':
              v53 = 512;
              goto LABEL_225;
            case '`':
              v53 = 1024;
              goto LABEL_225;
            case 'l':
              v53 = 2048;
              goto LABEL_225;
          }
        }
        else
        {
          switch ( v52 )
          {
            case 0x18u:
              v53 = 64;
              goto LABEL_225;
            case 0x24u:
              v53 = 128;
              goto LABEL_225;
            case 0x30u:
              v53 = 256;
              goto LABEL_225;
          }
        }
      }
      else if ( (v51 & 0x7Fu) > 0xB )
      {
        switch ( v52 )
        {
          case 0xCu:
            v53 = 16;
            goto LABEL_225;
          case 0x12u:
            v53 = 32;
            goto LABEL_225;
          case 0x16u:
            v53 = 8;
            goto LABEL_225;
        }
      }
      else
      {
        switch ( v52 )
        {
          case 2u:
            v53 = 1;
            goto LABEL_225;
          case 4u:
            v53 = 2;
            goto LABEL_225;
          case 0xBu:
            v53 = 4;
LABEL_225:
            v18 |= v53;
            break;
        }
      }
      *v48++ = v51;
      v49 = *((_BYTE *)a3 + 252) + 1;
      *((_BYTE *)a3 + 252) = v49;
    }
    ++v47;
  }
  while ( v47 != 12 );
  if ( v49 || *((_BYTE *)a3 + 265) )
    goto LABEL_229;
  result = 16;
LABEL_230:
  _ReadStatusReg(SP_EL0);
  return result;
}
