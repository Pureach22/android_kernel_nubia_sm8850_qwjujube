__int64 __fastcall ipa_flt_sram_set_client_prio_high(unsigned int a1)
{
  __int64 ep_mapping; // x0
  unsigned int v3; // w19
  __int64 *v4; // x1
  __int64 *v5; // x9
  unsigned int v6; // w10
  __int64 *v7; // x8
  __int64 v8; // x13
  __int64 **v9; // x11
  __int64 v10; // x2
  __int64 *v11; // x8
  __int64 v12; // x10
  __int64 v13; // x12
  __int64 *v14; // x9
  __int64 **v15; // x10
  __int64 v16; // x2
  __int64 *v17; // x1
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0

  if ( (unsigned int)ipa_get_ep_mapping(48) != a1
    && (unsigned int)ipa_get_ep_mapping(116) != a1
    && (unsigned int)ipa_get_ep_mapping(102) != a1
    && (unsigned int)ipa_get_ep_mapping(108) != a1 )
  {
    printk(&unk_3A37A8, "ipa_flt_sram_set_client_prio_high");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d Operation not permitted for non ETH clients\n",
          "ipa_flt_sram_set_client_prio_high",
          2308);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(
          v21,
          "ipa %s:%d Operation not permitted for non ETH clients\n",
          "ipa_flt_sram_set_client_prio_high",
          2308);
    }
    return 4294967274LL;
  }
  ep_mapping = ipa_get_ep_mapping(a1);
  if ( (_DWORD)ep_mapping == -1 )
    return 4294967274LL;
  v3 = ep_mapping;
  if ( (ipa_is_ep_support_flt(ep_mapping) & 1) == 0 )
    return 4294967274LL;
  mutex_lock(ipa3_ctx + 29472);
  if ( v3 > 0x23 )
  {
    __break(0x5512u);
LABEL_39:
    _list_add_valid_or_report(v5, v4);
  }
  else
  {
    v6 = v3;
    v7 = *(__int64 **)(ipa3_ctx + 30472);
    while ( v7 != (__int64 *)(ipa3_ctx + 30472) )
    {
      v8 = v7[2];
      v5 = v7;
      v7 = (__int64 *)*v7;
      if ( v8 == ipa3_ctx + 304LL * v3 + 17640 )
      {
        v9 = (__int64 **)v5[1];
        if ( *v9 == v5 && (__int64 *)v7[1] == v5 )
        {
          v7[1] = (__int64)v9;
          *v9 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        v10 = ipa3_ctx + 30472;
        v4 = *(__int64 **)(ipa3_ctx + 30480);
        if ( v5 != (__int64 *)(ipa3_ctx + 30472) && v4 != v5 && *v4 == v10 )
        {
          *(_QWORD *)(ipa3_ctx + 30480) = v5;
          *v5 = v10;
          v5[1] = (__int64)v4;
          *v4 = (__int64)v5;
          break;
        }
        goto LABEL_39;
      }
    }
  }
  v11 = *(__int64 **)(ipa3_ctx + 30488);
  v12 = ipa3_ctx + 304LL * v6 + 17792;
  while ( v11 != (__int64 *)(ipa3_ctx + 30488) )
  {
    v13 = v11[2];
    v14 = v11;
    v11 = (__int64 *)*v11;
    if ( v13 == v12 )
    {
      v15 = (__int64 **)v14[1];
      if ( *v15 == v14 && (__int64 *)v11[1] == v14 )
      {
        v11[1] = (__int64)v15;
        *v15 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v14);
      }
      *v14 = 0xDEAD000000000100LL;
      v14[1] = 0xDEAD000000000122LL;
      v16 = ipa3_ctx + 30488;
      v17 = *(__int64 **)(ipa3_ctx + 30496);
      if ( v14 == (__int64 *)(ipa3_ctx + 30488) || v17 == v14 || *v17 != v16 )
      {
        _list_add_valid_or_report(v14, v17);
      }
      else
      {
        *(_QWORD *)(ipa3_ctx + 30496) = v14;
        *v14 = v16;
        v14[1] = (__int64)v17;
        *v17 = (__int64)v14;
      }
      break;
    }
  }
  mutex_unlock(ipa3_ctx + 29472);
  return 0;
}
