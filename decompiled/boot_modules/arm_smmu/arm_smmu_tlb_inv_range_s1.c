__int64 __fastcall arm_smmu_tlb_inv_range_s1(
        unsigned __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 v5; // x21
  int v6; // w24
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 v12; // x22
  __int64 v13; // x8
  __int64 v14; // x1
  _DWORD *v15; // x8
  __int64 result; // x0
  __int64 v17; // x22
  int v18; // w25

  v5 = *(_QWORD *)a4;
  v6 = *(unsigned __int8 *)(a4 + 48);
  if ( (*(_BYTE *)(*(_QWORD *)a4 + 32LL) & 1) != 0 )
    __dsb(0xEu);
  v10 = *(unsigned __int16 *)(a4 + 50);
  if ( *(_DWORD *)(a4 + 64) == 1 )
  {
    v11 = -a2;
    v12 = (v10 << 48) | (a1 >> 12);
    do
    {
      v13 = *(_QWORD *)(v5 + 48);
      v14 = (unsigned int)(*(_DWORD *)(v5 + 24) + v6);
      if ( v13 && (v15 = *(_DWORD **)(v13 + 24)) != nullptr )
      {
        if ( *(v15 - 1) != 1922493645 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v15)(v5, v14, a5, v12);
      }
      else
      {
        result = writeq_relaxed(v12, (_QWORD *)(*(_QWORD *)(v5 + 8) + (int)((_DWORD)v14 << *(_DWORD *)(v5 + 28)) + a5));
      }
      v11 += a3;
      v12 += a3 >> 12;
    }
    while ( v11 );
  }
  else
  {
    v17 = 0;
    v18 = a1 & 0xFFFFF000 | v10;
    do
    {
      result = arm_smmu_writel(v5, *(_DWORD *)(v5 + 24) + v6, a5, v18 + (int)v17);
      v17 += a3;
    }
    while ( a2 != v17 );
  }
  return result;
}
