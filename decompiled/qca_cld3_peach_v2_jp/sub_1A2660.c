__int64 __fastcall sub_1A2660(int a1, int a2, int a3)
{
  unsigned __int64 *v3; // x19

  __ldxr(v3);
  return crypto_hash_find_by_linkid_and_macaddr(a1, a2, a3);
}
