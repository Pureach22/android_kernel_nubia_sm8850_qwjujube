__int64 __fastcall _bpf_trace_cfg80211_return_bool(__int64 a1, char a2)
{
  return bpf_trace_run1(a1, a2 & 1);
}
