__int64 __fastcall dp_set_psoc_param(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  unsigned __int8 v13; // w4
  const char *v14; // x2
  unsigned __int8 v15; // w4
  unsigned __int8 v16; // w4
  int v17; // w4
  __int64 v19; // x19
  __int64 v20; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w5
  int v31; // w19
  _DWORD *v32; // x21
  _BYTE *v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w9
  int v43; // w8

  v12 = *(_QWORD *)(a1 + 40);
  switch ( a2 )
  {
    case 0:
      *(_BYTE *)(a1 + 18672) = *a3;
      return 0;
    case 1:
      v19 = a1;
      v20 = v12;
      wlan_cfg_set_dp_soc_nss_cfg();
      v30 = *(_DWORD *)a3;
      if ( *(int *)a3 > 2 )
      {
        if ( v30 != 7 && v30 != 3 )
          goto LABEL_39;
LABEL_34:
        wlan_cfg_set_num_tx_desc_pool(v20, 0);
        wlan_cfg_set_num_tx_ext_desc_pool(v20, 0);
        wlan_cfg_set_num_tx_desc(v20, 0);
        wlan_cfg_set_num_tx_spl_desc(*(_QWORD *)(v19 + 40), 0);
        wlan_cfg_set_num_tx_ext_desc(v20, 0);
        goto LABEL_40;
      }
      if ( !v30 )
        goto LABEL_40;
      if ( v30 == 1 )
        goto LABEL_34;
LABEL_39:
      qdf_trace_msg(
        0x89u,
        2u,
        "%s: %pK: Invalid offload config %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_set_psoc_param",
        v19);
LABEL_40:
      qdf_trace_msg(
        0x89u,
        2u,
        "%s: %pK: nss-wifi<0> nss config is enabled",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_set_psoc_param",
        v19);
      return 0;
    case 2:
      *(_BYTE *)(a1 + 18716) = *(_DWORD *)a3;
      return 0;
    case 4:
      *(_BYTE *)(v12 + 540) = *a3;
      return 0;
    case 5:
      wlan_cfg_set_vdev_stats_hw_offload_config(v12, *a3);
      return 0;
    case 6:
      wlan_cfg_set_sawf_config(v12, *a3);
      return 0;
    case 8:
      wlan_cfg_set_sawf_stats_config(v12, *a3);
      return 0;
    case 10:
      v31 = *a3;
      v32 = (_DWORD *)a1;
      v33 = (_BYTE *)(a1 + 13280);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: rx_peer_metadata version %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_rx_peer_metadata_ver_update",
        *a3);
      if ( v31 > 1 )
      {
        if ( v31 != 2 && v31 != 3 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: invliad rx_peer_metadata version %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "dp_rx_peer_metadata_ver_update",
            (unsigned int)v31);
          v33[24] = v31;
          return 0;
        }
        v42 = 14;
        *v33 = 0;
        v32[3321] = 0x1FFF;
        v43 = 4177920;
      }
      else
      {
        if ( !v31 )
        {
          *v33 = 0;
          v32[3321] = 0xFFFF;
          v33[8] = 16;
          v32[3323] = 16711680;
          v33[24] = 0;
          return 0;
        }
        v42 = 16;
        *v33 = 0;
        v32[3321] = 0x1FFF;
        v43 = 16711680;
      }
      v33[8] = v42;
      v32[3323] = v43;
      v33[16] = 13;
      v32[3325] = 0x2000;
      v33[24] = v31;
      return 0;
    case 12:
      wlan_cfg_set_num_tx_desc(v12, *(unsigned int *)a3);
      return 0;
    case 13:
      wlan_cfg_set_num_tx_ext_desc(v12, *(unsigned int *)a3);
      return 0;
    case 14:
      wlan_cfg_set_tx_ring_size(v12, *(unsigned int *)a3);
      return 0;
    case 15:
      wlan_cfg_set_tx_comp_ring_size(v12, *(unsigned int *)a3);
      return 0;
    case 16:
      wlan_cfg_set_dp_soc_rx_sw_desc_num(v12, *(unsigned int *)a3);
      return 0;
    case 17:
      wlan_cfg_set_reo_dst_ring_size(v12, *(unsigned int *)a3);
      return 0;
    case 18:
      wlan_cfg_set_dp_soc_rxdma_refill_ring_size(v12, *(unsigned int *)a3);
      return 0;
    case 19:
      wlan_cfg_set_rx_refill_buf_pool_size(v12, *(unsigned int *)a3);
      return 0;
    case 22:
      wlan_cfg_set_ast_indication_disable(v12, *a3);
      return 0;
    case 25:
      *(_BYTE *)(a1 + 1142) = *a3;
      return 0;
    case 26:
      v13 = *a3;
      v14 = "%s: FW support ML mon: %d";
      *(_BYTE *)(a1 + 20045) = v13;
      goto LABEL_12;
    case 27:
      v17 = *a3;
      v14 = "%s: monior interface flags: 0x%x";
      *(_DWORD *)(a1 + 20216) = v17;
      goto LABEL_12;
    case 29:
      *(_BYTE *)(a1 + 20220) = *a3;
      return 0;
    case 30:
      v15 = *a3;
      v14 = "%s: FW supports Tx Vdev NSS report: %d";
      *(_BYTE *)(a1 + 20047) = v15;
      goto LABEL_12;
    case 31:
      v16 = *a3;
      v14 = "%s: Dynamic resource manager support: %u";
      *(_BYTE *)(a1 + 20048) = v16;
LABEL_12:
      qdf_trace_msg(0x45u, 5u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "dp_set_psoc_param");
      return 0;
    default:
      return 0;
  }
}
