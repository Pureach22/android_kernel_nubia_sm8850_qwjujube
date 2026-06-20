void *__fastcall lim_add_bss_eht_cap(_BYTE *a1, __int64 a2)
{
  a1[868] = *(_BYTE *)(a2 + 2612) != 0;
  qdf_mem_copy(a1 + 284, (const void *)(a2 + 2612), 0x5Cu);
  return qdf_mem_copy(a1 + 376, (const void *)(a2 + 2704), 0xCu);
}
