__int64 __fastcall dp_get_psoc_param(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x19
  __int64 hash_key; // x8
  _DWORD *v18; // x19
  int num_tx_ext_desc; // w0
  _BYTE *v20; // x19
  char is_peer_ext_stats_enabled; // w0
  char v22; // w8
  int v23; // w8

  if ( !a1 )
    return 16;
  v12 = a1;
  v13 = *(_QWORD *)(a1 + 40);
  switch ( (int)a2 )
  {
    case 0:
      LOBYTE(v12) = *(_BYTE *)(v12 + 18728);
      goto LABEL_24;
    case 3:
      v20 = (_BYTE *)a3;
      is_peer_ext_stats_enabled = wlan_cfg_is_peer_ext_stats_enabled(v13);
      goto LABEL_26;
    case 5:
      v20 = (_BYTE *)a3;
      is_peer_ext_stats_enabled = wlan_cfg_get_vdev_stats_hw_offload_config(v13);
      goto LABEL_26;
    case 7:
      result = 0;
      *(_BYTE *)a3 = 0;
      return result;
    case 11:
      result = 0;
      *(_QWORD *)a3 = *(_QWORD *)(v12 + 1128);
      return result;
    case 12:
      v18 = (_DWORD *)a3;
      wlan_cfg_get_num_tx_desc(v13, 0xFFFF);
      goto LABEL_28;
    case 13:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_get_num_tx_ext_desc(v13, a2, a3, a4, (unsigned int)a2);
      goto LABEL_28;
    case 14:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_tx_ring_size(v13, 0xFFFF, a3, a4, (unsigned int)a2);
      goto LABEL_28;
    case 15:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_tx_comp_ring_size(v13, 0xFFFF, a3, a4, (unsigned int)a2);
      goto LABEL_28;
    case 16:
      v18 = (_DWORD *)a3;
      wlan_cfg_get_dp_soc_rx_sw_desc_num(v13);
      goto LABEL_28;
    case 17:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_get_reo_dst_ring_size(v13, 0xFFFF, a3, a4, (unsigned int)a2);
      goto LABEL_28;
    case 18:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_get_dp_soc_rxdma_refill_ring_size(v13);
      goto LABEL_28;
    case 19:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_get_rx_refill_buf_pool_size(v13, a2, a3, a4, (unsigned int)a2);
      goto LABEL_28;
    case 20:
      v15 = v12;
      *(_DWORD *)a3 = (unsigned __int16)wlan_cfg_get_rx_flow_search_table_size(v13, a2, a3, a4, (unsigned int)a2);
      *(_WORD *)(a3 + 4) = (unsigned __int8)wlan_cfg_rx_fst_get_max_search(*(_QWORD *)(v15 + 40));
      hash_key = wlan_cfg_rx_fst_get_hash_key(*(_QWORD *)(v15 + 40));
      result = 0;
      *(_QWORD *)(a3 + 8) = hash_key;
      return result;
    case 21:
      result = 0;
      *(_WORD *)a3 = *(_WORD *)(v12 + 1138);
      return result;
    case 23:
      LOBYTE(v12) = -1;
      goto LABEL_24;
    case 24:
      v20 = (_BYTE *)a3;
      is_peer_ext_stats_enabled = wlan_cfg_is_peer_jitter_stats_enabled(v13);
LABEL_26:
      v22 = is_peer_ext_stats_enabled;
      *v20 = v22 & 1;
      return 0;
    case 25:
      LOBYTE(v12) = *(_BYTE *)(v12 + 1142);
      goto LABEL_24;
    case 26:
      LOBYTE(v12) = *(_BYTE *)(v12 + 20101);
      goto LABEL_24;
    case 27:
      LODWORD(v12) = *(_DWORD *)(v12 + 20272);
      goto LABEL_24;
    case 28:
      v18 = (_DWORD *)a3;
      num_tx_ext_desc = wlan_cfg_get_reo_rings_mapping(v13, a2, a3, a4, (unsigned int)a2);
LABEL_28:
      v23 = num_tx_ext_desc;
      result = 0;
      *v18 = v23;
      return result;
    case 30:
      LOBYTE(v12) = *(_BYTE *)(v12 + 20103);
LABEL_24:
      *(_BYTE *)a3 = v12;
      result = 0;
      break;
    default:
      qdf_trace_msg(0x45u, 3u, "%s: Invalid param: %u", a5, a6, a7, a8, a9, a10, a11, a12, "dp_get_psoc_param");
      result = 0;
      break;
  }
  return result;
}
