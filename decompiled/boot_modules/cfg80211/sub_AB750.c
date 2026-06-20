__int64 sub_AB750()
{
  __int64 v0; // x10

  if ( !v0 )
    JUMPOUT(0x490DC);
  return _bpf_trace_cfg80211_rx_mgmt();
}
