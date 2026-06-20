__int64 __fastcall arm_smmu_tlb_add_page_s2(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x0
  int v5; // w8
  int v6; // w9
  __int64 v7; // x3
  int v8; // w1
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v12; // x8

  v4 = *a4;
  v5 = *((unsigned __int8 *)a4 + 48);
  if ( (*(_BYTE *)(*a4 + 32) & 1) != 0 )
    __dsb(0xEu);
  v6 = *((_DWORD *)a4 + 16);
  v7 = a2 >> 12;
  v8 = *(_DWORD *)(v4 + 24) + v5;
  if ( v6 == 1 )
  {
    v9 = *(_QWORD *)(v4 + 48);
    if ( !v9 )
      return writeq_relaxed(v7, (_QWORD *)(*(_QWORD *)(v4 + 8) + (v8 << *(_DWORD *)(v4 + 28)) + 1592LL));
    v10 = *(__int64 (**)(void))(v9 + 24);
    if ( !v10 )
      return writeq_relaxed(v7, (_QWORD *)(*(_QWORD *)(v4 + 8) + (v8 << *(_DWORD *)(v4 + 28)) + 1592LL));
    if ( *((_DWORD *)v10 - 1) != 1922493645 )
      __break(0x8228u);
  }
  else
  {
    v12 = *(_QWORD *)(v4 + 48);
    if ( !v12 )
      return writel_relaxed_0(v7, (unsigned int *)(*(_QWORD *)(v4 + 8) + (v8 << *(_DWORD *)(v4 + 28)) + 1592LL));
    v10 = *(__int64 (**)(void))(v12 + 8);
    if ( !v10 )
      return writel_relaxed_0(v7, (unsigned int *)(*(_QWORD *)(v4 + 8) + (v8 << *(_DWORD *)(v4 + 28)) + 1592LL));
    if ( *((_DWORD *)v10 - 1) != -1008624849 )
      __break(0x8228u);
  }
  return v10();
}
