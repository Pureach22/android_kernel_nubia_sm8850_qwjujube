__int64 __fastcall dot11f_unpack_ie_fils_kde(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 <= 7u )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 1, (const void *)a2, 8u);
    a4[9] = a3 - 8;
    qdf_mem_copy(a4 + 10, (const void *)(a2 + 8), (unsigned __int8)(a3 - 8));
    return 0;
  }
}
