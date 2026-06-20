__int64 __usercall wlansap_release_vdev_ref@<X0>(
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
  {
    sap_release_vdev_ref(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_release_vdev_ref");
    return 16;
  }
}
