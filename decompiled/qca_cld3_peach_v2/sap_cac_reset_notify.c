__int64 __fastcall sap_cac_reset_notify(__int64 result)
{
  __int64 v1; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8

  v1 = *(_QWORD *)(result + 14888);
  if ( (*(_DWORD *)(result + 14896) | 2) == 3 && v1 != 0 )
    *(_WORD *)(v1 + 1561) = 0;
  if ( (*(_DWORD *)(result + 14912) | 2) == 3 )
  {
    v3 = *(_QWORD *)(result + 14904);
    if ( v3 )
      *(_WORD *)(v3 + 1561) = 0;
  }
  if ( (*(_DWORD *)(result + 14928) | 2) == 3 )
  {
    v4 = *(_QWORD *)(result + 14920);
    if ( v4 )
      *(_WORD *)(v4 + 1561) = 0;
  }
  if ( (*(_DWORD *)(result + 14944) | 2) == 3 )
  {
    v5 = *(_QWORD *)(result + 14936);
    if ( v5 )
      *(_WORD *)(v5 + 1561) = 0;
  }
  if ( (*(_DWORD *)(result + 14960) | 2) == 3 )
  {
    v6 = *(_QWORD *)(result + 14952);
    if ( v6 )
      *(_WORD *)(v6 + 1561) = 0;
  }
  if ( (*(_DWORD *)(result + 14976) | 2) == 3 )
  {
    v7 = *(_QWORD *)(result + 14968);
    if ( v7 )
      *(_WORD *)(v7 + 1561) = 0;
  }
  return result;
}
