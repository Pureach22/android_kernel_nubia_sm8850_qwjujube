__int64 __fastcall sub_8CC00(__int64 a1, __int64 _X1, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __asm { STGP            X22, X15, [X1,#0xFC] }
  return _traceiter_cfg80211_report_obss_beacon(a1, _X1, a3, a4, a5, a6);
}
