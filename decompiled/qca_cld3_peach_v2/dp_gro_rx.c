__int64 __fastcall dp_gro_rx(_BYTE *a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 context; // x0
  __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int intr_idx_from_rx_ring_id; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 dp_rx_napi; // x1
  __int64 (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x0
  const char *v29; // x2
  __int64 v30; // x20

  v4 = (*(_DWORD *)(a2 + 72) >> 18) & 0xF;
  context = _cds_get_context(71, "dp_gro_rx");
  if ( *(_BYTE *)(*(_QWORD *)a1 + 371LL) != 1
    || (a1[3614] & 1) != 0
    || (v6 = context, (dp_rx_is_ring_latency_sensitive_reo(v4) & 1) != 0) )
  {
    v15 = _cds_get_context(61, "dp_gro_rx_get_napi_from_id");
    intr_idx_from_rx_ring_id = wlan_cfg_get_intr_idx_from_rx_ring_id(v4);
    if ( intr_idx_from_rx_ring_id != -22 )
    {
      dp_rx_napi = hif_get_dp_rx_napi(v15, intr_idx_from_rx_ring_id);
      if ( dp_rx_napi )
        return dp_gro_rx_bh_disable(a1, dp_rx_napi, a2);
    }
    goto LABEL_19;
  }
  if ( !v6 )
  {
    v29 = "%s: soc in NULL!";
LABEL_18:
    qdf_trace_msg(0x45u, 2u, v29, v7, v8, v9, v10, v11, v12, v13, v14, "dp_rx_get_napi_context");
    goto LABEL_19;
  }
  if ( !*(_QWORD *)v6 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v7, v8, v9, v10, v11, v12, v13, v14, "cdp_soc_get_dp_txrx_handle");
LABEL_17:
    v29 = "%s: dp_ext_hdl in NULL!";
    goto LABEL_18;
  }
  v27 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)v6 + 624LL);
  if ( !v27 )
    goto LABEL_17;
  if ( *((_DWORD *)v27 - 1) != -1355198606 )
    __break(0x8228u);
  v28 = v27(v6);
  if ( !v28 )
    goto LABEL_17;
  dp_rx_napi = dp_rx_tm_get_napi_context(v28 + 16, v4);
  if ( dp_rx_napi )
    return dp_gro_rx_bh_disable(a1, dp_rx_napi, a2);
LABEL_19:
  v30 = jiffies;
  if ( dp_gro_rx___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: no napi to use for GRO!", v17, v18, v19, v20, v21, v22, v23, v24, "dp_gro_rx");
    dp_gro_rx___last_ticks = v30;
  }
  return 16;
}
