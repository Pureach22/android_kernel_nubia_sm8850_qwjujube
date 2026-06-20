__int64 __fastcall nl80211_register_unexpected_frame(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w9

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 992LL);
  v3 = *(_DWORD *)(v2 + 8);
  if ( v3 != 9 && v3 != 3 )
    return 4294967274LL;
  if ( *(_DWORD *)(v2 + 172) )
    return 4294967280LL;
  *(_DWORD *)(v2 + 172) = *(_DWORD *)(a2 + 4);
  return 0;
}
