__int64 __fastcall ipa3_rx_poll(unsigned int a1, int a2)
{
  unsigned int ep_mapping; // w0
  __int64 v5; // x22
  __int64 v6; // x8
  int v7; // w21
  int v8; // w20
  __int64 v9; // x9
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w2
  unsigned int v14; // w25
  void (__fastcall *v15)(_QWORD); // x9
  void (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x8
  __int64 v18; // x25
  __int64 v19; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  unsigned int v34; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    goto LABEL_34;
  if ( a1 >= 0x24 )
    goto LABEL_56;
  if ( !*(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
LABEL_34:
    printk(&unk_3CC727, "ipa3_rx_poll");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d bad parm 0x%x\n", "ipa3_rx_poll", 7310, a1);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d bad parm 0x%x\n", "ipa3_rx_poll", 7310, a1);
        v8 = 0;
        goto LABEL_33;
      }
    }
LABEL_44:
    v8 = 0;
    goto LABEL_33;
  }
  ep_mapping = ipa_get_ep_mapping(35);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3AC96C, "ipa3_rx_poll");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d Invalid client.\n", "ipa3_rx_poll", 7318);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d Invalid client.\n", "ipa3_rx_poll", 7318);
        v8 = 0;
        goto LABEL_33;
      }
    }
    goto LABEL_44;
  }
  v5 = ipa3_ctx + 480LL * a1;
  if ( ep_mapping > 0x23 )
LABEL_56:
    __break(0x5512u);
  v6 = ipa3_ctx;
  v7 = (unsigned int)a2 / *(_DWORD *)(ipa3_ctx + 50128);
  if ( v7 >= 65 )
  {
    printk(&unk_3F50EC, "ipa3_rx_poll");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_rx_poll", 7328);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(v30, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_rx_poll", 7328);
    }
    printk(&unk_3A9B7A, "ipa3_rx_poll");
    v31 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_55;
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(v32, "ipa %s:%d expected %d got %d\n", "ipa3_rx_poll", 7330, 64, v7);
      v31 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v31 + 34160);
    if ( v33 )
    {
      ipc_log_string(v33, "ipa %s:%d expected %d got %d\n", "ipa3_rx_poll", 7330, 64, v7);
      v8 = -22;
    }
    else
    {
LABEL_55:
      v8 = -22;
    }
  }
  else
  {
    v8 = 0;
    v9 = *(_QWORD *)(*(_QWORD *)(v5 + 640) + 1944LL);
    _ReadStatusReg(SP_EL0);
    v10 = *(_QWORD *)(v6 + 480LL * ep_mapping + 640);
    ++*(_DWORD *)(v9 + 1616);
    while ( 1 )
    {
      ipa_pm_activate(*(unsigned int *)(*(_QWORD *)(v5 + 640) + 1776LL));
      v11 = *(_QWORD *)(v5 + 640);
      while ( v7 >= 1 && *(_DWORD *)(v11 + 4) )
      {
        v12 = ipa3_ctx + 31972;
        *(_DWORD *)(ipa3_ctx + 31972) = 1;
        if ( *(_DWORD *)(v12 + 2268) )
          v13 = v7;
        else
          v13 = 1;
        if ( (unsigned int)ipa_poll_gsi_n_pkt(*(_QWORD *)(v5 + 640), ipa3_rx_poll_notify, v13, (int *)&v34) )
        {
          v11 = *(_QWORD *)(v5 + 640);
          break;
        }
        v14 = v34;
        ipa3_rx_napi_chain(*(_QWORD *)(v5 + 640), ipa3_rx_poll_notify, v34);
        v11 = *(_QWORD *)(v5 + 640);
        v7 -= v14;
        if ( !*(_DWORD *)v11 )
        {
          v8 = (__PAIR64__(v8, v7) - 1) >> 32;
          break;
        }
      }
      v15 = *(void (__fastcall **)(_QWORD))(v11 + 360);
      v8 += a2 - *(_DWORD *)(ipa3_ctx + 50128) * v7;
      if ( *((_DWORD *)v15 - 1) != 1136933575 )
        __break(0x8229u);
      v15(v11);
      v16 = *(void (__fastcall **)(_QWORD))(v10 + 360);
      if ( *((_DWORD *)v16 - 1) != 1136933575 )
        __break(0x8228u);
      v16(v10);
      queue_delayed_work_on(32, *(_QWORD *)(ipa3_ctx + 51448), &ipa3_collect_default_coal_recycle_stats_wq_work, 3);
      if ( v8 >= a2 )
        break;
      v17 = *(_QWORD *)(v5 + 640);
      if ( *(_DWORD *)v17 < 0x21u || *(_DWORD *)v10 < 0x21u )
        break;
      napi_complete_done(*(_QWORD *)(v17 + 384), 0);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_rx_switch_to_intr_mode)(*(_QWORD *)(v5 + 640)) != -13
        || (v18 = *(_QWORD *)(*(_QWORD *)(v5 + 640) + 384LL), (napi_schedule_prep(v18) & 1) == 0) )
      {
        ipa3_dec_client_disable_clks_no_block();
        goto LABEL_33;
      }
      _napi_schedule(v18);
    }
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v19 )
        ipc_log_string(
          v19,
          "ipa %s:%d Client = %d not replenished free descripotrs\n",
          "ipa3_rx_poll",
          7392,
          *(_DWORD *)(v5 + 172));
    }
    v8 = a2;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v8;
}
