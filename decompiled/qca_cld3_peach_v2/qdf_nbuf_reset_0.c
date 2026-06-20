__int64 __fastcall qdf_nbuf_reset_0(__int64 a1, unsigned int a2)
{
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // x8
  int v7; // w10
  unsigned __int64 v8; // x9
  int v9; // w8
  int v10; // w10
  int v11; // w10

  skb_push(a1, (unsigned int)(*(_DWORD *)(a1 + 224) - *(_DWORD *)(a1 + 216)));
  if ( *(_DWORD *)(a1 + 116) )
    v4 = 0;
  else
    v4 = (unsigned int)(*(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208));
  skb_put(a1, v4);
  memset(*(void **)(a1 + 224), 0, *(unsigned int *)(a1 + 112));
  result = skb_trim(a1, 0);
  v6 = *(_QWORD *)(a1 + 224);
  v7 = *(_DWORD *)(a1 + 208);
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  v8 = v6 + 64;
  v9 = v7 + 64;
  *(_QWORD *)(a1 + 224) = v8;
  *(_DWORD *)(a1 + 208) = v7 + 64;
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_BYTE *)(a1 + 68) = 3;
  if ( a2 )
  {
    v10 = v8 % a2;
    if ( v10 )
    {
      v11 = a2 - v10;
      *(_DWORD *)(a1 + 208) = v11 + v9;
      *(_QWORD *)(a1 + 224) = v8 + v11;
    }
  }
  return result;
}
