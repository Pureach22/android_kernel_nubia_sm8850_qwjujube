__int64 __fastcall gen8_bcl_sid_set(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v4; // w8
  int v5; // w10
  unsigned int v6; // w12
  int v7; // w10

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) == 0 )
    return 4294967274LL;
  v4 = -22;
  v5 = *(_DWORD *)(a1 + 23992);
  if ( (v5 & 1) != 0 && a2 <= 2 )
  {
    v6 = dword_166A4C[a2];
    v7 = v5 & dword_166A40[a2];
    *(_DWORD *)(a1 + 23992) = v7;
    return (unsigned int)adreno_power_cycle_u32(a1, (_DWORD *)(a1 + 23992), v7 | (a3 << (7 * a2 + 1)) & v6);
  }
  return v4;
}
