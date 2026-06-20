__int64 __fastcall coresight_enabled_sink(__int64 a1, _BYTE *a2)
{
  if ( (*(_DWORD *)(a1 - 48) | 2) != 2 || *(_BYTE *)(a1 + 925) != 1 )
    return 0;
  if ( *a2 == 1 )
    *(_BYTE *)(a1 + 925) = 0;
  return 1;
}
