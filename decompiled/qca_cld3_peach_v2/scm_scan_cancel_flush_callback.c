__int64 __usercall scm_scan_cancel_flush_callback@<X0>(
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
  __int64 *v10; // x19

  if ( a1 && (v10 = *(__int64 **)(a1 + 8)) != nullptr )
  {
    wlan_objmgr_vdev_release_ref(*v10, 0xCu, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    _qdf_mem_free((__int64)v10);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: msg or msg->bodyptr is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "scm_scan_cancel_flush_callback");
    return 29;
  }
}
