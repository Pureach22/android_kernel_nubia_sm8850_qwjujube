bool __fastcall mlo_peer_is_assoc_peer(__int64 a1, __int64 a2)
{
  _BOOL8 result; // x0

  result = 0;
  if ( a1 )
  {
    if ( a2 )
      return *(_QWORD *)(a1 + 16) == a2;
  }
  return result;
}
