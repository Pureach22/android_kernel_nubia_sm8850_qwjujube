__int64 __usercall sub_77458@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 _X8@<X8>)
{
  __asm { LDLARB          W15, [X8] }
  return ieee80211_request_sched_scan_start(a1, a2);
}
