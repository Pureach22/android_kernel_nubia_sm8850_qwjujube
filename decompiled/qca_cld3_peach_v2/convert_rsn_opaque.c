__int64 __fastcall convert_rsn_opaque(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  unsigned __int8 v3; // w8

  v3 = *(_BYTE *)(a3 + 1);
  *a2 = v3;
  qdf_mem_copy(a2 + 1, (const void *)(a3 + 2), v3);
  return 0;
}
