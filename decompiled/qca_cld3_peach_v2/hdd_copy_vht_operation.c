void *__fastcall hdd_copy_vht_operation(__int64 a1, __int64 a2)
{
  void *result; // x0

  result = qdf_mem_set((void *)(a1 + 718), 5u, 0);
  *(_BYTE *)(a1 + 718) = *(_BYTE *)(a2 + 1);
  *(_BYTE *)(a1 + 719) = *(_BYTE *)(a2 + 2);
  *(_BYTE *)(a1 + 720) = *(_BYTE *)(a2 + 3);
  *(_WORD *)(a1 + 721) = *(_WORD *)(a2 + 4);
  return result;
}
