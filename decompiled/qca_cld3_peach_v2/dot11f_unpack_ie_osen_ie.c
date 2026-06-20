__int64 __fastcall dot11f_unpack_ie_osen_ie(__int64 a1, const void *a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  a4[1] = a3;
  *a4 = 1;
  qdf_mem_copy(a4 + 2, a2, a3);
  return 0;
}
