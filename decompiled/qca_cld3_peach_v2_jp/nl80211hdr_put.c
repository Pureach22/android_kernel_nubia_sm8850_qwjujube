__int64 __fastcall nl80211hdr_put(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  __int64 genl_family; // x0

  genl_family = cld80211_get_genl_family();
  return genlmsg_put(a1, a2, a3, genl_family, a4, a5);
}
