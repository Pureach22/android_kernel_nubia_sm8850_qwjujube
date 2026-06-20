__int64 __fastcall qdf_event_reset(__int64 a1)
{
  if ( !a1 )
    return 5;
  if ( *(_DWORD *)(a1 + 32) != 305402420 )
    return 4;
  *(_WORD *)(a1 + 36) = 0;
  *(_DWORD *)a1 = 0;
  return 0;
}
