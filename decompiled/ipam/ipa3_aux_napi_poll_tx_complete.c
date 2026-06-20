__int64 __fastcall ipa3_aux_napi_poll_tx_complete(__int64 a1, int a2)
{
  __int64 v3; // x22
  int v4; // w0
  int v5; // w26
  int v6; // w25
  unsigned __int64 v7; // x27
  __int64 v8; // x20
  __int64 v9; // x0
  int v10; // w21
  _DWORD *v11; // x22
  int v12; // w8
  __int64 v13; // x0
  unsigned int ep_mapping; // w0
  __int64 v15; // x8
  int v16; // w0
  int v17; // w8
  __int64 v18; // x0
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x8
  const char *v23; // x8
  __int64 v24; // x0
  int v26; // w19
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x8
  int v31; // [xsp+8h] [xbp-618h]
  int v32; // [xsp+Ch] [xbp-614h] BYREF
  _QWORD s[194]; // [xsp+10h] [xbp-610h] BYREF

  v3 = a1 - 720;
  s[192] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  memset(s, 0, 0x600u);
  v31 = a2;
  do
  {
    v4 = ipa_poll_gsi_n_pkt(v3, s, (unsigned int)a2, &v32);
    v5 = v32;
    v6 = v4;
    if ( v32 >= 1 )
    {
      v7 = 0;
      v8 = 24LL * (unsigned int)v32;
      while ( v7 != 1536 )
      {
        if ( v7 - 1528 < 0xFFFFFFFFFFFFFA00LL )
          goto LABEL_63;
        v3 = *(_QWORD *)(s[v7 / 8 + 1] + 72LL);
        ipa3_write_done_common(v3);
        v7 += 24LL;
        --a2;
        if ( v8 == v7 )
          goto LABEL_7;
      }
      goto LABEL_62;
    }
LABEL_7:
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d Number of desc polled %d", "ipa3_napi_poll_tx_complete", 449, v5);
    }
  }
  while ( !v6 && a2 > 0 );
  v10 = v31 - a2;
  gsi_ring_evt_doorbell_polling_mode(*(_QWORD *)(*(_QWORD *)(a1 + 904) + 8LL));
  if ( v10 >= v31 )
    goto LABEL_50;
  napi_complete_done(a1, 0);
  v11 = (_DWORD *)(a1 - 716);
  *(_DWORD *)(a1 - 716) = 0;
  v12 = *(_DWORD *)(*(_QWORD *)(a1 + 904) + 4LL);
  if ( v12 > 94 )
  {
    if ( v12 == 95 )
    {
      v13 = 35;
    }
    else
    {
      if ( v12 != 127 )
        goto LABEL_26;
      v13 = 33;
    }
LABEL_22:
    ep_mapping = ipa_get_ep_mapping(v13);
    if ( ep_mapping == -1 )
      goto LABEL_26;
    if ( ep_mapping < 0x24 )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 480LL * ep_mapping + 640);
      if ( v15 )
        *(_DWORD *)(v15 + 4) = 0;
      goto LABEL_26;
    }
    goto LABEL_62;
  }
  if ( v12 == 33 )
  {
    v13 = 127;
    goto LABEL_22;
  }
  if ( v12 == 35 )
  {
    v13 = 95;
    goto LABEL_22;
  }
LABEL_26:
  v16 = gsi_config_channel_mode(*(_QWORD *)(*(_QWORD *)(a1 + 904) + 8LL), 0);
  if ( !v16 )
    goto LABEL_46;
  if ( *v11 )
    goto LABEL_28;
  if ( v16 != -13 )
  {
    v26 = v16;
    printk(&unk_3B4D85, "ipa3_tx_switch_to_intr_mode");
    v16 = v26;
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d Failed to switch to intr mode %d ch_id %lu\n",
          "ipa3_tx_switch_to_intr_mode",
          1166,
          *v11,
          *(_QWORD *)(*(_QWORD *)(a1 + 904) + 8LL));
        v16 = v26;
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d Failed to switch to intr mode %d ch_id %lu\n",
          "ipa3_tx_switch_to_intr_mode",
          1166,
          *v11,
          *(_QWORD *)(*(_QWORD *)(a1 + 904) + 8LL));
        v16 = v26;
      }
    }
LABEL_28:
    if ( v16 == -13 )
      goto LABEL_44;
    goto LABEL_46;
  }
  *v11 = 1;
  v17 = *(_DWORD *)(*(_QWORD *)(a1 + 904) + 4LL);
  if ( v17 > 94 )
  {
    if ( v17 == 95 )
    {
      v18 = 35;
    }
    else
    {
      if ( v17 != 127 )
        goto LABEL_44;
      v18 = 33;
    }
LABEL_40:
    v19 = ipa_get_ep_mapping(v18);
    if ( v19 == -1 )
      goto LABEL_44;
    if ( v19 < 0x24 )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 480LL * v19 + 640);
      if ( v20 )
        *(_DWORD *)(v20 + 4) = 1;
      goto LABEL_44;
    }
LABEL_62:
    __break(0x5512u);
LABEL_63:
    __break(1u);
  }
  if ( v17 == 33 )
  {
    v18 = 127;
    goto LABEL_40;
  }
  if ( v17 == 35 )
  {
    v18 = 95;
    goto LABEL_40;
  }
LABEL_44:
  if ( (napi_schedule_prep(a1) & 1) != 0 )
  {
    _napi_schedule(a1);
    goto LABEL_50;
  }
LABEL_46:
  v21 = *(_QWORD *)(a1 + 904);
  s[1] = "ipa_dp.c";
  s[2] = 486;
  v22 = *(unsigned int *)(v21 + 4);
  if ( (unsigned int)v22 <= 0x85 )
    v23 = ipa_clients_strings[v22];
  else
    v23 = "Invalid Client";
  s[0] = v23;
  ipa3_dec_client_disable_clks_no_block();
LABEL_50:
  if ( ipa3_ctx )
  {
    v24 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v24 )
      ipc_log_string(v24, "ipa %s:%d the number of tx completions is: %d", "ipa3_aux_napi_poll_tx_complete", 488, v10);
  }
  _ReadStatusReg(SP_EL0);
  if ( v10 >= v31 )
    return (unsigned int)v31;
  else
    return (unsigned int)v10;
}
