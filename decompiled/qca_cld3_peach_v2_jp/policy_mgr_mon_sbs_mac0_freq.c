__int64 __fastcall policy_mgr_mon_sbs_mac0_freq(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x22
  bool can_2ghz_share_low_high_5ghz_sbs; // w0
  __int64 v9; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v5 = context;
    v6 = policy_mgr_get_context(a1);
    if ( v6 && (v7 = v6, (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0) )
    {
      can_2ghz_share_low_high_5ghz_sbs = policy_mgr_can_2ghz_share_low_high_5ghz_sbs(v7);
      v9 = 1268;
      if ( can_2ghz_share_low_high_5ghz_sbs )
        v9 = 1332;
    }
    else
    {
      v9 = 1268;
    }
    LOBYTE(context) = policy_mgr_is_freq_on_mac_id(v5 + v9, a2, 0);
  }
  return context & 1;
}
