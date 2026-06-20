_BYTE *__fastcall ieee80211_wep_add_iv(__int64 a1, __int64 a2, int a3, char a4)
{
  _WORD *v4; // x9
  unsigned int v5; // w8
  unsigned int v10; // w24
  __int64 v11; // x23
  __int64 v12; // x8
  int v13; // w9
  _BYTE *result; // x0
  int v15; // w8
  int v16; // w8

  v4 = *(_WORD **)(a2 + 224);
  v5 = (unsigned __int16)*v4 | 0x4000;
  *v4 |= 0x4000u;
  if ( ((*(_DWORD *)(a2 + 224) - *(_DWORD *)(a2 + 216)) & 0xFFFFFFFC) != 0 )
  {
    v10 = ieee80211_hdrlen(v5);
    v11 = skb_push(a2, 4);
    memmove((void *)v11, (const void *)(v11 + 4), v10);
    v12 = *(_QWORD *)(a2 + 72);
    if ( v12 && (*(_WORD *)(v12 + 16) & 0x20) != 0 )
    {
      return (_BYTE *)(v11 + v10);
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 4608);
      result = (_BYTE *)(v11 + v10);
      v15 = v13 + 1;
      *(_DWORD *)(a1 + 4608) = v13 + 1;
      if ( (~(v13 + 1) & 0xFF00) == 0 && BYTE2(v15) >= 3u && BYTE2(v15) < a3 + 3 )
      {
        v15 = v13 + 257;
        *(_DWORD *)(a1 + 4608) = v13 + 257;
      }
      if ( result )
      {
        *result = BYTE2(v15);
        result[1] = BYTE1(*(_DWORD *)(a1 + 4608));
        v16 = *(_DWORD *)(a1 + 4608);
        result[3] = a4 << 6;
        result[2] = v16;
      }
    }
  }
  else
  {
    __break(0x800u);
    return nullptr;
  }
  return result;
}
