__int64 __fastcall sub_8BE80(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int _W5)
{
  __asm { STLLR           W5, [X3] }
  return _traceiter_cfg80211_send_assoc_failure(a1, a2, a3);
}
