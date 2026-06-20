_QWORD *__fastcall adreno_alloc_dcvs_profile_memory(_QWORD *result, __int64 a2)
{
  size_t v3; // x20

  if ( (*(_BYTE *)(result[1783] + 35LL) & 4) != 0 )
  {
    result = (_QWORD *)gmu_core_alloc_kernel_block();
    if ( !(_DWORD)result )
    {
      v3 = (unsigned int)(*(_QWORD *)(a2 + 736) >> 1);
      memset(*(void **)(a2 + 704), 255, v3);
      return memset((void *)(*(_QWORD *)(a2 + 704) + v3), 0, v3);
    }
  }
  return result;
}
