__int64 __fastcall wlan_hdd_get_rates(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  __int64 v4; // x10
  int v5; // w8
  __int64 v6; // x9
  __int64 result; // x0
  int v8; // w13
  unsigned __int16 *v9; // x15
  int v10; // t1

  if ( !a4 )
    return 0;
  v4 = *(_QWORD *)(a1 + 8LL * a2 + 328);
  v5 = *(_DWORD *)(v4 + 24);
  if ( !v5 )
    return 0;
  v6 = 0;
  LODWORD(result) = 0;
  do
  {
    v8 = 0;
    v9 = (unsigned __int16 *)(*(_QWORD *)(v4 + 8) + 4LL);
    while ( 1 )
    {
      v10 = *v9;
      v9 += 6;
      if ( 5 * (*(_BYTE *)(a3 + v6) & 0x7F) == v10 )
        break;
      if ( v5 == ++v8 )
        return 0;
    }
    ++v6;
    result = (1 << v8) | (unsigned int)result;
  }
  while ( v6 != a4 );
  return result;
}
