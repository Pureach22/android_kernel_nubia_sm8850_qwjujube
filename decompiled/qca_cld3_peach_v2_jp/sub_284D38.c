// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_284D38@<X0>(
        const char *a1@<X2>,
        __int16 a2@<W8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x19
  __int64 v29; // x20
  int v30; // w21
  __int64 v31; // x22
  __int64 v32; // x23
  __int64 v33; // x24
  __int64 v34; // x25
  __int64 v35; // x29

  if ( (a2 & 0x100) == 0 )
    return wlan_dp_get_tsf_time();
  qdf_trace_msg(0x45u, 2u, a1, a3, a4, a5, a6, a7, a8, a9, a10);
  *(_QWORD *)(v31 + 1792) = v32;
  v18 = *(_DWORD *)(v35 - 68);
  if ( *(_DWORD *)(v33 + 3076) )
    dp_tx_rx_collect_connectivity_stats_info(v28, v29, 2, (_BYTE *)(v35 - 52), v10, v11, v12, v13, v14, v15, v16, v17);
  qdf_dp_trace_data_pkt(v28, 0xFFu, 1u, 0, 0);
  sk_skb_reason_drop(0, v28, 2);
  ++*(_QWORD *)(v33 + 2944);
  ++*(_DWORD *)(v34 + 4);
  if ( (v18 & 1) != 0 )
  {
    ++*(_WORD *)(v33 + 2724);
    v27 = jiffies;
    if ( dp_start_xmit___last_ticks_26 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x45u, 5u, "%s: ARP packet dropped", v19, v20, v21, v22, v23, v24, v25, v26, "dp_start_xmit");
      dp_start_xmit___last_ticks_26 = v27;
    }
    goto LABEL_14;
  }
  if ( !*(_DWORD *)(v35 - 72) )
  {
    if ( !*(_DWORD *)(v35 - 76) )
      goto LABEL_14;
    if ( (unsigned int)(v30 - 5) <= 4 )
    {
      ++*(_WORD *)(v33 + 2LL * (unsigned int)(v30 - 5) + 2810);
      goto LABEL_14;
    }
LABEL_15:
    __break(0x5512u);
  }
  if ( (unsigned int)(v30 - 1) > 4 )
    goto LABEL_15;
  ++*(_WORD *)(v33 + 2LL * (unsigned int)(v30 - 1) + 2850);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return 16;
}
