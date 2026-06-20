__int64 __fastcall p2p_process_mgmt_tx_ack_cnf(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x22
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x19
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x6
  __int64 v43; // x8
  unsigned int v44; // w7
  unsigned int v45; // w9
  int v46; // w10
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x9
  void (__fastcall *v56)(__int64, __int64 *); // x8
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // [xsp+18h] [xbp-38h] BYREF
  __int64 v67; // [xsp+20h] [xbp-30h]
  unsigned __int64 v68; // [xsp+28h] [xbp-28h]
  __int64 v69; // [xsp+30h] [xbp-20h]
  __int64 v70; // [xsp+38h] [xbp-18h]
  _QWORD *v71[2]; // [xsp+40h] [xbp-10h] BYREF

  v71[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)a1;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v66 = 0;
  if ( v10 && v10[11] )
  {
    v11 = *(_QWORD *)(a1 + 8);
    v71[0] = nullptr;
    v20 = nullptr;
    if ( !(unsigned int)qdf_list_peek_front(v10 + 7, v71) )
    {
      do
      {
        v20 = v71[0];
        if ( v71[0][32] == v11 )
        {
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: find tx ctx, nbuf:%pK",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "p2p_find_tx_ctx_by_nbuf",
            v11);
          goto LABEL_12;
        }
      }
      while ( !(unsigned int)qdf_list_peek_next(v10 + 7, v71[0], v71) );
      v20 = nullptr;
    }
LABEL_12:
    v23 = *(_QWORD *)(a1 + 8);
    if ( v23 )
      _qdf_nbuf_free(v23);
    if ( v20 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: tx context:%pK",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "p2p_disable_tx_timer",
        v20);
      v24 = qdf_mc_timer_stop((__int64)(v20 + 9));
      if ( v24 )
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to stop tx timer, status:%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "p2p_disable_tx_timer",
          v24);
      v33 = qdf_mc_timer_destroy((__int64)(v20 + 9));
      if ( v33 )
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to destroy tx timer, status:%d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "p2p_disable_tx_timer",
          v33);
      v42 = *((int *)v20 + 10);
      v43 = v20[6];
      v44 = *((_DWORD *)v20 + 14);
      v45 = *(_DWORD *)(a1 + 16);
      v46 = *((_DWORD *)v20 + 66);
      LODWORD(v66) = *((_DWORD *)v20 + 6);
      v67 = v42;
      v69 = v43;
      v68 = __PAIR64__(v45, v44);
      LODWORD(v70) = v46;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: soc:%pK, vdev_id:%d, action_cookie:%llx, len:%d, status:%d, buf:%pK",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "p2p_process_mgmt_tx_ack_cnf",
        *v10,
        v45,
        v43);
      if ( *v10 && (*((_BYTE *)v20 + 63) & 1) != 0 )
        p2p_random_mac_handle_tx_done(
          *v10,
          *((_DWORD *)v20 + 6),
          *((int *)v20 + 10),
          *((_DWORD *)v20 + 16),
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54);
      v55 = v10[11];
      v56 = *(void (__fastcall **)(__int64, __int64 *))(v55 + 32);
      if ( v56 )
      {
        v57 = *(_QWORD *)(v55 + 40);
        if ( *((_DWORD *)v56 - 1) != 366326974 )
          __break(0x8228u);
        v56(v57, &v66);
      }
      else
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: Got tx conf, but no valid up layer callback",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "p2p_process_mgmt_tx_ack_cnf");
      }
      p2p_remove_tx_context((__int64)v20, v58, v59, v60, v61, v62, v63, v64, v65);
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: can't find tx_ctx, tx ack comes late",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "p2p_process_mgmt_tx_ack_cnf");
    }
    result = 0;
  }
  else
  {
    v21 = *(_QWORD *)(a1 + 8);
    if ( v21 )
      _qdf_nbuf_free(v21);
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Invalid p2p soc object or start parameters",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_mgmt_tx_ack_cnf");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
