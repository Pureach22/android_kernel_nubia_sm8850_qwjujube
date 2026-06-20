__int64 __usercall ml_activate_pend_disconn_req_flush_cb@<X0>(
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
  __int64 v10; // x0

  v10 = *(_QWORD *)(a1 + 8);
  if ( v10 )
  {
    wlan_objmgr_vdev_release_ref(v10, 0x5Au, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Null input vdev",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ml_activate_pend_disconn_req_flush_cb");
    return 4;
  }
}
