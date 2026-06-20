__int64 __fastcall wlan_hdd_cfg80211_tx_pb_callback(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v12; // x2
  __int64 v13; // x0
  unsigned int v14; // w4
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  unsigned int v25; // w1
  __int64 result; // x0
  _DWORD *v27; // x0
  __int64 v28; // x22
  unsigned int v29; // w21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v12 = "%s: TPB: Invalid result";
    goto LABEL_34;
  }
  if ( (unsigned int)_wlan_hdd_validate_context(
                       a1,
                       (__int64)"wlan_hdd_cfg80211_tx_pb_callback",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
  {
    v12 = "%s: TPB: Invalid HDD context";
    goto LABEL_34;
  }
  qdf_wake_lock_timeout_acquire(a1 + 8584, 1000);
  qdf_runtime_pm_prevent_suspend((__int64 *)(a1 + 8784));
  v13 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 74, 128, 3264);
  if ( !v13 )
  {
    v12 = "%s: TPB: vendor_event skb alloc failed";
    goto LABEL_34;
  }
  v14 = a2[6];
  v15 = v13;
  if ( v14 >= 2 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: Invalid inference stage: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_tx_pb_convert_inf_stage_reg_to_nl");
    v14 = 0;
  }
  LODWORD(v46[0]) = v14;
  if ( (unsigned int)nla_put(v15, 8, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put inference_stage";
LABEL_33:
    qdf_trace_msg(0x33u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "hdd_tx_power_boost_pack_resp_nlmsg");
    sk_skb_reason_drop(0, v15, 2);
    v12 = "%s: TPB: Failed to pack Tx power boost response";
    goto LABEL_34;
  }
  LODWORD(v46[0]) = a2[7];
  if ( (unsigned int)nla_put(v15, 6, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put mcs";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[8];
  if ( (unsigned int)nla_put(v15, 2, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put bandwidth";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[9];
  if ( (unsigned int)nla_put(v15, 7, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put temperature_degreeC";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[10];
  if ( (unsigned int)nla_put(v15, 3, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put primary_chan_mhz";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[11];
  if ( (unsigned int)nla_put(v15, 4, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put center_freq1";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[12];
  if ( (unsigned int)nla_put(v15, 5, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put center_freq2";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[13];
  if ( (unsigned int)nla_put(v15, 11, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put phy_mode";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[18];
  if ( (unsigned int)nla_put(v15, 12, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put iq_sample_buf_size";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = hdd_tx_pb_convert_status_reg_to_nl((unsigned int)a2[5]);
  if ( (unsigned int)nla_put(v15, 13, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put iq_status";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[16];
  if ( (unsigned int)nla_put(v15, 16, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put tx power";
    goto LABEL_33;
  }
  LODWORD(v46[0]) = a2[17];
  if ( (unsigned int)nla_put(v15, 17, 4, v46) )
  {
    v24 = "%s: TPB: Failed to nla put tx_chain_idx";
    goto LABEL_33;
  }
  v27 = (_DWORD *)_qdf_mem_malloc(0x40u, "hdd_txpb_req_enqueue", 208);
  if ( !v27 )
  {
LABEL_41:
    sk_skb_reason_drop(0, v15, 2);
    v12 = "%s: TPB: Failed to enqueue TxPb request";
    goto LABEL_34;
  }
  v28 = (__int64)v27;
  v27[4] = a2[4];
  v27[5] = a2[5];
  v27[6] = a2[6];
  v27[7] = a2[7];
  v27[8] = a2[8];
  v27[9] = a2[9];
  v27[10] = a2[10];
  v27[11] = a2[11];
  v27[12] = a2[12];
  v27[13] = a2[13];
  v27[14] = a2[14];
  qdf_mutex_acquire(a1 + 8816);
  v29 = *(_DWORD *)(a1 + 8808);
  if ( v29 >= 5 )
  {
    qdf_mutex_release(a1 + 8816);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: Failed to enqueue req_id: %d, already max %d reached",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "hdd_txpb_req_enqueue",
      *(unsigned int *)(v28 + 56),
      v29);
    _qdf_mem_free(v28);
    goto LABEL_41;
  }
  qdf_list_insert_back((_QWORD *)(a1 + 8792), (_QWORD *)v28);
  qdf_mutex_release(a1 + 8816);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: TPB: enqueue req_id: %u cookie: %llx",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_txpb_req_enqueue",
    *(unsigned int *)(v28 + 56),
    v28);
  v46[0] = v28;
  if ( !(unsigned int)nla_put_64bit(v15, 14, 8, v46, 229) )
  {
    _cfg80211_send_event_skb(v15, 3264);
    v12 = "%s: TPB: NL event sent to userspace";
    v25 = 8;
    goto LABEL_35;
  }
  sk_skb_reason_drop(0, v15, 2);
  v12 = "%s: TPB: Failed to nla put cookie";
LABEL_34:
  v25 = 2;
LABEL_35:
  result = qdf_trace_msg(0x33u, v25, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_cfg80211_tx_pb_callback");
  _ReadStatusReg(SP_EL0);
  return result;
}
