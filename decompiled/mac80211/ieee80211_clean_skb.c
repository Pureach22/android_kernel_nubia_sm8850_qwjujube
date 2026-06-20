_DWORD *__fastcall ieee80211_clean_skb(_DWORD *result, int a2, unsigned int a3)
{
  int v4; // w1
  _DWORD *v5; // x20
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w8
  __int64 v9; // x9
  unsigned __int16 *v10; // x22
  __int16 v11; // w19
  _DWORD *v12; // x20
  __int64 v13; // x8
  __int64 v14; // x21
  unsigned int v15; // w20
  __int64 v16; // x9

  if ( a2 )
  {
    v4 = result[28] - a2;
    if ( result[29] )
    {
      v5 = result;
      __pskb_trim();
      result = v5;
    }
    else
    {
      v6 = result[56];
      v7 = result[54];
      result[28] = v4;
      result[52] = v4 + v6 - v7;
    }
  }
  v8 = result[28];
  if ( a3 <= v8 - result[29] )
    goto LABEL_6;
  if ( v8 >= a3 )
  {
    v12 = result;
    v13 = _pskb_pull_tail(result);
    result = v12;
    if ( v13 )
    {
      v8 = v12[28];
LABEL_6:
      v9 = *((_QWORD *)result + 28);
      result[28] = v8 - a3;
      *((_QWORD *)result + 28) = v9 + a3;
    }
  }
  v10 = *((unsigned __int16 **)result + 28);
  result[16] &= 0xE3EFFFFF;
  v11 = *v10;
  if ( (*v10 & 0x800C) == 0x8000 )
  {
    v14 = (__int64)result;
    v15 = ieee80211_hdrlen(*v10);
    *v10 = v11 & 0x7FF3;
    if ( pskb_may_pull(v14, v15) )
    {
      memmove((void *)(*(_QWORD *)(v14 + 224) + 4LL), *(const void **)(v14 + 224), v15 - 4);
      if ( pskb_may_pull(v14, 4u) )
      {
        v16 = *(_QWORD *)(v14 + 224) + 4LL;
        *(_DWORD *)(v14 + 112) -= 4;
        *(_QWORD *)(v14 + 224) = v16;
        return (_DWORD *)v14;
      }
      else
      {
        return (_DWORD *)v14;
      }
    }
    else
    {
      consume_skb(v14);
      return nullptr;
    }
  }
  return result;
}
