__int64 __fastcall wlan_ipa_tx_pkt_opt_dp_ctrl(
        unsigned __int8 a1,
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
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int16 *v21; // x22
  unsigned __int64 StatusReg; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  unsigned int v32; // w9
  __int64 v33; // x9
  __int16 v34; // w10
  __int64 v35; // x8
  unsigned __int16 v36; // w19
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w2
  int v55; // w3
  int v56; // w4
  int v57; // w5
  int v58; // w6
  int v59; // w7
  __int64 v60; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v12 = gp_ipa;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: schedule WQ for vdev id %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ipa_tx_pkt_opt_dp_ctrl",
    a1);
  v21 = *(unsigned __int16 **)(v12 + 2768);
  if ( v21 && *((_QWORD *)v21 + 1) )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: enqueue msg to the list",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_fw_event_msg_list_enqueue");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v21 + 12);
    }
    else
    {
      raw_spin_lock_bh(v21 + 12);
      *((_QWORD *)v21 + 4) |= 1uLL;
    }
    v31 = *v21;
    v32 = v21[1];
    if ( v32 <= (unsigned int)v31 )
    {
      if ( (_WORD)v32 + v21[8] + ~(_WORD)v31 )
        goto LABEL_9;
    }
    else if ( (_WORD)v32 + ~(_WORD)v31 )
    {
LABEL_9:
      v33 = *((_QWORD *)v21 + 1) + 32 * v31;
      *(_BYTE *)v33 = a1;
      *(_QWORD *)(v33 + 8) = a2;
      *(_WORD *)(v33 + 16) = 13;
      v34 = v31 + 1;
      v35 = *((_QWORD *)v21 + 4);
      v36 = (v21[8] - 1) & v34;
      *v21 = v36;
      if ( (v35 & 1) != 0 )
      {
        *((_QWORD *)v21 + 4) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v21 + 12);
      }
      else
      {
        raw_spin_unlock(v21 + 12);
      }
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: hp value %d",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "wlan_fw_event_msg_list_enqueue",
        v36);
      *(_WORD *)(v12 + 2776) |= 1u;
      return queue_work_on(32, system_wq, v12 + 2696);
    }
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: list is full",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_fw_event_msg_list_enqueue");
    v60 = *((_QWORD *)v21 + 4);
    if ( (v60 & 1) != 0 )
    {
      *((_QWORD *)v21 + 4) = v60 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v21 + 12);
    }
    else
    {
      raw_spin_unlock(v21 + 12);
    }
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: list allocation failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_fw_event_msg_list_enqueue");
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: nbuf message enqueue failed",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wlan_ipa_tx_pkt_opt_dp_ctrl");
  result = wlan_ipa_log_message(
             (int)"wlan_ipa_tx_pkt_opt_dp_ctrl",
             (int)"nbuf message enqueue failed",
             v54,
             v55,
             v56,
             v57,
             v58,
             v59,
             vars0);
  ++*(_DWORD *)(v12 + 8428);
  if ( a2 )
    return _qdf_nbuf_free(a2);
  return result;
}
