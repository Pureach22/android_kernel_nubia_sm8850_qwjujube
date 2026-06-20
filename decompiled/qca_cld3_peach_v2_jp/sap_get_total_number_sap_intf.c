__int64 __fastcall sap_get_total_number_sap_intf(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9

  if ( (*(_DWORD *)(a1 + 14824) | 2) == 3 )
  {
    v1 = *(_QWORD *)(a1 + 14816);
    if ( v1 )
      LODWORD(v1) = *(_DWORD *)(v1 + 728) != 0;
  }
  else
  {
    LODWORD(v1) = 0;
  }
  if ( (*(_DWORD *)(a1 + 14840) | 2) == 3 )
  {
    v2 = *(_QWORD *)(a1 + 14832);
    if ( v2 )
    {
      if ( *(_DWORD *)(v2 + 728) )
        LODWORD(v1) = v1 + 1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14856) | 2) == 3 )
  {
    v3 = *(_QWORD *)(a1 + 14848);
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 + 728) )
        LODWORD(v1) = v1 + 1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14872) | 2) == 3 )
  {
    v4 = *(_QWORD *)(a1 + 14864);
    if ( v4 )
    {
      if ( *(_DWORD *)(v4 + 728) )
        LODWORD(v1) = v1 + 1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14888) | 2) == 3 )
  {
    v5 = *(_QWORD *)(a1 + 14880);
    if ( v5 )
    {
      if ( *(_DWORD *)(v5 + 728) )
        LODWORD(v1) = v1 + 1;
    }
  }
  if ( (*(_DWORD *)(a1 + 14904) | 2) == 3 )
  {
    v6 = *(_QWORD *)(a1 + 14896);
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 728) )
        LODWORD(v1) = v1 + 1;
    }
  }
  return (unsigned int)v1;
}
