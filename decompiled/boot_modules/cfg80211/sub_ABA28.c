__int64 sub_ABA28()
{
  int v0; // w18

  if ( (v0 & 0x4000000) == 0 )
    JUMPOUT(0xACFFC);
  return _bpf_trace_cfg80211_get_bss();
}
