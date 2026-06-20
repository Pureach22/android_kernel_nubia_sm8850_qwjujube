__int64 __fastcall dot11f_unpack_ie_P2P2IEOpaque(__int64 a1, const void *a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  a4[1] = a3;
  *a4 = 1;
  if ( a3 < 0xFAu )
  {
    qdf_mem_copy(a4 + 2, a2, a3);
    return 0;
  }
  else
  {
    *a4 = 0;
    return 8;
  }
}
