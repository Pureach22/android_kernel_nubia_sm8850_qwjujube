__int64 __fastcall sme_get_hs20vendor_ie(__int64 a1, unsigned __int8 *a2, unsigned int a3, void *a4)
{
  __int64 result; // x0
  __int64 v9; // x21

  result = _qdf_mem_malloc(0x1A08u, "sme_get_hs20vendor_ie", 15017);
  if ( result )
  {
    v9 = result;
    sir_parse_beacon_ie(a1, result, a2, a3);
    qdf_mem_copy(a4, (const void *)(v9 + 2570), 4u);
    return _qdf_mem_free(v9);
  }
  return result;
}
