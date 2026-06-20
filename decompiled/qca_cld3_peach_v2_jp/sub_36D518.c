__int64 __usercall sub_36D518@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x11
  _QWORD *v3; // x29

  *v3 = a2;
  v3[1] = v2;
  return hdd_set_mon_rx_cb(a1);
}
