__int64 __fastcall ieee80211_crypto_tkip_encrypt(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x8
  unsigned __int16 *v5; // x23
  __int64 v6; // x21
  int v7; // w24
  unsigned int v8; // w22
  int v9; // w28
  __int64 v10; // x23
  __int64 v11; // x8
  __int64 v13; // x0
  __int64 v14; // x23
  unsigned __int64 v20; // x2
  unsigned __int64 v21; // x2

  ieee80211_tx_set_protected(a1);
  v2 = a1 + 8;
  while ( 1 )
  {
    v2 = *(_QWORD *)v2;
    if ( v2 == a1 + 8 )
      return 0;
    v4 = *(_QWORD *)(v2 + 72);
    v5 = *(unsigned __int16 **)(v2 + 224);
    v6 = *(_QWORD *)(a1 + 56);
    if ( !v4 )
      break;
    v7 = 0;
    v3 = 0;
    if ( (*(_WORD *)(v4 + 16) & 0x22) != 0 )
      goto LABEL_9;
LABEL_3:
    if ( v3 < 0 )
      return 1;
  }
  v7 = 4;
LABEL_9:
  v8 = ieee80211_hdrlen(*v5);
  if ( *(_DWORD *)(v2 + 116) )
  {
    if ( v7 > 0 )
      goto LABEL_22;
  }
  else if ( *(_DWORD *)(v2 + 212) - *(_DWORD *)(v2 + 208) < v7 )
  {
    goto LABEL_22;
  }
  if ( (((_DWORD)v5 - *(_DWORD *)(v2 + 216)) & 0xFFFFFFF8) != 0 )
  {
    v9 = *(_DWORD *)(v2 + 112);
    v10 = skb_push(v2, 8);
    memmove((void *)v10, (const void *)(v10 + 8), v8);
    v11 = *(_QWORD *)(v2 + 72);
    if ( v11 && (*(_WORD *)(v11 + 16) & 0x20) != 0 )
      goto LABEL_2;
    _X1 = (unsigned __int64 *)(v6 + 536);
    __asm { PRFM            #0x11, [X1] }
    do
    {
      v20 = __ldxr(_X1);
      v21 = v20 + 1;
    }
    while ( __stlxr(v21, _X1) );
    __dmb(0xBu);
    v13 = ieee80211_tkip_add_iv(v10 + v8, (__int64)_X1, v21);
    if ( *(_QWORD *)(v2 + 72) )
    {
LABEL_2:
      v3 = 0;
    }
    else
    {
      v14 = v13;
      skb_put(v2, 4);
      v3 = ieee80211_tkip_encrypt_data(*(_QWORD *)(a1 + 32) + 2544LL, v6, v2, v14, (int)(v9 - v8));
    }
    goto LABEL_3;
  }
LABEL_22:
  __break(0x800u);
  return 1;
}
