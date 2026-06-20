__int64 __fastcall dp_tso_soc_attach(__int64 a1)
{
  unsigned int num_tx_desc_pool; // w20
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  unsigned int num_tx_ext_desc; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2
  const char *v17; // x3
  __int64 result; // x0

  num_tx_desc_pool = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  num_tx_ext_desc = wlan_cfg_get_num_tx_ext_desc(*(_QWORD *)(a1 + 40), v3, v4, v5, v6);
  if ( (unsigned int)dp_tx_tso_desc_pool_alloc(a1, num_tx_desc_pool, num_tx_ext_desc) )
  {
    v16 = "%s: TSO Desc Pool alloc %d failed %pK";
LABEL_5:
    v17 = "dp_tx_tso_cmn_desc_pool_alloc";
LABEL_6:
    qdf_trace_msg(0x45u, 2u, v16, v8, v9, v10, v11, v12, v13, v14, v15, v17, (unsigned __int8)num_tx_desc_pool, a1);
    return 16;
  }
  if ( (unsigned int)dp_tx_tso_num_seg_pool_alloc(a1, num_tx_desc_pool, num_tx_ext_desc) )
  {
    v16 = "%s: TSO Num of seg Pool alloc %d failed %pK";
    goto LABEL_5;
  }
  if ( (unsigned int)dp_tx_tso_desc_pool_init(a1, num_tx_desc_pool, num_tx_ext_desc) )
  {
    v16 = "%s: TSO Desc Pool alloc %d failed %pK";
LABEL_12:
    v17 = "dp_tx_tso_cmn_desc_pool_init";
    goto LABEL_6;
  }
  result = dp_tx_tso_num_seg_pool_init(a1, num_tx_desc_pool, num_tx_ext_desc);
  if ( (_DWORD)result )
  {
    v16 = "%s: TSO Num of seg Pool alloc %d failed %pK";
    goto LABEL_12;
  }
  return result;
}
