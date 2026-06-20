__int64 __fastcall ieee80211_eht_cap_ie_to_sta_eht_cap(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 *a5,
        unsigned __int8 a6,
        __int64 a7)
{
  __int64 v7; // x21
  int v9; // w8
  unsigned int v10; // w10
  __int64 v11; // x9
  char v12; // w11
  __int64 v13; // x10
  __int64 v14; // x11
  int v15; // w9
  unsigned __int8 v16; // w20
  int v17; // w10
  int v18; // w9
  char v19; // w8
  unsigned __int8 v20; // w23
  unsigned int v21; // w24
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x19
  __int64 v25; // x23
  __int64 v26; // x24
  __int64 *v27; // x25
  __int16 v28; // w26
  unsigned int v29; // w8

  v7 = *(_QWORD *)(a7 + 920);
  *(_QWORD *)(v7 + 186) = 0;
  *(_QWORD *)(v7 + 181) = 0;
  *(_QWORD *)(v7 + 173) = 0;
  *(_QWORD *)(v7 + 165) = 0;
  *(_QWORD *)(v7 + 141) = 0;
  *(_QWORD *)(v7 + 157) = 0;
  *(_QWORD *)(v7 + 149) = 0;
  if ( !a5 )
    return result;
  v9 = *(_DWORD *)(result + 4720);
  if ( *(_BYTE *)(result + 5848) != 1 )
    goto LABEL_7;
  if ( v9 != 2 )
  {
    if ( v9 == 3 )
    {
      v10 = 9;
      v11 = *(unsigned __int16 *)(a2 + 92);
      if ( !*(_WORD *)(a2 + 92) )
        return result;
      goto LABEL_9;
    }
LABEL_7:
    v10 = (unsigned __int8)*(_DWORD *)(result + 4720);
    if ( v10 >= 0xC )
    {
      __break(0x800u);
      return result;
    }
    v11 = *(unsigned __int16 *)(a2 + 92);
    if ( !*(_WORD *)(a2 + 92) )
      return result;
    goto LABEL_9;
  }
  v10 = 8;
  v11 = *(unsigned __int16 *)(a2 + 92);
  if ( !*(_WORD *)(a2 + 92) )
    return result;
LABEL_9:
  if ( v10 == 4 )
    v12 = 3;
  else
    v12 = v10;
  v13 = *(_QWORD *)(a2 + 96);
  v14 = 1LL << v12;
  while ( ((unsigned __int16)v14 & *(_WORD *)v13) == 0 )
  {
    --v11;
    v13 += 128;
    if ( !v11 )
      return result;
  }
  if ( v13 && v13 != -59 && (*(_BYTE *)(v13 + 59) & 1) != 0 )
  {
    v15 = *(unsigned __int8 *)(a3 + 6);
    v16 = 3;
    if ( (v15 & 2) == 0 )
    {
      v17 = (v15 << 29 >> 31) & 3;
      if ( (v15 & 8) != 0 )
        v17 += 3;
      if ( (*((_BYTE *)a5 + 2) & 2) != 0 )
        v18 = v17 + 3;
      else
        v18 = v17;
      if ( v9 == 2 )
        v19 = 3;
      else
        v19 = 4;
      if ( v18 )
        v16 = v18;
      else
        v16 = v19;
    }
    v20 = v16 + 11;
    if ( (*((_BYTE *)a5 + 7) & 8) != 0 )
    {
      if ( (unsigned __int64)v16 + 13 > a6 )
        return result;
      v26 = a7;
      v27 = a5;
      v28 = *(_WORD *)((char *)a5 + v16 + 11);
      result = _sw_hweight16(v28 & 0x1F0);
      v29 = result * (6 * (v28 & 0xF) + 6) + 16;
      if ( (unsigned __int8)(v29 >> 3) > 0x20u )
        return result;
      a7 = v26;
      v21 = v29 >> 3;
      a5 = v27;
      v20 += v29 >> 3;
    }
    else
    {
      LOBYTE(v21) = 0;
    }
    if ( v20 <= (unsigned int)a6 )
    {
      v22 = *(_DWORD *)((char *)a5 + 7);
      v23 = *a5;
      v24 = (__int64)a5 + 11;
      v25 = a7;
      *(_QWORD *)(v7 + 153) = 0;
      *(_DWORD *)(v7 + 149) = v22;
      *(_QWORD *)(v7 + 142) = v23;
      *(_BYTE *)(v7 + 161) = 0;
      memcpy((void *)(v7 + 153), (char *)a5 + 11, v16);
      if ( (_BYTE)v21 )
        memcpy((void *)(v7 + 162), (const void *)(v24 + v16), (unsigned __int8)v21);
      *(_BYTE *)(v7 + 141) = 1;
      *(_DWORD *)(v25 + 912) = ((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_sta_cap_rx_bw)(v25, 0);
      result = ieee80211_sta_cur_vht_bw(v25, 0);
      *(_DWORD *)(*(_QWORD *)(v25 + 920) + 232LL) = result;
    }
  }
  return result;
}
