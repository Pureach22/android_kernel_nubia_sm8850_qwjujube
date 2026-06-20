__int64 __fastcall gsi_find_idx_from_addr(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 16);
  if ( v2 > a2 || *(_QWORD *)(a1 + 64) <= a2 )
  {
    __break(0x800u);
    v2 = *(_QWORD *)(a1 + 16);
  }
  return ((int)a2 - (int)v2) / (unsigned int)*(unsigned __int8 *)(a1 + 60);
}
