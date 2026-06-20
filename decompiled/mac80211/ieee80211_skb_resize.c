__int64 __fastcall ieee80211_skb_resize(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x19
  unsigned int v5; // w8
  int v6; // w8
  char v7; // w9
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 result; // x0

  v4 = *(_QWORD *)(a1 + 1616);
  if ( a4 == 1 )
    goto LABEL_4;
  if ( a4 != 2 )
  {
    v7 = 0;
    v5 = 0;
    if ( (*(_BYTE *)(a2 + 126) & 1) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  v5 = *(_DWORD *)(a1 + 1528);
  if ( !v5 )
  {
    v7 = 0;
    if ( (*(_BYTE *)(a2 + 126) & 1) == 0 )
      goto LABEL_11;
LABEL_10:
    v8 = *(_QWORD *)(a2 + 216);
    v9 = v8 + *(unsigned int *)(a2 + 212);
    if ( (unsigned __int16)*(_DWORD *)(v9 + 32) != 1 )
    {
      if ( (*(_QWORD *)(v4 + 96) & 0x8000000) == 0
        || (unsigned __int16)*(_DWORD *)(v9 + 32) - (*(int *)(v9 + 32) >> 16) != 1 )
      {
        goto LABEL_18;
      }
      if ( *(_DWORD *)(a2 + 224) - (int)v8 + 14 > (unsigned int)*(unsigned __int16 *)(a2 + 122) )
        v7 = 1;
      if ( (v7 & 1) != 0 )
        goto LABEL_18;
    }
    goto LABEL_11;
  }
LABEL_4:
  if ( *(_DWORD *)(a2 + 116) )
    v6 = 18;
  else
    v6 = *(_DWORD *)(a2 + 208) - *(_DWORD *)(a2 + 212) + 18;
  v5 = v6 & ~(v6 >> 31);
  v7 = 1;
  if ( (*(_BYTE *)(a2 + 126) & 1) != 0 )
    goto LABEL_10;
LABEL_11:
  if ( !(a3 | v5) )
    return 0;
LABEL_18:
  result = pskb_expand_head(a2, a3, v5, 2080);
  if ( (_DWORD)result )
  {
    dev_printk(&unk_BBEF5, *(_QWORD *)(v4 + 72) + 392LL, "failed to reallocate TX buffer\n");
    return 4294967284LL;
  }
  return result;
}
