__int64 __fastcall dp_soc_srng_alloc(__int64 a1)
{
  __int64 v1; // x20
  unsigned int dp_soc_wbm_release_ring_size; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x3
  __int64 v14; // x21
  unsigned int dp_soc_reo_reinject_ring_size; // w0
  unsigned int dp_soc_rx_release_ring_size; // w0
  unsigned int dp_soc_reo_cmd_ring_size; // w0
  unsigned int dp_soc_reo_status_ring_size; // w0
  __int64 result; // x0
  unsigned int dp_soc_reo_exception_ring_size; // w0
  unsigned int v21; // w21
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x4
  unsigned __int64 v25; // x21
  __int64 v26; // x22
  __int64 reo_dst_ring_size; // x0
  __int64 v28; // x1
  __int64 (__fastcall *v29)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 40);
  dp_soc_wbm_release_ring_size = wlan_cfg_get_dp_soc_wbm_release_ring_size(v1);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 7768, 0xCu, dp_soc_wbm_release_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed for wbm_desc_rel_ring";
LABEL_3:
    v13 = "dp_soc_srng_alloc";
LABEL_13:
    qdf_trace_msg(0x7Cu, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, v13, a1);
    goto LABEL_14;
  }
  v14 = *(_QWORD *)(a1 + 40);
  dp_soc_reo_reinject_ring_size = wlan_cfg_get_dp_soc_reo_reinject_ring_size(v14);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 6480, 2u, dp_soc_reo_reinject_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed for reo_reinject_ring";
LABEL_12:
    v13 = "dp_srng_alloc_non_bn_rings";
    goto LABEL_13;
  }
  dp_soc_rx_release_ring_size = wlan_cfg_get_dp_soc_rx_release_ring_size(v14);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 6720, 0xDu, dp_soc_rx_release_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed for rx_rel_ring";
    goto LABEL_12;
  }
  dp_soc_reo_cmd_ring_size = wlan_cfg_get_dp_soc_reo_cmd_ring_size(v14);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 6560, 3u, dp_soc_reo_cmd_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed for reo_cmd_ring";
    goto LABEL_12;
  }
  dp_soc_reo_status_ring_size = wlan_cfg_get_dp_soc_reo_status_ring_size(v14);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 6640, 4u, dp_soc_reo_status_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed for reo_status_ring";
    goto LABEL_12;
  }
  dp_soc_reo_exception_ring_size = wlan_cfg_get_dp_soc_reo_exception_ring_size(v1);
  if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 6400, 1u, dp_soc_reo_exception_ring_size, 0) )
  {
    v12 = "%s: %pK: dp_srng_alloc failed - reo_exception";
    goto LABEL_3;
  }
  wlan_cfg_get_dp_soc_nss_cfg(v1);
  if ( *(_BYTE *)(a1 + 7201) )
  {
    v21 = 0;
    while ( !(unsigned int)dp_alloc_tx_ring_pair_by_index(a1, v21) )
    {
      if ( ++v21 >= *(unsigned __int8 *)(a1 + 7201) )
        goto LABEL_22;
    }
    goto LABEL_14;
  }
LABEL_22:
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 && (unsigned int)dp_alloc_tx_ring_pair_by_index(a1, 4) )
  {
LABEL_14:
    ((void (__fastcall *)(__int64))dp_soc_srng_free)(a1);
    return 2;
  }
  if ( *(_BYTE *)(a1 + 12896) )
  {
    v25 = 0;
    v26 = a1 + 5760;
    while ( 1 )
    {
      reo_dst_ring_size = wlan_cfg_get_reo_dst_ring_size(v1, (unsigned int)v25, v22, v23, v24);
      if ( v25 == 9 )
        break;
      if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, v26, 0, reo_dst_ring_size, 0) )
      {
        v12 = "%s: %pK: dp_srng_alloc failed for reo_dest_ring";
        goto LABEL_3;
      }
      ++v25;
      v26 += 80;
      if ( v25 >= *(unsigned __int8 *)(a1 + 12896) )
        goto LABEL_29;
    }
    __break(0x5512u);
    return dp_alloc_tx_ring_pair_by_index(reo_dst_ring_size, v28);
  }
  else
  {
LABEL_29:
    v29 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1176);
    if ( !v29 )
      return 0;
    if ( *((_DWORD *)v29 - 1) != -1941278151 )
      __break(0x8228u);
    result = v29(a1);
    if ( (_DWORD)result )
    {
      v12 = "%s: %pK: dp_srng_alloc failed for arch rings";
      goto LABEL_3;
    }
  }
  return result;
}
