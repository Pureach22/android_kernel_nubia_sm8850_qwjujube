__int64 __fastcall dp_rx_thread_gro_flush_ind_cbk(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 context; // x20
  unsigned int intr_idx_from_rx_ring_id; // w0
  __int64 dp_rx_napi; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x0
  unsigned int v18; // w20
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 (*v28)(void); // x8
  __int64 v29; // x0

  if ( !a1 || (v10 = *(_QWORD *)(a1 + 32)) == 0 || !*(_QWORD *)v10 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Null params being passed",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_rx_thread_gro_flush_ind_cbk");
    return 16;
  }
  if ( (*(_BYTE *)(v10 + 3614) & 1) != 0 || (dp_rx_is_ring_latency_sensitive_reo(a2) & 1) != 0 )
  {
    context = _cds_get_context(61, "dp_gro_rx_get_napi_from_id");
    intr_idx_from_rx_ring_id = wlan_cfg_get_intr_idx_from_rx_ring_id(a2);
    if ( intr_idx_from_rx_ring_id != -22 )
    {
      dp_rx_napi = hif_get_dp_rx_napi(context, intr_idx_from_rx_ring_id);
      if ( dp_rx_napi )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        *(_DWORD *)(StatusReg + 16) += 512;
        v16 = napi_gro_flush(dp_rx_napi, 0);
        local_bh_enable(v16);
        return 0;
      }
    }
    return 16;
  }
  if ( *(_DWORD *)(*(_QWORD *)v10 + 1104LL) )
  {
    ++*(_DWORD *)(v10 + 2680);
    v18 = 2;
  }
  else
  {
    v18 = 1;
  }
  v19 = _cds_get_context(71, "dp_rx_thread_gro_flush_ind_cbk");
  if ( v19 )
  {
    if ( *(_QWORD *)v19 )
    {
      v28 = *(__int64 (**)(void))(**(_QWORD **)v19 + 624LL);
      if ( v28 )
      {
        if ( *((_DWORD *)v28 - 1) != -1355198606 )
          __break(0x8228u);
        v29 = v28();
        if ( v29 )
          return dp_rx_tm_gro_flush_ind(v29 + 16, a2, v18);
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "cdp_soc_get_dp_txrx_handle");
    }
    return 5;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: invalid input param soc %pK",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_rx_gro_flush_ind",
      0);
    return 4;
  }
}
