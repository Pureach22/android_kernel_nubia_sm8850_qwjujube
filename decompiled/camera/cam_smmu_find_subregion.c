_DWORD *__fastcall cam_smmu_find_subregion(int a1, _DWORD *a2)
{
  if ( *a2 == a1 )
    return a2;
  if ( a2[24] == a1 )
    return a2 + 24;
  if ( a2[48] == a1 )
    return a2 + 48;
  if ( a2[72] == a1 )
    return a2 + 72;
  if ( a2[96] == a1 )
    return a2 + 96;
  if ( a2[120] == a1 )
    return a2 + 120;
  else
    return nullptr;
}
