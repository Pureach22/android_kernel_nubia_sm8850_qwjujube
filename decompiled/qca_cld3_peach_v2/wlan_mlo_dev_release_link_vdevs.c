__int64 __usercall wlan_mlo_dev_release_link_vdevs@<X0>(
        __int64 *a1@<X0>,
        unsigned int *a2@<X8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  __int64 v11; // x0
  __int64 result; // x0

  v11 = *a1;
  if ( v11 )
    wlan_objmgr_vdev_release_ref(v11, 0x5Au, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  result = a1[1];
  if ( result )
    return wlan_objmgr_vdev_release_ref(result, 0x5Au, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  return result;
}
