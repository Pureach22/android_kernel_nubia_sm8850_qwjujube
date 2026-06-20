unsigned __int64 __fastcall gmu_core_hwsched_memory_init(__int64 a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v3; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x8

  v1 = *(_QWORD *)(a1 + 8664);
  if ( v1 && v1 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = *(_QWORD *)(a1 + 8672);
    if ( !v3 )
      goto LABEL_11;
    goto LABEL_9;
  }
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
             a1,
             0,
             4096,
             4,
             0);
  *(_QWORD *)(a1 + 8664) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  if ( !result )
  {
LABEL_18:
    __break(0x800u);
    return 4294967277LL;
  }
  v5 = *(_QWORD *)(result + 40);
  if ( v5 <= 3 )
    goto LABEL_21;
  **(_DWORD **)(result + 8) = v5 >> 2;
  __dsb(0xEu);
  v3 = *(_QWORD *)(a1 + 8672);
  if ( v3 )
  {
LABEL_9:
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
      return 0;
  }
LABEL_11:
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
             a1,
             0,
             0x4000,
             4,
             0);
  v6 = result;
  *(_QWORD *)(a1 + 8672) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  v7 = *(_QWORD *)(a1 + 8664);
  if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_18;
  if ( *(_QWORD *)(v7 + 40) <= 0xBu )
  {
LABEL_21:
    __break(0x800u);
    printk(&unk_13DA5C);
    return 4294967274LL;
  }
  result = 0;
  *(_DWORD *)(*(_QWORD *)(v7 + 8) + 8LL) = *(_DWORD *)(v6 + 184);
  __dsb(0xEu);
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 8672) + 8LL);
  *(_DWORD *)(v8 + 40) = 5;
  *(_QWORD *)(v8 + 4) = 0x5040000001LL;
  *(_QWORD *)(v8 + 32) = *(unsigned int *)(*(_QWORD *)(a1 + 8672) + 184LL);
  *(_DWORD *)(v8 + 12) = *(_QWORD *)(*(_QWORD *)(a1 + 8672) + 40LL);
  *(_DWORD *)(v8 + 44) = 1;
  return result;
}
