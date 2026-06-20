__int64 __fastcall dot11f_unpack_ie_ric_data_desc(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
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
  return unpack_core(a1, a2, a3, &FFS_RICDataDesc, &IES_RICDataDesc, a4, a5 & 1, a8, v8, v9);
}
