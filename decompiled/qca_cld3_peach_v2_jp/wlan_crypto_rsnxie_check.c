__int64 __fastcall wlan_crypto_rsnxie_check(__int64 result, __int64 a2)
{
  int v2; // w8
  char *v3; // x9
  _BYTE *v4; // x10
  char v5; // t1

  v2 = *(unsigned __int8 *)(a2 + 1);
  if ( *(_BYTE *)(a2 + 1) )
  {
    v3 = (char *)(a2 + 2);
    v4 = (_BYTE *)(result + 156);
    do
    {
      v5 = *v3++;
      --v2;
      *v4++ = v5;
    }
    while ( (_BYTE)v2 );
  }
  *(_BYTE *)(result + 156) &= 0xF0u;
  return result;
}
