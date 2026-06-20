__int64 __fastcall ieee80211_send_delba(__int64 a1, __int64 a2, __int16 a3, __int16 a4, __int16 a5)
{
  __int64 v5; // x24
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x9
  __int64 v15; // x0
  _WORD *v16; // x24
  int v17; // w8
  _WORD *v18; // x8

  v5 = *(_QWORD *)(a1 + 1616);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v5 + 104) + 50), 2080);
  if ( result )
  {
    v12 = *(int *)(v5 + 104);
    v13 = result;
    v14 = *(_QWORD *)(result + 224) + v12;
    LODWORD(v12) = *(_DWORD *)(result + 208) + v12;
    *(_QWORD *)(result + 224) = v14;
    *(_DWORD *)(result + 208) = v12;
    v15 = skb_put(result, 24);
    *(_QWORD *)v15 = 0;
    *(_QWORD *)(v15 + 8) = 0;
    v16 = (_WORD *)v15;
    *(_QWORD *)(v15 + 16) = 0;
    *(_DWORD *)(v15 + 4) = *(_DWORD *)a2;
    *(_WORD *)(v15 + 8) = *(_WORD *)(a2 + 4);
    *(_DWORD *)(v15 + 10) = *(_DWORD *)(a1 + 5842);
    *(_WORD *)(v15 + 14) = *(_WORD *)(a1 + 5846);
    v17 = *(_DWORD *)(a1 + 4720);
    if ( v17 <= 2 )
    {
      if ( v17 == 1 )
      {
        *(_DWORD *)(v15 + 16) = *(_DWORD *)(a1 + 2346);
        v18 = (_WORD *)(a1 + 2350);
      }
      else
      {
        if ( v17 != 2 )
        {
LABEL_11:
          *(_WORD *)v15 = 208;
          skb_put(v13, 6);
          v16[12] = 515;
          v16[14] = a5;
          v16[13] = (a4 << 11) | (a3 << 12);
          return ieee80211_tx_skb_tid(a1, v13, 7, 0xFFFFFFFFLL);
        }
        *(_DWORD *)(v15 + 16) = *(_DWORD *)(a1 + 4802);
        v18 = (_WORD *)(a1 + 4806);
      }
    }
    else
    {
      if ( (unsigned int)(v17 - 3) >= 2 && v17 != 7 )
        goto LABEL_11;
      v18 = (_WORD *)(a1 + 5846);
      *(_DWORD *)(v15 + 16) = *(_DWORD *)(a1 + 5842);
    }
    *(_WORD *)(v15 + 20) = *v18;
    goto LABEL_11;
  }
  return result;
}
