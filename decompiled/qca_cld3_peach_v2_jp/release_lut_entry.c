void *__fastcall release_lut_entry(__int64 a1, __int64 a2)
{
  *(_WORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 208) = 0;
  *(_QWORD *)(a2 + 216) = 0;
  return qdf_mem_set((void *)(a2 + 40), 0xA0u, 0);
}
