__int64 __fastcall hdd_ipa_send_nbuf_to_network(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 vdev_by_user; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x6
  __int64 v40; // x7
  char *StatusReg; // x8
  _BYTE *v42; // x23
  char v43; // w24
  __int64 v44; // x0
  char v45; // w8
  unsigned int v46; // w21
  int v47; // w0
  __int64 result; // x0

  if ( (unsigned int)_hdd_validate_adapter(
                       a2 + 2688,
                       (__int64)"hdd_ipa_send_nbuf_to_network",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10)
    || (cds_get_driver_state(v12, v13, v14, v15, v16, v17, v18, v19) & 4) != 0 )
  {
    return sk_skb_reason_drop(0, a1, 2);
  }
  hdd_ipa_update_rx_mcbc_stats(a2 + 2688, a1);
  if ( *(_DWORD *)(a2 + 2728) == 1 && _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a1 + 224)) )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 0x61u, (__int64)"hdd_ipa_send_nbuf_to_network");
    if ( vdev_by_user )
    {
      v29 = vdev_by_user;
      ucfg_dp_softap_inspect_dhcp_packet(vdev_by_user, a1, 1, v21, v22, v23, v24, v25, v26, v27, v28);
      _hdd_objmgr_put_vdev_by_user(
        v29,
        0x61u,
        (__int64)"hdd_ipa_send_nbuf_to_network",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38);
    }
  }
  _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a1 + 224));
  qdf_dp_trace_set_track(a1, 1);
  ucfg_dp_event_eapol_log(a1, 1);
  qdf_dp_trace_log_pkt(*(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL), a1, 1u, 0xFFu, *(_DWORD *)(a2 + 2728));
  qdf_dp_trace(a1, 0x1Bu, 0xFFu, a1 + 224, 8u, 1, v39, v40);
  qdf_dp_trace_data_pkt(a1, 0xFFu, 0xFu, 0, 1);
  StatusReg = (char *)_ReadStatusReg(SP_EL0);
  if ( StatusReg == (char *)&init_task )
    v42 = &vendor_data_pad;
  else
    v42 = StatusReg + 5184;
  v43 = v42[188];
  if ( !v43 )
    v42[188] = 1;
  *(_QWORD *)(a1 + 16) = *(_QWORD *)(a2 + 2720);
  v44 = eth_type_trans(a1);
  v45 = *(_BYTE *)(a1 + 128);
  v46 = *(_DWORD *)(a1 + 112);
  *(_WORD *)(a1 + 180) = v44;
  *(_BYTE *)(a1 + 128) = v45 & 0x9F;
  if ( (ipa_get_lan_rx_napi(v44) & 1) != 0 )
    v47 = netif_receive_skb(a1);
  else
    v47 = netif_rx(a1);
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, bool))ucfg_dp_inc_rx_pkt_stats)(
             *(_QWORD *)(*(_QWORD *)(a2 + 55512) + 32LL),
             v46,
             v47 == 0);
  if ( (v43 & 1) == 0 )
    v42[188] = 0;
  return result;
}
