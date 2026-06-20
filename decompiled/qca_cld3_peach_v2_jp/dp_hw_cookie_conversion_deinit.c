__int64 __fastcall dp_hw_cookie_conversion_deinit(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned int v3; // w8
  __int64 v4; // x11

  if ( *(_DWORD *)(a2 + 4) )
  {
    v2 = *(_QWORD *)(a2 + 8);
    v3 = 0;
    do
    {
      v4 = v2 + 24LL * (int)v3++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22552) + 24LL * *(unsigned int *)(v4 + 16)) = 0;
    }
    while ( v3 < *(_DWORD *)(a2 + 4) );
  }
  return 0;
}
