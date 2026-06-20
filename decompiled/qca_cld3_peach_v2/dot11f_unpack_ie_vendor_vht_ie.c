__int64 __fastcall dot11f_unpack_ie_vendor_vht_ie(
        __int64 a1,
        _BYTE *a2,
        char a3,
        _BYTE *a4,
        char a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x29
  __int64 v9; // x30

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    a4[1] = *a2;
    return unpack_core(
             a1,
             a2 + 1,
             (unsigned __int8)(a3 - 1),
             &FFS_vendor_vht_ie,
             &IES_vendor_vht_ie,
             a4,
             a5 & 1,
             a8,
             v8,
             v9);
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
