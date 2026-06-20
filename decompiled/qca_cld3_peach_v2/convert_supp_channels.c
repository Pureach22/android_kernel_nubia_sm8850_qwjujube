void *__fastcall convert_supp_channels(__int64 a1, _BYTE *a2, __int64 a3)
{
  unsigned __int8 v3; // w8

  *a2 = 36;
  v3 = 2 * *(_BYTE *)(a3 + 1);
  a2[1] = v3;
  return qdf_mem_copy(a2 + 2, (const void *)(a3 + 2), v3 & 0xFE);
}
