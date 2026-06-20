__int64 __fastcall arm_smmu_tlb_inv_walk_s2(unsigned __int64 a1, __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x21
  int v5; // w23
  __int64 v8; // x22
  __int64 v9; // x25
  __int64 v10; // x1
  __int64 v11; // x8
  void (__fastcall *v12)(__int64, __int64, __int64, __int64); // x8
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x3

  v4 = *a4;
  v5 = *((unsigned __int8 *)a4 + 48);
  if ( (*(_BYTE *)(*a4 + 32) & 1) != 0 )
    __dsb(0xEu);
  v8 = a1 >> 12;
  v9 = -a2;
  do
  {
    v10 = (unsigned int)(*(_DWORD *)(v4 + 24) + v5);
    if ( *((_DWORD *)a4 + 16) == 1 )
    {
      v11 = *(_QWORD *)(v4 + 48);
      if ( !v11 || (v12 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + 24)) == nullptr )
      {
        writeq_relaxed(v8, (_QWORD *)(*(_QWORD *)(v4 + 8) + (int)((_DWORD)v10 << *(_DWORD *)(v4 + 28)) + 1584LL));
        goto LABEL_5;
      }
      v14 = v4;
      v15 = v8;
      if ( *((_DWORD *)v12 - 1) != 1922493645 )
        __break(0x8228u);
    }
    else
    {
      v13 = *(_QWORD *)(v4 + 48);
      if ( !v13 || (v12 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v13 + 8)) == nullptr )
      {
        writel_relaxed_0(
          v8,
          (unsigned int *)(*(_QWORD *)(v4 + 8) + (int)((_DWORD)v10 << *(_DWORD *)(v4 + 28)) + 1584LL));
        goto LABEL_5;
      }
      v14 = v4;
      v15 = (unsigned int)v8;
      if ( *((_DWORD *)v12 - 1) != -1008624849 )
        __break(0x8228u);
    }
    v12(v14, v10, 1584, v15);
LABEL_5:
    v9 += a3;
    v8 += a3 >> 12;
  }
  while ( v9 );
  return arm_smmu_tlb_sync_context(a4);
}
