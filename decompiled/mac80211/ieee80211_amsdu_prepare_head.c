__int64 __fastcall ieee80211_amsdu_prepare_head(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x20
  int v7; // w21
  unsigned int v8; // w8
  __int64 v9; // x24
  int v10; // w0
  size_t v11; // x20
  unsigned int v12; // w24
  __int64 v13; // x21
  unsigned __int16 *v14; // x19
  char *v15; // x10
  __int64 v16; // x11
  char *v17; // x9
  char *v18; // x8
  unsigned int v19; // w10
  char *v20; // x10
  __int16 v21; // w11
  __int64 result; // x0
  __int64 v23; // x8

  if ( (*(_BYTE *)(a3 + 41) & 0x10) != 0 )
    return 0;
  if ( (*(_BYTE *)(a3 + 80) & 8) != 0 )
    return 1;
  v3 = *(_QWORD *)(a1 + 1616);
  v5 = a2[8];
  v7 = *(_DWORD *)(a3 + 112);
  v8 = *(_DWORD *)(v3 + 104) + 14;
  if ( v8 > *(_DWORD *)(a3 + 224) - *(_DWORD *)(a3 + 216)
    && (v9 = a3, v10 = pskb_expand_head(a3, v8, 0, 2080), a3 = v9, v10) )
  {
    dev_printk(&unk_BBEF5, *(_QWORD *)(v3 + 72) + 392LL, "failed to reallocate TX buffer\n");
    return 0;
  }
  else
  {
    v11 = v5 - 6;
    v12 = v7 - v11;
    v13 = a3;
    v14 = (unsigned __int16 *)skb_push(a3, 14);
    memmove(v14, v14 + 7, v11);
    v15 = (char *)v14 + v11;
    v16 = a2[10];
    v17 = (char *)v14 + a2[9];
    *((_WORD *)v15 + 6) = bswap32(v12) >> 16;
    *(_DWORD *)(v15 + 6) = *(_DWORD *)v17;
    v18 = (char *)v14 + v16;
    *((_WORD *)v15 + 5) = *((_WORD *)v17 + 2);
    *(_DWORD *)v15 = *(_DWORD *)((char *)v14 + v16);
    *((_WORD *)v15 + 2) = *(unsigned __int16 *)((char *)v14 + v16 + 4);
    v19 = *(_DWORD *)(a1 + 4720) - 2;
    if ( v19 <= 2 )
    {
      v20 = (char *)*(&off_C0ED8 + v19) + a1;
      if ( v20 )
      {
        v21 = *v14;
        if ( (*v14 & 0x200) != 0 )
        {
          *(_DWORD *)v17 = *(_DWORD *)v20;
          v21 = *v14;
          *((_WORD *)v17 + 2) = *((_WORD *)v20 + 2);
        }
        if ( (v21 & 0x100) != 0 )
        {
          *(_DWORD *)v18 = *(_DWORD *)v20;
          *((_WORD *)v18 + 2) = *((_WORD *)v20 + 2);
        }
      }
    }
    result = 1;
    v23 = 12;
    if ( (~*v14 & 0x300) == 0 )
      v23 = 15;
    LOBYTE(v14[v23]) |= 0x80u;
    *(_DWORD *)(v13 + 80) |= 8u;
  }
  return result;
}
