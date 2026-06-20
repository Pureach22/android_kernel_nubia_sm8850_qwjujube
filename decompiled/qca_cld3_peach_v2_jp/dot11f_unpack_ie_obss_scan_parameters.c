__int64 __fastcall dot11f_unpack_ie_obss_scan_parameters(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  int v8; // w21

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 <= 1u
    || (qdf_mem_copy(a4 + 2, (const void *)a2, 2u), v8 = a3 & 0xFE, v8 == 2)
    || (qdf_mem_copy(a4 + 4, (const void *)(a2 + 2), 2u), v8 == 4)
    || (qdf_mem_copy(a4 + 6, (const void *)(a2 + 4), 2u), v8 == 6)
    || (qdf_mem_copy(a4 + 8, (const void *)(a2 + 6), 2u), v8 == 8)
    || (qdf_mem_copy(a4 + 10, (const void *)(a2 + 8), 2u), v8 == 10)
    || (qdf_mem_copy(a4 + 12, (const void *)(a2 + 10), 2u), v8 == 12) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 14, (const void *)(a2 + 12), 2u);
    return 0;
  }
}
