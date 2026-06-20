__int64 __fastcall ipa3_smp2p_probe(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  const char **v4; // x20
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  const char *v8; // x21
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  unsigned int v13; // w20
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0

  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    v4 = *(const char ***)(a1 + 744);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d node->name=%s\n", "ipa3_smp2p_probe", 11654, *v4);
      v1 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v1 + 34160);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d node->name=%s\n", "ipa3_smp2p_probe", 11654, *v4);
      v1 = ipa3_ctx;
    }
    if ( *(_DWORD *)(v1 + 32256) == 2 )
    {
      if ( v1 )
      {
        v6 = *(_QWORD *)(v1 + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d Ignore smp2p on APQ platform\n", "ipa3_smp2p_probe", 11656);
          v1 = ipa3_ctx;
        }
        result = *(_QWORD *)(v1 + 34160);
        if ( result )
        {
          ipc_log_string(result, "ipa %s:%d Ignore smp2p on APQ platform\n", "ipa3_smp2p_probe", 11656);
          return 0;
        }
        return result;
      }
      return 0;
    }
    v8 = *v4;
    if ( !strcmp("qcom,smp2p_map_ipa_1_out", *v4) )
    {
      result = of_find_property(v4, "qcom,smem-states", 0);
      if ( !result )
        return result;
      v9 = qcom_smem_state_get(a1, "ipa-smp2p-out", ipa3_ctx + 43732);
      v10 = ipa3_ctx;
      *(_QWORD *)(ipa3_ctx + 43736) = v9;
      if ( v9 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_3B1A6F, "ipa3_smp2p_probe");
        v25 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v26 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v26 )
          {
            ipc_log_string(
              v26,
              "ipa %s:%d fail to get smp2p clk resp bit %ld\n",
              "ipa3_smp2p_probe",
              11667,
              *(_QWORD *)(ipa3_ctx + 43736));
            v25 = ipa3_ctx;
          }
          v27 = *(_QWORD *)(v25 + 34160);
          if ( v27 )
          {
            ipc_log_string(
              v27,
              "ipa %s:%d fail to get smp2p clk resp bit %ld\n",
              "ipa3_smp2p_probe",
              11667,
              *(_QWORD *)(v25 + 43736));
            v25 = ipa3_ctx;
          }
        }
        return *(unsigned int *)(v25 + 43736);
      }
      else
      {
        if ( !v10 )
          return 0;
        v11 = *(_QWORD *)(v10 + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d smem_bit=%d\n", "ipa3_smp2p_probe", 11670, *(_DWORD *)(v10 + 43732));
          v10 = ipa3_ctx;
        }
        result = *(_QWORD *)(v10 + 34160);
        if ( result )
        {
          ipc_log_string(result, "ipa %s:%d smem_bit=%d\n", "ipa3_smp2p_probe", 11670, *(_DWORD *)(v10 + 43732));
          return 0;
        }
      }
    }
    else
    {
      if ( strcmp("qcom,smp2p_map_ipa_1_in", v8) )
        return 0;
      result = of_irq_get_byname(v4, "ipa-smp2p-in");
      v12 = ipa3_ctx;
      if ( (result & 0x80000000) != 0 )
      {
        if ( ipa3_ctx )
        {
          v22 = result;
          v23 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v23 )
          {
            ipc_log_string(v23, "ipa %s:%d of_irq_get_byname returned %d\n", "ipa3_smp2p_probe", 11675, v22);
            v12 = ipa3_ctx;
          }
          v24 = *(_QWORD *)(v12 + 34160);
          if ( v24 )
            ipc_log_string(v24, "ipa %s:%d of_irq_get_byname returned %d\n", "ipa3_smp2p_probe", 11675, v22);
          return v22;
        }
      }
      else
      {
        v13 = result;
        *(_DWORD *)(ipa3_ctx + 43724) = result;
        if ( v12 )
        {
          v14 = *(_QWORD *)(v12 + 34152);
          if ( v14 )
          {
            ipc_log_string(v14, "ipa %s:%d smp2p irq#=%d\n", "ipa3_smp2p_probe", 11680, v13);
            v12 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v12 + 34160);
          if ( v15 )
            ipc_log_string(v15, "ipa %s:%d smp2p irq#=%d\n", "ipa3_smp2p_probe", 11680, v13);
        }
        result = devm_request_threaded_irq(a1, v13, 0, ipa3_smp2p_modem_clk_query_isr, 8193, "ipa_smp2p_clk_vote", a1);
        if ( (_DWORD)result )
        {
          printk(&unk_3E5C80, "ipa3_smp2p_probe");
          v16 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v17 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v17 )
            {
              ipc_log_string(v17, "ipa %s:%d fail to register smp2p irq=%d\n", "ipa3_smp2p_probe", 11686, v13);
              v16 = ipa3_ctx;
            }
            v18 = *(_QWORD *)(v16 + 34160);
            if ( v18 )
              ipc_log_string(v18, "ipa %s:%d fail to register smp2p irq=%d\n", "ipa3_smp2p_probe", 11686, v13);
          }
          return 4294967277LL;
        }
      }
    }
  }
  else
  {
    printk(&unk_3C30BD, "ipa3_smp2p_probe");
    v19 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294966779LL;
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_smp2p_probe", 11651);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_smp2p_probe", 11651);
      return 4294966779LL;
    }
    else
    {
      return 4294966779LL;
    }
  }
  return result;
}
