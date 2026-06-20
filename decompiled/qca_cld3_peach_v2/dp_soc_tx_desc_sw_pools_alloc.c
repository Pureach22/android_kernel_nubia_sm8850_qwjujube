__int64 __fastcall dp_soc_tx_desc_sw_pools_alloc(__int64 a1)
{
  __int64 result; // x0
  unsigned __int8 num_tx_desc_pool; // w22
  unsigned int v4; // w20
  unsigned int num_tx_spl_desc; // w23
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  unsigned int num_tx_ext_desc; // w21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2

  if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) )
    return 0;
  num_tx_desc_pool = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  v4 = wlan_cfg_get_num_tx_desc_pool(*(_QWORD *)(a1 + 40));
  num_tx_spl_desc = wlan_cfg_get_num_tx_spl_desc(*(_QWORD *)(a1 + 40));
  num_tx_ext_desc = wlan_cfg_get_num_tx_ext_desc(*(_QWORD *)(a1 + 40), v6, v7, v8, v9);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Tx Desc Alloc num_pool: %d ",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dp_soc_tx_desc_sw_pools_alloc",
    num_tx_desc_pool);
  result = 1;
  if ( num_tx_desc_pool <= 6u && (unsigned __int8)v4 <= 6u && num_tx_spl_desc <= 0x1000 )
  {
    if ( num_tx_desc_pool )
    {
      *(_DWORD *)(a1 + 2560) = 0;
      *(_QWORD *)(a1 + 2568) = 0;
      *(_DWORD *)(a1 + 2368) = 6;
      if ( num_tx_desc_pool != 1 )
      {
        *(_DWORD *)(a1 + 2856) = 0;
        *(_QWORD *)(a1 + 2864) = 0;
        *(_DWORD *)(a1 + 2664) = 6;
        if ( num_tx_desc_pool != 2 )
        {
          *(_DWORD *)(a1 + 3152) = 0;
          *(_QWORD *)(a1 + 3160) = 0;
          *(_DWORD *)(a1 + 2960) = 6;
          if ( num_tx_desc_pool != 3 )
          {
            *(_DWORD *)(a1 + 3448) = 0;
            *(_QWORD *)(a1 + 3456) = 0;
            *(_DWORD *)(a1 + 3256) = 6;
            if ( num_tx_desc_pool != 4 )
            {
              *(_DWORD *)(a1 + 3744) = 0;
              *(_QWORD *)(a1 + 3752) = 0;
              *(_DWORD *)(a1 + 3552) = 6;
              if ( num_tx_desc_pool != 5 )
              {
                *(_DWORD *)(a1 + 4040) = 0;
                *(_QWORD *)(a1 + 4048) = 0;
                *(_DWORD *)(a1 + 3848) = 6;
              }
            }
          }
        }
      }
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dp_tx_ext_desc_pool_alloc)(
                         a1,
                         v4,
                         num_tx_ext_desc) )
      return 1;
    if ( (wlan_cfg_is_tso_desc_attach_defer(*(_QWORD *)(a1 + 40)) & 1) != 0 )
      return 0;
    if ( (unsigned int)dp_tx_tso_desc_pool_alloc(a1, v4, num_tx_ext_desc) )
    {
      v27 = "%s: TSO Desc Pool alloc %d failed %pK";
LABEL_20:
      qdf_trace_msg(0x45u, 2u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "dp_tx_tso_cmn_desc_pool_alloc", v4 & 7, a1);
      dp_tx_ext_desc_pool_free(a1, v4);
      return 1;
    }
    result = dp_tx_tso_num_seg_pool_alloc(a1, v4, num_tx_ext_desc);
    if ( (_DWORD)result )
    {
      v27 = "%s: TSO Num of seg Pool alloc %d failed %pK";
      goto LABEL_20;
    }
  }
  return result;
}
