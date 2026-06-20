__int64 __fastcall sub_3E9520(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 *v3; // x30

  atomic_store(a1, v3);
  return dot11f_get_packed_ie_country(a1, a2, a3);
}
