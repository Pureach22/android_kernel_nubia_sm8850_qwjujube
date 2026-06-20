__int64 __fastcall hdd_lpc_disable_powersave(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 adapter; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = ucfg_dp_is_local_pkt_capture_enabled();
  if ( (result & 1) != 0 )
  {
    ucfg_fwol_set_ilp_config(*(_QWORD *)a1, *(_QWORD *)(a1 + 8), 0);
    if ( (unsigned int)wma_enable_disable_imps(*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 40LL), 0) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: IMPS feature disable failed",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "hdd_lpc_disable_powersave");
    adapter = hdd_get_adapter(a1, 0);
    if ( adapter )
    {
      result = wlan_hdd_lpc_set_bmps(adapter, 0, 0);
      *(_BYTE *)(a1 + 8312) = 1;
    }
    else
    {
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: STA adapter does not exist",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "hdd_lpc_disable_powersave");
    }
  }
  return result;
}
