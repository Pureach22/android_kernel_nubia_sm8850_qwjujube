__int64 __fastcall hdd_wmm_is_active(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 3001) == 1 )
    return *(_BYTE *)(a1 + 3000) & 1;
  else
    return 0;
}
