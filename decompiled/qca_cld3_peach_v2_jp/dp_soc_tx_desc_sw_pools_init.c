__int64 __fastcall dp_soc_tx_desc_sw_pools_init(__int64 a1)
{
  unsigned int num_tx_desc_pool; // w20
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  unsigned int num_tx_ext_desc; // w21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2

  if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) )
    return 0;
  wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  num_tx_desc_pool = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  wlan_cfg_get_num_tx_spl_desc(*(_QWORD *)(a1 + 40));
  num_tx_ext_desc = wlan_cfg_get_num_tx_ext_desc(*(_QWORD *)(a1 + 40), v4, v5, v6, v7);
  if ( !(unsigned int)dp_tx_ext_desc_pool_init(a1, num_tx_desc_pool, num_tx_ext_desc) )
  {
    if ( (wlan_cfg_is_tso_desc_attach_defer(*(_QWORD *)(a1 + 40)) & 1) != 0 )
      return 0;
    if ( (unsigned int)dp_tx_tso_desc_pool_init(a1, num_tx_desc_pool, num_tx_ext_desc) )
    {
      v17 = "%s: TSO Desc Pool alloc %d failed %pK";
    }
    else
    {
      if ( !(unsigned int)dp_tx_tso_num_seg_pool_init(a1, num_tx_desc_pool, num_tx_ext_desc) )
      {
        dp_tx_flow_control_init(a1);
        *(_BYTE *)(a1 + 17548) = 1;
        return 0;
      }
      v17 = "%s: TSO Num of seg Pool alloc %d failed %pK";
    }
    qdf_trace_msg(
      0x45u,
      2u,
      v17,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_tx_tso_cmn_desc_pool_init",
      (unsigned __int8)num_tx_desc_pool,
      a1);
    ((void (__fastcall *)(__int64, _QWORD))dp_tx_ext_desc_pool_deinit)(a1, num_tx_desc_pool);
  }
  return 1;
}
