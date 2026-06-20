__int64 __usercall sub_7706C@<X0>(__int64 _X8@<X8>)
{
  __asm { LDLARB          W15, [X8] }
  return _ieee80211_request_sched_scan_start();
}
