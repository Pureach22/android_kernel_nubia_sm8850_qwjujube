__int64 __fastcall sap_cac_reset_notify(__int64 result)
{
  __int64 v1; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8

  v1 = *(_QWORD *)(result + 14816);
  if ( (*(_DWORD *)(result + 14824) | 2) == 3 && v1 != 0 )
    *(_WORD *)(v1 + 1553) = 0;
  if ( (*(_DWORD *)(result + 14840) | 2) == 3 )
  {
    v3 = *(_QWORD *)(result + 14832);
    if ( v3 )
      *(_WORD *)(v3 + 1553) = 0;
  }
  if ( (*(_DWORD *)(result + 14856) | 2) == 3 )
  {
    v4 = *(_QWORD *)(result + 14848);
    if ( v4 )
      *(_WORD *)(v4 + 1553) = 0;
  }
  if ( (*(_DWORD *)(result + 14872) | 2) == 3 )
  {
    v5 = *(_QWORD *)(result + 14864);
    if ( v5 )
      *(_WORD *)(v5 + 1553) = 0;
  }
  if ( (*(_DWORD *)(result + 14888) | 2) == 3 )
  {
    v6 = *(_QWORD *)(result + 14880);
    if ( v6 )
      *(_WORD *)(v6 + 1553) = 0;
  }
  if ( (*(_DWORD *)(result + 14904) | 2) == 3 )
  {
    v7 = *(_QWORD *)(result + 14896);
    if ( v7 )
      *(_WORD *)(v7 + 1553) = 0;
  }
  return result;
}
