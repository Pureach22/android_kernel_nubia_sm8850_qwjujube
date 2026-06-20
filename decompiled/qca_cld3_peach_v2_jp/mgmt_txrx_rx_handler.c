__int64 __fastcall mgmt_txrx_rx_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  __int64 v13; // x19

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 2136);
    if ( v10 )
    {
      v11 = *(__int64 (**)(void))(v10 + 8);
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != 905390846 )
          __break(0x8228u);
        return v11();
      }
    }
    else
    {
      v13 = a2;
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: rx_ops is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_lmac_if_get_mgmt_txrx_rx_ops");
      a2 = v13;
    }
  }
  if ( a2 )
    _qdf_nbuf_free(a2);
  return 29;
}
