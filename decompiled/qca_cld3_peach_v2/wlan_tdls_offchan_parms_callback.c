__int64 __usercall wlan_tdls_offchan_parms_callback@<X0>(
        __int64 a1@<X0>,
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
  if ( a1 )
    return wlan_objmgr_vdev_release_ref(a1, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  else
    return qdf_trace_msg(0, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_tdls_offchan_parms_callback");
}
