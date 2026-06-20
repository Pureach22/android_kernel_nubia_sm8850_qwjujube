bool __fastcall coresight_sink_by_id(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x8
  _BOOL8 result; // x0

  result = false;
  if ( (*(_DWORD *)(a1 - 48) | 2) == 2 )
  {
    v2 = *(_QWORD *)(a1 + 928);
    if ( v2 )
    {
      if ( *a2 == *(_DWORD *)(v2 + 32) )
        return true;
    }
  }
  return result;
}
