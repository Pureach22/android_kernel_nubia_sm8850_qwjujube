__int64 __fastcall qdf_event_set(__int64 a1, __int64 a2)
{
  if ( !a1 )
    return 5;
  if ( *(_DWORD *)(a1 + 32) != 305402420 )
    return 4;
  *(_BYTE *)(a1 + 36) = 1;
  complete(a1, a2);
  return 0;
}
