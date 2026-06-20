__int64 __fastcall dot11f_unpack_ie_dh_parameter_element(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
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
    qdf_mem_copy(a4 + 1, (const void *)a2, 2u);
    a4[3] = a3 - 2;
    qdf_mem_copy(a4 + 4, (const void *)(a2 + 2), (unsigned __int8)(a3 - 2));
    return 0;
  }
}
