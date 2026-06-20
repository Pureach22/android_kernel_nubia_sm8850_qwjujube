__int64 __fastcall sub_AB6CC(__int64 a1, __int64 a2)
{
  __asm { LDTRSB          W2, [X11,#0x11] }
  return _bpf_trace_cfg80211_ready_on_channel(a1, a2, _X2);
}
