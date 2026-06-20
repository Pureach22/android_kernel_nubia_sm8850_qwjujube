__int64 __usercall _dp_objmgr_put_vdev_by_user@<X0>(
        __int64 a1@<X0>,
        unsigned int a2@<W1>,
        __int64 a3@<X2>,
        unsigned int *a4@<X8>,
        double a5@<D0>,
        double a6@<D1>,
        double a7@<D2>,
        double a8@<D3>,
        double a9@<D4>,
        double a10@<D5>,
        double a11@<D6>,
        double a12@<D7>)
{
  if ( a1 )
    return wlan_objmgr_vdev_release_ref(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11, a12);
  else
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: VDEV is NULL (via %s, id %d)",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "__dp_objmgr_put_vdev_by_user",
             a3,
             a2);
}
