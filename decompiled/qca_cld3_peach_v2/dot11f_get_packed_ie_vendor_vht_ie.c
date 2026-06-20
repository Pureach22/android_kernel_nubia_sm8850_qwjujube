__int64 __fastcall dot11f_get_packed_ie_vendor_vht_ie(__int64 a1, _BYTE *a2, int *a3)
{
  if ( !*a2 )
    return 0;
  ++*a3;
  return get_packed_size_core(a1, (__int64)a2, a3, IES_vendor_vht_ie);
}
