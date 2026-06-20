__int64 __fastcall wlan_mgmt_txrx_desc_pool_deinit(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x23
  unsigned int v12; // w20
  __int64 v13; // x24
  unsigned int v14; // w0
  __int64 result; // x0
  __int64 v16; // x0

  if ( *(_QWORD *)(a1 + 32) )
  {
    v9 = *(unsigned int *)(a1 + 28);
    if ( (_DWORD)v9 )
    {
      v11 = 0;
      v12 = 0;
      v13 = 72 * v9;
      do
      {
        v14 = qdf_list_remove_node(a1 + 8, (_QWORD *)(*(_QWORD *)(a1 + 32) + v11));
        if ( v14 )
          qdf_trace_msg(
            0x4Bu,
            2u,
            "%s: Failed to get mgmt desc from freelist, desc id: %d: status %d",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "wlan_mgmt_txrx_desc_pool_deinit",
            v12,
            v14);
        v11 += 72;
        ++v12;
      }
      while ( v13 != v11 );
    }
    if ( *(_DWORD *)(a1 + 24) )
      qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", a2, a3, a4, a5, a6, a7, a8, a9, "qdf_list_destroy");
    result = _qdf_mem_free(*(_QWORD *)(a1 + 32));
    *(_QWORD *)(a1 + 32) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Empty mgmt descriptor pool",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mgmt_txrx_desc_pool_deinit");
    v16 = printk(
            &unk_AAA255,
            "0",
            "wlan_mgmt_txrx_desc_pool_deinit",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/umac/cmn_services/mgmt_txrx/core/src/wlan_mgmt_txrx_main.c");
    return dump_stack(v16);
  }
  return result;
}
