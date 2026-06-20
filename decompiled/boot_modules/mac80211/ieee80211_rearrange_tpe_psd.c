__int64 __fastcall ieee80211_rearrange_tpe_psd(unsigned __int8 *a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w8
  int v6; // w20
  __int64 result; // x0
  int v8; // w22
  int v9; // w8
  unsigned __int8 v10; // w0
  __int64 v11; // x9
  unsigned __int64 i; // x8
  unsigned __int64 v13; // x16
  unsigned int v14; // w8
  unsigned __int64 v15; // x12
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x11
  unsigned __int64 v18; // x11
  unsigned __int64 v19; // x11
  __int64 v20; // x14
  unsigned __int64 v21; // x16
  char *v22; // x12
  unsigned __int8 *v23; // x13
  unsigned __int64 v24; // x14
  __int16 v25; // w15
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x9
  unsigned __int8 *v28; // x12
  unsigned __int64 v29; // x11
  unsigned __int8 v30; // w14
  _QWORD v31[3]; // [xsp+8h] [xbp-18h] BYREF

  v31[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a3 + 8);
  if ( v5 == 4 )
    LOBYTE(v6) = 8;
  else
    v6 = (int)nl80211_chan_width_to_mhz(v5) / 20;
  result = *(unsigned int *)(a2 + 8);
  if ( (_DWORD)result == 4 )
  {
    v8 = 8;
  }
  else
  {
    result = nl80211_chan_width_to_mhz(result);
    v8 = (unsigned __int8)((int)result / 20);
  }
  v9 = *a1;
  v31[0] = 0;
  v31[1] = 0;
  if ( v9 == 1 )
  {
    if ( a1[18] )
    {
      v10 = ieee80211_calc_chandef_subchan_offset(a2);
      if ( v8 )
      {
        v11 = a1[18];
        for ( i = 0; v8 != i; ++i )
        {
          v13 = i - v10;
          if ( i >= v10 )
          {
            if ( i >= v10 + (unsigned int)v11 )
            {
              v13 = i;
              if ( i > 0xF )
                goto LABEL_44;
              goto LABEL_12;
            }
            if ( (((_DWORD)i - v10) | (unsigned int)i) > 0xF )
              goto LABEL_44;
          }
          else
          {
            v13 = i + v11;
            if ( i + v11 >= 0x10 )
              goto LABEL_44;
          }
          if ( i > 0xF )
          {
LABEL_19:
            __break(1u);
            break;
          }
LABEL_12:
          *((_BYTE *)v31 + i) = a1[v13 + 1];
        }
      }
      *(_QWORD *)(a1 + 9) = 0x7F7F7F7F7F7F7F7FLL;
      *(_QWORD *)(a1 + 1) = 0x7F7F7F7F7F7F7F7FLL;
      result = ieee80211_calc_chandef_subchan_offset(a2);
      v14 = (unsigned __int8)v6;
      if ( (_BYTE)v6 )
      {
        v15 = (unsigned __int8)v6 - 1LL;
        LODWORD(v16) = 16 - (unsigned __int8)result;
        if ( (unsigned __int8)result <= 0x10u )
          v16 = (unsigned int)v16;
        else
          v16 = 0;
        v17 = 16LL - (unsigned __int8)result;
        if ( (unsigned __int8)result > 0x10uLL )
          v17 = 0;
        if ( v17 >= v16 )
          v17 = v16;
        if ( v15 >= v17 )
          v15 = v17;
        v18 = 0;
        if ( v15 > 1 )
        {
          v19 = v15 + 1;
          v20 = (v15 + 1) & 1;
          v21 = ~v15;
          if ( !v20 )
            v20 = 2;
          v22 = (char *)v31 + (unsigned __int8)result + 1;
          v23 = a1 + 2;
          v18 = v19 - v20;
          v24 = v21 + v20;
          do
          {
            v25 = *(_WORD *)(v22 - 1);
            v24 += 2LL;
            v22 += 2;
            *(_WORD *)(v23 - 1) = v25;
            v23 += 2;
          }
          while ( v24 );
        }
        v26 = v16 - v18;
        v27 = v18 + (unsigned __int8)result;
        v28 = &a1[v18 + 1];
        v29 = (unsigned __int8)v6 - v18;
        while ( v26 )
        {
          if ( v27 > 0xF )
            goto LABEL_19;
          v30 = *((_BYTE *)v31 + v27);
          --v29;
          --v26;
          ++v27;
          *v28++ = v30;
          if ( !v29 )
            goto LABEL_41;
        }
LABEL_44:
        __break(0x5512u);
      }
    }
    else
    {
      v14 = (unsigned __int8)v6;
    }
LABEL_41:
    if ( v14 < a1[17] )
      a1[17] = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
