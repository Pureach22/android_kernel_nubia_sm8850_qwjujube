void *__fastcall lim_add_bss_he_cap(_BYTE *a1, __int64 a2)
{
  a1[857] = *(_BYTE *)(a2 + 2508) != 0;
  qdf_mem_copy(a1 + 192, (const void *)(a2 + 2508), 0x3Cu);
  return qdf_mem_copy(a1 + 252, (const void *)(a2 + 2568), 0x12u);
}
