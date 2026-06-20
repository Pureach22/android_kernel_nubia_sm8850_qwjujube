__int64 __fastcall dot11f_unpack_ie_vendor1_ie(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  return 0;
}
