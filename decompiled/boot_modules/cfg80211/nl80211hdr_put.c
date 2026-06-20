__int64 __fastcall nl80211hdr_put(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  return genlmsg_put(a1, a2, a3, &nl80211_fam, a4, a5);
}
