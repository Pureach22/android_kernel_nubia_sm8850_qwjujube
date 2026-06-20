// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_2B3FBC@<X0>(
        __int64 a1@<X8>,
        double a2@<D0>,
        double a3@<D1>,
        double a4@<D2>,
        double a5@<D3>,
        double a6@<D4>,
        double a7@<D5>,
        double a8@<D6>,
        double a9@<D7>)
{
  __int64 v9; // x23
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 v12; // x24
  __int64 v13; // x25
  __int64 v14; // x29

  if ( (a1 & 0x100) == 0 )
    return wlan_dp_get_tsf_time();
  v9 = *(_QWORD *)(a1 + 2304);
  if ( dp_start_xmit___last_ticks_13 - v9 + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Device is system suspended, drop pkt",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_start_xmit");
    *(_QWORD *)(v14 - 76) = 0;
    dp_start_xmit___last_ticks_13 = v9;
  }
  else
  {
    *(_QWORD *)(v14 - 76) = 0;
  }
  if ( *(_DWORD *)(v12 + 3076) )
    dp_tx_rx_collect_connectivity_stats_info(v10, v11, 2, (_BYTE *)(v14 - 52), a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_dp_trace_data_pkt(v10, 0xFFu, 1u, 0, 0);
  sk_skb_reason_drop(0, v10, 2);
  ++*(_QWORD *)(v12 + 2944);
  ++*(_DWORD *)(v13 + 4);
  if ( *(_DWORD *)(v14 - 72) || *(_DWORD *)(v14 - 76) )
    __break(0x5512u);
  _ReadStatusReg(SP_EL0);
  return 16;
}
