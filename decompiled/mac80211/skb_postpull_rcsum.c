__int64 __fastcall skb_postpull_rcsum(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w9
  __int64 v4; // x19

  v2 = *(unsigned __int8 *)(result + 128);
  v3 = (v2 >> 5) & 3;
  if ( v3 == 3 )
  {
    if ( *(_DWORD *)(result + 216) - *(_DWORD *)(result + 224) + *(unsigned __int16 *)(result + 140) < 0 )
      *(_BYTE *)(result + 128) = v2 & 0x9F;
  }
  else if ( v3 == 2 )
  {
    v4 = result;
    result = csum_partial(a2, 8, (unsigned int)-*(_DWORD *)(result + 140));
    *(_DWORD *)(v4 + 140) = -(int)result;
  }
  return result;
}
