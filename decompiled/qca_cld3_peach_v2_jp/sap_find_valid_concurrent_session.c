__int64 __fastcall sap_find_valid_concurrent_session(__int64 a1)
{
  __int64 v1; // x8

  if ( (*(_DWORD *)(a1 + 14824) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14816);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14840) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14832);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14856) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14848);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14872) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14864);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14888) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14880);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 728) )
        return v1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14904) | 2) == 3 && (v1 = *(_QWORD *)(a1 + 14896)) != 0 && *(_DWORD *)(v1 + 728) )
    return v1;
  else
    return 0;
}
