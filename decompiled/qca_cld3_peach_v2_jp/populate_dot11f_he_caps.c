__int64 __fastcall populate_dot11f_he_caps(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned int a5, _BYTE *a6)
{
  char v11; // w24
  bool is_24ghz_ch_freq; // w0
  __int64 v14; // x8
  __int64 v15; // x9
  char v16; // w22
  bool v17; // w0
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  __int16 v21; // w10
  __int16 v22; // w11
  __int16 v23; // w9
  __int16 v24; // w10
  __int16 v25; // w11

  *a6 = 1;
  if ( a2 )
  {
    v11 = 2 * *(_BYTE *)(a2 + 8635);
    qdf_mem_copy(a6, (const void *)(a2 + 8680), 0x3Cu);
    populate_dot11f_twt_he_cap(a1, a2, a6);
    if ( (*(_DWORD *)(a2 + 7036) | 2) == 2 && (unsigned int)wlan_mlme_get_max_bw() > 2 && a5 == 2 )
      a5 = 3;
  }
  else
  {
    qdf_mem_copy(a6, (const void *)(*(_QWORD *)(a1 + 8) + 1288LL), 0x3Cu);
    v11 = 4;
    if ( !a4 )
      goto LABEL_70;
  }
  if ( (a6[14] & 4) != 0 )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a4);
    v14 = *(_QWORD *)(a1 + 8);
    v15 = 1433;
    if ( is_24ghz_ch_freq )
      v15 = 1408;
    v16 = 25;
    qdf_mem_copy(a6 + 33, (const void *)(v14 + v15), 0x19u);
    if ( !a6[57] )
    {
      if ( a6[56] )
      {
        v16 = 24;
      }
      else if ( a6[55] )
      {
        v16 = 23;
      }
      else if ( a6[54] )
      {
        v16 = 22;
      }
      else if ( a6[53] )
      {
        v16 = 21;
      }
      else if ( a6[52] )
      {
        v16 = 20;
      }
      else if ( a6[51] )
      {
        v16 = 19;
      }
      else if ( a6[50] )
      {
        v16 = 18;
      }
      else if ( a6[49] )
      {
        v16 = 17;
      }
      else if ( a6[48] )
      {
        v16 = 16;
      }
      else if ( a6[47] )
      {
        v16 = 15;
      }
      else if ( a6[46] )
      {
        v16 = 14;
      }
      else if ( a6[45] )
      {
        v16 = 13;
      }
      else if ( a6[44] )
      {
        v16 = 12;
      }
      else if ( a6[43] )
      {
        v16 = 11;
      }
      else if ( a6[42] )
      {
        v16 = 10;
      }
      else if ( a6[41] )
      {
        v16 = 9;
      }
      else if ( a6[40] )
      {
        v16 = 8;
      }
      else if ( a6[39] )
      {
        v16 = 7;
      }
      else if ( a6[38] )
      {
        v16 = 6;
      }
      else if ( a6[37] )
      {
        v16 = 5;
      }
      else if ( a6[36] )
      {
        v16 = 4;
      }
      else if ( a6[35] )
      {
        v16 = 3;
      }
      else if ( a6[34] )
      {
        v16 = 2;
      }
      else
      {
        v16 = a6[33] != 0;
      }
    }
    a6[32] = v16;
  }
  else
  {
    a6[32] = 0;
  }
  v17 = wlan_reg_is_24ghz_ch_freq(a4);
  v18 = *(_QWORD *)(a6 + 1);
  if ( v17 )
  {
    v19 = 0xFE47FFFFFFFFFFFFLL;
LABEL_69:
    *(_QWORD *)(a6 + 1) = v18 & v19;
    goto LABEL_70;
  }
  *(_QWORD *)(a6 + 1) = v18 & 0xFEBBFFFFFFFFFFFFLL;
  if ( a5 < 3 )
  {
    v19 = 0xFE8BFFFFFFFFFFFFLL;
    goto LABEL_69;
  }
  if ( a5 == 3 )
  {
    v19 = 0xFE9BFFFFFFFFFFFFLL;
    goto LABEL_69;
  }
LABEL_70:
  v21 = *((_WORD *)a6 + 11) | (-1LL << v11);
  v22 = *((_WORD *)a6 + 12) | (-1LL << v11);
  *((_WORD *)a6 + 10) |= -1LL << v11;
  v23 = *((_WORD *)a6 + 13);
  *((_WORD *)a6 + 11) = v21;
  v24 = *((_WORD *)a6 + 14);
  *((_WORD *)a6 + 12) = v22;
  v25 = *((_WORD *)a6 + 15);
  *((_WORD *)a6 + 13) = v23 | (-1LL << v11);
  *((_WORD *)a6 + 14) = v24 | (-1LL << v11);
  *((_WORD *)a6 + 15) = v25 | (-1LL << v11);
  return 0;
}
