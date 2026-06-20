void *__fastcall convert_ext_supp_rates(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  unsigned __int8 v3; // w8

  v3 = *(_BYTE *)(a3 + 1);
  *a2 = v3;
  return qdf_mem_copy(a2 + 1, (const void *)(a3 + 2), v3);
}
