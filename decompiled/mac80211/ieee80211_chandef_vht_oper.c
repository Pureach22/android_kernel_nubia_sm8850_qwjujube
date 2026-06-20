__int64 __fastcall ieee80211_chandef_vht_oper(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        __int64 a4,
        unsigned int **a5)
{
  unsigned int v6; // w9
  unsigned int *v7; // x11
  unsigned int *v8; // x10
  __int64 v11; // x1
  int v13; // w9
  bool v14; // w23
  int v15; // w11
  char v16; // w24
  int v17; // w21
  unsigned int v18; // w22
  unsigned int v19; // w12
  unsigned int v20; // w8
  __int64 v21; // x8
  unsigned int v22; // w25
  unsigned int v23; // w0
  unsigned int v24; // w10
  unsigned int v25; // w9
  char v26; // w10
  unsigned int *v27; // x9
  unsigned int *v28; // x10
  char v31; // w9
  unsigned int *v35; // [xsp+8h] [xbp-28h] BYREF
  unsigned int *v36; // [xsp+10h] [xbp-20h]
  unsigned int *v37; // [xsp+18h] [xbp-18h]
  unsigned int *v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v6 = 0;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a5[1];
  v35 = *a5;
  v36 = v7;
  v8 = a5[3];
  v37 = a5[2];
  v38 = v8;
  if ( !a3 || !a4 )
    goto LABEL_42;
  v11 = **a5;
  if ( (unsigned int)v11 < 6 )
  {
    v13 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * v11 + 328) + 56LL);
    v14 = (v13 & 0xC000000C) != 0;
    if ( (v13 & 8) != 0 )
    {
      v16 = 1;
    }
    else
    {
      v15 = ((unsigned int)v13 >> 2) & 1;
      if ( (v13 & 0xC0000000) == 0 )
        LOBYTE(v15) = 0;
      if ( v13 < 0 )
        v16 = 1;
      else
        v16 = v15;
    }
    v17 = a3[1];
    v18 = (unsigned __int8)(*(unsigned __int16 *)(a4 + 2) >> 5);
    v19 = a2 >> 2;
    if ( (*(_QWORD *)(a1 + 96) & 0x40000000000LL) != 0 )
      v20 = a2 >> 30;
    else
      v20 = 0;
    v21 = v20 & 0xFFFFFFCF | (16 * (v19 & 3));
    if ( (unsigned int)v21 <= 0x23 )
    {
      if ( ((1LL << v21) & 0x900080000LL) != 0 )
        goto LABEL_20;
      if ( ((1LL << v21) & 0x60000) != 0 )
      {
        if ( a3[2] )
          v18 = a3[2];
        goto LABEL_25;
      }
      if ( v21 == 16 )
      {
LABEL_20:
        v18 = a3[2];
        goto LABEL_25;
      }
    }
    if ( (unsigned int)(v21 - 2) >= 2 )
    {
      if ( (_DWORD)v21 == 1 )
      {
        v16 = 0;
      }
      else
      {
        v18 = 0;
        v16 = 0;
        v14 = 0;
      }
    }
LABEL_25:
    v22 = (unsigned int)ieee80211_channel_to_freq_khz(a3[1], v11) / 0x3E8;
    v23 = ieee80211_channel_to_freq_khz(v18, **a5);
    v24 = *a3;
    v6 = 0;
    if ( v24 > 1 )
    {
      if ( v24 == 2 )
      {
        LODWORD(v36) = 5;
        HIDWORD(v36) = v22;
      }
      else
      {
        if ( v24 != 3 )
          goto LABEL_42;
        LODWORD(v37) = v23 / 0x3E8;
        LODWORD(v36) = 4;
        HIDWORD(v36) = v22;
      }
    }
    else if ( *a3 )
    {
      if ( v24 == 1 )
      {
        LODWORD(v36) = 3;
        HIDWORD(v36) = v22;
        if ( v18 )
        {
          v25 = v18 - v17;
          v26 = !v14;
          if ( (int)(v18 - v17) < 0 )
            v25 = v17 - v18;
          if ( v25 != 8 )
            v26 = 1;
          if ( (v26 & 1) != 0 )
          {
            _CF = v25 >= 9;
            v31 = v16 ^ 1;
            if ( !_CF )
              v31 = 1;
            if ( (v31 & 1) == 0 )
            {
              LODWORD(v37) = v23 / 0x3E8;
              LODWORD(v36) = 4;
            }
          }
          else
          {
            LODWORD(v36) = 5;
            HIDWORD(v36) = v23 / 0x3E8;
          }
        }
        goto LABEL_39;
      }
LABEL_42:
      _ReadStatusReg(SP_EL0);
      return v6;
    }
LABEL_39:
    if ( (cfg80211_chandef_valid(&v35) & 1) != 0 )
    {
      v27 = v36;
      *a5 = v35;
      a5[1] = v27;
      v28 = v38;
      v6 = 1;
      a5[2] = v37;
      a5[3] = v28;
    }
    else
    {
      v6 = 0;
    }
    goto LABEL_42;
  }
  __break(0x5512u);
  __asm { STTR            W25, [X28,#0x94] }
  return ieee80211_chandef_eht_oper(a1, v11);
}
