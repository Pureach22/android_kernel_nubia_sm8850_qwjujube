// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_39F664@<X0>(
        unsigned int a1@<W0>,
        char a2@<W8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  __int64 v10; // x24
  unsigned int v11; // w19
  unsigned int v12; // w19

  if ( (a2 & 1) == 0 )
  {
    v11 = a1;
    wlan_hdd_qmi_put_suspend(a3, a4, a5, a6, a7, a8, a9, a10);
    a1 = v11;
  }
  *(_BYTE *)(v10 + 3424) = 0;
  v12 = a1;
  ((void (__fastcall *)(const char *))_osif_vdev_sync_op_stop)("wlan_hdd_cfg80211_get_station");
  _ReadStatusReg(SP_EL0);
  return v12;
}
