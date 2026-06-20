__int64 __fastcall dp_soc_cfg_attach(__int64 a1)
{
  unsigned int target_type; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x0
  char v15; // w0
  __int64 v16; // x8
  __int64 result; // x0
  __int64 v18; // x0
  char v19; // w0
  __int64 v20; // x8
  char v21; // w0
  __int64 v22; // x8
  __int64 v23; // x0

  target_type = hal_get_target_type(*(_QWORD *)(a1 + 1128));
  switch ( target_type )
  {
    case 0x14u:
      wlan_cfg_set_tso_desc_attach_defer(*(_QWORD *)(a1 + 40), 1);
      break;
    case 0x15u:
      wlan_cfg_set_reo_dst_ring_size(*(_QWORD *)(a1 + 40), 1023);
      break;
    case 0x17u:
    case 0x1Bu:
    case 0x1Cu:
      wlan_cfg_set_reo_dst_ring_size(*(_QWORD *)(a1 + 40), 1023);
      goto LABEL_5;
    case 0x18u:
    case 0x19u:
    case 0x1Au:
    case 0x1Du:
    case 0x1Eu:
    case 0x20u:
    case 0x21u:
    case 0x23u:
    case 0x27u:
    case 0x29u:
      wlan_cfg_set_tso_desc_attach_defer(*(_QWORD *)(a1 + 40), 1);
      wlan_cfg_set_rxdma1_enable(*(_QWORD *)(a1 + 40));
      break;
    case 0x1Fu:
    case 0x22u:
    case 0x25u:
    case 0x28u:
    case 0x2Au:
    case 0x2Bu:
      goto LABEL_5;
    case 0x24u:
      wlan_cfg_set_tso_desc_attach_defer(*(_QWORD *)(a1 + 40), 1);
LABEL_5:
      *(_BYTE *)(*(_QWORD *)(a1 + 40) + 633LL) = 0;
      break;
    default:
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: Unknown tgt type %d\n",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "dp_soc_cfg_attach",
        "dp_soc_cfg_attach",
        target_type);
      v23 = printk(
              &unk_AAA255,
              "0",
              "dp_soc_cfg_attach",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rings_main.c");
      dump_stack(v23);
      break;
  }
  v11 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 288LL);
  if ( v11 )
  {
    v12 = *(_QWORD *)(a1 + 16);
    if ( *((_DWORD *)v11 - 1) != 1044053383 )
      __break(0x8228u);
    v13 = v11(v12);
  }
  else
  {
    v13 = 0;
  }
  wlan_cfg_set_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40), v13);
  if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) )
  {
    wlan_cfg_set_num_tx_desc_pool(*(_QWORD *)(a1 + 40), 0);
    wlan_cfg_set_num_tx_ext_desc_pool(*(_QWORD *)(a1 + 40), 0);
    wlan_cfg_set_num_tx_desc(*(_QWORD *)(a1 + 40), 0);
    wlan_cfg_set_num_tx_spl_desc(*(_QWORD *)(a1 + 40), 0);
    wlan_cfg_set_num_tx_ext_desc(*(_QWORD *)(a1 + 40), 0);
    v14 = *(_QWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 7202) = 0;
    v15 = wlan_cfg_num_nss_tcl_data_rings(v14);
    v16 = *(_QWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 7201) = v15;
    result = wlan_cfg_num_nss_reo_dest_rings(v16);
  }
  else
  {
    v18 = *(_QWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 7202) = 1;
    v19 = wlan_cfg_num_tx_comp_rings(v18);
    v20 = *(_QWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 7200) = v19;
    v21 = wlan_cfg_num_tcl_data_rings(v20);
    v22 = *(_QWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 7201) = v21;
    result = wlan_cfg_num_reo_dest_rings(v22);
  }
  *(_BYTE *)(a1 + 12896) = result;
  return result;
}
