__int64 __fastcall dot11f_unpack_ie_tsf_info(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 <= 1u )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 2, (const void *)a2, 2u);
    if ( (a3 & 0xFE) == 2 )
    {
      *a4 = 0;
      return 4;
    }
    else
    {
      qdf_mem_copy(a4 + 4, (const void *)(a2 + 2), 2u);
      return 0;
    }
  }
}
