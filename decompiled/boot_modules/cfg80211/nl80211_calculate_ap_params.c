__int64 __fastcall nl80211_calculate_ap_params(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x21
  __int64 elem_match; // x0
  unsigned __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w11
  __int64 v8; // x0
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w11
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  _BYTE *v16; // x0
  __int64 v17; // x10
  unsigned int v18; // w8
  unsigned __int8 v19; // w22
  int v20; // w8
  int v21; // w23
  int v22; // w10
  int v23; // w8
  __int16 v24; // w24
  __int64 v25; // x0
  unsigned int v26; // w8
  unsigned int v27; // w9
  char s2[4]; // [xsp+8h] [xbp-18h] BYREF
  char v30[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v31[4]; // [xsp+10h] [xbp-10h] BYREF
  char v32[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 136);
  v3 = *(_QWORD *)(a1 + 48);
  elem_match = cfg80211_find_elem_match(1, v3, v2, nullptr, 0);
  if ( elem_match && *(_BYTE *)(elem_match + 1) )
  {
    v5 = 0;
    v6 = elem_match + 2;
    do
    {
      v7 = *(unsigned __int8 *)(v6 + v5);
      if ( v7 == 127 )
      {
        *(_BYTE *)(a1 + 808) = 1;
        v7 = *(unsigned __int8 *)(v6 + v5);
        if ( v7 != 126 )
          goto LABEL_7;
      }
      else if ( v7 != 126 )
      {
LABEL_7:
        if ( v7 == 122 )
          goto LABEL_8;
        goto LABEL_12;
      }
      *(_BYTE *)(a1 + 809) = 1;
      v7 = *(unsigned __int8 *)(v6 + v5);
      if ( v7 == 122 )
      {
LABEL_8:
        *(_BYTE *)(a1 + 810) = 1;
        if ( *(_BYTE *)(v6 + v5) == 123 )
          goto LABEL_13;
        goto LABEL_4;
      }
LABEL_12:
      if ( v7 == 123 )
LABEL_13:
        *(_BYTE *)(a1 + 811) = 1;
LABEL_4:
      ++v5;
    }
    while ( v5 < *(unsigned __int8 *)(elem_match + 1) );
  }
  v8 = cfg80211_find_elem_match(50, v3, v2, nullptr, 0);
  if ( v8 && *(_BYTE *)(v8 + 1) )
  {
    v9 = 0;
    v10 = v8 + 2;
    do
    {
      v11 = *(unsigned __int8 *)(v10 + v9);
      if ( v11 == 127 )
      {
        *(_BYTE *)(a1 + 808) = 1;
        v11 = *(unsigned __int8 *)(v10 + v9);
        if ( v11 != 126 )
          goto LABEL_20;
      }
      else if ( v11 != 126 )
      {
LABEL_20:
        if ( v11 == 122 )
          goto LABEL_21;
        goto LABEL_25;
      }
      *(_BYTE *)(a1 + 809) = 1;
      v11 = *(unsigned __int8 *)(v10 + v9);
      if ( v11 == 122 )
      {
LABEL_21:
        *(_BYTE *)(a1 + 810) = 1;
        if ( *(_BYTE *)(v10 + v9) == 123 )
          goto LABEL_26;
        goto LABEL_17;
      }
LABEL_25:
      if ( v11 == 123 )
LABEL_26:
        *(_BYTE *)(a1 + 811) = 1;
LABEL_17:
      ++v9;
    }
    while ( v9 < *(unsigned __int8 *)(v8 + 1) );
  }
  v12 = cfg80211_find_elem_match(45, v3, v2, nullptr, 0);
  if ( v12 && *(unsigned __int8 *)(v12 + 1) >= 0x1Au )
    *(_QWORD *)(a1 + 760) = v12 + 2;
  v13 = cfg80211_find_elem_match(191, v3, v2, nullptr, 0);
  if ( v13 && *(unsigned __int8 *)(v13 + 1) >= 0xCu )
    *(_QWORD *)(a1 + 768) = v13 + 2;
  s2[0] = 35;
  v14 = cfg80211_find_elem_match(255, v3, v2, s2, 1u);
  if ( v14 && *(unsigned __int8 *)(v14 + 1) >= 0x12u )
    *(_QWORD *)(a1 + 776) = v14 + 3;
  v30[0] = 36;
  v15 = cfg80211_find_elem_match(255, v3, v2, v30, 1u);
  if ( v15 && *(unsigned __int8 *)(v15 + 1) >= 7u )
    *(_QWORD *)(a1 + 784) = v15 + 3;
  v31[0] = 108;
  v16 = (_BYTE *)cfg80211_find_elem_match(255, v3, v2, v31, 1u);
  if ( !v16 )
  {
LABEL_57:
    v32[0] = 106;
    v25 = cfg80211_find_elem_match(255, v3, v2, v32, 1u);
    if ( !v25
      || *(_BYTE *)(v25 + 1)
      && (*(_QWORD *)(a1 + 800) = v25 + 3, v26 = *(unsigned __int8 *)(v25 + 1) - 1, v26 >= 5)
      && ((*(_BYTE *)(v25 + 3) & 1) != 0 ? (v27 = *(_BYTE *)(v25 + 3) & 2 | 8) : (v27 = 5), v27 <= (unsigned __int8)v26) )
    {
      v18 = 0;
      goto LABEL_66;
    }
    goto LABEL_64;
  }
  if ( !v16[1] )
    goto LABEL_64;
  v17 = *(_QWORD *)(a1 + 776);
  v18 = -22;
  *(_QWORD *)(a1 + 792) = v16 + 3;
  if ( v17 )
  {
    v19 = v16[1] - 1;
    if ( v19 >= 0xBu )
    {
      v20 = *(unsigned __int8 *)(v17 + 6);
      v21 = 14;
      if ( (v20 & 2) == 0 )
      {
        v22 = (v20 << 29 >> 31) & 3;
        if ( (v20 & 8) != 0 )
          v22 += 3;
        if ( (v16[5] & 2) != 0 )
          v23 = v22 + 3;
        else
          v23 = v22;
        if ( v23 )
          v21 = v23 + 11;
        else
          v21 = 14;
      }
      if ( (unsigned __int8)v21 > (unsigned int)v19 )
        goto LABEL_64;
      if ( (v16[10] & 8) != 0 )
      {
        if ( (unsigned __int64)(unsigned __int8)v21 + 2 > v19 )
          goto LABEL_64;
        v24 = *(_WORD *)&v16[(unsigned __int8)v21 + 3];
        v21 += ((unsigned int)_sw_hweight16(v24 & 0x1F0) * (6 * (v24 & 0xF) + 6) + 16) >> 3;
      }
      if ( (unsigned __int8)v21 <= (unsigned int)v19 )
        goto LABEL_57;
LABEL_64:
      v18 = -22;
    }
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v18;
}
