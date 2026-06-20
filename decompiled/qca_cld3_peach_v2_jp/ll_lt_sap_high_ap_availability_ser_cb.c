__int64 __usercall ll_lt_sap_high_ap_availability_ser_cb@<X0>(
        __int64 a1@<X0>,
        int a2@<W1>,
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
  __int64 v11; // x19
  __int64 v12; // x0

  if ( a1 && (v11 = *(_QWORD *)(a1 + 40)) != 0 )
  {
    v12 = *(_QWORD *)(a1 + 32);
    if ( a2 > 1 )
    {
      if ( a2 != 2 )
      {
        if ( a2 == 3 )
          return 0;
        return 4;
      }
      wlan_objmgr_vdev_release_ref(v12, 0x69u, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      _qdf_mem_free(v11);
      return 0;
    }
    else
    {
      if ( a2 )
      {
        if ( a2 == 1 )
        {
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: ll_lt_sap ser cmd cancelled",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "ll_lt_sap_high_ap_availability_ser_cb");
          return 0;
        }
        return 4;
      }
      return ll_lt_sap_high_ap_availability_process(v12, v11);
    }
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: NULL ser cmd",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ll_lt_sap_high_ap_availability_ser_cb");
    return 29;
  }
}
