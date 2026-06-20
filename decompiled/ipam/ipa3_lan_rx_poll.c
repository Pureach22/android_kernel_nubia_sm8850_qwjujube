__int64 __fastcall ipa3_lan_rx_poll(__int64 a1, int a2)
{
  __int64 v2; // x25
  __int64 v3; // x25
  int v4; // t1
  int v5; // w26
  int v6; // w20
  __int64 v7; // x28
  unsigned __int64 v8; // x21
  char *v9; // x27
  unsigned int v10; // w8
  void (*v11)(void); // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x27
  __int64 v16; // x8
  const char *v17; // x8
  int v19; // w19
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  _QWORD v30[3]; // [xsp+8h] [xbp-28h] BYREF
  int v31; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)a1 )
    goto LABEL_47;
  if ( (unsigned int)a1 >= 0x24 )
  {
LABEL_46:
    __break(0x5512u);
    goto LABEL_47;
  }
  v2 = ipa3_ctx + 480LL * (unsigned int)a1;
  v4 = *(_DWORD *)(v2 + 168);
  v3 = v2 + 168;
  if ( !v4 )
  {
LABEL_47:
    v19 = a1;
    printk(&unk_3D573B, "ipa3_lan_rx_poll");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d bad param 0x%x\n", "ipa3_lan_rx_poll", 7224, v19);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d bad param 0x%x\n", "ipa3_lan_rx_poll", 7224, v19);
        v6 = 0;
        goto LABEL_45;
      }
    }
LABEL_62:
    v6 = 0;
    goto LABEL_45;
  }
  v5 = a2;
  if ( a2 > 64 )
  {
    printk(&unk_3F50EC, "ipa3_lan_rx_poll");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_lan_rx_poll", 7229);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
        ipc_log_string(v25, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_lan_rx_poll", 7229);
    }
    printk(&unk_3A9B7A, "ipa3_lan_rx_poll");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d expected %d got %d\n", "ipa3_lan_rx_poll", 7231, 64, a2);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d expected %d got %d\n", "ipa3_lan_rx_poll", 7231, 64, a2);
    }
    goto LABEL_62;
  }
  v6 = 0;
  while ( 1 )
  {
    ipa_pm_activate(*(unsigned int *)(*(_QWORD *)(v3 + 472) + 1776LL));
    do
    {
      if ( v5 < 1 )
        goto LABEL_37;
      if ( !*(_DWORD *)(*(_QWORD *)(v3 + 472) + 4LL) )
        goto LABEL_37;
      *(_DWORD *)(ipa3_ctx + 31972) = 1;
      LODWORD(a1) = ipa_poll_gsi_n_pkt(*(_QWORD *)(v3 + 472), &g_lan_rx_notify, (unsigned int)v5, &v31);
      if ( (_DWORD)a1 )
        goto LABEL_37;
      v7 = (unsigned int)v31;
      if ( v31 >= 1 )
      {
        v8 = 0;
        v9 = (char *)&g_lan_rx_notify;
        do
        {
          v10 = *(_DWORD *)(v3 + 4);
          if ( v10 <= 0x2F )
          {
            if ( ((1LL << v10) & 0x2A800) != 0 )
              goto LABEL_18;
            if ( ((1LL << v10) & 0xA00000000000LL) != 0 )
            {
              LODWORD(a1) = ipa3_dma_memcpy_notify(*(_QWORD *)(v3 + 472));
              goto LABEL_15;
            }
          }
          if ( v10 == 119 )
          {
LABEL_18:
            if ( v8 > 0x40 )
              goto LABEL_46;
            LODWORD(a1) = ipa3_wlan_wq_rx_common(*(_QWORD *)(v3 + 472), v9);
            goto LABEL_15;
          }
          if ( v8 > 0x40 )
            goto LABEL_46;
          v30[0] = 0;
          if ( v9 )
          {
            a1 = handle_skb_completion(v9, 1, v30);
            if ( a1 )
            {
              v11 = *(void (**)(void))(*(_QWORD *)(v30[0] + 80LL) + 128LL);
              if ( *((_DWORD *)v11 - 1) != 2117430862 )
                __break(0x8228u);
              v11();
              v12 = *(__int64 (**)(void))(*(_QWORD *)(v30[0] + 80LL) + 360LL);
              if ( *((_DWORD *)v12 - 1) != 1136933575 )
                __break(0x8228u);
              LODWORD(a1) = v12();
            }
          }
          else
          {
            LODWORD(a1) = __ratelimit(&ipa3_wq_rx_common__rs, "ipa3_wq_rx_common");
            if ( (_DWORD)a1 )
              LODWORD(a1) = printk(&unk_3C6D67, "ipa3_wq_rx_common");
            v13 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v14 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v14 )
              {
                ipc_log_string(v14, "ipa %s:%d gsi_chan_xfer_notify is null\n", "ipa3_wq_rx_common", 5593);
                v13 = ipa3_ctx;
              }
              a1 = *(_QWORD *)(v13 + 34160);
              if ( a1 )
                LODWORD(a1) = ipc_log_string(a1, "ipa %s:%d gsi_chan_xfer_notify is null\n", "ipa3_wq_rx_common", 5593);
            }
          }
LABEL_15:
          ++v8;
          v9 += 24;
        }
        while ( v7 != v8 );
      }
      v5 -= v7;
    }
    while ( **(_DWORD **)(v3 + 472) );
    v6 = (__PAIR64__(v6, v5) - 1) >> 32;
LABEL_37:
    v6 += a2 - v5;
    if ( v6 >= a2 )
      goto LABEL_45;
    napi_complete_done(*(_QWORD *)(*(_QWORD *)(v3 + 472) + 384LL), 0);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_rx_switch_to_intr_mode)(*(_QWORD *)(v3 + 472)) != -13 )
      break;
    v15 = *(_QWORD *)(*(_QWORD *)(v3 + 472) + 384LL);
    if ( (napi_schedule_prep(v15) & 1) == 0 )
      break;
    _napi_schedule(v15);
  }
  v30[1] = "ipa_dp.c";
  v30[2] = 7279;
  v16 = *(unsigned int *)(v3 + 4);
  if ( (unsigned int)v16 <= 0x85 )
    v17 = ipa_clients_strings[v16];
  else
    v17 = "Invalid Client";
  v30[0] = v17;
  ipa3_dec_client_disable_clks_no_block();
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
