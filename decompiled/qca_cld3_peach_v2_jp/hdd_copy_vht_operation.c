void *__fastcall hdd_copy_vht_operation(__int64 a1, __int64 a2)
{
  void *result; // x0

  result = qdf_mem_set((void *)(a1 + 710), 5u, 0);
  *(_BYTE *)(a1 + 710) = *(_BYTE *)(a2 + 1);
  *(_BYTE *)(a1 + 711) = *(_BYTE *)(a2 + 2);
  *(_BYTE *)(a1 + 712) = *(_BYTE *)(a2 + 3);
  *(_WORD *)(a1 + 713) = *(_WORD *)(a2 + 4);
  return result;
}
