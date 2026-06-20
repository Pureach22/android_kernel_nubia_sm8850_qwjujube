__int64 __fastcall lim_cleanup(__int64 a1)
{
  _DWORD *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  int v30; // w20
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  __int64 v44; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v45[3]; // [xsp+8h] [xbp-18h] BYREF

  v2 = (_DWORD *)(a1 + 12344);
  v45[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  while ( !(unsigned int)qdf_list_remove_front(v2, &v44) )
  {
    _qdf_mem_free(v44);
    v2 = (_DWORD *)(a1 + 12344);
  }
  if ( *(_DWORD *)(a1 + 12360) )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", v3, v4, v5, v6, v7, v8, v9, v10, "qdf_list_destroy");
  qdf_mutex_destroy(a1 + 12280);
  v11 = *(_QWORD *)(a1 + 21552);
  v45[0] = 122;
  v45[1] = pe_handle_mgmt_frame;
  v20 = wlan_mgmt_txrx_deregister_rx_cb(v11, 0, (__int64)v45, 1u, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (_DWORD)v20 )
    v20 = qdf_trace_msg(
            0x35u,
            2u,
            "%s: Deregistering the PE Handle with MGMT TXRX layer has failed",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "pe_deregister_mgmt_rx_frm_callback");
  wma_de_register_mgmt_frm_client(v20);
  v29 = *(_QWORD *)(a1 + 11416);
  if ( v29 )
  {
    if ( *(_DWORD *)(a1 + 11408) )
    {
      v30 = 0;
      do
        _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(a1 + 11416) + 8LL * (unsigned __int8)v30++));
      while ( *(_DWORD *)(a1 + 11408) > (unsigned int)(unsigned __int8)v30 );
      v29 = *(_QWORD *)(a1 + 11416);
    }
    _qdf_mem_free(v29);
    *(_QWORD *)(a1 + 11416) = 0;
    *(_DWORD *)(a1 + 11408) = 0;
  }
  if ( *(_QWORD *)(a1 + 8904) )
    lim_delete_dialogue_token_list(a1);
  v31 = *(_QWORD *)(a1 + 8912);
  if ( v31 )
  {
    _qdf_mem_free(v31);
    *(_QWORD *)(a1 + 8912) = 0;
  }
  v32 = *(_QWORD *)(a1 + 11376);
  if ( v32 )
  {
    _qdf_mem_free(v32);
    *(_QWORD *)(a1 + 11376) = 0;
  }
  v33 = *(_QWORD *)(a1 + 12392);
  if ( v33 )
  {
    _qdf_mem_free(v33);
    *(_QWORD *)(a1 + 12392) = 0;
  }
  v34 = *(_QWORD *)(a1 + 12400);
  if ( v34 )
  {
    _qdf_mem_free(v34);
    *(_QWORD *)(a1 + 12400) = 0;
  }
  ((void (__fastcall *)(__int64))lim_reset_deferred_msg_q)(a1);
  rrm_cleanup(a1, 0);
  rrm_cleanup(a1, 1);
  rrm_cleanup(a1, 2);
  rrm_cleanup(a1, 3);
  rrm_cleanup(a1, 4);
  v35 = lim_ft_cleanup_all_ft_sessions(a1);
  result = wlan_scan_unregister_requester(
             *(_QWORD *)(a1 + 21552),
             *(unsigned __int16 *)(a1 + 12434),
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42);
  _ReadStatusReg(SP_EL0);
  return result;
}
