__int64 __fastcall dot11f_unpack_ie_link_identifier(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  int v5; // w21

  if ( *a4 )
    return 32;
  v5 = a3;
  *a4 = 1;
  if ( a3 <= 5u
    || (qdf_mem_copy(a4 + 1, (const void *)a2, 6u), (unsigned int)(v5 - 6) <= 5)
    || (qdf_mem_copy(a4 + 7, (const void *)(a2 + 6), 6u), (unsigned int)(v5 - 12) <= 5) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 13, (const void *)(a2 + 12), 6u);
    return 0;
  }
}
