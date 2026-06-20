__int64 __fastcall qmp_combo_phy_xlate(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x8

  if ( !*(_DWORD *)(a2 + 8) )
    return -22;
  v2 = *(_DWORD *)(a2 + 12);
  v3 = *(_QWORD *)(a1 + 152);
  if ( v2 )
  {
    if ( v2 == 1 )
      return *(_QWORD *)(v3 + 288);
    return -22;
  }
  return *(_QWORD *)(v3 + 264);
}
