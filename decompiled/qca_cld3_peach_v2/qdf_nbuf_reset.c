__int64 __fastcall qdf_nbuf_reset(__int64 a1)
{
  __int64 v2; // x1
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w10

  skb_push(a1, (unsigned int)(*(_DWORD *)(a1 + 224) - *(_DWORD *)(a1 + 216)));
  if ( *(_DWORD *)(a1 + 116) )
    v2 = 0;
  else
    v2 = (unsigned int)(*(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208));
  skb_put(a1, v2);
  memset(*(void **)(a1 + 224), 0, *(unsigned int *)(a1 + 112));
  result = skb_trim(a1, 0);
  v4 = *(_QWORD *)(a1 + 224);
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  v5 = v4 + 64;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  LODWORD(v6) = 8 - (v5 & 7);
  v7 = *(_DWORD *)(a1 + 208);
  if ( (v5 & 7) != 0 )
    v6 = (unsigned int)v6;
  else
    v6 = 0;
  *(_BYTE *)(a1 + 68) = 3;
  *(_QWORD *)(a1 + 224) = v5 + v6 + 40;
  *(_DWORD *)(a1 + 208) = v7 + v6 + 104;
  return result;
}
