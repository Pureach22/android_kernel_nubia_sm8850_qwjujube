__int64 __fastcall lim_mlo_link_recfg_add_process_assoc_rsp(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  unsigned int cache_link_assoc_rsp; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  __int64 result; // x0
  __int64 v16; // x3
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  _ReadStatusReg(SP_EL0);
  v4 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 93LL);
  cache_link_assoc_rsp = mlo_get_cache_link_assoc_rsp();
  v14 = *(unsigned __int8 *)(a2 + 10);
  if ( cache_link_assoc_rsp )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev %d link_id %d assoc rsp get failed status %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "lim_mlo_link_recfg_add_process_assoc_rsp",
      v14,
      v4,
      cache_link_assoc_rsp);
    result = 4;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: process assoc rsp for link vdev %d link id %d len %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "lim_mlo_link_recfg_add_process_assoc_rsp",
      v14,
      v4,
      0);
    mgmt_txrx_frame_hex_dump(0, 0, 0, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    lim_process_assoc_rsp_frame(a1, 0, 0, 0, a2, v25, v26, v27, v28, v29, v30, v31, v32);
    _qdf_mem_free(0);
    lim_process_bcn_tpe_and_set_tpc(a1, a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
