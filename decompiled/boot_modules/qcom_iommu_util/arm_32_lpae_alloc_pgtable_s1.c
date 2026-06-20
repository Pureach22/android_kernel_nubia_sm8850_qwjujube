_DWORD *__fastcall arm_32_lpae_alloc_pgtable_s1(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a1 + 24) > 0x20u )
    return nullptr;
  if ( *(_DWORD *)(a1 + 28) > 0x28u )
    return nullptr;
  *(_QWORD *)(a1 + 16) &= 0x40201000uLL;
  return arm_64_lpae_alloc_pgtable_s1(a1, a2);
}
