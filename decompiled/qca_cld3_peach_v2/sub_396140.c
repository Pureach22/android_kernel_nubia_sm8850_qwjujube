__int64 __usercall sub_396140@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x11
  _QWORD *v3; // x29

  *v3 = a2;
  v3[1] = v2;
  return wlan_hdd_sched_scan_stop(a1);
}
