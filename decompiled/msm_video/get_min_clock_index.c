__int64 __fastcall get_min_clock_index(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w9
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x9

  v1 = *(_QWORD *)(a1 + 3904);
  v2 = *(_DWORD *)(v1 + 72);
  v3 = *(_QWORD *)(v1 + 64);
  v4 = v3 + 72LL * v2;
  if ( v3 >= v4 )
    return 0;
  while ( *(_BYTE *)(v3 + 20) != 1 )
  {
    v3 += 72LL;
    if ( v3 >= v4 )
      return 0;
  }
  return (unsigned int)(*(_DWORD *)(v3 + 56) - 1);
}
