__int64 __fastcall pskb_trim(_DWORD *a1, __int64 a2)
{
  int v3; // w8
  int v4; // w9

  if ( a1[28] > (unsigned int)a2 )
  {
    if ( a1[29] )
      return __pskb_trim(a1, a2);
    v3 = a1[56];
    v4 = a1[54];
    a1[28] = a2;
    a1[52] = v3 - v4 + a2;
  }
  return 0;
}
