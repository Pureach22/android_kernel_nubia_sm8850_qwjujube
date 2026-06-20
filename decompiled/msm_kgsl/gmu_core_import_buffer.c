__int64 __fastcall gmu_core_import_buffer(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w9
  unsigned int v4; // w4
  unsigned int v5; // w3

  v2 = *(_DWORD *)(a2 + 8);
  if ( (v2 & 0x10) != 0 )
    v3 = 33;
  else
    v3 = 1;
  v4 = v3 | (v2 >> 4) & 2;
  if ( *(_DWORD *)(a2 + 12) == 23 && (*(_QWORD *)(a1 + 104) & 8) != 0 )
  {
    v4 |= 4u;
    *(_QWORD *)(*(_QWORD *)(a2 + 40) + 72LL) |= 0x80000000uLL;
  }
  if ( (v2 & 0x80) != 0 )
    v5 = 1;
  else
    v5 = 4;
  return gmu_core_map_gmu(a1, *(_QWORD *)(a2 + 40), 0, v5, v4, *(_DWORD *)(a2 + 32));
}
