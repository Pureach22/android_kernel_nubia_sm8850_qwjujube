__int64 __fastcall sub_46758(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 *v3; // x19
  unsigned __int64 v4; // x3

  v4 = atomic_load(v3);
  return nl80211hdr_put(a1, a2, a3, v4);
}
