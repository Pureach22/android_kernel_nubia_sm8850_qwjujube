__int64 __fastcall dp_rx_gro_flush_cbk(
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
  _QWORD *v10; // x8
  __int64 context; // x20
  unsigned int intr_idx_from_rx_ring_id; // w0
  __int64 dp_rx_napi; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x0

  if ( !a1 || (v10 = *(_QWORD **)(a1 + 32)) == nullptr || !*v10 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Null params being passed", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_gro_flush_cbk");
    return 16;
  }
  context = _cds_get_context(61, "dp_gro_rx_get_napi_from_id");
  intr_idx_from_rx_ring_id = wlan_cfg_get_intr_idx_from_rx_ring_id(a2);
  if ( intr_idx_from_rx_ring_id == -22 )
    return 16;
  dp_rx_napi = hif_get_dp_rx_napi(context, intr_idx_from_rx_ring_id);
  if ( !dp_rx_napi )
    return 16;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  v16 = napi_gro_flush(dp_rx_napi, 0);
  local_bh_enable(v16);
  return 0;
}
