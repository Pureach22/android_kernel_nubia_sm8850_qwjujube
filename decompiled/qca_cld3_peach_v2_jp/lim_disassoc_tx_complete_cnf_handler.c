__int64 __fastcall lim_disassoc_tx_complete_cnf_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( a4 )
  {
    wlan_send_tx_complete_event(a1, a2, a4, a3, 11);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: tx_success: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_disassoc_tx_complete_cnf_handler",
      a3);
    lim_update_disconnect_vdev_id(a1, *(unsigned __int8 *)(a4 + 10));
    if ( !a2 )
      goto LABEL_4;
    goto LABEL_3;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tx_success: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_disassoc_tx_complete_cnf_handler",
    a3);
  if ( a2 )
LABEL_3:
    _qdf_nbuf_free(a2);
LABEL_4:
  v35 = a4;
  LOWORD(v34) = 4319;
  HIDWORD(v34) = a3;
  v24 = lim_post_msg_high_priority(a1, (unsigned __int16 *)&v34);
  if ( v24 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: posting message: %X to LIM failed, reason: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_disassoc_tx_complete_cnf_handler",
      (unsigned __int16)v34,
      v24);
  _ReadStatusReg(SP_EL0);
  return v24;
}
