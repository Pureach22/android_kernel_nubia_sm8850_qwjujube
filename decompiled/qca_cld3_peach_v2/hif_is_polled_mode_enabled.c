__int64 __fastcall hif_is_polled_mode_enabled(__int64 a1)
{
  unsigned int v1; // w8
  bool v2; // w9
  unsigned int i; // w11
  __int64 v4; // x12

  v1 = *(_DWORD *)(a1 + 656);
  if ( !v1 )
    return 1;
  v2 = 0;
  for ( i = 0; i != v1; v2 = i >= v1 )
  {
    v4 = *(_QWORD *)(a1 + 27400) + 32LL * (int)i;
    if ( v4 && *(_DWORD *)(v4 + 16) && (*(_BYTE *)v4 & 0x10) == 0 )
      break;
    ++i;
  }
  return v2;
}
