__int64 __fastcall wlan_cfg80211_nla_parse_nested_0(__int64 a1, _WORD *a2)
{
  if ( (__int16)a2[1] < 0 )
    return _nla_parse(a1, 2, a2 + 2, (unsigned __int16)(*a2 - 4), &p2p_usd_chan_config_policy, 31, 0);
  do_trace_netlink_extack("NLA_F_NESTED is missing");
  return 4294967274LL;
}
