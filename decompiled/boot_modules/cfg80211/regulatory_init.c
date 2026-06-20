unsigned __int64 regulatory_init()
{
  unsigned __int64 result; // x0
  _QWORD v1[13]; // [xsp+8h] [xbp-68h] BYREF

  v1[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v1, 0, 24);
  v1[3] = "regulatory";
  memset(&v1[4], 0, 64);
  result = platform_device_register_full(v1);
  reg_pdev = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    atomic_store((unsigned __int64)cfg80211_world_regdom, (unsigned __int64 *)&cfg80211_regdomain);
    user_alpha2 = 14137;
    result = regulatory_init_db();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
