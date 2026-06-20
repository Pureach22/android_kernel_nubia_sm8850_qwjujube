__int64 __fastcall ipa_opt_log_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x23
  int v7; // w24
  unsigned __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x0
  _QWORD *v11; // x25
  _QWORD *v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x24
  unsigned __int64 v15; // x26
  __int64 v16; // x27
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x8
  unsigned int v31; // w9
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  int v35; // w8
  _QWORD v37[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v38[3]; // [xsp+18h] [xbp-18h] BYREF

  v38[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[2] = &woken_wake_function;
  v38[0] = v38;
  StatusReg = _ReadStatusReg(SP_EL0);
  v38[1] = v38[0];
  v37[0] = 0;
  v37[1] = StatusReg;
  add_wait_queue(ipa3_opt_log_ctx + 296, v37);
  v7 = 0;
  v8 = a2;
  v9 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_4;
LABEL_2:
  v10 = *(_QWORD *)(v9 + 34160);
  if ( v10 )
    ipc_log_string(v10, "ipa %s:%d Writing message to opt log\n", "ipa_opt_log_read", 144);
LABEL_4:
  while ( (*(_BYTE *)(ipa3_opt_log_ctx + 272) & 2) != 0 )
  {
    mutex_lock(ipa3_opt_log_ctx + 176);
    v11 = *(_QWORD **)(ipa3_opt_log_ctx + 160);
    if ( v11 == (_QWORD *)(ipa3_opt_log_ctx + 160) )
    {
      mutex_unlock(ipa3_opt_log_ctx + 176);
      if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
        goto LABEL_42;
    }
    else
    {
      v12 = (_QWORD *)v11[1];
      if ( (_QWORD *)*v12 == v11 && (v13 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
      {
        *(_QWORD *)(v13 + 8) = v12;
        *v12 = v13;
      }
      else
      {
        _list_del_entry_valid_or_report(v11);
      }
      *v11 = 0xDEAD000000000100LL;
      v11[1] = 0xDEAD000000000122LL;
      if ( *(_DWORD *)(ipa3_opt_log_ctx + 288) )
      {
        _X8 = (unsigned int *)(ipa3_opt_log_ctx + 288);
        __asm { PRFM            #0x11, [X8] }
        do
          v31 = __ldxr(_X8);
        while ( __stxr(v31 - 1, _X8) );
      }
      v14 = v11 - 2;
      mutex_unlock(ipa3_opt_log_ctx + 176);
      if ( v11 != &qword_10 )
      {
        v15 = *((int *)v11 - 2);
        if ( a3 < v15 )
        {
          printk(&unk_3FB600, "ipa_opt_log_read");
          v32 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v33 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v33 )
            {
              ipc_log_string(v33, "ipa %s:%d Message length greater than count\n", "ipa_opt_log_read", 162);
              v32 = ipa3_ctx;
            }
            v34 = *(_QWORD *)(v32 + 34160);
            if ( v34 )
              ipc_log_string(v34, "ipa %s:%d Message length greater than count\n", "ipa_opt_log_read", 162);
          }
          goto LABEL_41;
        }
        v16 = *v14;
        if ( *v14 )
        {
          if ( (v15 & 0x80000000) != 0 )
          {
            __break(0x800u);
LABEL_41:
            kfree(*v14);
            kfree(v11 - 2);
LABEL_42:
            v7 = -11;
            break;
          }
          _check_object_size(*v14, *((int *)v11 - 2), 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v17 = v8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v17 = v8 & ((__int64)(v8 << 8) >> 8);
          if ( 0x8000000000LL - v15 >= v17 )
          {
            v18 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v24 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v24);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v18);
            v15 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, v16, v15);
            v25 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v27 - 4096);
            _WriteStatusReg(TTBR1_EL1, v27);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v25);
          }
          if ( v15 )
            goto LABEL_41;
          v28 = *((int *)v11 - 2);
          v8 += v28;
          a3 -= v28;
          kfree(*(v11 - 2));
        }
        ++*(_DWORD *)(ipa3_opt_log_ctx + 280);
        kfree(v11 - 2);
      }
      if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
        goto LABEL_42;
    }
    if ( (*(_QWORD *)StatusReg & 0x40) != 0 )
    {
      v7 = -4;
      break;
    }
    v7 = -4;
    if ( (*(_QWORD *)StatusReg & 1) != 0 || v8 != a2 )
      break;
    wait_woken(v37, 1, 0x7FFFFFFFFFFFFFFFLL);
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_2;
  }
  remove_wait_queue(ipa3_opt_log_ctx + 296, v37);
  v35 = v8 - a2;
  _ReadStatusReg(SP_EL0);
  if ( v8 == a2 )
    return v7;
  return v35;
}
