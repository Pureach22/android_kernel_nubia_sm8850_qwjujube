__int64 __fastcall dot11f_unpack_ie_fils_hlp_container(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 <= 5u || (qdf_mem_copy(a4 + 1, (const void *)a2, 6u), (unsigned __int8)(a3 - 6) <= 5u) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 7, (const void *)(a2 + 6), 6u);
    a4[13] = a3 - 12;
    qdf_mem_copy(a4 + 14, (const void *)(a2 + 12), (unsigned __int8)(a3 - 12));
    return 0;
  }
}
