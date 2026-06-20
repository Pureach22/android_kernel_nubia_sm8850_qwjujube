__int64 __fastcall ipa3_rmnet_ll_rx_poll(__int64 a1, int a2)
{
  int v2; // w19
  _DWORD *v4; // x23
  int v5; // w22
  unsigned int v6; // w26
  void (__fastcall *v7)(_DWORD *); // x9
  __int64 v8; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  void (__fastcall **v16)(_DWORD *); // [xsp+8h] [xbp-38h]
  unsigned int v18; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v2 = (unsigned int)a2 / *(_DWORD *)(ipa3_ctx + 50128);
  if ( v2 >= 65 )
  {
    printk(&unk_3F50EC, "ipa3_rmnet_ll_rx_poll");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_rmnet_ll_rx_poll", 7568);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d NAPI weight is higher than expected\n", "ipa3_rmnet_ll_rx_poll", 7568);
    }
    printk(&unk_3A9B7A, "ipa3_rmnet_ll_rx_poll");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d expected %d got %d\n", "ipa3_rmnet_ll_rx_poll", 7570, 64, v2);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d expected %d got %d\n", "ipa3_rmnet_ll_rx_poll", 7570, 64, v2);
    }
    v5 = -22;
  }
  else
  {
    v4 = (_DWORD *)(a1 - 1152);
    ++*(_DWORD *)(a1 + 464);
    v5 = 0;
    _ReadStatusReg(SP_EL0);
    v16 = (void (__fastcall **)(_DWORD *))(a1 - 792);
    while ( 1 )
    {
      ipa_pm_activate(*(unsigned int *)(a1 + 624));
      while ( v2 >= 1 )
      {
        if ( !*(_DWORD *)(a1 - 1148) )
          break;
        *(_DWORD *)(ipa3_ctx + 31972) = 1;
        if ( (unsigned int)ipa_poll_gsi_n_pkt(v4, &ipa3_rmnet_ll_rx_poll_notify, (unsigned int)v2, &v18) )
          break;
        v6 = v18;
        ipa3_rx_napi_chain(v4, &ipa3_rmnet_ll_rx_poll_notify, v18);
        v2 -= v6;
        if ( !*v4 )
        {
          v5 = (__PAIR64__(v5, v2) - 1) >> 32;
          break;
        }
      }
      v7 = *v16;
      v5 += a2 - *(_DWORD *)(ipa3_ctx + 50128) * v2;
      if ( *((_DWORD *)*v16 - 1) != 1136933575 )
        __break(0x8229u);
      v7(v4);
      queue_delayed_work_on(32, *(_QWORD *)(ipa3_ctx + 51448), &ipa3_collect_low_lat_data_recycle_stats_wq_work, 3);
      if ( v5 >= a2 || *v4 < 0x21u )
        break;
      napi_complete_done(a1, 0);
      if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *))ipa3_rx_switch_to_intr_mode)(v4) != -13
        || (napi_schedule_prep(a1) & 1) == 0 )
      {
        ipa3_dec_client_disable_clks_no_block();
        goto LABEL_21;
      }
      _napi_schedule(a1);
    }
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d Client = %d not replenished free descripotrs\n",
          "ipa3_rmnet_ll_rx_poll",
          7627,
          *(_DWORD *)(*(_QWORD *)(a1 + 472) + 4LL));
    }
    v5 = a2;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
