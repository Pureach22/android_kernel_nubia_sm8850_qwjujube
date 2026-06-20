bool __fastcall fpm_is_tid_override(__int64 a1, _BYTE *a2)
{
  int v2; // w10

  v2 = *(_DWORD *)(a1 + 168);
  if ( (v2 & 0xF000000) == 0xC000000 )
    *a2 = v2 & 0xF;
  return (v2 & 0xF000000) == 201326592;
}
