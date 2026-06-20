__int64 __fastcall wlan_cfg80211_nla_parse_nested(__int64 a1, __int64 a2, _WORD *a3, __int64 a4)
{
  if ( (__int16)a3[1] < 0 )
    return _nla_parse(a1, a2, a3 + 2, (unsigned __int16)(*a3 - 4), a4, 31, 0);
  do_trace_netlink_extack("NLA_F_NESTED is missing");
  return 4294967274LL;
}
