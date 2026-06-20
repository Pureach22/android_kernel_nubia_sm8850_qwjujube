__int64 __fastcall sap_find_valid_concurrent_session(__int64 a1)
{
  __int64 v1; // x8

  if ( (*(_DWORD *)(a1 + 14896) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14888);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14912) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14904);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14928) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14920);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14944) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14936);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14960) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14952);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14976) | 2) == 3 && (v1 = *(_QWORD *)(a1 + 14968)) != 0 && *(_DWORD *)(v1 + 728) )
    return v1;
  else
    return 0;
}
