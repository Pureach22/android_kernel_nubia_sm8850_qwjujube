__int64 __fastcall ipa3_suspend_active_aggr_wa(unsigned int a1)
{
  __int64 reg_n; // x0
  __int64 result; // x0
  unsigned int v4; // w19
  __int64 ep_bit; // x3
  __int64 v6; // x24
  __int64 v7; // x23
  __int64 v8; // x19
  int v9; // w21
  unsigned int ep_reg_idx; // w0
  __int64 v11; // x2
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v16; // x25
  __int64 (__fastcall *v17)(_QWORD); // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0

  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
    reg_n = ipahal_read_reg_n(29, 0);
  else
    reg_n = ipahal_read_ep_reg(132, a1);
  result = ipahal_test_ep_bit(reg_n, a1);
  if ( (result & 1) != 0 )
  {
    v4 = *(_DWORD *)(ipa3_ctx + 32240);
    ep_bit = (unsigned int)ipahal_get_ep_bit(a1);
    if ( v4 < 0x15 )
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(44, 0, 0, ep_bit);
    else
      ipahal_write_ep_reg(133, a1, (unsigned int)ep_bit);
    v6 = qword_200450;
    if ( qword_200450 )
    {
      v7 = qword_200460;
      v8 = _kmalloc_cache_noprof(sg_next, 2336, 8);
      if ( v8 )
      {
        while ( 1 )
        {
          v9 = ipahal_get_ep_bit(a1);
          ep_reg_idx = ipahal_get_ep_reg_idx(a1);
          if ( ep_reg_idx <= 1 )
            break;
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v16 = *(_QWORD *)(StatusReg + 80);
          v17 = sg_next;
          *(_QWORD *)(StatusReg + 80) = &ipa3_suspend_active_aggr_wa__alloc_tag;
          v8 = _kmalloc_cache_noprof(v17, 2336, 8);
          *(_QWORD *)(StatusReg + 80) = v16;
          if ( !v8 )
            goto LABEL_20;
        }
        *(_DWORD *)(v8 + 4LL * ep_reg_idx) = v9;
        v11 = _kmalloc_cache_noprof(ipc_log_string, 2336, 64);
        if ( v11 )
        {
          *(_QWORD *)v11 = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v11 + 8) = v11 + 8;
          *(_QWORD *)(v11 + 16) = v11 + 8;
          *(_QWORD *)(v11 + 24) = ipa3_deferred_interrupt_work;
          *(_QWORD *)(v11 + 32) = v6;
          *(_DWORD *)(v11 + 40) = 13;
          v12 = ipa_interrupt_wq;
          *(_QWORD *)(v11 + 48) = v7;
          *(_QWORD *)(v11 + 56) = v8;
          return queue_work_on(32, v12, v11);
        }
        else
        {
          printk(&unk_3DB878, "ipa3_suspend_active_aggr_wa");
          v20 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v21 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v21 )
            {
              ipc_log_string(
                v21,
                "ipa %s:%d failed allocating ipa3_interrupt_work_wrap\n",
                "ipa3_suspend_active_aggr_wa",
                730);
              v20 = ipa3_ctx;
            }
            v22 = *(_QWORD *)(v20 + 34160);
            if ( v22 )
              ipc_log_string(
                v22,
                "ipa %s:%d failed allocating ipa3_interrupt_work_wrap\n",
                "ipa3_suspend_active_aggr_wa",
                730);
          }
          return kfree(v8);
        }
      }
      else
      {
LABEL_20:
        result = printk(&unk_3D5B42, "ipa3_suspend_active_aggr_wa");
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v19 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v19 )
          {
            ipc_log_string(
              v19,
              "ipa %s:%d failed allocating suspend_interrupt_data\n",
              "ipa3_suspend_active_aggr_wa",
              719);
            v18 = ipa3_ctx;
          }
          result = *(_QWORD *)(v18 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d failed allocating suspend_interrupt_data\n",
                     "ipa3_suspend_active_aggr_wa",
                     719);
        }
      }
    }
    else
    {
      result = printk(&unk_3ACE5B, "ipa3_suspend_active_aggr_wa");
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d no CB function for IPA_TX_SUSPEND_IRQ\n", "ipa3_suspend_active_aggr_wa", 712);
          v13 = ipa3_ctx;
        }
        result = *(_QWORD *)(v13 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d no CB function for IPA_TX_SUSPEND_IRQ\n",
                   "ipa3_suspend_active_aggr_wa",
                   712);
      }
    }
  }
  return result;
}
