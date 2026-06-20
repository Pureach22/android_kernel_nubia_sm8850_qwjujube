__int64 __fastcall dot11f_unpack_ie_descriptor_element(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4, char a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 v13; // x7
  __int64 v14; // [xsp+8h] [xbp-38h]

  if ( *a4 )
    return 32;
  v14 = v6;
  *a4 = 1;
  if ( a3 && (a4[1] = *a2, a3 > 2u) && (qdf_mem_copy(a4 + 2, a2 + 1, 2u), (unsigned __int8)(a3 - 3) > 3u) )
  {
    qdf_mem_copy(a4 + 4, a2 + 3, 4u);
    return unpack_core(
             a1,
             a2 + 7,
             (unsigned __int8)(a3 - 7),
             &FFS_descriptor_element,
             &IES_descriptor_element,
             a4,
             a5 & 1,
             v13,
             v5,
             v14);
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
