__int64 __usercall ucfg_tdls_release_mlo_vdev@<X0>(
        __int64 a1@<X0>,
        unsigned int a2@<W1>,
        unsigned int *a3@<X8>,
        double a4@<D0>,
        double a5@<D1>,
        double a6@<D2>,
        double a7@<D3>,
        double a8@<D4>,
        double a9@<D5>,
        double a10@<D6>,
        double a11@<D7>)
{
  return wlan_tdls_release_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
