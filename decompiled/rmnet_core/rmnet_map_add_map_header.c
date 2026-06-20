__int64 __fastcall rmnet_map_add_map_header(_DWORD *a1, int a2, int a3, __int64 a4)
{
  int v4; // w23
  __int64 result; // x0
  char v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w21
  size_t v13; // x20
  char *v14; // x22
  void *v15; // x0

  v4 = a1[28];
  result = skb_push(a1, 4);
  *(_DWORD *)result = 0;
  v10 = 0;
  if ( (*(_BYTE *)(a4 + 8) & 0x40) != 0 )
  {
    v10 = 64;
    *(_BYTE *)result = 64;
  }
  v11 = v4 - a2;
  if ( a3 )
  {
    v12 = (v11 + 3) & 0xFFFFFFFC;
    v13 = v12 - v11;
    if ( v12 != v11 )
    {
      if ( a1[29] )
      {
        if ( (_DWORD)v13 )
          return 0;
      }
      else if ( a1[53] - a1[52] < (unsigned int)v13 )
      {
        return 0;
      }
      v14 = (char *)result;
      v15 = (void *)skb_put(a1, (unsigned int)v13);
      memset(v15, 0, v13);
      v10 = *v14;
      result = (__int64)v14;
    }
    *(_BYTE *)result = v10 & 0xC0 | v13 & 0x3F;
    *(_WORD *)(result + 2) = bswap32(v12) >> 16;
  }
  else
  {
    *(_WORD *)(result + 2) = bswap32(v11) >> 16;
  }
  return result;
}
