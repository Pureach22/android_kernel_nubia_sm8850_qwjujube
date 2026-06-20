__int64 __fastcall ieee80211_send_auth(
        __int64 a1,
        __int16 a2,
        __int16 a3,
        __int16 a4,
        const void *a5,
        unsigned int a6,
        int *a7,
        int *a8,
        __int64 a9,
        unsigned __int8 a10,
        unsigned __int8 a11,
        int a12)
{
  __int64 v13; // x24
  int v18; // w27
  __int64 v19; // x22
  int v20; // w9
  __int64 result; // x0
  __int64 v23; // x21
  int v24; // w8
  __int64 v25; // x9
  __int64 v26; // x0
  _WORD *v27; // x22
  int v28; // w9
  int v29; // w8
  void *v30; // x0
  __int64 v31; // x0
  __int64 v32; // [xsp+0h] [xbp-30h]
  _BYTE v35[12]; // [xsp+1Ch] [xbp-14h]

  v13 = a1 + 5842;
  _ReadStatusReg(SP_EL0);
  v18 = *(unsigned __int16 *)(a1 + 5800);
  *(_WORD *)&v35[4] = 1792;
  v19 = *(_QWORD *)(a1 + 1616);
  *(_DWORD *)v35 = 7015167;
  if ( *(_WORD *)(a1 + 5800) )
    v20 = 12;
  else
    v20 = 0;
  *(_DWORD *)&v35[6] = *(_DWORD *)(a1 + 5842);
  *(_WORD *)&v35[10] = *(_WORD *)(a1 + 5846);
  result = _netdev_alloc_skb(0, a6 + v20 + *(_DWORD *)(v19 + 104) + 38, 2080);
  if ( result )
  {
    v23 = result;
    v32 = v19;
    v24 = *(_DWORD *)(v19 + 104) + 4;
    v25 = *(_QWORD *)(result + 224) + v24;
    *(_DWORD *)(result + 208) += v24;
    *(_QWORD *)(result + 224) = v25;
    v26 = skb_put(result, 30);
    *(_QWORD *)(v26 + 2) = 0;
    v27 = (_WORD *)v26;
    *(_QWORD *)(v26 + 10) = 0;
    *(_QWORD *)(v26 + 18) = 0;
    *(_DWORD *)(v26 + 26) = 0;
    *(_WORD *)v26 = 176;
    v28 = *a7;
    *(_WORD *)(v26 + 8) = *((_WORD *)a7 + 2);
    *(_DWORD *)(v26 + 4) = v28;
    LOWORD(v28) = *(_WORD *)(v13 + 4);
    *(_DWORD *)(v26 + 10) = *(_DWORD *)v13;
    *(_WORD *)(v26 + 14) = v28;
    v29 = *a8;
    LOWORD(v28) = *((_WORD *)a8 + 2);
    *(_WORD *)(v26 + 24) = a3;
    *(_WORD *)(v26 + 26) = a2;
    *(_DWORD *)(v26 + 16) = v29;
    *(_WORD *)(v26 + 20) = v28;
    *(_WORD *)(v26 + 28) = a4;
    if ( a5 )
    {
      v30 = (void *)skb_put(v23, a6);
      memcpy(v30, a5, a6);
    }
    if ( v18 )
    {
      v31 = skb_put(v23, 12);
      *(_QWORD *)v31 = *(_QWORD *)v35;
      *(_DWORD *)(v31 + 8) = *(_DWORD *)&v35[8];
    }
    if ( a2 == 3 && a3 == 1 && (*v27 |= 0x4000u, (unsigned int)ieee80211_wep_encrypt(v32, v23, a9, a10, a11)) )
    {
      __break(0x800u);
      result = sk_skb_reason_drop(0);
    }
    else
    {
      *(_DWORD *)(v23 + 40) |= a12 | 0x10000;
      result = ieee80211_tx_skb_tid(a1, v23, 7, -1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
