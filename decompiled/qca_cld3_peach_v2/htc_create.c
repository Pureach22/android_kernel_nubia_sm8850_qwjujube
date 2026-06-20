_QWORD *__fastcall htc_create(const void *a1, __int64 *a2, __int64 a3, int a4)
{
  _QWORD *v8; // x0
  _QWORD *v9; // x19
  __int64 v10; // x8
  int v11; // w9
  int v12; // w8
  __int64 v13; // x9
  _QWORD *v14; // x11
  int v15; // w12
  int v16; // w23
  __int64 v17; // x0
  _QWORD *v19; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v20)(); // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v21)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v22)(); // [xsp+20h] [xbp-20h]
  __int64 (__fastcall *v23)(); // [xsp+28h] [xbp-18h]
  __int64 (__fastcall *v24)(); // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = nullptr;
  v24 = nullptr;
  v21 = nullptr;
  v22 = nullptr;
  v19 = nullptr;
  v20 = nullptr;
  if ( a1 )
  {
    qdf_trace_msg(62, 8, "+htc_create ..  HIF :%pK", a1);
    v8 = (_QWORD *)_qdf_mem_malloc(3584, "htc_create", 446);
    v9 = v8;
    if ( v8 )
    {
      v8[443] = v8;
      v8[442] = htc_kick_queues;
      v8[438] = 0xFFFFFFFE00000LL;
      v8[439] = v8 + 439;
      v8[440] = v8 + 439;
      v8[441] = _qdf_defer_func;
      htc_credit_history_init();
      *((_DWORD *)v9 + 740) = 0;
      v9[371] = 0;
      *((_DWORD *)v9 + 744) = 0;
      v9[373] = 0;
      *((_DWORD *)v9 + 748) = 0;
      v9[375] = 0;
      *((_DWORD *)v9 + 78) = 0;
      v9[40] = 0;
      *((_DWORD *)v9 + 160) = 0;
      v9[81] = 0;
      *((_DWORD *)v9 + 242) = 0;
      v9[122] = 0;
      *((_DWORD *)v9 + 324) = 0;
      v9[163] = 0;
      *((_DWORD *)v9 + 406) = 0;
      v9[204] = 0;
      *((_DWORD *)v9 + 488) = 0;
      v9[245] = 0;
      *((_DWORD *)v9 + 570) = 0;
      v9[286] = 0;
      *((_DWORD *)v9 + 652) = 0;
      v9[327] = 0;
      *((_DWORD *)v9 + 734) = 0;
      v9[368] = 0;
      *((_BYTE *)v9 + 3560) = 0;
      *(_WORD *)((char *)v9 + 3561) = 1;
      qdf_mem_copy((_DWORD)v9 + 3024, (int)a2, 0x30u);
      v10 = *a2;
      v11 = *((_DWORD *)v9 + 767);
      v9[432] = a3;
      *((_DWORD *)v9 + 889) = a4;
      v9[377] = v10;
      if ( !v11 )
        *((_DWORD *)v9 + 767) = 6000;
      v12 = 0;
      v13 = 0;
      do
      {
        v14 = &v9[v13];
        v13 += 41;
        *((_WORD *)v14 + 6) = 0;
        v14[14] = v14 + 14;
        v14[15] = v14 + 14;
        v14[29] = v14 + 29;
        v14[30] = v14 + 29;
        v14[17] = 0;
        *((_DWORD *)v14 + 2) = v12++;
        *((_DWORD *)v14 + 32) = 0;
        *((_DWORD *)v14 + 62) = 0;
        v14[32] = v14 + 32;
        v14[33] = v14 + 32;
        *((_DWORD *)v14 + 68) = 0;
        v14[36] = v9;
        v15 = htc_credit_flow;
        v14[41] = 0;
        *((_BYTE *)v14 + 308) = v15 != 0;
        *((_DWORD *)v14 + 71) = 0;
      }
      while ( v13 != 369 );
      v16 = 32;
      v9[385] = v9 + 385;
      v9[386] = v9 + 385;
      *((_DWORD *)v9 + 774) = 0;
      do
      {
        v17 = _qdf_mem_malloc(112, "htc_create", 484);
        if ( v17 )
          free_htc_packet_container(v9, v17);
        --v16;
      }
      while ( v16 );
      qdf_mem_set((int)&v19, 0x30u, 0);
      v19 = v9;
      v20 = htc_tx_completion_handler;
      v21 = htc_rx_completion_handler;
      v22 = htc_tx_resource_avail_handler;
      v23 = htc_fw_event_handler;
      v24 = htc_update_rx_bundle_stats;
      *v9 = a1;
      hif_post_init((int)a1, (int)v9, (int)&v19);
      hif_get_default_pipe(*v9, (_BYTE *)v9 + 144, (_BYTE *)v9 + 145);
      hif_set_initial_wakeup_cb(*v9, a2[3], a2[4]);
      htc_recv_init(v9);
      *((_DWORD *)v9 + 891) = 0;
      *((_DWORD *)v9 + 892) = 0;
      qdf_trace_msg(62, 8, "-htc_create: (0x%pK)", v9);
      htc_hang_event_notifier_register(v9);
      htc_link_vote_ids[0] = 0;
      dword_7CF260 = 0;
      dword_7CF264 = 0;
      dword_7CF268 = 0;
      dword_7CF26C = 0;
      dword_7CF270 = 0;
      dword_7CF274 = 0;
      hif_rtpm_register(2u, 0);
      hif_rtpm_register(3u, 0);
    }
  }
  else
  {
    qdf_trace_msg(62, 2, "%s: ol_sc = NULL", "htc_create");
    v9 = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
