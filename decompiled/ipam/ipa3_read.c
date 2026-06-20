__int64 __fastcall ipa3_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // x8
  unsigned __int64 StatusReg; // x23
  unsigned __int64 v8; // x27
  __int64 v9; // x8
  _QWORD *v10; // x9
  _QWORD *v11; // x8
  __int64 v12; // x10
  unsigned __int8 *v13; // x22
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v22; // x9
  __int64 v23; // x0
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x26
  __int64 v28; // x25
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x8
  unsigned __int64 v35; // x9
  __int64 v36; // x0
  void (__fastcall *v37)(_QWORD); // x8
  __int64 v38; // x1
  unsigned __int64 v39; // x8
  int v40; // w25
  char v41; // w8
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  _QWORD v47[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v48[3]; // [xsp+18h] [xbp-18h] BYREF

  v48[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47[2] = &woken_wake_function;
  v48[0] = v48;
  v6 = ipa3_ctx;
  StatusReg = _ReadStatusReg(SP_EL0);
  v48[1] = v48[0];
  v47[0] = 0;
  v47[1] = StatusReg;
  add_wait_queue(v6 + 32216, v47);
  v8 = a2;
  while ( 1 )
  {
    mutex_lock(ipa3_ctx + 32104);
    v9 = ipa3_ctx;
    v10 = *(_QWORD **)(ipa3_ctx + 32072);
    if ( v10 == (_QWORD *)(ipa3_ctx + 32072) )
    {
      v13 = nullptr;
      if ( !ipa3_ctx )
        goto LABEL_11;
    }
    else
    {
      v11 = (_QWORD *)v10[1];
      if ( (_QWORD *)*v11 == v10 && (v12 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
      }
      v13 = (unsigned __int8 *)(v10 - 3);
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      v9 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_11;
    }
    v14 = *(_QWORD *)(v9 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d msg=%pK\n", "ipa3_read", 729, v13);
LABEL_11:
    if ( v13 )
    {
      if ( a3 < *((unsigned __int16 *)v13 + 1) )
      {
        printk(&unk_3FB600, "ipa3_read");
        v44 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v45 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v45 )
          {
            ipc_log_string(v45, "ipa %s:%d Message length greater than count\n", "ipa3_read", 733);
            v44 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v44 + 34160);
          if ( v46 )
            ipc_log_string(v46, "ipa %s:%d Message length greater than count\n", "ipa3_read", 733);
        }
        kfree(*((_QWORD *)v13 + 2));
        kfree(v13);
        remove_wait_queue(ipa3_ctx + 32216, v47);
        v40 = -11;
        goto LABEL_39;
      }
      mutex_unlock(ipa3_ctx + 32104);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = v8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v15 = v8 & ((__int64)(v8 << 8) >> 8);
      if ( v15 > 0x7FFFFFFFFCLL )
        goto LABEL_36;
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      v23 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, v13, 4);
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      if ( v23 )
      {
LABEL_36:
        kfree(v13);
        remove_wait_queue(ipa3_ctx + 32216, v47);
        v41 = 0;
        v40 = -14;
        goto LABEL_41;
      }
      v27 = *((_QWORD *)v13 + 2);
      v8 += 4LL;
      a3 -= 4LL;
      if ( v27 )
      {
        v28 = *((unsigned __int16 *)v13 + 1);
        _check_object_size(*((_QWORD *)v13 + 2), v28, 1);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v29 = v8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v29 = v8 & ((__int64)(v8 << 8) >> 8);
        if ( 0x8000000000LL - v28 >= v29 )
        {
          v30 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v32 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v32 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v32);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v30);
          v28 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, v27, v28);
          v33 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v35 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v35 - 4096);
          _WriteStatusReg(TTBR1_EL1, v35);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v33);
        }
        if ( v28 )
          goto LABEL_36;
        v37 = *((void (__fastcall **)(_QWORD))v13 + 1);
        v36 = *((_QWORD *)v13 + 2);
        v38 = *((unsigned __int16 *)v13 + 1);
        v8 += v38;
        a3 -= v38;
        if ( *((_DWORD *)v37 - 1) != -1844471269 )
          __break(0x8228u);
        v37(v36);
      }
      v39 = *v13;
      if ( v39 >= 0x3B )
        __break(0x5512u);
      ++*(_DWORD *)(ipa3_ctx + 4 * v39 + 32596);
      kfree(v13);
    }
    if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
    {
      v40 = -11;
      goto LABEL_38;
    }
    if ( (*(_QWORD *)StatusReg & 0x40) != 0 )
      break;
    v40 = -4;
    if ( (*(_QWORD *)StatusReg & 1) != 0 || v8 != a2 )
      goto LABEL_38;
    mutex_unlock(ipa3_ctx + 32104);
    wait_woken(v47, 1, 0x7FFFFFFFFFFFFFFFLL);
  }
  v40 = -4;
LABEL_38:
  remove_wait_queue(ipa3_ctx + 32216, v47);
  if ( v13 )
    goto LABEL_40;
LABEL_39:
  mutex_unlock(ipa3_ctx + 32104);
LABEL_40:
  v41 = 1;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  if ( ((unsigned __int8)v41 & (v8 != a2)) != 0 )
    return (int)v8 - (int)a2;
  else
    return v40;
}
